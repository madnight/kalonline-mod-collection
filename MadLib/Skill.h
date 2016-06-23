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

