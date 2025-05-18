// SnakeMoves.cpp : This file contains the 'main' function. Program execution begins and ends there.
//4.	Snake Moves
//You are walking in the park and you encounter a snake!You are terrified, and you start running zig - zag, so the snake starts following you.
//You have a task to visualize the snake's path in a square form. A snake is represented by a string. The isle is a rectangular matrix of size NxM. A snake starts going down from the top-left corner and slithers its way down. The first cell is filled 	with the first symbol of the snake, the second cell is filled with the second symbol, etc. The snake is as long as it takes to fill the stairs completely – if you reach the end of the string representing the snake, start again at the beginning. After you fill the matrix with the snake's path, you should print it.
//Input
//•	The input data should be read from the console.It consists of exactly two lines.
//•	On the first line, you'll receive the dimensions of the stairs in the format: "N M", where N is the number of rows, and M is the number of columns. They'll be separated by a single space.
//•	On the second line, you'll receive the string representing the snake.
//Output
//•	The output should be printed on the console.It should consist of N lines.
//•	Each line should contain a string representing the respective row of the matrix.
//Constraints
//•	The dimensions N and M of the matrix will be integers in the range[1 - 12].
//•	The snake will be a string with a length in the range[1 - 20] and will not contain any whitespace characters.


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

void fillArrayFromString(char**& arr, int rows, int cols, string& snakeWord) {
	int snakeIndex = 0;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (row % 2 == 0) {
				arr[row][col] = snakeWord[snakeIndex++ % snakeWord.size()];
			}
			else {
				arr[row][cols - 1 -col] = snakeWord[snakeIndex++ % snakeWord.size()];
			}
		}
	}
}

void printArray(char**& arr, int rows, int cols) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cout << arr[row][col];
		}
		cout << endl;
	}
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

	string snakeWord;
	cin >> snakeWord;

	fillArrayFromString(arr, rows, cols, snakeWord);

	printArray(arr, rows, cols);

	deleteArray(arr, rows);
}