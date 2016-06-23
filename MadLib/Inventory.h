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