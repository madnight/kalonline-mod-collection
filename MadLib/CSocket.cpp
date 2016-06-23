#include "CSocket.h"

char* CSocket::GetIP()
{
	return inet_ntoa(((struct in_addr*)_this)[35]); //140
}

int CSocket::GetID()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+280]
}

int CSocket::GetPort()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+136]  //136/4 =34
}

char* CSocket::GetData()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+92]  
}

void CSocket::EnterCriticalSection()
{
//	void *soc_crit_sec;
	__asm mov ecx, [ecx]
	__asm add ecx, 20
	__asm mov edx, 0x00423640
	__asm call edx
//	__asm mov soc_crit_sec, ecx
//	Server::CIOCriticalSection::Enter(soc_crit_sec);
}

void CSocket::LeaveCriticalSection()
{
	__asm mov ecx, [ecx]
	__asm add ecx, 20
	__asm mov edx, 0x004236D0
	__asm call edx
}

unsigned int CSocket::GetPlayer()
{
	return _this[30];
}

int CSocket::GetUID()
{
	return _this[38]; //152
}

int CSocket::GetCheckSum()
{
	return _this[32];

}

void CSocket::SetCheckSum(int check)
{
	_this[32] = check;
}


int CSocket::GetOffsetCode()
{
	if ( _this[33] )
	return *(int*)_this[33];
	else
	return 0;
}

void CSocket::SetExTPointer(void* offset)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+132], ecx
}

void* CSocket::GetExTPointer()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+132]
}

bool CSocket::IsValid()
{
	return _this != 0;
}

void CSocket::Close()
{
	__asm mov ebx, this
	__asm mov ecx, [ebx]CSocket.thispointer
	__asm mov eax, 0x00424260
	__asm jmp eax
}

void CSocket::Kill()
{
	Server::CSocket::Write(this->thispointer,45,"b",1);
	Server::CSocket::Logout(this->thispointer,6);
	Server::CIOSocket::GracefulClose(this->thispointer);
}
