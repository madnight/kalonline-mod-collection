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
 
#include "MadAI.h"

#include <MadCore.h>
#pragma comment(lib, "MadLib.lib")



BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	//CreateConsole();
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadAI::CIOServer::Start);
	core.Register(&(PVOID&)Server::CMonsterReal::AI, MadAI::CMonsterReal::AI);
	return core.Run();
}