int __cdecl Summon(int Player, int Map, int X, int Y, int Index, int Amount,
                   int SafeZoneCheck, int Delay, int Disappear, int Pet)
{
    void *GetMonster = 0;
    int Value = 0, Monster = 0, Argument = 0;
    int GetMap = Undefined::MapCheck(Map);

    if (GetMap)
    {
        void *MonsterValueCheck = (void*)Undefined::GetMonsterValue(0x2B0u);

        if (MonsterValueCheck)
            GetMonster = Undefined::MonsterCreate(MonsterValueCheck);
        else
            GetMonster = 0;

        Monster = (int)GetMonster;
        IChar IMonster((void*)Monster);
        CIOCriticalSection::Enter((void*)0x4E182C);
        Undefined::CreateMonsterValue((void*)0x4E1820, (int)&Argument, (int)&Index);
        int GetCheck = Undefined::Check((int)0x4E1820, (int)&Value);

        if (*(DWORD*)(void*)&Argument == *(DWORD*)GetCheck)
        {
            CIOCriticalSection::Leave((void*)0x4E182C);
        } else {
            int Check = *(DWORD *)(Undefined::GetValue(&Argument) + 4);

            if (*(DWORD *)(Check + 304))
            {
                int *GetSetXY = new int[1];
                GetSetXY[0] = X;
                GetSetXY[1] = Y;
                *(DWORD *)(Monster + 316) = Map;
                *(DWORD *)(Monster + 320) = GetMap;
                *(DWORD *)(Monster + 512) = Index;
                *(DWORD *)(Monster + 476) = 1;

                if (Disappear)
                    MonsterDisappear[(int)IMonster.GetOffset()] = GetTickCount() + Disappear;

                CChar::SetXY(Monster, (int)GetSetXY);
                delete[] GetSetXY;
                (*(void (__thiscall **)(int, int))(*(DWORD *)Monster + 192))(Monster, Check);

                if (Delay)
                {
                    IMonster.Buff(159,(Delay+2000)/1000,0);
                    IMonster.Delay(Delay);
                    IMonster.UnAttack(Delay);
                }

                CIOCriticalSection::Leave((void*)0x4E182C);
                CChar::Lock((void*)Monster);
                int *CellMapCoordinate = new int[1];
                CellMapCoordinate[0] = X >> 5;
                CellMapCoordinate[1] = Y >> 5;
                IMonster.MonsterSummonWrite(SafeZoneCheck,Monster,(int)CellMapCoordinate);
                delete[] CellMapCoordinate;
            } else {
                CIOCriticalSection::Leave((void*)0x4E182C);
            }
        }
    }

    return Monster;
}

int __fastcall SummonAI(void *Monster, void *edx)
{
    IChar IMonster(Monster);

    if (IMonster.IsValid())
    {
        if (IMonster.GetMobIndex() == 566 && F10::DunamicSkillDelay)
            return 0;

        if (IMonster.GetMobIndex() == 572 && F10::CheiosSkillDelay)
            return 0;

        if (IMonster.GetMobIndex() == 445 || IMonster.GetMobIndex() == 448)
            return 0;

        if (IMonster.GetMobIndex() >= 352 && IMonster.GetMobIndex() <= 360)
            return 0;

        if (IMonster.GetMobIndex() == 384)
            return 0;
    }

    return CMonsterMaguniMaster::AI(Monster);
}

