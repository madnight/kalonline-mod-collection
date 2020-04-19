#ifndef __ITEM_H
#define __ITEM_H

namespace Mods
{
	namespace Item
	{
		void __cdecl ItemDrop(void *player, unsigned char Type, char* format, WORD index, long iid, long x, long y, long amount);
		DWORD __cdecl PrepItemDrop(unsigned char Type, char* format, WORD index, long iid, long x, long y, long amount);

	}
}

#endif