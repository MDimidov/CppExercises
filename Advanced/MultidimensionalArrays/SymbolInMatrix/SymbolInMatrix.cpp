// SymbolInMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Symbol in Matrix
//Write a program that reads N, a number representing rows and cols of a matrix.On the next N lines, you will receive rows of the matrix.Each row consists of ASCII characters.After that, you will receive a symbol.Find the first occurrence of that symbol in the matrix and print its position in the format : "({row}, {col})".If there is no such symbol print an error message : "{symbol} does not occur in the matrix ".


#include <iostream>

using namespace std;

void deleteArray(char**& arr, int size) {
	for (int i = 0; i < size; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}

int main()
{
	int n;
	cin >> n;

	string line;
	char** arr = new char* [n];

	// Create array and fill values
	for (int i = 0; i < n; i++) {
		cin >> line;
		arr[i] = new char[n + 1];
		for (int j = 0; j < n; j++) {
			if (i == n) {
				arr[i][j] = '\0';
			}
			else {
				arr[i][j] = line[j];
			}
		}
	}

	// Check if the symbol exist
	char symbol;
	cin >> symbol;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (arr[row][col] == symbol) {
				cout << "(" << row << ", " << col << ")";
				deleteArray(arr, n);
				return 0;
			}
		}
	}

	cout << symbol << " does not occur in the matrix";
	deleteArray(arr, n);
}