// SquaresInMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//2X2 Squares in Matrix
//Find the count of 2 x 2 squares of equal chars in a matrix.
//Input
//•	On the first line, you are given the integers rows and cols – the matrix's dimensions.
//•	Matrix characters come at the next rows lines(space separated).
//Output
//•	Print the number of all the squares matrixes you have found.


#include <iostream>

using namespace std;

char** createArray(int rows, int cols) {
	char** arr = new char* [rows];
	for (int row = 0; row < rows; row++) {
		arr[row] = new char[cols + 1];
		arr[row][cols] = '\0';
	}

	return arr;
}

void fillArrayFromConsoleAndGetAllUniqueSymbols(char**& arr, int rows, int cols) {
	char symbol;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cin >> symbol;
			arr[row][col] = symbol;
		}
	}
}

bool isSubMatrixValid(char**& arr, int rowIndex, int colIndex) {
	if (arr[rowIndex][colIndex] == arr[rowIndex + 1][colIndex] &&
		arr[rowIndex][colIndex] == arr[rowIndex][colIndex + 1] &&
		arr[rowIndex][colIndex] == arr[rowIndex + 1][colIndex + 1]) {
		return true;
	}

	return false;
}

int getEqualsMatrix(char**& arr, int rows, int cols) {
	int result = 0;
	for (int row = 0; row < rows - 1; row++) {
		for (int col = 0; col < cols - 1; col++) {
			if (isSubMatrixValid(arr, row, col)) {
				result++;
			}
		}
	}

	return result;
}

void deleteArray(char**& arr, int rows) {
	for (int row = 0; row < rows; row++) {
		delete[] arr[row];
	}

	delete[] arr;
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	char** arr = createArray(rows, cols);

	fillArrayFromConsoleAndGetAllUniqueSymbols(arr, rows, cols);

	int equalMatrix = getEqualsMatrix(arr, rows, cols);

	cout << equalMatrix;

	deleteArray(arr, rows);
}