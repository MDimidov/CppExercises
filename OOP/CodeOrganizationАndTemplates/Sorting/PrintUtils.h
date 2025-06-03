#pragma once
#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <iostream>
#include <vector>

template <typename T>
void printVector(vector<T>& vec) {
	for (T& element : vec) {
		cout << element << " ";
	}
}
#endif // !define PRINT_UTILS_H
