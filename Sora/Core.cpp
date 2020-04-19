#include "StdAfx.h"
#include "Core.h"
#include "Interface.h"
#include "Deflector.h"
#include "Memory.h"

CREATE_INTERFACE(ICore)

unsigned long __stdcall DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    Interface<ICore> Core;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Core->Boot(hModule);
        break;
    }
    return 1;
}


ICore::ICore(void)
{
}

ICore::~ICore(void)
{
}

void ICore::Boot(HMODULE hModule)
{
    Interface<IMemory> Memory;

    // Remove SpeedHack message
    Memory->Fill(0x004949f7, IMemory::_I_NOP, 0x1f, false);
    Memory->Fill(0x00494a79, IMemory::_I_NOP, 0x1f, false);
}
