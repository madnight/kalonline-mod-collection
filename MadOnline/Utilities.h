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
 
#include <fstream>
#include <string>
#include <sstream>
#include <Database.h>
#include <Memory.h>
#include <MainPlayer.h>
#pragma comment(lib, "MadLib.lib")



void OnlineCheck()
{
//	std::stringstream sqlstatement;
//	sqlstatement << "UPDATE Player SET Online = (CASE WHEN PID = 545";
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
//	Database *database = new Database;
//	database->Execute((sqlstatement.str().c_str()),true);
//	delete database;
}

