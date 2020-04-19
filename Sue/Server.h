#ifndef __SERVER_H
#define __SERVER_H

namespace Server
{
	namespace CSocket
	{
		static void (__thiscall *Login)(void *Socket, int nId, int UID) = (void (__thiscall*)(void*, int, int))0x004168c0;
	}

	struct _CDB
	{
		int Data[4];
	};

	namespace CDB
	{
		static void (__thiscall *CDB)(void *DB) = (void (__thiscall*)(void*))0x004026c0;
		static void (__thiscall *_CDB)(void *DB) = (void (__thiscall*)(void*))0x004026f0;

		static int (__cdecl *Prepare)(const char* Statement, ...) = (int (__cdecl*)(const char*, ...))0x0040dce0;
		static int (__cdecl *Execute)(void *DB, const char* Statement, ...) = (int (__cdecl*)(void*, const char*, ...))0x00402730;
		static int (__thiscall *Fetch)(void *DB) = (int (__thiscall*)(void*))0x00402ce0;

		static void (__thiscall *Bind_String)(void *DB, char* String, int Length) = (void (__thiscall*)(void*, char*, int))0x0041b260;
		static void (__thiscall *Bind_Dword)(void *DB, unsigned long* Value) = (void (__thiscall*)(void*, unsigned long*))0x0041b1c0;
		static void (__thiscall *Bind_Word)(void *DB, unsigned short* Value) = (void (__thiscall*)(void*, unsigned short*))0x0041b390;
		static void (__thiscall *Bind_Byte)(void *DB, unsigned char* Value) = (void (__thiscall*)(void*, unsigned char*))0x0041b170;
	}

	namespace CIOBuffer
	{
		static void * (__cdecl *Alloc)() = (void * (__cdecl*)())0x0040b500;
	}

	namespace CIOSocket
	{
		static void (__thiscall *Write)(void *Socket, char *Buffer) = (void (__thiscall*)(void*, char*))0x0040bd10;
	}

	static char * (__cdecl *WritePacket)(char *Packet, const char* Type, ...) = (char * (__cdecl*)(char*, const char*, ...))0x0041c830;
	static char * (__stdcall *PutString)(char *Packet, const char* String) = (char * (__stdcall*)(char*, const char*))0x0041d0b0;
	static char * (__cdecl *PutDword)(char *Packet, unsigned long Value) = (char * (__cdecl*)(char*, unsigned long))0x0041bc40;
	static char * (__cdecl *PutWord)(char *Packet, unsigned short Value) = (char * (__cdecl*)(char*, unsigned short))0x0041bc00;
	static char * (__cdecl *PutByte)(char *Packet, unsigned char Value) = (char * (__cdecl*)(char*, unsigned char))0x0041bbe0;
}

#endif