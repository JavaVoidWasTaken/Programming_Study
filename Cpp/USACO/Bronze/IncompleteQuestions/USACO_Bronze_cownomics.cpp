#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

bool isCharInsideIndexOfStrings(int index, char search, vector<string> list){
	for (int i = 0; i < list.size(); ++i){
		if (list[i][index] == search){
			return true;
		}
	}

	return false;
}

int main(){
	/*
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	*/

	int cowAmount, genomeSize, result = 0;
	bool isGenomeUnique;
	string temp;
	string genomeCase = "ATCG";
	vector<string> spottyList, plainList;

	cin >> cowAmount >> genomeSize;

	for (int i = 0; i < cowAmount; ++i){
		cin >> temp;
		spottyList.push_back(temp);
	}
	for (int i = 0; i < cowAmount; ++i){
		cin >> temp;
		plainList.push_back(temp);
	}

	for (int i = 0; i < cowAmount; ++i){
		isGenomeUnique = true;
		int j = 0;
		while (j < 4){
			if (isCharInsideIndexOfStrings(i, genomeCase[j], spottyList)){
				if (isCharInsideIndexOfStrings(i, genomeCase[j], plainList)){
					cout << genomeCase[j] << " ";
					isGenomeUnique = false;
					break;
				} 
			}
			++j;   
		}

		if (isGenomeUnique){
			result++;
		}
	}

	cout << result << '\n';

}
