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
 
#include "MadWord.h"
#include <MadCore.h>

#include <Memory.h>

#pragma comment(lib, "MadLib.lib")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadWord::CIOServer::Start);
	core.Register(&(PVOID&)Server::Console::WriteBlack, MadWord::Console::WriteBlack);
	core.Register(&(PVOID&)Server::Console::WriteRed, MadWord::Console::WriteRed);
	core.Register(&(PVOID&)Server::Console::WriteBlue, MadWord::Console::WriteBlue);
	return core.Run();
}