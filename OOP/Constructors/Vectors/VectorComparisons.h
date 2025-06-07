//Vectors
//You are given code for a program that reads Vectors from the console, sorts them in reverse order of their length(the Vector class defines methods for length calculation), and prints them(longest - first).For that, it uses a multiset and supplies an additional template parameter that instructs the multiset on how to compare two Vector objects.
//Your task is to study the way the provided code and create types that allow the appropriate comparison of Vector objects, such that the resulting code accomplishes the task described.
//You should submit a single.zip file for this task, containing ONLY the files you created.
//The Judge system has a copy of the other files and will compile them, along with your file(s), in the same directory.


#pragma once
#ifndef VECTORCOMPARISONS_H
#define VECTORCOMPARISONS_H

#include <iostream>
#include <vector>
#include "Vector.h"


struct VectorLengthComparer {
	bool operator()(const Vector& a, const Vector& b) const {
		return a.getLength() < b.getLength();
	}
};

template <typename T, typename Comp>
struct ReverseComparer {
	bool operator()(const T& a, const T& b) const {
		return Comp()(b, a);
	}
};

#endif // !VECTORCOMPARISONS_H
