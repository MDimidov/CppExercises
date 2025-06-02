#pragma once

#ifndef SPLIT_H
#define SPLIT_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
vector<T> split(const string& line, const char delimiter) {
	vector<T> result;
	string curr;

	for (char& ch : line) {
		if (ch == delimeter) {
			result.push_back(T(curr));
			curr.clear();
		}
		else {
			curr += ch;
		}
	}

	result.push_back(T(curr));
	return result;
}

#endif // !SPLIT_H