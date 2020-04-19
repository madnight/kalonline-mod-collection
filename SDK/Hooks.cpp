#include "StdAfx.h"
#include "Hooks.h"

#include "Interface.h"

#include "Deflector.h"
#include "Deflection.h"
#include "Server.h"

void __fastcall Hooks::CSocket::Process(void *Socket, void *_edx, const char* Data)
{
	Interface<IDeflector> Deflector;
	if (!Deflector->Forward(Deflection::CSocketProcess, Socket, Data))
		Server::CSocket::Process(Socket, Data);
}
void __cdecl Hooks::CPlayer::Write(void *Player, unsigned char Type, const char* Format, ...)
{
	// This is really the dirty way, it would be better to just rewrite the original function.
	Interface<IDeflector> Deflector;

	va_list Args;
	va_start(Args, Format);

	unsigned char _Type = Type;

	if (!Deflector->Forward(Deflection::CPlayerWrite, Player, Type, Format, Args))
	{
		unsigned long EbpOffset = 16, StackShift = 12;

		for(size_t i=0; i < strlen(Format); i++)
		{
			if (Format[i] == 'I')
			{
				EbpOffset += 4;
				StackShift += 4;
			}
			EbpOffset += 4;
			StackShift += 4;
		}

		for(; EbpOffset > 16; EbpOffset-=4)
		{
			__asm mov eax, EbpOffset
			__asm push [ebp+eax]
		}
		
		__asm push Format
		__asm mov al, _Type
		__asm push eax
		__asm push Player
		__asm call Server::CPlayer::Write
		__asm add esp, StackShift
	}
	va_end(Args);
}

void __fastcall Hooks::CMonster::Blob(void *Monster, void *_edx, unsigned char)
{
	Interface<IDeflector> Deflector;

	unsigned long _Ebp;
	__asm mov eax, [ebp]
	__asm mov _Ebp, eax

	__asm
	{
		push 0
		mov eax, _Ebp
		mov ecx, [eax-0x44]
		mov edx, [ecx]
		call [edx+0xbc]
	}

	Deflector->Forward(Deflection::MonsterBlob, Monster);
}
