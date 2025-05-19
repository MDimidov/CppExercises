// Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//3.	Order
//Write a program that :
//•	Reads info about companies in the following format : {name} { id }
//•	Read infos until you receive command "end"
//•	Print company infos order by id in ascending order


#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void addCompany(string& line, map<string, string>& companies) {
	istringstream iss(line);

	string name, id;
	iss >> name >> id;

	companies[id] = name;
}

void printOrderedCompanies(map<string, string>& companies) {
	for (auto kvp : companies) {
		cout << kvp.second << " " << kvp.first << endl;
	}
}

int main()
{
	string line;
	map<string, string> companies;

	while (true) {
		getline(cin, line);
		if (line == "end") {
			break;
		}

		addCompany(line, companies);
	}

	printOrderedCompanies(companies);
}