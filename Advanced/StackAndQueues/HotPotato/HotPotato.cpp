// HotPotato.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a program that:
//•	Simulates the game of Hot Potato
//•	This is the rules :
//o	Hot potato is a game in which children form a circle and start passing a hot potato.
//o	The counting starts with the first kid
//o	Every nth toss, the child left with the potato leaves the game
//o	When a kid leaves the game, it passes the potato along
//o	 This continues until there is only one kid left
//•	Print every kid that is removed from the circle
//•	In the end, print the kid that is left last


#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<string> getQueueFromInput(string& input) {
	queue<string> names;
	string name;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] != ' ') {
			name += input[i];
		}
		if (input[i] == ' ' || i == input.size() - 1) {
			names.push(name);
			name.clear();
		}
	}

	return names;
}


int main()
{
	string input;
	getline(cin, input);

	int count{ 0 };
	cin >> count;

	queue<string> names = getQueueFromInput(input);

	while (names.size() > 1) {
		for (int i = 1; i <= count; i++) {
			if (i == count) {
				cout << "Removed " << names.front() << endl;
			}
			else {
				names.push(names.front());
			}

			names.pop();
		}
	}

	cout << "Last is " << names.front();
}
