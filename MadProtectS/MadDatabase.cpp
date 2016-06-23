#include "IMadDatabase.h"


string convertInt(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}

std::string ReplaceString(std::string subject, const std::string& search, const std::string& replace) 
{
		size_t pos = 0;
		while ((pos = subject.find(search, pos)) != std::string::npos) 
		{
			subject.replace(pos, search.length(), replace);
			pos += replace.length();
		}
		return subject;
}

void IMadDatabase::Load_Config_MadProtectS()
{
	CIniReader *reader = new CIniReader(".\\MadProtectS.txt");
	std::ostringstream header;	
	header << "Protect";

	conf->SHA_ENABLED = reader->ReadInteger(MAD_CONST(header),"Checksum",0);
	conf->HWID_ENABLED = reader->ReadInteger(MAD_CONST(header),"HardwareID",0);
	conf->CLIENT_SPEEDCHECK = reader->ReadInteger(MAD_CONST(header),"SpeedCheck",0);
	conf->MAX_ATTACK = reader->ReadInteger(MAD_CONST(header),"MaxAttack",6000);
	conf->MAX_FINAL_DAMAGE = reader->ReadInteger(MAD_CONST(header),"MaxDamage",20000);
	conf->MAX_MOVE_SPEED = reader->ReadInteger(MAD_CONST(header),"MaxSpeed",800);
	conf->UG_OG_CHECK = reader->ReadInteger(MAD_CONST(header),"UgOgCheck",0);
	conf->MAX_Z_VALUE = reader->ReadInteger(MAD_CONST(header),"MaxZ",6000);
	conf->MIN_Z_VALUE = reader->ReadInteger(MAD_CONST(header),"MinZ",200);
	conf->CALLER_CHECK = reader->ReadInteger(MAD_CONST(header),"CallerCheck",0);
	conf->JOB_HACK_CHECK = reader->ReadInteger(MAD_CONST(header),"JobHackCheck",0);

	std::ostringstream misc;	
	misc << "Misc";

	conf->Weclome_Message = reader->ReadString(MAD_CONST(misc),"WelcomeMsg","");
	conf->PLAYERON_MSG = reader->ReadInteger(MAD_CONST(misc),"PlayerOnMsg",0);
	conf->CHAT_LOG  = reader->ReadInteger(MAD_CONST(misc),"ChatLog",0);
	conf->EXCEPTION_REPORT = reader->ReadInteger(MAD_CONST(misc),"ExceptionReport",0);
	conf->Database_Name = reader->ReadString(MAD_CONST(misc),"DatabaseName","kal_db");//ReplaceString(reader->ReadString(MAD_CONST(misc),"DatabaseName","kal_db")," ","");
	
	std::ostringstream checksum;	
	checksum << "Checksum";

	conf->Engine_SHA  = reader->ReadString(MAD_CONST(checksum),"Engine","");
	conf->MadHelp_SHA  = reader->ReadString(MAD_CONST(checksum),"MadHelp","");
	conf->Epk_SHA  = reader->ReadString(MAD_CONST(checksum),"Epk","");
	conf->Configpk_SHA  = reader->ReadString(MAD_CONST(checksum),"Configpk","");

	std::ostringstream announcement;	
	announcement << "Announcement";
	//
	conf->MESSAGE_DELAY = reader->ReadInteger(MAD_CONST(announcement),"Delay",0);
	conf->MESSAGES = reader->ReadStringSection("Announcement");

	conf->MESSAGES.erase(conf->MESSAGES.begin()); // Delete Delay Attribute
	for (std::vector<std::string>::iterator it = conf->MESSAGES.begin() ; it != conf->MESSAGES.end(); ++it)
	{
		*it = ReplaceString(*it,"Message = ","");*it = ReplaceString(*it,"Message =","");*it = ReplaceString(*it,"Message=","");
	}
	delete reader, reader = 0;
}

void IMadDatabase::MadDatabaseSaveIP(int UID, std::string ip)
{
	std::stringstream sqlstatement;
	sqlstatement << "UPDATE MadDB SET IP = '"; 
	sqlstatement << ip;
	sqlstatement << "' WHERE UID = ";
	sqlstatement << UID;
	sqlstatement << " if @@rowcount = 0  begin INSERT into MadDB (UID, IP) VALUES (";
	sqlstatement << UID;
	sqlstatement << " ,'";
	sqlstatement << ip;
	sqlstatement << "') end";
	database->Execute((sqlstatement.str().c_str()),true);
}

void IMadDatabase::MadDatabaseSaveName(int UID, std::string name)
{
	std::stringstream sqlstatement;
	sqlstatement << "UPDATE MadDB SET PC = '"; 
	sqlstatement << name;
	sqlstatement << "' WHERE UID = ";
	sqlstatement << UID;
	sqlstatement << " if @@rowcount = 0  begin INSERT into MadDB (UID, PC) VALUES (";
	sqlstatement << UID;
	sqlstatement << " ,'";
	sqlstatement << name;
	sqlstatement << "') end";
	database->Execute((sqlstatement.str().c_str()),true);
}

