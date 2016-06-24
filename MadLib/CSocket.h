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
 
#ifndef __CSocket_H
#define __CSocket_H

#include <Windows.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")

#include "../Server.h"

#define _this ((int*) this->thispointer)

class CSocket
{
private: 
	void* thispointer;

public:
	CSocket(void *CSocketptr) { this->thispointer = CSocketptr; }

	char* GetIP();
	int GetUID();
	int GetID();
	int GetPort();
	bool IsValid();
	void Close();
	int GetOffsetCode();
	char* GetData();
	unsigned int GetPlayer();
	//void SetOffsetCode(int offset);
	void* GetExTPointer();
	void SetExTPointer(void* offset);
	int GetCheckSum();
	void SetCheckSum(int check);
	void EnterCriticalSection();
	void LeaveCriticalSection();
	void Kill();

};


#endif

