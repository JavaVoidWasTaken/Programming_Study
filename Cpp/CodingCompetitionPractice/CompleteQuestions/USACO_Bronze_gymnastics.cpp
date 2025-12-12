#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int getIndexOfCow(int cow, vector<int> cows){
	int result; 
	for (int i = 0; i < cows.size(); ++i){
		if (cows[i] == cow){
			return i;
		}
	}
	return -1;
}

vector<int> getBetterThan(int cow, vector<int> cows){
	int usingIndex = getIndexOfCow(cow+1, cows); 
	vector<int> result;

	if (usingIndex == cows.size()-1){
		return {};
	}

	for (int i = usingIndex+1; i < cows.size(); ++i){
		result.push_back(cows[i]);
	}

	return result;
}

vector<int> getVectorAND(vector<int> v1, vector<int> v2){
	vector<int> result;

	for (int i = 0; i < v1.size(); ++i){
		for (int j = 0; j < v2.size(); ++j){
			if (v1[i] == v2[j]){
				result.push_back(v1[i]);
			}
		}
	}

	return result;
}

int main(){

	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int testSize, listSize, temp, result = 0;
	vector<int> cowsTemp, currentBetterThan;
	vector<vector<int>> cows;

	cin >> testSize >> listSize;

	for (int i = 0; i < testSize; ++i){
		for (int o = 0; o < listSize; ++o){
			cin >> temp;
			cowsTemp.push_back(temp);
		}
		cows.push_back(cowsTemp);
		cowsTemp = {};
	}

	for (int i = 0; i < listSize; ++i){
		currentBetterThan = getBetterThan(i, cows[0]);

		for (int j = 0; j < testSize; ++j){
			currentBetterThan = getVectorAND(currentBetterThan ,getBetterThan(i, cows[j]));
		}

		result += currentBetterThan.size();
	}

	cout << result << endl;
}
