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
 
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> words;

void readConfig()
{
	string buffer;
	ifstream f;  
	ifstream ifile("MadConsoleWords.txt");
	if (ifile) 
	{
		f.open("MadConsoleWords.txt", ios::in);
		while (!f.eof())         
		{
			getline(f, buffer); 
			words.push_back(buffer);
			buffer.clear();
		}
	}
}

bool checkWords(string text){
	for (unsigned int i = 0; i<words.size();i++)
	{
		if (text.find(words[i]) != string::npos)
			return true;
	}
	return false;
}

