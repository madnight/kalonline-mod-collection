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
 
#include "MadOnTimer.h"

void IMadOntimer::Run()
{
	if (counter%1800 == 0)
	{
		if ( config->DEBUG_MODE && false )
			Server::Console::WriteBlack("PlayerOnTimer write Message");
		
		Server::CPlayer::WriteAll(15,"s","This Server is protected by MadKnight's Protection "+VERSION+"");
	}

	if (config->MESSAGE_DELAY >= 0)
	{
		if (counter % config->MESSAGE_DELAY == 0)
		{
			std::string messgae = config->MESSAGES.back();
			config->MESSAGES.pop_back();
			std::reverse(config->MESSAGES.begin(),config->MESSAGES.end());
			config->MESSAGES.push_back(messgae);
			std::reverse(config->MESSAGES.begin(),config->MESSAGES.end());
			Server::CPlayer::WriteAll(15,"s",messgae.c_str());
		}

	}

	if (counter%5 == 0)
	{
		if ( config->DEBUG_MODE && false )	
			Server::Console::WriteBlack("Enter PlayerOnTimer Check");
	
		ENTER_CRIT
			PLAYER_LIST_ITERATE
		{
			Player *player = new Player(PLAYER_POINTER);

			if ( player && player->GetAdmin() < 8)
			{						
				if (config->UG_OG_CHECK && (player->GetZCoord() >= config->MAX_Z_VALUE || player->GetZCoord() < config->MIN_Z_VALUE || player->GetXCoord() < 0 || player->GetYCoord() < 0))
				{
					Server::Console::WriteRed("[MadProtectS UndergroundHack detected %s kicked]",player->GetName());
					player->Kick();
				}

				if (
					player->GetMinAtk()    < 0 ||
					player->GetMinMagAtk() < 0 ||
					player->GetMaxAtk()    < 0 ||
					player->GetMaxMagAtk() < 0 ||
					player->GetMaxAtk()    >= config->MAX_ATTACK ||
					player->GetMaxMagAtk() >= config->MAX_ATTACK ||
					player->GetMinAtk()    >= config->MAX_ATTACK ||
					player->GetMinMagAtk() >= config->MAX_ATTACK )
				{
					Server::Console::WriteRed("[MadProtectS DamageHack detected %s kicked]",player->GetName());
					player->Kick();
				}
				//  15 everyone, 47 mage, 31 knight
				if ( config->JOB_HACK_CHECK &&
				   ( player->GetSpeciality() == 15 || player->GetSpeciality() == 47 || 
					 player->GetSpeciality() == 31 || player->GetSpeciality() == 63  ||
					 player->GetSpeciality() == 59 ) )
				{
					Server::Console::WriteRed("[MadProtectS 2xJobhack detected %s kicked]",player->GetName());
					player->Kick();
				}	

				if ( player->GetSpeed() >= config->MAX_MOVE_SPEED)
				{
					Server::Console::WriteRed("[MadProtectS SpeedHack detected %s kicked]",player->GetName());
					player->Kick();
				}		
			}
			delete player, player = 0;
		}
		LEAVE_CRIT

			if ( config->DEBUG_MODE && false )
				Server::Console::WriteBlack("Leave PlayerOnTimer Check");
	}
}

