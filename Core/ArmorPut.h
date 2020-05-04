int getItemStat(int x, int y, int item) {

    IItem IItem((void*)item);
    return (GetItemStat.find(IItem.GetIID())->second % x) / y;
}

void demonGongTypeApply(int type, int stat, int player, bool remove){

    IChar IPlayer((void*)player);
    int s = stat -1;
    if (remove) {
        switch (type)
        {
            case 1:
                IPlayer.RemoveDef(DemonGongStatArmorEarth[0][s]);
                IPlayer.RemoveOTP(DemonGongStatArmorEarth[1][s]);
            case 2:
                IPlayer.DecreaseMaxHp(DemonGongStatArmorWind[0][s]);
                IPlayer.RemoveEva(DemonGongStatArmorWind[1][s]);
            case 3:
                IPlayer.RemoveAgi(DemonGongStatArmorWater[0][s]);
                IPlayer.RemoveDef(DemonGongStatArmorWater[1][s]);
        }
    } else {
        switch (type)
        {
            case 1:
                IPlayer.AddDef(DemonGongStatArmorEarth[0][s]);
                IPlayer.AddOTP(DemonGongStatArmorEarth[1][s]);
            case 2:
                IPlayer.IncreaseMaxHp(DemonGongStatArmorWind[0][s]);
                IPlayer.AddEva(DemonGongStatArmorWind[1][s]);
            case 3:
                IPlayer.AddAgi(DemonGongStatArmorWater[0][s]);
                IPlayer.AddDef(DemonGongStatArmorWater[1][s]);
        }
    }
}


void qigongChestStats(int type, int attr, int player, bool remove) {

    IChar IPlayer((void*)player);
     if (remove) {
         switch (type) {
             case 0:
                 IPlayer.RemoveStr(attr);
             case 1:
                 IPlayer.RemoveHp(attr);
             case 2:
                 IPlayer.RemoveInt(attr);
             case 3:
                 IPlayer.RemoveWis(attr);
             case 4:
                 IPlayer.RemoveAgi(attr);
         }
     } else {
           switch (type) {
               case 0:
                   IPlayer.AddStr(attr);
               case 1:
                   IPlayer.AddHp(attr);
               case 2:
                   IPlayer.AddInt(attr);
               case 3:
                   IPlayer.AddWis(attr);
               case 4:
                   IPlayer.AddAgi(attr);
           }
     }

}

