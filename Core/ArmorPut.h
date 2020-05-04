int getItemStat(int x, int y, int item) {
    IItem IItem((void*)item);
    return (GetItemStat.find(IItem.GetIID())->second % x) / y;
}

void playerAddStats(int x, int y, int z, int player) {
    IChar IPlayer((void*)player);
    IPlayer.AddDef(z / 100);
    switch ( x % 5 ) {
        case 0:
            IPlayer.AddAgi(y);
        case 1:
            IPlayer.AddStr(y);
        case 2:
            IPlayer.AddHp(y);
        case 3:
            IPlayer.AddInt(y);
        case 4:
            IPlayer.AddWis(y);
    }
}

void playerAddAgiStrInt(int value, int player) {
    IChar IPlayer((void*)player);
    IPlayer.AddAgi(value);
    IPlayer.AddStr(value);
    IPlayer.AddInt(value);
}

void playerRemoveAgiStrInt(int value, int player) {
    IChar IPlayer((void*)player);
    IPlayer.RemoveAgi(value);
    IPlayer.RemoveStr(value);
    IPlayer.RemoveInt(value);
}

int getStat(int grade) {

    if (grade >= 46 && grade <= 49) {
        return 1;
    }

    if (grade >= 50 && grade <= 53) {
        return 2;
    }

    if (grade >= 55 && grade <= 58) {
        return 3;
    }

    if (grade >= 60 && grade <= 63) {
        return 4;
    }

    if (grade >= 65 && grade <= 68) {
        return 5;
    }

    if (grade >= 70 && grade <= 73) {
        return 6;
    }

    if (grade >= 80 && grade <= 83) {
        return 7;
    }

    if (grade >= 90 && grade <= 93) {
        return 8;
    }

    if (grade >= 95) {
        return 9;
    }

    return 0;
}

void setBeadOfFire(int grade, int type, int player) {
    IChar IPlayer((void*)player);
    switch (type) {
        case 2:
            BeadOfFire[IPlayer.GetPID()].Helmet = grade;
        case 3:
            BeadOfFire[IPlayer.GetPID()].Chest = grade;
        case 4:
            BeadOfFire[IPlayer.GetPID()].Short = grade;
        case 5:
            BeadOfFire[IPlayer.GetPID()].Gloves = grade;
        case 6:
            BeadOfFire[IPlayer.GetPID()].Boots = grade;
    }
}

void beadOfFireApply(int grade, int attr, int player, bool remove) {

    IChar IPlayer((void*)player);
    CheckBof bof = BeadOfFire.find(IPlayer.GetPID())->second;

    if (bof.HalfSet == grade && (bof.Boots != grade || bof.Short != grade || bof.Gloves != grade))
    {
        if (remove) {
            BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
            playerRemoveAgiStrInt(attr, player);
        } else {
            BeadOfFire[IPlayer.GetPID()].HalfSet = grade;
            playerAddAgiStrInt(attr, player);
        }
    }

    if (bof.FullSet == grade && (bof.HalfSet != grade || bof.Chest != grade || bof.Helmet != grade))
    {
        if (remove) {
            BeadOfFire[IPlayer.GetPID()].FullSet = 0;
            playerRemoveAgiStrInt(attr, player);
        } else {
            BeadOfFire[IPlayer.GetPID()].FullSet = grade;
            playerAddAgiStrInt(attr, player);
        }
    }
}

