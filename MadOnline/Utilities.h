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

