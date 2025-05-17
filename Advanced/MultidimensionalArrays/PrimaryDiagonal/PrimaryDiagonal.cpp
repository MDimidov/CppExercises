// PrimaryDiagonal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Primary Diagonal
//Write a program that finds the sum of the matrix primary diagonal.
//Input
//•	On the first line, you are given the integer N – the size of the square matrix.
//•	The next N lines hold the values for every row – N numbers separated by a space.


#include <iostream>

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
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][i];
    }

    // Print sum
    cout << sum;

    // Delete array
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
