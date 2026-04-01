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

// Uses a naive approach, increments each time by 1, and halve each time it "fails".
double getLog(double input, long long precision, double base) {
	double exponent = 1;
	double increment = 1;
	
	if (input == base) {
		return 1;
	}
	
	while (true) {
		double roughResult = pow(base, exponent);
		double roughExpectedResult = input;
		double delta = roughResult/roughExpectedResult;
		double tolerance = pow(10, -1*precision);

		if ((delta < (1+tolerance)) && 
		    (delta > (1-tolerance))) {
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
	// Makes sure the precision value is less than 5.
	while (true) {
		printnl("How many front digit places do you want it to be accurate to? (Note: due to floating point limitations, it can only be as precise as >=5 digit points..)"); 
		getInput(precision);
		if (precision > 5){
			cout << "You cant pick a value larger than 5!";
			cout << endl;
		} else {
			break;
		}
	}
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
