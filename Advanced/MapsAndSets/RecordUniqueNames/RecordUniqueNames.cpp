// RecordUniqueNames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Record Unique Names
//Write a program, which will take a list of names and print only the unique names in the list.


#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	set<string> names;
	vector<string> sortedNames;
	string line;
	for (int i = 0; i < n; i++) {
		getline(cin, line);

		if (!names.count(line)) {
			sortedNames.push_back(line);
			names.insert(line);
		}
	}

	for (auto& name : sortedNames) {
		cout << name << endl;
	}
}