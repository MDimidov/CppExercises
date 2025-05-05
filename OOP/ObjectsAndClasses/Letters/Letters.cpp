// 1.	Letters
//You are given a text in English.Let's define a word as any sequence of alphabetical characters. Each of those characters we will call a letter, but we will consider the uppercase and lowercase variant of a character in a word as the same letter.
//Write a program that reads the text(a single line on the console) and then reads lines, each containing a single letter, until a line containing a '.' (dot)is entered.
//For each of those lines, print all words that contain the letter, ordered alphabetically(capitals letters before lowercase letters), without duplicates – if no words contain that letter, print "---" (three dashes)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

class Sentence {
private:
	string sentences;

	vector <string> splitedSentences;

	void GetSplitSentences() {
		string word{ "" };
		for (int i = 0; i < sentences.size(); i++) {
			char currSymbol = sentences[i];
			if (currSymbol == ' ' || currSymbol == ',' || currSymbol == '.') {
				splitedSentences.push_back(word);
				word.clear();
				continue;
			}

			word += currSymbol;
		}
	}

public:
	Sentence(string sentences) {
		this->sentences = sentences;
		GetSplitSentences();
	}

	set<string> GetWords(vector<char>& letters) const {
		set<string> choosenWords;

		for (int i = 0; i < splitedSentences.size(); i++) {
			string currWord = splitedSentences[i];
			for (int k = 0; k < currWord.size(); k++) {
				char currSymbol = currWord[k];
				bool isAdded = false;
				for (char letter : letters) {
					if (currSymbol == letter) {
						choosenWords.insert(currWord);
						isAdded = true;
						break;
					}
				}

				if (isAdded) {
					break;
				}
			}
		}

		return choosenWords;
	}



};

void printResult(set<string>& results) {
	for (string word : results) {
		cout << word << " ";
	}
}
int main()
{
	string sentence;
	getline(cin, sentence);
	Sentence sentenceClass(sentence);

	vector<char> letters;
	while (true) {
		char letter;
		cin >> letter;
		if (letter == '.') {
			break;
		}

		letters.push_back(letter);
	}

	set<string> result = sentenceClass.GetWords(letters);
	printResult(result);
}