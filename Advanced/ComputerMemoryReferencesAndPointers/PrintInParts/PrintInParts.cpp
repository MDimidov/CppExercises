// PrintInParts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Print in Parts
//Write a program that receives a 2 - dimensional dynamic array with N rows and M columns and returns the first R rows and C columns.
//You are not allowed to use STL.


#include <iostream>

using namespace std;

int** setArray(int rows, int cols) {
	int** arr = new int* [rows];

	for (int row = 0; row < rows; row++) {
		arr[row] = new int[cols];
	}

	return arr;
}

void fillArrayFromConsole(int** arr, int rows, int cols) {

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cin >> arr[row][col];
		}
	}
}

void printArrayToGivenIndex(int** arr, int printRows, int printCols) {
	for (int row = 0; row < printRows; row++) {
		for (int col = 0; col < printCols; col++) {
			cout << arr[row][col] << " ";
		}
		
		cout << endl;
	}
}

void deleteArray(int** arr, int rows) {
	for (int row = 0; row < rows; row++) {
		delete[] arr[row];
	}
	delete[] arr;
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	int** arr = setArray(rows, cols);

	fillArrayFromConsole(arr, rows, cols);

	int printRows, printCols;
	cin >> printRows >> printCols;

	if (printRows > rows) printRows = rows;
	if (printCols > cols) printCols = cols;

	printArrayToGivenIndex(arr, printRows, printCols);

	deleteArray(arr, rows);
}