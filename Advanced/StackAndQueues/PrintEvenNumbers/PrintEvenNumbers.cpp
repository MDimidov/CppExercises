// PrintEvenNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a program that:
//●	Reads an array of integers and adds them to a queue.
//●	Prints the even numbers separated by ", ".


#include <iostream>
#include<queue>
#include<string>

using namespace std;

queue<int> getQueueFromInput(string str) {
    queue<int> result;

    string currNum{ "" };

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' && currNum.size() > 0) {
            result.push(stoi(currNum));
            currNum.clear();
            continue;
        }

        currNum += str[i];

        if (i == str.size() - 1) {
            result.push(stoi(currNum));
        }
    }

    return result;
}
int main()
{
    string input;
    getline(cin, input);

    queue<int> queues = getQueueFromInput(input);

    int index = 0;
    while (!queues.empty()) {
        if (queues.front() % 2 == 0) {
            if (index != 0) {
                cout << ", ";
            }
            cout << queues.front();
            index++;
        }

        queues.pop();
    }
}