// Miners.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Miners
//You are given a sequence of strings, each on a new line.Every odd line on the console is representing a resource(e.g.Gold, Silver, Copper, and so on), and every even – quantity.Your task is to collect the resources and print them each on a new line.
//Print the resources and their quantities in the format :
//{resource} – > {quantity}
//The quantities of inputs will be in the range[1 - 2 000].


#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	string resource;
	int quantity;

	unordered_map<string, int> resources;
	vector<string> orderedResources;

	while (true) {
		cin >> resource;
		if (resource == "stop") {
			break;
		}
		cin >> quantity;

		if (!resources.count(resource)) {
			orderedResources.push_back(resource);
		}

		resources[resource] += quantity;
	}

	for (auto& res : orderedResources) {
		cout << res << " -> " << resources[res] << endl;
	}
}