int __fastcall SummonDie(int Monster, void *edx, int Arg, int Arg1, int Arg2,
                         int Arg3)
{
    IChar IMonster((void*)Monster);

    if (Hunting::Active == true && IMonster.GetOffset() == Hunting::Monster)
    {
        int Around = IMonster.GetObjectListAround(50);

        while(Around)
        {
            IChar Object((void*)*(DWORD*)Around);

            if (Object.GetType() == 0 && Object.GetGID() == Hunting::Guild)
                (*(int (__cdecl **)(int, signed int, signed int, unsigned __int64,
                                    unsigned __int64))
                 (*(DWORD *)Object.GetOffset() + 88))
                ((int)Object.GetOffset(), 25, 1, (unsigned __int64)HGEA, HIDWORD(HGEA));

            Around = CBaseList::Pop((void*)Around);
        }
    }

    if (Hell::Active == true && IMonster.IsBuff(168))
    {
        if (IMonster.GetMobIndex() == 667)
        {
            int Around = IMonster.GetObjectListAround(50);

            while(Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.GetType() == 0 && Object.IsBuff(166))
                {
                    CheckHonor[Object.GetPID()].RPx += 1000;
                    CheckHonor[Object.GetPID()].HPx += 100;
                }

                Around = CBaseList::Pop((void*)Around);
            }
        }

        Hell::KillCount += 1;
    }

    if (IMonster.GetMobIndex() == 572)
        F10::KillCount += 1;

    if (IMonster.GetMobIndex() == 566)
        F10::KillCount += 1;

    if (IMonster.GetMobIndex() == 384)
    {
        for (int i = 0; i < 8; i++)
        {
            Summon(0, EmokMap, IMonster.GetX(), IMonster.GetY(), 385, 1, 0, 0, 3600000, 0);
        }

        for (int i = 0; i < 8; i++)
        {
            Summon(0, EmokMap, IMonster.GetX(), IMonster.GetY(), 386, 1, 0, 0, 3600000, 0);
        }

        NailKill += 1;

        if (NailKill == 4)
        {
            NailKill = 0;
            Summon(0, EmokMap, 330904, 264756, 383, 1, 0, 0, 3600000, 0);
            CPlayer::WriteAll(0xFF, "dsd", 247,
                              "A Thousand Year Old E-Moogi has been appeared.", 2);
        }
    }

    if (IMonster.GetMobIndex() == 383)
    {
        Summon(0, EmokMap, 330904, 264756, 382, 1, 0, 0, 3600000, 0);
        CPlayer::WriteAll(0xFF, "dsd", 247, "Ghost of Dragon has been appeared.", 2);
    }

    if (IMonster.GetMobIndex() == 445)
    {
        Battlefield::RedScore += 25;
        CPlayer::WriteInMap(BFMap, 0xFF, "dsd", 247, "Blue Tiger stone destroyed.", 3);
    }

    if (IMonster.GetMobIndex() == 448)
    {
        Battlefield::BlueScore += 25;
        CPlayer::WriteInMap(BFMap, 0xFF, "dsd", 247, "White Tiger stone destroyed.", 6);
    }

    if (IMonster.GetMobIndex() == 352)
    {
        Scenario::BlueScore += 5;
        Scenario::BlueTeamTowerCount += 1;
        CPlayer::WriteInMap(ScenarioMap, 0xFF, "ddddd", 242, 22, 255, 255, 255);
    }

    if (IMonster.GetMobIndex() == 354)
    {
        Scenario::BlueScore += 2;
        Scenario::BlueTeamTowerCount += 1;
        CPlayer::WriteInMap(ScenarioMap, 0xFF, "ddddd", 242, 19, 255, 255, 255);
    }

    if (IMonster.GetMobIndex() == 356)
    {
        Scenario::RedScore += 5;
        Scenario::RedTeamTowerCount += 1;
        CPlayer::WriteInMap(ScenarioMap, 0xFF, "ddddd", 242, 33, 255, 255, 255);
    }

    if (IMonster.GetMobIndex() == 358)
    {
        Scenario::RedScore += 2;
        Scenario::RedTeamTowerCount += 1;
        CPlayer::WriteInMap(ScenarioMap, 0xFF, "ddddd", 242, 30, 255, 255, 255);
    }

    if (Scenario::RedTeamTowerCount == 7)
    {
        Scenario::RedTeamSeal = 1;
        CPlayer::WriteInMap(ScenarioMap, 0xFF, "ddddd", 242, 17, 255, 255, 255);
    }

    if (Scenario::BlueTeamTowerCount == 7)
    {
        Scenario::BlueTeamSeal = 1;
        CPlayer::WriteInMap(ScenarioMap, 0xFF, "ddddd", 242, 28, 255, 255, 255);
    }

    return CMonsterMaguniMaster::Die(Monster,Arg,Arg1,Arg2,Arg3);
}

