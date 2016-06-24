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
 
#pragma once
#include <string>
#include <vector>

class Command
{
private: 
	std::string command;

public:
	Command(std::string command) { this->command = command; }

	bool beginWith(std::string begin);
	std::string GetParamString(int x);
	int GetParamInt(int x);
};