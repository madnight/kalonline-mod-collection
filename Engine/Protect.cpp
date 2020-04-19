#include <windows.h>
#include "Protect.h"
#include "Interface.h"
#include "Tools.h"
#pragma comment(lib,"Detours/enigma_ide.lib")
#include "Detours/enigma_ide.h"

CREATE_INTERFACE(IProtect)

std::string Crypt(std::string Key)
{
    std::string output = Key;
    
    for (int i = 0; i < (int)Key.size(); i++)
        output[i] = Key[i] ^ 250;
    
	return output;
}

static int (__cdecl *Connection)(int Type, const char *Text,...) = (int (__cdecl*)(int,const char*,...))0x0046F850;

int __cdecl ConnectionFix(int Type, const char *Text, int Value, int Object, int Argument)
{
	return Connection(Type,"bd",Value,Object);
}

DWORD __stdcall FixGetFileAttributesA(LPCSTR lpFileName)
{
	return 0;
}

bool IProtect::Disable()
{
	Interface<ITools> Tools;
	Tools->Intercept(ITools::_I_CALL, (void*)0x0062151B, ConnectionFix, 5);
	Tools->Intercept(ITools::_I_CALL, (void*)0x0078EA35, (void*)FixGetFileAttributesA, 6);
	Tools->FillMemoryEx(0x0060F81E, ITools::_I_NOP, 1);
	Tools->FillMemoryEx(0x0060F825, ITools::_I_NOP, 1);
	Tools->FillMemoryEx(0x0060F82D, ITools::_I_NOP, 6);
	Tools->FillMemoryEx(0x0046ED41, ITools::_I_JMP_SHORT, 1);
	Tools->FillMemoryEx(0x0046ED68, ITools::_I_JMP_SHORT, 1);
	Tools->SetMemoryEx(0x0081C450, "sbbbbbbbb", 10);
	Tools->SetMemoryEx(0x00821398, "bbddww", 7);
	Tools->FillMemoryEx(0x00622EBC, ITools::_I_JMP_SHORT, 1);
	Tools->FillMemoryEx(0x00621566, ITools::_I_NOP, 5);
	Tools->FillMemoryEx(0x0062156B, ITools::_I_NOP, 5);
	float ZoomLimit = 300.0;
	Tools->MemcpyExD((void*)0x008409A4, &ZoomLimit, 4);
	return true;
}