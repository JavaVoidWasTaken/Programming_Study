#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
	vector<vector<bool>> truthMapOne = {{true, false, true},  {true, false, true}, {true, false, true}};
	vector<vector<bool>> truthMapTwo = {{true, true, false}, {true, true, true}, {false, true, false}};
	vector<bool> truthMapTemporary;
	vector<vector<bool>> truthMapOutput;

	for (int i = 0; i < truthMapOne.size(); ++i){
		for (int o = 0; o < truthMapOne.size(); ++o){
			if (truthMapOne[i][o] && truthMapTwo[i][o]){
				truthMapTemporary.push_back(true);
			} else {
				truthMapTemporary.push_back(false);
			}
		}
		truthMapOutput.push_back(truthMapTemporary);
		truthMapTemporary = {};
	}

	for (int i = 0; i < truthMapOne.size(); ++i){
		for (int o = 0; o < truthMapOne.size(); ++o){
			if (truthMapOutput[i][o]){
				cout << "\u25A0 ";
			}else{
				cout << "\u25A1 ";
			}
		}
		cout << endl;
	}
}