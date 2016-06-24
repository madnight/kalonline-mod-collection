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
 
#pragma once

#include "Player.h"
#include <vector>
using namespace std;

#define ENTER_CRIT Server::CIOCriticalSection::Enter((void*)0x004e2078); Server::CIOCriticalSection::Enter((void*)0x004e2098); Server::CLink::MoveTo((void*)0x004e200c,(int)0x004e2004); Server::CIOCriticalSection::Leave((void*)0x004e2098);
#define PLAYER_LIST_ITERATE for ( DWORD pp = *(DWORD*)0x004e2004; pp != 0x004e2004; pp = *(DWORD*)pp)
#define PLAYER_POINTER (int*)(pp-428)
#define LEAVE_CRIT Server::CIOCriticalSection::Leave((void*)0x004e2078);

class MainPlayer
{
private:
public:
	MainPlayer(){}    
	Player* FindPlayerByName(std::string name);
	void Notice(char* notice);
	int PlayerOnline();
};

/**
Memory->Set(0x004605F2,"\xFF\xFF",2) // Set Duel Distance to higher value

Memory->Set(0x004605F2,"\xA0",1) // Set Duel Distance back to normal

Duel End
if ( *(_DWORD *)(Playerp + 1520) >= 600u )

/ surrender
EndPvP(Playerpointer, EnemyPointer, 3, 2, 6);




<<< 0 -> blue, 1-> red , 2->orange
static void (__cdecl *ScreenMsg)(unsigned char Type, const char* Message) = (void (__cdecl*)(unsigned char, const char*))0x004AFF20;
static void (__cdecl *SystemMsg)(const char* Message, int Color, int type) = (void (__cdecl*)(const char*, int, int))0x004AB5F0;


void GetPlayersFromGild(int GID)
Server::CIOCriticalSection::Enter((void*)0x004e2078); 
Server::CIOCriticalSection::Enter((void*)0x004e2098); 
Server::CLink::MoveTo((void*)0x004e200c,(int)0x004e2004); 
Server::CIOCriticalSection::Leave((void*)0x004e2098);
for ( DWORD pp = *(DWORD*)0x004e2004; pp != 0x004e2004; pp = *(DWORD*)pp)
{
  Player *p = new Player((int*)(pp-428))

  if (p->GetGID == GID)
	push p->pid onto vector
 
 }
Server::CIOCriticalSection::Leave((void*)0x004e2078);

  
  //Revive
         Server::CChar::Lock(playerpointer);
        Server::CPlayer::Revival(playerpointer);
        *(int *)(playerpointer + 1448) = GetTickCount();
         Server::CChar::Unlock((void *)playerpointer);

		 Server::CChar::CancelBuffPrty(playerpointer1, 4);
		Server::CChar::CancelBuffPrty(playerpointer2, 4);
		 

**/