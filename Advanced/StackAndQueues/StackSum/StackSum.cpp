//2.	Stack Sum
//Write a program that :
//•	Reads an input of integer numbers and adds them to a stack
//•	Reads commands until "end" is received
//•	Prints the sum of the remaining elements of the stack
//Input
//•	On the first line, you will receive an array of integers.
//•	On the next lines, until the "end" command is given, you will receive commands – a single command and one or two numbers after the command, depending on what command you are given.
//•	If the command is "add", you will always receive exactly two numbers after the command which you need to add to the stack.
//•	If the command is "remove", you will always receive exactly one number after the command which represents the count of the numbers you need to remove from the stack.If there are not enough elements skip the command.
//Output
//•	When the command "end" is received, you need to print the sum of the remaining elements in the stack.


#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;


vector<string> splitStringBySymbol(string toSplit, char delimeter) {
	string str{ "" };
	vector<string> commands;
	for (int i = 0; i < toSplit.size(); i++) {
		if (i == toSplit.size() - 1) {
			str += toSplit[i];
			commands.push_back(str);
		}

		if (toSplit[i] == delimeter) {
			commands.push_back(str);
			str.clear();
		}
		else {
			str += toSplit[i];
		}

	}

	return commands;
}

int sumStack(stack<int>& resultStack) {
	int sum = 0;

	while (!resultStack.empty()) {
		sum += resultStack.top();
		resultStack.pop();
	}

	return sum;
}

int main()
{
	string firstInput;
	getline(cin, firstInput);

	stack<int> nums;
	string numString{ "" };
	for (int i = 0; i < firstInput.size(); i++) {
		if (i == firstInput.size() - 1) {
			numString += firstInput[i];
			nums.push(stoi(numString));
		}
		if (firstInput[i] == ' ') {
			nums.push(stoi(numString));
			numString.clear();
		}
		else {
			numString += firstInput[i];
		}
	}

	string input;
	while (getline(cin, input) && input != "end") {
		vector<string> commands = splitStringBySymbol(input, ' ');
		string command = commands[0];
		int num1 = stoi(commands[1]);

		if (command == "add") {
			int num2 = stoi(commands[2]);

			nums.push(num1);
			nums.push(num2);
		}
		else if (command == "remove") {
			if (nums.size() >= num1) {
				for (int i = 0; i < num1; i++) {
					nums.pop();
				}
			}
		}
	}

	cout << sumStack(nums);
}
