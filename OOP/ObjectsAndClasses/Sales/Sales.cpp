// Sales.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Sales
//Write a class Sale holding the following data : town, product, price and quantity.Read a list of sales and calculate and print the total sales by the town as shown in the output.Order the towns alphabetically in the output.


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class Sale {
public:
	string town;
	string product;
	double totalPrice{ 0 };

	Sale(string town, string product, double price, int quantity)
		: town(town), product(product), price(price), quantity(quantity) {
		totalPrice += price * quantity;
	}

private:
	double price;
	int quantity;

};

void addSale(map<string, vector<Sale>>& sales, string& line) {
	string town, product;
	double price;
	int quantity;

	istringstream iss(line);

	iss >> town >> product >> price >> quantity;

	sales[town].push_back(Sale(town, product, price, quantity));
}

int main()
{
	map<string, vector<Sale>> sales;

	int num;
	cin >> num;
	cin.ignore();

	string line;
	for (int i = 0; i < num; i++) {
		getline(cin, line);
		addSale(sales, line);
	}

	for (auto& kvp : sales) {
		double sum = 0;

		for (auto& sale : kvp.second) {
			sum += sale.totalPrice;
		}

		cout << kvp.first << " -> " << fixed << setprecision(2) << sum << endl;
	}
}
