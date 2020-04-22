signed int __stdcall MixItemCheck(int MainItem, int Weapon, int Armor)
{
    signed int result = 0;

    if (MainItem == Weapon || MainItem == Armor) {
        return 0;
    }

    if (Weapon == MainItem || Weapon == Armor) {
        return 0;
    }

    if (Armor == MainItem || Armor == Weapon) {
        return 0;
    }

    if (*(DWORD*)(*(DWORD*)(MainItem + 40) + 80) == 70
        || *(DWORD*)(*(DWORD*)(MainItem + 40) + 80) == 75
        || *(DWORD*)(*(DWORD*)(MainItem + 40) + 80) == 80
        || *(DWORD*)(*(DWORD*)(MainItem + 40) + 80) == 90)
    {
        switch (*(DWORD*)(*(DWORD*)(MainItem + 40) + 80))
        {
            case 70:
                if (*(DWORD*)(*(DWORD*)(Weapon + 40) + 80) != 62
                    || *(DWORD*)(*(DWORD*)(Armor + 40) + 80) != 55
                    || *(DWORD*)(*(DWORD*)(Armor + 40) + 72) != 5) {
                    result = 0;
                }
                else {
                    result = 1;
                }

                break;

            case 75:
                if (*(DWORD*)(*(DWORD*)(Weapon + 40) + 80) != 65
                    || *(DWORD*)(*(DWORD*)(Armor + 40) + 80) != 60
                    || *(DWORD*)(*(DWORD*)(Armor + 40) + 72) != 5) {
                    result = 0;
                }
                else {
                    result = 1;
                }

                break;

            case 80:
                if (*(DWORD*)(*(DWORD*)(Weapon + 40) + 80) != 70
                    || *(DWORD*)(*(DWORD*)(Armor + 40) + 80) != 65
                    || *(DWORD*)(*(DWORD*)(Armor + 40) + 72) != 5) {
                    result = 0;
                }
                else {
                    result = 1;
                }

                break;

            case 90:
                if (*(DWORD*)(*(DWORD*)(Weapon + 40) + 80) != 75
                    || *(DWORD*)(*(DWORD*)(Armor + 40) + 80) != 70
                    || *(DWORD*)(*(DWORD*)(Armor + 40) + 72) != 5) {
                    result = 0;
                }
                else {
                    result = 1;
                }

                break;
        }
    } else {
        result = CItem::MixItemCheck(MainItem, Weapon, Armor);
    }

    return result;
}

