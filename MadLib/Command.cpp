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
 
#include "Command.h"


bool Command::beginWith(std::string begin)
{
	if (this->command.size() >= begin.size())
	{
		if (this->command.substr(0, begin.size()) == begin)
			return true;
	}
	return false;
}

unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch)
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



std::string Command::GetParamString(int x)
{
	std::vector<std::string> v;
	split(this->command, v, ' ');
	if (v.size() > (unsigned int) x)
		return v[x];
	else
		return "";
}

int Command::GetParamInt(int x)
{
	std::vector<std::string> v;
	split(this->command, v, ' ');
    return (v.size() > (unsigned int) x) ? 
		 atoi(v[x].c_str()) : 0;
}