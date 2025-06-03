#pragma once
#ifndef COMPARATORS_H
#define COMPARATORS_H

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
struct LessThan {
	bool operator()(const T& a, const T& b) const {
		return b < a;
	}

};

template<typename T, typename Comp>
struct Reverse {
	bool operator()(const T& a, const T& b) const {
		return Comp()(a, b);
	}
};

#endif // !#define COMPARATORS_H
