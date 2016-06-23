#include "Inventory.h"


int Inventory::GetItemCount()
{
	return Server::CPlayer::GetInvenSize(Inv_Player_Pointer);
//	__asm mov eax, 0x00456720
	//__asm mov edi, this
//	__asm mov ecx, [edi]Inventory.thspointer
	//__asm jmp eax
}


bool Inventory::RemoveItem(int index, int amount)
{
  return Server::CPlayer::RemoveItem(Inv_Player_Pointer, 9, index, amount) ? true : false;
}

Item Inventory::GetItem(int index)
{
	return new Item(Server::CPlayer::FindItem(Inv_Player_Pointer,index,1));
}