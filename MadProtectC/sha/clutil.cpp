/*
	---------------------------------------------------------------------------
	Copyright (c) 2003, Dominik Reichl <dominik.reichl@t-online.de>, Germany.
	All rights reserved.

	Distributed under the terms of the GNU General Public License v2.

	This software is provided 'as is' with no explicit or implied warranties
	in respect of its properties, including, but not limited to, correctness 
	and/or fitness for purpose.
	---------------------------------------------------------------------------
*/

#include "clutil.h"
#include "rehash.h"

bool isArgument(char *pszString)
{
	if(pszString == NULL) return false;

	if(pszString[0] == '-') return true;

	return false;
}

void fmtArgument(char *pszArg, char *pszDest)
{
	unsigned int i = 0;
	int pos = 0;

	if(pszArg == NULL) return;
	if(pszDest == NULL) return;

	pszDest[0] = 0;

	// Filter special characters
	for(i = 0; i < strlen(pszArg); i++)
	{
		if(pszArg[i] == '-') continue;
		if(pszArg[i] == '#') continue;
		if(pszArg[i] == ' ') continue;
		if(pszArg[i] == '<') continue;
		if(pszArg[i] == '>') continue;
		if(pszArg[i] == '(') continue;
		if(pszArg[i] == ')') continue;
		if(pszArg[i] == '[') continue;
		if(pszArg[i] == ']') continue;
		if(pszArg[i] == '/') continue;
		if(pszArg[i] == '\\') continue;
		if(pszArg[i] == '\"') continue;

		pszDest[pos] = pszArg[i];
		pos++;
	}

	pszDest[pos] = 0;

	strlwr(pszDest);
}

void fmtPath(char *pszPath)
{
	unsigned int i = 0;
	char chFind = 0;
	char chReplace = 0;

	if(pszPath == NULL) return;
	if(strlen(pszPath) == 0) return;

	#if(RH_TARGET_SYSTEM == RH_TARGET_SYSTEM_WINDOWS)
		chFind    = '/';
		chReplace = '\\';
	#elif(RH_TARGET_SYSTEM == RH_TARGET_SYSTEM_LINUX)
		chFind    = '\\';
		chReplace = '/';
	#endif

	for(i = 0; i < strlen(pszPath); i++)
	{
		if(pszPath[i] == chFind) pszPath[i] = chReplace;
	}
}

void catdirsep(char *pszPath)
{
	unsigned int i = 0;

	if(pszPath == NULL) return;

	i = strlen(pszPath);

	if(pszPath[i-1] == SZ_DIR_CHAR) return; // Nothing to do

	strcat(pszPath, SZ_DIR_STR);
}

void pathonly(char *pszPath)
{
	unsigned int i = 0;
	bool bReplaced = false;

	if(pszPath == NULL) return;

	i = strlen(pszPath) - 1;
	if(i == (unsigned int)-1) return;
	while(1)
	{
		if(pszPath[i] == SZ_DIR_CHAR)
		{
			pszPath[i] = 0;
			bReplaced = true;
			break;
		}

		i--;
		if(i == (unsigned int)-1) break;
	}

	if(bReplaced == false) pszPath[0] = 0;

	#if(RH_TARGET_SYSTEM == RH_TARGET_SYSTEM_WINDOWS)
		if(strlen(pszPath) == 2) catdirsep(pszPath);
	#endif
}

void fileonly(char *pszPath)
{
	char szTemp[RH_MAX_PATH];
	unsigned int i = 0;
	unsigned int j = 0;

	if(pszPath == NULL) return;

	i = strlen(pszPath) - 1;
	if(i == (unsigned int)-1) return;
	if(i <= 1) return;

	while(1) // Reverse scan for path delimiter
	{
		if(pszPath[i] == SZ_DIR_CHAR) break;
		i--;
		if(i == 0) break;
	}

	if(i == 0) return;

	j = 0;
	i++;
	for( ; i < strlen(pszPath); i++) // Copy only filename to new buffer
	{
		szTemp[j] = pszPath[i];
		j++;
	}
	szTemp[j] = 0;

	strcpy(pszPath, szTemp); // Copy working buffer to return buffer
}

// Is this a <..> or <.> path env descriptor?
bool ispathnav(char *pszPath)
{
	unsigned int i = 0;

	if(pszPath == NULL) return false;

	i = strlen(pszPath);
	if(i == 0) return false;
	if((pszPath[i-1] == '.') && (i == 1)) return true;
	if((pszPath[i-1] == '.') && (pszPath[i-2] == '.') && (i == 2)) return true;
	if((pszPath[i-1] == '.') && (pszPath[i-2] == SZ_DIR_CHAR)) return true;
	if((pszPath[i-1] == '.') && (pszPath[i-2] == '.') && (pszPath[i-3] == SZ_DIR_CHAR)) return true;

	return false;
}
