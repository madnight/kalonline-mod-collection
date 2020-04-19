#ifndef __INVENTORY_H
#define __INVENTORY_H

namespace Mods
{
namespace Inventory
{
void __fastcall SendItemInfo(void *player, void *_edx, char* Inventory);
void __fastcall ItemPutInfo(void *_this, void *_edx, char **spec, int a3);
void __fastcall SendUpdateItemInfo(void *player, void *_edx, char* Item);
}
}

#endif
