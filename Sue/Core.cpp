#include "StdAfx.h"
#include "Core.h"
#include "Interface.h"
#include "Exports.h"
#include "Process.h"

CREATE_INTERFACE(ICore)

unsigned long __stdcall DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    Interface<ICore> Core;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Core->Boot();
        break;
    }
    return 1;
}

void ICore::Boot()
{
    Interface<IExports> Exports;
    Interface<IProcess> Process;
    Exports->Initialize();
    Process->Hook();
}

unsigned long __stdcall ICore::Run(void* Arg)
{
    while(true) Sleep(1);
}
