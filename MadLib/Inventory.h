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
 
#ifndef __INVENTORY_H
#define __INVENTORY_H


#include "Item.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")

#define _this ((int*) this->thispointer)
#define Inv_Player_Pointer (int*)this->thispointer - 255

class Inventory
{
private: 
	void* thispointer;

public:
	Inventory(void *socketptr) { this->thispointer = socketptr; }

	bool RemoveItem(int index, int amount);
	Item GetItem(int index);
	int GetItemCount();
};



#endif