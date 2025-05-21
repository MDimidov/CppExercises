// TheMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//2.	The Matrix
//Given a matrix, write a program that calculates the SUM of the prime numbers BELOW the two diagonals.
//HINT – a prime number is a number that can be divided by 1 and himself(1, 3, 5, 7, 13, 17 ...)
//The maximum size of matrix should be 100x100


#include <iostream>
#include <vector>

using namespace std;

struct Indexes {
	Indexes(int r, int c) {
		row = r;
		col = c;
	}

	int row{ -1 };
	int col{ -1 };
};

int** setMatrix(int size) {
	int** arr = new int* [size];
	for (int row = 0; row < size; row++) {
		arr[row] = new int[size];
	}

	return arr;
}

void fillMatrixFromConsole(int** arr, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			cin >> arr[row][col];
		}
	}
}

vector<Indexes> getIndexesOfDiagonals(int** arr, int size) {
	vector<Indexes> indexes;
	for (int i = size - 1; i > size / 2 - 1; i--) {
		Indexes index(i, size - 1 - i);
		indexes.push_back(index);
	}

	for (int i = size - 1; i > (size % 2 == 0 ? size / 2 - 1 : size / 2); i--) {
		Indexes index(i, i);
		indexes.push_back(index);
	}

	return indexes;
}

bool isPrimeNum(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) return false;
	}

	return true;
}

int getSumOfPrimeNums(int** arr, int size, vector<Indexes>& indexes){
	int sum = 0;
	for (auto& index : indexes) {
		for (int row = index.row + 1; row < size; row++) {
			int num = arr[row][index.col];

			if (isPrimeNum(num)) {
				sum += num;
			}
		}
	}

	return sum;
}

int main()
{
	int size;
	cin >> size;

	int** arr = setMatrix(size);

	fillMatrixFromConsole(arr, size);

	vector<Indexes> indexes = getIndexesOfDiagonals(arr, size);

	cout << getSumOfPrimeNums(arr, size, indexes);
}