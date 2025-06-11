// DivisibleBy45.cpp : This file contains the 'main' function. Program execution begins and ends there.
//You are given a BigInt.h file with the implementation of a BigInt class which can represent positive integers of any size, can calculate sums of such integers, and has some other useful methods and operators defined. You can use this class in your program if you want to.
//•	The Judge system has a copy of this class and will compile your code in the same directory.
//•	To use it, you can write #include "BigInt.h" in your code.
//•	DO NOT submit or modify BitInt.h, as the system will overwrite it with its version.If you want to extend the functionality of that class, you will need to do it in another file.
//Your task is to write a program that finds all the numbers, which are divisible by 45, inside a specified range.
//For this task the system only has a copy of the BigInt.h file, so the.zip file you upload should contain a file with the main() function, and you should handle input and output as described below.
//Input
//Exactly 2 lines, each containing a single integer number – with an arbitrary length, but no more than 100 digits.
//The first line contains the start of the range(inclusive) S
//The second line contains the end of the range(exclusive) E
//Output
//One or more lines, with a single integer number each, representing the numbers divisible by 45 in the given range, in ascending order(i.e.start from the smallest number divisible by 45 in the range and print each of them on a separate line).
//Restrictions
//The range will be such that the total numbers divisible by 45 will be no more than 100.
//The number of digits in the numbers specifying the range will NOT exceed 100.
//0 < S < E - 1
//    The total running time of your program should be no more than 0.1s.
//    The total memory allowed for use by your program is 5MB.


#include <iostream>
#include "BigInt.h"
#include <set>
#include <string>
#include <sstream>

using namespace std;

bool isDivisibleBy45(const BigInt& num) {
	const std::string& digits = num.getDigits();
	if (digits.empty()) return false;

	char lastDigit = digits.back();
	if (lastDigit != '0' && lastDigit != '5') {
		return false;
	}

	int sum = 0;
	for (char c : digits) {
		sum += (c - '0');
	}

	return (sum % 9 == 0);
}

int main()
{
	string line1, line2;
	cin >> line1 >> line2;
	BigInt firstNum(line1), lastNum(line2);
	
	
	set<BigInt> result;

	for (BigInt i = firstNum; i < lastNum;) {
		if (isDivisibleBy45(i)) {
			result.insert(i);
			i += 45;
		}
		else {
			i += 1;
		}
	}

	for (auto& num : result) {
		cout << num << endl;
	}
}
