#include <Windows.h>
#include <sstream>
#include <Command.h>
#include <Player.h>
#include <Database.h>
#include <MadCore.h>
#include <sstream>

#pragma comment(lib, "MadLib.lib")

namespace MadReborn
{
	Database *database = new Database;
	namespace CIOServer
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Server::Console::WriteBlue("[MadReborn connect to Database...]");
			Server::Console::WriteBlue(database->Connect());
		}
	}

	namespace CPlayer
	{
		void __fastcall ChatCommand(void *thispointer,  void *_edx, char *comm)
		{
			Player *player = new Player(thispointer);
			Command *command = new Command(comm);
			std::ostringstream chatpost;	
			chatpost << player->GetName();
			Server::Console::WriteBlue(MAD_CONST(chatpost));	
			chatpost.str("");
			chatpost.clear();
				chatpost << player->GetRebornName();
				Server::Console::WriteBlue(MAD_CONST(chatpost));
			if (command->beginWith("/reborn") && player->GetLevel() == 111)
			{
				std::stringstream sqlstatement;
				sqlstatement << "UPDATE Player SET Reborn = Reborn + 1";
				sqlstatement << "' WHERE PID =";
				sqlstatement << player->GetPid();
				database->Execute(sqlstatement.str().c_str(),true);
				player->Reborn();
				chatpost.clear();
				chatpost << player->GetName();
				Server::Console::WriteBlue(MAD_CONST(chatpost));
			}
			delete player, command;
			Server::CPlayer::ChatCommand(thispointer,comm);
		}
	}
}