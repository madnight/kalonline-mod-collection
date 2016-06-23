
#include <string>
#include <vector>

#pragma once

class IMadConf
{
public:
	int SHA_ENABLED;
	std::string Engine_SHA;
	std::string MadHelp_SHA;
	std::string Epk_SHA;
	std::string Configpk_SHA;

	int MAX_ATTACK;
	int MAX_FINAL_DAMAGE;
	int MAX_MOVE_SPEED;
	int UG_OG_CHECK;
	int MAX_Z_VALUE;
	int MIN_Z_VALUE;
	int PLAYERON_MSG;
	int CLIENT_SPEEDCHECK;
	int HWID_ENABLED;
	int DEBUG_MODE;
	int CHAT_LOG;
	int START_TIME;
	int CALLER_CHECK;
	int PACKET_VERIFY;
	int EXCEPTION_REPORT;
	int JOB_HACK_CHECK;

	int ACCESS_VIOLATION_TEST;
	int INTEGER_DIVISION_BY_ZERO_TEST;

	int MESSAGE_DELAY;
	std::vector<std::string> MESSAGES;

	std::string Weclome_Message;
	std::string Database_Name;

	unsigned char *order;

	int* packet_decode;

	IMadConf(){}
	~IMadConf(){}
};
