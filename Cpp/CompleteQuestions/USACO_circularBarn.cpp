#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int getSumOfVector(vector<int> input){
	int sum = 0;
	for (int i = 0; i < input.size(); ++i){
		sum += input[i];
	}
	return sum;
}

int main(){
	// Prepares input and output.
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	
	// Setup variables.
	int cows, temp;
	vector<int> cowsNeeded;
	int currentCows;
	int lowestCowsTraveled, currentCowsTraveled = 0;

	// Gets number of test cases.
	cin >> cows;

	// Gets all the needed cows for each room.
	for (int i = 0; i < cows; ++i){
		cin >> temp;
		cowsNeeded.push_back(temp);
	}

	// Sets lowestCowsTraveled to a really big value so that it won't interfere with min().
	lowestCowsTraveled = getSumOfVector(cowsNeeded)*cows;
	// Sets the current amount of cows going around the barn to the sum of the cows needed.
	currentCows = getSumOfVector(cowsNeeded);


	// Algorithm, brute force method.
	for (int i = 0; i < cows; ++i){
		for (int o = i; o < cows+i; ++o){
			// Reduces the amount of cows as they go through the barn.
			currentCows -= cowsNeeded[o%cows];
			currentCowsTraveled += max(currentCows, 0);
		}
		// Gets the best answer and sets all variables to default.
		lowestCowsTraveled = min(lowestCowsTraveled, currentCowsTraveled);
		currentCowsTraveled = 0;
		currentCows = getSumOfVector(cowsNeeded);
	}

	// Output result.
	cout << lowestCowsTraveled;
}
