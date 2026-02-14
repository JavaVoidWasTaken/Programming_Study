#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// Inclusive number generator,
// EXAMPLE: from=0, to=3 -> values of 0 until 3.
int generateRandomNumber(int from, int to){
	int difference = from-to;
	int randomNumber = from;
	// Makes sure cases of modulus of 0 are handled properly. Added/Subtracted by 1 to be inclusive.
	if (difference < 0){
		randomNumber = rand()%(difference*-1+1);
		return from+randomNumber;
	}
	if (difference > 0){
		randomNumber = rand()%(difference+1);
		return from-randomNumber;
	}

	// A zero difference means a range of 0, meaning there is only one value.
	return randomNumber;
}

// O(N), linear search. 
int getBruteForceMinOfVector(vector<int> input){
	int result = input[0];
	int size = input.size();
	for (int i = 0; i < size; ++i){
		if (input[i] < result){
			result = input[i];
		}
	}
	return result;
}

// Returns the index(es) of the target in the vector.
// Uses binary search (O(log(N)), and exponential search to find the lower/upper bounds of the items.
vector<int> findItems(vector<int> input, int target){
	int size = input.size();
	int left = 0;
	int right = size-1;
	vector<int> result;
		
	while(left <= right){
		int middle = (right+left)/2;
		if (input[middle] == target){
			result.push_back(middle);
			input.erase(input.begin() + middle);
			size--;
			break;
		} else if (input[middle] < target){
			left = middle+1;
		} else if (input[middle] > target){
			right = middle-1;
		}
	}
	
	return result;
}

void printVector(vector<int> input, char separator){
	int size = input.size();
	for (int i = 0; i < size; ++i){
		cout << input[i] << separator;
	}
	cout << endl;
}

void print(string input){
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
	
	vector<int> targetNumberIndexes;
	print("The index of the number is:");
	targetNumberIndexes = findItems(randomArray, targetNumber);
	printVector(targetNumberIndexes, ' ');
}
