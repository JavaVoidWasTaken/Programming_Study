#include <iostream>
using namespace std;
using ll = long long;

void printTooLow(ll input){
	cout << "Testing the number : " << input << endl;
	cout << "Computer made too low of a input." << endl;
}

void printTooHigh(ll input){
	cout << "Testing the number : " << input << endl;
	cout << "Computer made too high of a input." << endl;
}

void printCorrect(ll input, ll iterations){
	cout << "Testing the number : " << input << endl;
	cout << "Computer made made the right input in " << iterations << " iterations." << endl;
}

enum guess {
	CORRECT,
	TOO_LOW,
	TOO_HIGH
};

enum guess tester (ll guess, ll target) {
	if (guess < target) {
		return TOO_LOW;
	}
	if (guess > target) {
		return TOO_HIGH;
	}
	if (guess == target) {
		return CORRECT;
	}
}

void bot (ll target) {
	enum guess guessResult;	
	ll iterations = 0;
	ll low = 0;
	ll middle = 0;
	ll high = 1;

	while (low <= high) {
		++iterations;
		middle = low + (high - low) / 2;
		guessResult = tester(middle, target);
		if (guessResult == TOO_LOW) {
			printTooLow(middle);
			low = middle+1;
			high *= 2;
		} else if (guessResult == TOO_HIGH) {
			printTooHigh(middle);
			high = middle-1;
		} else if (guessResult == CORRECT) {
			printCorrect(middle, iterations);
			break;
		} 
	}
}
		
		


int main() {
	ll target;
	cin >> target;

	bot(target);
}

