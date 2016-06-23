#include "CPlayer.h"
#include "../Server.h"


void CPlayer::CIOCriticalSectionEnter(void)
{
	Server::CIOCriticalSection::Enter((void*)((DWORD)this->offset+1020));
}

void CPlayer::CIOCriticalSectionLeave(void)
{
	Server::CIOCriticalSection::Leave((void*)((DWORD)this->offset+1020));
}

int CPlayer::GetPID(void)
{
	return this->offset[113];
}

bool CPlayer::CheckOnline(void)
{
	Server::CIOCriticalSection::Enter((void*)0x4e2078);
	Server::CIOCriticalSection::Enter((void*)0x4e2098);
	Server::CLink::MoveTo((void*)0x4e200c,(int)0x4e2004);
	Server::CIOCriticalSection::Leave((void*)0x4e2098);
	void* Playerp = 0;
	for ( DWORD i = *(DWORD*)0x4e2004; i != 0x4e2004; i = *(DWORD*)i)
	{
		Playerp = (void*)(i-428);
		if(Playerp == this->offset)
		{
			Server::CIOCriticalSection::Leave((void*)0x4e2078);
			return true;
		}
	}
	Server::CIOCriticalSection::Leave((void*)0x4e2078);
	return false;
}

int CPlayer::GetAdmin(void)
{
	return *(DWORD*)((DWORD)this->offset+0x1C8);
}

int CPlayer::GetRange(void)
{
	return *(DWORD*)((DWORD)this->offset+580);
}

void CPlayer::InsetItem(int a2, int item)
{
	Server::CPlayer::InsertItem(this->offset,a2,item);
}

int CPlayer::getLevel()
{
	return (int)this->offset + 60;
	

}

int CPlayer::GetUID(void)
{
	int PlayerUID = 0;
	int *pp = this->offset;
	__asm
	{
		push eax
			push edx
			mov eax,pp
			add eax,28
			mov edx, DWORD PTR SS:[eax]
			mov PlayerUID,edx
			pop edx
			pop eax
	}
	return PlayerUID;
}
