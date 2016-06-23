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