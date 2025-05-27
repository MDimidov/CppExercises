//Resources
//You are given code for a program that reads information about Resources(links to Presentations, Demos, or Videos) in the SoftUni Learning system and then sorts them by their id, and also prints how many of each type of resource there was in the input.
//Each Resource has the following properties :
//•	An integer id
//•	A ResourceType – one of Presentation, Demo, or Video
//•	A string representing the link to the resource
//The code for the program is in the ResourcesMain.cpp and it uses a Resource class, which it expects to be defined in a file named "Resource.h" in the same directory.
//Your task is to study the ResourcesMain.cpp file and the ResourceType.h file, and to create the Resource.h file and implement the Resource class in such a way that the program correctly reads the input, orders it by id, prints it as lines on the output(each Resource output line should have the same format as the matching Resource input line) and then prints the number of Resources of each type.
//Your Resource.h file should resemble the following :

#pragma once

#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

using namespace std;

namespace SoftUni {
	class Resource {
	private:
		int id;
		ResourceType type;
		string url;
	public:

		Resource(int id, ResourceType type, string url)
			: id(id), type(type), url(url) {
		}

		Resource() {}

		int getId() const {
			return this->id;
		}

		ResourceType getType() const {
			return this->type;
		}

		string getUrl() const {
			return this->url;
		}

		void setId(int id) {
			this->id = id;
		}

		void setType(ResourceType type) {
			this->type = type;
		}

		void setType(const string& t) {
			if (t == "Presentation") {
				this->type = ResourceType::PRESENTATION;
			}
			if (t == "Demo") {
				this->type = ResourceType::DEMO;
			}
			if (t == "Video") {
				this->type = ResourceType::VIDEO;
			}
		}

		void setUrl(string& url) {
			this->url = url;
		}

		bool operator<(const Resource& other) const {
			return this->id < other.id;
		}
	};

	Resource& operator>>(istream& is, Resource& r) {
		int id;
		string type;
		string url;
		is >> id >> type >> url;

		r.setId(id);
		r.setType(type);
		r.setUrl(url);

		return r;
	}

	ostream& operator<<(ostream& os, const Resource& r) {
		os << r.getId() << " " << r.getType() << " " << r.getUrl();

		return os;
	}
}

#endif // !RESOURCE_H 
