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