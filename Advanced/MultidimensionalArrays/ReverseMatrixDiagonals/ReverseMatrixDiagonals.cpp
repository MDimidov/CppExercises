// ReverseMatrixDiagonals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Reverse Matrix Diagonals
//You are given a matrix(2D array) of integers.You have to print the matrix diagonal but in reversed order.Print each left to right diagonal on a new line.
//Input
//On the first line, single integer the number R of rows in the matrix.On each of the next R lines, C numbers are separated by single spaces.Note that R and C may have different values.
//Output
//The output should consist of R lines, each consisting of exactly C characters, separated by spaces, representing the left to right matrix diagonals reversed.
//
//Constraints
//All the integers will be in the range[1….1000].


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

void printArrayDiagonals(int**& arr, int rows, int cols) {
	int maxSumIndex = rows - 1 + cols;

	while (--maxSumIndex >= 0) {
		for (int row = rows - 1; row >= 0; row--) {
			for (int col = cols - 1; col >= 0; col--) {
				if (row + col == maxSumIndex) {
					cout << arr[row][col] << " ";
				}
				else if (row + col < maxSumIndex) {
					break;
				}
			}
		}
		cout << endl;
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

	printArrayDiagonals(arr, rows, cols);
	deleteArray(arr, rows);
}
