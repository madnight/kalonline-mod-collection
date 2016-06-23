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

#include <stdlib.h>
#include <stdio.h>

#include "hashmgr.h"
#include "rehash.h"

CHashManager::CHashManager()
{
	m_bFullPath = false;
	m_bRecursive = true;

	SelectAllAlgorithms();

	//gosthash_init();
}

CHashManager::~CHashManager()
{
}

void CHashManager::SelectAllAlgorithms(bool bSelect)
{
	int i = 0;
	for(i = 0; i < RH_MAX_ALGORITHMS; i++) m_bAlgorithm[i] = bSelect;
}

bool CHashManager::SelectAlgorithm(int nAlgorithm, bool bSelect)
{
	if(nAlgorithm < 0) return false;
	if(nAlgorithm >= RH_MAX_ALGORITHMS) return false;

	m_bAlgorithm[nAlgorithm] = bSelect;
	return true;
}

bool CHashManager::SetOption(int nOption, bool bState)
{
	if(nOption <= 0) return false;
	if(nOption >= OPT_MAX_OPTIONS) return false;

	if(nOption == OPT_FULLPATH) m_bFullPath = bState;
	if(nOption == OPT_RECURSIVE) m_bRecursive = bState;

	return true;
}

std::string CHashManager::HashPath(char *pszBasePath, char *pszFileSpec)
{
	std::string result;
	recursivesafe long lHandle = 0;
	recursivesafe long lSearcherHandle = 0;
	recursivesafe finddata fdInfo;
	recursivesafe char szFull[RH_MAX_PATH];
	recursivesafe char szAll[RH_MAX_PATH];

	if(pszBasePath == NULL) return "NULL";
	if(pszFileSpec == NULL) return "NULL";

	fmtPath(pszBasePath);
	fmtPath(pszFileSpec);

	if(strlen(pszBasePath) == 0) getcwd(pszBasePath, RH_MAX_PATH);
	fileonly(pszFileSpec);

	strcpy(szAll, pszBasePath);
	catdirsep(szAll);
	strcat(szAll, SZ_DIR_ALL);

	#ifdef RH_DEBUG
		printf("Function HashPath: pszBasePath=%s, pszFileSpec=%s", pszBasePath, pszFileSpec);
		printf(CPS_NEWLINE);
		printf("Function HashPath: szAll=%s", szAll);
		printf(CPS_NEWLINE);
	#endif

	//////////////////////////////////////////////////////////////////////////
	// Start directory enumeration code

	lSearcherHandle = findfirst(szAll, &fdInfo);
	while(1)
	{
		if(fdInfo.attrib & _A_SUBDIR)
		{
			if((ispathnav(fdInfo.name) == false) && (m_bRecursive))
			{
				if(chdir(fdInfo.name) == 0)
				{
					getcwd(szFull, RH_MAX_PATH);

					#ifdef RH_DEBUG
						printf("Opening new scan path: %s, filemask: %s", szFull, pszFileSpec);
						printf(CPS_NEWLINE);
					#endif

					HashPath(szFull, pszFileSpec);
					chdir(SZ_LEVEL_UP);
				}
			}
		}

		if(findnext(lSearcherHandle, &fdInfo) != 0) break;
	}
	findclose(lSearcherHandle);
	lSearcherHandle = 0;

	// End directory enumeration code
	//////////////////////////////////////////////////////////////////////////

	memset(&fdInfo, 0, sizeof(finddata));
	lHandle = findfirst(pszFileSpec, &fdInfo);
	if(lHandle == EINVAL) return "NULL";;
	if(lHandle == ENOENT) return "NULL";;
	if(lHandle == -1) return "NULL";;

	while(1)
	{
		if(fdInfo.attrib & _A_SUBDIR)
		{
			// Don't process directories here
		}
		else
		{
			if(m_bFullPath)
			{
				fullpath(szFull, fdInfo.name, RH_MAX_PATH);
				result = HashFile(szFull);
			}
			else
			{
				result = HashFile(fdInfo.name);
			}
			printf(CPS_NEWLINE);
		}

		if(findnext(lHandle, &fdInfo) != 0) break;
	}

	findclose(lHandle);
	lHandle = 0;

	return result;
}

std::string CHashManager::HashFile(char *pszFile)
{
	FILE *fp = NULL;
	 std::string my_sha;
	unsigned char pBuf[SIZE_HASH_BUFFER];
	unsigned long uRead = 0;
	unsigned char pTemp[256];
	char szTemp[RH_MAX_BUFFER];
	int i = 0;

	printf("File: <");
	printf(pszFile);
	printf(">");
	printf(CPS_NEWLINE);

	fp = fopen(pszFile, "rb");
	if(fp == NULL) return "NULL";

	
	if(m_bAlgorithm[HASHID_SHA2_512]) sha512_begin(&m_sha512);
	
	while(1)
	{
		uRead = fread(pBuf, 1, SIZE_HASH_BUFFER, fp);

		if(uRead != 0)
		{
			if(m_bAlgorithm[HASHID_SHA2_512])
				sha512_hash(pBuf, uRead, &m_sha512);
		}

		if(uRead != SIZE_HASH_BUFFER) break;
	}

	fclose(fp); fp = NULL;

	// SizeHash-32 is the first hash, because it's the simplest one,
	// the fastest, and most widely used one. ;-)

	if(m_bAlgorithm[HASHID_SHA2_512])
	{
		sha512_end(pTemp, &m_sha512);
		printf(SZ_SHA2_512);
		printf(SZ_HASHPRE);

		 char buffer [50];
		
		for(i = 0; i < 64; i++)
		{
			
			//printf("%02X", pTemp[i]);
			sprintf(buffer, "%02X", pTemp[i]);
			my_sha.append(buffer);
		}
		//printf(CPS_NEWLINE);
		//printf(my_sha.c_str());
		//printf(CPS_NEWLINE);
	}
	return my_sha;
}

