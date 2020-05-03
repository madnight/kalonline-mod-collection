void MemoryCopy(void *Destination, void *Source, size_t Size)
{
    unsigned long p1, p2;
    VirtualProtect(Destination, Size, PAGE_EXECUTE_READWRITE, &p1);
    VirtualProtect(Source, Size, PAGE_EXECUTE_READWRITE, &p2);
    CopyMemory(Destination, Source, Size);
    VirtualProtect(Destination, Size, p1, &p1);
    VirtualProtect(Source, Size, p1, &p2);
}

static unsigned __int64 _ExpTable[] = {
    0, 5, 24, 60, 80, 164, 271, 407, 579, 794, 1125, 1543, 2068, 2722,
    3534, 4563, 5830, 7385, 9286, 11607, 17493, 21845, 27147, 33593, 41416,
    51341, 63394, 78005, 95696, 117090, 166758, 203151, 247043, 299942, 363659,
    440404, 532757, 643849, 777437, 938032, 1211834, 1460324, 1758856, 2117449,
    2548126, 3065315, 3686331, 4431950, 5327106, 6401717, 10255633, 12320243,
    14798389, 17772795, 21342730, 25627317, 30769501, 36940820, 44347118, 53235407,
    63902104, 76702906, 92064653, 110499551, 132622249, 159170373, 191028978, 229260177,
    275138508, 330193415, 396260232, 1188853398, 1426699190, 1712116603, 2054620005,
    2465626643, 2958837208, 3550692535, 4260921625, 5113199283, 12271870776, 14726443120,
    17671935710, 21206532706, 31810068850, 38172360013, 45807117133, 54968833525, 65962901170,
    94986948540, 113984718984, 136782053544, 164138865195, 196967049519, 315147841592, 378177986472,
    453814174732, 544577615260, 653493758732, 980241432400, 1029253504020, 1080716179221, 1134751988182,
    1191489587591, 1251064066970, 1313617270318, 1379298133833, 1448263040524,
    1448263040524, 1520676192550, 1596710002177, 1676545502285, 1760372777399,
    1848391416268, 1940810987081, 2037851536435, 2139744113256, 2246731318918,
    2359067884863, 2477021279106, 2600872343061, 2730915960214, 2867461758224,
    3010834846135, 3161376588441, 3319445417863, 3485417688756, 3659688573193,
    3842673001852, 4034806651944, 4236546984541, 4448374333768, 4670793050456,
    4904332702978, 5149549338126, 5407026805032, 5677378145283, 5961247052547,
    6259309405174, 6572274875432, 6900888619203, 7245933050163, 7608229702671,
    7988641187804, 8388073247194, 8807476909553, 9247850755030, 9710243292781,
    10195755457420, 10705543230291, 11240820391805, 11802861411395, 12393004481964,
    13012654706062, 13663287441365, 13936553190192, 14215284253995, 14499589939074,
    14789581737855, 15085373372612, 15387080840064, 15694822456865, 16008718906002,
    16328893284122, 16655471149804, 16988580572800, 17328352184256, 17674919227941,
    18028417612499, 18388985964748, 18756765684042, 19131900997722, 19514539017676,
    19904829798029, 20302926393989, 20708984921868, 21123164620305, 21545627912711,
    21976540470965, 22416071280384, 22864392705991, 23321680560110, 23788114171312,
    24263876454738, 24749153983832, 25244137063508, 25749019804778, 26264000200873,
    26789280204890, 27325065808987, 27871567125166, 28428998467669, 28997578437022,
    29577530005762, 30169080605877, 30772462217994, 31387911462353, 32015669691600,
    32655983085432, 33309102747140, 33975284802082, 34654790498123, 35347886308085,
    36054844034246, 36775940914930, 37511459733228, 38261688927892, 39026922706449,
    39807461160577, 40603610383788, 41415682591463, 42243996243292, 43088876168157,
    43950653691520, 44829666765350, 45726260100657, 46640785302670, 47573601008723,
    48525073028897, 49495574489474, 50485485979263, 51495195698848, 52525099612824,
    53575601605080, 54647113637181, 55740055909924, 56854857028122, 57991954168684,
    59151793252057, 60334829117098, 61541525699439, 62772356213427, 64027803337695,
    65308359404448, 66614526592536, 67946817124386, 69305753466873, 70691868536210,
    72105705906934, 73547820025072, 75018776425573, 76519151954084, 78049534993165,
    79610525693028, 81202736206888, 82826790931025, 84483326749645, 86172993284637,
    87896453150329, 89654382213335, 91447469857601, 93276419254753, 95141947639848,
    97044786592644, 106749265251908,
};

