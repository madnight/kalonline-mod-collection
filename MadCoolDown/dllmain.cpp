#include <MadCore.h>
#include "MadCoolDown.h"

#pragma comment(lib, "MadLib.lib")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadCoolDown::CIOServer::Start);
	core.Register(&(PVOID&)Server::CPlayer::ChatCommand, MadCoolDown::CPlayer::ChatCommand);
	core.Register(&(PVOID&)Server::CPlayerSkill::ExcuteSkill, MadCoolDown::CPlayerSkill::ExcuteSkill);
	return core.Run();
}