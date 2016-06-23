#include "MadLaOtp.h"
#include <MadCore.h>
#pragma comment(lib, "MadLib.lib")


BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadLaOtp::CIOServer::Start);
	//core.Register(&(PVOID&)Real_LifeAsorbtion, MadLaOtp::CPlayerSkill::LifeAsorbtion);
	return core.Run();
}