#ifndef __MONSTER_H
#define __MONSTER_H

namespace Mods
{
namespace Monster
{
void __cdecl SendCreateInSight(void *monster, unsigned char Type, char* format, short index,
                               long id, long x, long y, unsigned short direction, long curhp,
                               long maxhp, unsigned long gState, unsigned __int64 mState64,
                               char* guildName, char race, long GID, char* userName);

void __cdecl SendCreate(void *player, unsigned char Type, char* format, short index, long id,
                        long x, long y, unsigned short direction, long curhp, long maxhp,
                        unsigned long gState, unsigned __int64 mState64, char* guildName, char race,
                        long GID, char* userName);

void __cdecl WriteExclusive(unsigned char Type, char* format, short index, long id, long x, long y,
                            unsigned short direction, long curhp, long maxhp, unsigned long gState,
                            unsigned __int64 mState64, char* guildName, char race, long GID, char* userName);
}
}

#endif
