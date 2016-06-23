#ifndef __CSKILLVTBL_H
#define __CSKILLVTBL_H

#include <Windows.h>
#include "../Server.h"

#define _this ((int*) this->thispointer)

class CSkillVtbl
{
private:
	void* thispointer;
public:
	CSkillVtbl(void *CSkillVtbl) { this->thispointer = CSkillVtbl; }

	int GetCopy();
	int GetCanExecuteFunkPtr();
	int GetExecuteFunkPtr();
	int GetExecutePassiveFunkPtr();
};

#endif