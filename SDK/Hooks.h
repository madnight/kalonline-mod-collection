#ifndef __HOOKS_H
#define __HOOKS_H

namespace Hooks
{
	namespace CSocket
	{
		void __fastcall Process(void *Socket, void *_edx, const char *Data);
	}
	namespace CPlayer
	{
		void __cdecl Write(void *Player, unsigned char Type, const char* Format, ...);
	}
	namespace CMonster
	{
		void __fastcall Blob(void *Monster, void *_edx, unsigned char);
	}
}

#endif