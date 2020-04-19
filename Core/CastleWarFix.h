int __fastcall WarEnd(void *Value, void *edx)
{
	int GID = 0, AlliGID = 0;
	RETCODE rcx; HENV henvx; HDBC hdbcx; HSTMT hstmtx; SDWORD cbData;
	const char *db = ConfigCheckDB2;
	SQLAllocEnv(&henvx);
	SQLAllocConnect(henvx, &hdbcx);
	rcx = SQLConnect(hdbcx, (unsigned char*)db, SQL_NTS, 0, 0, 0, 0);

	if ((rcx != SQL_SUCCESS) && (rcx != SQL_SUCCESS_WITH_INFO))
	{
		SQLFreeConnect(hdbcx);
		SQLFreeEnv(henvx);
		return CCastle::WarEnd(Value);
	}

	rcx = SQLAllocStmt(hdbcx, &hstmtx);
	std::stringstream query;
	query << "SELECT [GID] FROM [GuildCastle]";
	std::string runquery = query.str();
	const char *sql =  runquery.c_str();
	rcx = SQLExecDirect(hstmtx, (unsigned char*)sql, SQL_NTS);
	
	if ((rcx != SQL_SUCCESS) && (rcx != SQL_SUCCESS_WITH_INFO))
	{
		SQLFreeStmt(hstmtx, SQL_DROP);
		SQLDisconnect(hdbcx);
		SQLFreeConnect(hdbcx);
		SQLFreeEnv(henvx);
		return CCastle::WarEnd(Value);
	} else{
		for (rcx = SQLFetch(hstmtx); rcx == SQL_SUCCESS; rcx = SQLFetch(hstmtx))
			SQLGetData(hstmtx, 1, SQL_INTEGER, &GID, sizeof(int), &cbData);
	}

	if (GID)
	{
		CIOCriticalSection::Enter((void*)0x004e2078);
		CIOCriticalSection::Enter((void*)0x004e2098);
		CLink::MoveTo((void*)0x004e200c,(int)0x004e2004);
		CIOCriticalSection::Leave((void*)0x004e2098);
		for (DWORD i = *(DWORD*)0x004E2004; i != 0x004E2004; i = *(DWORD*)i)
		{
			IChar CheckGID((void*)(i - 428));

			if (CheckGID.IsOnline() && CheckGID.GetGID() == GID)
			{
				AlliGID = CheckGID.GetAlliance();
				break;
			}
		}
		CIOCriticalSection::Leave((void*)0x004e2078);
		CIOCriticalSection::Enter((void*)0x004e2078);
		CIOCriticalSection::Enter((void*)0x004e2098);
		CLink::MoveTo((void*)0x004e200c,(int)0x004e2004);
		CIOCriticalSection::Leave((void*)0x004e2098);
		for (DWORD i = *(DWORD*)0x004E2004; i != 0x004E2004; i = *(DWORD*)i)
		{
			IChar CwReward((void*)(i - 428));

			if (CwReward.IsOnline() && CwReward.GetGID() && CwReward.GetGID() == GID)
			{
				CheckHonor[CwReward.GetPID()].RPx += 1500;
				CheckHonor[CwReward.GetPID()].HPx += 1500;
			}

			if (CwReward.IsOnline() && CwReward.GetGID() && CwReward.GetGID() == AlliGID)
			{
				CheckHonor[CwReward.GetPID()].RPx += 1000;
				CheckHonor[CwReward.GetPID()].HPx += 1000;
			}

			if (CwReward.IsOnline() && CwReward.GetGID() && CwReward.GetGID() != GID && CwReward.GetGID() != AlliGID && CwReward.IsBuff(377))
			{
				CheckHonor[CwReward.GetPID()].RPx += 500;
				CheckHonor[CwReward.GetPID()].HPx += 500;
			}
		}
		CIOCriticalSection::Leave((void*)0x4e2078);
	}

	SQLFreeStmt(hstmtx, SQL_DROP);
	SQLDisconnect(hdbcx);
	SQLFreeConnect(hdbcx);
	SQLFreeEnv(henvx);
	return CCastle::WarEnd(Value);
}

int __fastcall GuildWarDamage(void *Target, void *edx, int Player, int Damage, int a4, int a5, int a6, int a7)
{
	IChar IPlayer((void*)Player);
	IChar ITarget(Target);
	int Argument = 0, v13 = 0, v14 = 0, v10 = 0, Flag = 0, Gate = 0;
	*(DWORD*)a6 = 0;

	if (Damage < 0)
		return 0;

	if (a7)
		Argument = (*(int (__thiscall **)(int))(*(DWORD *)a7 + 52))(a7);
	else
		Argument = 1;

	if (Argument && IPlayer.IsValid() && ITarget.IsValid())
	{
		v13 = CChar::GetFinalDamage(Target, Player, Damage, Argument);

		if (v13 > 0)
		{
			CChar::Lock(Target);

			if (CChar::IsNormal((int)Target))
			{
				v14 = v13 + CChar::GetFatalDamage(Player, v13, a5, 0);

				if (v14 >= (int)*((DWORD*)Target + 68))
					v10 = *((DWORD*)Target + 68);
				else
					v10 = v14;

				*(DWORD *)a4 = v10;
				*((DWORD *)Target + 68) -= *(DWORD *)a4;
				*((DWORD *)Target + 118) = GetTickCount() + 20000;

				if (*((DWORD *)Target + 68) > 0)
				{
					CChar::Unlock(Target);
				} else {
					*((DWORD *)Target + 68) = 0;
					(*(void (__thiscall **)(int, DWORD, DWORD))(*(DWORD *)Player + 76))(Player,*((DWORD *)Target + 7),*(DWORD *)a5);
					CChar::WriteInSight(Target, 61, "db", *((DWORD *)Target + 7), 9);
					CChar::Unlock(Target);

					if (CInitMonster::IsRace(*((DWORD*)Target + 110),2))
					{
						Flag = CCastle::GetMonsterTile2CID(*((DWORD *)Target + 79),*((DWORD *)Target + 83),*((DWORD *)Target + 84));
						CGuild::BrokenStandard(Flag);
					} else {
						if (CInitMonster::IsRace(*((DWORD*)Target + 110),3))
						{
							Gate = CCastle::GetMonsterTile2CID(*((DWORD *)Target + 79),*((DWORD *)Target + 83),*((DWORD *)Target + 84));
							CGuild::BrokenGate(Gate, (int)Target);
						}
					}

					CBase::Delete(Target);
				}

				return 1;
			} else {
				CChar::Unlock(Target);
				return 1;
			}
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}