void SwitchTable()
{
    DWORD* ExpPtr = (DWORD*)_ExpTable;
    DWORD Exptr2;
    DWORD ExpAdr1[] = {0x004592A6, 0x004592BE, 0x0046337A, 0x0046440F, 0x00415649, 0x0041566F, 0x004156B8, 0x00415737};
    DWORD ExpAdr2[] = {0x00459289, 0x004592CB, 0x00463387, 0x00464407, 0x00415650, 0x00415667, 0x004156B0, 0x0041572F};

    for (int i = 0; i < sizeof(ExpAdr1) / 4; i++) {
        MemoryCopy((void*)ExpAdr1[i], (void*) &ExpPtr, 4);
    }

    MemoryCopy((void*)&Exptr2, (void*)0x00415737, 4);
    Exptr2 += 0x04;

    for (int i = 0; i < sizeof(ExpAdr2) / 4; i++) {
        MemoryCopy((void*)ExpAdr2[i], (void*) &Exptr2, 4);
    }
}

int __cdecl MyUpdateProperty(int Player, int Type, int InOut,
    signed __int64 Exp)
{
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline() && Type == 8 && InOut == 1 && IPlayer.GetClass() == 4)
    {
        int pSkill = IPlayer.GetSkillPointer(16);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int Increase = 4 * xSkill.GetGrade();
            Exp += Increase;
        }
    }

    if (Type == 25 && IPlayer.IsOnline() && InOut)
    {
        if (IPlayer.IsBuff(258)) {
            Exp += (Exp / 5);
        }

        if (IPlayer.IsBuff(120)) {
            Exp += (Exp / 10);
        }

        if (IPlayer.IsBuff(298) && Exp > 100) {
            Exp += (Exp / 100);
        }

        if (LevelGap.count(IPlayer.GetLevel())
            && LevelGap.find(IPlayer.GetLevel())->second > 0 && Exp > 100) {
            Exp = (Exp * LevelGap.find(IPlayer.GetLevel())->second) / 100;
        }
    }

    return CPlayer::UpdateProperty(Player, Type, InOut, Exp);
}

void __cdecl MyStatStr(int Player, unsigned char Packet, char *Format,
    unsigned char Type, unsigned short Str, unsigned short Otp,
    unsigned short MinAtk, unsigned short MaxAtk)
{
    IChar IPlayer((void*)Player);
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwwww", 0, IPlayer.GetStr(),
        CChar::GetHit(Player), CChar::GetMinAttack(Player),
        CChar::GetMaxAttack(Player));
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwwww", 43,
        (CChar::GetStr(Player) - IPlayer.GetStr()), CChar::GetHit(Player),
        CChar::GetMinAttack(Player), CChar::GetMaxAttack(Player));
}

void __cdecl MyStatHth(int Player, unsigned char Packet, char *Format,
    unsigned char Type, unsigned short Str, unsigned short Otp,
    unsigned short MinAtk, unsigned short MaxAtk)
{
    IChar IPlayer((void*)Player);
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwddw", 1, IPlayer.GetHth(),
        IPlayer.GetCurHp(), CChar::GetMaxHP(Player),
        CChar::GetResist(IPlayer.GetOffset(), 4));
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwddw", 44,
        (CChar::GetHth(Player) - IPlayer.GetHth()), IPlayer.GetCurHp(),
        CChar::GetMaxHP(Player), CChar::GetResist(IPlayer.GetOffset(), 4));
}

