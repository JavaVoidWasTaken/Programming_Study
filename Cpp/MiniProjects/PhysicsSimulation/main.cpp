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
double gravity = -0.4;
double initialSpeed = 5;
double mass = 1000;
string output = "";


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

double truncateLastDigits(double input, int decimals){
	int powerOfTen = pow(10, decimals);
	return floor(input*powerOfTen)/powerOfTen;
}

void appendOutput(string beginning, double value, string end){
	output.append(beginning);
	output.append(to_string(value));
	output.append(end);
}

void appendDataSummary(double until){
	appendOutput("Current mass              : ", mass, "\n");
	appendOutput("Current gravity           : ", gravity, "\n");
	appendOutput("Current Height            : ", truncateLastDigits(getFinalPosition(until), 3) + 0.001, "\n");
	appendOutput("Current Speed             : ", truncateLastDigits(getCurrentSpeed(until), 3) + 0.001, "\n");
	appendOutput("Current Potential Energy  : ", round(getPotentialEnergy(until)), "\n");
	appendOutput("Current Kinetic Energy    : ", round(getKineticEnergy(until)), "\n");
	appendOutput("Current Mechanical Energy : ", getPotentialEnergy(until) + getKineticEnergy(until), "\n");
}

void printAndEmptyOutput(){
	cout << output;
	output = "";
}

void appendChart(double until){
	for (int y = canvasSize; y >= 0; --y){
		for (int x = 0; x < canvasSize*2; ++x){
			if (round(getFinalPosition(x)) == y && x <= until){
				output.append("O");
			} else {
				output.append("-");
			}
		}
		output.append("\n");
	}
}

void drawPlot(double until){
	appendDataSummary(until);
	appendChart(until);
	printAndEmptyOutput();
}


int main(){
	int x = 1;

	for (float i = 0; i < canvasSize*2; i += 0.1){
		cout << "\n" << endl;
		drawPlot(i);
		if (getFinalPosition(i) < 0){
			break;
		}
		this_thread::sleep_for(chrono::milliseconds(5));
	}
}
