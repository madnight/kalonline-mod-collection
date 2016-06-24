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
 
#ifndef _CUSTOMSKILL_H_
#define _CUSTOMSKILL_H_

#include <Windows.h>
#include "../Server.h"
#include "CustomVtbl.h"

#define RUN 0
#define BEHEAD 1

class CustomSkill
{
public:
	CustomSkill(int skillid) 
	{
		switch (skillid)
		{
		case RUN:
			this->vtbl = new CustomVtbl(0x004488D0,0x00481210,0x004021B0,0x004021B0); // I dunno what the last one is but maybe it is not accessed during
		 // the Run function, im also not sure if its the correct order well lets find out yas
			this->m_nLevel = 1;  
			this->m_nLmtLevel = 0;
			this->m_dwLmtSpecialty = 1;
			this->m_nDecMP = 0;
			this->m_nLastTime = 1;
			this->m_dwDelay = 0;
			this->m_nV1 = 0;
			this->m_nV2 = 6;
			this->m_dwTick = 0;
			break;
		case BEHEAD:
			this->vtbl = new CustomVtbl(0x00481330,0x004813A0,0x004488D0,0x004021B0); 
			this->m_nLevel = 1;   
			this->m_nLmtLevel = 0;
			this->m_dwLmtSpecialty = 1;
			this->m_nDecMP = 0;
			this->m_nLastTime = 1;
			this->m_dwDelay = 0;
			this->m_nV1 = 0;
			this->m_nV2 = 0;
			this->m_dwTick = 0;
		case 17:
			this->vtbl = new CustomVtbl(0x00480E80,0x00481750,0x004488D0,0x004021B0);
			this->m_nLevel = 1;
			this->m_nLmtLevel = 5;
			this->m_dwLmtSpecialty = 1;
			this->m_nDecMP = 0;
			this->m_dwDelay = 0;
			this->m_nLastTime = 10;
			this->m_nV1 = 1;
			this->m_nV2 = 10;
			this->m_dwTick = 0;
			break;
		 default:
			break;
		}
	}

  CustomVtbl *vtbl;
  int m_nSkill;
  int m_nLevel;
  int m_nLmtLevel;
  unsigned int m_dwLmtSpecialty;
  int m_nDecMP;
  unsigned int m_dwDelay;
  int m_nLastTime;
  int m_nV1;
  int m_nV2;
  unsigned int m_dwTick;
};

#endif