// Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//2.	Distance
//Write a program to calculate the(Euclidean) distance between two points p1 { x1, y1 } and p2{ x2, y2 }. You should write a class to represent such points and a method in it that calculates the distance from the point to another point.


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Points {
private:
	int m_p1;
	int m_p2;

	int m_q1;
	int m_q2;

public:
	Points(int p1, int p2, int q1, int q2) {
		m_p1 = p1;
		m_p2 = p2;
		m_q1 = q1;
		m_q2 = q2;
	}

	double getDistanceBetweenPoints() {
		return sqrt(pow(abs(m_q1 - m_p1), 2) + pow(abs(m_q2 - m_p2), 2));
	}
};

int main()
{
	int p1, p2, q1, q2;

	cin >> p1 >> p2 >> q1 >> q2;

	Points points(p1, p2, q1, q2);

	cout <<	fixed << setprecision(3) << points.getDistanceBetweenPoints();
}