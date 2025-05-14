// AverageStudentGrades.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//Write a program, which reads a name of a student and their grades and adds them to the student record, then prints the students' names with their grades and their average grade, sorted by students' names in ascending order.

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

void addGrades(string& line, map<string, vector<double>>& grades) {
	istringstream iss(line);

	string name;
	iss >> name;

	double grade;
	iss >> grade;

	grades[name].push_back(grade);
}

void printResult(map<string, vector<double>>& grades) {
	for (const auto& kvp : grades) {

		double sum = 0.0;
		cout << kvp.first << " -> ";

		for (const auto& grade : kvp.second) {
			cout << fixed << setprecision(2) << grade << ' ';
			sum += grade;
		}
		cout << "(avg: " << fixed << setprecision(2) << sum / kvp.second.size() << ")" << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	map<string, vector<double>> grades;

	string line;
	for (int i = 0; i < n; i++) {
		getline(cin, line);

		addGrades(line, grades);
	}

	printResult(grades);
}
