// MaximalSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Maximal Sum
//Write a program that reads a rectangular integer matrix of size N x M and finds the square 3 x 3 with a maximal sum of its elements.
//Input
//•	On the first line, you will receive the rows N and columns M.
//•	On the next N lines, you will receive each row with its elements.
//Print the elements of the 3 x 3 square as a matrix, along with their sum.See the format of the output below.


#include <iostream>
#include <climits>

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

int getSumOfSubArray(int**& arr, int rowIndex, int colIndex) {
	int sum = 0;
	for (int row = rowIndex; row < rowIndex + 3; row++) {
		for (int col = colIndex; col < colIndex + 3; col++) {
			sum += arr[row][col];
		}
	}

	return sum;
}

void setMaxSubArr(int**& arr, int rowIndex, int colIndex, int(&subArr)[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			subArr[row][col] = arr[rowIndex + row][colIndex + col];
		}
	}
}

int getMaxSumAndSubArray(int**& arr, int rows, int cols, int(&subArr)[3][3]) {
	int maxSum = INT_MIN;
	int currSum;

	for (int row = 0; row < rows - 2; row++) {
		for (int col = 0; col < cols - 2; col++) {
			currSum = getSumOfSubArray(arr, row, col);
			if (currSum > maxSum) {
				maxSum = currSum;
				setMaxSubArr(arr, row, col, subArr);
			}
		}
	}

	return maxSum;
}

void printResult(int maxSum, int(&subArr)[3][3]) {
	cout << "Sum = " << maxSum << endl;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			cout << subArr[row][col] << " ";
		}

		cout << endl;
	}
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	int** arr = createArray(rows, cols);

	fillArrayFromConsole(arr, rows, cols);

	int subArr[3][3];
	int maxSum = getMaxSumAndSubArray(arr, rows, cols, subArr);

	printResult(maxSum, subArr);
}