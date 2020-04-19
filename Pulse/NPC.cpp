#include "StdAfx.h"
#include "NPC.h"
#include "Interface.h"
#include "Server.h"
#include "Tools.h"

void __cdecl Mods::NPC::SendCreate(void *pPlayer, BYTE bType, const char* sFormat,
        int nID, WORD wIndex, BYTE bShape, int nX, int nY, int nZ, WORD wDirection,
        unsigned long iGState, DWORD nFlagItem)
{
    Server::CPlayer::Write(pPlayer, bType, "dwbdddwId", nID, wIndex, bShape, nX, nY,
            nZ, wDirection, (unsigned __int64)iGState, nFlagItem);
}

void __cdecl Mods::NPC::SendCreateInSight(void *pNPC, BYTE bType, const char* sFormat,
        int nID, WORD wIndex, BYTE bShape, int nX, int nY, int nZ, WORD wDirection,
        unsigned long iGState, DWORD nFlagItem)
{
    Server::CChar::WriteInSight(pNPC, bType, "dwbdddwId", nID, wIndex, bShape, nX, nY,
            nZ, wDirection, (unsigned __int64)iGState, nFlagItem);
}

void __fastcall Mods::NPC::SendAssassinList(void *pSocket, void *_edx, char* pData)
{
    struct PKInfo {
        char Guild[16 +1], Killer[20 +1], Dead[20 +1];
    };
    unsigned char nCount = pData[3];
    pData += 4;
    char* nData = new char[nCount * sizeof PKInfo];

    for(unsigned char i=0; i < nCount; i++)
    {
        PKInfo nf;
        ZeroMemory(&nf, sizeof PKInfo);
        CopyMemory(nf.Guild, &pData[i*51], 16);
        CopyMemory(nf.Killer, &pData[i*51 +17], 16);
        CopyMemory(nf.Dead, &pData[i*51 +34], 16);
        CopyMemory(&nData[i*sizeof PKInfo], &nf, sizeof PKInfo);
    }

    Server::CSocket::Write(pSocket, 0x0c, "bm", nCount, nData, nCount * sizeof PKInfo);
    delete[] nData;
}