void playerAddStats(int x, int y, int z, int player, bool remove) {

    IChar IPlayer((void*)player);
    if (remove) {
        IPlayer.RemoveDef(z / 100);
        switch ( x % 5 ) {
            case 0:
                IPlayer.RemoveAgi(y);
            case 1:
                IPlayer.RemoveStr(y);
            case 2:
                IPlayer.RemoveHp(y);
            case 3:
                IPlayer.RemoveInt(y);
            case 4:
                IPlayer.RemoveWis(y);
        }
    } else {
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

void nItemGSTApply(int gst, int check, int player, bool remove) {

    if (gst >= 36 && gst <= 40) {
        playerAddStats(gst, 7, (check * 18), player, remove);
    }

    if (gst >= 31 && gst <= 35) {
        playerAddStats(gst, 5, (check * 16), player, remove);
    }

    if (gst >= 26 && gst <= 30) {
        playerAddStats(gst, 3, (check * 14), player, remove);
    }

    if (gst >= 21 && gst <= 25) {
        playerAddStats(gst, 3, (check * 12), player, remove);
    }

    if (gst >= 16 && gst <= 20) {
        playerAddStats(gst, 2, (check * 10), player, remove);
    }

    if (gst >= 11 && gst <= 15) {
        playerAddStats(gst, 2, (check * 8), player, remove);
    }

    if (gst >= 6 && gst <= 10) {
        playerAddStats(gst, 1, (check * 6), player, remove);
    }

    if (gst >= 1 && gst <= 5) {
        playerAddStats(gst, 1, (check * 4), player, remove);
    }
}

void __fastcall DefenseApplySpec(int Item, void *edx, int Player)
{
    IItem IItem((void*)Item);
    IChar IPlayer((void*)Player);

    if (!IPlayer.IsOnline())
    {
        return;
    }

    int def = IPlayer.GetDef();
    CItemDefense::ApplySpec(Item, Player);
    int check = IPlayer.GetDef() - (def + *((DWORD*)Item + 27));
    int FirstDemonGongType = 0, SecondDemonGongType = 0;
    int FirstDemonGongStat = 0, SecondDemonGongStat = 0;

    if (GetItemStat.count(IItem.GetIID()))
    {
        FirstDemonGongType = getItemStat(100000000, 10000000, Item);
        SecondDemonGongType = getItemStat(1000000, 100000, Item);
        FirstDemonGongStat = getItemStat(10000000, 1000000, Item);
        SecondDemonGongStat = getItemStat(100000, 10000, Item);
    }

    demonGongTypeApply(FirstDemonGongType, FirstDemonGongStat, Player, false);
    demonGongTypeApply(FirstDemonGongType, SecondDemonGongStat, Player, false);

    if (GetItemStat.find(IItem.GetIID())->second > 0)
    {
        int QigongType = GetItemStat.find(IItem.GetIID())->second % 100;

        if (QigongType)
        {
            switch (IItem.GetType()) {
                case 3:
                    IPlayer.AddDef((check * QigongChest[QigongType - 1][0]) / 100);
                case 4:
                    IPlayer.AddDef((check * QigongShort[QigongType - 1][0]) / 100);
                default:
                    IPlayer.AddDef((check * QigongMain[QigongType - 1][0]) / 100);

            }
            int Type = QigongChest[QigongType - 1][1];
            int Stat = QigongChest[QigongType - 1][2];
            qigongChestStats(Type, Stat, Player, false);
        }
    }

    int nItemGST = IItem.GetSetGem() - 200;
    nItemGSTApply(nItemGST, check, Player, false);

    if (IItem.GetInfo() & 2097152)
    {
        int Grade = *(DWORD*)(*(DWORD*)(Item + 40) + 80);
        int Stat = getStat(Grade);

        playerAddAgiStrInt(Stat, Player);

        setBeadOfFire(Grade, IItem.GetType(), Player)

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

    if (IPlayer.IsOnline() && IPlayer.IsBuff(120) && IItem.LevelLimit() > 5) {
        IItem.SetLevelLimit(IItem.LevelLimit() - 5);
    }

    CItemDefense::PutOn(Item, Player);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(120) && IItem.LevelLimit() > 5) {
        IItem.SetLevelLimit(IItem.LevelLimit() + 5);
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

        playerRemoveAgiStrInt(Stat, player);
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
        FirstDemonGongType = getItemStat(100000000, 10000000, Item);
        SecondDemonGongType = getItemStat(1000000, 100000, Item);
        FirstDemonGongStat = getItemStat(10000000, 1000000, Item);
        SecondDemonGongStat = getItemStat(100000, 10000, Item);
    }

    demonGongTypeApply(FirstDemonGongType, FirstDemonGongStat, Player, true);
    demonGongTypeApply(FirstDemonGongType, SecondDemonGongStat, Player, true);

    if (GetItemStat.find(IItem.GetIID())->second > 0)
    {
        int QigongType = GetItemStat.find(IItem.GetIID())->second % 100;

        if (QigongType)
        {
            switch (IItem.GetType()) {
                case 3:
                    IPlayer.RemoveDef((check * QigongChest[QigongType - 1][0]) / 100);
                case 4:
                    IPlayer.RemoveDef((check * QigongShort[QigongType - 1][0]) / 100);
                default:
                    IPlayer.RemoveDef((check * QigongMain[QigongType - 1][0]) / 100);

            }
            int Type = QigongChest[QigongType - 1][1];
            int Stat = QigongChest[QigongType - 1][2];
            qigongChestStats(Type, Stat, Player, true);
        }
    }

    int nItemGST = IItem.GetSetGem() - 200;
    nItemGSTApply(nItemGST, check, Player, true);
}