void __cdecl MyStatInt(int Player, unsigned char Packet, char* Format,
    unsigned char statType, unsigned short points, unsigned short curWisdom,
    unsigned short maxWisdom, unsigned short curse)
{
    IChar IPlayer((void*)Player);
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwwwwww", 2, IPlayer.GetInt(),
        CChar::GetMinMagic(Player), CChar::GetMaxMagic(Player),
        CChar::GetResist(IPlayer.GetOffset(), 0), CChar::GetResist(IPlayer.GetOffset(),
            1), CChar::GetResist(IPlayer.GetOffset(), 2));
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwwwwww", 45,
        (CChar::GetInt(Player) - IPlayer.GetInt()), CChar::GetMinMagic(Player),
        CChar::GetMaxMagic(Player), CChar::GetResist(IPlayer.GetOffset(), 0),
        CChar::GetResist(IPlayer.GetOffset(), 1), CChar::GetResist(IPlayer.GetOffset(),
            2));
}

void __cdecl MyStatWis(int Player, unsigned char Packet, char* Format,
    unsigned char statType, unsigned short points, unsigned short curWisdom,
    unsigned short maxWisdom, unsigned short curse)
{
    IChar IPlayer((void*)Player);
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwwwwww", 3, IPlayer.GetWis(),
        IPlayer.GetCurMp(), CChar::GetMaxMp(Player), CChar::GetMinMagic(Player),
        CChar::GetMaxMagic(Player), CChar::GetResist(IPlayer.GetOffset(), 3));
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwwwwww", 46,
        (CChar::GetWis(Player) - IPlayer.GetWis()), IPlayer.GetCurMp(),
        CChar::GetMaxMp(Player), CChar::GetMinMagic(Player), CChar::GetMaxMagic(Player),
        CChar::GetResist(IPlayer.GetOffset(), 3));
}

void __cdecl MyStatAgi(int Player, unsigned char Type, char* format,
    unsigned char statType, unsigned short points, unsigned short otp,
    unsigned short evasion, unsigned short minAttack, unsigned short maxAttack)
{
    IChar IPlayer((void*)Player);
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwwwwww", 4, IPlayer.GetAgi(),
        CChar::GetHit(Player), CChar::GetDodge(Player), CChar::GetDodge(Player),
        CChar::GetMinAttack(Player), CChar::GetMaxAttack(Player));
    CPlayer::Write(IPlayer.GetOffset(), 69, "bwwwwww", 47,
        (CChar::GetDex(Player) - IPlayer.GetAgi()), CChar::GetHit(Player),
        CChar::GetDodge(Player), CChar::GetDodge(Player), CChar::GetMinAttack(Player),
        CChar::GetMaxAttack(Player));
}

void __cdecl MyStatCurHp1(int Player, unsigned char Type, char* format,
    unsigned char statType, unsigned short hp)
{
    IChar IPlayer((void*)Player);
    CPlayer::Write(IPlayer.GetOffset(), 69, "bd", 7, IPlayer.GetCurHp());
}

void __cdecl MyStatCurHp(int Player, unsigned char Type, char* format,
    unsigned char statType, unsigned short hp, unsigned short maxhp)
{
    IChar IPlayer((void*)Player);
    CPlayer::Write(IPlayer.GetOffset(), 69, "bdd", 5, IPlayer.GetCurHp(),
        CChar::GetMaxHP(Player));
}

int __fastcall IsNormal(int Player, void *edx)
{
    IChar IPlayer((void*)Player);

    if (IPlayer.IsValid())
    {
        if (IPlayer.GetClass() == 3)
        {
            if (IPlayer.IsBuff(329)) {
                return 0;
            }
        }

        if (IPlayer.GetClass() < 5 && CChar::IsGState((int)IPlayer.GetOffset(), 512))
        {
            if (IPlayer.IsBuff(327)) {
                return 0;
            }
        }
    }

    return CChar::IsNormal(Player);
}

