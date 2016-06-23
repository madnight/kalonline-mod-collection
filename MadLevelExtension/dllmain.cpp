#include "MadLevelExtension.h"

#include <MadCore.h>
#pragma comment(lib, "MadLib.lib")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadLevelExtension::CIOServer::Start);
	

	
		core.Register(&(PVOID&)Server::CPlayerSkill::AttackHit, MadLevelExtension::CPlayerSkill::AttackHit);
	
	core.Register(&(PVOID&)Server::CPlayer::CheckBlock, MadLevelExtension::CPlayer::CheckBlock);
	
	core.Register(&(PVOID&)Server::CPlayerSkill::AttackHitX, MadLevelExtension::CPlayerSkill::AttackHitX);
	
	return core.Run();
}




//CRAP!!!
//core.Register(&(PVOID&)Server::CPlayer::CheckBlock, MadLevelExtension::CPlayer::CheckBlock);

//core.RegisterHook(0x00482065,MadLevelExtension::CPlayerSkill::Fix);
//core.RegisterHook(0x00482098,MadLevelExtension::CPlayerSkill::Fix);


//core.RegisterHook(0x00482A69,MadLevelExtension::CPlayerSkill::Fix);
//core.RegisterHook(0x00482A9C,MadLevelExtension::CPlayerSkill::Fix);