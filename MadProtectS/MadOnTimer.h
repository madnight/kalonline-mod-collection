
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
