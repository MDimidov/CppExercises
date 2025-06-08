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
