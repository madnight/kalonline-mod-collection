void DuelTournamentSelection(void *Pack)
{
    int GetSize = DuelTournamentList.size();

    for (int i = 0; i < GetSize; i++)
    {
        const char *check = DuelTournamentList.front();
        DuelTournamentList.erase(DuelTournamentList.begin());
        IChar DuelPlayer((void*)CPlayer::FindPlayerByName((char)check));

        if (DuelPlayer.IsValid()) {
            DuelTournamentList.push_back(DuelPlayer.GetName());
        }
    }

    if (DuelTournamentList.size() > 32)
    {
        while (DuelTournamentList.size() > 32)
        {
            std::random_shuffle(DuelTournamentList.begin(), DuelTournamentList.end());
            DuelTournamentList.erase(DuelTournamentList.begin());
        }
    }
}

void __fastcall OnTimer(void *Value, void *edx, int Argument)
{
    CCalendar::OnTimer(Value, Argument);
    time_t MyTime = time(0);
    tm *DuelTime = localtime(&MyTime);

    if (Time::GetTime() == HGST && Hunting::Active == false)
    {
        std::string GetGuildName;

        if (DuelTime->tm_wday == 0)
        {
            Hunting::Guild = HGDSu;
            GetGuildName = HGNSu;
        } else if (DuelTime->tm_wday == 1)
        {
            Hunting::Guild = HGDM;
            GetGuildName = HGNM;
        } else if (DuelTime->tm_wday == 2)
        {
            Hunting::Guild = HGDTu;
            GetGuildName = HGNTu;
        } else if (DuelTime->tm_wday == 3)
        {
            Hunting::Guild = HGDW;
            GetGuildName = HGNW;
        } else if (DuelTime->tm_wday == 4)
        {
            Hunting::Guild = HGDTh;
            GetGuildName = HGNTh;
        } else if (DuelTime->tm_wday == 5)
        {
            Hunting::Guild = HGDF;
            GetGuildName = HGNF;
        } else if (DuelTime->tm_wday == 6)
        {
            Hunting::Guild = HGDSa;
            GetGuildName = HGNSa;
        } else {
            Hunting::Guild = 0;
        }

        if (Hunting::Guild > 0 && !GetGuildName.empty())
        {
            Hunting::Active = true;
            std::string msg = "Hunting System started for " + GetGuildName + " guild.";
            CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 2);
            int Mob = Summon(0, HGMapI, HGXC, HGYC, HGMobI, 1, 0, 0, 3600000, 0);
            Hunting::Monster = (void*)Mob;
        }
    }

    if (F10::ShowTime > 0) {
        F10::ShowTime--;
    }

    if (Protect32::Time > 0) {
        Protect32::Time--;
    }

    if (Protect32::Active == true && Protect32::Time == 0)
    {
        if (Protect32::RedScore > Protect32::BlueScore) {
            Protect32::RedWin += 1;
        }

        if (Protect32::BlueScore > Protect32::RedScore) {
            Protect32::BlueWin += 1;
        }

        if (Protect32::RedWin < 2 && Protect32::BlueWin < 2)
        {
            Protect32::Round += 1;
            Protect32::Prayer = 0;
            Protect32::RedScore = 0;
            Protect32::BlueScore = 0;

            if (Protect32::Round < 4) {
                Protect32::Time = 1260;
            }
        }

        if (Protect32::Active == true && Protect32::RedWin >= 2)
        {
            Protect32::Winner = Protect32::GuildSecond;
            std::string msg = Protect32::SecondGuild + " won the Protecting Leader.";
            CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 2);
            Protect32::Active = false;
        }

        if (Protect32::Active == true && Protect32::BlueWin >= 2)
        {
            Protect32::Winner = Protect32::GuildFirst;
            std::string msg = Protect32::FirstGuild + " won the Protecting Leader.";
            CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 2);
            Protect32::Active = false;
        }

        if (Protect32::Active == true && Protect32::Round > 3)
        {
            if (Protect32::Active == true && Protect32::BlueWin > Protect32::RedWin)
            {
                Protect32::Winner = Protect32::GuildFirst;
                std::string msg = Protect32::FirstGuild + " won the Protecting Leader.";
                CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 2);
                Protect32::Active = false;
            }

            if (Protect32::Active == true && Protect32::RedWin > Protect32::BlueWin)
            {
                Protect32::Winner = Protect32::GuildSecond;
                std::string msg = Protect32::SecondGuild + " won the Protecting Leader.";
                CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 2);
                Protect32::Active = false;
            }

            if (Protect32::Active == true)
            {
                Protect32::Winner = 0;
                std::string msg = "Protecting Leader between " +
                    Protect32::FirstGuild + " guild and " + Protect32::SecondGuild +
                    " guild ended in draw.";
                CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 2);
                Protect32::Active = false;
            }
        }
    }

    if (LastManStand::Time > 0) {
        LastManStand::Time--;
    }

    if (NPCELeftTime > 0) {
        NPCELeftTime--;
    }

    if (NPCELeftTime == 1 || NPCELeftTime == 2)
    {
        CPlayer::WriteAll(0xFF, "ds", 234,
            "[Exp Event NPC] Event duration has been over!");
        NPCELeftTime = 0;
        CPlayer::SetEventCode(0, 0);
    }

    if (Time::GetTime() == "00:00:01" && NPCEDailyLimit > 0) {
        NPCEDailyLimit = 0;
    }

    if (Scenario::RedScore > 999)
    {
        Scenario::RedScore = 999;
        Scenario::Time = 0;
    }

    if (Scenario::BlueScore > 999)
    {
        Scenario::BlueScore = 999;
        Scenario::Time = 0;
    }

    if (DuelTournament::RedScore > 9999999) {
        DuelTournament::RedScore = 9999999;
    }

    if (DuelTournament::BlueScore > 9999999) {
        DuelTournament::BlueScore = 9999999;
    }

    if (Hell::Active == true && Hell::Time > 0) {
        Hell::Time -= 1;
    }

    if (Hell::Active == true && Hell::Delay > 0) {
        Hell::Delay -= 1;
    }

    if (Scenario::Active == true && Scenario::Time > 0) {
        Scenario::Time -= 1;
    }

    if (AutoNoticeDay.count(Time::GetTime())
        && AutoNoticeMsg.count(Time::GetTime()))
    {
        if (AutoNoticeDay.find(Time::GetTime())->second == Time::GetDayName()
            || AutoNoticeDay.find(Time::GetTime())->second == "Daily")
            CPlayer::WriteAll(0xFF, "dsd", 247,
                AutoNoticeMsg.find(Time::GetTime())->second.c_str(), 2);
    }

    if (SummonTimer.count(Time::GetTime()))
    {
        if (strlen(SummonTimer.find(Time::GetTime())->second.Day.c_str())
            && SummonTimer.find(Time::GetTime())->second.Day == Time::GetDayName()
            || SummonTimer.find(Time::GetTime())->second.Day == "Daily")
        {
            if (strlen(SummonTimer.find(Time::GetTime())->second.Msg.c_str()))
                CPlayer::WriteAll(0xFF, "dsd", 247,
                    SummonTimer.find(Time::GetTime())->second.Msg.c_str(), 2);

            for (int i = 0; i < SummonTimer.find(Time::GetTime())->second.Amount; i++)
            {
                Summon(0, SummonTimer.find(Time::GetTime())->second.Map,
                    SummonTimer.find(Time::GetTime())->second.X,
                    SummonTimer.find(Time::GetTime())->second.Y,
                    SummonTimer.find(Time::GetTime())->second.Index, 1, 1, 0,
                    SummonTimer.find(Time::GetTime())->second.Disappear*1000, 0);
            }
        }
    }

    if (DuelTournament::Active == true && DuelTournament::RoundTime > 0) {
        DuelTournament::RoundTime -= 1;
    }

    if (DuelTournament::Active == true && DuelTournament::Delay > 0) {
        DuelTournament::Delay -= 1;
    }

    if (DuelTournament::Active == true && DuelTournament::SelectPlayers == false
        && DuelTournament::FirstPlayer && DuelTournament::SecondPlayer)
    {
        IChar FirstPlayerCheck((void*)DuelTournament::FirstPlayer);
        IChar SecondPlayerCheck((void*)DuelTournament::SecondPlayer);

        if (DuelTournament::RoundTime == 0)
        {
            if (DuelTournament::RedScore > DuelTournament::BlueScore)
            {
                if (FirstPlayerCheck.IsOnline())
                {
                    std::string msg = (std::string)FirstPlayerCheck.GetName() + " won the duel.";
                    CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
                    DuelTournamentList.push_back(FirstPlayerCheck.GetName());
                }

                DuelTournament::Delay = 10;
                DuelTournament::SelectPlayers = true;
                DuelTournament::FirstPlayer = 0;
                DuelTournament::SecondPlayer = 0;
            } else if (DuelTournament::BlueScore > DuelTournament::RedScore)
            {
                if (SecondPlayerCheck.IsOnline())
                {
                    std::string msg = (std::string)SecondPlayerCheck.GetName() + " won the duel.";
                    CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
                    DuelTournamentList.push_back(SecondPlayerCheck.GetName());
                }

                DuelTournament::Delay = 10;
                DuelTournament::SelectPlayers = true;
                DuelTournament::FirstPlayer = 0;
                DuelTournament::SecondPlayer = 0;
            } else {
                if (SecondPlayerCheck.IsOnline() && FirstPlayerCheck.IsOnline())
                {
                    std::string msg = "Duel between " + (std::string)FirstPlayerCheck.GetName() +
                        " and " + (std::string)SecondPlayerCheck.GetName() + " ended in a draw.";
                    CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
                    DuelTournamentList.push_back(FirstPlayerCheck.GetName());
                    DuelTournamentList.push_back(SecondPlayerCheck.GetName());
                }

                DuelTournament::Delay = 10;
                DuelTournament::SelectPlayers = true;
                DuelTournament::FirstPlayer = 0;
                DuelTournament::SecondPlayer = 0;
            }
        }

        if (DuelTournament::RoundTime > 0)
        {
            if (!FirstPlayerCheck.IsOnline() && !SecondPlayerCheck.IsOnline())
            {
                DuelTournament::Delay = 10;
                DuelTournament::SelectPlayers = true;
                DuelTournament::FirstPlayer = 0;
                DuelTournament::SecondPlayer = 0;
            } else if (!FirstPlayerCheck.IsOnline() && SecondPlayerCheck.IsOnline())
            {
                DuelTournament::Delay = 10;
                DuelTournament::SelectPlayers = true;
                DuelTournament::FirstPlayer = 0;
                DuelTournament::SecondPlayer = 0;

                if (SecondPlayerCheck.IsValid())
                {
                    SecondPlayerCheck.CancelBuff(373);
                    SecondPlayerCheck.CancelBuff(374);
                    std::string msg = (std::string)SecondPlayerCheck.GetName() + " won the duel.";
                    CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
                    DuelTournamentList.push_back(SecondPlayerCheck.GetName());
                }
            } else if (!SecondPlayerCheck.IsOnline() && FirstPlayerCheck.IsOnline())
            {
                DuelTournament::Delay = 10;
                DuelTournament::SelectPlayers = true;
                DuelTournament::FirstPlayer = 0;
                DuelTournament::SecondPlayer = 0;

                if (FirstPlayerCheck.IsValid())
                {
                    FirstPlayerCheck.CancelBuff(373);
                    FirstPlayerCheck.CancelBuff(374);
                    std::string msg = (std::string)FirstPlayerCheck.GetName() + " won the duel.";
                    CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
                    DuelTournamentList.push_back(FirstPlayerCheck.GetName());
                }
            }

            if (FirstPlayerCheck.IsOnline() && SecondPlayerCheck.IsOnline()
                && DuelTournament::RoundTime <= 170)
            {
                if (FirstPlayerCheck.GetRectX() < 6703 || FirstPlayerCheck.GetRectX() > 6721)
                {
                    DuelTournament::Delay = 10;
                    DuelTournament::SelectPlayers = true;
                    DuelTournament::FirstPlayer = 0;
                    DuelTournament::SecondPlayer = 0;
                    FirstPlayerCheck.CancelBuff(373);
                    FirstPlayerCheck.CancelBuff(374);
                    SecondPlayerCheck.CancelBuff(373);
                    SecondPlayerCheck.CancelBuff(374);
                    std::string msg = (std::string)SecondPlayerCheck.GetName() + " won the duel.";
                    CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
                    DuelTournamentList.push_back(SecondPlayerCheck.GetName());
                }

                if (SecondPlayerCheck.GetRectX() < 6703 || SecondPlayerCheck.GetRectX() > 6721)
                {
                    DuelTournament::Delay = 10;
                    DuelTournament::SelectPlayers = true;
                    DuelTournament::FirstPlayer = 0;
                    DuelTournament::SecondPlayer = 0;
                    FirstPlayerCheck.CancelBuff(373);
                    FirstPlayerCheck.CancelBuff(374);
                    SecondPlayerCheck.CancelBuff(373);
                    SecondPlayerCheck.CancelBuff(374);
                    std::string msg = (std::string)FirstPlayerCheck.GetName() + " won the duel.";
                    CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
                    DuelTournamentList.push_back(FirstPlayerCheck.GetName());
                }
            }
        }
    }

    if (DuelTournament::Active == true && DuelTournament::SelectPlayers == true
        && DuelTournament::Delay == 0  && !DuelTournament::FirstPlayer
        && !DuelTournament::SecondPlayer)
    {
        if (DuelTournamentList.size() > 1)
        {
            DuelTournament::SelectPlayers = false;
            const char *firstplayer = DuelTournamentList.front();
            DuelTournamentList.erase(DuelTournamentList.begin());
            IChar FirstPlayer((void*)CPlayer::FindPlayerByName((char)firstplayer));
            const char *secondplayer = DuelTournamentList.front();
            DuelTournamentList.erase(DuelTournamentList.begin());
            IChar SecondPlayer((void*)CPlayer::FindPlayerByName((char)secondplayer));

            if (!FirstPlayer.IsValid() && SecondPlayer.IsValid())
            {
                DuelTournament::Delay = 10;
                DuelTournament::SelectPlayers = true;
                DuelTournamentList.push_back(SecondPlayer.GetName());
                std::string msg = (std::string)secondplayer +
                    " won the duel becouse opponent is not avalible to fight.";
                CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
            } else if (!SecondPlayer.IsValid() && FirstPlayer.IsValid())
            {
                DuelTournament::Delay = 10;
                DuelTournament::SelectPlayers = true;
                DuelTournamentList.push_back(FirstPlayer.GetName());
                std::string msg = (std::string)firstplayer +
                    " won the duel becouse opponent is not avalible to fight.";
                CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
            } else if (FirstPlayer.IsValid() && SecondPlayer.IsValid())
            {
                std::string msg = "Duel between " + (std::string)firstplayer + " and " +
                    (std::string)secondplayer + " started.";
                CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
                DuelTournament::RoundTime = 180;
                DuelTournament::RedScore = 0;
                DuelTournament::BlueScore = 0;
                FirstPlayer.Buff(373, 180, 0);
                FirstPlayer.Teleport(0, 214928, 280731);
                DuelTournament::FirstPlayer = (int)FirstPlayer.GetOffset();
                SecondPlayer.Buff(374, 180, 0);
                SecondPlayer.Teleport(0, 214679, 280862);
                DuelTournament::SecondPlayer = (int)SecondPlayer.GetOffset();
            } else {
                DuelTournament::Delay = 10;
                DuelTournament::SelectPlayers = true;
            }
        } else {
            DuelTournament::Active = false;
            DuelTournament::Delay = 0;
            DuelTournament::FirstPlayer = 0;
            DuelTournament::SecondPlayer = 0;
            DuelTournament::RedScore = 0;
            DuelTournament::BlueScore = 0;
            DuelTournament::SelectPlayers = false;

            if (DuelTournamentList.size() == 1)
            {
                const char *check = DuelTournamentList.front();
                DuelTournamentList.erase(DuelTournamentList.begin());
                IChar WinnerPlayer((void*)CPlayer::FindPlayerByName((char)check));

                if (WinnerPlayer.IsOnline())
                {
                    WinnerPlayer.CancelBuff(373);
                    WinnerPlayer.CancelBuff(374);
                    std::string msg = (std::string)WinnerPlayer.GetName() +
                        " won the Duel Tournament.";
                    CPlayer::WriteAll(0xFF, "ds", 234, msg.c_str());
                    CheckHonor[WinnerPlayer.GetPID()].RPx += 5000;
                    CheckHonor[WinnerPlayer.GetPID()].HPx += 1000;
                    WinnerPlayer.Buff(120, (21600+WinnerPlayer.GetBuffRemain(120)), 0);
                }
            } else {
                CPlayer::WriteAll(0xFF, "ds", 234,
                    "Duel Tournament ended. There is no winner.");
            }
        }
    }

    if (Time::GetTime() == ExpEventStart && ((std::string)ActiveExpEvent == "true"
            || (std::string)ActiveExpEvent == "True")) {
        CPlayer::SetEventCode(0, 1);
    }

    if (Time::GetTime() == ExpEventEnd && ((std::string)ActiveExpEvent == "true"
            || (std::string)ActiveExpEvent == "True")) {
        CPlayer::SetEventCode(0, 0);
    }

    if (LastManStand::Active == false && Time::GetTime() == "19:00:00")
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

    if (DuelTournament::Active == false && Time::GetTime() == "16:00:00")
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

    if (Protect32::Active == false && Time::GetDayName() == "Monday"
        && Time::GetTime() == "22:30:00" || Protect32::Active == false
        && Time::GetDayName() == "Wednesday" && Time::GetTime() == "22:30:00"
        || Protect32::Active == false && Time::GetDayName() == "Friday"
        && Time::GetTime() == "22:30:00")
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

    if (Scenario::Active == false && Time::GetDayName() == "Tuesday"
        && Time::GetTime() == "21:00:00" || Scenario::Active == false
        && Time::GetDayName() == "Thursday" && Time::GetTime() == "21:00:00")
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
    }

    if (Scenario::Active == true && Scenario::Time == 0)
    {
        ScenarioRegistration.clear();
        Scenario::Active = false;
        Scenario::Time = 0;
    }

    if (Battlefield::RedScore > 999)
    {
        Battlefield::RedScore = 999;
        Battlefield::Time = 0;
    }

    if (Battlefield::BlueScore > 999)
    {
        Battlefield::BlueScore = 999;
        Battlefield::Time = 0;
    }

    if (Battlefield::Active == true && Battlefield::Time > 0) {
        Battlefield::Time -= 1;
    }

    if (Battlefield::Active == false && Time::GetDayName() == "Wednesday"
        && Time::GetTime() == "21:00:00" || Battlefield::Active == false
        && Time::GetDayName() == "Friday" && Time::GetTime() == "21:00:00")
    {
        if (Battlefield::RegisterAmount > 1)
        {
            CPlayer::WriteAll(0xFF, "dsd", 247, "Battlefield started.", 2);
            Battlefield::Time = BFTime;
            Battlefield::RedScore = 0;
            Battlefield::BlueScore = 0;
            Battlefield::RegisterAmount = 0;
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
        } else {
            CPlayer::WriteAll(0xFF, "dsd", 247,
                "Enough players did not registered for Battlefield.", 2);
        }
    }

    if (Battlefield::Active == true && (Battlefield::Time == 3000
            || Battlefield::Time == 2400 || Battlefield::Time == 1800
            || Battlefield::Time == 1200 || Battlefield::Time == 600))
    {
        IChar M1((void*)CMonster::FindMonster(Battlefield::BlueStoneID[0]));
        IChar M2((void*)CMonster::FindMonster(Battlefield::BlueStoneID[1]));
        IChar M3((void*)CMonster::FindMonster(Battlefield::BlueStoneID[2]));
        IChar m1((void*)CMonster::FindMonster(Battlefield::RedStoneID[0]));
        IChar m2((void*)CMonster::FindMonster(Battlefield::RedStoneID[1]));
        IChar m3((void*)CMonster::FindMonster(Battlefield::RedStoneID[2]));

        if (!M1.IsValid())
        {
            IChar N1((void*)Summon(0, BFMap, 274761, 212814, 445, 1, 0, 0, 0, 0));
            Battlefield::BlueStoneID[0] = N1.GetID();
        }

        if (!M2.IsValid())
        {
            IChar N2((void*)Summon(0, BFMap, 278472, 209291, 445, 1, 0, 0, 0, 0));
            Battlefield::BlueStoneID[1] = N2.GetID();
        }

        if (!M3.IsValid())
        {
            IChar N3((void*)Summon(0, BFMap, 278441, 212986, 445, 1, 0, 0, 0, 0));
            Battlefield::BlueStoneID[2] = N3.GetID();
        }

        if (!m1.IsValid())
        {
            IChar n1((void*)Summon(0, BFMap, 278531, 212982, 448, 1, 0, 0, 0, 0));
            Battlefield::BlueStoneID[0] = n1.GetID();
        }

        if (!m2.IsValid())
        {
            IChar n2((void*)Summon(0, BFMap, 278706, 216690, 448, 1, 0, 0, 0, 0));
            Battlefield::BlueStoneID[1] = n2.GetID();
        }

        if (!m3.IsValid())
        {
            IChar n3((void*)Summon(0, BFMap, 282215, 213033, 448, 1, 0, 0, 0, 0));
            Battlefield::BlueStoneID[2] = n3.GetID();
        }

        CPlayer::WriteInMap(BFMap, 0xFF, "dsd", 247,
            "Battlefield team stones have been re-spawned.", 2);
    }

    if (Battlefield::Active == true && Battlefield::Time == 0)
    {
        BattlefieldRegistration.clear();
        Battlefield::Active = false;
        Battlefield::Time = 0;
    }

    if (Hell::Active == true && Hell::Time == 0)
    {
        CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 90, 255, 255, 255);
        Hell::Active = false;
        Hell::Time = 0;
    }

    if (Hell::Active == true && Hell::Round == 1)
    {
        if (Hell::Time == 1800)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 75, 255, 255, 255);

            for (int i = 0; i < 21; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 841, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 21)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 2)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 76, 255, 255, 255);

            for (int i = 0; i < 14; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 842, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 14)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 3)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 77, 255, 255, 255);

            for (int i = 0; i < 16; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 843, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 16)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 4)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 78, 255, 255, 255);

            for (int i = 0; i < 12; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 845, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 12)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 5)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 79, 255, 255, 255);

            for (int i = 0; i < 13; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 846, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 13)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 6)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 80, 255, 255, 255);

            for (int i = 0; i < 18; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 847, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 18)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 7)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 81, 255, 255, 255);

            for (int i = 0; i < 15; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 849, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 15)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 8)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 82, 255, 255, 255);

            for (int i = 0; i < 17; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 850, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 17)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 9)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 83, 255, 255, 255);

            for (int i = 0; i < 12; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 852, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 12)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 10)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 84, 255, 255, 255);

            for (int i = 0; i < 18; i++)
            {
                IChar xSummon((void*)Summon(0, HellMap, HellSummonX+CTools::Rate(1, 20),
                        HellSummonY+CTools::Rate(1, 20), 851, 1, 1, 0, 0, 0));
                xSummon.Buff(168, 3600, 0);
            }
        }

        if (Hell::KillCount == 18)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 86, 255, 255, 255);
            Hell::Round += 1;
            Hell::KillCount = 0;
            Hell::Delay = 5;
        }
    }

    if (Hell::Active == true && Hell::Round == 11)
    {
        if (Hell::Delay == 3) {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 87, 255, 255, 255);
        }

        if (Hell::Delay == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 85, 255, 255, 255);
            IChar xSummon((void*)Summon(0, HellMap, HellSummonX, HellSummonY, 667, 1, 1, 0,
                    0, 0));
            xSummon.Buff(168, 3600, 0);
        }

        if (Hell::KillCount == 1)
        {
            CPlayer::WriteInMap(HellMap, 0xFF, "ddddd", 242, 88, 255, 255, 255);
            Hell::Active = false;
            Hell::Time = 0;
        }
    }

    if (Time::GetTime() == "19:00:00")
    {
        NailKill = 0;
        Summon(0, EmokMap, 330747, 266095, 384, 1, 0, 0, 3600000, 0);
        Summon(0, EmokMap, 331444, 265375, 384, 1, 0, 0, 3600000, 0);
        Summon(0, EmokMap, 330222, 264165, 384, 1, 0, 0, 3600000, 0);
        Summon(0, EmokMap, 329511, 264894, 384, 1, 0, 0, 3600000, 0);
        CPlayer::WriteAll(0xFF, "dsd", 247, "Nail of Dragons have been appeared.", 2);
    }

    if (Time::GetTime() == "18:00:00")
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
        } else {
            CPlayer::WriteAll(0xFF, "dsd", 247,
                "Enough players did not registered for Ilyer Company System.", 2);
        }
    }
}
