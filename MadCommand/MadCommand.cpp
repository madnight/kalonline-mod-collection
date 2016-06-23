#include "MadCommand.h"

static unsigned __int64 ExpTable[] = {
	1, 5, 24, 60, 160, 328, 542, 814, 1157, 1588, // 9
	2250, 3086, 4135, 5444, 7068, 9126, 11660, 14769, 18572, 23214,// 19
	29155, 36409, 45245, 55988, 69026, 85569, 105656, 130009, 159494, 195150, // 29
	238225, 290216, 352918, 428488, 519513, 629149, 761081, 919784, 1110624, 1340045, // 39
	1615778, 1947099, 2345141, 2823265, 3397501, 4087087, 4915108, 5909267, 7102808, 8535623, // 49
	10255633, 12320243, 14798389, 17772795, 21342730, 25627317, 30769501, 36940820, 44347118, 53235407, // 59
	63902104, 76702906, 92064653, 110499551, 132622249, 159170373, 191028978, 229260177, 275138508, 330193415, // 69
	396260232, 1188853398, 1426699190, 1712116603, 2054620005, 2465626643 ,2958837208 ,3550692535 ,4260921625 ,5113199283 ,// 79
	6135935388 ,736322156 ,883596785 ,1060326635 ,1272402754 ,1526894400 ,1832284685 ,2198753341 ,2638516046 ,3166231618 ,// 89
	3799490632 ,4559401784 ,5471295506 ,6565568317 ,7878696039 ,9454449661 ,11345354368 ,13614440381 ,16337343968 ,19604828648,// 99
	6012954215, 5583457486, 5153960756, 6871947675, 3435973837, 77309411329, 3435973848, 7730941133, 3435973838, 60129542161, // 109
	4294967297, 4724464027  //119
};

void __stdcall IMadCommand::Start(int start)
{
	Server::CIOServer::Start(start);
	Server::Console::WriteBlue("[MadCommand started]");
}


	//	if (this->command->beginWith("/madspawn"))
	//		this->Spawn();
	//	if (this->command->beginWith("/madsummon"))
	//		this->Spawn_Alt();
	//	if (this->command->beginWith("/debug"))
	//		this->Debug();
	//	if (this->command->beginWith("/madknight"))
	//		this->Mad();
	
		//	if (this->command->beginWith("/showip"))
	//		this->ShowIP();

void IMadCommand::Run()
{
	if (this->player->isGM())
	{
		if (this->command->beginWith("/portrandom"))
			this->PortRandom();
		if (this->command->beginWith("/madmoveto"))
			this->PortTo();
		if (this->command->beginWith("/moveto"))
			this->PortTo();
		if (this->command->beginWith("/setspeed"))
			this->SetSpeed();

		if (this->command->beginWith("/partyon")) 
			this->PartyOn();
		if (this->command->beginWith("/partyoff")) 
			this->PartyOff();
		if (this->command->beginWith("/setlevel"))
			this->SetLevel();

		if (this->command->beginWith("/coordinates"))
			this->Coordinates();
		
		if (this->command->beginWith("/madcoord"))
			this->Coordinates();
	}

	if (this->player->isAdmin())
	{
		if (this->command->beginWith("/portuserall"))
			this->PortUserAll();
		if (this->command->beginWith("/getmoney"))
			this->GetMoney();

	}
	
	if (this->command->beginWith("/uptime"))
		this->Uptime();

	if (this->command->beginWith("/madup"))
		this->Uptime();

	if (this->command->beginWith("/playeron"))
		this->PlayerOn();

	if (this->command->beginWith("/online"))
		this->PlayerOn();

	if (this->command->beginWith("/expneed"))
		this->ExpNeed();

	if (this->command->beginWith("/madkickme"))
		this->KickMe();
}

void IMadCommand::PlayerOn()
{
	int on = this->main->PlayerOnline();
	char buffer[100];
	sprintf(buffer, "There are currently %i Players Online", on);
	this->player->Notice(buffer);
}

