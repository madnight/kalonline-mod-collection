int __fastcall Process(void *Socket, void *edx, char *Data)
{
	if (!LicenseSerialCheck) return 0;

	if ((unsigned char)Data[2] == 253)
	{
		int Type = 0, Value = 0;
		CPacket::Read((char*)((void*)(Data + 3)), (char*)(Data + *(WORD*)Data), "dd", &Type, &Value);

		if (Value != 6547)
			return 0;

		PacketHackCheck[(int)Socket] = Type;
		return 0;
	}

	if ((unsigned char)Data[2] != 253)
	{
		if ((unsigned char)Data[2] != PacketHackCheck.find((int)Socket)->second)
		{
			CDBSocket::ProcessHtml((int)Socket,(char)0xFF,(unsigned int)"d",220);
			return 0;
		}
	}

	if (Data[2] == 9 && ((std::string)Active2ndPwd == "true" || (std::string)Active2ndPwd == "True"))
	{
		int Type = 0; const char *RealPwd="asd",*Pwd2="asd",*MyPwd2="asd"; Interface<ITools> Tools;
		Tools->ParseData((char*)((void*)(Data + 3)),"b",&Type);

		if (Type == 0)
		{
			Tools->ParseData((char*)((void*)(Data + 3)),"bs",&Type,&MyPwd2);

			if (strlen(MyPwd2))
				CDBSocket::ProcessHtml((int)Socket,(char)0xFF,(unsigned int)"ds",252,MyPwd2);
		}

		if (Type == 1)
		{
			Tools->ParseData((char*)((void*)(Data + 3)),"bss",&Type,&RealPwd,&Pwd2);
			CDBSocket::ProcessHtml((int)Socket,(char)0xFF,(unsigned int)"dss",251,RealPwd,Pwd2);
		}

		if (Type == 2)
		{
			Tools->ParseData((char*)((void*)(Data + 3)),"bss",&Type,&RealPwd,&Pwd2);
			CDBSocket::ProcessHtml((int)Socket,(char)0xFF,(unsigned int)"dss",250,RealPwd,Pwd2);
		}

		return 0;
	}

	if ((unsigned char)Data[2] == 255)
	{
		int Type = 0;
		int LeftPacket = CPacket::Read((char*)((void*)(Data + 3)), (char*)(Data + *(WORD*)Data), "d",&Type);

		if (Type == 1 && ((std::string)Active2ndPwd == "true" || (std::string)Active2ndPwd == "True"))
		{
			const char *MyID,*MyPwd,*My2ndPwd;
			CPacket::Read((char*)LeftPacket, (char*)(Data + *(WORD*)Data), "sss",&MyID,17,&MyPwd,9,&My2ndPwd,9);

			if (!Read2ndPwd.count(MyID) || !strlen(My2ndPwd))
				return 0;

			std::stringstream strValuexx;
			strValuexx << My2ndPwd << std::endl;
			int Valuexx = 0;
			strValuexx >> Valuexx;
			std::stringstream strValueyy;
			strValueyy << Read2ndPwd.find(MyID)->second << std::endl;
			int Valueyy = 0;
			strValueyy >> Valueyy;

			if (Valuexx == Valueyy)
			{
				if (Undefined::CheckID((int*)MyID))
				{
					if (*(BYTE*)MyPwd)
					{
						Undefined::Login(1,(unsigned int)"dssdw",*(DWORD *)((int)Socket + 280),MyID,MyPwd,*(DWORD *)((int)Socket + 140),*(DWORD *)((int)Socket + 136));
						Undefined::LoginSuccess((signed __int32 *)((int)Socket + 108), 0);
					} else {
						CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 3);
					}
				} else {
					CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 2);
				}
			} else {
				CDBSocket::ProcessHtml((int)Socket,(char)143,(unsigned int)"bd", 3,1);
			}
		}

		if (Type == 2 && ((std::string)Active2ndPwd == "true" || (std::string)Active2ndPwd == "True"))
		{
			const char *MyID,*MyPwd,*My2ndPwd;
			CPacket::Read((char*)LeftPacket, (char*)(Data + *(WORD*)Data), "sss",&MyID,17,&MyPwd,9,&My2ndPwd,9);

			if (Undefined::CheckID((int*)MyID))
			{
				if (*(BYTE*)MyPwd && strlen(My2ndPwd))
				{
					std::string MyGetID = MyID;
					Undefined::Login(1,(unsigned int)"dssdw",*(DWORD *)((int)Socket + 280),MyID,MyPwd,*(DWORD *)((int)Socket + 140),*(DWORD *)((int)Socket + 136));
					Undefined::LoginSuccess((signed __int32 *)((int)Socket + 108), 0);
					CDBSocket::Write(86,"ss",MyID,My2ndPwd);
					Read2ndPwd[MyID] = My2ndPwd;
				} else {
					CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 3);
				}
			} else {
				CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 2);
			}
		}

		if (Type == 3)
		{
			int NewType = 0;
			CPacket::Read((char*)LeftPacket, (char*)(Data + *(WORD*)Data), "d",&NewType);

			if (NewType == 1)
				CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 3);
		}

		if (Type == 4 && ((std::string)Active2ndPwd == "true" || (std::string)Active2ndPwd == "True"))
		{
			const char *IDMy,*PwdMy,*Old2ndPwd,*New2ndPwd;
			CPacket::Read((char*)LeftPacket, (char*)(Data + *(WORD*)Data), "ssss",&IDMy,17,&PwdMy,9,&Old2ndPwd,9,&New2ndPwd,9);
			std::stringstream strValuevv;
			strValuevv << Old2ndPwd << std::endl;
			int Valuevv = 0;
			strValuevv >> Valuevv;
			std::stringstream strValuezz;
			strValuezz << Read2ndPwd.find(IDMy)->second << std::endl;
			int Valuezz = 0;
			strValuezz >> Valuezz;

			if (!strlen(Old2ndPwd) || !strlen(New2ndPwd))
				return 0;

			if (Valuevv == Valuezz)
			{
				if (Undefined::CheckID((int*)IDMy))
				{
					if (*(BYTE*)PwdMy  && strlen(New2ndPwd))
					{
						Undefined::Login(1,(unsigned int)"dssdw",*(DWORD *)((int)Socket + 280),IDMy,PwdMy,*(DWORD *)((int)Socket + 140),*(DWORD *)((int)Socket + 136));
						Undefined::LoginSuccess((signed __int32 *)((int)Socket + 108), 0);
						CDBSocket::Write(86,"ss",IDMy,New2ndPwd);
						Read2ndPwd[IDMy] = New2ndPwd;
					} else {
						CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 3);
					}
				} else {
					CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 2);
				}
			} else {
				CDBSocket::ProcessHtml((int)Socket,(char)143,(unsigned int)"bd", 3,1);
			}
		}

		if (Type != 5)
			return 0;
	}

	if (Data[2] == 28)
	{
		char Type = 0; int Amount = 0, ItemIndex;
		CPacket::Read((char*)((void*)(Data + 3)), (char*)(Data + *(WORD*)Data), "bd", &Type, &Amount);
		void *GetPlayer = *(void**)((int)Socket + 120);
		IChar IPlayer(GetPlayer);

		if (IPlayer.IsOnline() && Type && Amount)
		{
			if (Type == 2) ItemIndex = 2524;
			else if (Type == 3) ItemIndex = 2525;
			else if (Type == 4) ItemIndex = 2526;
			else if (Type == 5) ItemIndex = 2527;
			else if (Type == 6) ItemIndex = 2528;
			else if (Type == 11) ItemIndex = 2529;

			if (Type == 7)
			{
				if (MiningLimit.count(IPlayer.GetIP()) && MiningLimit.find(IPlayer.GetIP())->second && IPlayer.IsBuff(296))
					MiningLimit[IPlayer.GetIP()] = 0;

				IPlayer.CloseWindow("minebar");
				CheckMining[IPlayer.GetPID()].Time = 0;
				CheckMining[IPlayer.GetPID()].Cycle = 0;
				CheckMining[IPlayer.GetPID()].Index = 0;
				CheckMining[IPlayer.GetPID()].Amount = 0;
				return 0;
			}

			if (!CheckMining.count(IPlayer.GetPID()) || !CheckMining.find(IPlayer.GetPID())->second.Time)
			{
				if (MiningLimit.count(IPlayer.GetIP()) && MiningLimit.find(IPlayer.GetIP())->second)
				{
					IPlayer.SystemMessage("Exceeded the maximum miner limit.",TEXTCOLOR_RED);
					return 0;
				}

				if (CChar::IsGState((int)IPlayer.GetOffset(), 32))
				{
					IPlayer.SystemMessage("You can not mine while fishing.",TEXTCOLOR_RED);
					return 0;
				}

				if (IPlayer.GetRectX() < 8198 || IPlayer.GetRectX() > 8433 || IPlayer.GetRectY() < 8790 || IPlayer.GetRectY() > 8966)
				{
					CPlayer::Write(IPlayer.GetOffset(),220,"bb",0,7);
					return 0;
				}

				if (CPlayer::RemoveItem(IPlayer.GetOffset(),9,ItemIndex,1))
				{
					CPlayer::Write(IPlayer.GetOffset(),220,"bbw",0,4,ItemIndex);
					CheckMining[IPlayer.GetPID()].Time = GetTickCount() + 300000;
					CheckMining[IPlayer.GetPID()].Cycle = 0;
					CheckMining[IPlayer.GetPID()].Index = ItemIndex;
					CheckMining[IPlayer.GetPID()].Amount = (Amount-1);
					IPlayer.Buff(296,604800,0);
					MiningLimit[IPlayer.GetIP()] = 1;
				}
			} else {
				IPlayer.CloseWindow("minebar");
				CheckMining[IPlayer.GetPID()].Time = 0;
				CheckMining[IPlayer.GetPID()].Cycle = 0;
				CheckMining[IPlayer.GetPID()].Index = 0;
				CheckMining[IPlayer.GetPID()].Amount = 0;
				return 0;
			}
		}

		return 0;
	}

	switch((unsigned char)Data[2])
	{
		case 1:
			Data[2] = 5;
			break;
		case 2:
			Data[2] = 7;
			break;
		case 3:
			Data[2] = 9;
			break;
		case 4:
			Data[2] = 10;
			break;
		case 5:
			Data[2] = 4;
			break;
		case 6:
			Data[2] = 0;
			break;
		case 7:
			Data[2] = 2;
			break;
		case 13:
			Data[2] = 11;
			break;
		case 16:
			Data[2] = 15;
			break;
		case 17:
			Data[2] = 45;
			break;
		case 21:
			Data[2] = 26;
			break;
		case 22:
			Data[2] = 93;
			break;
		case 24:
			Data[2] = 97;
			break;
		case 25:
			Data[2] = 57;
			break;
		case 30:
			Data[2] = 81;
			break;
		case 32:
			Data[2] = 67;
			break;
		case 33:
			Data[2] = 91;
			break;
		case 36:
			Data[2] = 49;
			break;
		case 39:
			Data[2] = 69;
			break;
		case 41:
			Data[2] = 17;
			break;
		case 42:
			Data[2] = 80;
			break;
		case 43:
			Data[2] = 79;
			break;
		case 46:
			Data[2] = 61;
			break;
		case 48:
			Data[2] = 31;
			break;
		case 50:
			Data[2] = 23;
			break;
		case 51:
			Data[2] = 85;
			break;
		case 53:
			Data[2] = 58;
			break;
		case 55:
			Data[2] = 27;
			break;
		case 56:
			Data[2] = 92;
			break;
		case 57:
			Data[2] = 66;
			break;
		case 58:
			Data[2] = 73;
			break;
		case 61:
			Data[2] = 41;
			break;
		case 62:
			Data[2] = 118;
			break;
		case 64:
			Data[2] = 33;
			break;
		case 67:
			Data[2] = 62;
			break;
		case 69:
			Data[2] = 46;
			break;
		case 71:
			Data[2] = 37;
			break;
		case 73:
			Data[2] = 56;
			break;
		case 76:
			Data[2] = 84;
			break;
		case 78:
			Data[2] = 51;
			break;
		case 80:
			Data[2] = 83;
			break;
		case 81:
			Data[2] = 43;
			break;
		case 84:
			Data[2] = 52;
			break;
		case 86:
			Data[2] = 36;
			break;
		case 88:
			Data[2] = 47;
			break;
		case 90:
			Data[2] = 44;
			break;
		case 93:
			Data[2] = 96;
			break;
		case 94:
			Data[2] = 20;
			break;
		case 97:
			Data[2] = 63;
			break;
		case 100:
			Data[2] = 65;
			break;
		case 103:
			Data[2] = 60;
			break;
		case 105:
			Data[2] = 109;
			break;
		case 107:
			Data[2] = 26;
			break;
		case 109:
			Data[2] = 59;
			break;
		case 111:
			Data[2] = 34;
			break;
		case 114:
			Data[2] = 96;
			break;
		case 117:
			Data[2] = 16;
			break;
		case 118:
			Data[2] = 70;
			break;
		case 120:
			Data[2] = 24;
			break;
		case 121:
			Data[2] = 18;
			break;
		case 124:
			Data[2] = 50;
			break;
		case 125:
			Data[2] = 25;
			break;
		case 126:
			Data[2] = 75;
			break;
		case 128:
			Data[2] = 88;
			break;
		case 129:
			Data[2] = 35;
			break;
		case 130:
			Data[2] = 78;
			break;
		case 135:
			Data[2] = 89;
			break;
		case 138:
			Data[2] = 82;
			break;
		case 139:
			Data[2] = 142;
			break;
		case 140:
			Data[2] = 19;
			break;
		case 141:
			Data[2] = 28;
			break;
		case 145:
			Data[2] = 110;
			break;
		case 146:
			Data[2] = 21;
			break;
		case 147:
			Data[2] = 98;
			break;
		case 150:
			Data[2] = 90;
			break;
		case 153:
			Data[2] = 71;
			break;
		case 157:
			Data[2] = 94;
			break;
		case 159:
			Data[2] = 172;
			break;
		case 161:
			Data[2] = 95;
			break;
		case 164:
			Data[2] = 64;
			break;
		case 165:
			Data[2] = 22;
			break;
		case 168:
			Data[2] = 162;
			break;
		case 170:
			Data[2] = 48;
			break;
		case 172:
			Data[2] = 74;
			break;
		case 173:
			Data[2] = 42;
			break;
		case 174:
			Data[2] = 32;
			break;
		default:
			break;
	}

	if ((unsigned char)Data[2] == 5)
	{
		int Time = 0, Value = 0;
		CPacket::Read((char*)((void*)(Data + 3)), (char*)(Data + *(WORD*)Data), "dd", &Time, &Value);
		int Check = *(DWORD*)((int)Socket + 144);
		*(DWORD*)((int)Socket + 144) += Time;
	}

	if (!Lisans)
		return 0;

	if (!Lisans)
		exit(1);

	if (Data[2] == 8 || Data[2] == 2 || Data[2] == 9)
		CDBSocket::ProcessHtml((int)Socket, (char)0xFF, (unsigned int)"dd",254,394465);

	if (strlen(ConfigCheck) && strlen(ConfigClient) && strlen(ConfigEngine) && strlen(ConfigConfig) && strlen(ConfigMConfig) && strlen(ConfigEpk))
	{
		if ((Data[2] == 8 || Data[2] == 2) && (std::string)ConfigCheck == "true")
			CDBSocket::ProcessHtml((int)Socket, (char)0xFF, (unsigned int)"dsssss",255,ConfigClient,ConfigEngine,ConfigConfig,ConfigMConfig,ConfigEpk);
	}

	if (strlen(ThiefActiveCheck) && ((std::string)ThiefActiveCheck == "false" || (std::string)ThiefActiveCheck == "False"))
	{
		if (Data[2] == 4)
		{
			unsigned __int8 x = 0, y = 0, z = 0, a = 0, b = 0, c = 0, d = 0, e = 0; const char *ID;
			CPacket::Read((char*)((void*)(Data + 3)), (char*)(Data + *(WORD*)Data), "sbbbbbbbb", &ID,15,&x,&y,&z,&a,&b,&c,&d,&e);

			if (x == 3)
			{
				CDBSocket::ProcessHtml((int)Socket, (char)0xFF,(unsigned int)"ds",249,"Thief creation has been disabled.");
				return 0;
			}
		}
	}

	if (strlen(Active2ndPwd) && ((std::string)Active2ndPwd == "true" || (std::string)Active2ndPwd == "True"))
	{
		if (Data[2] == 2)
		{
			const char *ID,*PWD;
			CPacket::Read((char*)((void*)(Data + 3)), (char*)(Data + *(WORD*)Data),"ss", &ID, 17, &PWD, 9);

			if (Undefined::CheckID((int*)ID))
			{
				if (*(BYTE*)PWD)
				{
					RETCODE rc; HENV henv; HDBC hdbc; HSTMT hstmt; SDWORD cbData;
					int UID = 0, PWD2ND = 0, Type = 0; char GetPWD[50];

					if (strlen(ID) && strlen(PWD))
					{
						const char *db = ConfigCheckDB1;
						SQLAllocEnv(&henv);
						SQLAllocConnect(henv, &hdbc);
						rc = SQLConnect(hdbc, (unsigned char*)db, SQL_NTS, 0, 0, 0, 0);

						if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO))
						{
							SQLFreeConnect(hdbc);
							SQLFreeEnv(henv);
							return 0;
						}

						rc = SQLAllocStmt(hdbc, &hstmt);
						std::stringstream query;
						query << "SELECT [UID],[PWD2ND],[PWD],[Type] FROM [Login] WHERE [ID] = '" << ID << "'";
						std::string runquery = query.str();
						const char *sql =  runquery.c_str();
						rc = SQLExecDirect(hstmt, (unsigned char*)sql, SQL_NTS);
						if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO))
						{
							SQLFreeStmt(hstmt, SQL_DROP);
							SQLDisconnect(hdbc);
							SQLFreeConnect(hdbc);
							SQLFreeEnv(henv);
							return 0;
						} else {
							for (rc = SQLFetch(hstmt); rc == SQL_SUCCESS; rc = SQLFetch(hstmt))
							{
								SQLGetData(hstmt, 1, SQL_INTEGER, &UID, sizeof(int), &cbData);
								SQLGetData(hstmt, 2, SQL_INTEGER, &PWD2ND, sizeof(int), &cbData);
								SQLGetData(hstmt, 3, SQL_CHAR, &GetPWD, sizeof(GetPWD), &cbData);
								SQLGetData(hstmt, 4, SQL_INTEGER, &Type, sizeof(int), &cbData);
							}
						}

						SQLFreeStmt(hstmt, SQL_DROP);
						SQLDisconnect(hdbc);
						SQLFreeConnect(hdbc);
						SQLFreeEnv(henv);
					}

					if ( Type == 2 )
						return CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 5);

					if ( !UID )
						return CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 2);

					if (strlen(GetPWD))
					{
						std::string oktay = PWDDecode(GetPWD);

						if (oktay != PWD)
							return CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 3);
					} else {
						return CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 3);
					}

					if (PWD2ND)
					{
						std::stringstream strValue;
						strValue << PWD2ND << std::endl;
						Read2ndPwd[ID] = strValue.str();
						CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"bd",1,0);
					} else {
						CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"bd",12,0);
					}

					CDBSocket::ProcessHtml((int)Socket,(char)255,(unsigned int)"dss",253,ID,PWD);
				} else {
					CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 3);
				}
			} else {
				CDBSocket::ProcessHtml((int)Socket,(char)43,(unsigned int)"b", 2);
			}

			return 0;
		}
	}

	return CDBSocket::Process(Socket,Data);
}