int __fastcall Imperial(void *pPlayer, void *edx, int MainItem, int Armor,
    int Stone, int Weapon, int NextStone)
{
    IChar IPlayer(pPlayer);

    if (!IPlayer.IsOnline()) {
        return 0;
    }

    if (MainItem == Armor || MainItem == Stone || MainItem == Weapon
        || MainItem == NextStone) {
        return 0;
    }

    if (Armor == MainItem || Armor == Stone || Armor == Weapon
        || Armor == NextStone) {
        return 0;
    }

    if (Stone == MainItem || Stone == Armor || Stone == Weapon
        || Stone == NextStone) {
        return 0;
    }

    if (Weapon == MainItem || Weapon == Armor || Weapon == Stone
        || Weapon == NextStone) {
        return 0;
    }

    if (NextStone == MainItem || NextStone == Armor || NextStone == Stone
        || NextStone == Weapon) {
        return 0;
    }

    CIOCriticalSection::Enter((struct _RTL_CRITICAL_SECTION *)((
                int)pPlayer + 1020));
    int MixCheck = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0,
        j = 0,
        k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, r = 0, s = 0, t = 0, u = 0, z = 0;
    *(DWORD*)&MixCheck = 0;
    bool success = false;

    if (!*(DWORD*)((int)pPlayer + 1096)
        || *(DWORD*)(*(DWORD*)((int)pPlayer + 1096) + 52) < 70000)
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
            (int)&a, (int)&MainItem);
    b = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&c);

    if (!Undefined::CheckValues(&MixCheck, b))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    d = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    IItem Itemd((void*)d);

    if (Itemd.CheckIndex() >= 769 && Itemd.CheckIndex() <= 801
        || Itemd.CheckIndex() >= 1433 && Itemd.CheckIndex() <= 1441
        || Itemd.CheckIndex() >= 1700 && Itemd.CheckIndex() <= 1704
        || Itemd.CheckIndex() >= 3033 && Itemd.CheckIndex() <= 3039
        || Itemd.CheckIndex() >= 1921 && Itemd.CheckIndex() <= 1927
        || Itemd.CheckIndex() >= 1821 && Itemd.CheckIndex() <= 1824
        || Itemd.CheckIndex() >= 1448 && Itemd.CheckIndex() <= 1453
        || Itemd.CheckIndex() >= 1442 && Itemd.CheckIndex() <= 1445
        || Itemd.CheckIndex() >= 2676 && Itemd.CheckIndex() <= 2682
        || Itemd.CheckIndex() >= 2688 && Itemd.CheckIndex() <= 2693
        || Itemd.CheckIndex() >= 2700 && Itemd.CheckIndex() <= 2705
        || Itemd.CheckIndex() >= 4329 && Itemd.CheckIndex() <= 4335
        || Itemd.CheckIndex() == 1853 || Itemd.CheckIndex() == 1669
        || Itemd.CheckIndex() == 1668)
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
            (int)&e, (int)&Armor);
    f = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&g);

    if (!Undefined::CheckValues(&MixCheck, f))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    h = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    IItem Itemh((void*)h);

    if (Itemh.CheckIndex() == 906)
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
            (int)&m, (int)&Weapon);
    n = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&o);

    if (!Undefined::CheckValues(&MixCheck, n))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    p = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    IItem Itemp((void*)p);

    MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
            (int)&i, (int)&Stone);
    j = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&k);

    if (!Undefined::CheckValues(&MixCheck, j))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    l = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    IItem Iteml((void*)l);

    MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
            (int)&r, (int)&NextStone);
    t = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&s);

    if (!Undefined::CheckValues(&MixCheck, t))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    u = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    IItem Itemu((void*)u);

    if (Itemd.GetIID() == Itemh.GetIID() || Itemd.GetIID() == Iteml.GetIID()
        || Itemh.GetIID() == Iteml.GetIID())
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    if (Itemu.GetIID() == Itemp.GetIID())
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    if (Itemu.CheckIndex() < 895 || Itemu.CheckIndex() > 905)
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    if (Itemp.CheckIndex() < 895 || Itemp.CheckIndex() > 905)
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    if (!MixItemCheck(d, h, l))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    switch (*(DWORD*)(*(DWORD*)(d + 40) + 80))
    {
        case 0x28:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x2D:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x30:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x32:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x35:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x38:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x3B:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x3E:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x41:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x46:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x4B:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x50:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;

        case 0x5A:
            if (CTools::Rate(0, 99) <= ConfigImp) {
                success = true;
            }

            break;
    }

    if (success == false)
    {
        if (!(*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                (**((DWORD**)pPlayer + 274) + 120))(*((DWORD *)pPlayer + 274),
                pPlayer, 9, -70000)) {
            CPlayer::_OutOfInven(IPlayer.GetOffset(), *((DWORD *)pPlayer + 274));
        }

        if (!CBase::IsDeleted(p)
            && Itemp.GetItemPointerFromIID(IPlayer.GetOffset(), Itemp.GetIID())) {
            CItem::RemoveItem(pPlayer, p);
        }

        if (!CBase::IsDeleted(u)
            && Itemu.GetItemPointerFromIID(IPlayer.GetOffset(), Itemu.GetIID())) {
            CItem::RemoveItem(pPlayer, u);
        }

        CPlayer::Write(pPlayer, 68, "bb", 138, 1);

        if (Itemd.GetEndurance() >= 5) {
            *(DWORD *)((int)Itemd.GetOffset() + 96) -= 5;
        }
        else
            *(DWORD *)((int)Itemd.GetOffset() + 96) -= *(DWORD *)((int)Itemd.GetOffset() +
                    96);

        if (Itemd.GetEndurance() > 0)
        {
            CPlayer::Write(pPlayer, 91, "db", Itemd.GetIID(), Itemd.GetEndurance());
            CDBSocket::Write(18, "ddb", Itemd.GetIID(), IPlayer.GetID(),
                Itemd.GetEndurance());
        } else
        {
            if (Itemd.Prefix()) {
                z = Itemd.PrefixID();
            }
            else {
                z = 0;
            }

            CPlayer::Write(IPlayer.GetOffset(), 91, "db", Itemd.GetIID(), 0);
            CDBSocket::Write(3, "ddwdbddd", Itemd.GetIID(), IPlayer.GetID(),
                Itemd.CheckIndex(),
                1, 27, 0, 0, 0);
            int value = *(DWORD*)(d + 100) & 0xFF | ((*(DWORD*)(d + 84) & 0xFF) << 8) | ((*
                        (DWORD*)(d + 92) & 0xFF) << 16) | (z << 24);
            int argument = ((*(DWORD*)(d + 112) & 0xFF) << 8) | (*(DWORD*)(d + 104) << 24);
            int checker = ((*(DWORD*)(d + 128) & 0xFF) << 8) | ((*(DWORD*)(
                            d + 124) & 0xFF) << 16) | (*(DWORD*)(d + 120) << 24);
            CDBSocket::Write(3, "ddwdbddd", Itemd.GetIID(), IPlayer.GetID(),
                Itemd.CheckIndex(),
                *(DWORD*)(d + 52), 9, value, argument, checker);
            CBase::Delete(Itemd.GetOffset());
        }

        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        return 0;
    } else {
        if (!CBase::IsDeleted(p)
            && Itemp.GetItemPointerFromIID(IPlayer.GetOffset(), Itemp.GetIID())) {
            CItem::RemoveItem(pPlayer, p);
        }

        if (!CBase::IsDeleted(u)
            && Itemu.GetItemPointerFromIID(IPlayer.GetOffset(), Itemu.GetIID())) {
            CItem::RemoveItem(pPlayer, u);
        }

        if (!CBase::IsDeleted(h)
            && Itemh.GetItemPointerFromIID(IPlayer.GetOffset(), Itemh.GetIID())) {
            CItem::RemoveItem(pPlayer, h);
        }

        if (!CBase::IsDeleted(l)
            && Iteml.GetItemPointerFromIID(IPlayer.GetOffset(), Iteml.GetIID())) {
            CItem::RemoveItem(pPlayer, l);
        }

        if (!(*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                (**((DWORD **)pPlayer + 274) + 120))(*((DWORD *)pPlayer + 274),
                pPlayer, 9, -70000)) {
            CPlayer::_OutOfInven(IPlayer.GetOffset(), *((DWORD *)pPlayer + 274));
        }

        int ImpItem = 0, Imp = 0;

        switch (*(DWORD *)(*(DWORD *)(d + 40) + 80))
        {
            case 0x28:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    Imp = 7210;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1433;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1) {
                        Imp = 771;
                    }
                    else {
                        Imp = 770;
                    }
                } else {
                    Imp = 769;
                }

                break;

            case 0x2D:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    Imp = 7290;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1434;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1) {
                        Imp = 774;
                    }
                    else {
                        Imp = 773;
                    }
                } else {
                    Imp = 772;
                }

                break;

            case 0x30:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    Imp = 7214;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1435;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1) {
                        Imp = 777;
                    }
                    else {
                        Imp = 776;
                    }
                } else {
                    Imp = 775;
                }

                break;

            case 0x32:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    Imp = 7218;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1436;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1) {
                        Imp = 781;
                    }
                    else {
                        Imp = 780;
                    }
                } else {
                    Imp = (*(DWORD *)(*(DWORD *)(d + 40) + 72) != 0) + 778;
                }

                break;

            case 0x35:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    Imp = 7222;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1437;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1) {
                        Imp = 785;
                    }
                    else {
                        Imp = 784;
                    }
                } else {
                    Imp = (*(DWORD *)(*(DWORD *)(d + 40) + 72) != 0) + 782;
                }

                break;

            case 0x38:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    Imp = 7226;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1438;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1) {
                        Imp = 789;
                    }
                    else {
                        Imp = 788;
                    }
                } else {
                    Imp = (*(DWORD *)(*(DWORD *)(d + 40) + 72) != 0) + 786;
                }

                break;

            case 0x3B:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    Imp = 7230;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1439;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1) {
                        Imp = 793;
                    }
                    else {
                        Imp = 792;
                    }
                } else {
                    Imp = (*(DWORD *)(*(DWORD *)(d + 40) + 72) != 0) + 790;
                }

                break;

            case 0x3E:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    if (Itemd.CheckIndex() == 7231) {
                        Imp = 7230;
                    }
                    else if (Itemd.CheckIndex() == 7233) {
                        Imp = 7235;
                    }
                    else if (Itemd.CheckIndex() == 7234) {
                        Imp = 7236;
                    }
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1440;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1) {
                        Imp = 797;
                    }
                    else {
                        Imp = 796;
                    }
                } else {
                    Imp = (*(DWORD *)(*(DWORD *)(d + 40) + 72) != 0) + 794;
                }

                break;

            case 0x41:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    Imp = 7238;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1441;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1 && Itemd.CheckIndex() == 672) {
                        Imp = 801;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 1677) {
                        Imp = 1821;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 1678) {
                        Imp = 1822;
                    }
                    else {
                        Imp = 800;
                    }
                } else {
                    Imp = (*(DWORD *)(*(DWORD *)(d + 40) + 72) != 0) + 798;
                }

                break;

            case 0x46:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    if (Itemd.CheckIndex() == 7239) {
                        Imp = 7241;
                    }
                    else if (Itemd.CheckIndex() == 7240) {
                        Imp = 7242;
                    }
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 1704;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1 && Itemd.CheckIndex() == 1698) {
                        Imp = 1853;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 1705) {
                        Imp = 1823;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 1706) {
                        Imp = 1824;
                    }
                    else {
                        Imp = 1702;
                    }
                } else {
                    if (Itemd.CheckIndex() == 1695) {
                        Imp = 1700;
                    }
                    else {
                        Imp = 1701;
                    }
                }

                break;

            case 0x4B:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    if (Itemd.CheckIndex() == 7243) {
                        Imp = 7245;
                    }
                    else if (Itemd.CheckIndex() == 7244) {
                        Imp = 7246;
                    }
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    if (Itemd.CheckIndex() == -1328) {
                        Imp = 4335;
                    }
                    else {
                        Imp = 1927;
                    }
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1 && Itemd.CheckIndex() == 1917) {
                        Imp = 1924;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 1918) {
                        Imp = 1925;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 1919) {
                        Imp = 1926;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == -1325) {
                        Imp = 4332;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == -1326) {
                        Imp = 4333;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == -1327) {
                        Imp = 4334;
                    }
                    else if (Itemd.CheckIndex() == -1324) {
                        Imp = 4331;
                    }
                    else {
                        Imp = 1923;
                    }
                } else {
                    if (Itemd.CheckIndex() == 1914) {
                        Imp = 1921;
                    }
                    else if (Itemd.CheckIndex() == -1322) {
                        Imp = 4329;
                    }
                    else if (Itemd.CheckIndex() == -1323) {
                        Imp = 4330;
                    }
                    else {
                        Imp = 1922;
                    }
                }

                break;

            case 0x50:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    if (Itemd.CheckIndex() == 7247) {
                        Imp = 7249;
                    }
                    else if (Itemd.CheckIndex() == 7248) {
                        Imp = 7250;
                    }
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 3039;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1 && Itemd.CheckIndex() == 3029) {
                        Imp = 3036;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 3030) {
                        Imp = 3037;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 3031) {
                        Imp = 3038;
                    }
                    else {
                        Imp = 3035;
                    }
                } else {
                    if (Itemd.CheckIndex() == 3026) {
                        Imp = 3033;
                    }
                    else {
                        Imp = 3034;
                    }
                }

                break;

            case 0x5A:
                if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == -1)
                {
                    if (Itemd.CheckIndex() == 7251) {
                        Imp = 7253;
                    }
                    else if (Itemd.CheckIndex() == 7252) {
                        Imp = 7254;
                    }
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 3)
                {
                    Imp = 3161;
                } else if (*(DWORD *)(*(DWORD *)(d + 40) + 96))
                {
                    if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1 && Itemd.CheckIndex() == 3150) {
                        Imp = 3158;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 3151) {
                        Imp = 3159;
                    }
                    else if (*(DWORD *)(*(DWORD *)(d + 40) + 96) == 1
                        && Itemd.CheckIndex() == 3152) {
                        Imp = 3160;
                    }
                    else {
                        Imp = 3157;
                    }
                } else {
                    if (Itemd.CheckIndex() == 3147) {
                        Imp = 3155;
                    }
                    else {
                        Imp = 3156;
                    }
                }

                break;

            default:
                break;
        }

        int Prefix = 0;
        int ItemStat = GetItemStat.find(*(DWORD *)(d + 36))->second;

        if (*(DWORD *)(d + 44)) {
            Prefix = *(DWORD *)(*(DWORD *)(d + 44) + 32);
        }
        else {
            Prefix = 0;
        }

        if (Imp) {
            ImpItem = CItem::CreateItem(Imp, Prefix, 1, -1);
        }

        if (ImpItem)
        {
            CIOObject::AddRef(ImpItem);

            if (*(DWORD *)(d + 48)) {
                *(DWORD *)(ImpItem + 48) = *(DWORD *)(d + 48);
            }

            if (*(DWORD *)(d + 100)) {
                *(DWORD *)(ImpItem + 100) = *(DWORD *)(d + 100);
            }

            if (*(DWORD *)(d + 104)) {
                *(DWORD *)(ImpItem + 104) = *(DWORD *)(d + 104);
            }

            if (*(DWORD *)(d + 112)) {
                *(DWORD *)(ImpItem + 112) = *(DWORD *)(d + 112);
            }

            if (*(DWORD *)(d + 124)) {
                *(DWORD *)(ImpItem + 124) = *(DWORD *)(d + 124);
            }

            if (*(DWORD *)(d + 84)) {
                *(DWORD *)(ImpItem + 84) = *(DWORD *)(d + 84);
            }

            if (CPlayer::_InsertItem(IPlayer.GetOffset(), 27, ImpItem) != 1)
            {
                CConsole::Red("MixItem() insert item Null error [PID (%d)] ", IPlayer.GetPID());
                CBase::Delete((void *)ImpItem);
                CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
                return 0;
            }

            CIOObject::Release((void *)ImpItem);
        }

        if (!CBase::IsDeleted(d)
            && Itemd.GetItemPointerFromIID(IPlayer.GetOffset(), Itemd.GetIID())) {
            CItem::RemoveItem(pPlayer, d);
        }

        GetItemStat[*(DWORD *)(ImpItem + 36)] = ItemStat;
        CDBSocket::Write(90, "ddd", IPlayer.GetPID(), ItemStat,
            *(DWORD *)(ImpItem + 36));
        CDBSocket::Write(87, "ddd", IPlayer.GetPID(), *(DWORD *)(ImpItem + 84),
            *(DWORD *)(ImpItem + 36));
        CDBSocket::Write(21, "dddbb", *(DWORD *)(ImpItem + 36),
            *(DWORD *)(ImpItem + 32),
            *(DWORD *)(ImpItem + 48), 8, 7);
        CDBSocket::Write(17, "ddbbb", *(DWORD *)(ImpItem + 36),
            *(DWORD *)(ImpItem + 32),
            27, *(DWORD *)(ImpItem + 100), 0);
        CDBSocket::Write(17, "ddbbb", *(DWORD *)(ImpItem + 36),
            *(DWORD *)(ImpItem + 32),
            28, *(DWORD *)(ImpItem + 104), 0);
        CDBSocket::Write(17, "ddbbb", *(DWORD *)(ImpItem + 36),
            *(DWORD *)(ImpItem + 32),
            9, *(DWORD *)(ImpItem + 112), 0);
        CDBSocket::Write(28, "ddbb", *(DWORD *)(ImpItem + 36), *(DWORD *)(ImpItem + 32),
            2,
            *(DWORD *)(ImpItem + 124));
        CItem::SendItemInfo((void*)ImpItem, (int)IPlayer.GetOffset(), 92);
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        return 1;
    }

    return 0;
}

