#include "StdAfx.h"
#include "Player.h"
#include <time.h>
#include "Interface.h"
#include "Server.h"
#include "Tools.h"

void __cdecl Mods::Player::SendCreate(void *player, unsigned char Type, char* format,
        long id, char* name, unsigned char _class, long x, long y, long z, unsigned short direction,
        unsigned long gState, unsigned char* Items, int ItemsLen, char face, char hair,
        unsigned __int64 mState64, char* GuildTitle, char* GuildName, long GuildID,
        char flag, long flagIndex)
{
    Server::CPlayer::Write(player, 0x32, "dsbdddwImbbIssdbdddII", id, name, _class,
            x, y, z, direction, (unsigned __int64)gState, Items, 16, face, hair, mState64,
            GuildTitle, GuildName, GuildID, flag, flagIndex, 0, 0, (__int64)0, (__int64)0);
}

void __cdecl Mods::Player::SendExclusiveCreate(unsigned char Type, void *player, long id,
        char* name, unsigned char _class, long x, long y, long z, unsigned short direction,
        unsigned long gState, unsigned char* Items, int ItemsLen, char face, char hair,
        unsigned __int64 mState64, char* GuildTitle, char* GuildName, long GuildID,
        char flag, long flagIndex)
{
    Server::CObject::WriteExclusive(0x32, "dsbdddwImbbIssdbdddII", id, name, _class,
            x, y, z, direction, (unsigned __int64)gState, Items, 16, face, hair,
            mState64, GuildTitle, GuildName, GuildID, flag, flagIndex, 0, 0, (__int64)0, (__int64)0);
}

void __cdecl Mods::Player::SendMState(void *player, unsigned char Type, char* format, unsigned long mState)
{
    Server::CPlayer::Write(player, Type, "I", (unsigned __int64)mState);
}

void __cdecl Mods::Player::SendGState(void *player, unsigned char Type, char* format,
        long id, unsigned long gState)
{
    Server::CPlayer::Write(player, Type, "dI", id, (unsigned __int64)gState);
}

void __cdecl Mods::Player::SendGStateInSight(void *player, unsigned char Type, char* format,
        long id, unsigned long gState)
{
    Server::CChar::WriteInSight(player, Type, "dI", id, (unsigned __int64)gState);
}

Mods::Player::BASE_STATS Mods::Player::g_BaseStats[] =
{
    18, 16, 8, 8, 10, 180, 120,		// knight
    8, 10, 18, 16, 8, 170, 140,		// mage
    14, 10, 8, 10, 18, 160, 160,	// archer
    14, 10, 8, 10, 18, 160, 160,	// thieft
    8, 10, 20, 14, 8, 170, 140,		// shaman
};

unsigned int Mods::Player::g_FinalResistDivider[] =
{
    4, 1, 2, 2, 1,
};
