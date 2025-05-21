// ShoppingList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//1.	Shopping List
//Help Tom go to the supermarket.He has a list of Shopping Items with a price and count of each of them.
//Input
//•	On the first line, you are given an integer number of Shopping items.
//•	On the next lines, you are given :
//o	Name of Shopping Items
//o	Price of Item
//o	Shopping Item’s Count
//Note : There can only be one item with the same name.
//Output
//•	Print the total sum of the products – "The total sum is: {total sum} lv."
//•	Sort the Shopping Items by their final price.
//•	The final price is calculated by multiplying the Shopping Item’s count by the Shopping Item’s price(finalPrice = count * price)
//Note : If there are two or more items with the same price, print them in the order of their entrance.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
	string name{ "" };
	double price{ 0 };
	int quantity{ 0 };
	double finalPrice{ 0 };

	void setFinalPrice() {
		finalPrice = price * quantity;
	}

	void printItem() {
		cout << name << " " << finalPrice << endl;
	}
};

void fillProductsFromConsole(vector<Product>& products) {
	int totalItems;
	cin >> totalItems;

	for (int i = 0; i < totalItems; i++) {
		Product product;

		cin >> product.name;
		cin >> product.price;
		cin >> product.quantity;

		product.setFinalPrice();

		products.push_back(product);
	}
}

bool compareByFinalPrice(const Product& a, const Product& b)
{
	return a.finalPrice < b.finalPrice;
}

double getTotalSum(vector<Product>& products) {
	double totalSum = 0;
	for (auto& product : products) {
		totalSum += product.finalPrice;
	}

	return totalSum;
}

void printItems(vector<Product>& products) {
	cout << "The total sum is: " << getTotalSum(products) << " lv." << endl;

	for (auto& product : products) {
		product.printItem();
	}
}
int main()
{
	vector<Product> products;

	fillProductsFromConsole(products);

	sort(products.rbegin(), products.rend(), compareByFinalPrice);

	printItems(products);
}