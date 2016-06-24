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
 
#include "IMadOnStart.h"


const unsigned char KEYSIZE = 5;
const unsigned char HEADER_MAX = 0x80;
//0x11, 0x02, 0x22, 0xA2, 0xF2
unsigned char key[] = { 0x12, 0x03, 0x21, 0xA4, 0xF3 };
unsigned char chaos[HEADER_MAX];
unsigned char order[HEADER_MAX];

int packet_decode[50] = {15, 6, 11, 35, 27, 12, 5, 11, 43, 46, 13, 22, 44, 3, 37, 3, 40, 6, 53, 19, 34, 27, 21, 13, 22, 6, 25, 44, 36, 8, 10, 22, 34, 43, 8, 17, 14, 7, 30, 11, 39, 38, 10, 35, 27, 17, 9, 8, 17, 13};

void createChaosAndOrder()
{
	int i;
	for ( i = 0; i < HEADER_MAX; ++i )
		chaos[i] = i;
	for ( i = 0; i < HEADER_MAX; ++i )
	{ 
		unsigned char t;
		t = chaos[i];
		chaos[i] = chaos[(i + key[i % KEYSIZE]) % HEADER_MAX];
		chaos[(i + key[i % KEYSIZE]) % HEADER_MAX] = t;
	}
	for ( i = 0; i < HEADER_MAX; ++i )
		order[chaos[i]] = i;
}



void IMadOnStart::Run()
{
	IMadDatabase maddb = IMadDatabase(config,this->database);

	if (CheckLicense())
		maddb.Load_Config_MadProtectS();

	//if (CheckLicense())
	//	maddb->Load_Config();

	Server::Console::WriteBlue("[MadProtectS connect to Database...]");
	Server::Console::WriteBlue(this->database->Connect(config->Database_Name.c_str()));

	//Create MadDB Table if not exist
	this->database->Execute("IF NOT EXISTS ( SELECT [name] FROM sys.tables WHERE [name] = 'MadDB' ) CREATE TABLE MadDB (UID int,PC varchar(255),HWID varchar(255),IP varchar(255),BLOCK int )",true);

	//Create MadChat Table if not exist
	this->database->Execute("IF NOT EXISTS ( SELECT [name] FROM sys.tables WHERE [name] = 'MadChat' ) CREATE TABLE MadChat (PID int, PLAYER varchar(255),CHAT varchar(255),TIME varchar(255))",true);

	//Create MadConsoleLog Table if not exist
	this->database->Execute("IF NOT EXISTS ( SELECT [name] FROM sys.tables WHERE [name] = 'MadConsole' ) CREATE TABLE MadConsole (CONSOLE varchar(255),TIME varchar(255))",true);

	config->START_TIME = GetTickCount();

	if (CheckLicense())
		if (config->SHA_ENABLED)
			Server::Console::WriteBlue("[MadProtectS SHA-512 Checksum System enabled]");
		else
			Server::Console::WriteRed("[MadProtectS SHA-512 Checksum System disabled]");

	if (CheckLicense())
		if (config->HWID_ENABLED)
		{
			int blocked = database->Execute("SELECT COUNT (BLOCK) FROM MadDB WHERE BLOCK = 1",false);
			Server::Console::WriteBlue("[MadProtectS HardwareID Block System enabled. %i HWIDs Blocked]",blocked);
		}
		else
		{
			Server::Console::WriteRed("[MadProtectS HardwareID Block System disabled]");
		}

		if (CheckLicense())
		{
			createChaosAndOrder();
			config->order = order;
			config->packet_decode = packet_decode;
		}


		//NOT NULL PRIMARY KEY
		if (CheckLicense())
			Server::Console::WriteBlue("[MadProtectS started Version %s]",VERSION.c_str());

		IMemory *memory = new IMemory;
		memory->Fill(0x004956C4,0x90,4); //Uhhh?
		memory->Fill(0x004564C0,0x90,40); //Invalid state at Csocket  //4564E7
		memory->Set(0x004D5B80,"\x00",1); // Assert disable

		//Not tested
		memory->Fill(0x004949F7,0x90,31); // Speed Hack Message
		memory->Fill(0x00494A79,0x90,31); // Speed Hack Message 2

		memory->Set(0x00494593,"\xE7\x03",2); // Assert disable

		//Delete Stats Logging Print 0x00450E0C - 0x00450C61  
		memory->Fill(0x00450C61,0x90,427);

		delete memory, memory = 0;

		// ADD IO Threads
	//	int threadid = 40;
	//	for (;threadid <= 102;threadid++) //52
	//	{
	//		int thread = Server::CIOSocket::AddIOThread(threadid);
	//		if (thread)
	//			++*(DWORD *)0x004E1190;
	//	}

}