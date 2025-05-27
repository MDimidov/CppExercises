//Operators
//You are given code for a program that reads a specified number of lines from the console, and then formats them in the following way :
//•	It prepends two lines of characters before the lines from the input
//•	It then places each of the original lines prefixing it with its number(starting from 1) followed by ". "
//•	It then appends a line of characters at the end
//The program does all this (you don't have to do input, output, or determine line numbers), but it uses operators which aren’t defined in the C++ language.
//	Your task is to study the code in OperatorsMain.cpp and implement the necessary operators in Operators.h(which is #include - d by OperatorsMain.cpp), so that OperatorsMain.cpp compiles successfully and accomplishes the task described.Your Operators.h file should resemble the following :

#pragma once
#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string>& operator << (vector<string>& vec, const string& newLine) {
	vec.push_back(newLine);
	return vec;
}

ostream& operator << (ostream& os, const vector<string>& vec) {
	for (auto& line : vec) {
		os << line << endl;
	}

	return os;
}

string operator+(const string& lhs, const int rhs) {
	return lhs + to_string(rhs);
}

string operator+(const int lhs, const string& rhs) {
	return to_string(lhs) + rhs;
}


#endif // !OPERATORS_H
