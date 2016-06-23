

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

#include "rehash.h"
#include "clutil.h"
#include "hashmgr.h"



std::string mainx(int argc, char *argv[])
{
	int i = 0;
	bool bOnce = true;
	char szPath[RH_MAX_PATH];
	char szAbsPath[RH_MAX_PATH];
	char szOrgPath[RH_MAX_PATH];
	char szTemp[RH_MAX_BUFFER];
	std::string iErrorCode = "NULL";
	CHashManager hashmgr;

	getcwd(szOrgPath, RH_MAX_PATH);

	// No arguments?
	if(argc == 1)
	{
		return "NULL";
	}

	memset(szPath, 0, RH_MAX_PATH);
	bOnce = true;
	hashmgr.SelectAllAlgorithms(false);
	hashmgr.SelectAlgorithm(17, true);

	for(i = 1; i < argc; i++)
	{
		// Is the argument a path descriptor?
		if(isArgument(argv[i]) == false)
		{
			if(bOnce == false) strcat(szPath, " ");
			strcat(szPath, argv[i]);
			bOnce = false; // Next time add a space
			continue;
		}

		// The argument is an optional argument

		if(strlen(argv[i]) >= RH_MAX_BUFFER) continue; // Non-parsable option argument, ignore

		fmtArgument(argv[i], szTemp); // Format the argument, i.e. remove all special chars

	}

	// Check if a path is in the arguments
	bOnce = false;
	for(i = 1; i < argc; i++) if(isArgument(argv[i]) == 0) bOnce = true;
	if(bOnce == false) return "NULL"; // Silently exit

	fmtPath(szPath);

	strcpy(szAbsPath, szPath);
	pathonly(szAbsPath);
	if(strlen(szAbsPath) != 0)
	{
		if(chdir(szAbsPath) != 0)
		{
			printf("ERROR! Cannot change to directory: ");
			printf(szAbsPath);
			printf(CPS_NEWLINE);
			return "NULL";
		}
	}

	fileonly(szPath);
	iErrorCode = hashmgr.HashPath(szAbsPath, szPath);

	if(chdir(szOrgPath) != 0) return "NULL";
	return iErrorCode;
}

std::string SHA_512(char *argv)
{
	char *test[2];
	test[1] = argv;
	std::string result = mainx(2,test);
//	if (result == "8181F508820D3A967A558E4A7BE8E5065C60211D1CC2002BAA4F9709DE0BAC1AB5D7A3027ACA85AA549E30B68CF62C672DDA8FA26299562F3FD968CFA3301C42A")
	//	printf("true!");
	//printf(result.c_str());
	return result;
}
