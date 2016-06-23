#include <windows.h>
#include <Player.h>

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>
#include <queue>
#include <process.h> 
#include <windows.h>
using namespace std;

#define H 30
#define W 30

/* Tramplines */
static void (__thiscall* Real_LifeAsorbtion) (void* pSkill, void* pPlayer, char* pPacket, char* pPos) = (void (__thiscall*) (void*, void*, char*, char*))0x00488330;

/* Prototypes */
static unsigned (__thiscall* AverageDamage) (void* pPlayer) = (unsigned (__thiscall*) (void*))0x0043D970;
static bool (__thiscall* CheckHit) (void* pPlayer, void* pTarget, int arg) = (bool (__thiscall*) (void*, void*, int))0x43DA00;
static char* (__cdecl* ReadPacket)(char *pPacket, char *pPos, const char *sFormat, ...) = (char* (__cdecl*)(char*, char*, const char*, ...))0x4975F0;
static void* (__cdecl* FindMonster) (int nID) = (void* (__cdecl*) (int))0x0043A240;
static void* (__cdecl* FindPlayer) (int nID) = (void* (__cdecl*) (int))0x00450810;
static void (__cdecl* WriteInSight) (void* pPlayer, BYTE bType, const char *Format, ...) = ( void (__cdecl*) (void*, BYTE, const char*, ...))0x0040B9E0;
static LONG (__thiscall* ObjectRelease)(void* pOject, LONG lpAddend) = (LONG (__thiscall*)(void*, LONG))0x4239C0;

enum
{
	TYPE_PLAYER,
	TYPE_MONSTER,
};


namespace MadLaOtp
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Server::Console::WriteBlue("[MadLaOtp started credits goes to striker and sirix for their source]");
		}
	}

	namespace CPlayerSkill
	{
		void __fastcall LifeAsorbtion(void* pSkill, int edx, void* pPlayer, char* pPacket, char* pPos)
		{
			int nTargetID;
			char bType;
			ReadPacket(pPacket, pPos, "bd", &bType, &nTargetID);

			void* pTarget = 0;

			switch(bType)
			{
			case TYPE_PLAYER:
				pTarget = FindPlayer(nTargetID);
				break;
			case TYPE_MONSTER:
				pTarget = FindPlayer(nTargetID);
				break;
			}

			const int nPlayerID = *(int*)(unsigned(pPlayer)+0x1c);
			const int nSkillID = *(int*)(unsigned(pSkill)+4);
			const int nSkillGrade = *(int*)(unsigned(pSkill)+8);

			int nDmg = 0;
			bool nHit = false;

			if(pTarget)
			{
				if(CheckHit(pPlayer, pTarget, 10))
				{
					const int* const pCurHp = (int*)(unsigned(pTarget)+0x110);
					nHit = true;

					int nDmg = AverageDamage(pPlayer);

					if((40 * nSkillGrade + 50) * nDmg / 50 >= *pCurHp - 1)
						nDmg = *pCurHp - 1;
					else
						nDmg = ((40 *  nSkillGrade + 50) * nDmg / 50);

					const int nMaxDmg = (nSkillGrade * 3300);

					while(nDmg > nMaxDmg)
						nDmg -= 77;

					//	prevent hp renew 
					if((*(int (__thiscall **)(void*))(*(DWORD *)pTarget + 0x40))(pTarget))
						*(DWORD*)((unsigned)pTarget + 0x1d8) = GetTickCount() + 20000;

					//	damage the target 
					(*(void (__cdecl **)(void*, int, int, int))(*(DWORD*)pTarget+0x58))(pTarget, 7, 0, nDmg);
					// cure the player //
					(*(void (__cdecl **)(void*, int, int, int))(*(DWORD*)pPlayer+0x58))(pPlayer, 7, 1, (nDmg * (10 * nSkillGrade + 20) / 50));
					// consume mana //
					(*(void (__cdecl **)(void*, int, int, int))(*(DWORD*)pPlayer+0x58))(pPlayer, 8, 0, (*(int (__thiscall **)(void*, DWORD))(*(DWORD *)pSkill + 0x20))(pSkill, 0));
				}

				(*(void (__thiscall **)(void*, void *))(*(DWORD *)pTarget+0x50))(pTarget, pPlayer);
				WriteInSight(pPlayer, 0x3f, "bddbbwwb", nSkillID, nPlayerID, nTargetID, 1, nSkillGrade, nDmg, 0, nHit);
				ObjectRelease(pTarget, LONG(pTarget) + 0x160);
			}
		} 
	}
}