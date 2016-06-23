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

#ifndef ___HASH_MANAGER_H___
#define ___HASH_MANAGER_H___

#include "rhsyscfg.h"
#include "clutil.h"
#include <string>

#include "sizehash.h"
#include "sha1.h"
#include "sha2.h"
#include "tiger.h"

#define HASHID_NULL       0

#define HASHID_SHA2_512   17

#define RH_MAX_ALGORITHMS 19

#define OPT_NULL          0
#define OPT_FULLPATH      1
#define OPT_RECURSIVE     2
#define OPT_MAX_OPTIONS   3

// You may use all 12 characters
#define SZ_EMPTY       "            "

#define SZ_SHA2_512    "SHA-512     "


#define SZ_HASHPRE     " : "
#define SZ_HASHSEP     " "

#define SIZE_HASH_BUFFER       16384
#define NUM_DIGBLOCKS_PER_LINE 24

class CHashManager
{
public:
	// Constructor and destructor
	CHashManager();
	virtual ~CHashManager();

	void SelectAllAlgorithms(bool bSelect = true);
	bool SelectAlgorithm(int nAlgorithm, bool bSelect = true);
	bool SetOption(int nOption, bool bState);

	std::string HashPath(char *pszBasePath, char *pszFileSpec);
	std::string HashFile(char *pszFile);

private:
	void fmtFixHashOutput(int nCursorPos);

	bool m_bAlgorithm[RH_MAX_ALGORITHMS];

	bool m_bFullPath;
	bool m_bRecursive;

	unsigned short m_crc16;
	unsigned short m_crc16ccitt;
	unsigned long m_crc32;
	unsigned short m_fcs16;
	unsigned long m_fcs32;

	sha1_ctx m_sha1;
	sha256_ctx m_sha256;
	sha384_ctx m_sha384;
	sha512_ctx m_sha512;
	unsigned long m_uSizeHash32;
	tiger_hash_state m_tiger;
};

#endif // ___HASH_MANAGER_H___
