#include <Windows.h>
#pragma pack(1)
HINSTANCE hL = 0;
FARPROC p[806] = {0};
#pragma comment(lib,"Detours/detours.lib")
#include "Detours/detours.h"
#pragma comment(lib,"Detours/enigma_ide.lib")
#include "Detours/enigma_ide.h"
#include "Engine.h"
#include "Exports.h"
#include "Protect.h"
#include "Interface.h"
#include "Chatbox.h"
#include "Packets.h"
#include "VButtonFix.h"
#include "Buff.h"
#include "Tools.h"
#include "DSSWindow.h"
#include "MakeTip.h"
#include "RedBlue.h"
#include "ExpTable.h"
#include "MD5.h"
#include "base64.h"
#include "Sha256.h"
#include <iterator>
#include <iomanip>
#include <sstream>
#include <wininet.h>
#pragma comment(lib,"Wininet.lib")
#pragma comment(lib,"Ws2_32.lib")
#pragma warning (disable : 4996)
int StoreValue = 0;

void DisableProtection()
{
	Interface<IProtect> Protect;
	Protect->Disable();
	Interface<IChatbox> Chatbox;
	Chatbox->HookCommand();
	Interface<IPackets> Packets;
	Packets->Hook();
	Packets->DssUpdateCheck = false;
	Interface<IBuff> Buff;
	Buff->HookBuff();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			InitializeADVAPI32();
			Interface<ITools> Tools;
			BofFix();
			SwitchTable();
			DisableProtection();
			DetourTransactionBegin();
			DetourAttach(&(PVOID&)KalItemShop1, MyKalItemShop1);
			DetourAttach(&(PVOID&)KalItemShop2, MyKalItemShop2);
			DetourAttach(&(PVOID&)KalItemShop3, MyKalItemShop3);
			DetourAttach(&(PVOID&)Engine::KGameSys::OnOk, OnOk);
			DetourAttach(&(PVOID&)Engine::KGameSys::OnCancel, OnCancel);
			DetourAttach(&(PVOID&)IsPlayerCheck, MyIsPlayerCheck);
			DetourAttach(&(PVOID&)PlayerTick, MyPlayerTick);
			DetourAttach(&(PVOID&)IsPlayerAttack, MyIsPlayerAttack);
			DetourAttach(&(PVOID&)SetTip, MySetTip);
			DetourAttach(&(PVOID&)Engine::KGameSys::PressKey, PressKey);
			DetourAttach(&(PVOID&)Engine::KGameSys::CheckForDss, CheckForDss);
			DetourAttach(&(PVOID&)Engine::KGameSys::MakeTip, MakeTip);
			DetourAttach(&(PVOID&)SkillButton, MySkillButton);
			DetourTransactionCommit();
			break;
		}
	case DLL_PROCESS_DETACH:
		{
			FinalizeADVAPI32();
			BofFix();
			SwitchTable();
			DisableProtection();
			DetourTransactionBegin();
			DetourDetach(&(PVOID&)KalItemShop1, MyKalItemShop1);
			DetourDetach(&(PVOID&)KalItemShop2, MyKalItemShop2);
			DetourDetach(&(PVOID&)KalItemShop3, MyKalItemShop3);
			DetourDetach(&(PVOID&)Engine::KGameSys::OnOk, OnOk);
			DetourDetach(&(PVOID&)Engine::KGameSys::OnCancel, OnCancel);
			DetourDetach(&(PVOID&)IsPlayerCheck, MyIsPlayerCheck);
			DetourDetach(&(PVOID&)PlayerTick, MyPlayerTick);
			DetourDetach(&(PVOID&)IsPlayerAttack, MyIsPlayerAttack);
			DetourDetach(&(PVOID&)SetTip, MySetTip);
			DetourDetach(&(PVOID&)Engine::KGameSys::PressKey, PressKey);
			DetourDetach(&(PVOID&)Engine::KGameSys::CheckForDss, CheckForDss);
			DetourDetach(&(PVOID&)Engine::KGameSys::MakeTip, MakeTip);
			DetourDetach(&(PVOID&)SkillButton, MySkillButton);
			DetourTransactionCommit();
			break;
		}
	}
	return TRUE;
}