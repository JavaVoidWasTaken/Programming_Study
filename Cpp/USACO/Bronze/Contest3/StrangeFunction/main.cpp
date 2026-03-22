#include <iostream>
#include <string>
using namespace std;
using ll = long long;

void print (string input) {
	cout << input;
}

void strangeFunction (string& input) {
	input = "test";
}

int main() {
	ll testCaseAmount, result = 0;
	string input;
	cin >> testCaseAmount;

	for (ll i = 0; i < testCaseAmount; ++i) {
		cin >> input;
		while (!input.empty()){ 
			strangeFunction(input);
			print(input);
			++result;
		}
		cout << result << endl;
	}

}