void IMadCommand::PortTo()
{
	string targetname = command->GetParamString(1);
	Player *target = main->FindPlayerByName(targetname);
	if (target)
	{
		this->player->Teleport(target->GetMap(),target->GetXCoord(),target->GetYCoord());
	}
	else
	{
	char buffer[100];
	sprintf(buffer, "Player %s not found.", targetname.c_str());
	this->player->Notice(buffer);
	}
}

void IMadCommand::KickMe()
{
	this->player->Kick();
}

void IMadCommand::Coordinates()
{
	std::ostringstream message;
	message << "Your Coordinates are " 
		<< this->player->GetMap() << " " 
		<< this->player->GetXCoord() << " " 
		<< this->player->GetYCoord() << " "
		<< this->player->GetZCoord();
	this->player->Notice(MAD_CONST(message));
}

void spawntest(void *args)
{
	int index[] = {290,19,17,49,198,51,419,435,566,572,213};
	int x[] = {258196,258196,258196,258196,258196, 258396,258396,258396,258396,258396};
	int y[] = {262928,263028,263128,263228,263328, 262928,263028,263128,263228,263328};
		Summon *summon = new Summon;
	for (int z=0;z<11;z++)
	for (int i=0;i<10;i++)
	{
	summon->spwan_alt(index[z],x[i],y[i],0,1,0,0);
	Sleep(500);
	}
	delete summon;
}

void IMadCommand::Mad()
{
	//_beginthread(spawntest,0,0);
}



void IMadCommand::ExpNeed()
{
    unsigned int PlayerExp = this->player->GetExp();
	int PlayerLevel = this->player->GetLevel();

	//Server::Console::WriteBlue("Level %i",PlayerLevel);

	 if (PlayerLevel == 0 || PlayerLevel>118) // avoid EXPTable invalid access
		 PlayerLevel = 1;

	//Server::Console::WriteBlue("PlayerExp %lld",PlayerExp);

	unsigned __int64 LevelEXP =  ExpTable[PlayerLevel];

	//	Server::Console::WriteBlue("LevelEXP %I64d",LevelEXP);

	if (LevelEXP == 0) // avoid Integer div by zero
		LevelEXP = 1;

   	double ExpNeeded = ((double)PlayerExp) / ((double)LevelEXP);

	//  Server::Console::WriteBlue("ExpNeeded %f",ExpNeeded);

	int result = (int) (ExpNeeded * 100);

	std::ostringstream message;
	message << "You have: " << result << "% EXP (100% needed)";
	this->player->Notice(MAD_CONST(message));
}

void IMadCommand::Uptime()
{
int tage,stunden,minuten,sekunden,up;

up = GetTickCount() - this->uptime;
tage = up/(1000*60*60*24);
stunden = (up-(tage*1000*60*60*24))/(1000*60*60);
minuten = (up-(tage*1000*60*60*24)-(stunden*1000*60*60))/(1000*60);
sekunden = (up-(tage*1000*60*60*24)-(stunden*1000*60*60)-(minuten*1000*60))/1000;

std::ostringstream message;
	message << "The Total Server Uptime is "<< tage << " days " << stunden << " hours " << minuten << " mins " << sekunden << " seconds ";
	this->player->Notice(MAD_CONST(message));
}

void IMadCommand::PortRandom()
{
    srand (time(NULL));
	int random = rand()%main->PlayerOnline();
	int counter = 0;
	ENTER_CRIT
		PLAYER_LIST_ITERATE
	{
		//Server::Console::WriteBlack("counter %i   randon %i",counter, random);
		if (counter == random)
		{
			Player *target = new Player(PLAYER_POINTER);
			player->Teleport(target->GetMap(),target->GetXCoord(),target->GetYCoord());
			delete target;
		}
		counter++;
	}
	LEAVE_CRIT	
}

void IMadCommand::SetSpeed()
{
	int speed = command->GetParamInt(1);
	if (speed)
	{
		this->player->SetSpeed(speed);
		char buffer[100];
		sprintf(buffer, "Speed set up to: %i", speed);
		this->player->Notice(buffer);
	}
}

