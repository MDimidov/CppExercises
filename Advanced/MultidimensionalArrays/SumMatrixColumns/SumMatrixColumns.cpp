// SumMatrixColumns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Sum Matrix Columns
//Write a program that read a matrix from the console and prints the sum for each column.On the first line, you will get two integers : the number of matrix rows and columns.On the following rows lines, you will get elements for each column separated with a space.


#include <iostream>

using namespace std;

int main()
{
	int row, col;
	cin >> row >> col;

	// Create an array
	int** arr = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}


	// Fill the array
	int num;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			cin >> num;
			arr[r][c] = num;
		}
	}

	// Sum columns
	for (int c = 0; c < col; c++) {
		int sum = 0;
		for (int r = 0; r < row; r++) {
			sum += arr[r][c];
		}
		cout << sum << endl;
	}

	// Delete arr from memory
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;

}
