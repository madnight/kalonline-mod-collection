#include <Windows.h>
#include "../Server.h"
#include "Utilities.h"

namespace MadWord
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Server::Console::WriteBlue("[MadWord started]");
		}
	}
	namespace Console
	{
		void __cdecl WriteBlack(char* text,  ...)
		{
			readConfig();
			if (!checkWords((string) text))
			{
				va_list va;
				va_start(va,text);
				Server::Console::Write(1,text,va);
			}
		}
		void __cdecl WriteRed(char* text,  ...)
		{
			if (!checkWords((string) text))
			{
				va_list va;
				va_start(va,text);
				Server::Console::Write(2, text, va);
			}
		}
		void __cdecl WriteBlue(const char* text,  ...)
		{	
			if (!checkWords((string) text))
			{
				va_list va;
				va_start(va,text);
				Server::Console::Write(0,text,va);
			}
		}
	}
}