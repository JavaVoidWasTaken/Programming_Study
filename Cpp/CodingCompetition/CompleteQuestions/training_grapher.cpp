#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
	ll length, height, thickness, timescale;
	ll x = 0, y = 0;
	cin >> length >> height >> thickness >> timescale;

	for (ll i = height; i >= 0; --i){
		for (ll o = 0; o < length; ++o){
			x = o;
			y = sin(x*50) * 30 + height;
			y *= 0.5;
			y = round(y);

			if (y < i+thickness && y > i-thickness){
				cout << "\u25A0";
			} else {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}