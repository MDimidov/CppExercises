#pragma once
#ifndef ARTICLE_13_FILTER_CPP
#define ARTICLE_13_FILTER_CPP

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

#endif // !ARTICLE_13_FILTER_H

