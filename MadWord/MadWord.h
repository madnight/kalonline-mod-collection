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