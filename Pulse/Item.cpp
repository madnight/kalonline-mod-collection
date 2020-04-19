#include "StdAfx.h"
#include "Item.h"
#include "Server.h"

void __cdecl Mods::Item::ItemDrop(void *player, unsigned char Type, char* format,
        WORD index, long iid, long x, long y, long amount)
{
    Server::CPlayer::Write(player,0x36,"wddddd",index,iid,x,y,0xffffffff,amount);
}

DWORD __cdecl Mods::Item::PrepItemDrop(unsigned char Type, char* format, WORD index,
        long iid, long x, long y, long amount)
{
    return Server::CObject::WriteExclusive(0x36,"wddddd",index,iid,x,y,0xffffffff,amount);
}
