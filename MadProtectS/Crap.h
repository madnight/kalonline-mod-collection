/**
void __cdecl WritePurple(char* text,  ...)
{
	va_list va;
	va_start(va,text);
	Server::Console::Write(5, text, va);
}

/**
	int catchaLL(PEXCEPTION_POINTERS exp)
	{
		 PCONTEXT ctx = exp->ContextRecord;
		 ctx->Eip += 3;
		return EXCEPTION_CONTINUE_EXECUTION;
	}




	/************************************************************************/
		/* __int32 __fastcall SpeedUp(int* pSkill, int _edx, int *pPlayer, char *pPacket, char* pPos){
		int pMemberID = 0;
		int *pMember, *i;
		int *pTarget;
		int Buff = CChar::CreateBuff(12, 600, 60, pSkill);

		int nTargetID;
		char bType;
		ReadPacket(pPacket, pPos, "bd", &bType, &nTargetID); 


		pTarget = (int*)FindPlayer(nTargetID);

		if(pTarget[254])
		{
		void* PartyID = CParty::FindParty(pTarget[254]);

		for ( i = CParty::GetPlayerList(PartyID); i; i = CBaseList::Pop((void *)i) )
		{
		Buff = CChar::CreateBuff(12, 600, 60, pSkill);
		pMember = (int*)*(int*)i; 
		CChar::CancelBuff((void*)pMember, 12);
		CChar::AddBuff((void*)pMember, Buff);
		CChar::WriteInSight(pPlayer, 63, "bddbb", pSkill[1], pPlayer[7], pMember[7], 0, pSkill[2]);
		}


		}else
		{
		CChar::CancelBuff((void*)pTarget,12);
		CChar::AddBuff((void*)pTarget, Buff);
		CChar::WriteInSight(pPlayer, 63, "bddbb", pSkill[1], pPlayer[7], pTarget[7], 0, pSkill[2]);
		}


		return 1;
		}                                                                     */
		/************************************************************************/
		/**int ThiefSkill__Run(void *PlayerPointer, char *PacketPointer, char *PositionPointer)
		{
			__int64 state;
			char Type;
			Server::ReadPacketSecure(PacketPointer, PositionPointer, "b", &Type);
			if (Type)
			{
				state = Server::CChar::IsMState(PlayerPointer,1i64);
				if (!state)
				{
					state = Server::CPlayer::IsWearBuffStandard(PlayerPointer);
					if (!state)
					{
						if ( Server::CChar::IsMState(PlayerPointer, 8i64) )
							Server::CChar::CChar__CancelBuff(PlayerPointer, 2);
					}
				}
			}
		}
		**/



	void __stdcall Boot(int boot)
	{
		 __try
		 {
			 Server::Boot(boot);
		 }
		 __except(catchaLL(GetExceptionInformation()))
		 {
		
		 }
	}

	inline void IMadSocket::PacketCounterCheck()
	{
	if ((!this->killed) && 0 && (!(HEADER == SHA_ENGINE_HEADER || HEADER == SHA_MADHELP_HEADER || HEADER == SHA_EPK_HEADER || HEADER == SHA_CONFIGPK_HEADER || HEADER == HWID_HEADER || HEADER == SPEED_HEADER || HEADER == PCNAME_HEADER || HEADER == IP_HEADER  
	|| HEADER == 0x14 || HEADER == 0x15 || HEADER == 0x29 || HEADER == 0x2a )) && SIZE < SIZE_LIMIT)
	{
	unsigned long counter = 0;
	ITools *tools = new ITools;
	tools->ParseData(DATA+DATAEND-sizeof(unsigned long),"Z",&counter);
	delete tools, tools = 0;
	// Server::Console::WriteBlack("[ HEADER %x",HEADER);
	//Server::Console::WriteBlack("[MadProtectS Packet Counter received %i",counter);
	MadSockExt *p = static_cast<MadSockExt*>(this->csocket->GetExTPointer());
	if (p)
	{
	if (p->packet_counter == -1)
	{
	p->packet_counter = counter;
	}
	else 
	{
	int diff = counter - p->packet_counter;
	//Server::Console::WriteBlack("[MadProtectS Packet Counter diff is %i",diff);
	p->packet_counter = counter;
	if (diff =! 1)
	{
	Server::Console::WriteBlack("[MadProtectS Packet Verification failed in UID %i]",this->csocket->GetUID());
	this->SaveKill();
	}
	}
	}
	}
	}


	/**
			__asm mov eax, SkillID
			__asm mov ecx, PlayerCSkill
			__asm mov edx, [ecx+eax*4+8]
			__asm mov SkillPointer, edx
			**/
	**/

