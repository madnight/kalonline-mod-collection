
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
