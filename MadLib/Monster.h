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
 
#include "CSocket.h"
#include "Inventory.h"
#include "Command.h"
#include <string>
#include <sstream>
#include "Memory.h"
#include "Tools.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")

#define _this ((int*) this->thispointer)

#define MAD_CONST(x) (const_cast<char*>(x.str().c_str()))

class Monster
{
public:
	void* thispointer;
	Monster(void *monsterptr) { this->thispointer = monsterptr; }
	int GetIndex();
	int GetDamage();
	int GetTime();
	int GetX1();
	int GetY1();
	int GetX2();
	int GetY2();
	int GetID();
	int GetAI();

	int Get164();
	int Get120();
	int Get128();
	int Get119();

	void* GetState();

	void SetTime(int i);
	void SetDamage(int i);
	void SetIndex(int i);
	void SetGstate(int i);
	LONG GetRelease();
	void Die();
	int GetXCoord();
	int GetYCoord();
};




