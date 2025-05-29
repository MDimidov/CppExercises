//Lectures
//You are given code similar to Task 4 – Resources, however, this time the main() code uses a Lecture object(the class for which should be defined in a Lecture.h file) to store and organize the resources.It also uses several operators to do that and iterates the Resources in the Lecture through a range - based for loop(hint: the Lecture class will need to begin() and end() methods which return iterators).
//Another difference is that in this task, there can be two Resource objects in the input which have different links but have the same id.This indicates that the Resource has been changed – i.e. if a Resource with the same id is encountered multiple times, only keep its version appearing latest in the input.
//The program’s output should be the same as in Task 4 – the resources ordered by id, followed by the number of occurrences of each ResourceType, ordered Presentation(if non - zero), then Demos(if non - zero), and last Video(if non - zero).
//Your task is to study the code, figure out what operators and classes you need to implement, search the Web for concepts you aren’t familiar with, and submit the files necessary for the program to compile and run successfully.
//You should submit a single.zip file for this task, containing ONLY the files YOU created.The Judge system has a copy of the other files and will compile them, along with your file, in the same directory.

#pragma once

#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>
#include <algorithm>
#include <vector>

#include "Resource.h"

using namespace std;

namespace SoftUni {
	class Lecture {
	private:
		vector<Resource> resources;

	public:
		Lecture() {}

		auto begin() const {
			return resources.begin();
		}

		auto end() const {
			return resources.end();
		}

		friend Lecture& operator<<(Lecture& lec, const Resource& res) {
			auto it = find_if(lec.resources.begin(), lec.resources.end(),
				[&](const Resource& res1) {
					return res1.getId() == res.getId();
				});

			if (it != lec.resources.end()) {
				*it = res;
			}
			else {
				lec.resources.push_back(res);
			}

			sort(lec.resources.begin(), lec.resources.end());
			return lec;
		}

		friend vector<ResourceType>& operator << (vector<ResourceType>& vec, Lecture& lec) {
			bool hasPresentation = false, hasDemo = false, hasVideo = false;
			for (const auto& r : lec.resources) {
				switch (r.getType()) {
				case ResourceType::PRESENTATION: hasPresentation = true; break;
				case ResourceType::DEMO: hasDemo = true; break;
				case ResourceType::VIDEO: hasVideo = true; break;
				}
			}

			if (hasPresentation) vec.push_back(ResourceType::PRESENTATION);
			if (hasDemo) vec.push_back(ResourceType::DEMO);
			if (hasVideo) vec.push_back(ResourceType::VIDEO);

			return vec;
		}

		int operator[] (ResourceType& rt) const {
			return count_if(resources.begin(), resources.end(),
				[&](const Resource& res) {
					return res.getType() == rt;
				});
		}
	};
}

#endif // !LECTURE_H
