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

