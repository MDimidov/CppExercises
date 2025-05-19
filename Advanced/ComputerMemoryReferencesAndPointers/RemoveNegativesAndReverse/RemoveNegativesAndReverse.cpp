// RemoveNegativesAndReverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Remove Negative and Reverse
//Read a list of integers, remove all negative numbers from it and print the remaining elements in reversed order.In case there are no elements left in the list, print "empty".


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<unsigned int> getPositiveNums(string& line) {
	int num;
	istringstream iss(line);
	vector<unsigned int> nums;

	while (iss >> num) {
		if (num >= 0) {
			nums.push_back(num);
		}
	}

	return nums;
}

void printNumsInReverseOrder(vector<unsigned int>& nums) {

	if (!nums.empty()) {
		reverse(nums.rbegin(), nums.rend());
		for (auto& num : nums) {
			cout << num << " ";
		}
	}
	else {
		cout << "empty";
	}
}

int main()
{
	string line;
	getline(cin, line);

	vector<unsigned int> nums = getPositiveNums(line);

	printNumsInReverseOrder(nums);
}