void IMadDatabase::MadDatabaseSaveConsoleLog(std::string console_log)
{
	std::stringstream sqlstatement;
	sqlstatement << "INSERT into MadConsole (CONSOLE,TIME) VALUES ('"; 
	sqlstatement << console_log;
	sqlstatement << "' ,";
	sqlstatement << "CURRENT_TIMESTAMP";
	sqlstatement << ")";
	database->Execute((sqlstatement.str().c_str()),true);
}



void IMadDatabase::MadDatabaseSaveHWID(int UID, std::string hwid)
{
	std::stringstream sqlstatement;
	sqlstatement << "UPDATE MadDB SET HWID = '"; 
	sqlstatement << hwid;
	sqlstatement << "' WHERE UID = ";
	sqlstatement << UID;
	sqlstatement << " if @@rowcount = 0  begin INSERT into MadDB (UID, HWID) VALUES (";
	sqlstatement << UID;
	sqlstatement << " ,'";
	sqlstatement << hwid;
	sqlstatement << "') end";
	database->Execute((sqlstatement.str().c_str()),true);
}

void IMadDatabase::MadDatabaseSaveHWID(std::string hwid)
{
	std::stringstream sqlstatement;
	sqlstatement << "UPDATE MadDB SET HWID = '"; 
	sqlstatement << hwid;
	sqlstatement << "' WHERE HWID = '";
	sqlstatement << hwid;
	sqlstatement << "' if @@rowcount = 0  begin INSERT into MadDB (HWID) VALUES ('";
	sqlstatement << hwid;
	sqlstatement << "') end";
	database->Execute((sqlstatement.str().c_str()),true);
}


void IMadDatabase::MadDatabaseSaveChat(int PID, std::string playername, std::string post)
{
	std::stringstream sqlstatement;
	sqlstatement << "INSERT into MadChat (PID, PLAYER, CHAT, TIME) VALUES ("; 
	sqlstatement << PID;
	sqlstatement << " ,'";
	sqlstatement << playername;
	sqlstatement << "' ,'";
	sqlstatement << post;
	sqlstatement << "' ,";
	sqlstatement << "CURRENT_TIMESTAMP";
	sqlstatement << ")";
	//Server::Console::WriteRed("%s",sqlstatement.str().c_str());
	database->Execute((sqlstatement.str().c_str()),true);
}

void IMadDatabase::MadDatabaseSaveBlock(int UID, bool block)
{
	int iblock = 0;
	if (block)
		iblock = 1;

	std::stringstream sqlstatement;
	sqlstatement << "UPDATE MadDB SET BLOCK = '"; 
	sqlstatement << iblock;
	sqlstatement << "' WHERE UID = ";
	sqlstatement << UID;
	sqlstatement << " if @@rowcount = 0  begin INSERT into MadDB (UID, BLOCK) VALUES (";
	sqlstatement << UID;
	sqlstatement << " , ";
	sqlstatement << iblock;
	sqlstatement << ") end";
	database->Execute((sqlstatement.str().c_str()),true);
}

void IMadDatabase::MadDatabaseSaveBlock(std::string hwid, bool block)
{
	int iblock = 0;
	if (block)
		iblock = 1;

	std::stringstream sqlstatement;
	sqlstatement << "UPDATE MadDB SET BLOCK = '"; 
	sqlstatement << iblock;
	sqlstatement << "' WHERE HWID = '";
	sqlstatement << hwid;
	sqlstatement << "'";
	database->Execute((sqlstatement.str().c_str()),true);
}

bool IMadDatabase::CheckBlock(std::string hwid)
{
	std::stringstream sqlstatement;
	sqlstatement << "SELECT COUNT (BLOCK) FROM MadDB WHERE HWID ='"; 
	sqlstatement << hwid;
	sqlstatement << "'";
	sqlstatement << " AND BLOCK = 1";
	int blocked = database->Execute((sqlstatement.str().c_str()),false);
	if (blocked >= 1)
		return true;
	return false;
}

bool IMadDatabase::CheckBlockIP(std::string ip)
{
	std::stringstream sqlstatement;
	sqlstatement << "SELECT COUNT (BLOCK) FROM MadDB WHERE IP ='"; 
	sqlstatement << ip;
	sqlstatement << "'";
	sqlstatement << " AND BLOCK = 1";
	int blocked = database->Execute((sqlstatement.str().c_str()),false);
	if (blocked >= 1)
		return true;
	return false;
}

bool IMadDatabase::CheckBlockUID(int UID)
{
	std::stringstream sqlstatement;
	sqlstatement << "SELECT BLOCK FROM MadDB WHERE UID = "; 
	sqlstatement << UID;
	int blocked = database->Execute((sqlstatement.str().c_str()),false);
	if (blocked == 1)
		return true;
	return false;
}

bool IMadDatabase::MadDatabaseUIDExist(int UID)
{
	std::stringstream sqlstatement;
	sqlstatement << "SELECT COUNT (UID) FROM MadDB WHERE UID = "; 
	sqlstatement << UID;
	int exist = database->Execute((sqlstatement.str().c_str()),false);
	if (exist >= 1)
		return true;
	return false;
}