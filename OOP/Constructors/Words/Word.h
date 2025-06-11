//Words
//You are given code that reads two lines of words(strings containing lowercase English letters, separated by spaces) and prints the number of occurrences of each word(in lexicographical order, as C++ orders strings) in the first input line, then does the same for the second input line.
//The provided code handles input and output, however, it uses a Word class for the counting.Your task is to implement the Word class so that the program compiles successfully and runs as described.
//NOTE : the main() function just reads and initializes objects of the Word class, then adds them to a set to sort them lexicographically.It does not call any methods, other than the ones for getting the word string and the count for it at the end.You need to figure out how to handle the counting based on the provided code.
//You should submit a single.zip file for this task, containing ONLY the file(s) YOU created.The Judge system has a copy of the other files and will compile them, along with your file, in the same directory.

#pragma once
#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <map>

class Word {
private:
	static std::map<std::string, int> wordCounts;
	std::string strWord;

public:
	Word(const std::string& strWord)
		: strWord(strWord)
	{
		this->wordCounts[strWord]++;
	}

	std::string getWord() const {
		return this->strWord;
	}

	int getCount() const {
		int result = this->wordCounts[strWord];
		wordCounts.erase(strWord);
		return result;
	}

	bool operator<(const Word& w) const{
		return this->getWord() < w.getWord();
	}
};

std::map<std::string, int> Word::wordCounts;

#endif // !WORD_H
