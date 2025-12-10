#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using ll = long long;


double canvasSize = 40;
double gravity = -0.3;
double initialSpeed = 5; 
double mass = 50;


double getFinalPosition(double time){
	double output = (initialSpeed*time) + (0.5*gravity*(pow(time, 2)));
	return output;
}

double getCurrentSpeed(double time){
	double output = initialSpeed + gravity*time;
	return output;
}

double getPotentialEnergy(double time){
	double output = getFinalPosition(time) * mass * gravity * -1;
	return output;
}

double getKineticEnergy(double time){
	double output = 0.5*mass*pow(getCurrentSpeed(time),2);
	return output;
}

int drawPlot(double until){

	if (getFinalPosition(until) < 0){
		return 0;
	}

	cout << "Current mass              : " << mass << '\n';
	cout << "Current gravity           : " << gravity << '\n';
	cout << "Current Height            : " << getFinalPosition(until) << '\n';
	cout << "Current Speed             : " << getCurrentSpeed(until) << '\n';
	cout << "Current Potential Energy  : " << getPotentialEnergy(until) << '\n';
	cout << "Current Kinetic Energy    : " << getKineticEnergy(until) << '\n';
	cout << "Current Mechanical Energy : " << getPotentialEnergy(until) + getKineticEnergy(until) << '\n';

	for (int y = canvasSize; y >= 0; --y){
		for (int x = 0; x < canvasSize*2; ++x){

			if (round(getFinalPosition(x)) == y && x <= until){
				cout << 'O';
			} else {
				cout << '-';
			}

		}
		cout << '\n';
	}
	return 1;
}

int main(){
	int x = 1;

	for (float i = 0; i < canvasSize*2; i += 0.1){
		cout << "\n" << endl;
		x = drawPlot(i);
		if (x == 0){
			break;
		}	
		this_thread::sleep_for(chrono::milliseconds(30));
	}
}
