// CitiesByContinentAndCountry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Cities by Continent and Country
//Write a program that reads continents, countries, and their cities, puts them in a nested Map and prints them, sorted by continents' name by ascending order, then by countries' names in ascending order and finally order by cities' name.


#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>


using namespace std;

void addCity(string& line, map<string, map<string, set<string>>>& continents) {
	istringstream iss(line);
	string continent;
	string country;
	string city;

	iss >> continent;
	iss >> country;
	iss >> city;

	continents[continent][country].insert(city);
}

void printResult(map<string, map<string, set<string>>>& continents) {
	for (auto& kvp : continents) {
		cout << kvp.first << ":" << endl;
		for (auto& countries : kvp.second) {
			cout << "\t" << countries.first << " -> ";

			int index = 0;
			for (auto& city : countries.second) {
				if (index++ != 0) {
					cout << ", ";
				}

				cout << city;
			}

			cout << endl;
		}

	}
}


int main()
{
	int n;
	cin >> n;
	cin.ignore();

	map<string, map<string, set<string>>> continents;

	string line;
	for (int i = 0; i < n; i++) {
		getline(cin, line);

		addCity(line, continents);
	}

	printResult(continents);
}