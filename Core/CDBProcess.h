int __cdecl CDBProcess(char *Data)
{
    if (Data[2] == 25)
    {
        int PID = 0, MID = 0, RPID = 0, IID = 0;
        char Type = 0, xType = 0, Status = 0;
        const char *Name = "nopwd";
        CPacket::xRead((void*)(Data + 3), "dbdbbdsd", &PID, &Type, &MID, &xType,
                       &Status, &RPID, &Name, &IID);

        if (PID == -1 && Type == 1 && MID > 0 && RPID > 0 && IID)
        {
            int Player = CPlayer::ScanPlayer(RPID);

            if (Player)
            {
                IChar IPlayer((void*)Player);

                if (IPlayer.IsOnline())
                {
                    CDBSocket::Write(30,"dbddbbddwdd",MID,1,0,MID,0,1,RPID,IID,0,0,0);
                    CPlayer::Write(IPlayer.GetOffset(), 68, "bbs", 85, 0, "Kal Online");
                    return 0;
                }
            }
        }
    }

    if (Data[2] == 50)
    {
        int PID = 0, HP = 0, HK = 0, HD = 0, DKPT = 0, DKPW = 0, PLT = 0, PLW = 0,
            SVT = 0, SVW = 0, RP = 0;
        CPacket::xRead((void*)(Data + 3), "ddddddddddd", &PID, &HP, &HK, &HD, &DKPT,
                       &DKPW, &PLT, &PLW, &SVT, &SVW, &RP);

        if (PID)
        {
            if (HP)
            {
                CheckCurHonor[PID].CurHPx = HP;
                CheckHonor[PID].HPx = HP;
            }

            if (HK)
            {
                CheckCurHonor[PID].CurHKx = HK;
                CheckHonor[PID].HKx = HK;
            }

            if (HD)
            {
                CheckCurHonor[PID].CurHDx = HD;
                CheckHonor[PID].HDx = HD;
            }

            if (DKPT)
            {
                CheckCurHonor[PID].CurDKPTx = DKPT;
                CheckHonor[PID].DKPTx = DKPT;
            }

            if (DKPW)
            {
                CheckCurHonor[PID].CurDKPWx = DKPW;
                CheckHonor[PID].DKPWx = DKPW;
            }

            if (PLT)
            {
                CheckCurHonor[PID].CurPLTx = PLT;
                CheckHonor[PID].PLTx = PLT;
            }

            if (PLW)
            {
                CheckCurHonor[PID].CurPLWx = PLW;
                CheckHonor[PID].PLWx = PLW;
            }

            if (SVT)
            {
                CheckCurHonor[PID].CurSVTx = SVT;
                CheckHonor[PID].SVTx = SVT;
            }

            if (SVW)
            {
                CheckCurHonor[PID].CurSVWx = SVW;
                CheckHonor[PID].SVWx = SVW;
            }

            if (RP)
            {
                CheckCurHonor[PID].CurRPx = RP;
                CheckHonor[PID].RPx = RP;
            }
        }

        return 0;
    }

    if (Data[2] == 51)
    {
        int PID = 0, Time = 0, Day = 0;
        CPacket::xRead((void*)(Data + 3), "ddd", &PID, &Day, &Time);

        if (PID && Day)
        {
            CheckEmok[PID].Time = Time;
            CheckEmok[PID].Day = Day;
        }

        return 0;
    }

    if (Data[2] == 52)
    {
        int Remain = 0, Type = 0, PID = 0;
        CPacket::xRead((void*)(Data + 3), "ddd", &PID, &Type, &Remain);

        if (PID && Type && Remain)
            SetBuffx.insert(std::pair<int,int>(PID+4000000000+(Type*1000000),Remain));

        return 0;
    }

    if (Data[2] == 53)
    {
        const char *Lock = "nopwd";
        int PetLife = 0, IID = 0;
        CPacket::xRead((void*)(Data + 3), "sdd", &Lock, &PetLife, &IID);
        std::string check = "nopwd";

        if (IID)
        {
            if (strlen(Lock) && Lock != check && IID)
                ItemLockCheck.insert(std::pair<int,std::string>(IID,Lock));

            if (PetLife && IID)
                PetLifeCheck[IID].Time = PetLife;
        }

        return 0;
    }

    if (Data[2] == 54)
    {
        int PID = 0, xIndex = 0, IID = 0, GetPetTime = 259200;
        CPacket::xRead((void*)(Data + 3), "dd", &PID, &IID);
        int Player = CPlayer::ScanPlayer(PID);
        IChar IPlayer((void*)Player);

        if (Player && PID && IID)
        {
            if (IPlayer.IsOnline())
            {
                int CheckValue = 0, Checkx = 0, Recheckx = 0, MyItem = 0;
                Undefined::CreateMonsterValue((char*)IPlayer.GetOffset() + 1068,
                                              (int)&CheckValue, (int)&IID);
                Checkx = Undefined::Check((int)((char*)IPlayer.GetOffset() + 1068),
                                          (int)&Recheckx);

                if (Undefined::CheckValues(&CheckValue, Checkx))
                {
                    MyItem = *(DWORD *)(Undefined::GetValue(&CheckValue) + 4);

                    if (MyItem && PetLifeCheck.count(IID) && PetLifeCheck.find(IID)->second.Time)
                    {
                        xIndex = *(DWORD *)(*(DWORD *)(MyItem + 40) + 64);
                        PetLifeCheck[IID].Player = Player;

                        if (PetTime.count(xIndex) && PetTime.find(xIndex)->second.Time > 0)
                            GetPetTime = PetTime.find(xIndex)->second.Time;

                        *(DWORD*)(MyItem+68) = GetTickCount() + (2000*GetPetTime);
                        *(DWORD*)(MyItem+72) = 0;
                        CItem::OnTimer(MyItem,0);
                        CPlayer::Write(IPlayer.GetOffset(),0xFF,"ddd",230,IID,
                                       (PetLifeCheck.find(IID)->second.Time-(int)time(0))*1000);
                    }
                }
            }
        }

        return 0;
    }

    if (Data[2] == 55)
    {
        int IID = 0, ItemStat = 0;
        Interface<ITools> Tools;
        Tools->ParseData((char*)(void*)(Data + 3), "dd", &IID, &ItemStat);

        if (IID && !GetItemStat.count(IID) && ItemStat)
            GetItemStat.insert(std::pair<int,int>(IID,ItemStat));

        return 0;
    }

    if (Data[2] == 56)
    {
        int PID = 0, QuestID = 0, Clear = 0, QuestTime = 0, QuestRepeat = 0,
            MonsterCount = 0;
        CPacket::xRead((void*)(Data + 3), "dddddd", &PID, &QuestID, &Clear, &QuestTime,
                       &QuestRepeat, &MonsterCount);

        if (PID && QuestID && QuestTime)
        {
            if (!Clear)
                PlayerQuest[(QuestID * 1000000000000) + PID].Active = 1;
            else
                PlayerQuest[(QuestID * 1000000000000) + PID].Active = 0;

            PlayerQuest[(QuestID * 1000000000000) + PID].MobAmount = MonsterCount;
            PlayerQuest[(QuestID * 1000000000000) + PID].Repeat = QuestRepeat;
            PlayerQuest[(QuestID * 1000000000000) + PID].Time = QuestTime;
            int Player = CPlayer::ScanPlayer(PID);
            IChar IPlayer((void*)Player);
            if (Player && IPlayer.IsOnline())
                CPlayer::Write((void*)Player,255,"dddd",222,PID,QuestID, MonsterCount);
        }

        return 0;
    }

    return CDBSocket::RealProcess(Data);
}
