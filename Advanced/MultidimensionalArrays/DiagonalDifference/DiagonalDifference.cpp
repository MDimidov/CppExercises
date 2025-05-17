// DiagonalDifference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a program that finds the difference between the sums of the square matrix diagonals (absolute value).
//Input
//•	On the first line, you are given the integer N – the size of the square matrix.
//•	The next N lines hold the values for every row – N numbers separated by a space.
//Output
//•	Print the absolute difference between the sums of the primary and the secondary diagonal.


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Create array
	int n;
	cin >> n;

	int** arr = new int* [n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	// Fill array
	int num;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> num;
			arr[row][col] = num;
		}
	}

	// Find sum of primary diagonal
	int sumPrimary = 0;
	for (int i = 0; i < n; i++) {
		sumPrimary += arr[i][i];
	}

	// Find sum of secondary diagonal
	int sumSecondary = 0;
	for (int i = 0; i < n; i++) {
		sumSecondary += arr[i][n - 1 - i];
	}

	// Print difference between diagonals
	cout << abs(sumPrimary - sumSecondary);

	// Delete array
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

}
