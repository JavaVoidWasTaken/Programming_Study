#include <iostream>
#include <vector>
using namespace std;


// Change this seed if you want different simulations.
const int seed = 12345; 

// Modify these parameters if you want to change the behaviour of the simulation.
const int boardSize = 10;
const int initialInfectedStudents = 25;
const int iterations = 5;


void print2DVector(vector<vector<int>> input){
	for (int x = 0; x < input.size(); ++x){
		for (int y = 0; y < input.size(); ++y){
			if (input[x][y] == 1){
				cout << "\u25A0";
			} else {
				cout << "\u25A1";
			}
			cout << ' ';
		}
		cout << '\n';
	}
}

vector<vector<int>> construct2DVector(int size, int initialValue){
	vector<int> tempVect;
	vector<vector<int>> result;
	for (int i = 0; i < size; ++i){
		tempVect.push_back(initialValue);
	}
	for (int i = 0; i < size; ++i){
		result.push_back(tempVect);
	}
	return result;
}


// generates a random number, inclusive.
int generateRandomNumber(int from, int to){
	return (rand()%to)+from;
}


class classroom{
public:
	int size;
	vector<vector<int>> board, infectionMap;
	
	classroom(int tempSize, int initialInfectedStudents){
		size = tempSize;
		board = construct2DVector(size, 0);
		infectionMap = construct2DVector(size, 0);
		randomlyInfectStudents(initialInfectedStudents);
	}
		
	void simulateBoard(){
		print2DVector(board);
		cout << '\n';
		for (int i = 0; i < iterations; ++i){
			processInfectionMap();
			infectBoard();
			print2DVector(board);
			cout << '\n';
		}
	}

	void randomlyInfectStudents(int infectStudents){
		int rawIndex, xIndex, yIndex;
		while (infectStudents > 0){
			rawIndex =  generateRandomNumber(0, size*size-1);
			xIndex = rawIndex/size;
			yIndex = rawIndex%size;
			if (board[xIndex][yIndex] == 0){
				board[xIndex][yIndex] = 1;
				--infectStudents;
			}
		}
	}

	// "Splashes" the infection of the current tile onto adjacent squares (not diagonally) by incrementing them by 1.
	// The current infected square will stay infected.
	void splashInfection(int boardX, int boardY){
		if (board[boardX][boardY] == 1){
			// Current square.
			infectionMap[boardX][boardY] = infectionMap[boardX][boardY] + 2;
			// Start with vertical.
			if (boardX > 0){
				infectionMap[boardX-1][boardY] += 1;
			}
			if (boardX < size-1){
				infectionMap[boardX+1][boardY] += 1;
			}
			// Now with horizontal.
			if (boardY > 0){
				infectionMap[boardX][boardY-1] += 1;
			}
			if (boardY < size-1){
				infectionMap[boardX][boardY+1] += 1;
			}
		}
	}
	
	// Splashes the infection of every tile onto every other adjacent tile.
	void processInfectionMap(){
		infectionMap = construct2DVector(size, 0);
		for (int x = 0; x < size; ++x){
			for (int y = 0; y < size; ++y){
				splashInfection(x, y);	
			}
		}
	}
	
	// If the infection value of a tile is 2 or more, it becomes an infected tile.
	void infectBoard(){
		for (int x = 0; x < size; ++x){
			for (int y = 0; y < size; ++y){
				if (infectionMap[x][y] >= 2){
					board[x][y] = 1;
				}
			}
		}
	}

};


int main() {
	srand(seed);

	cout << "The following grid represents the state of the infected tiles, 1 being infected, and 0 being uninfected.\n";
	cout << "I used an \"infection map\" to infect tiles, with tiles that have more than 2 infected neighbours becoming infected.\n\n";
	
	classroom currentClassroom(boardSize, initialInfectedStudents);
	
	currentClassroom.simulateBoard();
}

