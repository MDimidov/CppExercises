// Fishes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//. Fishes
//You're a fisherman! You got three fishing poles, each one catching some fish.
//You also have three bags, where you store the fish from each pole.The fish from pole 1 always goes to bag 1, the
//fish from pole 2 – to bag 2, and the fish from pole 3 – to bag 3. Each fish you put in a bag is put on top of all other
//fishes, if there are such already in the bag.If you decide to takea fish from a bag, you can only pick the topmost fish,
//the one you put last.
//Each time, when a fishing pole catches a fish, you will get a line in your input, which gives you the pole number(1 to
//    3) and the kind of the fish it caught.For example "1 Sea Bass" (please note : the name of the fish may contain
//        space).
//    Also, there're two special input rows:
//    1. The input row "END" indicates that you're done with catching fishes and you move to the second stage of
//    your task.
//    2. If you get a row with the special fish name "THROW", it means that you must throw out a fish at the top of
//    the corresponding bag(the bag number will come with the command).For example : an input row "2
//    THROW" tells you to throw away a fish from bag 2.
//    If bag 2 is empty, you just ignore the command.
//    Once you're done with catching and throwing fishes, you must print all contents of your bags. Although you can pick
//    up only the top - most fish from a bag, you must print the contents of each bag in the order you added the fish to the
//    bag!Each bag contents are printed on a single row in the following format :
//"1: Sea Bass, Swordfish, Swordfish"
//If a bag is empty, we print "<empty>" for its contents.
//After you print out the contents, you must sort your catch and decide which fish to keep for delivery to restaurants,
//and which fish to deliver for "fish pâté".To make this distribution, you will get a list of fish names : each one on a
//separate line, the list ends with "END".
//Each fish name you get tells you that all fishes from this kind in all your bags will go for "Restaurant" delivery.
//After the list of fishes for the restaurant ends, you must put all the remaining fishes from your bags for "fish pâté".
//Then you must print both inventories, each fish inventory containing the names of the fishes in alphabetical order,
//and then the quantity of each fish.The first line contains all fishes for the restaurants, the second line is all fish for
//pâté.Here’s example printout of both inventories :
//Restaurant: <Fish Name1> : <quantity1>, <Fish Name2> : <quantity2>, <Fish Name3> :
//    <quantity3>
//    Pate : <Fish Name1> : <quantity1>, <Fish Name2> : <quantity2>, <Fish Name3> :
//    <quantity3>
//    If there's no delivery for the restaurant or the pate, print "<nothing>" instead of fish list, for example:
//    © SoftUni – about.softuni.bg.Copyrighted document.Unauthorized copy, reproduction or use is not permitted.
//
//    Follow us : Page 2 of 4
//    Restaurant : <Fish Name1> : <quantity1>, <Fish Name2> : <quantity2>, <Fish Name3> :
//    <quantity3>
//    Pate : <nothing>
//    Hints :
//    1. If you manually transfer all elements from one stack to another stack, you reverse the elements from the
//    first stack.
//    2. If you have a line like "5 Some Text Here" in your istringstream istr, you can read the number
//    with the >> operator, and after that you can get the rest of the contents of the current line by using the
//    getline like that : getline(std::ws(istr), theRestOfTheTextWithoutWhitespace).In this
//    case, the first parameter of getline "eats" the whitespace before the text.
//    Or, you can decide to handle the whitespace differently.



#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    map<int, stack<string>> bags;         // bags[1], bags[2], bags[3]
    map<int, vector<string>> addedOrder;  // for printing in order
    map<string, int> fishCounts;          // total count of all fishes

    string line;
    while (getline(cin, line) && line != "END") {
        istringstream iss(line);
        int pole;
        iss >> pole;

        string fish;
        getline(iss >> ws, fish);  // get the rest of the line after number

        if (fish == "THROW") {
            if (!bags[pole].empty()) {
                string topFish = bags[pole].top();
                bags[pole].pop();
                addedOrder[pole].pop_back();
                if (--fishCounts[topFish] == 0) {
                    fishCounts.erase(topFish);
                }
            }
        }
        else {
            bags[pole].push(fish);
            addedOrder[pole].push_back(fish);
            fishCounts[fish]++;
        }
    }

    // Print bag contents
    for (int i = 1; i <= 3; ++i) {
        cout << i << ": ";
        if (addedOrder[i].empty()) {
            cout << "<empty>" << endl;
        }
        else {
            for (size_t j = 0; j < addedOrder[i].size(); ++j) {
                cout << addedOrder[i][j];
                if (j != addedOrder[i].size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }

    // Read restaurant fish list
    map<string, int> restaurantFish;
    while (getline(cin, line) && line != "END") {
        if (fishCounts.count(line)) {
            restaurantFish[line] = fishCounts[line];
            fishCounts.erase(line);
        }
    }

    // Print restaurant
    cout << "Restaurant:";
    if (restaurantFish.empty()) {
        cout << " <nothing>";
    }
    else {
        bool first = true;
        for (const auto& kvp : restaurantFish) {
            if (!first) cout << ",";
            cout << " " << kvp.first << ": " << kvp.second;
            first = false;
        }
    }
    cout << endl;

    // Print pate
    cout << "Pate:";
    if (fishCounts.empty()) {
        cout << " <nothing>";
    }
    else {
        bool first = true;
        for (const auto& kvp : fishCounts) {
            if (!first) cout << ",";
            cout << " " << kvp.first << ": " << kvp.second;
            first = false;
        }
    }
    return 0;
}
