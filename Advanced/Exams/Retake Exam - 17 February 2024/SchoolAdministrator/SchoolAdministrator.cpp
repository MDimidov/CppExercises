// SchoolAdministrator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//School Administrator
//You're a school administrator, who's taking care for meeting and greeting kid participants for the local
//Programming Olympiad, and putting each one of them in their corresponding room.
//You're getting a list of all kids with their designated rooms. There're four rooms, each one numbered with
//an integer number : 1, 2, 3, and 4. You will get the list of each kids's rooms as first part of your input in the
//format "Daryl 4", where "Daryl" is the name of the kid(there will be no spaces in the name, and one
//	room will never have two kids with the same name), and 4 is the room number.You're supposed to
//	distribute each kid in their corresponding room.
//	The list will end up with "END".After this "END" command, you must print the list all kids in each room.
//	The names must be printed in the order they came from your input.
//	Then, you will start getting parent's questions about which kid is in which room. For example "Daryl". You
//	must locate where all kids with name "Daryl" are, and print them out in the following format : "Daryl:
//	1 4" (e.g., in this case a kid with name Daryl is in rooms 1 and 4). The list of the parent's questions will end
//	with "END".
//	If a kid is not present anywhere(for example "Stoyan", you shound print "Stoyan: Not found!".
//		Good luck, school admin!

#include <iostream>
#include <set>
#include <map>

using namespace std;

//struct Room
//{
//	int number{ -1 };
//	vector<string> studentNames;
//
//	Room(int number, )
//};

int main()
{
	map<string, set<int>> studentsRooms;
	string studentName;
	int room;
	while ((cin >> studentName) && studentName != "END") {
		cin >> room;

		studentsRooms[studentName].insert(room);
	}

	while ((cin >> studentName) && studentName != "END") {
		cout << studentName << ":";

		if (studentsRooms.count(studentName)) {
			for (int room : studentsRooms[studentName]) {
				cout << " " << room;
			}
		}
		else {
			cout << " Not found!";
		}

		cout << endl;
	}
}