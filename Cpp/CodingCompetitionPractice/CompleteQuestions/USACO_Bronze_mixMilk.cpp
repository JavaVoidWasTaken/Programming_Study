#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

class cow {
	public:
		int capacity;
		int milk;
};

int main(){
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	cow aCow;
	int totalMilk, leftoverMilk;
	int cowIndexOne, cowIndexTwo;
	vector<cow> cows;

	for (int i = 0; i < 3; ++i){
		cin >> aCow.capacity;
		cin >> aCow.milk;
		cows.push_back(aCow);
	}

	for (int i = 0; i < 100; ++i){
		cowIndexOne = i%3;
		cowIndexTwo = (i+1)%3;

		totalMilk = cows[cowIndexOne].milk + cows[cowIndexTwo].milk;
		leftoverMilk = max(totalMilk - cows[cowIndexTwo].capacity, 0);
		totalMilk -= leftoverMilk;

		cows[cowIndexOne].milk = leftoverMilk;
		cows[cowIndexTwo].milk = totalMilk;
	}

	cout << cows[0].milk << '\n';
	cout << cows[1].milk << '\n';
	cout << cows[2].milk << '\n';
}
