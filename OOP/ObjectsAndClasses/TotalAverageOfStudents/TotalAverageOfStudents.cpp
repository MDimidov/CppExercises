// TotalAverageOfStudents.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Total average of students
//Write a program, use a class that has params :
//•	Student Name
//•	Student Surname
//•	Total Average
//The class should have print method that for a given object prints all the information.
//Create a vector in main() that for a given number(passed thru user) saves the objects
//Make a function that calculates the Total average of all students.
//If there are no students, print "Invalid input".
//Explanation :
//	Number of students – 2
//	Name – Maria
//	Surname – Ivanova
//	Average – 3.5
//	Name – Dragan
//	Surname – Ivanov
//	Average – 4.5
//	TOTAL AVERAGE –(3.5 + 4.5) / 2 = 4


#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
	string name;
	string surname;
	double totalAverage;

public:
	Student(string name, string surname, double totalAverage)
		: name(name), surname(surname), totalAverage(totalAverage) {
	}

	void print() const {
		cout << name << " " << surname << " " << totalAverage << endl;
	}

	double getTotalAvg() const {
		return totalAverage;
	}

};

double getTotalAverage(vector<Student>& students) {
	if (students.empty()) {
		return -1;
	}

	double avg = 0;

	for (auto& student : students) {
		avg += student.getTotalAvg();
		student.print();
	}

	return avg / students.size();
}
int main()
{
	vector<Student> students;

	int n;
	cin >> n;

	if (n <= 0) {
		cout << "Invalid input";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		string name, surname;
		double grade;

		cin >> name >> surname >> grade;

		students.emplace_back(name, surname, grade);
	}

	double avg = getTotalAverage(students);
	cout << avg;
}