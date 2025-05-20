// Rust.cpp : This file contains the 'main' function. Program execution begins and ends there.
//2.	Rust
//You are given a 10x10 matrix representing a metal square, which has begun to rust.There are 3 types of symbols in the matrix – a . (dot)means a healthy part of the metal, a # indicates a rust - resistant part, and a !indicates a part that has begun to rust.
//There may be 0, 1 or more parts that have begun to rust.
//The rust spreads from a rusty cell to healthy cells by "infecting" adjacent cells directly above, to the right, below and to the left of itself(no diagonals), at the same time.The rust cannot infect cells that are indicated as rust resistant.Let's define the time it takes for all cells adjacent to a rusty cell to get infected as 1 unit.
//After reading the matrix, read a single integer – the elapsed time in units(as defined above) – and print a matrix representing how the metal square will look after the rust has been acting on it for that amount of time.


#include <iostream>

using namespace std;

void fillArrayFromConsole(char(&arr)[10][11]) {
	string line;

	for (int row = 0; row < 10; row++) {
		cin >> line;
		for (int col = 0; col < 10; col++) {
			arr[row][col] = line[col];
		}

		arr[row][10] = '\0';
	}
}

void multiplyRustPsn(char(&arr)[10][11], int row, int col, char(&newRustArr)[10][11]) {
	int dRow[] = { -1, 1, 0, 0 };
	int dCol[] = { 0, 0, -1, 1 };

	for (int d = 0; d < 4; d++) {
		int r = row + dRow[d];
		int c = col + dCol[d];

		if (r >= 0 && r < 10 && c >= 0 && c < 10 && arr[r][c] == '.') {
			newRustArr[r][c] = '!';
		}
	}
}

void combineNewRustWithOldRust(char(&arr)[10][11], char(&newRustArr)[10][11]) {
	char symbol;
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			symbol = newRustArr[row][col];
			if (symbol == '!') {
				arr[row][col] = symbol;
			}
		}
	}
}

void fillArrayWithDots(char(&newRustArr)[10][11]) {
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) {
			newRustArr[r][c] = '.';
		}
		newRustArr[r][10] = '\0';
	}
}

void multiplyRust(char(&arr)[10][11]) {
	char newRustArr[10][11];
	fillArrayWithDots(newRustArr);

	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			if (arr[row][col] == '!') {
				multiplyRustPsn(arr, row, col, newRustArr);
			}
		}
	}

	combineNewRustWithOldRust(arr, newRustArr);
}

void printResult(char(&arr)[10][11]) {
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			cout << arr[row][col];
		}
		cout << endl;
	}
}

int main()
{
	char arr[10][11];

	fillArrayFromConsole(arr);

	int rustMultiply;
	cin >> rustMultiply;

	for (int i = 0; i < rustMultiply; i++) {
		multiplyRust(arr);
	}

	printResult(arr);
}
