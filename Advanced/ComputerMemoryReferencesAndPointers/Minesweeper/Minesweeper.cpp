// Minesweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//You are given an N by M matrix (N and M are two integers entered on the console), in which the cells contain single characters – either a . (dot) or a ! (exclamation mark) – representing "empty" or "mined" positions.
//Write a program that prints an N by M matrix, where each cell contains a number, representing how many adjacent cells, including itself, are "mined".
//Each cell in a matrix has at most 8 adjacent cells – the cells directly above, below, to the left, to the right, as those diagonally – to the left and above, to the right and above, to the right and below and to the left and below.
//You are not allowed to use STL!


#include <iostream>

using namespace std;

char** getCharArray(int rows, int cols) {
	char** arr = new char* [rows];

	for (int row = 0; row < rows; row++) {
		arr[row] = new char[cols + 1];
		arr[row][cols] = '\0';
	}

	return arr;
}

void fillArrayFromConsole(char** arr, int rows, int cols) {
	string line;
	
	for (int row = 0; row < rows; row++) {
		cin >> line;

		for (int i = 0; i < cols; i++) {
			arr[row][i] = line[i];
		}
	}
}

int getSiblingCount(char** arr, int row, int col, int rows, int cols) {
	int beginingRow = row - 1;
	int beginingCol = col - 1;

	if (beginingRow < 0) beginingRow = 0;
	if (beginingCol < 0) beginingCol = 0;

	int endRow = row + 2;
	int endCol = col + 2;

	if (endRow > rows) endRow = rows;
	if (endCol > cols) endCol = cols;

	int cntMined = 0;

	for (int r = beginingRow; r < endRow; r++) {
		for (int c = beginingCol; c < endCol; c++) {
			if (arr[r][c] == '!') {
				cntMined++;
			}
		}
	}

	return cntMined;
}

int** getResultArray(char** arr, int rows, int cols) {
	int** resultArr = new int* [rows];
	for (int row = 0; row < rows; row++) {
		resultArr[row] = new int[cols];
		for (int col = 0; col < cols; col++) {
			resultArr[row][col] = getSiblingCount(arr, row, col, rows, cols);
		}
	}

	return resultArr;
}

void printResultArr(int** arr, int rows, int cols) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cout << arr[row][col];
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

void deleteArray(char** arr, int rows) {
	for (int row = 0; row < rows; row++) {
		delete[] arr[row];
	}

	delete[] arr;
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	char** arr = getCharArray(rows, cols);

	fillArrayFromConsole(arr, rows, cols);

	int** resultArray = getResultArray(arr, rows, cols);

	printResultArr(resultArray, rows, cols);

	deleteArray(arr, rows);
	deleteArray(resultArray, rows);
}