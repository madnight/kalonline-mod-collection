#include "StdAfx.h"
#include "Monster.h"
#include "Server.h"

void __cdecl Mods::Monster::SendCreateInSight(void *monster, unsigned char Type,
        char* format, short index, long id, long x, long y, unsigned short direction,
        long curhp, long maxhp, unsigned long gState, unsigned __int64 mState64,
        char* guildName, char race, long GID, char* userName)
{
    Server::CChar::WriteInSight(monster, 0x33, "wdddwddIIsbdsIIb", index, id, x, y,
            direction, curhp, maxhp, (unsigned __int64)gState, mState64, guildName,
            race, GID, userName, (__int64)0, (__int64)0, 0);

    Server::CChar::WriteInSight(monster, 148, "dI", id, (__int64)0);
}

void __cdecl Mods::Monster::SendCreate(void *player, unsigned char Type, char* format,
        short index, long id, long x, long y, unsigned short direction, long curhp,
        long maxhp, unsigned long gState, unsigned __int64 mState64, char* guildName,
        char race, long GID, char* userName)
{
    Server::CPlayer::Write(player, 0x33, "wdddwddIIsbdsIIb", index, id, x, y, direction,
            curhp, maxhp, (unsigned __int64)gState, mState64, guildName, race, GID,
            userName, (__int64)0, (__int64)0, 0);

    Server::CPlayer::Write(player, 148, "dI", id, (__int64)0);
}

void __cdecl Mods::Monster::WriteExclusive(unsigned char Type, char* format, short index,
        long id, long x, long y, unsigned short direction, long curhp, long maxhp,
        unsigned long gState, unsigned __int64 mState64, char* guildName, char race,
        long GID, char* userName)
{
    Server::CObject::WriteExclusive(0x33, "wdddwddIIsbdsIIb", index, id, x, y, direction,
            curhp, maxhp, (unsigned __int64)gState, mState64, guildName, race, GID, userName,
            (__int64)0, (__int64)0, 0);
}
