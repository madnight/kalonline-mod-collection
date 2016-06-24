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
 
#include "MainPlayer.h"
using namespace std;


int MainPlayer::PlayerOnline()
{
	int i = 0;
	ENTER_CRIT
		PLAYER_LIST_ITERATE
	{
		i++;
	}
	LEAVE_CRIT
		return i;
}

Player* MainPlayer::FindPlayerByName(std::string name)
{
	ENTER_CRIT
		PLAYER_LIST_ITERATE
	{
		Player *player = new Player(PLAYER_POINTER);
		if (strcmp(player->GetName(),name.c_str()) == 0)
		{
			LEAVE_CRIT
				return player;
		}
	}
	LEAVE_CRIT
		return NULL;
}


void MainPlayer::Notice(char* notice)
{
	Server::CPlayer::WriteAll(15,"s",notice);
}