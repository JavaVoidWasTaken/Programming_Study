#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
	ll testCaseSize;
	ll input;
	ll highestValue = 0;
	ll calculate;
	vector<ll> x;
	vector<ll> y;

	cin >> testCaseSize;

	for (int i = 0; i < testCaseSize; ++i)
	{
		cin >> input;
		x.push_back(input);
	}

	for (int i = 0; i < testCaseSize; ++i)
	{
		cin >> input;
		y.push_back(input);
	}

	for (int i = 0; i < testCaseSize; ++i)
	{
		for (int o = i; o < testCaseSize; ++o)
		{	
			calculate = floor(pow((x[i]-x[o]), 2) + pow((y[i]-y[o]), 2));
			highestValue = max(highestValue, calculate);
		}
	}

	cout << highestValue;
}