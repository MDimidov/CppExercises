// RemoveInvalid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Remove Invalid
//Write a program that :
//•	Reads info about companies in the following format : {name} { id }
//•	Read infos until you receive command "end"
//•	Print all companies with a valid id
//Note : Valid ids are non - negative.


#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

void fillCompaniesFromConsole(map<int, string>& companies) {
	int id;
	string name;
	string line;

	while (true) {

		getline(cin, line);
		istringstream iss(line);

		if (line == "end") {
			break;
		}

		iss >> id >> name;
		if (id >= 0) {
			companies[id] = name;
		}
	}
}

void printCompanies(map<int, string>& companies) {
	for (auto& kvp : companies) {
		cout << kvp.first << " " << kvp.second << endl;
	}
}

int main()
{
	map<int, string> companies;

	fillCompaniesFromConsole(companies);

	printCompanies(companies);
}