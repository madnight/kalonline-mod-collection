#include "MadOnline.h"

#pragma comment(lib, "MadLib.lib")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadOnline::CIOServer::Start);
//	core.Register(&(PVOID&)Server::Unknown::CPlayerSkill__ExcuteTransformSkill, MadOnline::CPlayerSkill::ExcuteTransformSkill);
//	core.Register(&(PVOID&)Server::CGuild::CGuild__AllianceOffer, MadOnline::CGuild::AllianceOffer);
	core.Register(&(PVOID&)Server::CPlayerObject::OnTimer, MadOnline::CPlayerObject::OnTimer);
	core.Register(&(PVOID&)Server::CPlayer::ChatCommand, MadOnline::CPlayer::ChatCommand);
	return core.Run();
}
