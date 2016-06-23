#include "MadRealtime.h"

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadRealtime::CIOServer::Start);
	core.Register(&(PVOID&)Server::CItemGeneral::Enchant, MadRealtime::CItemGeneral::Enchant);
	core.Register(&(PVOID&)Server::CPlayer::ChatCommand, MadRealtime::CPlayer::ChatCommand);
	//core.Register(&(PVOID&)Server::CItemWeapon::ChangePrefix, MadRealtime::CItemWeapon::ChangePrefix);
	
	return core.Run();
}