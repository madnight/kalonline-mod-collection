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
 
#include "IMadGameStart.h"

string convertToInt(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}

void IMadGameStart::RunIt()
{
	if ( conf->DEBUG_MODE )
	{
		Player *player = new Player(playerpointer);
		if (playerpointer)
			Server::Console::WriteBlack("GameStart Player %s Entered",player->GetName());
		delete player; player = 0;
	}

	if (conf->DEBUG_MODE)
		Server::Console::WriteBlack("GameStart Write Welcome Message");

	if ( conf->Weclome_Message != "" && conf->Weclome_Message != "0")
		Server::CPlayer::Write(playerpointer, 15,"s",conf->Weclome_Message.c_str());


	if (conf->DEBUG_MODE)
		Server::Console::WriteBlack("GameStart Write PlayerOn Message");

	if ( conf->PLAYERON_MSG )
	{
		MainPlayer *main = new MainPlayer();
		int online = main->PlayerOnline();
		std::string online_message = "There are "+convertToInt(online)+" Players Online";
		Server::CPlayer::Write(playerpointer, 15,"s",online_message.c_str());
		delete main; main = 0;
	}

	if (this->playerpointer)
	{
		Player *player = new Player(playerpointer);
		if (player)
		{
			if ( player->GetAdmin() >= 1 )
			{
				Server::CChar::AddMState(playerpointer,524288,0);
			}
		}
		delete player; player = 0;

	}

	if (this->playerpointer)
	{
		if (conf->DEBUG_MODE)
			Server::Console::WriteBlack("GameStart ProtectS Checks");

		Player *player = new Player(this->playerpointer);
		CSocket *csocket = new CSocket(player->GetSocket());
		MadSockExt *p = static_cast<MadSockExt*>(csocket->GetExTPointer());
		if ( p && ( !p->engine_check_passed || !p->configpk_check_passed || !p->epk_check_passed || !p->hwid_check_passed || !p->ip_check_passed || !p->madhelp_check_passed ) )
		{
			Server::Console::WriteRed("[MadProtectS %s did not passed the GameStart check HWID blocked or Checksums wrong kicked]",player->GetName());
			player->Kick();
		}
		delete player, csocket; player ,csocket = 0;
	}

	if ( conf->DEBUG_MODE )
	{
		Player *player = new Player(playerpointer);
		if (playerpointer)
			Server::Console::WriteBlack("GameStart Player %s Leave",player->GetName());
		delete player; player = 0;
	}
}

void IMadGameStart::Run()
{
	
	this->RunIt();

}