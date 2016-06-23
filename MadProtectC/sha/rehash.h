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

#ifndef ___REHASH_H___
#define ___REHASH_H___

#include "rhsyscfg.h"

#define SZ_REHASH_VERSION  "1.0.1"
#define SZ_REHASH_HOMEPAGE "http://www.reichlsoft.de.vu"

#define RH_MAX_PATH   2048
#define RH_MAX_BUFFER 2048

#define RH_SUCCESS          0
#define RH_NO_ARGS          1
#define RH_NO_PATH          2
#define RH_CANNOT_OPEN_FILE 3
#define RH_INVALID_PATH     4
#define RH_NO_PATTERN_MATCH 5
#define RH_DIRECTORY_ERROR  6

std::string SHA_512(char *argv);

#endif // ___REHASH_H___
