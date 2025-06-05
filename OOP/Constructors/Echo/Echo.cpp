#include <iostream>
#include "Echo.h"

bool echoOn = true;

void echo(const string& msg) {
	if (echoOn) {
		cout << msg << endl;
	}
}