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