int MAX_DAMAGE;
int MAX_MONSTER_DAMAGE;
int MAX_SPEED;

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

vector<std::string> hardware_ids;
std::string Weclome_Message;





//IMadOntimer* ontimer = new IMadOntimer(counter,VERSION,MAX_Z_VALUE,MIN_Z_VALUE,MAX_DAMAGE,MAX_MOVE_SPEED,UG_OG_CHECK);





inline void HWID_Check(void *Socket, char* Data)
{
	CSocket *socketc = new CSocket(Socket);
	if (HEADER == 0x06 && HWID_ENABLED)
	{
		char *message;
		Server::ReadPacketSecure(DATA,&Data[*(WORD *)Data],"s",&message,0x81);
		std::string check_it = message;

		if (socketc->GetUID() != 0)
			MadDatabaseSaveHWID(socketc->GetUID(),message);

		if ( Blocked(message) )
		{
			Server::Console::WriteRed("[MadProtectS HWID blocked Account in connection %p]",Socket);
			KILLSOCKET
		}
		delete message;
	}

	if (HEADER == 0x00 && HWID_ENABLED)
	{
		char *message;
		Server::ReadPacketSecure(DATA,&Data[*(WORD *)Data],"s",&message,0x81);
		std::string check_it = message;

		if (socketc->GetUID() != 0)
			MadDatabaseSaveName(socketc->GetUID(),message);
		delete message;
	}

	delete socketc;
}





inline void Caller_Check(void *Socket, char* Data)
{
	std::stringstream msg (std::stringstream::in | std::stringstream::out);
	char buffer [16];
	for (int i = (*(unsigned short*)Data -3) -1  ; i >= ( ( (int)(*(unsigned short*)Data -3) ) - 4 ); i--)
	{
		sprintf_s(buffer, sizeof(buffer),"%02x", ((const unsigned char *) (Data+3))[i] & 0xff);
		msg << buffer;
	}
	string rep = msg.str().replace(0,2,"");
	unsigned int caller;   
	std::stringstream ss;
	ss << std::hex << rep;
	ss >> caller;
	//	Server::Console::WriteBlue("Received %x",caller);
//	if	(  !(caller >= 0x401000 && caller <= 0x692000) )
	//{
	//	KILLSOCKET
	//}
}



//IMadSocket *madsock = new IMadSocket(Socket,Data,SHA_ENABLED,Engine_SHA,MadHelp_SHA,Epk_SHA,Configpk_SHA,order);

		IMadDatabase* maddb = new IMadDatabase
				(&MAX_Z_VALUE, &MIN_Z_VALUE, &MAX_DAMAGE, &MAX_MOVE_SPEED,
				&UG_OG_CHECK, &MAX_ATTACK, &MAX_FINAL_DAMAGE, &PLAYERON_MSG,
				&CLIENT_SPEEDCHECK, &HWID_ENABLED, &SHA_ENABLED, &Engine_SHA,
				&MadHelp_SHA, &Epk_SHA, &Configpk_SHA, &hardware_ids, &Weclome_Message); 


bool Blocked(std::string hwid)
{
//	for (int i = 0;i<hardware_ids.size();i++)
	//	if  (hwid == hardware_ids.at(i))
//			return true;
	return false;
}





