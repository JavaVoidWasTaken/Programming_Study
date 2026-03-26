#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

void printVect(vector<ll> input){
	for (int i = 0; i < input.size(); ++i) {
		cout << input[i] << ' ';
	}
	cout << endl;
}

int main() {
	ll testCaseSize;
	vector<ll> result;
	cin >> testCaseSize;
	cout << endl;
	for (ll i = 0; i < testCaseSize; ++i) {
		ll N, K, temp = 0, totalNumberOfAdditions = 0;
		vector<ll> input = {};
		vector<ll> delta = {};
		cin >> N >> K;

		for (ll i = 0; i < N; ++i) {
			cin >> temp;
			input.push_back(temp);
		}

		// Algo start.
		sort(input.begin(), input.end());
		for (ll i = 0; i < N-1; ++i) {
			delta.push_back(input[i+1]-input[i]);
		}
		
		for (ll i = 0; i < N-1; ++i) {
			if (delta[i] == 0){
				input[i] += K;
				delta[i] += K;
			}
		}
			

		cout << "\n> ";
		printVect(input);
		cout << "> ";
		printVect(delta);
		cout << totalNumberOfAdditions;
	}
	for (int i = 0; i < testCaseSize; ++i) {
		cout << result[i] << endl;
	}
}

		
