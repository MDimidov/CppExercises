// FastFood.cpp : This file contains the 'main' function. Program execution begins and ends there.
//You have a fast-food restaurant and most of the food that you're offering is previously prepared. You need to know if you will have enough food to serve lunch to all of your customers. Write a program that checks the orders' quantity. You also want to know the client with the biggest order for the day, because you want to give him a discount the next time he comes. 
//First, you will be given the quantity of the food that you have for the day(an integer number).Next, you will be given a sequence of integers, each representing the quantity of order.Keep the orders in a queue.Find the biggest order and print it.You will begin servicing your clients from the first one that came.Before each order, check if you have enough food left to complete it.If you have, remove the order from the queue and reduce the amount of food you have.If you succeeded in servicing all of your clients, print:
//"Orders complete".
//If not, print :
//    "Orders left: {order1} {order2} .... {orderN}".
//    Input
//    •	On the first line, you will be given the quantity of your food – an integer in the range[0 - 1000].
//    •	On the second line, you will receive a sequence of integers, representing each order, separated by a single space.
//    Output
//    •	Print the quantity of the biggest order.
//    •	Print "Orders complete" if the orders are complete.
//    •	If there are orders left, print them in the format given above.
//    Constraints
//    •	The input will always be valid.


#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;
struct Result {
public:
	queue<int> orders;
	int maxOrder{ 0 };
};

Result getOrders(string& input) {
	Result result;
	int order;

	istringstream iss(input);
	while (iss >> order) {
		if (result.maxOrder < order) {
			result.maxOrder = order;
		}
		result.orders.push(order);
	}

	return result;
}

int main()
{
	int totalFood;
	cin >> totalFood;
	cin.ignore();

	string line;
	getline(cin, line);

	Result ordersStruct = getOrders(line);

	queue<int> orders = ordersStruct.orders;

	int maxOrder = 0;
	string finalResult = "Orders complete";

	while (!orders.empty()) {
		if (totalFood >= orders.front()) {
			totalFood -= orders.front();

			orders.pop();
		}
		else {
			finalResult = "Orders left:";
			break;
		}
	}

	cout << ordersStruct.maxOrder << endl;
	if (orders.empty()) {
		cout << finalResult;
	}
	else {
		cout << finalResult;
		while (!orders.empty()) {
			cout << " " << orders.front();
			orders.pop();
		}
	}
}
