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