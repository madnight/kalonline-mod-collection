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
 
#define INST_NOP  0x90
#define INST_CALL 0xE8
#define INST_JMP  0xE9
#define INST_BYTE 0x00
#define SHORT_JZ  0x74
#define STD_CALL_LEN 0x05
#define INST_JMPR  0xEB
#define INST_RET 0xC3
#define _DWORD DWORD
#define _WORD WORD
#define _BYTE BYTE

#include <windows.h> 

LPVOID MemoryCopy(DWORD destination, DWORD source, int length)
{
	DWORD oldSource      = 0;
	DWORD oldDestination = 0;

	VirtualProtect((LPVOID)source,length,PAGE_EXECUTE_READWRITE,&oldSource);
	VirtualProtect((LPVOID)destination,length,PAGE_EXECUTE_READWRITE,&oldDestination);

	memcpy((void*)destination,(void*)source,length);

	VirtualProtect((LPVOID)destination,length,oldDestination,&oldDestination);
	VirtualProtect((LPVOID)source,length,oldSource,&oldSource);

	return (LPVOID)destination;
};

void MemoryCopy(void *Destination, void *Source, size_t Size)
{
	unsigned long p1, p2;
	VirtualProtect(Destination, Size, PAGE_EXECUTE_READWRITE, &p1);
	VirtualProtect(Source, Size, PAGE_EXECUTE_READWRITE, &p2);
	CopyMemory(Destination, Source, Size);
	VirtualProtect(Destination, Size, p1, &p1);
	VirtualProtect(Source, Size, p1, &p2);
};

void *DetourFunction(BYTE *src, const BYTE *dst, const int len) // credits to gamedeception
{
	BYTE *jmp = (BYTE*)malloc(len+5);
	DWORD dwback;
	VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len); jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src+1) = (DWORD)(dst - src) - 5;
	VirtualProtect(src, len, dwback, &dwback);
	return (jmp-len);
}


DWORD Intercept(int instruction, DWORD source, DWORD destination, int length)
{
	DWORD realTarget;
	LPBYTE buffer = new BYTE[length];

	memset(buffer,0x90,length); 

	if(instruction != INST_NOP && length >= 5)
	{
		buffer[(length-5)] = instruction;
		DWORD dwJMP = (DWORD)destination - (source + 5 + (length-5));
		memcpy(&realTarget,(void*)(source+1),4);
		realTarget = realTarget + source + 5;
		memcpy(buffer + 1 + (length - 5),&dwJMP,4);
	}

	if(instruction == SHORT_JZ)
	{
		buffer[0] = instruction;
		buffer[1] = (BYTE)destination;
	}

	if(instruction == INST_BYTE)
	{
		buffer[0] = (BYTE)destination;
	}

	MemoryCopy(source,(DWORD)buffer,length);
	delete[] buffer;

	return realTarget;
}



