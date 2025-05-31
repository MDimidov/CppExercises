//Censorship
//Did you hear about article 13 ? You should.
//You are given some code, which reads a line of strings(separated by single spaces) which describe "copyrighted" strings.Then it reads several lines(until a line containing the string "end" is entered), and checks each of them against the copyrighted words :
//•	If the line matches a copyrighted string, it is "blocked"
//•	Otherwise it is printed back on the output
//•	The last line "end" is not included in this logic, it just determines when the reading ends.No two lines will be the same.
//•	After the end line, the program prints a line beginning with "Blocked: ", followed by all the blocked strings, separated by single spaces, in the order they were entered
//The program handles input and output, but uses a class named Article13Filter to do the blocking and store the blocked strings.
//Your task is to study the available code and create a file with code such that the program compiles successfully and accomplishes the task described above.
//You should submit a single.zip file for this task, containing ONLY the file(s) YOU created.The Judge system has a copy of the other files and will compile them, along with your file, in the same directory.

#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted)
	: copyrighted(copyrighted) {
}

bool Article13Filter::blockIfCopyrighted(const std::string s)
{
	if (isCopyrighted(s)) {
		this->blocked.push_back(s);
		return true;
	}

	return false;
}
bool Article13Filter::isCopyrighted(const std::string s) {
	return this->copyrighted.find(s) != this->copyrighted.end();
}

std::vector<std::string> Article13Filter::getBlocked() {
	return this->blocked;
}