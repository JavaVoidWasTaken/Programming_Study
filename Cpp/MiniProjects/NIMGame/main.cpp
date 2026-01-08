#include <iostream>
#include <string>
using namespace std;

class NIMGame{
private:
	string rawUserInput;
	int userInput;
	int matchesLeft;
	enum playerTypes {
		firstPlayer = 1,
		secondPlayer = 2
	};
	enum playerTypes currentPlayer;

	void outputPlayerInputMessage(){
		switch (currentPlayer){
			case 1:
				cout << "Player A, input the amount of matches: ";
				break;
			case 2:
				cout << "Player B, input the amount of matches: ;
				break;
		}
	}

	void outputPlayerErrorMessage(){
		switch (currentPlayer){
			case 1:
				cout << "Sorry, player A. Please re-input the amount of matches to take:\n";
				break;
			case 2:
				cout << "Sorry, player B. Please re-input the amount of matches to take:\n";
				break;
		}
	}

	void outputNumberOfMatches(){
		cout << "The amount of matches = " << matchesLeft << '\n';
	}

	void outputWinMessage(int winCondition){
		if (winCondition == 2){
			cout << "Player A can't pick anymore matches, so player B wins\n";
		} else if (winCondition == 1) {
			cout << "Player B can't pick anymore matches, so player A wins\n";
		}
	}

	void takeMatches(int matchesTaken){
		matchesLeft -= matchesTaken;
	}

	void changePlayer(){
		switch (currentPlayer){
			case 1:
				currentPlayer = secondPlayer;
				break;
			case 2:
				currentPlayer = firstPlayer;
				break;
		}
	}

	bool isInputInBounds(){
		if (userInput >= 1 && userInput <= 3 && matchesLeft - userInput >= 0){
			return true;
		} else {
			return false;
		}
	} 

	// Returns true of the input is in the bounds and valid, false otherwise. Also converts raw string input into integer.
	bool processInput(){
		try {
			userInput = stoi(rawUserInput);
			if (isInputInBounds()){
				return true;
			} else {
				throw -1;
			}
		} catch (...){
			outputPlayerErrorMessage();
		}

		return false;
	}

	void getUserInput(){
		outputNumberOfMatches();
		outputPlayerInputMessage();
		getline(cin, rawUserInput);
	}

public:
	NIMGame(int startingMatches){
		matchesLeft = startingMatches;
		currentPlayer = firstPlayer;
	}

	// 2 = Player 2 wins, 1 = Player 1 wins, 0 = No one wins yet.
	int getWinCondition(){
		// The current player with no matches loses.
		if (matchesLeft == 0){
			switch (currentPlayer){
				case 1:
					return 2;
					break;
				case 2:
					return 1;
					break;
			}
		}
		return 0;
	}

	void processTurn(){
		while (true){	
			getUserInput();
			if (processInput()){
				break;
			}
		}	

		if (isInputInBounds()) {
			takeMatches(userInput);
		}
		
		changePlayer();
		outputWinMessage(getWinCondition());
	}
};

int main() {
	NIMGame game(16);

	// Starts the game
	while (true){
		game.processTurn();
		// If somebody won
		if (game.getWinCondition() != 0){
			break;
		}
	}
}
