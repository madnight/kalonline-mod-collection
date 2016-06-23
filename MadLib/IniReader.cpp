#include "IniReader.h"
#include <iostream>
#include <Windows.h>

CIniReader::CIniReader(char* szFileName)
{
	memset(m_szFileName, 0x00, 255);
	memcpy(m_szFileName, szFileName, strlen(szFileName));
}

static inline LPCSTR NextToken( LPCSTR pArg )
{
	return strchr( pArg, '\0' ) + 1;
}

const wchar_t* char2wchar(const char* indata)
{
	std::string UTF8String;
	static std::wstring UTF16String;
	UTF8String = indata;
	UTF16String.resize(UTF8String.length());
	std::copy(UTF8String.begin(), UTF8String.end(), UTF16String.begin());
	return UTF16String.c_str();
}

__int64 CIniReader::GetFileSize()
{
	__stat64 buf;
	if (_wstat64(char2wchar(this->m_szFileName), &buf) != 0)
		return -1; // error, could use errno to find out more
	return buf.st_size;
} 

int CIniReader::ReadInteger(char* szSection, char* szKey, int iDefaultValue)
{ 
	int iResult = GetPrivateProfileIntA(szSection,  szKey, iDefaultValue, m_szFileName); 
	return iResult;
}
float CIniReader::ReadFloat(char* szSection, char* szKey, float fltDefaultValue)
{
	char szResult[255];
	char szDefault[255];
	float fltResult;
	sprintf(szDefault, "%f",fltDefaultValue);
	GetPrivateProfileStringA(szSection,  szKey, szDefault, szResult, 255, m_szFileName); 
	fltResult = (float) atof(szResult);
	return fltResult;
}
bool CIniReader::ReadBoolean(char* szSection, char* szKey, bool bolDefaultValue)
{
	char szResult[255];
	char szDefault[255];
	bool bolResult;
	sprintf(szDefault, "%s", bolDefaultValue? "True" : "False");
	GetPrivateProfileStringA(szSection, szKey, szDefault, szResult, 255, m_szFileName);  
	bolResult =  (strcmp(szResult, "True") == 0 || strcmp(szResult, "true") == 0) ? true : false;
	return bolResult;
}
char* CIniReader::ReadString(char* szSection, char* szKey, const char* szDefaultValue)
{
	char* szResult = new char[255];
	memset(szResult, 0x00, 255);
	GetPrivateProfileStringA(szSection,  szKey, szDefaultValue, szResult, 255, m_szFileName);    
	return szResult;
}

std::vector<std::string> CIniReader::ReadStringSection(char* szSection)
{
	std::vector<std::string> result;

	char *szResult = new char[100000];
	DWORD dw = GetPrivateProfileSectionA(szSection,szResult,100000,m_szFileName);

	for ( LPCSTR pToken = szResult; pToken && *pToken; pToken = NextToken(pToken) )
		result.push_back(pToken); 

	return result;
}