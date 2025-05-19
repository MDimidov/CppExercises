// GaussTrick.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Gauss' Trick
//Write a program that sums all of the numbers in a list in the following order :
//first + last, first + 1 + last - 1, first + 2 + last - 2, … first + n, last - n.


#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> getNums(string& line) {
	istringstream iss(line);
	int num;
	vector<int> result;

	while (iss >> num) {
		result.push_back(num);
	}

	return result;
}

vector<int> getSummedNums(vector<int>& nums) {
	vector<int> summedNums;
	for (int i = 0; i < nums.size() / 2; i++) {
		summedNums.push_back(nums[i] + nums[nums.size() - 1 - i]);
	}

	if (nums.size() % 2 != 0) {
		summedNums.push_back(nums[nums.size() / 2]);
	}

	return summedNums;
}

void printResult(vector<int>& summedNums) {
	for (auto& num : summedNums) {
		cout << num << " ";
	}
}

int main()
{
	string line;
	getline(cin, line);

	vector<int> nums = getNums(line);

	vector<int> summedNums = getSummedNums(nums);

	printResult(summedNums);
}