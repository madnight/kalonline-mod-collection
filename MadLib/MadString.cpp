/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
#include "MadString.h"

bool MadString::beginWith(std::string begin)
{
	if (this->madstring.size() >= begin.size())
		if (this->madstring.substr(0, begin.size()) == begin)
			return true;
	return false;
}

void MadString::reverseStr()
{
	std::string temp = "";
	int len = this->madstring.length();
	for(int i = len - 1; i >= 0; --i)
		temp += this->madstring[i];
	this->madstring = temp;
}

unsigned int MadString::split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	unsigned int pos = txt.find( ch );
	unsigned int initialPos = 0;
	strs.clear();

	while( pos != std::string::npos ) 
	{
		strs.push_back( txt.substr( initialPos, pos - initialPos + 1 ) );
		initialPos = pos + 1;
		pos = txt.find( ch, initialPos );
	}
	strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );
	return strs.size();
}