void __fastcall DefenseApplySpec(int Item, void *edx, int Player)
{
    IItem IItem((void*)Item);
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline())
    {
        int def = IPlayer.GetDef();
        CItemDefense::ApplySpec(Item, Player);
        int check = IPlayer.GetDef() - (def + *((DWORD*)Item + 27));
        int FirstDemonGongType = 0, SecondDemonGongType = 0;
        int FirstDemonGongStat = 0, SecondDemonGongStat = 0;

        if (GetItemStat.count(IItem.GetIID()))
        {
            // 100000000 = 100.000.000 | 10000000  = 10.000.000
            FirstDemonGongType = getItemStat(100000000, 10000000, Item);

            // 1000000 = 1.000.000 | 100000  = 100.000
            SecondDemonGongType = getItemStat(1000000, 100000, Item);

            // 10000000 = 10.000.000 | 1000000 = 1.000.000)
            FirstDemonGongStat = getItemStat(10000000, 1000000, Item);

            // 100000 = 100.000 | 10000 = 10.000)
            SecondDemonGongStat = getItemStat(100000, 10000, Item);
        }

        switch (FirstDemonGongType)
        {
            case 1:
                IPlayer.AddDef(DemonGongStatArmorEarth[0][FirstDemonGongStat - 1]);
                IPlayer.AddOTP(DemonGongStatArmorEarth[1][FirstDemonGongStat - 1]);
            case 2:
                IPlayer.IncreaseMaxHp(DemonGongStatArmorWind[0][FirstDemonGongStat - 1]);
                IPlayer.AddEva(DemonGongStatArmorWind[1][FirstDemonGongStat - 1]);
            case 3:
                IPlayer.AddAgi(DemonGongStatArmorWater[0][FirstDemonGongStat - 1]);
                IPlayer.AddDef(DemonGongStatArmorWater[1][FirstDemonGongStat - 1]);
        }

        switch (SecondDemonGongType)
        {
            case 1:
                IPlayer.AddDef(DemonGongStatArmorEarth[0][SecondDemonGongStat - 1]);
                IPlayer.AddOTP(DemonGongStatArmorEarth[1][SecondDemonGongStat - 1]);
            case 2:
                IPlayer.IncreaseMaxHp(DemonGongStatArmorWind[0][SecondDemonGongStat - 1]);
                IPlayer.AddEva(DemonGongStatArmorWind[1][SecondDemonGongStat - 1]);
            case 3:
                IPlayer.AddAgi(DemonGongStatArmorWater[0][SecondDemonGongStat - 1]);
                IPlayer.AddDef(DemonGongStatArmorWater[1][SecondDemonGongStat - 1]);
        }

        if (GetItemStat.find(IItem.GetIID())->second > 0)
        {
            int QigongType = GetItemStat.find(IItem.GetIID())->second % 100;

            if (QigongType)
            {
                if (IItem.GetType() == 3) {
                    IPlayer.AddDef((check * QigongChest[QigongType - 1][0]) / 100);
                } else if (IItem.GetType() == 4) {
                    IPlayer.AddDef((check * QigongShort[QigongType - 1][0]) / 100);
                } else {
                    IPlayer.AddDef((check * QigongMain[QigongType - 1][0]) / 100);
                }

                int Type = QigongChest[QigongType - 1][1];
                int Stat = QigongChest[QigongType - 1][2];

                switch (Type) {
                    case 0:
                        IPlayer.AddStr(Stat);
                    case 1:
                        IPlayer.AddHp(Stat);
                    case 2:
                        IPlayer.AddInt(Stat);
                    case 3:
                        IPlayer.AddWis(Stat);
                    case 4:
                        IPlayer.AddAgi(Stat);
                }
            }
        }

        int nItemGST = IItem.GetSetGem() - 200;

        if (nItemGST >= 36 && nItemGST <= 40) {
            playerAddStats(nItemGST, 7, (check * 18), Player);
        }

        if (nItemGST >= 31 && nItemGST <= 35) {
            playerAddStats(nItemGST, 5, (check * 16), Player);
        }

        if (nItemGST >= 26 && nItemGST <= 30) {
            playerAddStats(nItemGST, 3, (check * 14), Player);
        }

        if (nItemGST >= 21 && nItemGST <= 25) {
            playerAddStats(nItemGST, 3, (check * 12), Player);
        }

        if (nItemGST >= 16 && nItemGST <= 20) {
            playerAddStats(nItemGST, 2, (check * 10), Player);
        }

        if (nItemGST >= 11 && nItemGST <= 15) {
            playerAddStats(nItemGST, 2, (check * 8), Player);
        }

        if (nItemGST >= 6 && nItemGST <= 10) {
            playerAddStats(nItemGST, 1, (check * 6), Player);
        }

        if (nItemGST >= 1 && nItemGST <= 5) {
            playerAddStats(nItemGST, 1, (check * 4), Player);
        }

        if (IItem.GetInfo() & 2097152)
        {
            int Grade = *(DWORD*)(*(DWORD*)(Item + 40) + 80);
            int Stat = getStat(Grade);

            playerAddAgiStrInt(Stat, Player);

            setBeadOfFire(Grade, IItem.GetType(), Player)

            switch (IItem.GetType()) {
                case 2:
                    BeadOfFire[IPlayer.GetPID()].Helmet = Grade;
                case 3:
                    BeadOfFire[IPlayer.GetPID()].Chest = Grade;
                case 4:
                    BeadOfFire[IPlayer.GetPID()].Short = Grade;
                case 5:
                    BeadOfFire[IPlayer.GetPID()].Gloves = Grade;
                case 6:
                    BeadOfFire[IPlayer.GetPID()].Boots = Grade;
            }

            if (!BeadOfFire.count(IPlayer.GetPID())) {
                return;
            }

            CheckBof bof = BeadOfFire.find(IPlayer.GetPID())->second;

            beadOfFireApply(46, 1, Player, false);
            beadOfFireApply(50, 2, Player, false);
            beadOfFireApply(55, 3, Player, false);
            beadOfFireApply(60, 4, Player, false);
            beadOfFireApply(65, 5, Player, false);
            beadOfFireApply(70, 6, Player, false);
            beadOfFireApply(80, 7, Player, false);
            beadOfFireApply(90, 8, Player, false);
            beadOfFireApply(95, 9, Player, false);
        }
    }
}

