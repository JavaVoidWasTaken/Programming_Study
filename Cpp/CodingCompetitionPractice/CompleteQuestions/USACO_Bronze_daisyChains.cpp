#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

vector<double> getRangeInVector(int from, int to, vector<double> list){
	vector<double> output;

	for (int i = from; i <= to; ++i){
		output.push_back(list[i]);
	}

	return output;
}

double getSumOfVector(vector<double> list){
	int currentSum = 0;
	
	for (int i = 0; i < list.size(); ++i){
		currentSum += list[i];
	}

	return currentSum;
}

int countAverageFlowers(double average, vector<double> list){
	int result = 0;

	for (int i = 0; i < list.size(); ++i){
		if (list[i] == average){
			return 1;
		}
	}

	return 0;
}

int main(){
	int inputSize, temp;
	vector<double> flowers;

	double numberOfAverageFlowers = 0, currentSum = 0, currentAverage = 0;

	cin >> inputSize;
	for (int i = 0; i < inputSize; ++i){
		cin >> temp;
		flowers.push_back(temp);
	}

	for (int from = 0; from < inputSize; ++from){
		for (int to = from; to < inputSize; ++to){
			currentSum = getSumOfVector(getRangeInVector(from, to, flowers));
			currentAverage = currentSum/(to-from+1);

			numberOfAverageFlowers += countAverageFlowers(currentAverage, getRangeInVector(from, to, flowers));
		}
	}

	cout << numberOfAverageFlowers << endl;
}
