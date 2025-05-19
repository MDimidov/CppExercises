// FillTheMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Filling a matrix regularly (top to bottom and left to right) is boring. Write two methods that fill a size N x N matrix in two different patterns. 
//Input
//You will receive a single integer number N, which describes the dimensions of a square matrix.
//After that you will receive the method(A or B) of filling out the matrix.
//Note: Please pay attention to the separating comma and space!
//Output
//A square matrix of size of N, filled out depending on the pattern.


#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

// Функция за разделяне на низа по определени разделители
vector<string> splitString(const string& str, const string& delimiters) {
	vector<string> result;
	size_t start = 0;
	size_t end = str.find_first_of(delimiters);

	while (end != string::npos) {
		if (end != start) {  // Ако не е празен низ
			result.push_back(str.substr(start, end - start));
		}
		start = end + 1;
		end = str.find_first_of(delimiters, start);
	}

	if (start < str.size()) {
		result.push_back(str.substr(start));  // Добавяме последния фрагмент
	}

	return result;
}

int** createArray(int rows, int cols) {
	int** arr = new int* [rows];
	for (int row = 0; row < rows; row++) {
		arr[row] = new int[cols];
	}

	return arr;
}

void fillArrayMethodA(int**& arr, int rows, int cols) {
	int num = 0;
	for (int col = 0; col < cols; col++) {
		for (int row = 0; row < rows; row++) {
			arr[row][col] = ++num;
		}
	}
}

void fillArrayMethodB(int**& arr, int rows, int cols) {
	int num = 0;
	for (int col = 0; col < cols; col++) {
		if (col % 2 == 0) {
			for (int row = 0; row < rows; row++) {
				arr[row][col] = ++num;
			}
		}
		else {
			for (int row = 0; row < rows; row++) {
				arr[rows - 1 - row][col] = ++num;
			}
		}
	}
}

void printArray(int**& arr, int rows, int cols) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cout << arr[row][col] << " ";
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

int main() {
	string line;
	getline(cin, line);

	string splitters = ", ";

	vector<string> commands = splitString(line, splitters);

	int matrixSize = stoi(commands[0]);

	int** arr = createArray(matrixSize, matrixSize);

	if (commands[1] == "A") {
		fillArrayMethodA(arr, matrixSize, matrixSize);
	}
	else if (commands[1] == "B") {
		fillArrayMethodB(arr, matrixSize, matrixSize);
	}

	printArray(arr, matrixSize, matrixSize);

	deleteArray(arr, matrixSize);
	return 0;
}
