#include <iostream>
#include <chrono>
using namespace std;
using ll = long long;

ll target = 1000000000000000000;

int main() {
	ll x = 0,
	   y = 1,
	   z = 0;


	while (true) {
		cout << x << endl;
		z = x;
		x = y + z;
		y = z;
		
		if (x >= target) {
			break;
		}
	}
	// 0 1 1 2 3 5 8 13
}
		



