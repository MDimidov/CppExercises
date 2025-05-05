// ReverseString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
    stack<char> inputStack;
    string input;
    getline(cin, input);

    for (int i = 0; i < input.size(); i++) {
        inputStack.push(input[i]);
    }

    while (!inputStack.empty()) {
        cout << inputStack.top();
        inputStack.pop();
    }
}