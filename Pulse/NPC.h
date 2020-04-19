#ifndef __NPC_H
#define __NPC_H

namespace Mods
{
	namespace NPC
	{
		void __cdecl SendCreate(void *pPlayer, BYTE bType, const char* sFormat, int nID, WORD wIndex, BYTE bShape, int nX, int nY, int nZ, WORD wDirection, unsigned long iGState, DWORD nFlagItem);
		void __cdecl SendCreateInSight(void *pNPC, BYTE bType, const char* sFormat, int nID, WORD wIndex, BYTE bShape, int nX, int nY, int nZ, WORD wDirection, unsigned long iGState, DWORD nFlagItem);
		void __fastcall SendAssassinList(void *pSocket, void *_edx, char* pData);
	}
}

#endif