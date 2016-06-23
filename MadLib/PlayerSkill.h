#ifndef __PLAYERSKILL_H
#define __PLAYERSKILL_H

#include <Windows.h>

#include "../Server.h"

#define _this ((int*) this->thispointer)

class PlayerSkill
{
private: 
	void* thispointer;

public:
	PlayerSkill(void *PlayerSkillptr) { this->thispointer = PlayerSkillptr; }

	void* GetPlayer();
	void* GetSkill(int SkillID);
	int GetClass();
	int SkillID();	  
	void* SetSkill( int SkillID, void *Skill );
};


#endif

