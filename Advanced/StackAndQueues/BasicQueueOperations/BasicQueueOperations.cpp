// BasicQueueOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Play around with a queue. You will be given an integer N representing the number of elements to add, an integer S representing the number of elements to remove from the queue, and finally an integer X, an element that you should look for in the queue. If it is, print true on the console. If it's not printed the smallest element is currently present in the queue. If there are no elements in the sequence, print 0 on the console.

#include <iostream>
#include <string>
#include <queue>
#include <climits>

using namespace std;

queue<int> getInputArr(string& input) {
    queue<int> nums;
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

    queue<int> inputs = getInputArr(input);

    int elementsToPush = inputs.front();
    inputs.pop();

    int elementsToPop = inputs.front();
    inputs.pop();

    int searchingElement = inputs.front();
    inputs.pop();

    input.clear();
    getline(cin, input);

    inputs = getInputArr(input);

    for (int i = 0; i < elementsToPop; i++) {
        inputs.pop();
    }

    queue<int> checkedElements;
    int minValue = INT_MAX;

    if (inputs.empty()) {
        cout << 0;
        return 0;
    }

    while (!inputs.empty()) {
        if (inputs.front() == searchingElement) {
            cout << "true";
            return 0;
        }

        checkedElements.push(inputs.front());
        inputs.pop();
    }

    while (!checkedElements.empty()) {
        if (minValue > checkedElements.front()) {
            minValue = checkedElements.front();
        }

        checkedElements.pop();
    }

    cout << minValue;

}
