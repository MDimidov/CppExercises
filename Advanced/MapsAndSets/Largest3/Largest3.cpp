// Largest3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Largest 3
//Read a list of real numbers and print the largest 3 of them.If less than 3 numbers exit, print all of them.


#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

set<double, greater<double>> getOrderedNums(string& line) {
	set<double, greater<double>> nums;
	istringstream iss(line);
	double num;

	while (iss >> num) {
		nums.insert(num);
	}

	return nums;
}

void printFirst3Nums(set<double, greater<double>>& nums) {
	int index = 0;

	for (auto& num : nums) {
		if (index >= 3) {
			break;
		}

		if (index++ != 0) {
			cout << " ";
		}

		cout << num;
	}
}

int main()
{
	string line;
	getline(cin, line);

	set<double, greater<double>> nums = getOrderedNums(line);

	printFirst3Nums(nums);
}
