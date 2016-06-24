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
 

#include <string>
#include <MainPlayer.h>
#include <fstream>
#include <IniReader.h>
#include <Database.h>
#include "IMadConf.h"
#include <algorithm>  


#pragma once

class IMadDatabase
{
private:
	IMadConf *conf;
	Database *database;;

public:
	IMadDatabase(IMadConf *c,Database *db)
	{
		this->conf = c;
		this->database = db;
	}  

	void Run();
	void Load_Config_MadProtectS();
	void MadDatabaseSaveName(int UID, std::string name);
	void MadDatabaseSaveHWID(int UID, std::string hwid);
	void MadDatabaseSaveHWID(std::string hwid);
	void MadDatabaseSaveBlock(int UID, bool block);
	void MadDatabaseSaveBlock(std::string hwid, bool block);
	void MadDatabaseSaveConsoleLog(std::string console_log);
	bool CheckBlock(std::string hwid);
	bool CheckBlockIP(std::string ip);
	bool CheckBlockUID(int UID);
	bool MadDatabaseUIDExist(int UID);
	void MadDatabaseSaveChat(int PID, std::string playername, std::string post);
	void MadDatabaseSaveIP(int UID, std::string ip);
	~IMadDatabase(){}
};

