#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <thread>
using namespace std;
using ll = long long;

class gameBoard {
public:
	vector<vector<char>> board;
	int boardSize;
	
gameBoard(int size){
	boardSize = size;
	vector<char> temp = {};
	for (int y = 0; y < size; ++y){
		temp.push_back('-');
	}
	for (int x = 0; x < size; ++x){
		board.push_back(temp);
	}
}

vector<char> getRow(int y){
	return board[y];
}

vector<char> getCollumn(int x){
	vector<char> result;
	for (int i = 0; i < boardSize; ++i){
		result.push_back(board[i][x]);
	}
	return result;
}

vector<char> getDiagonalTopLeft(){
	vector<char> result;
	for (int i = 0; i < boardSize; ++i){
		result.push_back(board[i][i]);
	}
	return result;
}

vector<char> getDiagonalTopRight(){
	vector<char> result;
	for (int i = boardSize-1; i >= 0; --i){
		result.push_back(board[i][i]);
	}
	return result;
}

vector<vector<int>> getEmptySpacesYX(){
	vector<int> temp;
	vector<vector<int>> result; 
	for (int y = 0; y < boardSize; ++y){
		for (int x = 0; x < boardSize; ++x){
			if (board[y][x] == '-'){
				temp.push_back(y);
				temp.push_back(x);
				result.push_back(temp);
				temp = {};
			}
		}	
	}
	return result;
}

void displayBoard(){
	// Show number coordinates.
	cout << "  ";
	for (int i = 1; i <= boardSize; ++i){
		cout << i << ' ';
	}
	cout << '\n';

	// Show board and letter coordinates.
	char characterCoordinate = 'A';
	for (int y = 0; y < boardSize; ++y){
		cout << characterCoordinate << ' ';
		characterCoordinate++;
		for (int x = 0; x < boardSize; ++x){
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
}

int generateRandomNumber(int from, int to){
	return rand()%to + from;
}

// Returns true if the tile is empty, false otherwise.
bool isMoveValid(int y, int x){
	if (y > boardSize-1 || y < 0){
		return false;
	}	
	if (x > boardSize-1 || x < 0 ){
		return false;
	}

	if (board[y][x] == '-'){
		return true;
	} else {
		return false;
	}
}

void addSymbolToBoard(char symbol, int y, int x){
	board[y][x] = symbol;
}

// If all items in the vector are the same as the item, return true, false otherwise.
bool isVectorIdentical(vector<char> list, char item){
	for (int i = 0; i < list.size(); ++i){
		if (list[i] != item){
			return false;
		}
	}
	return true;
}

string getWinCondition(){
	// Checks rows.
	for (int y = 0; y < boardSize; ++y){
		if (isVectorIdentical(getRow(y), 'O')){
			return "Player";
		}
		if (isVectorIdentical(getRow(y), 'X')){
			return "Opponent";
		}
	}

	// Checks Collumns.
	for (int x = 0; x < boardSize; ++x){
		if (isVectorIdentical(getCollumn(x), 'O')){
			return "Player";
		}
		if (isVectorIdentical(getCollumn(x), 'X')){
			return "Opponent";
		}
	}

	// Checks Diagonals
	if (isVectorIdentical(getDiagonalTopLeft(), 'O')){
		return "Player";
	}
	if (isVectorIdentical(getDiagonalTopLeft(), 'X')){
		return "Opponent";
	}

	if (isVectorIdentical(getDiagonalTopRight(), 'O')){
		return "Player";
	}
	if (isVectorIdentical(getDiagonalTopRight(), 'X')){
		return "Opponent";
	}

	// If no win conditions are found.
	return "None";
}

void makeAIMove(){
	vector<vector<int>> emptySpaces = getEmptySpacesYX();
	int emptySpaceAmount = emptySpaces.size();
	int addSymbolHere = generateRandomNumber(0, emptySpaceAmount);
	addSymbolToBoard('X', emptySpaces[addSymbolHere][0], emptySpaces[addSymbolHere][1]);
}
};

int main() {
	int boardSize;
	int moveX, moveY;
	string userInput;

	while (true){
		try {
			cout << "Please enter your desired board size (3-9)." << '\n';
			getline(cin, userInput);
			boardSize = stoi(userInput);
			if (boardSize > 9){
				throw -1;
			} else if (boardSize < 3){
				throw -1;
			}
			break;
		} catch (...) {
			cout << "Invalid Input!" << "\n";
		}
	}
	srand(time(0));

	gameBoard mainBoard(boardSize);

	while (mainBoard.getWinCondition() == "None"){
		mainBoard.displayBoard();
		cout << "What is your move? (Example: A1) \n";		
		getline(cin, userInput);

		if (userInput.size() == 2){
			moveY = userInput[0] - 'A';
			moveX = userInput[1] - '1';
			if (mainBoard.isMoveValid(moveY, moveX)){
				mainBoard.addSymbolToBoard('O', moveY, moveX);
				mainBoard.makeAIMove();
			} else {
				cout << "Invalid input, use the example's format!\n";
			}
		} else {
			cout << "Invalid input, use the example's format!\n";
		}

	}

	if (mainBoard.getWinCondition() == "Player"){
		cout << "You win!" << '\n';
	} else {
		cout << "You lose.." << '\n';
	}

}