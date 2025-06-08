#pragma once
#ifndef TRYPARSE_H
#define TRYPARSE_H

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

bool tryParse(const string& str, int& num) {
	stringstream ss(str);
	if (ss >> num) {
		return true;
	}

	return false;
}

#endif // !TRYPARSE_H
