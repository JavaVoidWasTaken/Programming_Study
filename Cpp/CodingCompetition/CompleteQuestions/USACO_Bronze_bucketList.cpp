#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

class cow {
	public:
		int amount;
		vector<int> startTime;
		vector<int> endTime;
		vector<int> buckets;
};

int main(){
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	int maxTime = 0, maxBuckets = 0, currentBuckets = 0, temp;
	cow cows;

	cin >> cows.amount;

	for (int i = 0; i < cows.amount; ++i){
		cin >> temp;
		cows.startTime.push_back(temp);
		
		cin >> temp;
		cows.endTime.push_back(temp);
		maxTime = max(temp, maxTime);
		
		cin >> temp;
		cows.buckets.push_back(temp);
	}

	for (int currentTime = 0; currentTime < maxTime; ++currentTime){
		for (int o = 0; o < cows.amount; ++o){
			if (cows.startTime[o] == currentTime){
				currentBuckets += cows.buckets[o];
			}
			if (cows.endTime[o] == currentTime){
				currentBuckets -= cows.buckets[o];
			}
		}
		maxBuckets = max(currentBuckets, maxBuckets);
	}

	cout << maxBuckets;
}
