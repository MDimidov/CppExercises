#pragma once
#ifndef JOIN_H
#define JOIN_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
string join(const vector<T>& vec, const string& joinStr) {
	ostringstream oss;

	for (size_t i = 0; i < vec.size(); i++) {
		if (i != 0) {
			oss << joinStr;
		}
		oss << vec[i];
	}

	return oss.str();
}
#endif // !JOIN_H
