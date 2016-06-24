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
 
#include <list>
#include "../Server.h"

using namespace Server::CChar;
using namespace std;

struct Player 
{ 
	void *thisptr;
	string playername;
	int level;
	int pid;
	int uid;
	int admin;
	int cclass;
	int guild;
	int guild_lvl;
	int range;
	__int64 exp;
	int statp;
	int max_hp;
	int max_mp;
	int hp;
	int str;
	int dex;
	int inte;
	int wis;
	int hit;
	int dodge;
	int def;
	int aspeed;
	int absorb;
	int atk;
	int magic;
	int max_atk;
	int min_atk;
	int x_coord;
	int y_coord;
	int z_coord;
	int duel_id;
	int duel_timer;
	int trade_id;
	char* ip;
	void insertItem(int index, int amount);
	void kick();
	void hide(bool);
	void teleport(int map, int x, int y);
};


struct Player init(void *thispointer)
{
	struct Player player;

	player.thisptr = thispointer;
	player.playername = string(((char*) thispointer)+32);
	player.level =  ((int*) thispointer)[15];// (((char*) thispointer)+60)[0]; // 15 * 4
	player.pid = ((int*) thispointer)[113];
	player.uid = ((int*) thispointer)[112];
	player.admin = ((int*) thispointer)[114];
	player.statp  = ((int*) thispointer)[115];
	player.range = ((int*) thispointer)[145];
	player.exp = ((__int64*)thispointer)[118]; //472
	player.guild = ((int*) thispointer)[121];
	player.guild_lvl = ((int*) thispointer)[122];
	player.x_coord = ((int*) thispointer)[83];
	player.y_coord = ((int*) thispointer)[84];
	player.z_coord = ((int*) thispointer)[85];
	player.max_hp = Server::CChar::GetMaxHp(thispointer); //21
	player.max_mp = Server::CChar::GetMaxMp(thispointer);
	player.hp = Server::CChar::GetHth(thispointer); //17
	player.str = Server::CChar::GetStr(thispointer); //16
	player.dex = Server::CChar::GetDex(thispointer); //agi 20
	player.inte =  Server::CChar::GetInt(thispointer); //18
	player.wis  = Server::CChar::GetWis(thispointer); //19
	player.hit = Server::CChar::GetHit(thispointer);
	player.dodge = Server::CChar::GetDodge(thispointer); 
	player.def = Server::CChar::GetDefense(thispointer);
	player.aspeed = Server::CChar::GetASpeed(thispointer); //65
	player.absorb = Server::CChar::GetAbsorb(thispointer);
	player.atk = Server::CChar::GetAttack(thispointer);
	player.magic = Server::CChar::GetMagic(thispointer);
	player.max_atk = Server::CChar::GetMaxAttack(thispointer);
	player.min_atk = Server::CChar::GetMinAttack(thispointer);
	player.duel_id = ((int*) thispointer)[378];
	player.duel_timer = ((int*) thispointer)[380];
	player.trade_id = ((int*) thispointer)[275];
	player.ip = inet_ntoa(((struct in_addr*)(((int *) thispointer)[419]))[35]);

	return player;
}

void Player::insertItem(int index, int amount)
{
	Server::CItem::InsertItem((int)thisptr,21,index,0,amount,-1);
}

void Player::kick()
{
	Server::CPlayer::Write(thisptr,(DWORD)0x2D,(const char*)0x00452E60);
}

void Player::hide(bool hide)
{
	if (hide)
	{
		Server::CPlayer::CPlayer__AddMState((int)this->thisptr,524288);
	}
	else
	{	
		Server::Unknown::CChar__SubMState((int)this->thisptr,524288,0);
	}
}
void Player::teleport(int map, int x, int y)
{
	Server::CPlayer::CPlayer__Teleport((int)this->thisptr,map,x,y,0);
}

std::list<Player> getPlayerList()
{
	std::list<Player> PlayerList;
	Server::CIOCriticalSection::Enter((void*)0x4e2078);
	Server::CIOCriticalSection::Enter((void*)0x4e2098);
	Server::CLink::MoveTo((void*)0x4e200c,(int)0x4e2004);
	Server::CIOCriticalSection::Leave((void*)0x4e2098);
	int* Playerp = 0;
	for ( DWORD i = *(DWORD*)0x4e2004; i != 0x4e2004; i = *(DWORD*)i)
	{
		Playerp = (int*)(i-428); //1712
		PlayerList.push_back(init(Playerp));
	}
	Server::CIOCriticalSection::Leave((void*)0x4e2078);
	return PlayerList;
}

struct Player getPlayerByName(string name)
{
	Player p;
	std::list<Player> players = getPlayerList();
	while (!players.empty())
	{
		p = players.back();
		if (p.playername == name)
			return p;
		players.pop_back();
	}
	return p;
}