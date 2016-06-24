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
#include "IMadConf.h"
#include "MadSockExt.h"
#include "ExceptionHandler.h"

class IMadGameStart
{
private:
	void *playerpointer;
	IMadConf *conf;

public:
	IMadGameStart(void *p, IMadConf *c)
	{
		this->playerpointer = p;
		this->conf = c;
	}

	void Run();
	void RunIt();
	~IMadGameStart(){}
};