int __fastcall IsStateCheck(int Item, void *edx, int Value)
{
    IItem IItem((void*)Item);

    if (IItem.CheckIndex() >= 3381 && IItem.CheckIndex() <= 3383
        && !CheckHaninMirror.find(*(DWORD*)(Item + 32))->second &&
        IItem.GetInfo() & 1) {
        CheckHaninMirror[*(DWORD*)(Item + 32)] = IItem.GetIID();
    }

    if (IItem.CheckIndex() >= 2986 && IItem.CheckIndex() <= 3009
        && IItem.GetInfo() & 1)
    {
        int GetGrade = (GetItemStat.find(IItem.GetIID())->second % 10000) / 100;

        if (TrigramGrade.count(*(DWORD*)(Item + 32))
            && GetGrade < TrigramGrade.find(*(DWORD*)(Item + 32))->second) {
            TrigramGrade[*(DWORD*)(Item + 32)] = GetGrade;
        }

        if (!TrigramGrade.count(*(DWORD*)(Item + 32))) {
            TrigramGrade[*(DWORD*)(Item + 32)] = GetGrade;
        }
    }

    if (IItem.CheckIndex() >= 2986 && IItem.CheckIndex() <= 3009
        && IItem.GetInfo() & 1)
    {
        int GetCurrentGrade = (GetItemStat.find(IItem.GetIID())->second % 10000) / 100;

        if (IItem.CheckIndex() == 2986)
            TrigramHP[*(DWORD*)(Item + 32)] =
                TriagramStats[0][GetCurrentGrade];

        if (IItem.CheckIndex() == 2994)
            TrigramHP[*(DWORD*)(Item + 32)] =
                TriagramStats[1][GetCurrentGrade];

        if (IItem.CheckIndex() == 3002)
            TrigramHP[*(DWORD*)(Item + 32)] =
                TriagramStats[2][GetCurrentGrade];

        if (IItem.CheckIndex() == 2987)
            TrigramMP[*(DWORD*)(Item + 32)] =
                TriagramStats[3][GetCurrentGrade];

        if (IItem.CheckIndex() == 2995)
            TrigramMP[*(DWORD*)(Item + 32)] =
                TriagramStats[4][GetCurrentGrade];

        if (IItem.CheckIndex() == 3003)
            TrigramMP[*(DWORD*)(Item + 32)] =
                TriagramStats[5][GetCurrentGrade];

        if (IItem.CheckIndex() == 2988)
            TrigramAtk[*(DWORD*)(Item + 32)] =
                TriagramStats[6][GetCurrentGrade];

        if (IItem.CheckIndex() == 2996)
            TrigramAtk[*(DWORD*)(Item + 32)] =
                TriagramStats[7][GetCurrentGrade];

        if (IItem.CheckIndex() == 3004)
            TrigramAtk[*(DWORD*)(Item + 32)] =
                TriagramStats[8][GetCurrentGrade];

        if (IItem.CheckIndex() == 2989)
            TrigramStr[*(DWORD*)(Item + 32)] =
                TriagramStats[9][GetCurrentGrade];

        if (IItem.CheckIndex() == 2997)
            TrigramStr[*(DWORD*)(Item + 32)] =
                TriagramStats[10][GetCurrentGrade];

        if (IItem.CheckIndex() == 3005)
            TrigramStr[*(DWORD*)(Item + 32)] =
                TriagramStats[11][GetCurrentGrade];

        if (IItem.CheckIndex() == 2990)
            TrigramAgi[*(DWORD*)(Item + 32)] =
                TriagramStats[12][GetCurrentGrade];

        if (IItem.CheckIndex() == 2998)
            TrigramAgi[*(DWORD*)(Item + 32)] =
                TriagramStats[13][GetCurrentGrade];

        if (IItem.CheckIndex() == 3006)
            TrigramAgi[*(DWORD*)(Item + 32)] =
                TriagramStats[14][GetCurrentGrade];

        if (IItem.CheckIndex() == 2991)
            TrigramInt[*(DWORD*)(Item + 32)] =
                TriagramStats[15][GetCurrentGrade];

        if (IItem.CheckIndex() == 2999)
            TrigramInt[*(DWORD*)(Item + 32)] =
                TriagramStats[16][GetCurrentGrade];

        if (IItem.CheckIndex() == 3007)
            TrigramInt[*(DWORD*)(Item + 32)] =
                TriagramStats[17][GetCurrentGrade];

        if (IItem.CheckIndex() == 2992)
            TrigramWis[*(DWORD*)(Item + 32)] =
                TriagramStats[18][GetCurrentGrade];

        if (IItem.CheckIndex() == 3000)
            TrigramWis[*(DWORD*)(Item + 32)] =
                TriagramStats[19][GetCurrentGrade];

        if (IItem.CheckIndex() == 3008)
            TrigramWis[*(DWORD*)(Item + 32)] =
                TriagramStats[20][GetCurrentGrade];

        if (IItem.CheckIndex() == 2993)
            TrigramHth[*(DWORD*)(Item + 32)] =
                TriagramStats[21][GetCurrentGrade];

        if (IItem.CheckIndex() == 3001)
            TrigramHth[*(DWORD*)(Item + 32)] =
                TriagramStats[22][GetCurrentGrade];

        if (IItem.CheckIndex() == 3009)
            TrigramHth[*(DWORD*)(Item + 32)] =
                TriagramStats[23][GetCurrentGrade];
    }

    if (IItem.CheckIndex() >= 3018 && IItem.CheckIndex() <= 3020
        && IItem.GetInfo() & 1)
    {
        int GetTaegeukPrefix = GetItemStat.find(IItem.GetIID())->second / 1000;

        if (GetTaegeukPrefix) {
            Taegeuk[*(DWORD*)(Item + 32)] = GetTaegeukPrefix;
        }
    }

    if (PetTime.count(IItem.CheckIndex()) || (IItem.CheckIndex() >= 1747
            && IItem.CheckIndex() <= 1762) || (IItem.CheckIndex() >= 1870
            && IItem.CheckIndex() <= 1877) || (IItem.CheckIndex() >= 2004
            && IItem.CheckIndex() <= 2007) || (IItem.CheckIndex() >= 2421
            && IItem.CheckIndex() <= 2423) || (IItem.CheckIndex() >= 2550
            && IItem.CheckIndex() <= 2653) || (IItem.CheckIndex() >= 6045
            && IItem.CheckIndex() <= 6052)) {
        CDBSocket::Write(85, "d", IItem.GetIID());
    }

    if (IItem.GetInfo() & 4194304) {
        CDBSocket::Write(85, "d", IItem.GetIID());
    }

    return CItem::IsState(Item, Value);
}