void IMadCommand::ShowIP()
{
	string targetname = command->GetParamString(1);
	Player *target = main->FindPlayerByName(targetname);
	char buffer[100];
	if (target)
	{
		sprintf(buffer, "IP from %s is %s", target->GetName(),target->GetSocket().GetIP());
		this->player->Notice(buffer);
	} 
	else
	{
		this->player->Notice("Player not found");
	}
}


void IMadCommand::PortUserAll()
{
	Player *target;
	ENTER_CRIT
		PLAYER_LIST_ITERATE
	{
		target = new Player(PLAYER_POINTER);
		target->Teleport(player->GetMap(),player->GetXCoord(),player->GetYCoord());
		delete target;
	}
	LEAVE_CRIT
}

void IMadCommand::PartyOn()
{
	IMemory *Memory = new IMemory;
	Memory->Fill(0x0044DA11,0x1E,1); //30 er Party
	this->main->Notice("30 Player Party activated");
	delete Memory;
}

void IMadCommand::PartyOff()
{
	IMemory *Memory = new IMemory;
	Memory->Fill(0x0044DA11,0x08,1); //8 er Party
	this->main->Notice("30 Player Party deactivated");
	delete Memory;
}

void IMadCommand::SetLevel()
{
	IMemory *Memory = new IMemory;
	Memory->Fill(0x0046349A, IMemory::_I_NOP, 5);	
	delete Memory;
	int level = command->GetParamInt(1);
	if (level)
		this->player->SetLevel(level);
}

void IMadCommand::GetMoney()
{
	Server::Console::WriteBlue("[MadCommand: Cheat Money inserted %s]",this->player->GetName());
	this->player->InsertItem(31,500000000);
}

void IMadCommand::Spawn()
{
	int MonsterIndex = command->GetParamInt(1);
	if (MonsterIndex == 0) MonsterIndex = 1;

	int count = command->GetParamInt(2);
	if (count == 0) count = 1;

	int spawntime = command->GetParamInt(3);
	if (spawntime == 0) spawntime = 10000;

	Server::Console::WriteBlue("[MadCommand: Monster summoned Index: %d Count: %d]",MonsterIndex,count);

	Summon *summon = new Summon;
	summon->spawn(MonsterIndex,this->player->GetXCoord(),this->player->GetYCoord(),this->player->GetMap(),count,spawntime);
	delete summon;
}

void IMadCommand::Spawn_Alt()
{
	
	int MonsterIndex = command->GetParamInt(1);
	if (MonsterIndex == 0) MonsterIndex = 1;

	int count = command->GetParamInt(2);
	if (count == 0) count = 1;

	int time = command->GetParamInt(3);
	if (time == 0) time = 1;

	int respawn = command->GetParamInt(4);
	
	Summon *summon = new Summon;
	summon->spwan_alt(MonsterIndex,this->player->GetXCoord(),this->player->GetYCoord(),this->player->GetMap(),count,time,respawn);
	Server::Console::WriteBlue("[MadCommand: Monster summoned Index: %d Count: %d Time: %d Respawn %d]",MonsterIndex,count,time,respawn);
	delete summon;
}


void IMadCommand::Debug()
{
	
	int MonsterIndex = command->GetParamInt(1);
	if (MonsterIndex == 0) MonsterIndex = 1;

	int count = command->GetParamInt(2);
	if (count == 0) count = 1;

	int time = command->GetParamInt(3);
	if (time == 0) time = 1;

	int respawn = command->GetParamInt(4);
	if (respawn == 0) respawn = 1;

	Summon *summon = new Summon;
	summon->spwan_alt(MonsterIndex,this->player->GetXCoord(),this->player->GetYCoord(),this->player->GetMap(),count,time,respawn);
	Server::Console::WriteBlue("[MadCommand: Monster summoned Index: %d Count: %d]",MonsterIndex,count);
	delete summon;
}



/**	Log *log = new Log; this->player->SetName("test");
	for (int i = 0; i < 200; i++)
	{
		//Server::Console::WriteBlue("Debug Value %d = %d",i, ((int*) this->player->thispointer)[i]);
		char print[100];
		sprintf_s(print, sizeof(print),"Debug Value %d = %d\n",i, ((int*) this->player->thispointer)[i]);
		log->Write("MADDEBUG",print);
	}
	delete[] log; **/