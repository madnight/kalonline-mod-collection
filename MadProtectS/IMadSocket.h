#include <string>
#include <MainPlayer.h>
#include <Database.h>
#include "IMadConf.h"
#include "IMadDatabase.h"
#include "MadSockExt.h"
#include "ExceptionHandler.h"
#include "WinAES.h"
#include <iostream>

#define HEADER *(unsigned char*)(this->Data+2)
#define DATA (char*)(this->Data+3)
#define SIZE *(WORD *)this->Data
#define DATAEND (int)(*(unsigned short*)Data -3) 
#define SIZE_LIMIT 1100
#define SHA_PACKET_SIZE 132
#define PACKET_DEBUG_PRINT_SIZE 30
#define CRYPT_OFF_PRIM 467
#define MAX_BUFFER_SIZE 8000

#define SHA_ENGINE_HEADER 0x01
#define SHA_MADHELP_HEADER 0x02
#define SHA_EPK_HEADER 0x03
#define SHA_CONFIGPK_HEADER 0x04
#define HWID_HEADER 0x06
#define SPEED_HEADER 0x07
#define PCNAME_HEADER 0x08
#define IP_HEADER 0x09

class IMadSocket
{
public:
	IMadSocket(void *s, char* d,IMadConf *c,Database *db) 
	{
		this->Socket = s;
		this->Data = d;
		this->conf = c;
		this->database = db;
		this->offset = 0;
		this->forward = true;
		this->csocket = new CSocket(s);
		this->killed = false;
	}  
	~IMadSocket()
	{
		delete this->csocket;
	}
	bool Run();
private:
	void *Socket;
	char *Data;

	IMadConf *conf;
	Database *database;
	CSocket *csocket; 

	int offset;
	bool forward;
	bool killed;
	
	bool Blocked(std::string hwid);
	bool BlockedIP(std::string ip);
	bool PreCheck();
	unsigned char Decrypt(unsigned char data);
	void CallerCheck();
	void PacketCounterCheck();
	void DebugPrintRecvCrypted();
	void DebugPrintRecvUncrypt();
	void ExecutionSpeedMeasurment(int i);
	void HWIDCheck(std::string hwid);
	void HeaderCheck();

	void SHACheck(std::string sha, int sha_id);
	void PCNameCheck(std::string name);
	void IPCheck(std::string ip);
	void LogChat();
	void PacketDecrypt();
	void SaveKill();
	void SetOffset();
	void SpeedCheck();
	void ProtectCheck();
};
