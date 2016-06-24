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
 
#include "IMadSocket.h"

bool iequals(const string& a, const string& b)
{
	unsigned int sz = a.size();
	if (b.size() != sz)
		return false;
	for (unsigned int i = 0; i < sz; ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return false;
	return true;
}

unsigned char IMadSocket::Decrypt(unsigned char data)
{
	return conf->order[data];
}

bool IMadSocket::Blocked(std::string hwid)
{
	IMadDatabase maddb = IMadDatabase(conf,this->database);
	return maddb.CheckBlock(hwid);
}

bool IMadSocket::BlockedIP(std::string ip)
{
	IMadDatabase maddb = IMadDatabase(conf,this->database);
	return maddb.CheckBlockIP(ip);
}

void IMadSocket::SaveKill()
{
	this->killed = true;
	this->forward = false;
	this->csocket->LeaveCriticalSection();
	if (this->csocket->GetPlayer())
	{
		Player *player = new Player((void*)this->csocket->GetPlayer());
		if (player)
		{
			Server::Console::WriteRed("[MadProtectS security check not passed %s kicked]",player->GetName());
			player->Kick();
		}
		delete player;
	}
	else
	{
		Server::CSocket::Write(this->Socket,45,"b",1);
		Server::CSocket::Logout(this->Socket,6);
		Server::CIOSocket::GracefulClose(this->Socket);
	}
}

bool IMadSocket::PreCheck()
{
	if (this->killed)
		return false;

	if (!this->Socket || !this->csocket)
	{
		Server::Console::WriteRed("[MadProtectS empty Socket detected]");
		return false;
	}

	if (!this->Data)
	{
		Server::Console::WriteRed("[MadProtectS empty Data in Socket detected]");
		return false;
	}

	if (!SIZE)
	{
		Server::Console::WriteRed("[MadProtectS invalid Packet Size in Socket detected]");
		return false;
	}

	if (SIZE > SIZE_LIMIT)
	{
		Server::Console::WriteRed("[MadProtectS Packet Size Limit exceeded %i]",SIZE);
		return false;
	}

	if (!HEADER)
	{
		Server::Console::WriteRed("[MadProtectS invalid Header detected]");
		return false;
	}

	return true;
}

void IMadSocket::DebugPrintRecvCrypted()
{
	if ( (!this->killed) && conf->DEBUG_MODE && HEADER!=0x14 && (SIZE > PACKET_DEBUG_PRINT_SIZE || HEADER == PCNAME_HEADER  || HEADER == SPEED_HEADER || HEADER == IP_HEADER) )
	{
		if (csocket->GetPlayer())
		{
			Player *player = new Player((void*)csocket->GetPlayer());
			if (player)
			{
				Server::Console::WriteBlack("Packet received from Player %s Header %x Size %i",player->GetName(),HEADER, SIZE);
			}
			delete player;
		}
		else
		{
			if (csocket->GetUID() != 0)
			{
				Server::Console::WriteBlack("Packet received from UID %i Header %x Size %i",csocket->GetUID(),HEADER,SIZE);
			}
			else
			{
				Server::Console::WriteBlack("Packet received from Socket %p Header %x Size %i",Socket,HEADER,SIZE);
			}
		}
	}
}

void IMadSocket::DebugPrintRecvUncrypt()
{
	if ((!this->killed) && conf->DEBUG_MODE && HEADER!=0x14 && SIZE > PACKET_DEBUG_PRINT_SIZE)
	{
		if (csocket->GetPlayer())
		{
			Player *player = new Player((void*)csocket->GetPlayer());
			if (player)
				Server::Console::WriteBlack("Packet Decrypted received from Player %s Header %x Size %i Offset %i",player->GetName(), HEADER, SIZE, this->offset);
			delete player;
		}
		else
		{
			if (csocket->GetUID() != 0)
				Server::Console::WriteBlack("Packet Decrypted received from UID %i Header %x Size %i Offset %i ", csocket->GetUID(), HEADER, SIZE, this->offset);
			else
				Server::Console::WriteBlack("Packet Decrypted received from Socket %p Header %x Size %i Offset %i",Socket, HEADER, SIZE, this->offset);
		}
	}
}

void IMadSocket::SHACheck(std::string sha, int sha_id)
{
	if ((!this->killed) && csocket->GetOffsetCode() && this->csocket->GetExTPointer()) // Make Sure a Secure Connection is established before checking Headers
	{
		MadSockExt *p = static_cast<MadSockExt*>(this->csocket->GetExTPointer());

		if ( p  && conf->SHA_ENABLED && SIZE < SIZE_LIMIT) //CPlayer__Process(int this, int PacketHeader, char *params, unsigned int paramsend)
		{
			switch (sha_id)
			{
			case 1:
				if (!iequals(sha,conf->Engine_SHA))
				{
					if (csocket->GetUID() != 0)
						Server::Console::WriteRed("[MadProtectS Engine checksum error Account UID %i]",csocket->GetUID());
					else
						Server::Console::WriteRed("[MadProtectS Engine checksum error in connection %p]",Socket);
					this->SaveKill();
				}
				else
				{
					p->engine_check_passed = 1;
				}
				if (conf->DEBUG_MODE && iequals(sha,conf->Engine_SHA))
				{
					Server::Console::WriteBlack("[MadProtectS Engine checksum check passed %p]",Socket);
				}
				break;

			case 2:
				if (!iequals(sha,conf->MadHelp_SHA))
				{
					if (csocket->GetUID() != 0)
						Server::Console::WriteRed("[MadProtectS MadHelp checksum error Account UID %i]",csocket->GetUID());
					else
						Server::Console::WriteRed("[MadProtectS MadHelp checksum error in connection %p]",Socket);
					this->SaveKill();
				}
				else
				{
					p->madhelp_check_passed = 1;
				}
				if (conf->DEBUG_MODE && iequals(sha,conf->MadHelp_SHA))
				{
					Server::Console::WriteBlack("[MadProtectS MadHelp checksum check passed %p]",Socket);
				}
				break;

			case 3:
				if (!iequals(sha,conf->Epk_SHA))
				{
					if (csocket->GetUID() != 0)
						Server::Console::WriteRed("[MadProtectS e.pk checksum error Account UID %i]",csocket->GetUID());
					else
						Server::Console::WriteRed("[MadProtectS e.pk checksum error in connection %p]",Socket);
					this->SaveKill();
				}
				else
				{
					p->epk_check_passed = 1;
				}
				if (conf->DEBUG_MODE && iequals(sha,conf->Epk_SHA))
				{
					Server::Console::WriteBlack("[MadProtectS e.pk checksum check passed %p]",Socket);
				}
				break;

			case 4:
				if (!iequals(sha,conf->Configpk_SHA))
				{
					if (csocket->GetUID() != 0)
						Server::Console::WriteRed("[MadProtectS config.pk checksum error Account UID %i]",csocket->GetUID());
					else
						Server::Console::WriteRed("[MadProtectS config.pk checksum error in connection %p]",Socket);
					this->SaveKill();
				}
				else
				{
					p->configpk_check_passed = 1;
				}
				if (conf->DEBUG_MODE && iequals(sha,conf->Configpk_SHA))
				{
					Server::Console::WriteBlack("[MadProtectS config.pk checksum check passed %p]",Socket);
				}
				break;

			default:
				Server::Console::WriteRed("[MadProtectS Wrong Checksum Header error in connection %p]",Socket);
				break;
			}
		}
		if (p && !conf->SHA_ENABLED)
		{
			p->engine_check_passed = 1;
			p->madhelp_check_passed = 1;
			p->epk_check_passed = 1;
			p->configpk_check_passed = 1;
		}
	}
}

void IMadSocket::HWIDCheck(std::string hwid)
{
	if ((!this->killed) && csocket->GetOffsetCode() && this->csocket->GetExTPointer()) // Make Sure a Secure Connection is established before checking Headers
	{
		MadSockExt *p = static_cast<MadSockExt*>(this->csocket->GetExTPointer());

		if (p && conf->HWID_ENABLED && SIZE < SIZE_LIMIT)
		{
			
			if (csocket->GetUID() != 0)
			{
				IMadDatabase maddb = IMadDatabase(conf,this->database);
				maddb.MadDatabaseSaveHWID(csocket->GetUID(),hwid);
				
			}
		/**	else
			{
				IMadDatabase maddb = IMadDatabase(conf,this->database);
				maddb.MadDatabaseSaveHWID(hwid);
				Server::Console::WriteRed("[Test1x]",Socket);
			}
			**/
			if ( this->Blocked(hwid) )
			{
				if (csocket->GetUID() != 0)
					Server::Console::WriteRed("[MadProtectS HWID blocked Account UID %i]",csocket->GetUID());
				else
					Server::Console::WriteRed("[MadProtectS HWID blocked Account in connection %p]",Socket);
				this->SaveKill();
			}
			else
			{
				p->hwid_check_passed = 1;
			}
		}

		if (p && !conf->HWID_ENABLED)
		{
			p->ip_check_passed = 1;
			p->hwid_check_passed = 1;
		}
	}
}

void IMadSocket::HeaderCheck()
{
	if ( (!this->killed) && HEADER == SHA_ENGINE_HEADER || HEADER == SHA_MADHELP_HEADER || HEADER == SHA_EPK_HEADER || HEADER == SHA_CONFIGPK_HEADER || HEADER == HWID_HEADER || HEADER == SPEED_HEADER || HEADER == PCNAME_HEADER || HEADER == IP_HEADER)
	{
		//this->forward = false;
		if (!csocket->GetOffsetCode()) // Security Checks without Offset Passed
		{
			Server::Console::WriteRed("[MadProtectS security check without offset error in connection %p]",Socket);
			this->SaveKill();
		}
	}
}

void IMadSocket::SpeedCheck()
{
	if ( (!this->killed) && csocket->GetOffsetCode() && HEADER == 0x14 && conf->CLIENT_SPEEDCHECK && SIZE < SIZE_LIMIT)
	{
		unsigned long speed = 0;
		ITools *tools = new ITools;
		tools->ParseData(DATA+DATAEND-sizeof(unsigned long),"Y",&speed);
		delete tools, tools = 0;
		if (csocket->GetPlayer())
		{
			Player *player = new Player((void*)csocket->GetPlayer());
			if ( player && player->GetAdmin() < 8 &&  speed > (unsigned int) conf->MAX_MOVE_SPEED )
			{
				Server::Console::WriteRed("[MadProtectS ClientSide SpeedHack detected %s kicked]",player->GetName());
				player->Kick();
			}
			delete player, player = 0;
		}
	} 
}

void IMadSocket::PCNameCheck(std::string name)
{
	if ((!this->killed) && csocket->GetOffsetCode() && conf->HWID_ENABLED && SIZE < SIZE_LIMIT)
	{
		if (csocket->GetUID() != 0)
		{
			IMadDatabase maddb = IMadDatabase(this->conf,this->database);
			maddb.MadDatabaseSaveName(csocket->GetUID(),name);
		}
	}
}


void IMadSocket::IPCheck(std::string ip)
{
	if ((!this->killed) && csocket->GetOffsetCode()) // Make Sure a Secure Connection is established before checking Headers
	{
		MadSockExt *p = static_cast<MadSockExt*>(this->csocket->GetExTPointer());

		if (p && conf->HWID_ENABLED && SIZE < SIZE_LIMIT)
		{

			if (csocket->GetUID() != 0)
			{
				IMadDatabase maddb = IMadDatabase(conf,this->database);
				maddb.MadDatabaseSaveIP(csocket->GetUID(),ip);
			}
			if ( this->BlockedIP(ip) )
			{
				Server::Console::WriteRed("[MadProtectS HWID blocked Account in connection %p]",Socket);
				SaveKill();
			}
			else
			{
				p->ip_check_passed = 1;
			}
		}
		if (p && !conf->HWID_ENABLED)
		{
			p->ip_check_passed = 1;
			p->hwid_check_passed = 1;
		}
	}
}

void IMadSocket::ProtectCheck()
{
	if ((!this->killed) && csocket->GetOffsetCode()  && this->forward && HEADER == 0x0A) // Make Sure a Secure Connection is established before checking Headers
	{
		MadSockExt *p = static_cast<MadSockExt*>(this->csocket->GetExTPointer());
		if ( p && ( !p->engine_check_passed || !p->configpk_check_passed || !p->epk_check_passed || !p->hwid_check_passed || !p->ip_check_passed || !p->madhelp_check_passed ) )
		{
			DWORD connectinfo;
			char *engine_sha = new char[MAX_BUFFER_SIZE]; // 1
			char *madhelp_sha = new char[MAX_BUFFER_SIZE];  // 2
			char *epk_sha = new char[MAX_BUFFER_SIZE];  // 3
			char *configpk_sha = new char[MAX_BUFFER_SIZE];  // 4
			char *hwid = new char[MAX_BUFFER_SIZE]; // 5
			char *username = new char[MAX_BUFFER_SIZE]; // 6
			char *realip = new char[MAX_BUFFER_SIZE]; // 7
			ITools *tools = new ITools; 
			tools->ParseData(DATA,"ddsssssss",&connectinfo,&connectinfo,&engine_sha,&madhelp_sha,&epk_sha,&configpk_sha,&hwid,&username,&realip);  
			std::string esha = engine_sha; //Server::Console::WriteBlack("engine_sha %s", esha.c_str());
			this->SHACheck(esha,1);
			std::string madhelpsha = madhelp_sha;
			this->SHACheck(madhelpsha,2); //Server::Console::WriteBlack("madhelp_sha %s", madhelpsha.c_str());
			std::string epksha = epk_sha;
			this->SHACheck(epksha,3);// Server::Console::WriteBlack("epk_sha %s", epksha.c_str());
			std::string configpksha = configpk_sha;
			this->SHACheck(configpksha,4); //Server::Console::WriteBlack("configpk_sha %s", configpksha.c_str());
			std::string hwids = hwid;
			this->HWIDCheck(hwids); //Server::Console::WriteBlack("hwid %s", hwids.c_str());
			std::string usernames = username;
			this->PCNameCheck(usernames); //Server::Console::WriteBlack("username %s", usernames.c_str());
			std::string ip = realip; 
			this->IPCheck(ip); //Server::Console::WriteBlack("realip %s", ip.c_str());
			if (conf->DEBUG_MODE)
				Server::Console::WriteBlack("IP %s PC Name %s connected",ip.c_str(),usernames.c_str());

			delete tools, engine_sha, madhelp_sha, epk_sha, configpk_sha, hwid, username, realip;
			tools, engine_sha, madhelp_sha, epk_sha, configpk_sha, hwid, username, realip = 0;
		}
	}
}


void IMadSocket::SetOffset()
{
	if ((!this->killed))
	{
		if (csocket->GetOffsetCode())
		{
			this->offset = csocket->GetOffsetCode();
		}
		else
		{ 
			this->offset = ((int)  (HEADER ) ) -  0x2C; // - 0x55

			MadSockExt *p = new MadSockExt( (((int)  (HEADER ) ) -  0x2C) );
			csocket->SetExTPointer(p);

			if (this->offset < 44 || this->offset > 70)
			{
				this->forward = false;
				Server::Console::WriteRed("[MadProtectS offset error in connection %p Wrong offset: %i]",Socket, this->offset);
				this->SaveKill();
			}
			else
			{
				Server::Console::WriteBlue("[MadProtectS new secured connection established]");
			}
		}
	}
}


void IMadSocket::PacketDecrypt()
{
	if ((!this->killed) && csocket->GetOffsetCode()  && this->forward) // Make Sure a Secure Connection is established before checking Headers
	{
		if ((!(HEADER == 0x14 || HEADER == 0x15 || HEADER == 0x29 || HEADER == 0x2a )) && SIZE < SIZE_LIMIT)
		{
			HEADER = ( (int) this->Decrypt( (HEADER - this->offset) ) ); 
			//Server::Console::WriteBlack("Header %x", HEADER);
			int keypos = 0;
			MadSockExt *p = static_cast<MadSockExt*>(this->csocket->GetExTPointer());
			if (p)
			{
				p->packet_counter++;
				if (p->packet_counter > 5)
					keypos = p->packet_counter;
			}

			// Init CryptTable
			char CRYPT_TABLE[20000];
			for (int x = 0; x < MAX_BUFFER_SIZE; x++) 
				CRYPT_TABLE[x] = (keypos ^ x) * CRYPT_OFF_PRIM;

			//xor decrypt
			for (int x = 0; x < (*(unsigned short*) Data -3); x++)
				(Data+3)[x] = (Data+3)[x] ^ CRYPT_TABLE[x];

			//reverse 
			char test[MAX_BUFFER_SIZE];
			for (int x = 0; x < (*(unsigned short*) Data -3); x++)
				test[x] = (Data+3)[(*(unsigned short*) Data -3)-1-x];

			for (int x = 0; x < (*(unsigned short*) Data -3); x++)
				(Data+3)[x] = test[x];

			//PacketDecryptCustom
			for (int i = 0; i < (*(unsigned short*) Data -3); i++) 
			{
				(Data+3)[i] = (unsigned char) (( ((int) (Data+3)[i]) - (this->offset+this->conf->packet_decode[i%50]+this->conf->packet_decode[(*(unsigned short*) Data -3)%50]) ));
			}

		}
	}
}

void IMadSocket::LogChat()
{
	if ( (!this->killed) && conf->CHAT_LOG && HEADER == 0x11 && csocket->GetOffsetCode() && this->forward) // Make Sure a Secure Connection is established before checking Headers
	{
		char *message = new char[MAX_BUFFER_SIZE];
		ITools *tools = new ITools;
		tools->ParseData(DATA,"s",&message);
		delete tools, tools = 0;
		std::string check_it = message;
		delete [] message, message = 0;

		if (csocket->GetPlayer())
		{
			Player *player = new Player((void*)csocket->GetPlayer());
			if (player)
			{
				if (conf->DEBUG_MODE)
					Server::Console::WriteBlack("[MadProtectS start LogChat for player %s]",player->GetName());

				IMadDatabase maddb = IMadDatabase(conf,this->database);
				maddb.MadDatabaseSaveChat(player->GetPid(),player->GetName(),check_it);

				if (conf->DEBUG_MODE)
					Server::Console::WriteBlack("[MadProtectS LogChat succeeded for player %s]",player->GetName());
			}
			delete player, player = 0;
		}
	}
}

void IMadSocket::ExecutionSpeedMeasurment(int i)
{	
	if ((!this->killed) &&  conf->DEBUG_MODE )
	{
		LONGLONG g_Frequency, g_CurentCount, g_LastCount = 0; 
		QueryPerformanceFrequency((LARGE_INTEGER*)&g_Frequency);
		if (!i)
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&g_CurentCount);
		}
		else
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&g_LastCount); 
			double dTimeDiff = (((double)(g_LastCount-g_CurentCount))/((double)g_Frequency));  
			if (dTimeDiff > 0.1)
				Server::Console::WriteBlack("[Execution Time was %lf µs]",dTimeDiff);
		}
	}
}

