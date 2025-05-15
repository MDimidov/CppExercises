// ParkingLot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Parking Lot
//Write a program that :
//•	Records a car number for every car that enters the parking lot.
//•	Removes a car number when the car leaves the parking lot.
//The input will be a string in the format : "direction, carNumber".You will be receiving commands until the "END" command is given.
//Print the car numbers of the cars, sorted by car numbers in ascending order, which are still in the parking lot :


#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

void addOrRemoveCar(string& line, set<string>& carNumbers) {
	istringstream iss(line);
	string direction;
	string carNumber;

	iss >> direction >> carNumber;
	if (direction.find("IN") != string::npos) {
		carNumbers.insert(carNumber);
	}
	else {
		carNumbers.erase(carNumber);
	}
}

void printResult(set<string>& carNumbers) {
	if (carNumbers.empty()) {
		cout << "Parking Lot is Empty";
	}
	else {
		for (auto& carNumber : carNumbers) {
			cout << carNumber << endl;
		}
	}
}
int main()
{
	string line;
	getline(cin, line);
	set<string> carNumbers;

	while (line != "END") {
		addOrRemoveCar(line, carNumbers);

		getline(cin, line);
	}

	printResult(carNumbers);
}
