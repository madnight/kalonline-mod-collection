
#include "MadProtectS.h"
#include <detours.h>

#define SERVER_RECV_CRYPT 0x0049463d
#define CSocket_Process_Caller 0x004946DC

void Disable_Rev_Crypt()
{
      IMemory *Memory = new IMemory;
	  Memory->Fill(SERVER_RECV_CRYPT, IMemory::_I_NOP, 23);
	  delete Memory;
}

void AddMenu()
{
      CreateThread(0, NULL, ThreadProc, (LPVOID)L"MainSvrt on port 30001", NULL, NULL);
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	if (CheckLicense())
	{
	core.RegisterCustom(Disable_Rev_Crypt);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadProtectS::CIOServer::Start);
	core.Register(&(PVOID&)Server::CPlayer::ChatCommand, MadProtectS::CPlayer::ChatCommand);
	//core.Register(&(PVOID&)Server::CPlayer::Tick,MadProtectS::CPlayer::Tick);

	// Unloaded Ontimer
	core.Register(&(PVOID&)Server::CPlayerObject::OnTimer,MadProtectS::CPlayerObject::OnTimer);
	
	core.RegisterHook(0x0043AC5D,MadProtectS::CMonster::CMonsterRealDamage);
	core.RegisterHook(0x0043F2F1,MadProtectS::CMonster::CMonsterRealDamage);
	core.RegisterHook(0x004424BD,MadProtectS::CMonster::CMonsterRealDamage);
	core.RegisterHook(0x00443A1D,MadProtectS::CMonster::CMonsterRealDamage);
	core.RegisterHook(0x00444EDD,MadProtectS::CMonster::CMonsterRealDamage);

	

	 // core.Register(&(PVOID&)Server::CIOSocket::IOThread,MadProtectS::CIOSocket::IOThread);

	
	
	core.Register(&(PVOID&)Orig_DLLWindowProc, Hooked_DLLWindowProc);
	core.Register(&(PVOID&)Server::CPlayer::GameStart, MadProtectS::CPlayer::GameStart);
	core.RegisterHook(CSocket_Process_Caller, MadProtectS::SSocket::Process);
	//core.Register(&(PVOID&)Server::CSocket::Process, MadProtectS::SSocket::Process);

	/** Gibts schon siehe Log//
	core.Register(&(PVOID&)Server::Console::WriteBlack, MadProtectS::Console::WriteBlack);
	core.Register(&(PVOID&)Server::Console::WriteRed, MadProtectS::Console::WriteRed);
	core.Register(&(PVOID&)Server::Console::WriteBlue, MadProtectS::Console::WriteBlue);
	**/
	}
	else
	core.Register(&(PVOID&)Server::CIOServer::Start, MadProtectS::CIOServer::Fail);
	return core.Run();
}