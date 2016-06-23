#include "MadReborn.h"

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadReborn::CIOServer::Start);
	core.Register(&(PVOID&)Server::CPlayer::ChatCommand, MadReborn::CPlayer::ChatCommand);
	return core.Run();
}