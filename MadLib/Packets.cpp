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
 
#include "Packets.h"

#include "Interface.h"
#include "Tools.h"

CREATE_INTERFACE(IPackets)

static int *g_lpClient = (int*)0x0070F9C8;
static float *m_fWriteTime = (float*)0x0070F9D0;
static float *g_fCurrentTime = (float*)0x007DE000;
static int (__thiscall *SendPacket)(void* _this, const char* Buffer, int Length) = 
	(int (__thiscall*)(void*, const char*, int))0x0052CBF0;
	

int IPackets::Send(unsigned char Type, std::string Format, va_list Args)
{
	int Ret;
	Interface<ITools> Tools;
	Interface<IPipe> Pipe;

	size_t Size = Tools->GenerateSize(Format, Args);
	char* Data = new char[Size+3];
	*(unsigned short*)Data = Size+3;
	*(unsigned char*)(Data+2) = Type;
	Tools->Compile(Data+3, Size, Format, Args);
	//Pipe->Write(true, Format, Data, Size+3);
	Ret = SendPacket((void*)*g_lpClient, Data, Size+3);
	delete [] Data;

	*m_fWriteTime = *g_fCurrentTime;
	return Ret;
}
int IPackets::Send(unsigned char Type, std::string Format, ...)
{
	va_list Args;
	va_start(Args, Format);
	int Ret = this->Send(Type, Format, Args);
	va_end(Args);
	return Ret;
}


