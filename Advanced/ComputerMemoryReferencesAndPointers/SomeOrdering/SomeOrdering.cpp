// SomeOrdering.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Some Ordering
//Write a program that receives a string with N elements and returns two other strings – the first one is the same string with lower - case letters only, and the second one is the same string with upper - case letters only.Write the program with the help of pointers!
//You are not allowed to use STL.


#include <iostream>
#include <string>

using namespace std;

string getLowerString(string& line) {
	string result = "";
	for (int i = 0; i < line.size(); i++) {
		result += tolower(line[i]);
	}

	return result;
}

string getUpperString(string& line) {
	string result = "";
	for (int i = 0; i < line.size(); i++) {
		result += toupper(line[i]);
	}

	return result;
}

int main()
{
	string line;
	getline(cin, line);

	string result = getLowerString(line);
	cout << result << endl;

	result = getUpperString(line);
	cout << result;
}
