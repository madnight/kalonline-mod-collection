
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
