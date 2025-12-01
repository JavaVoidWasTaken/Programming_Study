#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	int cowAmount, temp;
	vector<int> shuffle;
	vector<int> cowsPrev, cowsNow;


	cin >> cowAmount;

	for (int i = 0; i < cowAmount; ++i){
		cin >> temp;
		shuffle.push_back(temp);
	}

	for (int i = 0; i < cowAmount; ++i){
		cin >> temp;
		cowsNow.push_back(temp);  
	}

	cowsPrev = cowsNow;

	for (int i = 0; i < 3; ++i){
		for (int o = 0; o < cowAmount; ++o){
			cowsNow[o] = cowsPrev[shuffle[o]-1];
		}
		cowsPrev = cowsNow;
	}


	for (int i = 0; i < cowAmount; ++i){
		cout << cowsNow[i] << '\n';
	}
}
