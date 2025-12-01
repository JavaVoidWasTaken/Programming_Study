#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	ll N, K, temp, currentDiamonds = 0, highestDiamonds = 0;
	vector<ll> diamonds;

	cin >> N >> K;

	for (int i = 0; i < N; i++){
		cin >> temp;
		diamonds.push_back(temp);
	}

	sort(diamonds.begin(), diamonds.end());

	for (int i = 0; i < N; i++){
		for (int o = i+1; o < N; o++){
			if (diamonds[o] - diamonds[i] <= K){
				currentDiamonds++;
				cout << currentDiamonds << '\n';
			}
		}
		highestDiamonds = max(highestDiamonds, currentDiamonds);
		currentDiamonds = 0;
	}

	cout << highestDiamonds;
}