#include <fstream>
#include <string>
#include <sstream>
#include <windows.h> 
#include <MainPlayer.h>
#include <Summon.h>
#include <Log.h>
#include <Command.h>
#include <Memory.h>
#include <MadCore.h>
#include <time.h>

#pragma comment(lib, "MadLib.lib")



class IMadCommand
{
private:
	MainPlayer *main;
	Player *player;
	Command *command;
	void *playerp;

	int coordinatepointer[1];
	void* monsterpointer;
	int uptime;

public:
	IMadCommand(){};
	IMadCommand(void *playerptr, char *comm, unsigned int total)
	{
		this->main = new MainPlayer;
		this->player = new Player(playerptr);
		this->playerp = playerptr;
		this->command = new Command(comm);

		this->coordinatepointer[0] = 20187;
		this->coordinatepointer[1] = 66717;
		this->uptime = total;
	}  
	void Run();
	void PortRandom();
	void SetSpeed();
	void ShowIP();
	void PortUserAll();
	void GetMoney();
	void PartyOn();
	void PartyOff();
	void SetLevel();
	void Debug();
	void PlayerOn();
	void ExpNeed();
	void KickMe();
	void Spawn();
	void Spawn_Alt();
	void Mad();
	void PortTo();
	void Uptime();
	void Coordinates();
	void __stdcall Start(int start); 

	~IMadCommand(){delete main,player,command;}
};

namespace 
{
	namespace MadCommand
	{
		unsigned int totaluptime;
		
		namespace CIOServer 
		{ 
			void __stdcall Start(int start)
			{
				Server::CIOServer::Start(start);
				Server::Console::WriteBlue("[MadCommand started]");
				totaluptime = GetTickCount();
			}

			void __stdcall AfterStart(char *s,int port,int year,int mon, int day, int hour,int min, int sec)
			{
				Server::Console::WriteBlack(s,port,year,mon,day,hour,min,sec);
				IMemory *Memory = new IMemory;
				Memory->Fill(0x0046349A, IMemory::_I_NOP, 5);	
				delete Memory;
			}

		}
		namespace CPlayer
		{
			IMadCommand *MadCommand;
			void __fastcall ChatCommand(void *thispointer,  void *_edx, char *comm)
			{
				IMadCommand *MadCommand = new IMadCommand(thispointer,comm,totaluptime);
				MadCommand->Run();
				delete MadCommand;
				Server::CPlayer::ChatCommand(thispointer,comm);
			}
		}
	}
};