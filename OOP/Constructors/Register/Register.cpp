//Register
//You are given code that reads information about Company objects from the console, parses it multiple times(the number of repetitions is entered on the first line on the console), and prints the information about one of the Company objects, specified by its id.
//The provided code handles input, output, and the repeated executions – your task is to implement the Register(which is declared in the Register.h file, you need to create the Register.cpp file) class it uses for storing and looking up the Company objects.
//You should submit a single.zip file for this task, containing ONLY the file(s) YOU created.The Judge system has a copy of the other files and will compile them, along with your file, in the same directory.
//Restrictions
//There will always be a Company with the specified id.
//Make sure there are no memory leaks.

#include "Register.h"
#include <cassert>

Register::Register(size_t numCompanies)
{
	numAdded = 0;
	companiesArray = new Company[numCompanies];
}

void Register::add(const Company& c) {
	companiesArray[numAdded++] = c;
}

Company Register::get(int companyId) const {
	for (int i = 0; i < numAdded; i++) {
		if (companiesArray[i].getId() == companyId) {
			return companiesArray[i];
		}
	}

	assert(false && "Company ID not found in Register");

	return Company();
}

Register::~Register()
{
	delete[] companiesArray;
}