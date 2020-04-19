#include "StdAfx.h"
#include "Tools.h"
#include "Interface.h"

CREATE_INTERFACE(ITools)

void ITools::SetMemoryEx(void* Destination, const char* Data, size_t Size)
{
    this->MemcpyExD(Destination, (void*)Data, Size);
}

void ITools::SetMemoryEx(unsigned long Destination, const char* Data, size_t Size)
{
    this->SetMemoryEx((void*)Destination, Data, Size);
}

void* ITools::MemcpyEx(void *Dest, void* Source, size_t Size)
{
    unsigned long oldSourceProt, oldDestProt;
    VirtualProtect(Source, Size, PAGE_EXECUTE_READWRITE, &oldSourceProt);
    VirtualProtect(Dest, Size, PAGE_EXECUTE_READWRITE, &oldDestProt);
    memcpy(Dest, Source, Size);
    VirtualProtect(Dest, Size, oldDestProt, &oldDestProt);
    VirtualProtect(Source, Size, oldSourceProt, &oldSourceProt);
    return Dest;
}

void* ITools::MemcpyExS(void *Dest, void* Source, size_t Size)
{
    unsigned long oldSourceProt;
    VirtualProtect(Source, Size, PAGE_EXECUTE_READWRITE, &oldSourceProt);
    memcpy(Dest, Source, Size);
    VirtualProtect(Source, Size, oldSourceProt, &oldSourceProt);
    return Dest;
}

void* ITools::MemcpyExD(void *Dest, void* Source, size_t Size)
{
    unsigned long oldDestProt;
    VirtualProtect((LPVOID)Dest, Size, PAGE_EXECUTE_READWRITE, &oldDestProt);
    memcpy(Dest, Source, Size);
    VirtualProtect(Dest, Size, oldDestProt, &oldDestProt);
    return Dest;
}

void ITools::FillMemoryEx(void* Destination, unsigned char Fill, size_t Size)
{
    unsigned long oldDestProt;
    VirtualProtect(Destination, Size, PAGE_EXECUTE_READWRITE, &oldDestProt);
    FillMemory(Destination, Size, Fill);
    VirtualProtect(Destination, Size, oldDestProt, &oldDestProt);
}

void ITools::FillMemoryEx(unsigned long Destination, unsigned char Fill, size_t Size)
{
    this->FillMemoryEx((void*)Destination, Fill, Size);
}

unsigned long ITools::Intercept(unsigned char instruction, void* source, void* destination, size_t length)
{
    unsigned long realTarget;
    LPBYTE buffer = new BYTE[length];
    memset(buffer,0x90,length);
    if (instruction != ITools::I_NOP && length >= 5)
    {
        buffer[(length-5)] = instruction;
        unsigned long dwJMP = (unsigned long)destination - ((unsigned long)source + 5 + (length-5));
        memcpy(&realTarget,(void*)((unsigned long)source+1),4);
        realTarget = realTarget + (unsigned long)source + 5;
        memcpy(buffer + 1 + (length - 5),&dwJMP,4);
    }
    if (instruction == ITools::I_JE_SHORT)
    {
        buffer[0] = instruction;
        buffer[1] = (BYTE)destination;
    }
    if (instruction == 0x00)
        buffer[0] = (BYTE)destination;

    this->MemcpyExD(source, buffer, length);
    delete[] buffer;
    return realTarget;
}