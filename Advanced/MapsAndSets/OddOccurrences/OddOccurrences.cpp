// OddOccurrences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Odd Occurrences
//Write a program that extracts from a given sequence of words all elements that appear in it an odd number of times(case-insensitive).
//•	Words are given in a single line, space - separated.
//•	Print the result elements in lowercase, in their order of appearance.


#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

void setWords(string& line, unordered_map<string, int>& words, vector<string>& orderedWords) {
	istringstream iss(line);
	string word;

	while (iss >> word) {
		transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return tolower(c); });

		if (!words.count(word)) {
			orderedWords.push_back(word);
		}

		words[word]++;
	}
}

void printResult(unordered_map<string, int>& words, vector<string>& orderedWords) {
	int cntr = 0;

	for (auto& word : orderedWords) {
		if (words[word] % 2 != 0) {
			if(cntr++ != 0) cout << ", ";
			cout << word;
		}
	}
}

int main()
{
	string line;
	getline(cin, line);

	unordered_map<string, int> words;
	vector<string> orderedWords;
	setWords(line, words, orderedWords);

	printResult(words, orderedWords);
}