int __fastcall EnforceItem(void *pPlayer, void *edx, int MixLevel,
    int ItemIndex, int DemonSword, int Item, int NextItem, char Stone)
{
    IChar IPlayer(pPlayer);

    if (!IPlayer.IsOnline()) {
        return 0;
    }

    if (ItemIndex == DemonSword || ItemIndex == Item || ItemIndex == NextItem
        || ItemIndex == Stone) {
        return 0;
    }

    if (DemonSword == ItemIndex || DemonSword == Item || DemonSword == NextItem
        || DemonSword == Stone) {
        return 0;
    }

    if (Item == ItemIndex || Item == DemonSword || Item == NextItem
        || Item == Stone) {
        return 0;
    }

    if (NextItem == ItemIndex || NextItem == DemonSword || NextItem == Item
        || NextItem == Stone) {
        return 0;
    }

    if (Stone == ItemIndex || Stone == DemonSword || Stone == Item
        || Stone == NextItem) {
        return 0;
    }

    CIOCriticalSection::Enter((struct _RTL_CRITICAL_SECTION *)((
                int)pPlayer + 1020));
    int MixCheck = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0,
        j = 0,
        k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, r = 0, s = 0, t = 0, u = 0, v= 0,
        y = 0, z = 0;
    *(DWORD*)&MixCheck = 0;
    bool success = false;

    if (!*(DWORD *)((int)pPlayer + 1096)
        || *(DWORD *)(*(DWORD *)((int)pPlayer + 1096) + 52) < 30000)
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
            (int)&a, (int)&ItemIndex);
    b = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&c);

    if (!Undefined::CheckValues(&MixCheck, b))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    d = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    IItem Itemd((void*)d);

    MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
            (int)&e, (int)&DemonSword);
    f = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&g);

    if (!Undefined::CheckValues(&MixCheck, f))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    h = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    IItem Itemh((void*)h);

    if (Itemh.CheckIndex() == 906)
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
            (int)&i, (int)&Item);
    j = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&k);

    if (!Undefined::CheckValues(&MixCheck, j))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    l = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    IItem Iteml((void*)l);

    MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
            (int)&m, (int)&NextItem);
    n = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&o);

    if (!Undefined::CheckValues(&MixCheck, n))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    p = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    IItem Itemp((void*)p);

    if (Itemd.GetIID() == Itemh.GetIID() || Itemd.GetIID() == Iteml.GetIID()
        || Itemh.GetIID() == Iteml.GetIID())
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    if (MixLevel)
    {
        MixCheck = *(DWORD*)Undefined::CreateMonsterValue((char *)(int)pPlayer + 1068,
                (int)&r, (int)&Stone);
        t = (int)Undefined::Check((int)((char *)(int)pPlayer + 1068), (int)&s);

        if (!Undefined::CheckValues(&MixCheck, t))
        {
            CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
            CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
            return 0;
        }

        u = *(DWORD*)(Undefined::GetValue(&MixCheck) + 4);
    }

    IItem Itemu((void*)u);

    if (MixLevel && Itemu.GetIID() == Itemp.GetIID())
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    if (MixLevel && (Itemu.CheckIndex() < 895 || Itemu.CheckIndex() > 905))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    if (Itemp.CheckIndex() < 895 || Itemp.CheckIndex() > 905)
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    if (!MixItemCheck(d, h, l))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    if (MixLevel && Itemp.CheckIndex() != 904 && Itemp.CheckIndex() != 905
        && Itemu.CheckIndex() != 904 && Itemu.CheckIndex() != 905
        && !CItem::IsState(d, 1048576))
    {
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
        return 0;
    }

    switch (*(DWORD *)(*(DWORD *)(d + 40) + 80))
    {
        case 0x28:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x2D:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x30:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x32:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x35:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x38:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x3B:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x3E:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x41:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x46:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x4B:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;

        case 0x50:
            if (CTools::Rate(0, 99) <= ConfigMix) {
                success = true;
            }

            break;
    }

    if (success == false)
    {
        if (!(*(int (__thiscall **)(DWORD, void *, signed int,
                        signed int))(**((DWORD**)pPlayer + 274) + 120))(*((DWORD *)pPlayer + 274),
                pPlayer, 9, -30000)) {
            CPlayer::_OutOfInven(IPlayer.GetOffset(), *((DWORD *)pPlayer + 274));
        }

        if (!CBase::IsDeleted(p)
            && Itemp.GetItemPointerFromIID(IPlayer.GetOffset(), Itemp.GetIID())) {
            CItem::RemoveItem(pPlayer, p);
        }

        if (MixLevel)
        {
            if (!CBase::IsDeleted(u)
                && Itemu.GetItemPointerFromIID(IPlayer.GetOffset(), Itemu.GetIID())) {
                CItem::RemoveItem(pPlayer, u);
            }
        }

        CPlayer::Write(pPlayer, 68, "bb", 138, 1);

        if (Itemd.GetEndurance() >= 5) {
            *(DWORD *)((int)Itemd.GetOffset() + 96) -= 5;
        }
        else
            *(DWORD *)((int)Itemd.GetOffset() + 96) -= *(DWORD *)((int)Itemd.GetOffset() +
                    96);

        if (Itemd.GetEndurance() > 0)
        {
            CPlayer::Write(pPlayer, 91, "db", Itemd.GetIID(), Itemd.GetEndurance());
            CDBSocket::Write(18, "ddb", Itemd.GetIID(), IPlayer.GetID(),
                Itemd.GetEndurance());
        } else {
            if (Itemd.Prefix()) {
                z = Itemd.PrefixID();
            }
            else {
                z = 0;
            }

            CPlayer::Write(IPlayer.GetOffset(), 91, "db", Itemd.GetIID(), 0);
            CDBSocket::Write(3, "ddwdbddd", Itemd.GetIID(), IPlayer.GetID(),
                Itemd.CheckIndex(),
                1, 27, 0, 0, 0);
            int value = *(DWORD*)(d + 100) & 0xFF | ((*(DWORD*)(d + 84) & 0xFF) << 8) | ((*
                        (DWORD*)(d + 92) & 0xFF) << 16) | (z << 24);
            int argument = ((*(DWORD*)(d + 112) & 0xFF) << 8) | (*(DWORD*)(d + 104) << 24);
            int checker = ((*(DWORD*)(d + 128) & 0xFF) << 8) | ((*(DWORD*)(
                            d + 124) & 0xFF) << 16) | (*(DWORD*)(d + 120) << 24);
            CDBSocket::Write(3, "ddwdbddd", Itemd.GetIID(), IPlayer.GetID(),
                Itemd.CheckIndex(),
                *(DWORD*)(d + 52), 9, value, argument, checker);
            CBase::Delete(Itemd.GetOffset());
        }

        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        return 0;
    } else {
        CDBSocket::Write(21, "dddbb", Itemd.GetIID(), IPlayer.GetID(), 524032, 0, 39);
        CItem::SubState(d, 524032);

        if (MixLevel)
        {
            if (CItem::ReturnIndex(p) != 904 && CItem::ReturnIndex(p) != 905) {
                v = u;
            }
            else {
                v = p;
            }

            y = CItem::ReturnIndex(v);

            if (y == 904)
            {
                if (!CItem::IsState(d, 1048576))
                {
                    CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
                    CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
                    return 0;
                }

                CItem::AddGState((int)Itemd.GetOffset(), 131072);
            } else {
                if (y == 905)
                {
                    if (!CItem::IsState((int)Itemd.GetOffset(), 1048576))
                    {
                        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
                        CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 138, 0);
                        return 0;
                    }

                    CItem::AddGState((int)Itemd.GetOffset(), 262144);
                }
            }
        } else {
            switch (Itemp.CheckIndex())
            {
                case 0x37F:
                    CItem::AddGState((int)Itemd.GetOffset(), 256);
                    break;

                case 0x380:
                    CItem::AddGState((int)Itemd.GetOffset(), 512);
                    break;

                case 0x381:
                    CItem::AddGState((int)Itemd.GetOffset(), 1024);
                    break;

                case 0x382:
                    CItem::AddGState((int)Itemd.GetOffset(), 2048);
                    break;

                case 0x383:
                    CItem::AddGState((int)Itemd.GetOffset(), 4096);
                    break;

                case 0x384:
                    CItem::AddGState((int)Itemd.GetOffset(), 8192);
                    break;

                case 0x385:
                    CItem::AddGState((int)Itemd.GetOffset(), 16384);
                    break;

                case 0x386:
                    CItem::AddGState((int)Itemd.GetOffset(), 32768);
                    break;

                case 0x387:
                    CItem::AddGState((int)Itemd.GetOffset(), 65536);
                    break;

                default:
                    break;
            }
        }

        if (CItem::IsState((int)Itemd.GetOffset(), 524288)
            || CItem::IsState((int)Itemd.GetOffset(), 1048576))
        {
            if (CItem::IsState((int)Itemd.GetOffset(), 524288))
            {
                CDBSocket::Write(21, "dddbb", Itemd.GetIID(), IPlayer.GetID(), 524288, 0, 39);
                CItem::SubState((int)Itemd.GetOffset(), 524288);
                CItem::AddGState((int)Itemd.GetOffset(), 1048576);
            }
        } else {
            CItem::AddGState((int)Itemd.GetOffset(), 524288);
        }

        if (!CBase::IsDeleted(h)
            && Itemh.GetItemPointerFromIID(IPlayer.GetOffset(), Itemh.GetIID())) {
            CItem::RemoveItem(pPlayer, h);
        }

        if (!CBase::IsDeleted(l)
            && Iteml.GetItemPointerFromIID(IPlayer.GetOffset(), Iteml.GetIID())) {
            CItem::RemoveItem(pPlayer, l);
        }

        if (!(*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                (**((DWORD **)pPlayer + 274) + 120))(*((DWORD *)pPlayer + 274),
                pPlayer, 9, -30000)) {
            CPlayer::_OutOfInven(IPlayer.GetOffset(), *((DWORD *)pPlayer + 274));
        }

        if (!CBase::IsDeleted(p)
            && Itemp.GetItemPointerFromIID(IPlayer.GetOffset(), Itemp.GetIID())) {
            CItem::RemoveItem(pPlayer, p);
        }

        if (MixLevel)
        {
            if (!CBase::IsDeleted(u)
                && Itemu.GetItemPointerFromIID(IPlayer.GetOffset(), Itemu.GetIID())) {
                CItem::RemoveItem(pPlayer, u);
            }
        }

        if (Itemd.Prefix()) {
            z = Itemd.PrefixID();
        }
        else {
            z = 0;
        }

        int Value = *(DWORD*)(d + 100) & 0xFF | ((*(DWORD*)(d + 84) & 0xFF) << 8) | ((*
                    (DWORD*)(d + 92) & 0xFF) << 16) | (z << 24);
        int Argument = ((*(DWORD*)(d + 112) & 0xFF) << 8) | (*(DWORD*)(d + 104) << 24);
        CDBSocket::Write(21, "dddbwddb", Itemd.GetIID(), IPlayer.GetID(),
            Itemd.GetInfo(), 1,
            Itemd.CheckIndex(), Value, Argument, *(DWORD *)(d + 120));
        CItem::SendItemInfo((void *)d, (int)pPlayer, 92);
        CIOCriticalSection::Leave((void*)((char *)pPlayer + 1020));
        return 1;
    }

    return 0;
}
