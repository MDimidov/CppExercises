// ShortWords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Short Words
//Read a text, extract its words(separated by spaces) find all short words(less than 5 characters), and print them alphabetically, in lowercase, separate by a single comma and a single space.
//•	Use case-insensitive matching.
//•	Remove duplicated words.


#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

void setWordsUnder5Chars(string& line, set<string>& words) {
	istringstream iss(line);
	string word;

	while (iss >> word) {
		if (word.size() >= 5) {
			continue;
		}

		transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return tolower(c); });
		words.insert(word);
	}
}

void printMatchedWords(set<string>& words) {
	int index = 0;

	for (auto& word : words) {
		if (index++ != 0) {
			cout << ", ";
		}

		cout << word;
	}
}

int main()
{
	string line;
	getline(cin, line);

	set<string> words;

	setWordsUnder5Chars(line, words);

	printMatchedWords(words);
}