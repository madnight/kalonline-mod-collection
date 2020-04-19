#include "StdAfx.h"
#include "Memory.h"

#pragma comment(lib, "Detours.lib")

#include "Interface.h"

#include "Detours/Detours.h"

CREATE_INTERFACE(IMemory)

void IMemory::Copy(void *Destination, void *Source, size_t Size)
{
	unsigned long p1, p2;
	VirtualProtect(Destination, Size, PAGE_EXECUTE_READWRITE, &p1);
	VirtualProtect(Source, Size, PAGE_EXECUTE_READWRITE, &p2);
	CopyMemory(Destination, Source, Size);
	VirtualProtect(Destination, Size, p1, &p1);
	VirtualProtect(Source, Size, p1, &p2);
}
void IMemory::Fill(void *Destination, unsigned char Fill, size_t Size, bool Recoverable)
{
	unsigned char *Data = new unsigned char[Size];
	FillMemory(Data, Size, Fill);
	this->m_Patches[Destination] = new Patch(Destination, Data, Size, Recoverable);
	delete[] Data;
}
void IMemory::Fill(unsigned long Destination, unsigned char Fill, size_t Size, bool Recoverable)
{
	this->Fill((void*)Destination, Fill, Size, Recoverable);
}
void IMemory::Set(void *Destination, const char *Data, size_t Size, bool Recoverable)
{
	this->m_Patches[Destination] = new Patch(Destination, (unsigned char*)const_cast<char*>(Data), Size, Recoverable);
}
void IMemory::Set(unsigned long Destination, const char *Data, size_t Size, bool Recoverable)
{
	this->Set((void*)Destination, Data, Size, Recoverable);
}
void IMemory::Set(void *Destination, unsigned char *Data, size_t Size, bool Recoverable)
{
	this->Set(Destination, (const char*)Data, Size, Recoverable);
}
void IMemory::Set(unsigned long Destination, unsigned char *Data, size_t Size, bool Recoverable)
{
	this->Set((void*)Destination, Data, Size, Recoverable);
}

void IMemory::Hook(void *Address, void *Destination, unsigned char Instruction, size_t Size, bool Recoverable)
{
	unsigned char *Data = new unsigned char[Size];
	FillMemory(Data, Size, IMemory::_I_NOP);

	unsigned long Target = (unsigned long)Destination - (unsigned long)Address -5;

	Data[0] = Instruction;
	CopyMemory(Data+1, &Target, 4);

	this->m_Patches[Address] = new Patch(Address, Data, Size, Recoverable);

	delete[] Data;
}

void IMemory::Hook(unsigned long Address, void *Destination, unsigned char Instruction, size_t Size, bool Recoverable)
{
	this->Hook((void*)Address, Destination, Instruction, Size, Recoverable);
}

void IMemory::Hook(unsigned long Address[], size_t Count, void *Destination, unsigned char Instruction, size_t Size, bool Recoverable)
{
	for(size_t i=0; i < Count; i++)
		this->Hook((void*)Address[i], Destination, Instruction, Size, Recoverable);
}
void IMemory::Hook(void *Address, unsigned long Destination, unsigned char Instruction, size_t Size, bool Recoverable)
{
	this->Hook(Address, (void*)Destination, Instruction, Size, Recoverable);
}
void IMemory::Hook(unsigned long Address, unsigned long Destination, unsigned char Instruction, size_t Size, bool Recoverable)
{
	this->Hook((void*)Address, (void*)Destination, Instruction, Size, Recoverable);
}
void IMemory::Hook(unsigned long Address[], size_t Count, unsigned long Destination, unsigned char Instruction, size_t Size, bool Recoverable)
{
	for(size_t i=0; i < Count; i++)
		this->Hook((void*)Address[i], (void*)Destination, Instruction, Size, Recoverable);
}

void IMemory::Restore(void *Address)
{
	if (this->m_Patches.count(Address))
	{
		delete this->m_Patches[Address];
		this->m_Patches.erase(Address);
	}
}
void IMemory::Restore(unsigned long Address)
{
	this->Restore((void*)Address);
}
void IMemory::Restore(unsigned long Address[], size_t Count)
{
	for(size_t i=0; i < Count; i++)
		this->Restore((void*)Address);
}
void IMemory::Restore(unsigned long Address, void *Destination)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach((void**)&Address, (void*)Destination);
	DetourTransactionCommit();
}

void IMemory::HookAPI(void *Address, void *Destination)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach((void**)&Address, (void*)Destination);
	DetourTransactionCommit();
}
void IMemory::HookAPI(unsigned long Address, unsigned long Destination)
{
	this->HookAPI((void*)Address, (void*)Destination);
}
void IMemory::HookAPI(void *Address, unsigned long Destination)
{
	this->HookAPI(Address, (void*)Destination);
}
void IMemory::HookAPI(unsigned long Address, void *Destination)
{
	this->HookAPI((void*)Address, Destination);
}


Patch::Patch(void *Address, unsigned char *Data, size_t Size, bool Recoverable)
{
	Interface<IMemory> Memory;
	
	if (Recoverable)
	{
		this->m_Original = new unsigned char[Size];
		Memory->Copy(this->m_Original, Address, Size);
	}
	this->m_Address = Address;
	this->m_Size = Size;
	this->m_Recoverable = Recoverable;

	Memory->Copy(Address, Data, Size);
}
Patch::~Patch()
{
	Interface<IMemory> Memory;
	if (this->m_Recoverable)
	{
		Memory->Copy(this->m_Address, this->m_Original, this->m_Size);
		delete this->m_Original;
	}
}
