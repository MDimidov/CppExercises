//Order
//You are given a program in an OrderMain.cpp file that reads info about companies – name and id – and then prints them ordered by their id, in increasing order.To describe a company, it uses the Company.h file, which you are also given.
//To order the companies, OrderMain.cpp uses a class named OrderedInserter from a file named OrderedInserter.h – it initializes it with an empty vector of companies, then calls a method named insert for each company in the input, then prints the contents of the vector.
//Your task is to study the code in OrderMain.cpp, then create a file called OrderedInserter.h(which OrderMain.cpp includes) containing the definition of the OrderedInserter class, written in such a way that Main.cpp compiles successfully and works as described above.
//You should submit a single.zip file for this task, containing ONLY the OrderedInserter.h file.The Judge system has a copy of the other files and will compile them along with your OrderedInserter.h file in the same directory.
//To correctly use the Company definition, without interfering with its usage by OrderMain.cpp, use the following structure for the OrderedInserter.h file :

#pragma once
#ifndef ORDERED_INSERTER_H 
#define ORDERED_INSERTER_H

#include "Company.h"
#include<vector>
#include<algorithm>

using namespace std;

class OrderedInserter {
private:
	vector<const Company*>& companies;
public:
	OrderedInserter(vector<const Company*>& companies)
		: companies(companies) {
	}

	void insert(const Company* c) {
		companies.push_back(c);
		orderById();
	}

	void orderById() {
		stable_sort(companies.begin(), companies.end(),
			[](const Company* a, const Company* b) {
				return a->getId() < b->getId();
			});
	}
};

#endif // !ORDERED_INSERTER_H
