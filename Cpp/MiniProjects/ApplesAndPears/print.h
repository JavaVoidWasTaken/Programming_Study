#pragma once

int getDigits(int input) {
	int result = 1;
	while (input >= 10) {
		input /= 10;
		++result;
	}
	return result;
}

void printVector(vector<int> input, char separator) {
	int size = input.size();

	for (int i = 0; i < size; ++i) {
		cout << input.at(i) << separator;
	}

	cout << '\n';
}

void printAutoSpacedVector(vector<int> input, char separator) {
	int size = input.size();

	for (int i = 0; i < size; ++i) {
		cout << input.at(i);
		for (int j = 0; j < getDigits(i); ++j) {
			cout << separator;
		}
	}

	cout << '\n';
}
