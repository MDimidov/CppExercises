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

struct Location {
	string name;
	string lat;
	string lon;

	void printLocation() {
		cout << name << "," << lat << "," << lon << endl;
	}
};

void addLocation(string& line, vector<Location>& locations, char delimeter) {
	istringstream iss(line);
	string token;
	Location location;

	int index = 0;
	while (getline(iss, token, delimeter)) {
		if (index == 0) {
			location.name = token;
		}
		else if (index == 1) {
			location.lat = token;
		}
		else {
			location.lon = token;
		}

		index++;
	}

	locations.push_back(location);
}

void printLocations(string& line, vector<Location>& locations) {
	istringstream iss(line);
	string location;
	vector<string> searchingLocations;
	while (iss >> location) {
		searchingLocations.push_back(location);
	}

	if (searchingLocations.size() > 1) {
		string lat = searchingLocations[0];
		string lon = searchingLocations[1];

		for (auto& loc : locations) {
			if (loc.lat == lat && loc.lon == lon) {
				loc.printLocation();
			}
		}
	}
	else {
		for (auto& loc : locations) {
			if (loc.name == location) {
				loc.printLocation();
			}
		}
	}
}

int main()
{
	vector<Location> locations;

	string line;
	getline(cin, line);

	while (line != ".") {
		addLocation(line, locations, ',');

		getline(cin, line);
	}

	getline(cin, line);
	while (line != ".") {
		printLocations(line, locations);

		getline(cin, line);
	}
}