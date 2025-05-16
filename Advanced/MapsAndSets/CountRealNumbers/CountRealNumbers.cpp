// CountRealNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Count Real Numbers
//Read a list of real numbers and print them in ascending order along with their number of occurrences.


#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

map<double, int> getNumbers(string& line) {
	istringstream iss(line);
	double num;

	map<double, int> nums;
	while (iss >> num) {
		nums[num]++;
	}

	return nums;
}

void printResult(map<double, int>& nums) {
	for (auto& kvp : nums) {
		cout << kvp.first << " -> " << kvp.second << endl;
	}
}

int main()
{
	string line;
	getline(cin, line);

	map<double, int> numbers = getNumbers(line);

	printResult(numbers);
}