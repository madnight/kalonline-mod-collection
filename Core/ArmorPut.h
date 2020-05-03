int getItemStat(int x, int y) {
    return (GetItemStat.find(IItem.GetIID())->second % x) / y;
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

        switch (IItem.GetSetGem()) {
            case 240:
                IPlayer.AddDef((check * 18) / 100);
                IPlayer.AddAgi(7);
            case 239:
                IPlayer.AddDef((check * 18) / 100);
                IPlayer.AddWis(7);
            case 238:
                IPlayer.AddDef((check * 18) / 100);
                IPlayer.AddInt(7);
            case 237:
                IPlayer.AddDef((check * 18) / 100);
                IPlayer.AddHp(7);
            case 236:
                IPlayer.AddDef((check * 18) / 100);
                IPlayer.AddStr(7);
            case 235:
                IPlayer.AddDef((check * 16) / 100);
                IPlayer.AddAgi(5);
            case 234:
                IPlayer.AddDef((check * 16) / 100);
                IPlayer.AddWis(5);
            case 233:
                IPlayer.AddDef((check * 16) / 100);
                IPlayer.AddInt(5);
            case 232:
                IPlayer.AddDef((check * 16) / 100);
                IPlayer.AddHp(5);
            case 231:
                IPlayer.AddDef((check * 16) / 100);
                IPlayer.AddStr(5);
            case 230:
                IPlayer.AddDef((check * 14) / 100);
                IPlayer.AddAgi(3);
            case 229:
                IPlayer.AddDef((check * 14) / 100);
                IPlayer.AddWis(3);
            case 228:
                IPlayer.AddDef((check * 14) / 100);
                IPlayer.AddInt(3);
            case 227:
                IPlayer.AddDef((check * 14) / 100);
                IPlayer.AddHp(3);
            case 226:
                IPlayer.AddDef((check * 14) / 100);
                IPlayer.AddStr(3);
            case 225:
                IPlayer.AddDef((check * 12) / 100);
                IPlayer.AddAgi(3);
            case 224:
                IPlayer.AddDef((check * 12) / 100);
                IPlayer.AddWis(3);
            case 223:
                IPlayer.AddDef((check * 12) / 100);
                IPlayer.AddInt(3);
            case 222:
                IPlayer.AddDef((check * 12) / 100);
                IPlayer.AddHp(3);
            case 221:
                IPlayer.AddDef((check * 12) / 100);
                IPlayer.AddStr(3);
            case 220:
                IPlayer.AddDef((check * 10) / 100);
                IPlayer.AddAgi(2);
            case 219:
                IPlayer.AddDef((check * 10) / 100);
                IPlayer.AddWis(2);
            case 218:
                IPlayer.AddDef((check * 10) / 100);
                IPlayer.AddInt(2);
            case 217:
                IPlayer.AddDef((check * 10) / 100);
                IPlayer.AddHp(2);
            case 216:
                IPlayer.AddDef((check * 10) / 100);
                IPlayer.AddStr(2);
            case 215:
                IPlayer.AddDef((check * 8) / 100);
                IPlayer.AddAgi(2);
            case 214:
                IPlayer.AddDef((check * 8) / 100);
                IPlayer.AddWis(2);
            case 213:
                IPlayer.AddDef((check * 8) / 100);
                IPlayer.AddInt(2);
            case 212:
                IPlayer.AddDef((check * 8) / 100);
                IPlayer.AddHp(2);
            case 211:
                IPlayer.AddDef((check * 8) / 100);
                IPlayer.AddStr(2);
            case 210:
                IPlayer.AddDef((check * 6) / 100);
                IPlayer.AddAgi(1);
            case 209:
                IPlayer.AddDef((check * 6) / 100);
                IPlayer.AddWis(1);
            case 208:
                IPlayer.AddDef((check * 6) / 100);
                IPlayer.AddInt(1);
            case 207:
                IPlayer.AddDef((check * 6) / 100);
                IPlayer.AddHp(1);
            case 206:
                IPlayer.AddDef((check * 6) / 100);
                IPlayer.AddStr(1);
            case 205:
                IPlayer.AddDef((check * 4) / 100);
                IPlayer.AddAgi(1);
            case 204:
                IPlayer.AddDef((check * 4) / 100);
                IPlayer.AddWis(1);
            case 203:
                IPlayer.AddDef((check * 4) / 100);
                IPlayer.AddInt(1);
            case 202:
                IPlayer.AddDef((check * 4) / 100);
                IPlayer.AddHp(1);
            case 201:
                IPlayer.AddDef((check * 4) / 100);
                IPlayer.AddStr(1);
        }

        if (IItem.GetInfo() & 2097152)
        {
            int Grade = *(DWORD*)(*(DWORD*)(Item + 40) + 80);
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

            IPlayer.AddAgi(Stat);
            IPlayer.AddStr(Stat);
            IPlayer.AddInt(Stat);

            if (IItem.GetType() == 2) {
                BeadOfFire[IPlayer.GetPID()].Helmet = Grade;
            }
            else if (IItem.GetType() == 3) {
                BeadOfFire[IPlayer.GetPID()].Chest = Grade;
            }
            else if (IItem.GetType() == 4) {
                BeadOfFire[IPlayer.GetPID()].Short = Grade;
            }
            else if (IItem.GetType() == 5) {
                BeadOfFire[IPlayer.GetPID()].Gloves = Grade;
            }
            else if (IItem.GetType() == 6) {
                BeadOfFire[IPlayer.GetPID()].Boots = Grade;
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Boots == 46 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Short == 46 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Gloves == 46 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 46;
                IPlayer.AddAgi(1);
                IPlayer.AddStr(1);
                IPlayer.AddInt(1);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Helmet == 46 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Chest == 46 &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 46 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 46;
                IPlayer.AddAgi(1);
                IPlayer.AddStr(1);
                IPlayer.AddInt(1);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Boots == 50 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Short == 50 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Gloves == 50 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 50;
                IPlayer.AddAgi(2);
                IPlayer.AddStr(2);
                IPlayer.AddInt(2);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Helmet == 50 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Chest == 50 &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 50 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 50;
                IPlayer.AddAgi(2);
                IPlayer.AddStr(2);
                IPlayer.AddInt(2);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Boots == 55 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Short == 55 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Gloves == 55 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 55;
                IPlayer.AddAgi(3);
                IPlayer.AddStr(3);
                IPlayer.AddInt(3);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Helmet == 55 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Chest == 55 &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 55 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 55;
                IPlayer.AddAgi(3);
                IPlayer.AddStr(3);
                IPlayer.AddInt(3);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Boots == 60 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Short == 60 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Gloves == 60 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 60;
                IPlayer.AddAgi(4);
                IPlayer.AddStr(4);
                IPlayer.AddInt(4);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Helmet == 60 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Chest == 60 &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 60 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 60;
                IPlayer.AddAgi(4);
                IPlayer.AddStr(4);
                IPlayer.AddInt(4);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Boots == 65 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Short == 65 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Gloves == 65 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 65;
                IPlayer.AddAgi(5);
                IPlayer.AddStr(5);
                IPlayer.AddInt(5);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Helmet == 65 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Chest == 65 &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 65 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 65;
                IPlayer.AddAgi(5);
                IPlayer.AddStr(5);
                IPlayer.AddInt(5);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Boots == 70 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Short == 70 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Gloves == 70 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 70;
                IPlayer.AddAgi(6);
                IPlayer.AddStr(6);
                IPlayer.AddInt(6);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Helmet == 70 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Chest == 70 &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 70 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 70;
                IPlayer.AddAgi(6);
                IPlayer.AddStr(6);
                IPlayer.AddInt(6);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Boots == 80 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Short == 80 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Gloves == 80 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 80;
                IPlayer.AddAgi(7);
                IPlayer.AddStr(7);
                IPlayer.AddInt(7);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Helmet == 80 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Chest == 80 &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 80 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 80;
                IPlayer.AddAgi(7);
                IPlayer.AddStr(7);
                IPlayer.AddInt(7);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Boots == 90 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Short == 90 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Gloves == 90 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
            {
                BeadOfFire[IPlayer.GetPID()].HalfSet = 90;
                IPlayer.AddAgi(8);
                IPlayer.AddStr(8);
                IPlayer.AddInt(8);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Helmet == 90 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Chest == 90 &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 90 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.FullSet)
            {
                BeadOfFire[IPlayer.GetPID()].FullSet = 90;
                IPlayer.AddAgi(8);
                IPlayer.AddStr(8);
                IPlayer.AddInt(8);
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Boots >= 95 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Short >= 95 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Gloves >= 95 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots ==
                    BeadOfFire.find(IPlayer.GetPID())->second.Short &&
                    BeadOfFire.find(IPlayer.GetPID())->second.Short ==
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves &&
                    BeadOfFire.find(IPlayer.GetPID())->second.Boots ==
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = Grade;
                    IPlayer.AddAgi(9);
                    IPlayer.AddStr(9);
                    IPlayer.AddInt(9);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.Helmet >= 95 &&
                BeadOfFire.find(IPlayer.GetPID())->second.Chest >= 95 &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet >= 95 &&
                !BeadOfFire.find(IPlayer.GetPID())->second.FullSet)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Helmet ==
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest &&
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet ==
                    BeadOfFire.find(IPlayer.GetPID())->second.HalfSet &&
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest ==
                    BeadOfFire.find(IPlayer.GetPID())->second.HalfSet)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = Grade;
                    IPlayer.AddAgi(9);
                    IPlayer.AddStr(9);
                    IPlayer.AddInt(9);
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

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 46)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots != 46 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Short != 46 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves != 46)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(1);
                    IPlayer.RemoveStr(1);
                    IPlayer.RemoveInt(1);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 46)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.HalfSet != 46 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest != 46 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet != 46)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(1);
                    IPlayer.RemoveStr(1);
                    IPlayer.RemoveInt(1);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 50)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots != 50 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Short != 50 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves != 50)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(2);
                    IPlayer.RemoveStr(2);
                    IPlayer.RemoveInt(2);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 50)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.HalfSet != 50 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest != 50 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet != 50)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(2);
                    IPlayer.RemoveStr(2);
                    IPlayer.RemoveInt(2);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 55)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots != 55 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Short != 55 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves != 55)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(3);
                    IPlayer.RemoveStr(3);
                    IPlayer.RemoveInt(3);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 55)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.HalfSet != 55 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest != 55 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet != 55)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(3);
                    IPlayer.RemoveStr(3);
                    IPlayer.RemoveInt(3);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 60)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots != 60 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Short != 60 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves != 60)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(4);
                    IPlayer.RemoveStr(4);
                    IPlayer.RemoveInt(4);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 60)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.HalfSet != 60 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest != 60 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet != 60)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(4);
                    IPlayer.RemoveStr(4);
                    IPlayer.RemoveInt(4);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 65)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots != 65 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Short != 65 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves != 65)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(5);
                    IPlayer.RemoveStr(5);
                    IPlayer.RemoveInt(5);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 65)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.HalfSet != 65 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest != 65 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet != 65)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(5);
                    IPlayer.RemoveStr(5);
                    IPlayer.RemoveInt(5);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 70)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots != 70 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Short != 70 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves != 70)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(6);
                    IPlayer.RemoveStr(6);
                    IPlayer.RemoveInt(6);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 70)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.HalfSet != 70 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest != 70 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet != 70)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(6);
                    IPlayer.RemoveStr(6);
                    IPlayer.RemoveInt(6);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 80)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots != 80 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Short != 80 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves != 80)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(7);
                    IPlayer.RemoveStr(7);
                    IPlayer.RemoveInt(7);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 80)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.HalfSet != 80 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest != 80 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet != 80)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(7);
                    IPlayer.RemoveStr(7);
                    IPlayer.RemoveInt(7);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 90)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots != 90 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Short != 90 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves != 90)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(8);
                    IPlayer.RemoveStr(8);
                    IPlayer.RemoveInt(8);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 90)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.HalfSet != 90 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest != 90 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet != 90)
                {
                    BeadOfFire[IPlayer.GetPID()].FullSet = 0;
                    IPlayer.RemoveAgi(8);
                    IPlayer.RemoveStr(8);
                    IPlayer.RemoveInt(8);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.HalfSet >= 95)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.Boots < 95 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Short < 95 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Gloves < 95)
                {
                    BeadOfFire[IPlayer.GetPID()].HalfSet = 0;
                    IPlayer.RemoveAgi(9);
                    IPlayer.RemoveStr(9);
                    IPlayer.RemoveInt(9);
                }
            }

            if (BeadOfFire.count(IPlayer.GetPID()) &&
                BeadOfFire.find(IPlayer.GetPID())->second.FullSet >= 95)
            {
                if (BeadOfFire.find(IPlayer.GetPID())->second.HalfSet < 95 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Chest < 95 ||
                    BeadOfFire.find(IPlayer.GetPID())->second.Helmet < 95)
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
