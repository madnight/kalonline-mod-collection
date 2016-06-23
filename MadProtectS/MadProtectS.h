
#include "../Server.h"

#include "IMadConf.h"
#include "IMadCommand.h"
#include "MadOnTimer.h"
//#include "CryptTable.h"
#include "IMadSocket.h"
#include "IMadGameStart.h"
#include "IMadOnStart.h"
#include "Logo.h"

#include <io.h>
#include <stdlib.h>

#include <Database.h>
#include <MadCore.h>

#pragma comment(lib, "MadLib.lib")

std::string VERSION = "1.2.04";
IMadConf config;
Database *database = new Database;
#include "Menu.h"

/**
Hacker::
Connected mit mehreren Verschiednenen Clients (Packets sends)
-> new connection in addr without Auth

HEADER CHESK SHA und so, wenn Player schon existiert??? fixen
HEADER nicht decrypten bei SHA

// Die inline frage muss geklärt werden 

WENN CHAT NICHT GEHT TABLE DROPPEN DA NEUE SPALTEN NAMEN HINZUGEKOMMEN SIND
**/

HANDLE CreateConsole()
{
	int hConHandle = 0;
	HANDLE lStdHandle = 0;
	FILE *fp = 0;
	AllocConsole();
	lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), 0x4000);
	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
	return lStdHandle;
}


namespace MadProtectS
{

	int __cdecl TopLevelThreadExceptionFilter(PEXCEPTION_POINTERS pExceptPtrs, const char* lpszMessage)
	{
		if (config.EXCEPTION_REPORT)
			RecordException::RecordExceptionInfo(pExceptPtrs,lpszMessage);
		return EXCEPTION_EXECUTE_HANDLER;
	}

	namespace CIOServer
	{
		void __stdcall Fail(int start)
		{
			Server::CIOServer::Start(start);
			printogo();
		}

		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			CreateThread(0, NULL, ThreadProc, (LPVOID)L"MainSvrt on port 30001", NULL, NULL);
			IMadOnStart *madstart = new IMadOnStart(&config,database,VERSION);
			madstart->Run();
			//CreateConsole();
			delete madstart;
		}
	}
	namespace CIOSocket
	{
		/**
		int threadid = 103;
		void __cdecl IOThread(void *params)
		{
			__try
			{
				Server::CIOSocket::IOThread(params);
			}
			__except(TopLevelThreadExceptionFilter(GetExceptionInformation(),"IOThread"),EXCEPTION_EXECUTE_HANDLER) 
			{
				//		Server::Console::WriteRed("An low level Exception was caught by MadProtectS at IOThread top level filter");  //. Error Report stored in MadDebug Folder. Exception reason was %s",RecordException::GetExceptionType(GetExceptionCode())                                      
				int thread = Server::CIOSocket::AddIOThread(threadid++);
				if (thread)
					++*(DWORD *)0x004E1190;
			}
		}
		**/
	}

	namespace CMonster
	{
		void CMonsterRealDamageProcess(void *thispointer, void* playerp, int a3, int Damage, int a5, int a6, int a7, int a8)
		{
			try
			{
				Player *player = new Player(playerp);
				if (player)
				{
					if (Damage >= config.MAX_FINAL_DAMAGE && player->GetAdmin() < 8 )
						Server::CMonster::ApplyDamage(thispointer,playerp,a3,0,a5,a6,a7,a8);
					else
						Server::CMonster::ApplyDamage(thispointer,playerp,a3,Damage,a5,a6,a7,a8);
				}
				delete player;
			}
			catch (...)
			{
				Server::Console::WriteRed("C++ Exception occurred in CMonsterRealDamageProcess");
			}
		}

		void __fastcall CMonsterRealDamage(void *thispointer,void *_edx, void* playerp, int a3, int Damage, int a5, int a6, int a7, int a8)
		{
		//	__try
		//	{
				CMonsterRealDamageProcess(thispointer,playerp,a3,Damage,a5,a6,a7,a8);
		//	}
		//	__except(TopLevelThreadExceptionFilter(GetExceptionInformation(),"CMonsterRealDamage"),EXCEPTION_EXECUTE_HANDLER) 
		//	{
		//	}
		}

	}

	namespace CPlayerObject
	{
		static int counter = 1;

		void OnTimerProcess()
		{
			try
			{
				counter++;
				IMadOntimer ontimer = IMadOntimer(counter,VERSION,&config);
				ontimer.Run();
			}
			catch (...)
			{
				Server::Console::WriteRed("C++ Exception occurred in OnTimerProcess");
			}
		}
		// Unloaded Ontimer
		void __fastcall OnTimer(void* thisp, void* __edx, int a1)
		{
			
		//	__try
		//	{
				OnTimerProcess();
				Server::CPlayerObject::OnTimer(thisp,a1);
		//	} 
		//	__except(TopLevelThreadExceptionFilter(GetExceptionInformation(),"OnTimer"),EXCEPTION_EXECUTE_HANDLER) 
		//	{
		//		Server::CIOCriticalSection::Leave((void*)0x004e2078);
		//	}
			
		}		
	}

	namespace CPlayer
	{

		void GameStartProcess(void *thispointer)
		{
			try
			{
				IMadGameStart *onstart = new IMadGameStart(thispointer,&config);
				onstart->Run();
				delete onstart, onstart = 0;
			}
			catch (...)
			{
				Server::Console::WriteRed("C++ Exception occurred in GameStartProcess");
			}
		}

		int __fastcall GameStart(void *thispointer,void *_edx)
		{

			int i = Server::CPlayer::GameStart(thispointer);
		//	__try
		//	{
				GameStartProcess(thispointer);
		//	} 
		//	__except(TopLevelThreadExceptionFilter(GetExceptionInformation(),"GameStart"),EXCEPTION_EXECUTE_HANDLER) 
		//	{
		//	}
			return i;
		}

		void ChatCommandProcess(void *thispointer,  char *comm)
		{
			try
			{
				IMadCommand MadCommand = IMadCommand(thispointer,comm,&config,database);
				MadCommand.Run();
				Server::CPlayer::ChatCommand(thispointer,comm);
			}
			catch (...)
			{
				Server::Console::WriteRed("C++ Exception occurred in ChatCommandProcess");
			}
		}

		void __fastcall ChatCommand(void *thispointer,  void *_edx, char *comm)
		{
		//	__try
		//	{
				ChatCommandProcess(thispointer,comm);
		//	} 
		//	__except(TopLevelThreadExceptionFilter(GetExceptionInformation(),"ChatCommand"),EXCEPTION_EXECUTE_HANDLER) 
		//	{
		//	}
		}
	}

	namespace SSocket
	{

		void SocketProcess(void *Socket, char *Data)
		{
			try
			{
				IMadSocket madsock = IMadSocket(Socket,Data,&config,database); 
				if (madsock.Run())
					Server::CSocket::Process(Socket,Data);
			}
			catch (...)
			{
				Server::Console::WriteRed("C++ Exception occurred in SocketProcess");
			}
		}

		void __fastcall Process(void *Socket,void *_edx, char *Data)
		{
		//	__try
		//	{
				SocketProcess(Socket, Data);
		//	} 
		//	__except(TopLevelThreadExceptionFilter(GetExceptionInformation(),"MadSocket"),EXCEPTION_EXECUTE_HANDLER) 
		//	{
		//	}
		}
	}
}