// EvenTimes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Even Times
//Write a program that prints a number from a collection, which appears an even number of times in it. On the first line, you will be given n – the count of integers you will receive. On the next n lines, you will be receiving the numbers. It is guaranteed that only one of them appears an even number of times. Your task is to find that number and print it in the end. 

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int num;

    unordered_map<int, int> nums;

    for(int i = 0; i < n; i++) {
        cin >> num;

        nums[num]++;
    }

    for (auto& kvp : nums) {
        if (kvp.second % 2 == 0) {
            cout << kvp.first;
            break;
        }
    }
}
