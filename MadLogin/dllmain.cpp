// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#pragma pack(1)

using namespace std;

#define ASM            void __declspec(naked)
#define    EXPORT        __declspec(dllexport) __cdecl
#define    THREAD        DWORD WINAPI
#define Naked __declspec( naked )
#define INST_NOP 0x90
#define INST_CALL 0xe8
#define INST_JMP 0xe9
#define INST_BYTE 0x00
#define SHORT_JZ 0x74
#define MAXWAIT 100000
#define _DWORD DWORD
#define _WORD WORD
#define _BYTE BYTE

LPVOID MemcpyEx(DWORD lpDest, DWORD lpSource, int len)
{
	DWORD oldSourceProt,oldDestProt=0;
	VirtualProtect((LPVOID)lpSource,len,PAGE_EXECUTE_READWRITE,&oldSourceProt);
	VirtualProtect((LPVOID)lpDest,len,PAGE_EXECUTE_READWRITE,&oldDestProt);
	memcpy((void*)lpDest,(void*)lpSource,len);
	VirtualProtect((LPVOID)lpDest,len,oldDestProt,&oldDestProt);
	VirtualProtect((LPVOID)lpSource,len,oldSourceProt,&oldSourceProt);
	return (LPVOID)lpDest;
};

DWORD Intercept(int instruction, DWORD lpSource, DWORD lpDest, int len)
{
	DWORD realtarget;
	LPBYTE buffer = new BYTE[len];

	memset(buffer,0x90,len);

	if (instruction != INST_NOP && len >= 5)
	{
		buffer[(len-5)] = instruction;
		DWORD dwJMP = (DWORD)lpDest - (lpSource + 5 + (len-5));
		memcpy(&realtarget,(void*)(lpSource+1),4);
		realtarget = realtarget+lpSource+5;
		memcpy(buffer + 1 + (len-5),&dwJMP,4);
	}
	if (instruction == SHORT_JZ)
	{
		buffer[0]=instruction;
		buffer[1]=(BYTE)lpDest;
	}
	if (instruction == INST_BYTE)
	{
		buffer[0]=(BYTE)lpDest;
	}
	MemcpyEx(lpSource, (DWORD) buffer, len);
	delete[] buffer;
	return realtarget;
}

DWORD SearchPattern(char* pattern,DWORD start_offset ,DWORD ende)
{
	DWORD offset=start_offset;
	DWORD start=offset; 
	DWORD backoffset=0;
	DWORD size =strlen(pattern)-1;
	DWORD foundoffset=0;

	char * pEnd=pattern;
	while(1)
	{
		char &myposition=*(char*)offset;
		if ((pEnd[1]!='x'))
		{
			char temp=(char)strtoul(pEnd, &pEnd, 0x10);
			if (temp==myposition)
			{
				if (foundoffset==0)
				{
					foundoffset=offset;
				}
			}
			else
			{
				pEnd=pattern;
				if (foundoffset != 0)
					offset=foundoffset;
				foundoffset=0;
			}
		}
		else
		{
			pEnd=&pEnd[2];
		}
		offset++;
		if (((DWORD)pEnd-(DWORD)pattern>=size)||(offset>=ende))
			break;
	}
	return foundoffset;
}
HINSTANCE hLThis = 0;
HINSTANCE hL = 0;
FARPROC p[332] = {0};
void GetLogin(void* pParams);
DWORD sendadr_ = SearchPattern("55 8B EC 83 EC 18 83 3D x x x x 00 74 07 33 C0 E9 x x x x 8A 45 08 A2 x x x 00 83 3D x x x 00 01 75 0C"
	,0x00400000,0x007FFFFF);
DWORD sendadr = sendadr_+ 0x06;

__declspec(naked) int __cdecl Send_To_Server (BYTE type , LPCSTR format , ... )
{
	__asm
	{
		push ebp
			mov ebp, esp
			sub esp, 0x18
			jmp sendadr
	}
}




char Login_ID[255]; 
char Login_PW[255];
char Login_PW_Second[255];

void Send_SecondPW()
{
	Sleep(200);
	Send_To_Server(0x88,"bs",0,Login_PW_Second);
	Sleep(100);
}
void Send_Login()
{
	Send_To_Server(0x02,"ss",Login_ID,Login_PW);
	Sleep(500);
	Send_SecondPW();
}

void CommandHandler()
{
	for (int i = 0;i<10;i++)
	{
		Send_To_Server(0x15,"bbb",226,0,0);
	}
	Beep(500,500);
}

void GetLogin(void* pParams)
{ 

	DWORD destSize;
	destSize=100;
	GetPrivateProfileString(L"Auto_Login",L"ID",L"NULL",(LPWSTR)Login_ID,destSize,L".\\system.ini"); 
	GetPrivateProfileString(L"Auto_Login",L"PW",L"NULL",(LPWSTR)Login_PW,destSize,L".\\system.ini");
	GetPrivateProfileString(L"Auto_Login",L"2PW",L"NULL",(LPWSTR)Login_PW_Second,destSize,L".\\system.ini");
	Sleep(100);
	Send_Login();
}

void Load_Auto_Login(void* start_parameter)
{
	Sleep(10000);
	GetLogin(0);
	Sleep(30000);
	CommandHandler();
}  



BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		_beginthread(Load_Auto_Login,0,NULL);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

