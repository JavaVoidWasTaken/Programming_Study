#include <iostream>
#include <vector>
using namespace std;

#include "print.h"
#include "range.h"
#include "bowls.h"
	
int main() {
	int appleAmount, pearAmount;
	cout << "How many apple bowls to start with?\n> ";
	cin >> appleAmount;
	cout << "How many pear bowls to start with?\n> ";
	cin >> pearAmount;
	cout << '\n';
	bowls game(appleAmount, pearAmount);
	
	int appleSwapIndex;
	int pearSwapIndex;

	while (true) {
		game.printState();
		if (game.isWinConditionReached()) {
			cout << "You won!\n";
			break;
		}
		cout << "What index of an apple do you want to swap?\n> ";
		cin >> appleSwapIndex;
		cout << "What index of a pear do you want to swap?\n> ";
		cin >> pearSwapIndex;
		if (game.exchangeFruits(appleSwapIndex, pearSwapIndex)) {
			cout << "\n";
		} else {
			cout << " Invalid input!\n\n";
		}
	}
}

