#include "MadAI.h"

#include <MadCore.h>
#pragma comment(lib, "MadLib.lib")



BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	//CreateConsole();
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadAI::CIOServer::Start);
	core.Register(&(PVOID&)Server::CMonsterReal::AI, MadAI::CMonsterReal::AI);
	return core.Run();
}