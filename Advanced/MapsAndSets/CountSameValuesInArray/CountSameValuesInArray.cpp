// CountSameValuesInArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//Write a program that counts in a given array of double values the number of occurrences of each value. 

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<double> getOccurrences(string& line, unordered_map<double, int>& occurrences) {
	istringstream iss(line);
	double num;

	vector<double> input;

	while (iss >> num) {
		if (!occurrences.count(num)) {
			input.push_back(num);
		}
		occurrences[num]++;
	}

	return input;
}

void printResult(unordered_map<double, int>& occurrences, vector<double>& input) {
	for (const auto& key : input) {
		cout << key << " - " << occurrences[key] << " times" << endl;
	}
}


int main()
{
	string line;
	getline(cin, line);

	unordered_map<double, int> occurrences;
	vector<double> input = getOccurrences(line, occurrences);

	printResult(occurrences, input);
}
