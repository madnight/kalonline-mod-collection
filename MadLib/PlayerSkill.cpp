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
 
#include "PlayerSkill.h"


void* PlayerSkill::GetPlayer()
{
	__asm mov eax, [ecx]
	__asm sub eax, 624
}


int PlayerSkill::GetClass()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+4]
}

int PlayerSkill::SkillID()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+8]

}

void* PlayerSkill::GetSkill( int SkillID )
{
	__asm mov ecx, [ecx]
	__asm mov eax, [ebp+8]
	__asm mov eax, [ecx+eax*4+8]
}


void* PlayerSkill::SetSkill( int SkillID, void *Skill )
{
	__asm mov ecx, [ecx]
	__asm mov eax, [ebp+8]
	__asm mov edx, Skill
	__asm mov [ecx+eax*4+8], edx
}


