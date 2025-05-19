// MinBy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//MinBy
//Write a program that :
//•	Reads input string from the first line(sequence of words, separated by space)
//•	Reads integer number from the second line
//•	If the number is equals to :
//o	1->find and print the string that is earliest lexicographically
//o	2->find and print the shortest string
//o	3->find and print the longest string


#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

set<string> getWords(string& line) {
	set<string> words;
	istringstream iss(line);
	string word;

	while (iss >> word) {
		words.insert(word);
	}

	return words;
}

void printLargestWord(set<string>& words) {
	auto it = max_element(words.begin(), words.end(), [](const string& a, const string& b) {
		return a.size() < b.size();
		});

	cout << *it;
}

void printShortestWord(set<string>& words) {
	auto it = min_element(words.begin(), words.end(), [](const string& a, const string& b) {
		return a.size() < b.size();
		});

	cout << *it;
}

void printFirstAlphabetical(set<string>& words) {
	for (auto& word : words) {
		cout << word;
		break;
	}
}

int main()
{
	string line;
	getline(cin, line);

	set<string> words = getWords(line);

	int command;
	cin >> command;

	switch (command) {
	case 1:
		printFirstAlphabetical(words);
		break;
	case 2:
		printShortestWord(words);
		break;
	case 3:
		printLargestWord(words);
		break;
	}
}