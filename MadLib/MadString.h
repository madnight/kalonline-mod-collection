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
 
#include <string>
#include <vector>
#include <sstream>

class MadString
{
public:
	std::string madstring;
	MadString(std::string mad) {this->madstring = mad; }

	bool beginWith(std::string begin);
	void reverseStr();
	unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch);
};

