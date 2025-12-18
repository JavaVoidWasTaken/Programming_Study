#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

class text{
public:
	int lengthMultiplier, heightMultiplier;
	vector<string> text;
};

int main(){

	text thing;
	string temp;

	cin >> thing.lengthMultiplier >>  thing.heightMultiplier;

	while (cin){
		cin >> temp;
		thing.text.push_back(temp);
	}

	for (int i = 0; i < thing.text.size()-1; ++i){
		for (int j = 0; j < thing.heightMultiplier; ++j){
			for (int k = 0; k < thing.text[i].length(); ++k){
				for (int l = 0; l < thing.lengthMultiplier; ++l){
					cout << thing.text[i][k];
				}
			}
			cout << '\n';
		}
	}

	cout << "\nProcess done!\n"; 

}
