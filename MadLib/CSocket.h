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

