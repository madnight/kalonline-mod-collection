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

class Player
{
public:
	void* thispointer;
	Player(void *playerptr) { this->thispointer = playerptr; }

	char* GetName();
	int GetLevel();
	int GetPid();
	int GetAdmin();
	int GetClass();
	int GetSpeed();
	int GetCurHp();
	int GetCurMp();
	int GetStr();
	int GetAgi();
	int GetInt();
	int GetHp();
	int GetXCoord();
	int GetYCoord();
	int GetZCoord();
	int GetMap();
	int GetMaxHp();
	int GetEvasion();
	int GetOtp();
	int GetStatPoints();
	int GetSkillPoints();
	int GetRange();
	int GetMinAtk();
	int GetMaxAtk();
	int GetMaxMagAtk();
	int GetSpeciality();
	int GetContribute();
	int GetGRole();
	int GetKilled();
	int GetRage();
	int GetPartySize();
	int GetGState();
	int GetUid();
	int IsMState();
	long GetRelease();
	int GetMinMagAtk();
	int GetPlayerID();
	void GetDuelTimer();
	int GetDuelID();
	void* GetDuelOpponent();

	unsigned int GetExp();

	void SetName(const char *name);
	void SetLevel(int level);
	void SetPid(int pid);
	void SetAdmin(int admin);
	void SetClass(int pclass);
	void SetSpeed(int speed);
	void SetCurHp(int curhp);
	void SetCurMp(int curmp);
	void SetStr(int str);
	void SetAgi(int agi);
	void SetInt(int intel);
	void SetHp(int hp);
	void SetXCoord(int x);
	void SetYCoord(int y);
	void SetZCoord(int z);
	void SetMap(int map);
	void SetMaxHp(int hp);
	void SetEvasion(int eva);
	void SetOtp(int otp);
	void SetStatPoints(int statp);
	void SetSkillPoints(int skillp);
	void SetRange(int range);
	void SetMinAtk(int minatk);
	void SetMaxAtk(int maxatk);
	void SetSpeciality(int sepc);
	void SetContribute(int contr);
	void SetGRole(int grole);
	void SetKilled(int killed);
	void SetRage(int rage);
	void SetPartySize(int psize);
	void SetGState(int gstate);
	void SetExp(unsigned __int64 exp);
	void SetRelease(int re);
	void SetMinMagAtk(int minatk);
	void SetDuel(int TargetPlayerID);
	void SetDuelTimer(int timer);

	void CIOCriticalSectionEnter(void);
	void CIOCriticalSectionLeave(void);

	bool CheckOnline(void);
	bool isGM();
	bool isAdmin();

	void Teleport(int map, int x, int y);
	void InsertItem(int index, int amount);
	void Kick();
	void Hide(bool hide);
	void Notice(char* notice);
	void SystemMessage(char *message);
	void UpdateProperty(int a2, int a3, int a4, int a5);

	Inventory GetInventory();
	void* GetSocket();

	char* GetRebornName();
	char* GetIP();

	void Reborn();
	void SaveAllProperty();
	

};




