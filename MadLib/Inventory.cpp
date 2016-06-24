/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
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