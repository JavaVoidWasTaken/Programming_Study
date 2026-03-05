#pragma once

class bowls {
public:	
	int appleAmount, pearAmount, bowlAmount;
	vector<int> apples, pears;

	bowls(int inputAppleAmount, int inputPearAmount) {
		appleAmount = inputAppleAmount;
		pearAmount = inputPearAmount;
		bowlAmount = inputAppleAmount + inputPearAmount;

		for (int i = 0; i < inputAppleAmount; ++i) {
			apples.push_back(1);
			pears.push_back(0);
		}
		for (int i = 0; i < inputPearAmount; ++i) {
			apples.push_back(0);
			pears.push_back(1);
		}
	}
	
	// Side effect: Prints errors.
	bool isValidMove(int appleFrom, int pearFrom) {
		// Bounds checking.
		if (!isInRange(appleFrom, bowlAmount)) { 
			cout << "Bowl does not exist.";
			return false;
		}
		if (!isInRange(pearFrom, bowlAmount)) {
			cout << "Bowl does not exist.";
			return false;
		}
		// Checks if there is a fruit in the bowl.
		if (apples.at(appleFrom) < 1) {
			cout << "Empty bowl.";
			return false;
		}
		if (pears.at(pearFrom) < 1) {
			cout << "Empty bowl.";
			return false;
		}
		// Checks if the delta is even.
		if ((appleFrom-pearFrom) % 2 == 1 || (appleFrom-pearFrom) % 2 == -1) {
			cout << "Distance is not even.";
			return false;
		}
		return true;
	}

	// Returns true on success.
	bool exchangeFruits(int appleFrom, int pearFrom) {
		if (!isValidMove(appleFrom, pearFrom)) {
			return false;
		}
		
		apples.at(appleFrom) -= 1;
		apples.at(appleFrom+1) += 1;
		pears.at(pearFrom) -= 1;
		pears.at(pearFrom-1) += 1;
		return true;
	}
	
	bool isWinConditionReached() {
		for (int i = 0; i < pearAmount; ++i) {
			if (pears.at(i) == 0) {
				return false;
			}
		}
		for (int i = pearAmount; i < bowlAmount-1; ++i) {
			if (apples.at(i) == 0) {
				return false;
			}
		}
		return true;
	}

	void printState() {
		cout << "Indexes : ";
		printVector(range(0, bowlAmount), ' ');
		cout << "Apples  : ";
		printAutoSpacedVector(apples, ' ');
		cout << "Pears   : ";
		printAutoSpacedVector(pears, ' ');
	}
};
