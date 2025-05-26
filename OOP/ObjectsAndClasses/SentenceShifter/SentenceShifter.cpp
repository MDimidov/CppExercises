// SentenceShifter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//1.	Sentence Shifter
//You are given a list of words in one line.On the other line, you are given a simple integer.
//Your role is to shift the words in the sentence according to that integer.
//For an example, if a sentence has 10 words and you receive a shift number 2 - the first word should become the third, the second word should become the fourth and so on, ..., the word before the last should become the first and the last word should become the second.
//Implement this task with a class that is initialized with a linear container(array, vector, etc.) of words and which has a getShiftedSentence() method which returns the words shifted.
//Each word is printed on a different line.


#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

class Sentence {
public:
	Sentence(string& line) {
		splitWords(line);
	}

	string getShiftedSentence(int num) {
		
		changeOrder(num);

		string result;
		while (!m_words.empty()) {
			cout << m_words.front() << endl;
			m_words.pop_front();
		}

		return result;
	}

private:
	deque<string> m_words;
	
	void splitWords(string& line) {
		string word;
		istringstream iss(line);

		while (iss >> word) {
			m_words.push_back(word);
		}
	}

	void changeOrder(int num) {
		if (m_words.empty()) return;

		for (int i = 0; i < num; i++) {
			string test = m_words.back();
			m_words.push_front(m_words.back());
			m_words.pop_back();
		}
	}
};

int main()
{
	string line;
	getline(cin, line);

	Sentence sentence(line);

	int num;
	cin >> num;

	sentence.getShiftedSentence(num);
}
