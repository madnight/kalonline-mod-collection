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
 
#include "Skill.h"


void* Skill::GetPlayer()
{
	__asm mov eax, [ecx]
	__asm sub eax, 624
}

int Skill::GetID()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+4]
}

int Skill::GetLevel()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+8]
}

int Skill::GetLimitLevel()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+12]
}

unsigned int Skill::GetLimitSpecialty()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+16]
}

int Skill::GetDecreaseMP()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+20]
}

unsigned int Skill::GetDelay()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+24]
}

int Skill::GetLastTime()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+28]
}

int Skill::GetV1()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+32]
}

int Skill::GetV2()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+36]
}

unsigned int Skill::GetTick()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+40]
}

void* Skill::GetCSkillVtbl()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax]
}

