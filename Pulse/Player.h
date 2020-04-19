#ifndef __PLAYER_H
#define __PLAYER_H

namespace Mods
{
namespace Player
{
/*
void __fastcall GameStart(void *player, void *_edx);
void __fastcall SendCreate(void *_player, void *_edx, void *target, char* buffer);
*/
struct BASE_STATS
{
    int Str, Hlt, Int, Wis, Dex;
    int Hp, Mp;
};
extern BASE_STATS g_BaseStats[5];
extern unsigned int g_FinalResistDivider[5];

void __cdecl SendCreate(void *player, unsigned char Type, char* format, long id, char* name,
        unsigned char _class, long x, long y, long z, unsigned short direction, unsigned long gState,
        unsigned char* Items, int ItemsLen, char face, char hair, unsigned __int64 mState64,
        char* GuildTitle, char* GuildName, long GuildID, char flag, long flagIndex);

void __cdecl SendExclusiveCreate(unsigned char Type, void *player/*Format*/, long id, char* name,
        unsigned char _class, long x, long y, long z, unsigned short direction, unsigned long gState,
        unsigned char* Items, int ItemsLen, char face, char hair, unsigned __int64 mState64,
        char* GuildTitle, char* GuildName, long GuildID, char flag, long flagIndex);

void __cdecl SendMState(void *player, unsigned char Type, char* format, unsigned long mState);

void __cdecl SendGState(void *player, unsigned char Type, char* format, long id, unsigned long gState);

void __cdecl SendGStateInSight(void *player, unsigned char Type, char* format, long id, unsigned long gState);

void __fastcall SendStorageList(void *socket, void *_edx, char* packet);

void __fastcall SendStallList(void *player, void *_edx, char* packet);

void __fastcall SendTradeList(void *player, void *_edx, char* packet);
}
}

#endif
