// Find.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a program that:
//•	Reads info about companies in the following format : {name} { id }
//•	Read infos until you receive command "end"
//•	Read a search id
//•	Find a company with that id
//o	If there is such a company, prints the info about found company in the following format : {name} { id }
//o	If no such company has been entered, the program prints "[not found]"


#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

void addCompany(string& line, unordered_map<string, string>& companies) {
	istringstream iss(line);

	string name, id;
	iss >> name >> id;

	companies[id] = name;
}

int main()
{
	string line;
	unordered_map<string, string> companies;

	while (true) {
		getline(cin, line);
		if (line == "end") {
			break;
		}

		addCompany(line, companies);
	}

	string searchingId;
	cin >> searchingId;

	auto it = companies.find(searchingId);

	if (it != companies.end()) {
		cout << it->second << " " << it->first;
	}
	else {
		cout << "[not found]";
	}
}