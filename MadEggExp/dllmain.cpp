#include <MadCore.h>
#include "MadEggExp.h"


#pragma comment(lib, "MadLib.lib")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	IMemory *Memory = new IMemory;
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadEggExp::CIOServer::Start);
	//Memory->HookAPI(0x0042F030,EggExp);
	core.Register(&(PVOID&)Server::CPlayer::CPlayer__UpdateTransformExp, CPlayer__UpdateTransformExp);
	return core.Run();
}