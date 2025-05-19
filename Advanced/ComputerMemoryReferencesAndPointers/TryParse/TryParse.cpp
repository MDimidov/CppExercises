// TryParse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a program that:
//•	Reads two strings, each of which is either a valid integer or contains only letters
//•	Try to parse them into integer numbers
//o	If both numbers can be parsed, calculate and print sum of the parsed numbers
//o	Otherwise, two lines are printed :
//	One of them for the first number, the other for the second number
//	Each of those lines contains either the input string for that number, but if the number was not successfully parsed, the line starts with "[error] " followed by the input string for the number


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool TryParseInt(string& input, int& result) {
	stringstream ss(input);
	ss >> result;

	return ss.eof() && !ss.fail();
}

int main()
{
	string input1, input2;
	cin >> input1 >> input2;

	int num1, num2;
	bool isNum1Valid = TryParseInt(input1, num1);
	bool isNum2Valid = TryParseInt(input2, num2);

	if (isNum1Valid && isNum2Valid) {
		cout << num1 + num2;
	}
	else {
		cout << (!isNum1Valid ? "[error] " : "") << input1 << endl;
		cout << (!isNum2Valid ? "[error] " : "") << input2 << endl;
	}
}
