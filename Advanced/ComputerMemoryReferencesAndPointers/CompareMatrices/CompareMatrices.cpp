// CompareMatrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a program that reads two integer matrices (2D arrays) from the console and compares them element by element. 
//You are not allowed to use STL.
//
//For better code reusability, you could do the comparison in a function, which returns true if they are equal and false if not.
//Each matrix definition on the console will contain a line with a positive integer number R – the number of rows in the matrix – followed by R lines containing the numbers in the matrix, separated by spaces(each line will have an equal amount of numbers.
//    The matrices will have at most 10 rows and most 10 columns.
//    Print equal if the matrices match, and not equal if they do not match.


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void setArray(int(&arr)[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = 0;
		}
	}
}

void fillArrayFromConsole(int(&arr)[10][10], int rows) {
	string line;
	int num;


	for (int row = 0; row < rows; row++) {
		int col = 0;
		getline(cin, line);
		istringstream iss(line);

		while (iss >> num) {
			arr[row][col++] = num;
		}
	}

}

bool isArraysEquals(int(&firstArr)[10][10], int(&secondArr)[10][10]) {
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			if (firstArr[row][col] != secondArr[row][col]) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int rows;
	cin >> rows;
	cin.ignore();

	int firstArr[10][10];
	setArray(firstArr);
	fillArrayFromConsole(firstArr, rows);

	cin >> rows;
	cin.ignore();

	int secondArr[10][10];
	setArray(secondArr);
	fillArrayFromConsole(secondArr, rows);

	if (isArraysEquals(firstArr, secondArr)) {
		cout << "equal";
	}
	else {
		cout << "not equal";
	}
}