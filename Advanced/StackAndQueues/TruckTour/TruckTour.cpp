// TruckTour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Suppose there is a circle. There are N petrol pumps in that circle. Petrol pumps are numbered 0 to (N−1) (both inclusive). You have two pieces of information corresponding to each of the petrol pumps: (1) the amount of petrol that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.
//Initially, you have a tank of infinite capacity carrying no petrol.You can start the tour at any of the petrol pumps.Calculate the first point from where the truck will be able to complete the circle.Consider that the truck will stop at each of the petrol pumps.The truck will move one kilometer for each liter of petrol.
//Input
//•	The first line will contain the value of N.
//•	The next N lines will contain a pair of integers each, i.e.the amount of petrol that the petrol pump will give and the distance between that petrol pump and the next petrol pump.
//Output
//•	An integer which will be the smallest index of the petrol pump from which we can start the tour.
//Constraints
//•	1 ≤ N ≤ 1000001.
//•	1 ≤ Amount of petrol, Distance ≤ 1000000000.


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

struct Station {
	int fuel{ 0 };
	int distanceToNextStation{ 0 };
};

void setStation(string& line, queue<Station>& stations) {
	istringstream iss(line);

	Station station;
	int fuel, distance;

	while (iss >> fuel >> distance) {
		station.fuel = fuel;
		station.distanceToNextStation = distance;
		stations.push(station);
	}
}


int main()
{
	int n;
	cin >> n;
	cin.ignore();
	queue<Station> stations;


	string line;
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		setStation(line, stations);
	}

	queue<Station> coppiedStations = stations;

	int index = 0;

	int maxStops = stations.size();

	for (int i = 0; i < maxStops; i++) {

		int totalFuel = 0;
		while (!stations.empty()) {
			int distance = stations.front().distanceToNextStation;
			totalFuel += stations.front().fuel;

			if (totalFuel >= distance) {
				totalFuel -= distance;
			}
			else {
				break;
			}

			stations.pop();
		}

		if (!stations.empty()) {
			coppiedStations.push(coppiedStations.front());
			coppiedStations.pop();

			stations = coppiedStations;
			index++;
		}
		else {
			break;
		}
	}

	cout << index;
}