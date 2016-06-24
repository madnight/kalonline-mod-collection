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
 
#include "CSkillVtbl.h"

int CSkillVtbl::GetCanExecuteFunkPtr()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+4]
}

int CSkillVtbl::GetExecuteFunkPtr()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+8]
}

int CSkillVtbl::GetExecutePassiveFunkPtr()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+12]
}

int CSkillVtbl::GetCopy()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax]
}
