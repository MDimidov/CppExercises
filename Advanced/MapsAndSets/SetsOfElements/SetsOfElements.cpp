// SetsOfElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Sets of Elements
//Write a program that prints a set of elements.On the first line, you will receive two numbers – n and m, which represent the lengths of two separate sets.On the next n + m lines you will receive n numbers, which are the numbers in the first set, and m numbers, which are in the second set.Find all the unique elements that appear in both of them and print them in the ascending order.


#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

set<int> getSet(int n) {
	set<int> resultSet;

	int num;
	for (int i = 0; i < n;i++) {
		cin >> num;
		resultSet.insert(num);
	}

	return resultSet;
}

set<int> getMatchedElements(set<int>& firstSet, set<int>& secondSet) {
	set<int> resultSet;
	if (firstSet.size() > secondSet.size()) {
		for (auto& num : secondSet) {
			if (firstSet.count(num)) {
				resultSet.insert(num);
			}
		}
	}
	else {
		for (auto& num : firstSet) {
			if (secondSet.count(num)) {
				resultSet.insert(num);
			}
		}
	}

	return resultSet;
}

void printResult(set<int>& resultSet) {
	for (auto& num : resultSet) {
		cout << num << " ";
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	set<int> firstSet = getSet(n);
	set<int> secondSet = getSet(m);

	set<int> resultSet = getMatchedElements(firstSet, secondSet);
	printResult(resultSet);
}