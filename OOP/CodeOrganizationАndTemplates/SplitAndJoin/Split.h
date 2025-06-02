#pragma once

#ifndef SPLIT_H
#define SPLIT_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
void setCurrToVector(string& curr, vector<T>& vec) {
	istringstream iss(curr);
	T value;
	iss >> value;
	vec.push_back(value);
	curr.clear();
}

template <typename T>
vector<T> split(const string& line, const char separator) {
	vector<T> result;
	string curr;

	for (auto& ch : line) {
		if (ch == separator) {
			setCurrToVector(curr, result);
		}
		else {
			curr += ch;
		}
	}

	setCurrToVector(curr, result);

	return result;
}

#endif // !SPLIT_H