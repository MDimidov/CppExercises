//Write a program that :
//•	Reads an input string(expression) containing : numbers, +and -
//•	Evaluate the expression with only addition(+) and subtraction(-)
//•	Print the result
//Note : There will not be any parentheses.

#include <iostream>
#include<stack>
#include<string>
using namespace std;

stack<string> splitStringBySymbol(string toSplit, char delimeter) {
	string str{ "" };
	stack<string> commands;
	for (int i = 0; i < toSplit.size(); i++) {
		if (i == toSplit.size() - 1) {
			str += toSplit[i];
			commands.push(str);
		}

		if (toSplit[i] == delimeter) {
			commands.push(str);
			str.clear();
		}
		else {
			str += toSplit[i];
		}

	}

	return commands;
}
int main()
{
	string input;
	getline(cin, input);
	stack<string> stack = splitStringBySymbol(input, ' ');

	int sum = 0;
	while (!stack.empty()) {
		int num{ 0 };
		if (stack.top() != "-" && stack.top() != "+") {
			num = stoi(stack.top());
			stack.pop();

			if (!stack.empty()) {
				if (stack.top() == "-") {
					num *= -1;
				}

				stack.pop();
			}

			sum += num;
		}
	}

	cout << sum;
}