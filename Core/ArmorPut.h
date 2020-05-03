int getItemStat(int x, int y) {
    return (GetItemStat.find(IItem.GetIID())->second % x) / y;
}

void playerAddStats(int x, int y, int z) {
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

void playerAddAgiStrInt(int value) {
    IPlayer.AddAgi(value);
    IPlayer.AddStr(value);
    IPlayer.AddInt(value);
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
            FirstDemonGongType = getItemStat(100000000, 10000000);

            // 1000000 = 1.000.000 | 100000  = 100.000
            SecondDemonGongType = getItemStat(1000000, 100000);

            // 10000000 = 10.000.000 | 1000000 = 1.000.000)
            FirstDemonGongStat = getItemStat(10000000, 1000000);

            // 100000 = 100.000 | 10000 = 10.000)
            SecondDemonGongStat = getItemStat(100000, 10000);
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
            playerAddStats(nItemGST, 7, (check * 18));
        }

        if (nItemGST >= 31 && nItemGST <= 35) {
            playerAddStats(nItemGST, 5, (check * 16));
        }

        if (nItemGST >= 26 && nItemGST <= 30) {
            playerAddStats(nItemGST, 3, (check * 14));
        }

        if (nItemGST >= 21 && nItemGST <= 25) {
            playerAddStats(nItemGST, 3, (check * 12));
        }

        if (nItemGST >= 16 && nItemGST <= 20) {
            playerAddStats(nItemGST, 2, (check * 10));
        }

        if (nItemGST >= 11 && nItemGST <= 15) {
            playerAddStats(nItemGST, 2, (check * 8));
        }

        if (nItemGST >= 6 && nItemGST <= 10) {
            playerAddStats(nItemGST, 1, (check * 6));
        }

        if (nItemGST >= 1 && nItemGST <= 5) {
            playerAddStats(nItemGST, 1, (check * 4));
        }

        if (IItem.GetInfo() & 2097152)
        {
            int Grade = *(DWORD*)(*(DWORD*)(Item + 40) + 80);
            int Stat = 0;

            if (Grade >= 46 && Grade <= 49) {
                Stat = 1;
            }

            if (Grade >= 50 && Grade <= 53) {
                Stat = 2;
            }

            if (Grade >= 55 && Grade <= 58) {
                Stat = 3;
            }

            if (Grade >= 60 && Grade <= 63) {
                Stat = 4;
            }

            if (Grade >= 65 && Grade <= 68) {
                Stat = 5;
            }

            if (Grade >= 70 && Grade <= 73) {
                Stat = 6;
            }

            if (Grade >= 80 && Grade <= 83) {
                Stat = 7;
            }

            if (Grade >= 90 && Grade <= 93) {
                Stat = 8;
            }

            if (Grade >= 95) {
                Stat = 9;
            }

            playerAddAgiStrInt(Stat);

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

            if (bof.Boots == 46 && bof.Short == 46 && bof.Gloves == 46 && !bof.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 46;
                playerAddAgiStrInt(1);
            }

            if (bof.Helmet == 46 && bof.Chest == 46 && bof.HalfSet == 46 && !bof.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 46;
                playerAddAgiStrInt(1);
            }

            if (bof.Boots == 50 && bof.Short == 50 && bof.Gloves == 50 && !bof.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 50;
                playerAddAgiStrInt(2);
            }

            if (bof.Helmet == 50 && bof.Chest == 50 && bof.HalfSet == 50 && !bof.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 50;
                playerAddAgiStrInt(2);
            }

            if (bof.Boots == 55 && bof.Short == 55 && bof.Gloves == 55 && !bof.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 55;
                playerAddAgiStrInt(3);
            }

            if (bof.Helmet == 55 && bof.Chest == 55 && bof.HalfSet == 55 && !bof.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 55;
                playerAddAgiStrInt(3);
            }

            if (bof.Boots == 60 && bof.Short == 60 && bof.Gloves == 60 && !bof.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 60;
                playerAddAgiStrInt(4);
            }

            if (bof.Helmet == 60 && bof.Chest == 60 && bof.HalfSet == 60 && !bof.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 60;
                playerAddAgiStrInt(4);
            }

            if (bof.Boots == 65 && bof.Short == 65 && bof.Gloves == 65 && !bof.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 65;
                playerAddAgiStrInt(5);
            }

            if (bof.Helmet == 65 && bof.Chest == 65 && bof.HalfSet == 65 && !bof.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 65;
                playerAddAgiStrInt(5);
            }

            if (bof.Boots == 70 && bof.Short == 70 && bof.Gloves == 70 && !bof.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 70;
                playerAddAgiStrInt(6);
            }

            if (bof.Helmet == 70 && bof.Chest == 70 && bof.HalfSet == 70 && !bof.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 70;
                playerAddAgiStrInt(6);
            }

            if (bof.Boots == 80 && bof.Short == 80 && bof.Gloves == 80 && !bof.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 80;
                playerAddAgiStrInt(7);
            }

            if (bof.Helmet == 80 && bof.Chest == 80 && bof.HalfSet == 80 && !bof.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 80;
                playerAddAgiStrInt(7);
            }

            if (bof.Boots == 90 && bof.Short == 90 && bof.Gloves == 90 && !bof.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 90;
                playerAddAgiStrInt(8);
            }

            if (bof.Helmet == 90 && bof.Chest == 90 && bof.HalfSet == 90 && !bof.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 90;
                playerAddAgiStrInt(8);
            }

            if (bof.Boots >= 95 && bof.Short >= 95 && bof.Gloves >= 95 && !bof.HalfSet)
            {
                if (bof.Boots == bof.Short && bof.Short == bof.Gloves && bof.Boots == bof.Gloves)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = Grade;
                    playerAddAgiStrInt(9);
                }
            }

            if (bof.Helmet >= 95 && bof.Chest >= 95 && bof.HalfSet >= 95 && !bof.FullSet)
            {
                if (bof.Helmet == bof.Chest && bof.Helmet == bof.HalfSet && bof.Chest == bof.HalfSet)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = Grade;
                    playerAddAgiStrInt(9);
                }
            }
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
    } else {
        IPlayer.Buff(256, 2, 0);

        if (IItem.GetInfo() & 2097152)
        {
            int Grade = *(DWORD*)(*(DWORD*)((int)Item + 40) + 80);
            int Stat = 0;

            if (Grade >= 46 && Grade <= 49) {
                Stat = 1;
            }
            else if (Grade >= 50 && Grade <= 53) {
                Stat = 2;
            }
            else if (Grade >= 55 && Grade <= 58) {
                Stat = 3;
            }
            else if (Grade >= 60 && Grade <= 63) {
                Stat = 4;
            }
            else if (Grade >= 65 && Grade <= 68) {
                Stat = 5;
            }
            else if (Grade >= 70 && Grade <= 73) {
                Stat = 6;
            }
            else if (Grade >= 80 && Grade <= 83) {
                Stat = 7;
            }
            else if (Grade >= 90 && Grade <= 93) {
                Stat = 8;
            }
            else if (Grade >= 95) {
                Stat = 9;
            }

            IPlayer.RemoveAgi(Stat);
            IPlayer.RemoveStr(Stat);
            IPlayer.RemoveInt(Stat);

            if (IItem.GetType() == 2) {
                BeadOfFire[IPlayer.GetPID()].Helmet = 0;
            }
            else if (IItem.GetType() == 3) {
                BeadOfFire[IPlayer.GetPID()].Chest = 0;
            }
            else if (IItem.GetType() == 4) {
                BeadOfFire[IPlayer.GetPID()].Short = 0;
            }
            else if (IItem.GetType() == 5) {
                BeadOfFire[IPlayer.GetPID()].Gloves = 0;
            }
            else if (IItem.GetType() == 6) {
                BeadOfFire[IPlayer.GetPID()].Boots = 0;
            }


            if (BeadOfFire.count(IPlayer.GetPID())) {

                CheckBof bof = BeadOfFire.find(IPlayer.GetPID())->second;

                if (bof.HalfSet == 46 && (bof.Boots != 46 || bof.Short != 46 || bof.Gloves != 46))
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(1);
                    IPlayer.RemoveStr(1);
                    IPlayer.RemoveInt(1);
                }

                if (bof.FullSet == 46 && (bof.HalfSet != 46 || bof.Chest != 46 || bof.Helmet != 46))
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(1);
                    IPlayer.RemoveStr(1);
                    IPlayer.RemoveInt(1);
                }

                if (bof.HalfSet == 50 && (bof.Boots != 50 || bof.Short != 50 || bof.Gloves != 50))
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(2);
                    IPlayer.RemoveStr(2);
                    IPlayer.RemoveInt(2);
                }

                if (bof.FullSet == 50 && (bof.HalfSet != 50 || bof.Chest != 50 || bof.Helmet != 50))
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(2);
                    IPlayer.RemoveStr(2);
                    IPlayer.RemoveInt(2);
                }

                if (bof.HalfSet == 55 || bof.Boots != 55 || bof.Short != 55 || bof.Gloves != 55)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(3);
                    IPlayer.RemoveStr(3);
                    IPlayer.RemoveInt(3);
                }

                if (bof.FullSet == 55 && (bof.HalfSet != 55 || bof.Chest != 55 || bof.Helmet != 55))
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(3);
                    IPlayer.RemoveStr(3);
                    IPlayer.RemoveInt(3);
                }

               if (bof.HalfSet == 60 && (bof.Boots != 60 || bof.Short != 60 || bof.Gloves != 60))
               {
                   BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                   IPlayer.RemoveAgi(4);
                   IPlayer.RemoveStr(4);
                   IPlayer.RemoveInt(4);
               }

               if (bof.FullSet == 60 && (bof.HalfSet != 60 || bof.Chest != 60 || bof.Helmet != 60))
               {
                   BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                   IPlayer.RemoveAgi(4);
                   IPlayer.RemoveStr(4);
                   IPlayer.RemoveInt(4);
               }

               if (bof.HalfSet == 65 && (bof.Boots != 65 || bof.Short != 65 || bof.Gloves != 65))
               {
                   BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                   IPlayer.RemoveAgi(5);
                   IPlayer.RemoveStr(5);
                   IPlayer.RemoveInt(5);
               }

               if (bof.FullSet == 65 && (bof.HalfSet != 65 || bof.Chest != 65 || bof.Helmet != 65))
               {
                   BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                   IPlayer.RemoveAgi(5);
                   IPlayer.RemoveStr(5);
                   IPlayer.RemoveInt(5);
               }

               if (bof.HalfSet == 70 && (bof.Boots != 70 || bof.Short != 70 || bof.Gloves != 70))
               {
                   BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                   IPlayer.RemoveAgi(6);
                   IPlayer.RemoveStr(6);
                   IPlayer.RemoveInt(6);
               }

               if (bof.FullSet == 70 && (bof.HalfSet != 70 || bof.Chest != 70 || bof.Helmet != 70))
               {
                   BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                   IPlayer.RemoveAgi(6);
                   IPlayer.RemoveStr(6);
                   IPlayer.RemoveInt(6);
               }

               if (bof.HalfSet == 80 && (bof.Boots != 80 || bof.Short != 80 || bof.Gloves != 80))
               {
                   BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                   IPlayer.RemoveAgi(7);
                   IPlayer.RemoveStr(7);
                   IPlayer.RemoveInt(7);
               }

               if (bof.FullSet == 80 && (bof.HalfSet != 80 || bof.Chest != 80 || bof.Helmet != 80))
               {
                   BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                   IPlayer.RemoveAgi(7);
                   IPlayer.RemoveStr(7);
                   IPlayer.RemoveInt(7);
               }

               if (bof.HalfSet == 90 && (bof.Boots != 90 || bof.Short != 90 || bof.Gloves != 90))
               {
                   BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                   IPlayer.RemoveAgi(8);
                   IPlayer.RemoveStr(8);
                   IPlayer.RemoveInt(8);
               }

               if (bof.FullSet == 90 && (bof.HalfSet != 90 || bof.Chest != 90 || bof.Helmet != 90))
               {
                   BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                   IPlayer.RemoveAgi(8);
                   IPlayer.RemoveStr(8);
                   IPlayer.RemoveInt(8);
               }

               if (bof.HalfSet >= 95 && (bof.Boots < 95 || bof.Short < 95 || bof.Gloves < 95))
               {
                   BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                   IPlayer.RemoveAgi(9);
                   IPlayer.RemoveStr(9);
                   IPlayer.RemoveInt(9);
               }

               if (bof.FullSet >= 95 && (bof.HalfSet < 95 || bof.Chest < 95 || bof.Helmet < 95))
               {
                   BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                   IPlayer.RemoveAgi(9);
                   IPlayer.RemoveStr(9);
                   IPlayer.RemoveInt(9);
               }
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
}
