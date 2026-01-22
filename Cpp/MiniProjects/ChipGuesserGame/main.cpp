#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class chipGame{
private:
	int goodChipsAmount = 9;
    	int badChipsAmount = 7;
	enum chipCondition {
		good = 1,
		bad = 2,
		unknown = 3
	};
	enum winCondition {
		win = 1,
		lose = 2,
		none = 3
	};
	enum chipCondition chips[16];
    	enum chipCondition guessedChips[16]; 
	enum winCondition winStatus = none;



	string getUserInput(){
		string input;
		getline(cin, input);
		return input;
	}

	// Prints the coordinates of the chips.
	void printCoordinates(){
		for (int i = 0; i < 10; ++i){
			cout << i << ' ';
		}
		for (char i = 'a'; i <= 'f'; ++i){
			cout << i << ' ';
		}
		cout << '\n';
	}

	// Prints the guessed chips status.
	void printGuessedChips(){
		for (int i = 0; i < 16; ++i){
			switch (guessedChips[i]){
				case good:
					cout << "V ";
					break;
				case bad:
					cout << "X ";
					break;
				case unknown:
					cout << "? ";
					break;
			};
		}
		cout << '\n';
	}

	// DEBUG: Prints all actual chips.
	void printActualChips(){
		for (int i = 0; i < 16; ++i){
			switch (chips[i]){
				case good:
					cout << "V ";
					break;
				case bad:
					cout << "X ";
					break;
				case unknown:
					cout << "? ";
					break;
			};
		}
		cout << '\n';
	}

	void printMainOptions(){
		cout << "What do you want to do? (Use option numbers)\n";
		cout << "  0. Test a pair of chips.\n";
		cout << "  1. Guess a chip.\n";
		cout << "> ";
	}
	
	void printGuessOptions(){
		cout << "What is your guess? (Use the option number)\n";
		cout << "  0. Good chip\n";
		cout << "  1. Bad chip\n";
		cout << "> ";
	}

	void printLoseMessage(){
		cout << "You lost!\n";
	}

	void printWinMessage(){
		cout << "You win!\n";
	}

	enum chipCondition compareChip(int first, int second){
                if (chips[first] == good){
                        if (chips[second] == good) {
                               return good;
                        } else if (chips[second] == bad){
                                return bad;
                        }
                } else if (chips[first] == bad){
                        if (chips[second] == good) {
                                return bad;
                        } else if (chips[second] == bad){
                                return good;
                        }
                } else {
                        cout << "Invalid chip condition!\n";
                        throw -1;
                }
		return bad;
        }

	void testChip(int first, int second){
        	if (compareChip(first, second) == good){
                        cout << "Chip A says that Chip B is good!\n";
                } else {
                        cout << "Chip A says that Chip B is bad!\n";
                }
                if (compareChip(second,first) == good){
                        cout << "Chip B says that Chip A is good!\n";
                } else {
                        cout << "Chip B says that Chip A is bad!\n";
                }
        }

	void printGameStatus(){
		cout << endl;
		printCoordinates();
		printGuessedChips();
		printActualChips();
		printMainOptions();
	}

	bool isInputValidForOption(string input){
		if (input.length() == 1 && (input[0] == '0' || input[0] == '1')){
			return true;
		} else {
			return false;
		}
	}

	bool isInputValidForCoordinate(string input){
		if (input.length() == 1 && ((input[0] <= '9' && input[0] >= '0') || (input[0] <= 'f' && input[0] >= 'a'))){
			return true;
		} else {
			return false;
		}
	}

	// Converts the letter coordinate to an index e.g. f = 16 & 0 = 0.
        int convertCoordinateToIndex(char input){
                if (input <= '9' && input >= '0'){ 
                        return input - '0';
                } else if (input <='f' && input >= 'a'){
                        return input - 'a' + 10; 
                }
		return 0;
        }

	bool guessChip(int chipIndex, enum chipCondition guess){
                if (chips[chipIndex] == guess){
                        return true;
                } else {
                        return false;
                }
        }

	void setGuessedChip(int chipIndex, enum chipCondition guess){
                guessedChips[chipIndex] = guess;
        }
	
	void processTestChip(){
		string userInput;
		int firstChip, secondChip;

		cout << "What is the first chip you want to test? (First one's coordinate)\n> ";
		while (true) {
			userInput = getUserInput();
			if (isInputValidForCoordinate(userInput)){
				firstChip = convertCoordinateToIndex(userInput[0]);
				break;	
			} else {
				cout << "Invalid coordinate!\n> ";
			}
		}
		cout << "What is the second chip you want to test? (Second one's coordinate)\n> ";	
		while (true) {
			userInput = getUserInput();
			if (isInputValidForCoordinate(userInput)){
				if (convertCoordinateToIndex(userInput[0]) != firstChip){
					secondChip = convertCoordinateToIndex(userInput[0]);
					break;
				} else {
					cout << "You can't pick the same coordinates!\n> ";
				}
			} else {
				cout << "Invalid coordinate!\n> ";
			}
		}

		testChip(firstChip, secondChip);
	}

	void processGuessChip(){
		string userInput;
		int coordinate;
		enum chipCondition guess;
		
		cout << "What is your chip to guess? (Use coordinates)\n> ";
		while (true) {
			userInput = getUserInput();
			if (isInputValidForCoordinate(userInput)) {
				coordinate = convertCoordinateToIndex(userInput[0]); 
				break;
			} else {
				cout << "Invalid coordinates!\n> ";
			}
		}
		printGuessOptions();
		while (true) {
			userInput = getUserInput();
			if (isInputValidForOption(userInput)) {
				if (userInput[0] == '0') {
					guess = good;
					break;
				} else if (userInput[0] == '1') {
					guess = bad;
					break;
				}
			} else {
				cout << "Invalid option!\n> ";
			}
		}

		if (guessChip(coordinate, guess)) {
			cout << "Correct guess!\n";
			setGuessedChip(coordinate, guess);
		} else {
			cout << "Wrong guess!\n";
			winStatus = lose;
		}
	}
		
	bool isAllChipsGuessed(){
		for (int i = 0; i < 16; ++i){
			if (guessedChips[i] == unknown){
				return false;
			}
		}
		return true;
	}

	void checkWinCondition(){
		if (isAllChipsGuessed()){
			winStatus = win;
		}
	}
