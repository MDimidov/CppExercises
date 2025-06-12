//Sequences
//You are given code for a program that uses a Sequence class that can be iterated with a range - based for loop and can generate its elements using a templated Generator type, which overloads parameter - less operator() to generate the next element in the sequence.The provided code has two Generator types – IntegersGenerator and FibonacciGenerator, respectively generating the integer numbers starting from 0 and the Fibonacci numbers starting from 0.
//The provided code reads a number from the console, generates that amount of elements in the sequence, prints the first element, then reads a number again, generates that amount of new elements in the sequence, prints the second element, and so on, and continues until no more generated elements remain(meaning that the input always ends with 0).
//Your task is to implement the Sequence class to support the described operations so that the code accomplishes the task described.
//You should submit a single.zip file for this task, containing ONLY the files you created.
//The Judge system has a copy of the other files and will compile them, along with your file(s), in the same directory.

#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <vector>

template <typename T, typename Generator>
class Sequence {

private:
	std::vector <T> nums;
	Generator gen;

    struct iterator {
        std::vector<T>& vec;
        size_t index;

        iterator(std::vector<T>& v, size_t i) : vec(v), index(i) {}

        T operator*() const {
            return vec[index];
        }

        iterator& operator++() {
            ++index;
            return *this;
        }

        // Key: compare with current vector size, not a fixed end iterator
        bool operator!=(const iterator& other) {
            return index < vec.size();
        }
    };

public:
    iterator begin() {
        return iterator(nums, 0);
    }

    iterator end() {
        return iterator(nums, 0);
    }

	void generateNext(int count) {
		for (int i = 0; i < count; i++) {
			nums.push_back(gen());
		}
	}
};

#endif //!SEQUENCE_H