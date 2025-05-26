// Letters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//You are given a text in English. Let's define a word as any sequence of alphabetical characters. Each of those characters we will call a letter, but we will consider the uppercase and lowercase variant of a character in a word as the same letter.
//Write a program which reads the text(a single line on the console) and then reads lines, each containing a single letter, until a line containing a '.' (dot)is entered.For each of those lines, print all words that contain the letter, ordered alphabetically(capitals letters before lowercase letters), without duplicates – if no words contain that letter, print "---" (three dashes)


#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>

using namespace std;

bool isValidLetter(char& letter) {
	if ((letter >= 'A' && letter <= 'Z') ||
		(letter >= 'a' && letter <= 'z')) {
		return true;
	}

	return false;
}

set<string> getSentences(string& line) {
	istringstream iss(line);
	set<string> result;

	string word;
	while (iss >> word) {
		string currWord;

		for (auto& letter : word) {
			if (isValidLetter(letter)) {
				currWord += letter;
			}
			else {
				if (!currWord.empty()) {
					result.insert(currWord);
				}
				currWord.clear();
			}
		}

		result.insert(currWord);
	}

	return result;
}

vector<char> getSearchingSymbolsFromConsole() {
	char searchingSymbol;
	cin >> searchingSymbol;

	vector<char> searchingSymbols;
	while (searchingSymbol != '.') {
		searchingSymbols.push_back(searchingSymbol);
		cin >> searchingSymbol;
	}

	return searchingSymbols;
}

bool isWordContainsLetter(string& word, char letter) {
	for (int i = 0; i < word.size(); i++) {
		if (tolower(word[i]) == tolower(letter)) {
			return true;
		}
	}

	return false;
}

map<int, set<string>> getResultWords(set<string>& sentences, vector<char>& searchingSymbols) {
	map<int, set<string>> resultWords;
	int key = 1;
	for (auto& symbol : searchingSymbols) {
		bool isLetterContained = false;
		for (auto word : sentences) {
			if (isWordContainsLetter(word, symbol)) {
				resultWords[key].insert(word);
				isLetterContained = true;
			}
		}

		if (!isLetterContained) {
			resultWords[key].insert("---");
		}

		key++;
	}

	return resultWords;
}

void printResultWords(map<int, set<string>> resultWords) {
	for (auto& kvp : resultWords) {
		for (auto& word : kvp.second) {
			cout << word << " ";
		}
		cout << endl;
	}
}


int main()
{
	string line;
	getline(cin, line);

	set<string> sentences = getSentences(line);

	vector<char> searchingSymbols = getSearchingSymbolsFromConsole();

	map<int, set<string>> resultWords = getResultWords(sentences, searchingSymbols);

	printResultWords(resultWords);
}
