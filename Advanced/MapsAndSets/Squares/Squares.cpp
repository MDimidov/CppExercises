// Squares.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Squares
//Read a list of integers and extract all square numbers from it and print them in descending order.A square number is an integer that is the square of any integer.For example, 1, 4, 9, and 16 are square numbers.


#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

void setSquaredNums(string& line, map<int, int, greater<int>>& squaredNums) {
	istringstream iss(line);
	int num;
	int sqrtNum;
	while (iss >> num) {
		sqrtNum = static_cast<int>(sqrt(num));
		if (sqrtNum * sqrtNum == num) {
			squaredNums[num]++;
		}
	}
}

void printNums(map<int, int, greater<int>>& squaredNums) {
	int index = 0;
	for (auto& kvp : squaredNums) {
		if (index++ != 0) {
			cout << " ";
		}

		for (int i = 0; i < kvp.second; i++) {
			if (i != 0) {
				cout << " ";
			}

			cout << kvp.first;
		}
	}
}

int main()
{
	string line;
	getline(cin, line);

	map<int, int, greater<int>> squaredNums;

	setSquaredNums(line, squaredNums);
	printNums(squaredNums);
}
