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
 
#include "Log.h"


void Log::Write(char* Filename, char* String)
{
	FILE* pSendLogFile;

	std::string file_name = "Log\\";
	file_name += Filename;
	file_name += ".txt";

	char filename[100];
	sprintf_s(filename, sizeof(filename),file_name.c_str());

	pSendLogFile = fopen(filename, "a+");

	fprintf(pSendLogFile,String);
	fclose(pSendLogFile);
}

