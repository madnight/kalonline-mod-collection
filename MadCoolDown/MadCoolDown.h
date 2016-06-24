/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
#pragma comment(lib, "MadLib.lib")
#include <MainPlayer.h>
#include "Utilities.h"
#include <Command.h>

namespace MadCoolDown
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Read_Config();
			Server::Console::WriteBlue("[MadCoolDown started]");
		}
	}
	namespace CPlayer
	{
		void __fastcall ChatCommand(void *thispointer,  void *_edx, char *comm)
		{
			Player player(thispointer);
			Command command(comm);

			if(player.isGM())
			{
				if (command.beginWith("/reloadcooldown"))
				{
					Read_Config();
					Server::Console::WriteBlue("[MadCoolDown reloaded]");
				}
			}
			Server::CPlayer::ChatCommand(thispointer,comm);
		}
	}
	namespace CPlayerSkill
	{
		__declspec(noreturn) extern void fatal () {}
		signed int __fastcall ExcuteSkill(int *thispointer, void *_edx, signed int skillid, int a3, int a4)
		{

			Player player(thispointer - 156); 

			if (CoolDownTable[player.GetClass()][skillid] > 0 && CoolDown_Timer[player.GetPid()].Last_Call[skillid] != NULL &&
				GetTickCount() - CoolDown_Timer[player.GetPid()].Last_Call[skillid] < (unsigned int) CoolDownTable[player.GetClass()][skillid])
			{
				Server::Console::WriteRed("[Cooldownhack detected! Player: %s]",player.GetName());
				//player.Kick();
				CoolDown_Timer[player.GetPid()].Last_Call[skillid] = GetTickCount();
				fatal();
			}
			else
			{
				CoolDown_Timer[player.GetPid()].Last_Call[skillid] = GetTickCount();
				return Server::CPlayerSkill::ExcuteSkill(thispointer,skillid,a3,a4);
			}
		}
	}
}