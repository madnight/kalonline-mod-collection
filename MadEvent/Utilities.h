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
 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <process.h>
#include <ctime>
#include <vector>
#include "../Server.h"
using namespace std;

vector<int> starttimes;
vector<int> endtimes;

void readConfig()
{
	string prefix_start = "[StartTime]";
	string prefix_end = "[EndTime]";
	ifstream f;
	string s;
	string t;
	ifstream ifile("eventtable.txt");
	if (ifile) 
	{
		f.open("eventtable.txt", ios::in);
		while (!f.eof())        
		{
			getline(f, s);      
			if (s.substr(0, prefix_start.size()) == prefix_start) 
			{
				t = (s.substr(prefix_start.size(),30));	
				starttimes.push_back( atoi( t.c_str()) );
			}

			if (s.substr(0, prefix_end.size()) == prefix_end) 
			{
				t = (s.substr(prefix_end.size(),30));	
				endtimes.push_back( atoi( t.c_str()) );
			}
		}		
	}
	f.close();            
}

bool eventon = false;
bool eventfound = false;

void EventCheck()
{ 
	eventfound = false;
	for (unsigned int i = 0; i < starttimes.size() && i < endtimes.size(); i++) 
	{
		time_t t = time(0);   
		struct tm * now = localtime(&t);
		int datetime = (now->tm_hour*100)+now->tm_min;
		if ( starttimes[i] <= datetime && datetime < endtimes[i])
		{
			eventfound = true;
		}
	}
	if (eventfound && !eventon)
	{
		eventon = true;
		Server::CPlayer::SetEventCode(0,8);
		Server::Console::WriteBlue("[Event started]");
	}
	if (!eventfound && eventon)
	{
		eventon = false;
		Server::CPlayer::SetEventCode(0,0);
		Server::Console::WriteRed("[Event ended]");		
	}
}

