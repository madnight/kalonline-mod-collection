#include "MadCommand.h"


//0x004354CE Server Start Message 
BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadCommand::CIOServer::Start);
	core.Register(&(PVOID&)Server::CPlayer::ChatCommand, MadCommand::CPlayer::ChatCommand);
	core.RegisterHook(0x004354CE, MadCommand::CIOServer::AfterStart);
	return core.Run();
}