void IMadSocket::CallerCheck()
{
	if ((!this->killed) && conf->CALLER_CHECK && (!(HEADER == SHA_ENGINE_HEADER || HEADER == SHA_MADHELP_HEADER || HEADER == SHA_EPK_HEADER || HEADER == SHA_CONFIGPK_HEADER || HEADER == HWID_HEADER || HEADER == SPEED_HEADER || HEADER == PCNAME_HEADER || HEADER == IP_HEADER  
		|| HEADER == 0x14 || HEADER == 0x15 || HEADER == 0x29 || HEADER == 0x2a )) && SIZE < SIZE_LIMIT)
	{
		unsigned long caller = 0;
		ITools *tools = new ITools;
		tools->ParseData(DATA+DATAEND-sizeof(unsigned long)-sizeof(unsigned long),"X",&caller);
		delete tools, tools = 0;

		if (conf->DEBUG_MODE && SIZE > PACKET_DEBUG_PRINT_SIZE)
			Server::Console::WriteBlack("[MadProtectS Packet Caller received %x",caller);
		if	( !(caller >= 0x401000 && caller <= 0x692000) )
		{
			Server::Console::WriteRed("[MadProtectS CallerCheck not passed received %x in connection %p]",caller, Socket);
			this->SaveKill();
		}
	}
}

bool IMadSocket::Run()
{
	if(!this->PreCheck())
		return false;

	//	this->ExecutionSpeedMeasurment(0);
	this->DebugPrintRecvCrypted();
	this->HeaderCheck();
	this->SpeedCheck();

	this->SetOffset();
	this->PacketDecrypt();
	this->ProtectCheck();

	this->CallerCheck(); 
	this->DebugPrintRecvUncrypt();
	this->LogChat();
	//	this->ExecutionSpeedMeasurment(1);
	return this->forward;
}