
#include <windows.h>
#include <IniReader.h>
#include <Summon.h>
#include <vector>
#include <ctime>
#include <sstream>
#include <MainPlayer.h>
#include "../Server.h"



class SummonEvent
{
public:
	int MonsterIndex;
	int amount;
	int map;
	int x;
	int y;
	int respawn;
	int duration;
	int day;
	int time;
	char *notice;

	SummonEvent(int mi,int a,int m,int xc, int yc,int re,int dur, int dayn, int timen, char* n)
	{
		this->MonsterIndex = mi;
		this->amount = a;
		this->map = m;
		this->x = xc;
		this->y = yc;
		this->respawn = re;
		this->duration = dur;
		this->day = dayn;
		this->time = timen;
		this->notice = n;
	}  

};

/**
int x1;
int y1;

int x2;
int y2;

if (x2 > x1)
{
int a = x2-x1;
int b = y2-y1;

int random_a = rand()%a; //random zahl von 0 bis a
int random_b = rand()%b; //random zahl von 0 bis b

int spawnx = a+x1;
int spawny = b+y1;

SummonMonster(spawnx,spawny);

}
**/

std::vector<SummonEvent> Summon_Events;

namespace MadSummon
{

	void Load_Config()
	{
		CIniReader *reader = new CIniReader(".\\MadSummon.txt");
		int counter = 0;
		int approx_config_items = (reader->GetFileSize() / 10);
		Summon_Events.clear();
		for (int i = 1; i< approx_config_items ;i++)
		{
			std::ostringstream header;	
			header << "Summon " << i;

			int MonsterIndex = reader->ReadInteger(MAD_CONST(header),"index",0);
			int amount = reader->ReadInteger(MAD_CONST(header),"amount",0);
			int map = reader->ReadInteger(MAD_CONST(header),"map",0);
			int x = reader->ReadInteger(MAD_CONST(header),"xcoord",0);
			int y = reader->ReadInteger(MAD_CONST(header),"ycoord",0);

			int respawn = reader->ReadInteger(MAD_CONST(header),"respawn",0);
			int duration = reader->ReadInteger(MAD_CONST(header),"duration",3600);

			int day = reader->ReadInteger(MAD_CONST(header),"day",0);
			int time = reader->ReadInteger(MAD_CONST(header),"time",0);
			char *notice  = reader->ReadString(MAD_CONST(header),"notice",0);

			if (MonsterIndex != 0 && amount != 0)
			{
				Summon_Events.push_back(SummonEvent(MonsterIndex,amount,map,x,y,respawn,duration,day,time,notice));
				counter++;
			}

		}
		Server::Console::WriteBlue("[MadSummon started installed %d Summon Events]",counter); // (XEAxMaste Edition)
	//	Server::Console::WriteBlue("Filesize %d",	reader->GetFileSize()); 
	
		delete reader;
	}


	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Load_Config();
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
				if (command.beginWith("/reloadsummon"))
				{
					Load_Config();
					Server::Console::WriteBlue("[MadSummon config reloaded]");
				}
			}
			Server::CPlayer::ChatCommand(thispointer,comm);
		}
	}

	namespace CPlayerObject
	{
		static int stoptimer = 0;
		void __stdcall OnTimer(int a1)
		{
			Server::CPlayerObject::OnTimer(a1);

			time_t t = time(0);   
			struct tm * now = localtime(&t);
			int datetime = (now->tm_hour*100)+now->tm_min;
			int weekday = now->tm_wday + 1;
			Summon *summon = new Summon;
			MainPlayer *main = new MainPlayer;

			stoptimer--;

			if (stoptimer < 1)
				for (int i = 0; i <Summon_Events.size();i++)
				{
					if (Summon_Events.at(i).time == datetime)
					{
						if (Summon_Events.at(i).day == 0 || Summon_Events.at(i).day == weekday)
						{
						//	summon->spawn( 
						//		Summon_Events.at(i).MonsterIndex,  Summon_Events.at(i).x,
						//		Summon_Events.at(i).y ,Summon_Events.at(i).map, 
						//		Summon_Events.at(i).amount);
							summon->spwan_alt(Summon_Events.at(i).MonsterIndex,  Summon_Events.at(i).x,
								Summon_Events.at(i).y ,Summon_Events.at(i).map, 
								Summon_Events.at(i).amount,Summon_Events.at(i).duration,Summon_Events.at(i).respawn);
							Server::Console::WriteBlue("[MadSummon: Monster summoned Index: %d Count: %d]",Summon_Events.at(i).MonsterIndex,Summon_Events.at(i).amount);
							main->Notice(Summon_Events.at(i).notice);
							stoptimer = 120;
						}
					}
				}
				delete main;
				delete summon;
		}
	}
}