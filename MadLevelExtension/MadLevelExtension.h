#include "Utilities.h"

//#define VERSION "0.4.6" // GAP
#define VERSION "0.9.0" 
namespace MadLevelExtension
{	
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			//readConfig();
			setupExpTable();
			//ReadConfig();
			Server::Console::WriteBlue("[MadLevelExtension started Version "VERSION"]");
		//	Server::Console::WriteBlue("[MadExpGapSystem started Version "VERSION"]");
		}
	}
	namespace CPlayer
	{
		bool __fastcall CheckBlock(void* thispointer,void* _edx , int a2) 
		{
			__try 
			{
				return Server::CPlayer::CheckBlock(thispointer,a2);
			} __except (EXCEPTION_EXECUTE_HANDLER)
			{
				return 0;
			}
		}
	}
	namespace CPlayerSkill
	{
		//This fix is needed to avoid 2x Divsion by Zeros
		int __fastcall AttackHit(void *thispointer,void* _edx , void *PlayerPointer, void* Target, int a4, int a5, int a6, int a7)
		{

			__try 
			{
				return Server::CPlayerSkill::AttackHit(thispointer,PlayerPointer,Target,a4,a5,a6,a7);
			} __except (EXCEPTION_EXECUTE_HANDLER)
			{
				return 0;
			}
			/**
			int result = 0; 
			__try 
		{
			unsigned int AttackDamage; 
			int v8; 
			
			unsigned int v10; 
			unsigned int v11; 
			void *v12; 
			int v13; 

			int crashfix;
			int crasfix_two;
			v12 = thispointer;
			//int x =  (*(int (__thiscall **)(void*, void*))(*(_DWORD *)v12 + 0x24))(v12, PlayerPointer); //return *(_DWORD *)(this + 44) - 100 * *(_DWORD *)(this + 8);
			//Server::Console::WriteBlue("This is a test %d  %d",x , (*(_DWORD *)v12 + 0x24));
			AttackDamage = Server::CChar::GetAttack(PlayerPointer);
			v13 = (*(int (__thiscall **)(void*, void*, _DWORD))(*(_DWORD *)v12 + 0x10))(v12, PlayerPointer, AttackDamage);
			v8 = (*(int (__thiscall **)(void*))(*(_DWORD *)v12 + 84))(v12);
			if ( Server::CChar::CheckHit(PlayerPointer, Target, v8) )
			{
				v10 = a4 * (*(int (__thiscall **)(void*, void*))(*(_DWORD *)PlayerPointer + 168))(PlayerPointer, Target);
				crashfix = (*(int (__thiscall **)(void*, void*))(*(_DWORD *)v12 + 0x24))(v12, PlayerPointer);
			//	if (crashfix <= 0)
			//		crashfix = 2000;
				*(_DWORD *)a7 = v10 / crashfix;

				crasfix_two = (*(int (__thiscall **)(void*, void*, _DWORD, _DWORD, _DWORD, void*))(*(_DWORD *)v12 + 0x24))(
					v12,
					PlayerPointer,
					a5,
					a6,
					a7,
					v12);
			//	if ( crasfix_two <= 0)
			//		crasfix_two = 2000;
				result = (*(int (__thiscall **)(void*, void*, _DWORD))(*(_DWORD *)Target + 72))(Target, PlayerPointer, a4 * v13 / crasfix_two);
			}
			else
			{
				result = 0;
			}
		}
		__except(EXCEPTION_EXECUTE_HANDLER) 
		{   
		//Server::Console::WriteRed("Error");
		}
			
			return result;

			**/
		}

		//vll doch lieber wieder unsigned int
		int __fastcall Fix(void *SkillPointer,void* _edx,void *PlayerPointer )
		{
		   unsigned int i = *((_DWORD *)SkillPointer + 11) - 100 * *((_DWORD *)SkillPointer + 2);
		  if (i == 0)
			  return 1;
		  else 
			  return i;
		}

		// Heartbreaker
		int __fastcall AttackHitX(void *thispointer,void* _edx , void *PlayerPointer, void* Target, int a4, int a5, int a6, int a7)
		{
			__try 
			{
			 return Server::CPlayerSkill::AttackHitX(thispointer,PlayerPointer,Target,a4,a5,a6,a7);
			} __except (EXCEPTION_EXECUTE_HANDLER)
			{
				return 0;
			}
		}
		/**	int result = 0;
				__try 
		{
			unsigned int AttackDamage; // eax@1
			int v8; // eax@1
			unsigned int v9; // esi@2
			unsigned int crashfix2; // eax@2
			void *BuffP; // eax@4
			int v12; // ST14_4@4
			int result; // eax@5
			void *SkillP; // [sp+4h] [bp-Ch]@1
			int Damage; // [sp+8h] [bp-8h]@2
			int v16; // [sp+Ch] [bp-4h]@1
			int crashfix1;
		//	Server::Console::WriteBlue("this is a test by Mad Knight");
		//	*(_DWORD *)SkillP + 0x24
			//

			SkillP = thispointer;
			AttackDamage = Server::CChar::GetAttack(PlayerPointer);
			v16 = (*(int (__thiscall **)(void *, void*, unsigned int))(*(_DWORD *)SkillP + 0x10))(SkillP, PlayerPointer, AttackDamage);
			v8 = (*(int (__thiscall **)(void *))(*(_DWORD *)SkillP + 0x54))(SkillP);
			if ( Server::CChar::CheckHit(PlayerPointer, Target, v8) )
			{
				v9 = a4 * (*(int (__thiscall **)(void*, void*))(*(_DWORD *)PlayerPointer + 0xA8))(PlayerPointer, Target);

				crashfix1 = (*(int (__thiscall **)(void *, void*))(*(_DWORD *)SkillP + 0x24))(SkillP, PlayerPointer);
				//if (crashfix1 <= 0)
				//	crashfix1 = 2000;

				*(_DWORD *)a7 = v9 / crashfix1;
				crashfix2 = (*(int (__thiscall **)(void *, void*, int, int, int, void *))(*(_DWORD *)SkillP + 0x24))(
					SkillP,
					PlayerPointer,
					a5,
					a6,
					a7,
					SkillP);
			//	if (crashfix2 <= 0)
				//	crashfix2 = 2000;

				Damage = (*(int (__thiscall **)(void*, void*, unsigned int))(*(_DWORD *)Target + 0x48))(
					Target,
					PlayerPointer,
					a4 * v16 / crashfix2);
				if ( (*(int (__thiscall **)(void *, void*, void*))(*(_DWORD *)SkillP + 0x28))(SkillP, PlayerPointer, Target) )
				{
					if ( Server::CChar::IsNormal(Target) )
					{
						BuffP = Server::CBuff::CreateBuff(7, *((_DWORD *)SkillP + 2) / 2 + 1, v12, (int)SkillP);
						(*(void (__thiscall **)(void*, void *))(*(_DWORD *)Target + 0xB4))(Target, BuffP);
					}
				}
				result = Damage;
			}
			else
			{
				result = 0;
			}
			}
		__except(EXCEPTION_EXECUTE_HANDLER) 
		{   
		//Server::Console::WriteRed("Error");
		}
			return result;
			**/
	//	}
	}
}