#include <windows.h>
#include "IQuest.h"

IQuest::IQuest(void *Offset)
{
    this->Offset = Offset;
}

IQuest::~IQuest()
{
}

void *IQuest::GetOffset()
{
    return this->Offset;
}

int IQuest::GetIndex()
{
	if (this->GetOffset())
		return *(DWORD *)((int)this->Offset + 34);
	else
		return 0;
}

int IQuest::GetFlag()
{
	if (this->GetOffset())
		return *(DWORD *)((int)this->Offset + 32);
	else
		return 0;
}