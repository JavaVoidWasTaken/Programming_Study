#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
	ll size;
	cin >> size;

	for (int i = size; i > 0; --i){
		cout << endl;
		for (int o = 0; o < i; ++o){
			cout << "8";
		}
		for (int o = size-1; o > i; --o){
			cout << " ";
			cout << " ";
		}
		for (int o = 0; o < i; ++o){
			cout << "8";
		}
	}

	for (int i = 0; i < size; ++i){
		for (int o = 0; o < i; ++o){
			cout << "8";
		}
		for (int o = size-1; o > i; --o){
			cout << " ";
			cout << " ";
		}
		for (int o = 0; o < i; ++o){
			cout << "8";
		}
		cout << endl;
	}
}