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
#include "Utilities.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


namespace MadEvent 
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			readConfig();
			Server::Console::WriteBlue("[MadEvent started]");
		}
	}
	namespace CPlayerObject
	{
		void __stdcall OnTimer(int a1)
		{
			Server::CPlayerObject::OnTimer(a1);
			EventCheck();
		}
	}
}

	