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
#include "Monster.h"
#include <process.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")

#define _this ((int*) this->thispointer)

#define MAD_CONST(x) (const_cast<char*>(x.str().c_str()))



struct GenMonster 
{ 
	DWORD unk_0; 
	DWORD unk_4; 
	DWORD unk_8; 
	DWORD unk_12; 
	DWORD unk_16; 
	DWORD unk_20; 
	DWORD unk_24; 
	DWORD unk_28; 
	DWORD Index; //32   *((_DWORD *)v3 + 128) = *(_DWORD *)(a2 + 32);
	DWORD Map;   //36   *((_DWORD *)v3 + 79) = *(_DWORD *)(a2 + 36);
	DWORD ID;  //40  *((_DWORD *)v3 + 111) = *(_DWORD *)(a2 + 40);
	DWORD Max;   //44
	DWORD Cur;   //48
	DWORD unk_52; 
	DWORD X1;    //56    *((_DWORD *)v3 + 112) = *(_DWORD *)(a2 + 56);
	DWORD Y1;    //60  *((_DWORD *)v3 + 113) = *(_DWORD *)(a2 + 60);
	DWORD X2;    //64 *((_DWORD *)v3 + 114) = *(_DWORD *)(a2 + 64);
	DWORD Y2;    //68  *((_DWORD *)v3 + 115) = *(_DWORD *)(a2 + 68)
	DWORD unk_72;  // *(_DWORD *)(a2 + 320);
	DWORD unk_76; // Get Tick Count
	DWORD unk_80; 
	DWORD unk_84; 
	DWORD unk_88; 
	DWORD unk_92; 
	DWORD unk_96; 
	DWORD unk_100; 
	DWORD unk_104; 
	DWORD unk_108; 
	DWORD unk_112; 
	DWORD unk_116; 
	DWORD unk_120; 
	DWORD unk_124; 
	DWORD unk_128; 
	DWORD unk_132; 
	DWORD unk_136; 
	DWORD unk_140; 
	DWORD unk_144; 
};

struct MonsterGenInfo 
{ 
	int Monsterindex;
	int x; 
	int y;
	int map; 
	unsigned int time; 
	int respawn;
};

class Summon
{
public:
	void spawn(int Monsterindex, int x, int y, int map,int amount = 1,int spawntime = 10000);
	void spwan_alt(int Monsterindex, int x, int y, int map, int amount = 1, int time=10, int respawn = 1); 
};



