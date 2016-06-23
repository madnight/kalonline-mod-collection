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

// ReichlSoft Command Line Utilities
// Version 2.0

#ifndef ___CL_UTIL_H___
#define ___CL_UTIL_H___

#include "rhsyscfg.h"

bool isArgument(char *pszString);
void fmtArgument(char *pszArg, char *pszDest);
void fmtPath(char *pszPath);

void catdirsep(char *pszPath);
void pathonly(char *pszPath);
void fileonly(char *pszPath);
bool ispathnav(char *pszPath);

#endif // ___CL_UTIL_H___
