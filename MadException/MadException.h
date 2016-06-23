

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN            

#include <windows.h>

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <process.h>
#include <ctime>
#include <vector>
#include "../Server.h"

namespace MadException 
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Server::Console::WriteBlue("[MadException started]");
		}
	}
	namespace CIOSocket
	{
		int threadid = 103;
		void __cdecl IOThread(void *params)
		{
			__try
			{
				Server::CIOSocket::IOThread(params);
			}
			__except(EXCEPTION_EXECUTE_HANDLER) 
			{
				Server::Console::WriteRed("An low level Exception was caught by IOThread top level filter");  //. Error Report stored in MadDebug Folder. Exception reason was %s",RecordException::GetExceptionType(GetExceptionCode())                                      
				int thread = Server::CIOSocket::AddIOThread(threadid++);
				if (thread)
					++*(DWORD *)0x004E1190;
			}
		}	
	}
}
