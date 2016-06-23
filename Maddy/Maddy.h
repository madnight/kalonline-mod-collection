#pragma once

#define WIN32_LEAN_AND_MEAN         

#define KNIGHT  0
#define MAGE    1
#define ARCHER  2
#define THIEF   3
#define MAX_SKILL_ID 84

#define HIDING 6
#define RUPTURE 17

#define RUN 0
#define BEHEAD 1
#define DEBUG 1

//#define DEREF_VAL(pointer,val) *(DWORD *)(((int*)pointer)[val])

#include <windows.h>

#include "../Server.h"
#include "Player.h"
#include "Monster.h"
#include "Skill.h"
#include "PlayerSkill.h"
#include "CustomSkill.h"
#include "CSkillVtbl.h"
#include <process.h>

namespace Maddy 
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Server::Console::WriteBlue("[Maddy started]");
		}
	}

	namespace CPlayerSkill 
	{

		void Hiding(void* PlayerPointer)
		{
			(*(void (__thiscall **)(void*, signed int, _DWORD))(*(_DWORD *)PlayerPointer + 104))(PlayerPointer,524288,0); // Hide
			Sleep(20000);
			if (PlayerPointer) // Check that Player still exist
			{
				(*(void (__thiscall **)(void*, signed int, _DWORD))(*(_DWORD *)PlayerPointer + 124))(PlayerPointer,524288,0); // Unhide
			}
			 _endthread(); 
		}

		int ThiefSkill__Hiding(void *PlayerPointer, char *PacketPointer, char *PositionPointer)
		{
			Server::Console::WriteBlack("ThiefSkill__Hiding casted");
			_beginthread(Hiding,0,PlayerPointer); // Without Thread would be a better solution
			return 1;
		}

		int ThiefSkill__Rupture(PlayerSkill *p)
		{
			Server::Console::WriteBlack("ThiefSkill__Rupture casted");
			CustomSkill *Rupture = new CustomSkill(17);
			p->SetSkill(17,Rupture);
			return 1;
		}

		int ThiefSkill__Behead(void *PlayerPointer, char *PacketPointer, char *PositionPointer)
		{
			int result;
			char Type;
			unsigned int TargetId;
			Server::ReadPacketSecure(PacketPointer, PositionPointer, "bd", &Type, &TargetId);
			void *MonsterPointer = Server::CMonster::FindMonster(TargetId);
			Monster *monster = new Monster(MonsterPointer);
			Player *player = new Player(PlayerPointer);

			result = (int) MonsterPointer;

			if (MonsterPointer)
			{
				int PlayerMaxHP = Server::CChar::GetMaxHp(PlayerPointer);
				(*(void (__cdecl **)(void *, signed int, signed int, int))(*(_DWORD *)PlayerPointer + 88))(PlayerPointer, 7, 1, PlayerMaxHP / 10);

				int PlayerMaxMP = Server::CChar::GetMaxMP(PlayerPointer);
				(*(void (__cdecl **)(void *, signed int, signed int, int))(*(_DWORD *)PlayerPointer + 88))(PlayerPointer, 8, 1, PlayerMaxMP / 10);

				Server::CChar::SetDirection(PlayerPointer, monster->GetXCoord() - player->GetXCoord() , monster->GetYCoord() - player->GetYCoord() );

				int TargetID = Server::CBase::Id(MonsterPointer);
				int PlayerID = Server::CBase::Id(PlayerPointer);
				Server::CChar::WriteInSight(PlayerPointer,0x3F, "bddbb", 1, PlayerID, TargetID, 0, 1);

				int MonsterID = Server::CBase::Id(MonsterPointer);
				Server::CChar::WriteInSight(MonsterPointer, 0x3D, "db", MonsterID, 0xA);
				Server::CBase::Delete(MonsterPointer);
				result = Server::CIOObject::ReleaseN(MonsterPointer, monster->GetRelease());
			}
			delete monster,player; monster, player = 0;
			return result;
		}

		void ThiefSkill__Run(PlayerSkill *p)
		{
			CustomSkill *thiefrun = new CustomSkill(0);
			p->SetSkill(0,thiefrun);
		}

		void ThiefSkill__Behead(PlayerSkill *p)
		{
			CustomSkill *thiefbhead = new CustomSkill(1);
			p->SetSkill(1,thiefbhead);
		}

		int __fastcall PreSkill(void *CPlayerSkill, signed int SkillID, int a3)
		{
			Server::Console::WriteBlack("Preskill: %i", SkillID);
			int result; 
			PlayerSkill *pskill = new PlayerSkill(CPlayerSkill);
			Player *player = new Player(pskill->GetPlayer());
			Skill *skill = new Skill(pskill->GetSkill(SkillID));

		
			void *SkillPointer = skill->thispointer;
			if (skill->thispointer)
			{
				__asm mov eax, a3
				__asm push eax
				__asm mov edx, CPlayerSkill
				__asm mov eax, [edx]
				__asm push eax
				__asm mov ecx, SkillPointer
				__asm mov edx, [ecx]
				__asm mov ecx, SkillPointer
				__asm call dword ptr [edx+64] 
				__asm mov result, eax
			}
			else
			{
				__asm mov result, 0
				Server::Console::WriteBlack("Invalid SkillPointer");
			}
			delete pskill,player,skill; pskill,player,skill = 0;
		}

		int __fastcall ExecuteSkill(void *PlayerCSkill, void *edx_, signed int SkillID, char *PacketPointer, char *PositionPointer)
		{
			int result; 
			result = SkillID;

			PlayerSkill *pskill = new PlayerSkill(PlayerCSkill);
			Player *player = new Player(pskill->GetPlayer());
			Skill *skill = new Skill(pskill->GetSkill(SkillID));

			if ( player && SkillID < MAX_SKILL_ID )
			{
				switch ( player->GetClass() )
				{
				case KNIGHT:
					Server::Console::WriteBlack("Knight: Player %s cast SkillID %i SkillLevel %i",player->GetName(), SkillID, skill->GetLevel());
					break;
				case MAGE:
					Server::Console::WriteBlack("Mage: Player %s cast SkillID %i SkillLevel %i",player->GetName(), SkillID, skill->GetLevel());
					break;
				case ARCHER:
					Server::Console::WriteBlack("Archer: Player %s cast SkillID %i SkillLevel %i",player->GetName(), SkillID, skill->GetLevel());
					break;
				case THIEF:
					Server::Console::WriteBlack("Thief: Player %s cast SkillID %i ",player->GetName(), SkillID);

					switch (SkillID)
					{
					case RUN:
						ThiefSkill__Run(pskill);
						break;
					case BEHEAD:
						ThiefSkill__Behead(player->thispointer,PacketPointer,PositionPointer);//ThiefSkill__Behead(pskill);//
						break;
					case HIDING:
						ThiefSkill__Hiding(player->thispointer,PacketPointer,PositionPointer);
						break;
					case RUPTURE:
						ThiefSkill__Rupture(pskill);
						break;
					default:
						Server::Console::WriteBlack("ThiefSkill not yet implemented ID %i",SkillID);
						break;
					}
					break;
				default:
					Server::Console::WriteBlack("Invalid PlayerClass: Uhm? (no Knight / Mage / Archer or Thief) Player %s cast SkillID %i", player->GetName(), SkillID);
					break;
				}
			}
			else
			{
				Server::Console::WriteBlack("Invalid Player Pointer");
			}

			void *SkillPointer = skill->thispointer;//pskill->GetSkill(SkillID); 

			if (DEBUG && SkillPointer)
			{
				CSkillVtbl *vt = new CSkillVtbl(skill->GetCSkillVtbl());

				Server::Console::WriteBlack("SkillID %i, SkillLevel %i, SkillMPDec %i, SkillDelay %i SkillLastTime %i SkillGetLimitLevel %i",
					skill->GetID(),skill->GetLevel(),skill->GetDecreaseMP(),skill->GetDelay(),skill->GetLastTime(),skill->GetLimitLevel());

				Server::Console::WriteBlack("SkillLimitSpec %i, SkillTick %i SkillV1 %i, SkillV2 %i",
					skill->GetLimitSpecialty(),skill->GetTick(),skill->GetV1(), skill->GetV2());

				Server::Console::WriteBlack("CSkillVtbl+0 %i, CSkillVtbl+4 %i, CSkillVtbl+8 %i, CSkillVtbl+12 %i,  ",vt->GetCopy(),vt->GetCanExecuteFunkPtr(),vt->GetExecuteFunkPtr(),vt->GetExecutePassiveFunkPtr());

			}

			if ( SkillPointer )
			{
				__asm mov eax, PositionPointer
				__asm push eax
				__asm mov ecx, PacketPointer
				__asm push ecx
				__asm mov edx, PlayerCSkill
				__asm mov eax, [edx]
				__asm push eax
				__asm mov ecx, SkillPointer
				__asm mov edx, [ecx]
				__asm mov ecx, SkillPointer
				__asm call dword ptr [edx+4] 
				__asm mov result, eax
			}
			else
			{
				//check this line
				__asm mov result, 1 
				Server::Console::WriteBlack("Invalid SkillPointer");
			}
			delete pskill,player,skill; pskill,player,skill = 0;
			return result;
		}
	}
}