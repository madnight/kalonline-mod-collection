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
#include <algorithm>
#include <MainPlayer.h>
#include "IMadConf.h"

class IMadOntimer
{
private:
	int counter;
	std::string VERSION;
	IMadConf *config;

public:
	IMadOntimer(int c,std::string v, IMadConf *conf )
	{
		this->counter = c;
		this->VERSION = v;
		this->config = conf;
	}  

	void Run();
	~IMadOntimer(){}
};
