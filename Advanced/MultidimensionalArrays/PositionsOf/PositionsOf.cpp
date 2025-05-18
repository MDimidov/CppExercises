// PositionsOf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Positions Of
//Write a program that reads a matrix of integers from the console, then a number, and prints all the positions at which that number appears in the matrix.
//The matrix definition on the console will contain a line with two positive integer numbers R and C – the number of rows and columns in the matrix – followed by R lines, each containing C numbers(separated by spaces), representing each row of the matrix.
//The number you will need to find the positions of will be entered on a single line, after the matrix.
//You should print each position on a single line – first print the row, then the column at which the number appears.
//If the number does not appear in the matrix, print not found.


#include <iostream>

using namespace std;

int** createArray(int rows, int cols) {
	int** arr = new int* [rows];
	for (int row = 0; row < rows; row++) {
		arr[row] = new int[cols];
	}

	return arr;
}

void fillArrayFromConsole(int**& arr, int rows, int cols) {
	int num;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cin >> num;
			arr[row][col] = num;
		}
	}
}

void printPsnOfFoundedElements(int**& arr, int rows, int cols, int searchingElement) {
	bool isFound = false;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (searchingElement == arr[row][col]) {
				cout << row << " " << col << endl;
				isFound = true;
			}
		}
	}

	if (!isFound) {
		cout << "not found";
	}
}

void deleteArray(int**& arr, int rows) {
	for (int row = 0; row < rows; row++) {
		delete[] arr[row];
	}

	delete[] arr;
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	int** arr = createArray(rows, cols);
	
	fillArrayFromConsole(arr, rows, cols);

	int searchingElement;
	cin >> searchingElement;
	printPsnOfFoundedElements(arr, rows, cols, searchingElement);
	deleteArray(arr, rows);
}
