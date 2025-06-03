#pragma once
#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <iostream>
#include <iterator>
#include <set>

using namespace std;

template <typename Container>
void printContainer(typename Container::const_iterator begin, typename Container::const_iterator end) {
	for (auto it = begin; it != end; it++) {
		if (it != begin) {
			cout << " ";
		}
		cout << *it;
	}
}

#endif // !define PRINT_UTILS_H