int __fastcall SummonTick(void *Monster, void *edx)
{
    IChar IMonster(Monster);

    if (IMonster.IsValid() && IMonster.GetMobIndex() == 573 &&
            IMonster.GetCurHp() != IMonster.GetMaxHp())
        IMonster.IncreaseHp(100000);

    if (IMonster.IsValid() && F10::Active == true && IMonster.GetMobIndex() == 573)
    {
        if (F10::KillCount < 2)
        {
            DWORD Check = (MonsterDisappear.find((int)IMonster.GetOffset())->second -
                           GetTickCount()) / 1000;

            if (IMonster.IsValid() && Check == 3695)
                Undefined::MonsterPath(*(void **)((int)Monster + 320), (int)Monster, 0, -1, 0,
                                       1);

            if (IMonster.IsValid() && Check == 3691)
                CPlayer::WriteInMap(21, 0xFF, "dsd", 247,
                                    "I have a supernatural feeling that something invisible is trying to embody.", 1);

            if (IMonster.IsValid() && Check == 3688)
                CPlayer::WriteInMap(21, 0xFF, "dsd", 247,
                                    "Finally here you come. I have waited so long... about 100 years...", 1);

            if (IMonster.IsValid() && Check == 3684)
                CPlayer::WriteInMap(21, 0xFF, "dsd", 247,
                                    "You look very tired. I know the way that you had come here was not easy.", 1);

            if (IMonster.IsValid() && Check == 3680)
                CPlayer::WriteInMap(21, 0xFF, "dsd", 247,
                                    "Then, I'd like to get you through the final wringer I will estimate.", 1);

            if (IMonster.IsValid() && Check == 3676)
                CPlayer::WriteInMap(21, 0xFF, "dsd", 247,
                                    "Whatever you have a qualification and an ability to defeat energy of evil.", 1);

            if (IMonster.IsValid() && Check == 3672)
                CPlayer::WriteInMap(21, 0xFF, "dsd", 247,
                                    "If you pass it, I will pave the way to the subject of energy of evil.", 1);

            if (IMonster.IsValid() && Check == 3668)
                CPlayer::WriteInMap(21, 0xFF, "dsd", 247,
                                    "I hope you will pass it and annihilate the energy of evil which has been existed.",
                                    1);

            if (IMonster.IsValid() && Check == 3664)
                CPlayer::WriteInMap(21, 0xFF, "dsd", 247,
                                    "Since the first year of an era and thrown into confusion, so save the world finally.",
                                    1);

            if (IMonster.IsValid() && Check == 3660)
                IMonster.AddFxToTarget("davi_M573_72", 1, 0, 0);

            if (IMonster.IsValid() && Check == 3659)
                CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 258, IMonster.GetID(),
                                    IMonster.GetID(), 1, 1);

            if (IMonster.IsValid() && Check == 3658)
                CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 258, IMonster.GetID(),
                                    IMonster.GetID(), 1, 1);

            if (IMonster.IsValid() && Check == 3657)
                CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 258, IMonster.GetID(),
                                    IMonster.GetID(), 1, 1);

            if (IMonster.IsValid() && Check == 3656)
                CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 258, IMonster.GetID(),
                                    IMonster.GetID(), 1, 1);

            if (IMonster.IsValid() && Check == 3655)
                CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 258, IMonster.GetID(),
                                    IMonster.GetID(), 1, 1);

            if (IMonster.IsValid() && Check == 3654)
                CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 258, IMonster.GetID(),
                                    IMonster.GetID(), 1, 1);

            if (IMonster.IsValid() && Check == 3653)
                CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 256, IMonster.GetID(),
                                    IMonster.GetID(), 1, 1);

            if (IMonster.IsValid() && Check >= 3647 && Check <= 3650 && (!F10::Cheios
                    || !F10::Dunamic))
            {
                if (!F10::Cheios)
                {
                    F10::Cheios = Summon(0, 21, 117248, 36843, 572, 1, 0, 16000, 3616000, 0);
                    IChar Cheios((void*)F10::Cheios);

                    if (Cheios.IsValid())
                        Undefined::MonsterPath(*(void **)(F10::Cheios + 320), F10::Cheios, 0, -1, 0, 1);
                }

                if (!F10::Dunamic)
                {
                    F10::Dunamic = Summon(0, 21, 117432, 36840, 566, 1, 0, 16000, 3616000, 0);
                    IChar Dunamic((void*)F10::Dunamic);

                    if (Dunamic.IsValid())
                        Undefined::MonsterPath(*(void **)(F10::Dunamic + 320), F10::Dunamic, 0, -1, 0, 1);
                }
            }

            if (IMonster.IsValid() && Check == 3646)
                Undefined::MonsterPath(*(void **)((int)Monster + 320), (int)Monster, 0, 120, 0, 1);

            if (IMonster.IsValid() && Check == 3644)
                Undefined::MonsterPath(*(void **)((int)Monster + 320), (int)Monster, 0, 120, 0, 1);

            if (IMonster.IsValid() && Check == 3642)
                Undefined::MonsterPath(*(void **)((int)Monster + 320), (int)Monster, 0, 120, 0, 1);

            if (IMonster.IsValid() && Check == 3640)
                Undefined::MonsterPath(*(void **)((int)Monster + 320), (int)Monster, 0, 120, 0, 1);

            if (IMonster.IsValid() && Check == 3638)
                Undefined::MonsterPath(*(void **)((int)Monster + 320), (int)Monster, 0, 120, 0, 1);

            if (IMonster.IsValid() && Check == 3635)
                Undefined::MonsterPath(*(void **)((int)Monster + 320), (int)Monster, 0, -1, 0, 1);

            if (IMonster.IsValid() && Check == 3634)
            {
                for (int x = 0; x < 10; x++)
                    Summon(0, 21, CTools::Rate(117028, 117028+550), CTools::Rate(36601, 36601+550),
                           564, 1, 1, 0, 0, 0);

                int Around = IMonster.GetObjectListAround(50);

                while(Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.GetType() == 0 && Object.IsBuff(165))
                    {
                        Object.Buff(308,3600,0);
                        Object.ScreenTime(3600);
                    }

                    Around = CBaseList::Pop((void*)Around);
                }

                F10::ShowTime = 3600;
            }

            if ((Check == 300 || Check == 600 || Check == 900 || Check == 1200
                    || Check == 1500 || Check == 1800 || Check == 2100 || Check == 2400
                    || Check == 3000 || Check == 3300) && F10::Active == true && IMonster.IsValid())
            {
                for(int x = 0; x < 8; x++)
                    Summon(0, 21, CTools::Rate(117028, 117028+550), CTools::Rate(36601, 36601+550),
                           564, 1, 1, 0, 0, 0);
            }

            if (IMonster.IsValid() && Check <= 33)
            {
                CPlayer::WriteInMap(21, 0xFF, "dsd", 247, "Company System failed...", 3);

                int Around = IMonster.GetObjectListAround(50);

                while(Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.GetType() == 0 && Object.IsBuff(165))
                        Object.CloseScreenTime();

                    Around = CBaseList::Pop((void*)Around);
                }

                F10::CheiosSkillDelay = 0;
                F10::DunamicSkillDelay = 0;
                F10::Dunamic = 0;
                F10::Cheios = 0;
                F10::KillCount = 0;
                F10::RegisterAmount = 0;
                F10Registration.clear();
                F10::Active = false;
            }
        } else {
            CPlayer::WriteInMap(21, 0xFF, "dsd", 247, "Thank you for saving the world...",
                                3);
            int Around = IMonster.GetObjectListAround(50);

            while(Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.GetType() == 0 && Object.IsBuff(165))
                {
                    (*(int (__cdecl **)(int, signed int, signed int, unsigned __int64,
                                        unsigned __int64))(*(DWORD *)Object.GetOffset() + 88))
                        ((int)Object.GetOffset(), 25, 1, (unsigned __int64)F10Exp, HIDWORD(F10Exp));
                    Object.CloseScreenTime();
                }

                Around = CBaseList::Pop((void*)Around);
            }

            F10::CheiosSkillDelay = 0;
            F10::DunamicSkillDelay = 0;
            F10::Dunamic = 0;
            F10::Cheios = 0;
            F10::KillCount = 0;
            F10::RegisterAmount = 0;
            F10Registration.clear();
            F10::Active = false;
        }
    }

    if (IMonster.IsValid() && IMonster.GetMobIndex() >= 352
            && IMonster.GetMobIndex() <= 360)
    {
        if (IMonster.GetCurHp() <= (CChar::GetMaxHp((int)IMonster.GetOffset()) / 100 *
                                    25))
            CChar::WriteInSight(IMonster.GetOffset(),46,"dI",IMonster.GetID(),
                                __int64(0x00100000) << 32);
        else if (IMonster.GetCurHp() <= (CChar::GetMaxHp((int)IMonster.GetOffset()) /
                                         100 * 50))
            CChar::WriteInSight(IMonster.GetOffset(),46,"dI",IMonster.GetID(),
                                __int64(0x00080000) << 32);
        else
            CChar::WriteInSight(IMonster.GetOffset(),46,"dI",IMonster.GetID(),__int64(0));
    }

    if (IMonster.IsValid() && IMonster.GetMobIndex() == 382
            && (GetTickCount() / 1000) % 300 == 0)
    {
        for (int i = 0; i < 6; i++)
        {
            Summon(0, EmokMap, IMonster.GetX(), IMonster.GetY(), 385, 1, 1, 0, 0, 0);
        }

        for (int i = 0; i < 6; i++)
        {
            Summon(0, EmokMap, IMonster.GetX(), IMonster.GetY(), 386, 1, 1, 0, 0, 0);
        }
    }

    if (IMonster.IsValid() && MonsterDisappear.count((int)IMonster.GetOffset())
            && MonsterDisappear.find((int)IMonster.GetOffset())->second
            && GetTickCount() >= MonsterDisappear.find((int)IMonster.GetOffset())->second)
    {
        MonsterDisappear[(int)IMonster.GetOffset()] = 0;
        IMonster.MobDelete();
        return 0;
    }

    if (IMonster.IsValid() && IMonster.GetMobIndex() == 566
            && IMonster.GetMobTanker() && GetTickCount() >= F10::DunamicSkillDelay)
    {
        if (IMonster.IsValid() && F10::DunamicSkillDelay
                && GetTickCount() >= F10::DunamicSkillDelay)
        {
            F10::DunamicSkillDelay = 0;

            if (IMonster.IsValid() && F10::DunamicSkill == 1)
            {
                F10::DunamicSkill = 0;
                int Around = IMonster.GetObjectListAround(3);

                while(Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.GetType() == 0)
                        IMonster.OktayDamageStorm(Object,CTools::Rate(1000,1250));

                    Around = CBaseList::Pop((void*)Around);
                }
            }

            if (IMonster.IsValid() && F10::DunamicSkill == 2)
            {
                F10::DunamicSkill = 0;

                int Around = IMonster.GetObjectListAround(3);

                while(Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.GetType() == 0 && !Object.IsBuff(371))
                    {
                        Object.SetBuffIcon(10000,0,2038,224);
                        Object.Buff(370,10,0);
                        Object.Buff(371,3600,0);
                    }

                    Around = CBaseList::Pop((void*)Around);
                }
            }
        }

        if (IMonster.IsValid() && (GetTickCount() / 1000) % 45 == 0)
        {
            F10::DunamicSkill = 2;
            F10::DunamicSkillDelay = GetTickCount() + 1000;
            CChar::WriteInSight(IMonster.Offset, 61, "dbbd", IMonster.GetID(), 5, 19,
                                IMonster.GetID());
        }

        if (IMonster.IsValid() && (GetTickCount() / 1000) % 75 == 0)
        {
            F10::DunamicSkill = 2;
            F10::DunamicSkillDelay = GetTickCount() + 1000;
            CChar::WriteInSight(IMonster.Offset, 61, "dbbd", IMonster.GetID(), 5, 27,
                                IMonster.GetID());
        }
    }

    if (IMonster.IsValid() && IMonster.GetMobIndex() == 572
            && IMonster.GetMobTanker() && GetTickCount() >= F10::CheiosSkillDelay)
    {
        if (IMonster.IsValid() && F10::CheiosSkillDelay
                && GetTickCount() >= F10::CheiosSkillDelay)
        {
            F10::CheiosSkillDelay = 0;

            if (IMonster.IsValid() && F10::CheiosSkill == 1)
            {
                CChar::WriteInSight(IMonster.Offset, 61, "dbbd", IMonster.GetID(), 5, 19,
                                    IMonster.GetID());
                F10::CheiosSkill = 0;
                int Around = IMonster.GetObjectListAround(3);

                while(Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.GetType() == 0)
                        IMonster.OktayDamageStorm(Object,CTools::Rate(1000,1250));

                    Around = CBaseList::Pop((void*)Around);
                }
            }

            if (IMonster.IsValid() && F10::CheiosSkill == 2)
            {
                CChar::WriteInSight(IMonster.Offset, 61, "dbbd", IMonster.GetID(), 5, 20,
                                    IMonster.GetID());
                F10::CheiosSkill = 0;

                int Around = IMonster.GetObjectListAround(3);

                while(Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.GetType() == 0 && !Object.IsBuff(369))
                    {
                        if (Object.GetEva() >= 10)
                        {
                            Object.SetBuffIcon(-2, -1, 2042, 226);
                            Object.RemoveEva(10);
                            Object.Buff(40, 10, -50);
                            Object.Buff(368,10,0);
                            Object.Buff(369,3600,0);
                        }
                    }

                    Around = CBaseList::Pop((void*)Around);
                }
            }
        }

        if (IMonster.IsValid() && (GetTickCount() / 1000) % 45 == 0)
        {
            F10::CheiosSkill = 1;
            F10::CheiosSkillDelay = GetTickCount() + 2000;
            CChar::WriteInSight(IMonster.Offset, 61, "dbbd", IMonster.GetID(), 5, 26,
                                IMonster.GetID());
        }

        if (IMonster.IsValid() && (GetTickCount() / 1000) % 75 == 0)
        {
            F10::CheiosSkill = 2;
            F10::CheiosSkillDelay = GetTickCount() + 1000;
            CChar::WriteInSight(IMonster.Offset, 61, "dbbd", IMonster.GetID(), 5, 28,
                                IMonster.GetID());
        }
    }

    if (IMonster.IsValid() && F10::Active == false
            && (IMonster.GetMobIndex() == 564 || IMonster.GetMobIndex() == 566
                || IMonster.GetMobIndex() == 572 || IMonster.GetMobIndex() == 573))
    {
        IMonster.MobDelete();
        return 0;
    }

    if (IMonster.IsValid() && Battlefield::Active == false
            && (IMonster.GetMobIndex() == 445 || IMonster.GetMobIndex() == 448))
    {
        IMonster.MobDelete();
        return 0;
    }

    if (IMonster.IsValid() && Scenario::Active == false
            && (IMonster.GetMobIndex() >= 352 && IMonster.GetMobIndex() <= 360))
    {
        IMonster.MobDelete();
        return 0;
    }

    if (IMonster.IsValid() && Hell::Active == false && IMonster.IsBuff(168))
    {
        IMonster.MobDelete();
        return 0;
    }

    if (IMonster.IsValid() && SummonAi.count((int)IMonster.GetOffset()))
    {
        IChar IPlayer(SummonAi.find((int)IMonster.GetOffset())->second);

        if (!IPlayer.IsValid())
        {
            IMonster.MobDelete();
            return 0;
        }

        if (IPlayer.IsOnline() && IMonster.IsValid() && IMonster.GetMobTanker()
                && IMonster.GetMobTanker() != (int)IPlayer.GetOffset())
        {
            if (!IPlayer.GetPartyID())
            {
                IMonster.MobDelete();
                return 0;
            } else {
                IChar Tanker((void*)IMonster.GetMobTanker());

                if (Tanker.GetPartyID() != IPlayer.GetPartyID())
                {
                    IMonster.MobDelete();
                    return 0;
                }
            }
        }

        if (IPlayer.IsOnline()
                && CChar::GetRange((int)IPlayer.GetOffset() + 332,
                                   (int)IMonster.GetOffset() + 332) >= 300)
        {
            IMonster.MobDelete();
            return 0;
        }

        if (IPlayer.IsValid() && IMonster.IsValid() && IMonster.GetCurHp() > 0
                && !IMonster.GetMobTanker())
        {
            int Target = CMonsterReal::ScanSight((int)IMonster.GetOffset());
            IChar xPlayer((void*)Target);

            if (xPlayer.IsValid() && xPlayer.GetOffset() == IPlayer.GetOffset())
                IMonster.SetMobTarget(Target);
        }
    }

    return CMonsterMaguniMaster::Tick(Monster);
}
