#include "MadWord.h"
#include <MadCore.h>

#include <Memory.h>

#pragma comment(lib, "MadLib.lib")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadWord::CIOServer::Start);
	core.Register(&(PVOID&)Server::Console::WriteBlack, MadWord::Console::WriteBlack);
	core.Register(&(PVOID&)Server::Console::WriteRed, MadWord::Console::WriteRed);
	core.Register(&(PVOID&)Server::Console::WriteBlue, MadWord::Console::WriteBlue);
	return core.Run();
}