void __fastcall ArmorPutOn(int Item, void *edx, int Player)
{
    IItem IItem((void*)Item);
    IChar IPlayer((void*)Player);

    if (!IPlayer.IsOnline()) {
        return;
    }

    if (IPlayer.IsBuff(256))
    {
        IPlayer.SystemMessage("You need to wait 3 seconds to put on your armor.",
            TEXTCOLOR_INFOMSG);
        return;
    }

    IPlayer.Buff(256, 2, 0);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(120))
    {
        if (IItem.LevelLimit() > 5) {
            IItem.SetLevelLimit(IItem.LevelLimit() - 5);
        }
    }

    CItemDefense::PutOn(Item, Player);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(120))
    {
        if (IItem.LevelLimit() > 5) {
            IItem.SetLevelLimit(IItem.LevelLimit() + 5);
        }
    }
}

void __fastcall DefensePutOff(void *Item, void *edx, int Player)
{
    IItem IItem(Item);
    IChar IPlayer((void*)Player);

    if (!IPlayer.IsOnline()) {
        return;
    }

    if (IPlayer.IsBuff(256))
    {
        IPlayer.SystemMessage("You need to wait 3 seconds to put off your armor.",
            TEXTCOLOR_INFOMSG);
        return;
    }

    IPlayer.Buff(256, 2, 0);

    if (IItem.GetInfo() & 2097152)
    {
        int Grade = *(DWORD*)(*(DWORD*)((int)Item + 40) + 80);
        int Stat = getStat(Grade);

        IPlayer.RemoveAgi(Stat);
        IPlayer.RemoveStr(Stat);
        IPlayer.RemoveInt(Stat);

        setBeadOfFire(0, IItem.GetType(), Player)

        if (BeadOfFire.count(IPlayer.GetPID())) {

            CheckBof bof = BeadOfFire.find(IPlayer.GetPID())->second;

            beadOfFireApply(46, 1, Player, true);
            beadOfFireApply(50, 2, Player, true);
            beadOfFireApply(55, 3, Player, true);
            beadOfFireApply(60, 4, Player, true);
            beadOfFireApply(65, 5, Player, true);
            beadOfFireApply(70, 6, Player, true);
            beadOfFireApply(80, 7, Player, true);
            beadOfFireApply(90, 8, Player, true);
            beadOfFireApply(95, 9, Player, true);
        }
    }

    int def = IPlayer.GetDef();
    CItemDefense::PutOff(Item, Player);
    int check = def - (IPlayer.GetDef() + *((DWORD *)Item + 27));
    int FirstDemonGongType = 0, SecondDemonGongType = 0;
    int FirstDemonGongStat = 0, SecondDemonGongStat = 0;

    if (GetItemStat.count(IItem.GetIID()))
    {
        FirstDemonGongType = (GetItemStat.find(IItem.GetIID())->second % 100000000) /
            10000000;
        SecondDemonGongType = (GetItemStat.find(IItem.GetIID())->second % 1000000) /
            100000;
        FirstDemonGongStat = (GetItemStat.find(IItem.GetIID())->second % 10000000) /
            1000000;
        SecondDemonGongStat = (GetItemStat.find(IItem.GetIID())->second % 100000) /
            10000;
    }

    if (FirstDemonGongType)
    {
        if (FirstDemonGongType == 1)
        {
            IPlayer.RemoveDef(DemonGongStatArmorEarth[0][FirstDemonGongStat - 1]);
            IPlayer.RemoveOTP(DemonGongStatArmorEarth[1][FirstDemonGongStat - 1]);
        }

        if (FirstDemonGongType == 2)
        {
            IPlayer.DecreaseMaxHp(DemonGongStatArmorWind[0][FirstDemonGongStat - 1]);
            IPlayer.RemoveEva(DemonGongStatArmorWind[1][FirstDemonGongStat - 1]);
        }

        if (FirstDemonGongType == 3)
        {
            IPlayer.RemoveAgi(DemonGongStatArmorWater[0][FirstDemonGongStat - 1]);
            IPlayer.RemoveDef(DemonGongStatArmorWater[1][FirstDemonGongStat - 1]);
        }
    }

    if (SecondDemonGongType)
    {
        if (SecondDemonGongType == 1)
        {
            IPlayer.RemoveDef(DemonGongStatArmorEarth[0][SecondDemonGongStat - 1]);
            IPlayer.RemoveOTP(DemonGongStatArmorEarth[1][SecondDemonGongStat - 1]);
        }

        if (SecondDemonGongType == 2)
        {
            IPlayer.DecreaseMaxHp(DemonGongStatArmorWind[0][SecondDemonGongStat - 1]);
            IPlayer.RemoveEva(DemonGongStatArmorWind[1][SecondDemonGongStat - 1]);
        }

        if (SecondDemonGongType == 3)
        {
            IPlayer.RemoveAgi(DemonGongStatArmorWater[0][SecondDemonGongStat - 1]);
            IPlayer.RemoveDef(DemonGongStatArmorWater[1][SecondDemonGongStat - 1]);
        }
    }

    if (GetItemStat.find(IItem.GetIID())->second > 0)
    {
        int QigongType = GetItemStat.find(IItem.GetIID())->second % 100;

        if (QigongType)
        {
            if (IItem.GetType() == 3)
            {
                IPlayer.RemoveDef((check * QigongChest[QigongType - 1][0]) / 100);
                int Type = QigongChest[QigongType - 1][1];
                int Stat = QigongChest[QigongType - 1][2];

                if (Type == 0) {
                    IPlayer.RemoveStr(Stat);
                }
                else if (Type == 1) {
                    IPlayer.RemoveHp(Stat);
                }
                else if (Type == 2) {
                    IPlayer.RemoveInt(Stat);
                }
                else if (Type == 3) {
                    IPlayer.RemoveWis(Stat);
                }
                else if (Type == 4) {
                    IPlayer.RemoveAgi(Stat);
                }
            } else if (IItem.GetType() == 4)
            {
                IPlayer.RemoveDef((check * QigongShort[QigongType - 1][0]) / 100);
                int Type = QigongChest[QigongType - 1][1];
                int Stat = QigongChest[QigongType - 1][2];

                if (Type == 0) {
                    IPlayer.RemoveStr(Stat);
                }
                else if (Type == 1) {
                    IPlayer.RemoveHp(Stat);
                }
                else if (Type == 2) {
                    IPlayer.RemoveInt(Stat);
                }
                else if (Type == 3) {
                    IPlayer.RemoveWis(Stat);
                }
                else if (Type == 4) {
                    IPlayer.RemoveAgi(Stat);
                }
            } else {
                IPlayer.RemoveDef((check * QigongMain[QigongType - 1][0]) / 100);
                int Type = QigongChest[QigongType - 1][1];
                int Stat = QigongChest[QigongType - 1][2];

                if (Type == 0) {
                    IPlayer.RemoveStr(Stat);
                }
                else if (Type == 1) {
                    IPlayer.RemoveHp(Stat);
                }
                else if (Type == 2) {
                    IPlayer.RemoveInt(Stat);
                }
                else if (Type == 3) {
                    IPlayer.RemoveWis(Stat);
                }
                else if (Type == 4) {
                    IPlayer.RemoveAgi(Stat);
                }
            }
        }
    }

    if (IItem.GetSetGem() == 240)
    {
        IPlayer.RemoveDef((check * 18) / 100);
        IPlayer.RemoveAgi(7);
    } else if (IItem.GetSetGem() == 239)
    {
        IPlayer.RemoveDef((check * 18) / 100);
        IPlayer.RemoveWis(7);
    } else if (IItem.GetSetGem() == 238)
    {
        IPlayer.RemoveDef((check * 18) / 100);
        IPlayer.RemoveInt(7);
    } else if (IItem.GetSetGem() == 237)
    {
        IPlayer.RemoveDef((check * 18) / 100);
        IPlayer.RemoveHp(7);
    } else if (IItem.GetSetGem() == 236)
    {
        IPlayer.RemoveDef((check * 18) / 100);
        IPlayer.RemoveStr(7);
    } else if (IItem.GetSetGem() == 235)
    {
        IPlayer.RemoveDef((check * 16) / 100);
        IPlayer.RemoveAgi(5);
    } else if (IItem.GetSetGem() == 234)
    {
        IPlayer.RemoveDef((check * 16) / 100);
        IPlayer.RemoveWis(5);
    } else if (IItem.GetSetGem() == 233)
    {
        IPlayer.RemoveDef((check * 16) / 100);
        IPlayer.RemoveInt(5);
    } else if (IItem.GetSetGem() == 232)
    {
        IPlayer.RemoveDef((check * 16) / 100);
        IPlayer.RemoveHp(5);
    } else if (IItem.GetSetGem() == 231)
    {
        IPlayer.RemoveDef((check * 16) / 100);
        IPlayer.RemoveStr(5);
    } else if (IItem.GetSetGem() == 230)
    {
        IPlayer.RemoveDef((check * 14) / 100);
        IPlayer.RemoveAgi(3);
    } else if (IItem.GetSetGem() == 229)
    {
        IPlayer.RemoveDef((check * 14) / 100);
        IPlayer.RemoveWis(3);
    } else if (IItem.GetSetGem() == 228)
    {
        IPlayer.RemoveDef((check * 14) / 100);
        IPlayer.RemoveInt(3);
    } else if (IItem.GetSetGem() == 227)
    {
        IPlayer.RemoveDef((check * 14) / 100);
        IPlayer.RemoveHp(3);
    } else if (IItem.GetSetGem() == 226)
    {
        IPlayer.RemoveDef((check * 14) / 100);
        IPlayer.RemoveStr(3);
    } else if (IItem.GetSetGem() == 225)
    {
        IPlayer.RemoveDef((check * 12) / 100);
        IPlayer.RemoveAgi(3);
    } else if (IItem.GetSetGem() == 224)
    {
        IPlayer.RemoveDef((check * 12) / 100);
        IPlayer.RemoveWis(3);
    } else if (IItem.GetSetGem() == 223)
    {
        IPlayer.RemoveDef((check * 12) / 100);
        IPlayer.RemoveInt(3);
    } else if (IItem.GetSetGem() == 222)
    {
        IPlayer.RemoveDef((check * 12) / 100);
        IPlayer.RemoveHp(3);
    } else if (IItem.GetSetGem() == 221)
    {
        IPlayer.RemoveDef((check * 12) / 100);
        IPlayer.RemoveStr(3);
    } else if (IItem.GetSetGem() == 220)
    {
        IPlayer.RemoveDef((check * 10) / 100);
        IPlayer.RemoveAgi(2);
    } else if (IItem.GetSetGem() == 219)
    {
        IPlayer.RemoveDef((check * 10) / 100);
        IPlayer.RemoveWis(2);
    } else if (IItem.GetSetGem() == 218)
    {
        IPlayer.RemoveDef((check * 10) / 100);
        IPlayer.RemoveInt(2);
    } else if (IItem.GetSetGem() == 217)
    {
        IPlayer.RemoveDef((check * 10) / 100);
        IPlayer.RemoveHp(2);
    } else if (IItem.GetSetGem() == 216)
    {
        IPlayer.RemoveDef((check * 10) / 100);
        IPlayer.RemoveStr(2);
    } else if (IItem.GetSetGem() == 215)
    {
        IPlayer.RemoveDef((check * 8) / 100);
        IPlayer.RemoveAgi(2);
    } else if (IItem.GetSetGem() == 214)
    {
        IPlayer.RemoveDef((check * 8) / 100);
        IPlayer.RemoveWis(2);
    } else if (IItem.GetSetGem() == 213)
    {
        IPlayer.RemoveDef((check * 8) / 100);
        IPlayer.RemoveInt(2);
    } else if (IItem.GetSetGem() == 212)
    {
        IPlayer.RemoveDef((check * 8) / 100);
        IPlayer.RemoveHp(2);
    } else if (IItem.GetSetGem() == 211)
    {
        IPlayer.RemoveDef((check * 8) / 100);
        IPlayer.RemoveStr(2);
    } else if (IItem.GetSetGem() == 210)
    {
        IPlayer.RemoveDef((check * 6) / 100);
        IPlayer.RemoveAgi(1);
    } else if (IItem.GetSetGem() == 209)
    {
        IPlayer.RemoveDef((check * 6) / 100);
        IPlayer.RemoveWis(1);
    } else if (IItem.GetSetGem() == 208)
    {
        IPlayer.RemoveDef((check * 6) / 100);
        IPlayer.RemoveInt(1);
    } else if (IItem.GetSetGem() == 207)
    {
        IPlayer.RemoveDef((check * 6) / 100);
        IPlayer.RemoveHp(1);
    } else if (IItem.GetSetGem() == 206)
    {
        IPlayer.RemoveDef((check * 6) / 100);
        IPlayer.RemoveStr(1);
    } else if (IItem.GetSetGem() == 205)
    {
        IPlayer.RemoveDef((check * 4) / 100);
        IPlayer.RemoveAgi(1);
    } else if (IItem.GetSetGem() == 204)
    {
        IPlayer.RemoveDef((check * 4) / 100);
        IPlayer.RemoveWis(1);
    } else if (IItem.GetSetGem() == 203)
    {
        IPlayer.RemoveDef((check * 4) / 100);
        IPlayer.RemoveInt(1);
    } else if (IItem.GetSetGem() == 202)
    {
        IPlayer.RemoveDef((check * 4) / 100);
        IPlayer.RemoveHp(1);
    } else if (IItem.GetSetGem() == 201)
    {
        IPlayer.RemoveDef((check * 4) / 100);
        IPlayer.RemoveStr(1);
    }
}
