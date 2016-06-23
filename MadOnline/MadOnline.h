#include <Windows.h>
#include <sstream>
#include <Database.h>
#include <MadCore.h>
#include <Memory.h>
#include <MainPlayer.h>
#include <IniReader.h>


class AfkItemEvent
{
public:
	int ItemIndex;
	int amount;
	int seconds;

	AfkItemEvent(int mi,int a,int s)
	{
		this->ItemIndex = mi;
		this->amount = a;
		this->seconds = s;
	}  

};


std::vector<AfkItemEvent> AfkItem_Events;

namespace MadOnline
{

	void Load_Config()
	{
		CIniReader *reader = new CIniReader(".\\MadAFKItem.txt");
		int counter = 0;
		AfkItem_Events.clear();
		for (int i = 1; i<500;i++)
		{
			std::ostringstream header;	
			header << "Item " << i;

			int ItemIndex = reader->ReadInteger(MAD_CONST(header),"index",0);
			int amount = reader->ReadInteger(MAD_CONST(header),"amount",0);
			int seconds = reader->ReadInteger(MAD_CONST(header),"seconds",0);

			if (ItemIndex != 0 && amount != 0 && seconds != 0)
			{
				AfkItem_Events.push_back(AfkItemEvent(ItemIndex,amount,seconds));
				counter++;
			}
		}
		Server::Console::WriteBlue("[MadAFKItem started installed %d Items]",counter);
		delete reader;
	}

	Database *database = new Database;
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);	
			//	Server::Console::WriteBlue("[MadOnline connect to Database...]");
			//	Server::Console::WriteBlue(database->Connect());
			Load_Config();
			//Server::Console::WriteBlue("[MadAFKItem System (made by MadKnight)]");
			//	IMemory *Memory = new IMemory;
			//	Memory->Fill(0x0044DA11,0x1E,1);//30 er Party
			//	delete Memory;
		}
	}

	namespace CGuild
	{     // disbale Alliance System
		signed int __fastcall AllianceOffer(void *thisp,  void *_edx ,int a2, const char *a3, signed int a4)
		{
			return 60;
		}
	}

	namespace CPlayerSkill
	{    // Tranformcrash fix (disable egg skills)
		void __fastcall ExcuteTransformSkill(void *thisp,  void *_edx, signed int a2, int a3, int a4)
		{
		}
	}


	namespace CPlayer
	{
		void __fastcall ChatCommand(void *thispointer,  void *_edx, char *comm)
		{
			Player player(thispointer);
			Command command(comm);

			if(player.isAdmin())
			{
				if (command.beginWith("/reloadafkitem"))
				{
					Load_Config();
					Server::Console::WriteBlue("[MadAfkItem config reloaded]");
				}
			}
			Server::CPlayer::ChatCommand(thispointer,comm);
		}
	}

	namespace CPlayerObject
	{

		static int counter = 1;
		void __stdcall OnTimer(int a1)
		{
			Server::CPlayerObject::OnTimer(a1);

			for (int i = 0; i <AfkItem_Events.size();i++)
			{
				if (counter%AfkItem_Events.at(i).seconds == 0)
				{
					ENTER_CRIT
						PLAYER_LIST_ITERATE
					{
						Player *player = new Player(PLAYER_POINTER);
						player->InsertItem(AfkItem_Events.at(i).ItemIndex,AfkItem_Events.at(i).amount); 
						delete player;
					}
					LEAVE_CRIT
				}
			}
			counter++;
		}

		/**
		static int i = 1;
		void __stdcall OnTimer(int a1)
		{
		Server::CPlayerObject::OnTimer(a1);
		if(i%3600 == 0) //3600
		{
		//	std::stringstream sqlstatement;
		//sqlstatement << "UPDATE Player SET Online = (CASE WHEN PID = 545";
		ENTER_CRIT
		PLAYER_LIST_ITERATE
		{
		Player *player = new Player(PLAYER_POINTER);
		//	sqlstatement << " OR PID = " << player->GetPid();
		//	player->InsertItem(31,3500);
		//	player->InsertItem(5027,1);
		player->InsertItem(237,75); //XEA
		delete player;
		}
		LEAVE_CRIT
		//	sqlstatement << " THEN 1 ELSE 0 END), Min = (CASE WHEN Online = 1 THEN Min + 1 ELSE Min END)";
		//	database->Execute((sqlstatement.str().c_str()),true);
		i = 1;
		}
		i++;
		}
		**/
	}
}