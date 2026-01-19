#include "inout.h"
#include <iostream>
using namespace std;

int readNumber(){
	int output;
	cin >> output;
	return output+1;
}

void writeAnswer(int input){
	cout << input << '\n';
}

