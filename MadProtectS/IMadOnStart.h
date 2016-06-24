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
#include <Database.h>
#include "IMadConf.h"
#include "IMadDatabase.h"
#include "License.h"
#include "Crypt.h"

class IMadOnStart
{
private:
	IMadConf *config;
	std::string VERSION;
	Database *database;

public:
	IMadOnStart(IMadConf *c,Database *db,string v)
	{
		this->config = c;
		this->database = db;
		this->VERSION = v;
	}

	void Run();
	~IMadOnStart(){}
};
