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
 
#ifndef _CUSTOMVTBL_H_
#define _CUSTOMVTBL_H_

#include <Windows.h>
#include "../Server.h"

class CustomVtbl
{
public:
	CustomVtbl(int address1,int address2, int address3, int address4) 
	{
		this->Copy = address1;
		this->CanExcute = address2;
		this->Excute = address3;
		this->ExcutePassive = address4;
	}
	
	int Copy;
	int CanExcute;
	int Excute;
	int ExcutePassive;

};

#endif