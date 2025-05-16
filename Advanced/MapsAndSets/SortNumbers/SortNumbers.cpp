// SortNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

void setNums(string& line, set<double>& nums) {
	istringstream iss(line);
	double num;

	while (iss >> num) {
		nums.insert(num);
	}
}

void printNums(set<double>& nums) {
	int index = 0;

	for (auto& num : nums) {
		if (index++ != 0) {
			cout << " <= ";
		}

		cout << num;
	}
}

int main()
{
	string line;
	getline(cin, line);

	set<double> nums;

	setNums(line, nums);

	printNums(nums);
}
