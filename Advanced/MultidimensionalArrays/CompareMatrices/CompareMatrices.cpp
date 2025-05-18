// CompareMatrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Compare Matrices
//Write a program that reads two integer matrices(2D arrays) from the console and compares them element by element.For better code reusability, you could do the comparison in a function, which returns true if they are equal and false if not.
//Each matrix definition on the console will contain a line with a positive integer number R – the number of rows in the matrix – followed by R lines containing the numbers in the matrix, separated by spaces(each line will have an equal amount of numbers.
//	The matrices will have at most 10 rows and most 10 columns.
//	Print equal if the matrices match, and not equal if they do not match.


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void fillEmptyArray(unsigned int(&arr)[10][10]) {
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			arr[row][col] = 0;
		}
	}
}

void fillArrayRow(unsigned int (&arr)[10][10], string& line, int row) {
	istringstream iss(line);
	int num;

	int col = 0;
	while (iss >> num) {
		arr[row][col++] = num;
	}
}

bool isArraysEquals(unsigned int(&arr1)[10][10], unsigned int(&arr2)[10][10]) {
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			if (arr1[row][col] != arr2[row][col]) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	// Fill First Array
	unsigned int firstArr[10][10];
	fillEmptyArray(firstArr);

	int n;
	cin >> n;
	cin.ignore();

	string line;

	for (int i = 0; i < n; i++) {
		getline(cin, line);
		fillArrayRow(firstArr, line, i);
	}

	// Fill Second Array
	unsigned int secondArr[10][10];
	fillEmptyArray(secondArr);

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, line);
		fillArrayRow(secondArr, line, i);
	}

	// Check if arrays are equals
	if (isArraysEquals(firstArr, secondArr)) {
		cout << "equal";
	}else{
		cout << "not equal";
	}
}
