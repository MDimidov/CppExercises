// UniqueUsernames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Unique Usernames
//Write a program that reads from the console a sequence of N usernames and keeps a collection only of the unique ones.On the first line, you will be given an integer N.On the next N lines, you will receive one username per line.Print the collection on the console, in ascending order :


#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string line;
	set<string> names;
	for (int i = 0; i < n; i++) {
		cin >> line;

		names.insert(line);
	}

	for (auto& name : names) {
		cout << name << endl;
	}
}