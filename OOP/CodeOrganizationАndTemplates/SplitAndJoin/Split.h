#pragma once

#ifndef SPLIT_H
#define SPLIT_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;



template <typename T>
vector<T> split(const string& line, const char separator) {
	vector<T> result;
	string curr;

	for (auto& ch : line) {
		if (ch == separator) {
			istringstream iss(curr);
			T value;
			iss >> value;
			result.push_back(value);
			curr.clear();
		}
		else {
			curr += ch;
		}
	}

	istringstream iss(curr);
	T value;
	iss >> value;
	result.push_back(value);
	return result;
}

#endif // !SPLIT_H