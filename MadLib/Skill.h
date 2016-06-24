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
 
#ifndef __SKILL_H
#define __SKILL_H

#include <Windows.h>
#include "../Server.h"

#define _this ((int*) this->thispointer)

class Skill
{
public:
	Skill(void *Skillptr) { this->thispointer = Skillptr; }

	void* thispointer;
	void* GetPlayer();
	void* GetCSkillVtbl();
	int GetID();
	int GetLevel();
	int GetLimitLevel();
	unsigned int  GetLimitSpecialty();
	int GetDecreaseMP();
	unsigned int  GetDelay();
	int GetLastTime();
	int GetV1();
	int GetV2();
	unsigned int  GetTick();
};

#endif

