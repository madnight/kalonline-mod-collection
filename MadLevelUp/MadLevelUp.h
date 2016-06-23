#include "Utilities.h"
#include <MainPlayer.h>
#include <sstream>

namespace MadLevelUp 
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			readConfig();
			Server::Console::WriteBlue("[MadLevelUp started]");
		}
	}

	void __fastcall LevelUp(void *thispointer,void* _edx)
	{
		Server::CPlayer::LevelUp(thispointer);
		Player player(thispointer);
		std::ostringstream consolepost;	
		for (unsigned int i=0; i<levelrewardvec.size(); i++) 
		{
			if (levelrewardvec[i].level == player.GetLevel())
			{
				player.InsertItem(levelrewardvec[i].item_index, levelrewardvec[i].item_amount);
				consolepost << "[MadLevelUp reward given to " << player.GetName() << " ]";
				Server::Console::WriteBlue(MAD_CONST(consolepost));
			}
		}
	}
}