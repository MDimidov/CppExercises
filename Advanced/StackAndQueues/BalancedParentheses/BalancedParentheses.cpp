// BalancedParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Given a sequence consisting of parentheses, determine whether the expression is balanced. A sequence of parentheses is balanced if every open parenthesis can be paired uniquely with a closing parenthesis that occurs after the former. Also, the interval between them must be balanced. You will be given three types of parentheses: (, {, and [.
//{ [()] } – This is a balanced parenthesis.
//{ [(] )} – This is not a balanced parenthesis.
//Input
//●	Each input consists of a single line, the sequence of parentheses.
//Output
//●	For each test case, print on a new line "YES" if the parentheses are balanced.Otherwise, print "NO".Do not print the quotes.
//Constraints
//●	1 ≤ lens ≤ 1000, where the lens is the length of the sequence.
//●	Each character of the sequence will be one of{ , }, (, ), [, ].


#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

stack<char> getBrackets(string& line)
{
	stack<char> brackets;
	for (int i = 0; i < line.size(); i++) {
		brackets.push(line[i]);
	}

	return brackets;
}

void validateBrackets(stack<char>& brackets, stack<char>& copyBrackets) {
	map<char, char> bracketsDictionary = { {'{', '}'}, {'[', ']'}, {'(', ')'} };

	while (!brackets.empty()) {
		if (!copyBrackets.empty()) {
			if (bracketsDictionary[brackets.top()] == copyBrackets.top()) {
				copyBrackets.pop();
			}
			else {
				copyBrackets.push(brackets.top());
			}
		}
		else {
			copyBrackets.push(brackets.top());
		}

		brackets.pop();
	}

}

int main()
{
	string line;
	cin >> line;

	stack<char> brackets = getBrackets(line);
	stack<char> copyBrackets;

	validateBrackets(brackets, copyBrackets);
	
	if (copyBrackets.empty()) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
