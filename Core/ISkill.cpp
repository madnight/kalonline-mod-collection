#include <windows.h>
#include "Functions.h"
#include "ISkill.h"

ISkill::ISkill(void* Offset)
{
    this->Offset = Offset;
}

ISkill::~ISkill()
{
}

void *ISkill::GetOffset()
{
    return this->Offset;
}

int ISkill::GetIndex()
{
    if (this->GetOffset()) {
        return *(DWORD*)((int)(this->Offset) + 4);
    }
    else {
        return 0;
    }
}

int ISkill::GetGrade()
{
    if (this->GetOffset()) {
        return *(DWORD*)((int)(this->Offset) + 8);
    }
    else {
        return 0;
    }
}

int ISkill::DecreaseMana()
{
    if (this->GetOffset())
        return (*(int (__thiscall **)(void*, DWORD))
                (*(DWORD *)this->Offset + 0x20))(this->Offset, 0);
    else {
        return 0;
    }
}

void* ISkill::GetPlayer()
{
    if (this->GetOffset()) {
        return (void*)*(DWORD*)(int)(this->Offset);
    }
    else {
        return 0;
    }
}
