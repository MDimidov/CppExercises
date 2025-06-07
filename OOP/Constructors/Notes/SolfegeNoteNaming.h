#pragma once
#ifndef SOLFEGENOTENAMING_H
#define SOLFEGENOTENAMING_H

#include<iostream>
#include<string>
#include<map>
#include "NoteName.h"	

using namespace std;

struct SolfegeNoteNaming {
	map<string, char> notesTranslation = {
		{"Do", 'C'},
		{"Re", 'D'},
		{"Mi", 'E'},
		{"Fa", 'F'},
		{"Sol", 'G'},
		{"La", 'A'},
		{"Si", 'B'}
	};

	NoteName operator() (const string& noteText) const {
		auto it = notesTranslation.find(noteText);
		if (it != notesTranslation.end()) {
			return NoteName(it->second);
		}
		return NoteName('?');
	}

};

#endif // !SOLFEGENOTENAMING_H
