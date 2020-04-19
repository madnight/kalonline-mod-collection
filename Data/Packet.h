int __fastcall DBProcess(void *Socket, void *edx, int Data)
{
	void *pPos = (void *)(Data + 3);
	int Type = *(BYTE*)(Data + 2);

	if (Type == 1)
	{
		unsigned long PID = 0, Value = 0, UID = 0;
		Read((char *)pPos, (unsigned int)"ddd", &PID, &Value, &UID);
		DWORD IID = 0, ItemStat = 0;
		xCDB dbItem; CDB(&dbItem);

		if (PID)
		{
			BindDword(&dbItem, &IID);
			BindDword(&dbItem, &ItemStat);

			if (Execute((SQLHSTMT*)&dbItem, "SELECT [IID], [ItemStat] FROM Item WHERE [PID] = %d", PID))
			{
				while (Fetch(&dbItem))
				{
					if (IID && ItemStat)
					{
						Sleep(5);
						ServerSend((int)Socket, 55, "dd", IID,ItemStat);
					}
				}
			}
		}

		FreeCDB(&dbItem);
	}

	if (Type == 25)
	{
		void *MypPos = pPos;
		DWORD RemainLeft;
		xCDB dbItem; CDB(&dbItem);
		int PID = 0, Type = 0, Remain = 0, Value = 0;
		Read((char *)MypPos, (unsigned int)"dbdb", &PID, &Type, &Remain, &Value);

		if (PID && (Type >= 119 && Type <= 155) && Value == 1)
		{
			BindDword(&dbItem, &RemainLeft);
			Execute((SQLHSTMT*)&dbItem, "SELECT [Remain] FROM BuffRemain WHERE [Type] = %d AND [PID] = %d", Type, PID);
			Fetch(&dbItem);

			if ((RemainLeft - time(0)) > 0)
			{
				FreeCDB(&dbItem);
				Sleep(5);
				return ServerSend((int)Socket, 52, "ddd", PID, Type, RemainLeft-time(0));
			}
		}

		FreeCDB(&dbItem);
	}

	if (Type == 81)
	{
		int PID = 0, Point = 0, Type = 0, HP = 0, HK = 0, HD = 0, DKPT = 0, DKPW = 0, PLT = 0, PLW = 0, SVT = 0, SVW = 0, RP = 0;
		xCDB dbItem;
		CDB(&dbItem);
		Read((char *)pPos, (unsigned int)"ddddddddddd", &PID, &HP, &HK, &HD, &DKPT, &DKPW, &PLT, &PLW, &SVT, &SVW, &RP);

		if (PID)
		{
			Execute((SQLHSTMT*)&dbItem, "UPDATE Player SET [HonorPoint] = %d, [HonorKill] = %d, [HonorDeath] = %d, [DKPTotal] = %d, [DKPWin] = %d, [PLTotal] = %d, [PLWin] = %d, [SVTotal] = %d, [SVWin] = %d, [RewardPoint] = %d WHERE [PID] = %d", HP, HK, HD, DKPT, DKPW, PLT, PLW, SVT, SVW, RP, PID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Player SET [HonorPoint] = %d, [HonorKill] = %d, [HonorDeath] = %d, [DKPTotal] = %d, [DKPWin] = %d, [PLTotal] = %d, [PLWin] = %d, [SVTotal] = %d, [SVWin] = %d, [RewardPoint] = %d WHERE [PID] = %d", HP, HK, HD, DKPT, DKPW, PLT, PLW, SVT, SVW, RP, PID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Player SET [HonorPoint] = %d, [HonorKill] = %d, [HonorDeath] = %d, [DKPTotal] = %d, [DKPWin] = %d, [PLTotal] = %d, [PLWin] = %d, [SVTotal] = %d, [SVWin] = %d, [RewardPoint] = %d WHERE [PID] = %d", HP, HK, HD, DKPT, DKPW, PLT, PLW, SVT, SVW, RP, PID);
		}

		return FreeCDB(&dbItem);
	}

	if (Type == 82)
	{
		int PID = 0;
		DWORD HP,HK,HD,DKPT,DKPW,PLT,PLW,SVT,SVW,RP;
		xCDB dbItem;
		CDB(&dbItem);
		Read((char *)pPos, (unsigned int)"d", &PID);

		if (PID)
		{
			BindDword(&dbItem, &HP);
			BindDword(&dbItem, &HK);
			BindDword(&dbItem, &HD);
			BindDword(&dbItem, &DKPT);
			BindDword(&dbItem, &DKPW);
			BindDword(&dbItem, &PLT);
			BindDword(&dbItem, &PLW);
			BindDword(&dbItem, &SVT);
			BindDword(&dbItem, &SVW);
			BindDword(&dbItem, &RP);

			if (Execute((SQLHSTMT*)&dbItem, "SELECT [HonorPoint], [HonorKill], [HonorDeath], [DKPTotal], [DKPWin], [PLTotal], [PLWin], [SVTotal], [SVWin], [RewardPoint] FROM Player WHERE [PID] = %d", PID))
			{
				Fetch(&dbItem);
				Sleep(5);
				ServerSend((int)Socket, 50, "ddddddddddd", PID, HP, HK, HD, DKPT, DKPW, PLT, PLW, SVT, SVW, RP);
			}
		}

		return FreeCDB(&dbItem);
	}

	if (Type == 83)
	{
		int Day = 0, Time = 0, PID = 0;
		xCDB dbItem;
		CDB(&dbItem);
		Read((char *)pPos, (unsigned int)"ddd", &PID, &Day, &Time);

		if (PID)
		{
			Execute((SQLHSTMT*)&dbItem, "UPDATE Player SET [EmokDay] = %d, [EmokTime] = %d WHERE [PID] = %d", Day, Time, PID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Player SET [EmokDay] = %d, [EmokTime] = %d WHERE [PID] = %d", Day, Time, PID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Player SET [EmokDay] = %d, [EmokTime] = %d WHERE [PID] = %d", Day, Time, PID);
		}

		return FreeCDB(&dbItem);
	}

	if (Type == 84)
	{
		int PID = 0;
		DWORD Time, Day;
		xCDB dbItem;
		CDB(&dbItem);
		Read((char *)pPos, (unsigned int)"d", &PID);

		if (PID)
		{
			BindDword(&dbItem, &Time);
			BindDword(&dbItem, &Day);

			if (Execute((SQLHSTMT*)&dbItem, "SELECT [EmokDay], [EmokTime] FROM Player WHERE [PID] = %d", PID))
			{
				Fetch(&dbItem);
				Sleep(5);
				ServerSend((int)Socket, 51, "ddd", PID, Time, Day);
			}
		}

		return FreeCDB(&dbItem);
	}

	if (Type == 85)
	{
		int IID = 0;
		char Lock[17];
		DWORD PetLife = 0, PID = 0;
		unsigned short Index = 0;
		xCDB dbItem; CDB(&dbItem);
		Read((char *)pPos, (unsigned int)"d", &IID);

		if (IID)
		{
			BindDword(&dbItem, &PID);
			BindDword(&dbItem, &PetLife);
			BindString(&dbItem, Lock, 17);

			if (Execute((SQLHSTMT*)&dbItem, "SELECT [PID],[PetTime],[Lock] FROM Item WHERE [IID] = %d", IID))
			{
				Fetch(&dbItem);
				Sleep(5);
				ServerSend((int)Socket, 53, "sdd", Lock, PetLife, IID);
				Sleep(5);
				if (PetLife) ServerSend((int)Socket, 54, "dd", PID, IID);
			}
		}

		FreeCDB(&dbItem);
		return 0;
	}

	if (Type == 86)
	{
		RETCODE rc; HENV henv; HDBC hdbc; HSTMT hstmt;
		int xType = 0; const char *MyID,*PWD2ND;
		Read((char *)pPos, (unsigned int)"ss", &MyID, &PWD2ND);
		std::stringstream strValue;
		strValue << PWD2ND << std::endl;
		int Value = 0;
		strValue >> Value;

		if (MyID != NULL && PWD2ND != NULL)
		{
			const char *db = "kal_auth";
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
			query << "UPDATE Login SET [PWD2ND] = '" << Value << "' WHERE [ID] = '" << MyID << "'";
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
			}

			SQLFreeStmt(hstmt, SQL_DROP);
			SQLDisconnect(hdbc);
			SQLFreeConnect(hdbc);
			SQLFreeEnv(henv);
		}

		return 0;
	}

	if (Type == 87)
	{
		int PID = 0, SetGem = 0, IID = 0;
		xCDB dbItem;
		CDB(&dbItem);
		Read((char *)pPos, (unsigned int)"ddd", &PID, &SetGem, &IID);

		if (PID && IID)
		{
			Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [SetGem] = %d WHERE [PID] = %d AND [IID] = %d", SetGem, PID, IID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [SetGem] = %d WHERE [PID] = %d AND [IID] = %d", SetGem, PID, IID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [SetGem] = %d WHERE [PID] = %d AND [IID] = %d", SetGem, PID, IID);
		}

		return FreeCDB(&dbItem);
	}

	if (Type == 88)
	{
		RETCODE rc; HENV henv; HDBC hdbc; HSTMT hstmt;
		int PID = 0, IID = 0; const char *Lock;
		Read((char *)pPos, (unsigned int)"dsd", &PID, &Lock, &IID);

		if (Lock != NULL && IID)
		{
			const char *db = "kal_db";
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
			query << "UPDATE Item SET [Lock] = '" << Lock << "' WHERE [IID] = '" << IID << "'";
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
			}

			SQLFreeStmt(hstmt, SQL_DROP);
			SQLDisconnect(hdbc);
			SQLFreeConnect(hdbc);
			SQLFreeEnv(henv);
		}

		return 0;
	}

	if (Type == 89)
	{
		int PID = 0, IID = 0, PetLife = 0;
		xCDB dbItem;
		CDB(&dbItem);
		Read((char *)pPos, (unsigned int)"ddd", &PID, &PetLife, &IID);

		if (PID && IID && PetLife)
		{
			Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [PetTime] = %d WHERE [PID] = %d AND [IID] = %d", PetLife, PID, IID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [PetTime] = %d WHERE [PID] = %d AND [IID] = %d", PetLife, PID, IID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [PetTime] = %d WHERE [PID] = %d AND [IID] = %d", PetLife, PID, IID);
		}

		return FreeCDB(&dbItem);
	}

	if (Type == 90)
	{
		int PID = 0, IID = 0, ItemStat = 0;
		xCDB dbItem;
		CDB(&dbItem);
		Read((char *)pPos, (unsigned int)"ddd", &PID, &ItemStat, &IID);

		if (PID && IID)
		{
			Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [ItemStat] = %d WHERE [PID] = %d AND [IID] = %d", ItemStat, PID, IID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [ItemStat] = %d WHERE [PID] = %d AND [IID] = %d", ItemStat, PID, IID);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [ItemStat] = %d WHERE [PID] = %d AND [IID] = %d", ItemStat, PID, IID);
		}

		return FreeCDB(&dbItem);
	}

	if (Type == 91)
	{
		int PID = 0, Quest = 0, Time = 0, Repeat = 0, Count = 0;
		xCDB dbItem;
		CDB(&dbItem);
		Read((char *)pPos, (unsigned int)"ddddd", &PID, &Quest, &Repeat, &Count, &Time);

		if (PID && Quest)
		{
			Execute((SQLHSTMT*)&dbItem, "UPDATE Quest SET [QuestTime] = %d, [QuestRepeat] = %d, [MonsterCount] = %d WHERE [PID] = %d AND [Quest] = %d", Time, Repeat, Count, PID, Quest);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Quest SET [QuestTime] = %d, [QuestRepeat] = %d, [MonsterCount] = %d WHERE [PID] = %d AND [Quest] = %d", Time, Repeat, Count, PID, Quest);
			Execute((SQLHSTMT*)&dbItem, "UPDATE Quest SET [QuestTime] = %d, [QuestRepeat] = %d, [MonsterCount] = %d WHERE [PID] = %d AND [Quest] = %d", Time, Repeat, Count, PID, Quest);
		}

		return FreeCDB(&dbItem);
	}

	if (Type == 92)
	{
		int PID = 0; DWORD QuestID = 0, QuestClear = 0, QuestTime = 0, QuestRepeat = 0, MonsterCount = 0;
		xCDB ydbItem;
		CDB(&ydbItem);
		Read((char *)pPos, (unsigned int)"d", &PID);

		if (PID)
		{
			BindDword(&ydbItem, &QuestID);
			BindDword(&ydbItem, &QuestClear);
			BindDword(&ydbItem, &QuestTime);
			BindDword(&ydbItem, &QuestRepeat);
			BindDword(&ydbItem, &MonsterCount);

			if (Execute((SQLHSTMT*)&ydbItem, "SELECT TOP 100 [Quest], [Clear], [QuestTime], [QuestRepeat], [MonsterCount] FROM Quest WHERE [PID] = %d", PID))
			{
				while (Fetch(&ydbItem))
				{
					if (QuestID)
					{
						Sleep(5);
						ServerSend((int)Socket, 56, "dddddd", PID, QuestID, QuestClear, QuestTime, QuestRepeat, MonsterCount);
					}
				}
			}
		}

		return FreeCDB(&ydbItem);
	}

	return Process(Socket,Data);
}