public:
	chipGame(){
		// Randomizes the list of chips with good or bad chips. 	
		for (int i = 0; i < 16; ++i){
			if (rand() % (goodChipsAmount+badChipsAmount) <= goodChipsAmount){
				--goodChipsAmount;
                		chips[i] = good;
                	} else {
				--badChipsAmount;
				chips[i] = bad;
                	}
                }
		
		// Fills guessedChips with unknown.
		for (int i = 0; i < 16; ++i){
			guessedChips[i] = unknown;
		}
        }

	// False indicates game continuation, true means game end.
	bool isWinConditionReached(){
		switch (winStatus){
			case win:
				return true;
				break;
			case lose:
				return true;
				break;
			case none:
				return false;
				break;
		}
		return true;
	}
	
	// True indicates game continuation, false means game end.
	bool processTurn(){
		printGameStatus();
		string userInput = getUserInput();
		
		while (true){
			if (isInputValidForOption(userInput)){
				break;
			} else {
				cout << "Invalid option!\n";
				printGameStatus();
				userInput = getUserInput();
			}
		}

		if (userInput[0] == '0'){
			processTestChip();
		} else if (userInput[0] == '1'){
			processGuessChip();
			// Possibility of the user failing to guess the chipset, causing a loss.
			if (isWinConditionReached()){
				return false;
			}
		}
		
		checkWinCondition();
		if(isWinConditionReached()){
			if (winStatus == win){
				printWinMessage();
			} else if (winStatus == lose){
				printLoseMessage();
			}
			return false;
		}

		return true;
	}

};

int main(){
	chipGame currentGame;
	while(true){
		if (!currentGame.processTurn()){
			break;
		}
	}
}
