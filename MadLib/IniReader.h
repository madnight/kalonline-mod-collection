#ifndef INIREADER_H
#define INIREADER_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <string>

class CIniReader
{
public:
	CIniReader(char* szFileName);   
	__int64 GetFileSize();
	int ReadInteger(char* szSection, char* szKey, int iDefaultValue);
	float ReadFloat(char* szSection, char* szKey, float fltDefaultValue);
	bool ReadBoolean(char* szSection, char* szKey, bool bolDefaultValue);
	char* ReadString(char* szSection, char* szKey, const char* szDefaultValue);
	std::vector<std::string> ReadStringSection(char* szSection);
private:
	char m_szFileName[255];
};
#endif//INIREADER_H