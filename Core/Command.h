void __fastcall ChatCommand(int Player, void *edx, const char *command)
{
    if (!strlen(command)) {
        return;
    }

    std::string cmd = (std::string)command;
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline() && !CChar::IsGState((int)IPlayer.GetOffset(), 2)
        && !CChar::IsGState((int)IPlayer.GetOffset(), 256) &&
        cmd.substr(0, 5) == "/naro")
    {
        IPlayer.Teleport(0, 258042, 259367);
        return;
    }

    if (IPlayer.IsOnline() && !CChar::IsGState((int)IPlayer.GetOffset(), 2)
        && !CChar::IsGState((int)IPlayer.GetOffset(), 256)
        && cmd.substr(0, 6) == "/cargo")
    {
        IPlayer.Teleport(0, 265073, 262622);
        return;
    }

    if (IPlayer.IsOnline() && !CChar::IsGState((int)IPlayer.GetOffset(), 2)
        && !CChar::IsGState((int)IPlayer.GetOffset(), 256) &&
        cmd.substr(0, 5) == "/fort")
    {
        IPlayer.Teleport(0, 267586, 242863);
        return;
    }

    if (IPlayer.IsOnline() && !CChar::IsGState((int)IPlayer.GetOffset(), 2)
        && !CChar::IsGState((int)IPlayer.GetOffset(), 256) &&
        cmd.substr(0, 5) == "/mine")
    {
        IPlayer.Teleport(0, 266056, 284973);
        return;
    }

    if (IPlayer.IsOnline() && !CChar::IsGState((int)IPlayer.GetOffset(), 2)
        && !CChar::IsGState((int)IPlayer.GetOffset(), 256) &&
        cmd.substr(0, 5) == "/bird")
    {
        IPlayer.Teleport(0, 255764, 288738);
        return;
    }

    if (IPlayer.IsOnline() && !CChar::IsGState((int)IPlayer.GetOffset(), 2)
        && !CChar::IsGState((int)IPlayer.GetOffset(), 256) &&
        cmd.substr(0, 4) == "/cop")
    {
        IPlayer.Teleport(0, 232922, 294650);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && cmd.substr(0, 8) == "/warinfo")
    {
        int war = CPlayer::CountWarrelationPlayer();
        std::string msg = "War Info: " + Int2String(war);
        IPlayer.SystemMessage(msg, TEXTCOLOR_GREEN);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && cmd.substr(0, 14) == "/protectleader")
    {
        if (Protect32::Active == false)
        {
            if (ProtectLeaderList.size() > 1)
            {
                std::random_shuffle(ProtectLeaderList.begin(), ProtectLeaderList.end());
                Protect32::GuildFirst = ProtectLeaderList.front();
                ProtectLeaderList.erase(ProtectLeaderList.begin());
                std::random_shuffle(ProtectLeaderList.begin(), ProtectLeaderList.end());
                Protect32::GuildSecond = ProtectLeaderList.front();
                ProtectLeaderList.erase(ProtectLeaderList.begin());
                Protect32::FirstGuild = ProtectLeaderName.find(Protect32::GuildFirst)->second;
                Protect32::SecondGuild = ProtectLeaderName.find(Protect32::GuildSecond)->second;
                ProtectLeaderList.clear();
                ProtectLeaderName.clear();
                std::string msg = "Protecting Leader started between ";
                msg = msg + Protect32::FirstGuild;
                msg = msg + " guild and ";
                msg = msg + Protect32::SecondGuild;
                msg = msg + " guild.";
                CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 2);
                Protect32::Prayer = 0;
                Protect32::RedScore = 0;
                Protect32::BlueScore = 0;
                Protect32::RedWin = 0;
                Protect32::BlueWin = 0;
                Protect32::Winner = 0;
                Protect32::RedPrayerTime = 0;
                Protect32::BluePrayerTime = 0;
                Protect32::Round = 1;
                Protect32::Time = 1260;
                Protect32::Active = true;
            } else {
                CPlayer::WriteAll(0xFF, "dsd", 247,
                    "Enough guilds did not registered for Protecting Leader.", 2);
            }
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3 &&
        cmd.substr(0, 5) == "/ugog")
    {
        int Around = IPlayer.GetObjectListAround(50);

        while (Around)
        {
            IChar Object((void*)*(DWORD*)Around);

            if (Object.IsValid() && IPlayer.IsValid())
            {
                if (Object.GetType() == 0 && Object.GetZ() != IPlayer.GetZ()) {
                    IPlayer.SystemMessage(Object.GetName(), TEXTCOLOR_SHUTDOWN);
                }
            }

            Around = CBaseList::Pop((void*)Around);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8 && cmd.substr(0, 4) == "/lms")
    {
        if (LastManStand::Active == false)
        {
            if (LastManRegistration.size() > 1)
            {
                CPlayer::WriteAll(0xFF, "dsd", 247, "Last Man Standing started.", 2);
                LastManStand::Active = true;
                LastManStand::Time = 3;
            } else {
                CPlayer::WriteAll(0xFF, "dsd", 247,
                    "Enough players did not registered for Last Man Standing.", 2);
            }
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8
        && cmd.substr(0, 10) == "/cwdeclare")
    {
        *(DWORD**)0x004E0964 = (DWORD*)1;
        CPlayer::WriteAll(0xFF, "dsd", 247, "Guilds can declare for castle war.", 2);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8
        && cmd.substr(0, 13) == "/endcwdeclare")
    {
        *(DWORD**)0x004E0964 = (DWORD*)0;
        CPlayer::WriteAll(0xFF, "dsd", 247, "Declare for castle war ended.", 2);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8
        && sscanf(command, "/cwstart %d", &cwtotaltime) == 1)
    {
        time_t MyTime = time(0);
        struct tm *Time = localtime(&MyTime);

        if ((int)*(DWORD**)0x004E0964 != 4 && cwtotaltime)
        {
            int SetCwTime = MyTime;
            SetCwTime += cwtotaltime;
            *(DWORD**)0x004E0964 = (DWORD*)4;
            CCastle::WarBegin(SetCwTime);
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && sscanf(command,
            "/mute %d %[a-z | A-Z | 0-9/<>|.,~*;`:!'^+%&/()=?_-£#${[]}€]", &mutetime,
            &mutename) == 2)
    {
        if (!strlen(mutename)) {
            return;
        }

        const char *PlayerName = mutename;
        IChar Target((void*)CPlayer::FindPlayerByName((char)PlayerName));

        if (Target.IsOnline() && mutetime)
        {
            Target.Buff(164, mutetime, 0);
            Mute[Target.GetPID()] = (mutetime * 1000) + GetTickCount();
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 11
        && sscanf(command,
            "/donate -a %d -n %[a-z | A-Z | 0-9/<>|.,~*;`:!'^+%&/()=?_-£#${[]}€]",
            &donateamount, &donatename) == 2)
    {
        if (!strlen(donatename)) {
            return;
        }

        int Item, ValidItem = 0;
        const char *PlayerName = donatename;
        IChar Target((void*)CPlayer::FindPlayerByName((char)PlayerName));

        if (Target.IsOnline() && donateamount)
        {
            if (CPlayer::FindItem(Target.GetOffset(), DonationCoin, 1))
            {
                Item = CPlayer::FindItem(Target.GetOffset(), DonationCoin, 1);

                if (Item)
                {
                    (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                        (*(DWORD*)Item + 120))(Item, Target.GetOffset(), 9, donateamount);
                    Target.SystemMessage("You have received Donation Coin.", TEXTCOLOR_PINK);
                    IPlayer.SystemMessage("Donation Coin arrived to player successfully.",
                        TEXTCOLOR_PINK);
                }
            } else {
                if (CPlayer::GetInvenSize((int)Target.GetOffset()) < IPlayer.MaxInventorySize())
                {
                    Item = CItem::CreateItem(DonationCoin, 0, donateamount, -1);

                    if (Item)
                    {
                        IItem IItem((void*)Item);
                        ValidItem = CPlayer::_InsertItem(Target.GetOffset(), 7, Item);

                        if (ValidItem == 1)
                        {
                            Target.SystemMessage("You have received Donation Coin.", TEXTCOLOR_PINK);
                            IPlayer.SystemMessage("Donation Coin arrived to player successfully.",
                                TEXTCOLOR_PINK);
                        } else {
                            IPlayer.SystemMessage("Donation Coin did not arrived.", TEXTCOLOR_PINK);
                        }
                    }
                } else {
                    IPlayer.SystemMessage("Donation Coin did not arrived because player inventory is full.",
                        TEXTCOLOR_PINK);
                }
            }
        } else {
            IPlayer.SystemMessage("Player is offline.", TEXTCOLOR_RED);
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8
        && sscanf(command, "/summon -i %d -a %d", &summonindex, &summonamount) == 2)
    {
        if (summonindex && summonamount)
        {
            for (int i = 0; i < summonamount; i++)
            {
                Summon(0, IPlayer.GetMap(), IPlayer.GetX(), IPlayer.GetY(), summonindex, 1, 1,
                    0, 0, 0);
            }
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8
        && sscanf(command, "/buff %d", &buffid) == 1)
    {
        IPlayer.Buff(buffid, 3600, 50);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && sscanf(command, "/speed %d", &speedvalue) == 1)
    {
        IPlayer.Buff(12, 1800, speedvalue);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 11
        && sscanf(command, "/geons %d", &geonamount) == 1)
    {
        if (geonamount) {
            CItem::InsertItem((int)IPlayer.Offset, 27, 31, 0, geonamount, -1);
        }

        return;
    }

    if (IPlayer.IsOnline() && cmd.substr(0, 8) == "/suicide")
    {
        if (IPlayer.IsBuff(378)) {
            return;
        }

        if (IPlayer.IsBuff(160) || IPlayer.IsBuff(161)) {
            return;
        }

        if (IPlayer.IsBuff(162) || IPlayer.IsBuff(163)) {
            return;
        }

        if (IPlayer.IsBuff(166)) {
            return;
        }

        if (IPlayer.IsBuff(170) || IPlayer.IsBuff(171)) {
            return;
        }

        if (IPlayer.IsBuff(373) || IPlayer.IsBuff(374)) {
            return;
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8
        && cmd.substr(0, 15) == "/dueltournament" && DuelTournament::Active == false)
    {
        if (DuelTournamentList.size() > 1)
        {
            CPlayer::WriteAll(0xFF, "dsd", 247, "Duel Tournament started.", 2);
            DuelTournament::Active = true;
            DuelTournament::RegisterAmount = 0;
            DuelTournament::Delay = 15;
            DuelTournament::FirstPlayer = 0;
            DuelTournament::SecondPlayer = 0;
            DuelTournament::RedScore = 0;
            DuelTournament::BlueScore = 0;
            DuelTournament::SelectPlayers = true;
            DuelTournamentRegistration.clear();
            _beginthread(DuelTournamentSelection, 0, 0);
        } else {
            CPlayer::WriteAll(0xFF, "dsd", 247,
                "Enough players did not registered for Duel Tournament.", 2);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8 && cmd.substr(0, 4) == "/f10"
        && F10::Active == false)
    {
        if (F10::RegisterAmount > 0)
        {
            F10::CheiosSkillDelay = 0;
            F10::DunamicSkillDelay = 0;
            F10::Dunamic = 0;
            F10::Cheios = 0;
            F10::KillCount = 0;
            F10::RegisterAmount = 0;
            F10::Active = true;
            CPlayer::WriteAll(0xFF, "dsd", 247, "Ilyer Company System started.", 2);
            Summon(0, 21, 117339, 36841, 573, 1, 0, 3700000, 3700000, 0);
            return;
        } else {
            CPlayer::WriteAll(0xFF, "dsd", 247,
                "Enough players did not registered for Ilyer Company System.", 2);
            return;
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8
        && cmd.substr(0, 12) == "/destructing" && Scenario::Active == false)
    {
        if (Scenario::RegisterAmount > 1)
        {
            int First = 0, Second = 0;

            if (Scenario::RegisterAmount <= 3)
            {
                First = Scenario::RegisterAmount / 2;
                Second = Scenario::RegisterAmount / 1;
            } else {
                First = Scenario::RegisterAmount / 2;
                Second = Scenario::RegisterAmount / 3;
            }

            Scenario::GuildFirst = ScenarioGuildID.find(First)->second;
            Scenario::GuildSecond = ScenarioGuildID.find(Second)->second;
            Scenario::FirstGuild = ScenarioGuildName.find(First)->second;
            Scenario::SecondGuild = ScenarioGuildName.find(Second)->second;
            std::string msg = "Destructing Key Points started between ";
            msg = msg + ScenarioGuildName.find(First)->second;
            msg = msg + " guild and ";
            msg = msg + ScenarioGuildName.find(Second)->second;
            msg = msg + " guild.";
            CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 2);
            Scenario::Time = ScenarioTime;
            Scenario::RedScore = 0;
            Scenario::BlueScore = 0;
            Scenario::BlueTeamSeal = 0;
            Scenario::RedTeamSeal = 0;
            Scenario::BlueTeamTowerCount = 0;
            Scenario::RedTeamTowerCount = 0;

            for (int i = 0; i <= Scenario::RegisterAmount; i++)
            {
                ScenarioGuildID[i] = 0;
            }

            Scenario::RegisterAmount = 0;
            Scenario::Active = true;
            Summon(0, ScenarioMap, 286786, 351034, 360, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 286239, 351036, 352, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 285936, 351318, 354, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 286589, 350285, 354, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 285808, 350665, 354, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 287677, 350530, 354, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 286479, 351338, 354, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 286999, 351590, 354, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 287353, 351038, 356, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 285935, 351547, 358, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 286590, 350494, 358, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 287677, 350756, 358, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 287777, 351408, 358, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 287113, 350741, 358, 1, 0, 0, 0, 0);
            Summon(0, ScenarioMap, 287001, 351787, 358, 1, 0, 0, 0, 0);
        } else {
            CPlayer::WriteAll(0xFF, "dsd", 247,
                "Enough guilds did not registered for Destructing Key Points.", 2);
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8
        && cmd.substr(0, 12) == "/battlefield" && Battlefield::Active == false)
    {
        if (Battlefield::RegisterAmount > 1)
        {
            CPlayer::WriteAll(0xFF, "dsd", 247, "Battlefield started.", 2);
            Battlefield::Time = BFTime;
            Battlefield::RedScore = 0;
            Battlefield::BlueScore = 0;
            Battlefield::RegisterAmount = 0;
            IPlayer.SystemMessage("Battlefield started.", TEXTCOLOR_GREEN);
            Battlefield::Active = true;
            IChar M1((void*)Summon(0, BFMap, 274761, 212814, 445, 1, 0, 0, 0, 0));
            IChar M2((void*)Summon(0, BFMap, 278472, 209291, 445, 1, 0, 0, 0, 0));
            IChar M3((void*)Summon(0, BFMap, 278441, 212986, 445, 1, 0, 0, 0, 0));
            IChar m1((void*)Summon(0, BFMap, 278531, 212982, 448, 1, 0, 0, 0, 0));
            IChar m2((void*)Summon(0, BFMap, 278706, 216690, 448, 1, 0, 0, 0, 0));
            IChar m3((void*)Summon(0, BFMap, 282215, 213033, 448, 1, 0, 0, 0, 0));
            Battlefield::BlueStoneID[0] = M1.GetID();
            Battlefield::BlueStoneID[1] = M2.GetID();
            Battlefield::BlueStoneID[2] = M3.GetID();
            Battlefield::RedStoneID[0] = m1.GetID();
            Battlefield::RedStoneID[1] = m2.GetID();
            Battlefield::RedStoneID[2] = m3.GetID();
            return;
        } else {
            CPlayer::WriteAll(0xFF, "dsd", 247,
                "Enough players did not registered for Battlefield.", 2);
            return;
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && sscanf(command,
            "/boxnotice %[a-z | A-Z | 0-9/<>|.,~*;`:!'^+%&/()=?_-£#${[]}€]",
            &boxnotice) == 1)
    {
        if (strlen(boxnotice)) {
            CPlayer::WriteAll(0xFF, "ds", 249, boxnotice);
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 8
        && cmd.substr(0, 7) == "/reload")
    {
        ReadConfig();
        IPlayer.SystemMessage("Configs reloaded successfully.", TEXTCOLOR_GREEN);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && cmd.substr(0, 7) == "/online")
    {
        int number = 0;
        CIOCriticalSection::Enter((void*)0x4e2078);
        CIOCriticalSection::Enter((void*)0x4e2098);
        CLink::MoveTo((void*)0x4e200c, (int)0x4e2004);
        CIOCriticalSection::Leave((void*)0x4e2098);

        for (DWORD i = *(DWORD*)0x4E2004; i != 0x4E2004; i = *(DWORD*)i)
        {
            if ((void*)(i - 428)) {
                number++;
            }
        }

        CIOCriticalSection::Leave((void*)0x4e2078);
        std::stringstream onlineplayer;
        onlineplayer << "Players Online : " << number;
        std::string onlineamount = onlineplayer.str();
        IPlayer.SystemMessage(onlineamount.c_str(), TEXTCOLOR_INFOMSG);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && sscanf(command, "/moveto %[a-z | A-Z | 0-9/<>|.,~*;`:!'^+%&/()=?_-£#${[]}€]",
            &moveto) == 1)
    {
        if (strlen(moveto))
        {
            const char *PlayerName = moveto;
            IChar Target((void*)CPlayer::FindPlayerByName((char)PlayerName));

            if (Target.IsOnline()) {
                IPlayer.Teleport(Target.GetMap(), Target.GetX(), Target.GetY());
            }
        }

        return;
    }

    if (IPlayer.IsOnline() && cmd.substr(0, 11) == "/servertime")
    {
        std::stringstream servertime;
        servertime << "Server Time : " << Time::GetTime();
        std::string time = servertime.str();
        IPlayer.SystemMessage(time.c_str(), TEXTCOLOR_INFOMSG);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && cmd.substr(0, 7) == "/uptime")
    {
        time_t diff = difftime(time(NULL), uptimestart);
        const unsigned int SECS_PER_DAY = 60 * 60 * 24;
        const unsigned int SECS_PER_HR  = 60 * 60;
        const unsigned int SECS_PER_MIN = 60;
        unsigned int days  = diff / SECS_PER_DAY;
        diff = diff % SECS_PER_DAY;
        unsigned int hours = diff / SECS_PER_HR;
        diff = diff % SECS_PER_HR;
        unsigned int minutes = diff / SECS_PER_MIN;
        diff = diff % SECS_PER_MIN;
        unsigned int seconds = diff;
        std::stringstream uptime;
        uptime << "Server Uptime : " << days << " Days " << hours << " Hours " <<
            minutes << " Minutes " << seconds << " Seconds.";
        std::string showuptime = uptime.str();
        IPlayer.SystemMessage(showuptime.c_str(), TEXTCOLOR_INFOMSG);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && sscanf(command,
            "/newnotice %d %[a-z | A-Z | 0-9/<>|.,~*;`:!'^+%&/()=?_-£#${[]}€]",
            &newnoticetype, &newnotice) == 2)
    {
        if (strlen(newnotice)) {
            CPlayer::WriteAll(0xFF, "dsd", 247, newnotice, newnoticetype);
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && sscanf(command,
            "/hardblock %[a-z | A-Z | 0-9/<>|.,~*;`:!'^+%&/()=?_-£#${[]}€]",
            &hardblock) == 1)
    {
        if (!strlen(hardblock)) {
            return;
        }

        RETCODE rcc;
        HENV henvc;
        HDBC hdbcc;
        HSTMT hstmtc;
        SDWORD cbDatac;
        int UID = 0;
        const char *dbc = ConfigCheckDB2;
        SQLAllocEnv(&henvc);
        SQLAllocConnect(henvc, &hdbcc);
        rcc = SQLConnect(hdbcc, (unsigned char*)dbc, SQL_NTS, 0, 0, 0, 0);

        if ((rcc != SQL_SUCCESS) && (rcc != SQL_SUCCESS_WITH_INFO))
        {
            SQLFreeConnect(hdbcc);
            SQLFreeEnv(henvc);
            return;
        }

        rcc = SQLAllocStmt(hdbcc, &hstmtc);
        std::stringstream query;
        query << "SELECT [UID] FROM [Player] WHERE [Name] = '" << hardblock << "'";
        std::string runquery = query.str();
        const char *sql =  runquery.c_str();
        rcc = SQLExecDirect(hstmtc, (unsigned char*)sql, SQL_NTS);

        if ((rcc != SQL_SUCCESS) && (rcc != SQL_SUCCESS_WITH_INFO))
        {
            SQLFreeStmt(hstmtc, SQL_DROP);
            SQLDisconnect(hdbcc);
            SQLFreeConnect(hdbcc);
            SQLFreeEnv(henvc);
            return;
        } else {
            for (rcc = SQLFetch(hstmtc); rcc == SQL_SUCCESS; rcc = SQLFetch(hstmtc)) {
                SQLGetData(hstmtc, 1, SQL_INTEGER, &UID, sizeof(int), &cbDatac);
            }
        }

        SQLFreeStmt(hstmtc, SQL_DROP);
        SQLDisconnect(hdbcc);
        SQLFreeConnect(hdbcc);
        SQLFreeEnv(henvc);

        if (UID)
        {
            RETCODE rcb;
            HENV henvb;
            HDBC hdbcb;
            HSTMT hstmtb;
            const char *dbb = ConfigCheckDB1;
            SQLAllocEnv(&henvb);
            SQLAllocConnect(henvb, &hdbcb);
            rcb = SQLConnect(hdbcb, (unsigned char*)dbb, SQL_NTS, 0, 0, 0, 0);

            if ((rcb != SQL_SUCCESS) && (rcb != SQL_SUCCESS_WITH_INFO))
            {
                SQLFreeConnect(hdbcb);
                SQLFreeEnv(henvb);
                return;
            }

            rcb = SQLAllocStmt(hdbcb, &hstmtb);
            std::stringstream query;
            query << "UPDATE [Login] SET [Type] = 2 WHERE [UID] = '" << UID << "'";
            std::string runquery = query.str();
            const char *sql =  runquery.c_str();
            rcb = SQLExecDirect(hstmtb, (unsigned char*)sql, SQL_NTS);

            if ((rcb != SQL_SUCCESS) && (rcb != SQL_SUCCESS_WITH_INFO))
            {
                SQLFreeStmt(hstmtb, SQL_DROP);
                SQLDisconnect(hdbcb);
                SQLFreeConnect(hdbcb);
                SQLFreeEnv(henvb);
                return;
            }

            SQLFreeStmt(hstmtb, SQL_DROP);
            SQLDisconnect(hdbcb);
            SQLFreeConnect(hdbcb);
            SQLFreeEnv(henvb);
            const char *Player = hardblock;
            IChar Target((void*)CPlayer::FindPlayerByName((char)Player));
            IPlayer.SystemMessage("Player successfully blocked.", TEXTCOLOR_GREEN);

            if (Target.IsOnline())
            {
                PlayerBlockCheck[Target.GetUID()] = 1;
                Target.SystemMessage("Your account has been blocked.", TEXTCOLOR_RED);
                CPlayer::Write(Target.GetOffset(), 0xFF, "d", 246);
                Target.Kick();
            }
        } else {
            IPlayer.SystemMessage("Could not block player.", TEXTCOLOR_GREEN);
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && sscanf(command, "/block %[a-z | A-Z | 0-9/<>|.,~*;`:!'^+%&/()=?_-£#${[]}€]",
            &block) == 1)
    {
        if (!strlen(block)) {
            return;
        }

        RETCODE rcd;
        HENV henvd;
        HDBC hdbcd;
        HSTMT hstmtd;
        SDWORD cbDatad;
        int UID = 0;
        const char *dbd = ConfigCheckDB2;
        SQLAllocEnv(&henvd);
        SQLAllocConnect(henvd, &hdbcd);
        rcd = SQLConnect(hdbcd, (unsigned char*)dbd, SQL_NTS, 0, 0, 0, 0);

        if ((rcd != SQL_SUCCESS) && (rcd != SQL_SUCCESS_WITH_INFO))
        {
            SQLFreeConnect(hdbcd);
            SQLFreeEnv(henvd);
            return;
        }

        rcd = SQLAllocStmt(hdbcd, &hstmtd);
        std::stringstream query;
        query << "SELECT [UID] FROM [Player] WHERE [Name] = '" << block << "'";
        std::string runquery = query.str();
        const char *sql =  runquery.c_str();
        rcd = SQLExecDirect(hstmtd, (unsigned char*)sql, SQL_NTS);

        if ((rcd != SQL_SUCCESS) && (rcd != SQL_SUCCESS_WITH_INFO))
        {
            SQLFreeStmt(hstmtd, SQL_DROP);
            SQLDisconnect(hdbcd);
            SQLFreeConnect(hdbcd);
            SQLFreeEnv(henvd);
            return;
        } else {
            for (rcd = SQLFetch(hstmtd); rcd == SQL_SUCCESS; rcd = SQLFetch(hstmtd)) {
                SQLGetData(hstmtd, 1, SQL_INTEGER, &UID, sizeof(int), &cbDatad);
            }
        }

        SQLFreeStmt(hstmtd, SQL_DROP);
        SQLDisconnect(hdbcd);
        SQLFreeConnect(hdbcd);
        SQLFreeEnv(henvd);

        if (UID)
        {
            RETCODE rce;
            HENV henve;
            HDBC hdbce;
            HSTMT hstmte;
            const char *db = ConfigCheckDB1;
            SQLAllocEnv(&henve);
            SQLAllocConnect(henve, &hdbce);
            rce = SQLConnect(hdbce, (unsigned char*)db, SQL_NTS, 0, 0, 0, 0);

            if ((rce != SQL_SUCCESS) && (rce != SQL_SUCCESS_WITH_INFO))
            {
                SQLFreeConnect(hdbce);
                SQLFreeEnv(henve);
                return;
            }

            rce = SQLAllocStmt(hdbce, &hstmte);
            std::stringstream query;
            query << "UPDATE [Login] SET [Type] = 2 WHERE [UID] = '" << UID << "'";
            std::string runquery = query.str();
            const char *sql =  runquery.c_str();
            rce = SQLExecDirect(hstmte, (unsigned char*)sql, SQL_NTS);

            if ((rce != SQL_SUCCESS) && (rce != SQL_SUCCESS_WITH_INFO))
            {
                SQLFreeStmt(hstmte, SQL_DROP);
                SQLDisconnect(hdbce);
                SQLFreeConnect(hdbce);
                SQLFreeEnv(henve);
                return;
            }

            SQLFreeStmt(hstmte, SQL_DROP);
            SQLDisconnect(hdbce);
            SQLFreeConnect(hdbce);
            SQLFreeEnv(henve);
            const char *Player = block;
            IChar Target((void*)CPlayer::FindPlayerByName((char)Player));
            IPlayer.SystemMessage("Player successfully blocked.", TEXTCOLOR_GREEN);

            if (Target.IsOnline())
            {
                PlayerBlockCheck[Target.GetUID()] = 1;
                Target.SystemMessage("Your account has been blocked.", TEXTCOLOR_RED);
                Target.Kick();
            }
        } else {
            IPlayer.SystemMessage("Could not block player.", TEXTCOLOR_GREEN);
        }

        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetAdmin() >= 3
        && sscanf(command,
            "/unblock %[a-z | A-Z | 0-9/<>|.,~*;`:!'^+%&/()=?_-£#${[]}€]", &unblock) == 1)
    {
        if (!strlen(unblock)) {
            return;
        }

        RETCODE rc;
        HENV henv;
        HDBC hdbc;
        HSTMT hstmt;
        SDWORD cbData;
        int UID = 0;
        const char *db = ConfigCheckDB2;
        SQLAllocEnv(&henv);
        SQLAllocConnect(henv, &hdbc);
        rc = SQLConnect(hdbc, (unsigned char*)db, SQL_NTS, 0, 0, 0, 0);

        if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO))
        {
            SQLFreeConnect(hdbc);
            SQLFreeEnv(henv);
            return;
        }

        rc = SQLAllocStmt(hdbc, &hstmt);
        std::stringstream query;
        query << "SELECT [UID] FROM [Player] WHERE [Name] = '" << unblock << "'";
        std::string runquery = query.str();
        const char *sql =  runquery.c_str();
        rc = SQLExecDirect(hstmt, (unsigned char*)sql, SQL_NTS);

        if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO))
        {
            SQLFreeStmt(hstmt, SQL_DROP);
            SQLDisconnect(hdbc);
            SQLFreeConnect(hdbc);
            SQLFreeEnv(henv);
            return;
        } else {
            for (rc = SQLFetch(hstmt); rc == SQL_SUCCESS; rc = SQLFetch(hstmt)) {
                SQLGetData(hstmt, 1, SQL_INTEGER, &UID, sizeof(int), &cbData);
            }
        }

        SQLFreeStmt(hstmt, SQL_DROP);
        SQLDisconnect(hdbc);
        SQLFreeConnect(hdbc);
        SQLFreeEnv(henv);

        if (UID)
        {
            PlayerBlockCheck.erase(UID);
            RETCODE rca;
            HENV henva;
            HDBC hdbca;
            HSTMT hstmta;
            const char *dba = ConfigCheckDB1;
            SQLAllocEnv(&henva);
            SQLAllocConnect(henva, &hdbca);
            rca = SQLConnect(hdbca, (unsigned char*)dba, SQL_NTS, 0, 0, 0, 0);

            if ((rca != SQL_SUCCESS) && (rca != SQL_SUCCESS_WITH_INFO))
            {
                SQLFreeConnect(hdbca);
                SQLFreeEnv(henva);
                return;
            }

            rca = SQLAllocStmt(hdbca, &hstmta);
            std::stringstream query;
            query << "UPDATE [Login] SET [Type] = 0 WHERE [UID] = '" << UID << "'";
            std::string runquery = query.str();
            const char *sql =  runquery.c_str();
            rca = SQLExecDirect(hstmta, (unsigned char*)sql, SQL_NTS);

            if ((rca != SQL_SUCCESS) && (rca != SQL_SUCCESS_WITH_INFO))
            {
                SQLFreeStmt(hstmta, SQL_DROP);
                SQLDisconnect(hdbca);
                SQLFreeConnect(hdbca);
                SQLFreeEnv(henva);
                return;
            }

            SQLFreeStmt(hstmta, SQL_DROP);
            SQLDisconnect(hdbca);
            SQLFreeConnect(hdbca);
            SQLFreeEnv(henva);
            IPlayer.SystemMessage("Player successfully unblocked.", TEXTCOLOR_GREEN);
        } else {
            IPlayer.SystemMessage("Could not unblock player.", TEXTCOLOR_GREEN);
        }

        return;
    }

    CPlayer::ChatCommand(Player, command);
}
