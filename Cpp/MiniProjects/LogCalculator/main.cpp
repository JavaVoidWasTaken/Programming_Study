#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void getInput(auto& input) {
	cin >> input;
}

void printnl(auto input) {
	cout << input;
	cout << "\n> ";
}

double truncate (double input, double precision) {
	double result;
	result = input*pow(10, precision);
	result = trunc(result);
	result = result/pow(10, precision);
	return result;
}

double getLog(double input, long long precision, double base) {
	double exponent = 1;
	double increment = 1;
	
	if (input == base) {
		return 1;
	}
	
	while (true) {
		if (truncate(pow(base, exponent), precision) == truncate(input, precision)) {
			return exponent;
		}
		if (pow(base, exponent) < input) {
			exponent += increment;
			if (pow(base, exponent) > input) {
				increment /= 2;
			}
		} else if (pow(base, exponent) > input) {
			exponent -= increment;
			if (pow(base, exponent) < input) {
				increment /= 2;
			}
		}
	}
}


int main() {
	long long inputSize, precision;
	vector<double> input;
	double temp, base;

	printnl("How many inputs?");
	getInput(inputSize);
	printnl("How many decimal places do you want it to be accurate to? (Note: due to floating point limitations, it can only be as precise as >=5 decimal points..)"); 
	getInput(precision);
	printnl("What base do you want to use?");
	getInput(base);

	for (int i = 0; i < inputSize; ++i) {
		cin >> temp;
		input.push_back(temp);
	}
	
	printnl("");
	for (int i = 0; i < inputSize; ++i) {
		printnl(getLog(input[i], precision, base));
	}
}
