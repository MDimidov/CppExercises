// Supermarket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a program that:
//•	Reads an input string consisting of a name and adds it to a queue until "End" is received.
//•	If you receive "Paid", print every customer name and empty the queue, otherwise, we receive a client and we have to add him to the queue.
//•	When we receive "End", we have to print the count of the remaining people in the queue in the format : "{count} people remaining."


#include <iostream>
#include <string>
#include <queue>

using namespace std;
int main()
{
    string input;
    queue<string> customers;
    while (input != "End") {
        cin >> input;

        if (input == "Paid") {
            while (!customers.empty()) {
                cout << customers.front() << endl;
                customers.pop();
            }
        }
        else if (input != "End") {
            customers.push(input);
        }
    }

    cout << customers.size() << " people remaining.";
}
