// MatchingLocations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//3.	Matching Locations
//Write a program that reads names of places and their geographical coordinates in the format name, latitude, longitude(where latitude and longitude are floating - point numbers).No two locations will have the same name.Some locations may have the same coordinates.
//After all locations are entered, a single line containing the '.' (dot)character will be entered.
//After that, queries will be entered – the queries will either contain a name of a location, or latitude and longitude coordinates(entered as two floating point numbers separated by a single space).Print all locations that match the query in the same format that they were entered.
//After all queries are entered, a single line containing the '.' (dot)character will be entered.


#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

void addLocation(string& line, map<string, vector<string>>& locations, vector<string>& locationNames, char delimeter) {
	istringstream iss(line);
	string token;
	string locationName;

	int index = 0;
	while (getline(iss, token, delimeter)) {
		if (index++ == 0) {
			locationName = token;
			locationNames.push_back(locationName);
		}
		else {
			locations[locationName].push_back(token);
		}
	}
}

void printLocations(string& line, map<string, vector<string>>& locations, vector<string>& locationNames) {
	istringstream iss(line);
	string location;
	vector<string> searchingLocations;
	while (iss >> location) {
		searchingLocations.push_back(location);
	}

	vector<string> result;
	string currResult;
	if (searchingLocations.size() > 1) {
		string lat = searchingLocations[0];
		string lon = searchingLocations[1];

		for (auto& name : locationNames) {
			if (locations[name][0] == lat && locations[name][1] == lon) {
				currResult = name + "," + lat + "," + lon;
				result.push_back(currResult);
			}
		}
	}
	else {
		currResult = location;
		for (auto& psn : locations[location]) {
			currResult += "," + psn;
		}
		result.push_back(currResult);
	}

	for (auto& res : result) {
		cout << res << endl;
	}
}

int main()
{
	map<string, vector<string>> locations;
	vector<string> locationNames;

	string line;
	getline(cin, line);

	while (line != ".") {
		addLocation(line, locations, locationNames, ',');

		getline(cin, line);
	}

	getline(cin, line);
	while (line != ".") {
		printLocations(line, locations, locationNames);

		getline(cin, line);
	}
}