// Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//2.	Distance
//Write a program to calculate the(Euclidean) distance between two points p1 { x1, y1 } and p2{ x2, y2 }. You should write a class to represent such points and a method in it that calculates the distance from the point to another point.


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point {
private:
	int m_x;
	int m_y;

public:
	Point(int x, int y) : m_x(x), m_y(y) {}

	double getDistanceToGivenPoint(const Point& other) const {
		int dx = m_x - other.m_x;
		int dy = m_y - other.m_y;

		return sqrt(pow(dx, 2) + pow(dy, 2));
	}
};

int main()
{
	int x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	Point point1(x1, y1);
	Point point2(x2, y2);

	cout << fixed << setprecision(3) << point1.getDistanceToGivenPoint(point2);
}