// ProductsAndCities.cpp : This file contains the 'main' function. Program execution begins and ends there.
//1.	Products and Cities
//By given a number of Cities, price per product and quantity of products, write a program that calculates the Total price(product* pricePerProduct).The first number is the number of cities we want to input.The second is the CITY.The third is the price per product.The fourth is the quantity of products.
//Input
//On the first line you will receive the number of cities.
//On the next lines you will receive the cities, followed by the price per product and quantity of products.
//Output
//Print the City followed by the result number.


#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, double> cities;

	int n;
	cin >> n;
	cin.ignore();

	string cityName;
	double price;
	int quantity;

	while (cin >> cityName >> price >> quantity) {
		if (cities.size() < n || cities.count(cityName)) {
			cities[cityName] += price * quantity;
		}
	}

	for (auto& kvp : cities) {
		cout << kvp.first << " " << kvp.second << endl;
	}
}