#include "MadSummon.h"

#include <MadCore.h>
#pragma comment(lib, "MadLib.lib")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadSummon::CIOServer::Start);
	core.Register(&(PVOID&)Server::CPlayerObject::OnTimer, MadSummon::CPlayerObject::OnTimer);
	core.Register(&(PVOID&)Server::CPlayer::ChatCommand, MadSummon::CPlayer::ChatCommand);
	return core.Run();
}