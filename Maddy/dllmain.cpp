
#include "Maddy.h"


#include <MadCore.h>
#pragma comment(lib, "MadLib.lib")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);

	core.Register(&(PVOID&)Server::CIOServer::Start, Maddy::CIOServer::Start);
	core.Register(&(PVOID&)Server::CPlayerSkill::ExcuteSkill, Maddy::CPlayerSkill::ExecuteSkill);
	core.Register(&(PVOID&)Server::CPlayerSkill::PreSkill, Maddy::CPlayerSkill::PreSkill);
	return core.Run();
}