int __cdecl OpenPortalFix(int Player)
{
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(349))
    {
        IPlayer.SystemMessage("You can not use portal while riding.", TEXTCOLOR_RED);
        return 0;
    }

    return CPortal::OpenPortal(Player);
}

int __fastcall MyForPortalCheck(void *Value, void *edx, int Player)
{
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline() && (*(DWORD*)((int)Value + 4) & 65536))
    {
        CChar::Unlock(IPlayer.GetOffset());
        IPlayer.Buff(331, 3, 0);
        CChar::Lock(IPlayer.GetOffset());
    }

    return Undefined::ForPortalCheck(Value, Player);
}

int __fastcall RidingFix(void *Argument, void *edx)
{
    int Check = Undefined::GetValue(Argument);
    int Itemx = *(DWORD*)(Check + 4);
    IItem Item((void*)Itemx);
    int Player = CPlayer::ScanPlayer(*(DWORD*)(Itemx + 32));

    if (Player)
    {
        IChar IPlayer((void*)Player);

        if (IPlayer.IsOnline())
        {
            if (IPlayer.IsOnline() && ((Item.CheckIndex() >= 3412
                        && Item.CheckIndex() <= 3419) || (Item.CheckIndex() >= 4149
                        && Item.CheckIndex() <= 4153) || (Item.CheckIndex() >= 4156
                        && Item.CheckIndex() <= 4160) || (Item.CheckIndex() >= 6021
                        && Item.CheckIndex() <= 6024)) &&
                CChar::IsGState((int)IPlayer.GetOffset(), 4)) {
                return Check;
            }

            if (IPlayer.IsOnline() && ((Item.CheckIndex() >= 3412
                        && Item.CheckIndex() <= 3419) || (Item.CheckIndex() >= 4149
                        && Item.CheckIndex() <= 4153) || (Item.CheckIndex() >= 4156
                        && Item.CheckIndex() <= 4160) || (Item.CheckIndex() >= 6021
                        && Item.CheckIndex() <= 6024)) &&
                CChar::IsGState((int)IPlayer.GetOffset(), 512)) {
                return Check;
            }

            if (IPlayer.IsOnline() && ((Item.CheckIndex() >= 3412
                        && Item.CheckIndex() <= 3419) || (Item.CheckIndex() >= 4149
                        && Item.CheckIndex() <= 4153) || (Item.CheckIndex() >= 4156
                        && Item.CheckIndex() <= 4160) || (Item.CheckIndex() >= 6021
                        && Item.CheckIndex() <= 6024)) && (IPlayer.IsBuff(18) || IPlayer.IsBuff(19)
                    || IPlayer.IsBuff(313) || IPlayer.IsBuff(329))) {
                return Check;
            }

            if (IPlayer.IsOnline() && ((Item.CheckIndex() >= 3412
                        && Item.CheckIndex() <= 3419) || (Item.CheckIndex() >= 4149
                        && Item.CheckIndex() <= 4153) || (Item.CheckIndex() >= 4156
                        && Item.CheckIndex() <= 4160) || (Item.CheckIndex() >= 6021
                        && Item.CheckIndex() <= 6024)) && !IPlayer.IsBuff(349))
            {
                if (IPlayer.IsValid())
                {
                    IPlayer.Buff(313, 3, 0);
                    IPlayer.Buff(Item.CheckIndex(), 1296000, 0);

                    if (Item.CheckIndex() >= 3412
                        && Item.CheckIndex() <= 3419) {
                        IPlayer.EnableRiding(Item.CheckIndex() - 3411);
                    }

                    if (Item.CheckIndex() == 4149) {
                        IPlayer.EnableRiding(9);
                    }

                    if (Item.CheckIndex() == 4150) {
                        IPlayer.EnableRiding(10);
                    }

                    if (Item.CheckIndex() == 4151) {
                        IPlayer.EnableRiding(11);
                    }

                    if (Item.CheckIndex() == 4152) {
                        IPlayer.EnableRiding(14);
                    }

                    if (Item.CheckIndex() == 4153) {
                        IPlayer.EnableRiding(15);
                    }

                    if (Item.CheckIndex() == 4156) {
                        IPlayer.EnableRiding(12);
                    }

                    if (Item.CheckIndex() == 4157) {
                        IPlayer.EnableRiding(13);
                    }

                    if (Item.CheckIndex() == 4158) {
                        IPlayer.EnableRiding(16);
                    }

                    if (Item.CheckIndex() == 4159) {
                        IPlayer.EnableRiding(17);
                    }

                    if (Item.CheckIndex() == 4160) {
                        IPlayer.EnableRiding(18);
                    }

                    if (Item.CheckIndex() == 6022) {
                        IPlayer.EnableRiding(20);
                    }

                    if (Item.CheckIndex() == 6021) {
                        IPlayer.EnableRiding(21);
                    }

                    if (Item.CheckIndex() == 6023) {
                        IPlayer.EnableRiding(22);
                    }

                    if (Item.CheckIndex() == 6024) {
                        IPlayer.EnableRiding(23);
                    }
                }

                return Check;
            }

            if (IPlayer.IsOnline() && ((Item.CheckIndex() >= 3412
                        && Item.CheckIndex() <= 3419) || (Item.CheckIndex() >= 4149
                        && Item.CheckIndex() <= 4153) || (Item.CheckIndex() >= 4156
                        && Item.CheckIndex() <= 4160) || (Item.CheckIndex() >= 6021
                        && Item.CheckIndex() <= 6024)) && IPlayer.IsBuff(349))
            {
                IPlayer.Buff(313, 3, 0);
                IPlayer.DisableRiding();
                return Check;
            }
        }
    }

    return Check;
}

