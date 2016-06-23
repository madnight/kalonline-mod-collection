
#include <string>
#include <vector>

#pragma once

class MadSockExt
{
public:
	int offset;
	int engine_check_passed;
	int configpk_check_passed;
	int epk_check_passed;
	int madhelp_check_passed;
	int hwid_check_passed;
	int ip_check_passed;
	int packet_counter;

	MadSockExt(int off)
	{
		this->offset = off;
		this->engine_check_passed = 0;
		this->configpk_check_passed = 0;
		this->epk_check_passed = 0;
		this->madhelp_check_passed = 0;
		this->hwid_check_passed = 0;
		this->ip_check_passed = 0;
		this->packet_counter = -1;
	}
	~MadSockExt(){}
};
