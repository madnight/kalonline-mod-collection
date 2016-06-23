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
