#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

class cow {
public:
	vector<vector<int>> betterThan;
	vector<vector<int>> cowTournament;
};

vector<int> getBetterThan(int cow, vector<int> cowTournament){
	vector<int> result;
	int index;
	for (int i = 0; i < cowTournament.size(); ++i){
		if (cowTournament[i] == cow){
			index = i;
		}
	}
	
	int i = index + 1;
	
	while (i < cowTournament.size()){
		result.push_back(cowTournament[i]);
		++i;
	}

	return result;
}

int main(){

	freopen("gymnastics.in", "r", stdin);
	//freopen("gymnastics.out", "w", stdout);
	
	int inputSize;
	int inputLength;
	int temp;
	cow cows;
	vector<int> vectorTemp;

	cin >> inputSize >> inputLength;

	for (int i = 0; i < inputSize; ++i){
		for (int o = 0; o < inputLength; ++o){
			cin >> temp;
			vectorTemp.push_back(temp);
		}
		cows.cowTournament.push_back(vectorTemp);
		vectorTemp = {};
	}


	// Sets up the initial values of better than
	for (int i = 0; i < inputSize; ++i){
		cows.betterThan.push_back(getBetterThan(i, cows.cowTournament[0]));
	}

	for (int i = 0; i < inputSize; ++i){
		for (int o = 0; o < inputLength; ++o){
			cout << cows.betterThan[i][o] << " ";
		}
		cout << endl;
	}


}
