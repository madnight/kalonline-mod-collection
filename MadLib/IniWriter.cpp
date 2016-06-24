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
 
#include "IniWriter.h"
#include <iostream>
#include <Windows.h> 
CIniWriter::CIniWriter(char* szFileName)
{
 memset(m_szFileName, 0x00, 255);
 memcpy(m_szFileName, szFileName, strlen(szFileName));
}
void CIniWriter::WriteInteger(char* szSection, char* szKey, int iValue)
{
 char szValue[255];
 sprintf(szValue, "%d", iValue);
 WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName); 
}
void CIniWriter::WriteFloat(char* szSection, char* szKey, float fltValue)
{
 char szValue[255];
 sprintf(szValue, "%f", fltValue);
 WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName); 
}
void CIniWriter::WriteBoolean(char* szSection, char* szKey, bool bolValue)
{
 char szValue[255];
 sprintf(szValue, "%s", bolValue ? "True" : "False");
 WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName); 
}
void CIniWriter::WriteString(char* szSection, char* szKey, char* szValue)
{
 WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName);
}