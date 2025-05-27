#pragma once

#ifndef CAR_H
#define CAR_H

#include <iostream>
using namespace std;

class Car
{
private:
	string brand;
	string model;
	int year;

public:
	Car(string brand, string model, int year)
		: brand(brand), model(model), year(year) {
	}

	string const GetBrand() const {
		return this->brand;
	}

	string const GetModel() const {
		return this->model;
	}

	int const GetYear() const {
		return this->year;
	}
};

#endif

