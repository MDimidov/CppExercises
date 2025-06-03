#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template  <typename T>
class Parser {
private:
	istream& in;
	string stopLine;
public:
	Parser(istream& in, const string& stopLine)
		: in(in), stopLine(stopLine) {}

	bool readNext(T& result) {
		string line;
		if (!getline(in, line)) return false;
		if (line == stopLine) return false;

		istringstream iss(line);

		iss >> result;
		return true;
	}
};
#endif // !PARSER_H
