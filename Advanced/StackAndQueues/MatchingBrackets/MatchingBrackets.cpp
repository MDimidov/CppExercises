// MatchingBrackets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a program that:
//•	Reads an input string(arithmetic expression with brackets)
//•	Find all sub - expressions
//•	Print each sub - expression on separate line
//Note : The input expression will always be a correct mathematical expression.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void findSubexpressions(const string& expression) {
    stack<int> brackets;

    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '(') {
            brackets.push(i);
        }
        else if (expression[i] == ')') {
            int start = brackets.top();
            brackets.pop();
            cout << expression.substr(start, i - start + 1) << endl;
        }
    }
}

int main() {
    string input;
    getline(cin, input);

    findSubexpressions(input);

    return 0;
}
