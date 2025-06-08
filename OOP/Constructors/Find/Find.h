//Find
//You are given a program in a Main.cpp file that reads info about companies – name and id – and then reads a search id, finds a company with that id, and prints the info about that company.If no such company has been entered, the program prints "[not found]".To do the search, the program uses a function named to find.To describe a company, it uses the Company.h file, which you are also given.
//Your task is to study the code in Main.cpp, then create a file called Find.h(which Main.cpp includes) containing the definition of the find function, written in such a way that Main.cpp compiles successfully and works as described above.
//You should submit a single.zip file for this task, containing ONLY the Find.h file.The Judge system has a copy of the Main.cpp file and will compile it along with your Find.h file in the same directory.
//To correctly use the Company definition, without interfering with its usage by Main.cpp, use the following structure for the Find.h file :


#pragma once
#ifndef FIND_H
#define FIND_H

#include "Company.h"
#include<algorithm>

using namespace std;

Company* find(const vector<Company*>& companies, int searchedId) {
	auto it = find_if(companies.begin(), companies.end(),
		[&](Company* const& comp) {
			return comp->getId() == searchedId;
		});

	if (it != companies.end()) {
		return *it;
	}

	return nullptr;
}

#endif // !FIND_H
