//Sum Of Vectors
//You are given a program in a Main.cpp file that reads :
//•	How many couples of data do you have
//•	Elements data 1
//•	Elements data 2
//The number of couples is an integer, the datas are strings.
//With the couples in the data vectors, you have to create a new vector with the concatenation of the previous 2 vectors' data.
//Write a function that does the concatenation
//Your task is to study the code in Main.cpp and implement the SumOfVectors function in SumOfVectors.h(which is #include - d by Main.cpp), so that Main.cpp compiles successfully and accomplishes the task described.Your SumOfVectors.h file should resemble the following :

#pragma once
#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <string>
#include <vector>

using namespace std;

vector<string> operator+(const vector<string>& vec1, const vector<string>& vec2) {
	vector<string> result;

	for (int i = 0; i < min(vec1.size(), vec2.size()); i++) {
		result.push_back(vec1[i] + " " + vec2[i]);
	}

	return result;
}

#endif // !SUMOFVECTORS_H
