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
	vector<cow> cows;

	for (int i = 0; i < 3; ++i){
		cin >> aCow.capacity;
		cin >> aCow.milk;
		cows.push_back(aCow);
	}

	for (int i = 0; i < 100; ++i){
		cows[(i+1)%3].milk  = min(cows[i%3].milk, cows[(i+1)%3].capacity);

	}
}