int __fastcall MyInventoryCheck(int Player, void *edx)
{
    IChar IPlayer((void*)Player);
    int Size = CPlayer::GetInvenSize(Player);

    if (Size >= 60) {
        Size -= 12;
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(172) && IPlayer.IsBuff(173)
        && IPlayer.IsBuff(174)) {
        Size -= 108;
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(172) && IPlayer.IsBuff(173)
        && IPlayer.IsBuff(174)) {
        Size -= 72;
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(172) && !IPlayer.IsBuff(173)
        && IPlayer.IsBuff(174)) {
        Size -= 36;
    }

    if (Size < 0) {
        Size = 0;
    }

    return Size;
}

int __fastcall MirrorFix(int Player, void *edx, int Type)
{
    if (Type == -3 || Type == -97 || Type == -98 || Type == -99 || Type == -100
        || Type == -101) {
        return 0;
    }

    return CPlayer::IsWState(Player, Type);
}

void ExpMultiplier()
{
    Interface<IMemory> Memory;
    Interface<ITools> Tools;
    int EggGradeLimit = 100;
    int ItemTimer = 1000;
    Memory->Copy((void*)0x0042670F, &ItemTimer, 4);
    Memory->Copy((void*)0x0042F212, &EggGradeLimit, 1);
    Memory->Hook(0x0042C7DD, MirrorFix);
    Memory->Hook(0x00455FC9, MyInventoryCheck);
    Memory->Hook(0x004560DA, MyInventoryCheck);
    Memory->Hook(0x0045DE7D, MyInventoryCheck);
    Memory->Hook(0x0045E4CC, MyInventoryCheck);
    Memory->Hook(0x0045EEFE, MyInventoryCheck);
    Memory->Hook(0x0045F6CB, MyInventoryCheck);
    Memory->Hook(0x00464FD3, MyInventoryCheck);
    Memory->Hook(0x00469752, MyInventoryCheck);
    Memory->Hook(0x0043D0A5, IsNormal, 0xe8, 5);
    Memory->Hook(0x0043E95C, IsNormal, 0xe8, 5);
    Memory->Hook(0x0043F525, IsNormal, 0xe8, 5);
    Memory->Hook(0x0043F925, IsNormal, 0xe8, 5);
    Memory->Hook(0x00440599, IsNormal, 0xe8, 5);
    Memory->Hook(0x0044109D, IsNormal, 0xe8, 5);
    Memory->Hook(0x00441B5B, IsNormal, 0xe8, 5);
    Memory->Hook(0x00442774, IsNormal, 0xe8, 5);
    Memory->Hook(0x00444A59, IsNormal, 0xe8, 5);
    Memory->Hook(0x004453F9, IsNormal, 0xe8, 5);
    Memory->Hook(0x00445839, IsNormal, 0xe8, 5);
    Memory->Hook(0x00490C78, IsNormal, 0xe8, 5);
    Memory->Hook(0x00457127, IsStateCheck, 0xe8, 5);
    Memory->Hook(0x004923DF, OpenPortalFix, 0xe8, 5);
    Memory->Set(0x004B92E0, "ddddb", 6);
    Memory->Hook(0x00458965, MyStatStr);
    Memory->Hook(0x00459A8E, MyStatStr);
    Memory->Hook(0x0045B361, MyStatStr);
    Memory->Hook(0x00458AA7, MyStatHth);
    Memory->Hook(0x00459CA8, MyStatHth);
    Memory->Hook(0x0045B587, MyStatHth);
    Memory->Hook(0x00458C81, MyStatInt);
    Memory->Hook(0x00459FDF, MyStatInt);
    Memory->Hook(0x0045B8CA, MyStatInt);
    Memory->Hook(0x00458E05, MyStatWis);
    Memory->Hook(0x0045A301, MyStatWis);
    Memory->Hook(0x0045BBf8, MyStatWis);
    Memory->Hook(0x00458F6E, MyStatAgi);
    Memory->Hook(0x0045A56F, MyStatAgi);
    Memory->Hook(0x0045BE72, MyStatAgi);
    Memory->Hook(0x0045903B, MyStatCurHp1);
    Memory->Hook(0x00459556, MyStatCurHp);
    Memory->Hook(0x0045A61C, MyStatCurHp);
    Memory->Hook(0x0045BF2B, MyStatCurHp);
    Memory->Hook(0x004917A0, MyForPortalCheck, 0xe8, 5);
    Memory->Hook(0x0045DD79, RidingFix, 0xe8, 5);
    Tools->FillMemoryEx(0x0046BC20, ITools::_I_NOP, 5);
}
