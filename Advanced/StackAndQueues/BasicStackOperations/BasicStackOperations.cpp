// BasicStackOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Play around with a stack. You will be given an integer N representing the number of elements to push into the stack, an integer S representing the number of elements to pop from the stack, and finally an integer X, an element that you should look for in the stack. If it's found, print "true" on the console. If it isn't, print the smallest element currently present in the stack. If there are no elements in the sequence, print 0 on the console.
//Input
//•	On the first line, you will be given N, S, and X, separated by a single space.
//•	On the next line, you will be given N number of integers.
//Output
//•	On a single line print either true if X is present in the stack, otherwise print the smallest element in the stack.If the stack is empty, print 0.


#include <iostream>
#include <string>
#include <stack>
#include <climits>

using namespace std;

stack<int> getInputArr(string& input)  {
    stack<int> nums;
    string num;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') {
            nums.push(stoi(num));
            num.clear();
        }
        else {
            num += input[i];
        }

        if (i == input.size() - 1 && input[i] != ' ') {
            nums.push(stoi(num));
        }
    }

    return nums;
}

int main()
{
    string input;
    getline(cin, input);

    stack<int> inputs = getInputArr(input);

    int searchingElement = inputs.top();
    inputs.pop();

    int elementsToPop = inputs.top();
    inputs.pop();

    int elementsToPush = inputs.top();
    inputs.pop();

    input.clear();
    getline(cin, input);

    inputs = getInputArr(input);

    for (int i = 0; i < elementsToPop; i++) {
        inputs.pop();
    }

    stack<int> checkedElements;

    while (!inputs.empty()) {
        if (inputs.top() == searchingElement) {
            cout << "true";
            return 0;
        }

        checkedElements.push(inputs.top());
        inputs.pop();
    }

    int minElement = INT_MAX;

    if (checkedElements.empty()) {
        cout << 0;
        return 0;
    }

    while (!checkedElements.empty()) {
        if (checkedElements.top() < minElement) {
            minElement = checkedElements.top();
        }

        checkedElements.pop();
    }

    cout << minElement;
}
