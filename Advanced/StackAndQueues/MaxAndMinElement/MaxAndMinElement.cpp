// MaxAndMinElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//You have an empty sequence, and you will be given N queries. Each query is one of these three types:
//1 x – Push the element x into the stack.
//2 – Delete the element present at the top of the stack.
//3 – Print the maximum element in the stack.
//4 – Print the minimum element in the stack.
//After you go through all of the queries, print the stack in the following format :
//"{n}, {n1}, {n2} …, {nn}"
//Input
//•	The first line of input contains an integer N
//•	The next N lines each contain an above - mentioned query
//Output
//•	For each type 3 or 4 queries, print the maximum / minimum element in the stack on a new line.
//Constraints
//•	1 ≤ N ≤ 105
//•	1 ≤ x ≤ 109
//•	1 ≤ type ≤ 4
//•	If there are no elements in the stack, don't print anything on commands 3 and 4.

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> getInputArr(const string& input) {
	vector<int> nums;
	istringstream iss(input);
	int num;
	while (iss >> num) {
		nums.push_back(num);
	}
	return nums;
}

int getMaxElement(stack<int> elements) {
	int maxElement = INT_MIN;

	while (!elements.empty()) {
		if (maxElement < elements.top()) {
			maxElement = elements.top();
		}

		elements.pop();
	}

	return maxElement;
}

int getMinElement(stack<int> elements) {
	int minElement = INT_MAX;

	while (!elements.empty()) {
		if (minElement > elements.top()) {
			minElement = elements.top();
		}

		elements.pop();
	}

	return minElement;
}

void executeCommands(vector<int>& commands, stack<int>& nums, stack<int>& maxStack, stack<int>& minStack) {

	int command1 = commands[0];
	
	int element;
	switch (command1)
	{
	case 1:
		element = commands[1];
		nums.push(element);
		if (maxStack.empty() || maxStack.top() <= element) maxStack.push(element);
		if (minStack.empty() || minStack.top() >= element) minStack.push(element);
		break;
	case 2:
		if (!maxStack.empty() && maxStack.top() == nums.top()) maxStack.pop();
		if (!minStack.empty() && minStack.top() == nums.top()) minStack.pop();
		if (!nums.empty()) nums.pop();
		break;
	case 3:
		if (!nums.empty() && !maxStack.empty()) {
			cout << maxStack.top() << endl;
		}
		break;
	case 4:
		if (!nums.empty() && !minStack.empty()) {
			cout << minStack.top() << endl;
		}
		break;
	}
}

void printElements(stack<int>& elements) {
	int n = elements.size();
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << ", ";
		}

		cout << elements.top();
		elements.pop();
	}
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	stack<int> nums;
	stack<int> maxStack;
	stack<int> minStack;

	string line;
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		vector<int> commands = getInputArr(line);

		executeCommands(commands, nums, maxStack, minStack);
	}

	printElements(nums);
}
