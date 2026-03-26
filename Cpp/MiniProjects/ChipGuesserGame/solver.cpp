#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<bool> input){
	for (int i = 0; i < input.size(); ++i){
		if (input[i]){
			cout << "V ";
		} else {
			cout << "X ";
		}
	}
	cout << '\n';
}

void printVector(vector<int> input){
	for (int i = 0; i < input.size(); ++i){
		cout << input[i];
	}
	cout << '\n';
}

class chipGame{
public: 
	int chips;
	int goodChips;
	int badChips;
	// True means a good chip, false means a bad chip.
	vector<bool> chipBoard;
	vector<bool> guessedChipBoard;

	chipGame(int inputNumberOfChips){
		chips = inputNumberOfChips;
		if (chips % 2 == 0){
			goodChips = chips/2+1;
			badChips = chips/2-1;
		} else {
			goodChips = chips/2+1;
			badChips = chips/2;
		}

		for (int i = 0; i < chips; ++i){
			if (rand() % (goodChips+badChips) <= goodChips){
				chipBoard.push_back(true);
				--goodChips;
			} else {
				chipBoard.push_back(false);
				--badChips;
			}
		}
	}
	
	// If both chips are identical, return true. If both chips are different, return false.
	bool isChipGood(int firstChip, int secondChip){
		if ((chipBoard[firstChip] && chipBoard[secondChip]) || (!chipBoard[firstChip] && !chipBoard[secondChip])){
			return true;
		} else {
			return false;
		}
	}

	// If a chip has a score that is equal or larger than 0, it is a good chip.
	vector<bool> solveChips(){
		vector<bool> result;
		int currentChipScore = 0;
		// Loops over every single pair for every single chip.
		for (int i = 0; i < chips; ++i){
			for (int j = 0; j < chips; ++j){
				if (isChipGood(i, j)){
					++currentChipScore;
				} else {
					--currentChipScore;
				}
			}
			if (currentChipScore > 0){
				result.push_back(true);
			} else {
				result.push_back(false);
			}
			currentChipScore = 0;
		}
		return result;
	}
};

int main(){
	chipGame currentGame(16);
	cout << "Actual board:\n";
	printVector(currentGame.chipBoard);
	cout << "Guessed board:\n";
	printVector(currentGame.solveChips());
}

