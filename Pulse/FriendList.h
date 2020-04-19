#ifndef __FRIENDLIST_H
#define __FRIENDLIST_H

namespace Mods
{
	namespace FriendList
	{
		void __fastcall SendList(void *pSocket, void *_edx, char* pPacket);
		void __cdecl SendAdd(void *vPlayer, unsigned char pType, char* pFormat, char fType, long id, char* name, char type);
	}
}

#endif