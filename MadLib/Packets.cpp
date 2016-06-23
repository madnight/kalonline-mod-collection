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