#define KILL Server::CSocket::Write(Socket,45,"b",1);Server::CSocket::Logout(Socket,6);Server::CIOSocket::GracefulClose(Socket);

		unsigned int __stdcall SocketCheck(void *Socket)
		{
			Sleep(100);
			if ( Socket )
			{
				CSocket *socketc = new CSocket(Socket);
				if (!socketc->GetOffsetCode())
				{
					Server::Console::WriteRed("[MadProtectS Pre-Authentication error in connection %p]",Socket);
					KILL
				}
				delete socketc;
			}
			return 0;
		}


		unsigned int __stdcall SocketKILL(void *Socket)
		{
			Sleep(100);
			if (Socket)
			{
				CSocket *socketc = new CSocket(Socket);
				KILL
					delete socketc;
			}
			return 0;
		}


		void __cdecl OnNewConnection(char *text, char*ip,int port,void *Socket)
		{
			Server::Console::WriteBlue(text,ip,port,Socket);
			CSocket *socketc = new CSocket(Socket);
			if (socketc->GetOffsetCode())
			{
				Server::Console::WriteRed("[MadProtectS Pre-Authentication error in connection %p]",Socket);
				_beginthreadex(NULL, 0, SocketKILL, Socket, 0, NULL); 
			}
			delete socketc;

			_beginthreadex(NULL, 0, SocketCheck, Socket, 0, NULL); 
		}


**/

/**

void IMadDatabase::MadDatabaseRead()
{
	conf->hardware_ids.clear();
	string hwid_prefix = "HardwareID=";
	string block_prefix = "Blocked=";
	ifstream f;
	string s;
	string value;
	string blocked;
	ifstream ifile("MadDatabase.txt");
	if (ifile) 
	{
		f.open("MadDatabase.txt", ios::in);
		while (!f.eof())        
		{
			getline(f, s);      
			if (s.substr(0, hwid_prefix.size()) == hwid_prefix) 
			{
				value = (s.substr(hwid_prefix.size(),50));	
			}

			if (s.substr(0, block_prefix.size()) == block_prefix) 
			{
				blocked = (s.substr(block_prefix.size(),30));	
			}
			if (blocked == "True")
			{
				conf->hardware_ids.push_back( value );
				blocked = "False";
			}
		}		
	}
	f.close();            
}

**/

/**		CIniWriter *writer = new CIniWriter(".\\MadDatabase.txt");
	std::string prefix_uid = "UID ";

	std::string uid = prefix_uid + convertInt(UID);
	writer->WriteBoolean(const_cast<char*>(uid.c_str()), "Blocked", block);  
	delete writer;
	//MadDatabaseRead();
	if (block)
	conf->hardware_ids.push_back(this->MadDatabaseGetHWID(UID));
	else
		conf->hardware_ids.erase(std::remove(conf->hardware_ids.begin(), conf->hardware_ids.end(), this->MadDatabaseGetHWID(UID)), conf->hardware_ids.end());
//	delete writer;
**/

/**
std::string IMadDatabase::MadDatabaseGetHWID(int UID)
{
	CIniReader *reader = new CIniReader(".\\MadDatabase.txt");
	std::ostringstream header;	
	header << "UID " << UID;

	std::string hwid = reader->ReadString(MAD_CONST(header),"HardwareID","Invalid HWID");

	delete reader;
	return hwid;
}



void IMadDatabase::Load_Config()
{
	CIniReader *reader = new CIniReader(".\\MadChecksum.txt");
	std::ostringstream header;	
	header << "Checksum";

	conf->Engine_SHA  = reader->ReadString(MAD_CONST(header),"Engine","");
	conf->MadHelp_SHA  = reader->ReadString(MAD_CONST(header),"MadHelp","");
	conf->Epk_SHA  = reader->ReadString(MAD_CONST(header),"Epk","");
	conf->Configpk_SHA  = reader->ReadString(MAD_CONST(header),"Configpk","");
	//Server::Console::WriteBlack("Configpk %s",Engine.c_str());
}
#define KILLSOCKET Server::CSocket::Write(Socket,45,"b",1);Server::CSocket::Logout(Socket,6);Server::CIOSocket::GracefulClose(Socket);
**/
