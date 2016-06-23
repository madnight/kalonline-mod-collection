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


