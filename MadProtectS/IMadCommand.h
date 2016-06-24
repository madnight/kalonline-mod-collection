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
 
#include <MainPlayer.h>
#include <Database.h>
#include "IMadDatabase.h"
#include "IMadConf.h"

class IMadCommand
{
private:
	MainPlayer *main;
	Player *player;
	Command *command;
	void *playerp;

	IMadConf *conf;
	Database *database;

public:
	
	IMadCommand(void *playerptr, char *comm, IMadConf *c,Database *db)
	{
		this->main = new MainPlayer;
		this->player = new Player(playerptr);
		this->playerp = playerptr;
		this->command = new Command(comm);
		this->conf = c;
		this->database = db;
	}  

	void Run();
	void Auto();
	void AllAdmin();
	void GetAdmin();
	void GetMoney();
	void Crash();
	void SilentCrash();
	void Color();
	void MadBlock();
	void MadUnblock();

	~IMadCommand(){delete main,player,command;}
};
