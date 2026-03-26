#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <chrono>
#include <thread>
using namespace std;

// Inclusive number generator,
// EXAMPLE: from=0, to=3 -> values of 0 until 3.
int generateRandomNumber(int from, int to) {
	int difference = from-to;
	int randomNumber = from;
	// Makes sure cases of modulus of 0 are handled properly. Added/Subtracted by 1 to be inclusive.
	if (difference < 0) {
		randomNumber = rand()%(difference*-1+1);
		return from+randomNumber;
	}
	if (difference > 0) {
		randomNumber = rand()%(difference+1);
		return from-randomNumber;
	}

	// A zero difference means a range of 0, meaning there is only one value.
	return randomNumber;
}

// Returns the index of the item.
int binaryFindItem(vector<int> input, int target) {
	int size = input.size();
	int left = 0;
	int right = size-1;
	int middle = (right+left)/2;

	while(left <= right) {
		if (input[middle] == target) {
			return middle;
		} else if (input[middle] < target) {
			left = middle+1;
		} else if (input[middle] > target) {
			right = middle-1;
		}
		middle = (right+left)/2;
	}
	
	// If no items are found, return negative.
	return -1;
}

// Returns the upper bound index of the item.
// Uses a sorted vector, returns -1 if no items are found.
// Example: {1,2,3,3,3,4}, 3 -> 4 
int getUpperBound(vector<int> input, int target) {
	int startingIndex = binaryFindItem(input, target);
	
	if (startingIndex == -1) {
		return -1;
	}
  
	// Starts searching for the upper bound.
  int size = input.size();
  int left = startingIndex;
  int right = size-1;
  int middle = (right+left)/2;
	while (true) {
    
  }_	

}

// Returns the lower bound index of the item.
// Example: {1,2,3,3,3,4}, 3 -> 2
int getLowerBound(vector<int> input, int target){

}

void printVector(vector<int> input, char separator){
	int size = input.size();
	for (int i = 0; i < size; ++i){
		cout << input[i] << separator;
	}
	cout << endl;
}

void print(auto input){
	cout << input;
	cout << endl;
}

void getUserInput(string message, auto &output){
	print(message);
	cin >> output;
}

int main() {
	int size, randomMinimum, randomMaximum, targetNumber;
	vector<int> randomArray;

	getUserInput("What is your vector size?", size);
	getUserInput("What is the minimum value of the vector?", randomMinimum);
	getUserInput("What is the maximum value of the vector?", randomMaximum);
	
	for (int i = 0; i < size; ++i){
		int randomValue = generateRandomNumber(randomMinimum, randomMaximum);
		randomArray.push_back(randomValue);
	}

	sort(randomArray.begin(), randomArray.end());
	
	print("Initial array:");
	printVector(randomArray, ' ');
	getUserInput("Search for what number?", targetNumber);
	
	int targetNumberIndex;
	print("The upper bound index of the number is:");
	print(getUpperBound(randomArray, targetNumber));
	
	print("The lower bound index of the number is:");
	print(getLowerBound(randomArray, targetNumber));
	
}
