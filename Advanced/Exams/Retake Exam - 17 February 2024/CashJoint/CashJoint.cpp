// CashJoint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Cash Joint
//You're tasked to create the software for exchange office. Your software must have the following
//functionalities:
//1. Support a number of currencies
//2. Support the following commands :
//3.1.Adding currency ballance to an account
//3.2.Subtract currency ballance from an account
//3.3.Exchange currency ballance between accounts
//3.4.Print all balances
//3.5.Quit
//Input
//The first part of the input is your data initialization.You will currency balance initialization commands,
//each on a separate row.The commands will have the following format :
//CURRENCY_TICKER CURRENCY_AMOUNT
//Where :
//• CURRENCY_TICKER is a three - letter abbreviation(e.g., the "ticker") of the currency, for example
//"USD", "BGN", "EUR" or "GBP"
//• CURRENCY_AMOUNT is a double value, which instructs the program to initialize the respective
//"currency drawer" with this amount.
//o If CURRENCY_TICKER is END, this means that all initial amounts are loaded, so now follows
//the second part of the initialization.
//The second part of the input are your "commands".Each command comes in a separate row.The list of
//the commands is as follows :
//
//Command Example Explanation
//Add amount to
//account
//+ USD 20 Adds a specified amount to specified account.In
//the example, the account with
//ticker USD receives 20.
//Bear in mind : the numbers are double, not int,
//although there might be no.in the examaples.
//Subtract amount
//from an account
//- EUR 20.0 The same as above, but subtracts the given
//amount from the account with the corresponding
//© SoftUni – about.softuni.bg.Copyrighted document.Unauthorized copy, reproduction or use is not permitted.
//
//Follow us : Page 2 of 3
//Command Example Explanation
//ticker.The example subtracts 20 from the
//account EUR.
//Exchange from
//account to another
//account
//X USD 25.34 EUR 1.05 This command exchanges from the currency
//(USD) the amount of 25.34 and adds EUR amount
//26.607 (25.34 * 1.05) the correct value.
//Please note : we do not do any rounding to the
//second digit!
//Prints out all
//accounts with their
//corresponding
//amounts.
//P Prints all accounts in the order of their
//initialization.
//Each account and its amount are on a separate
//row and must have the following
//format : CURRENCY_TICKER:
//CURRENCY_AMOUNT.For example : USD: 26.61.
//Please note : we do round to the second digit.
//Exits the program E The program exits.This is your the command in
//your sequence.
//Limitations :
//	1. You will always get correct input and output.
//	2. In the operations part, you’ll never get a currency, which was not initialized
//	3. It’s OK the amounts to become negative, do not add verification if you have enough money
//	in the source currency when you exchange or subtract.

#include <iostream>

using namespace std;

int main()
{

}