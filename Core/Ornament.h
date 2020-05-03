int __cdecl GetLowestTrigramGrade(int PID)
{
    int Grade = 20;

    if (TrigramHP.find(PID)->second
        && TrigramHP.find(PID)->second < Grade) {
        Grade = TrigramHP.find(PID)->second;
    }

    if (TrigramMP.find(PID)->second
        && TrigramMP.find(PID)->second < Grade) {
        Grade = TrigramMP.find(PID)->second;
    }

    if (TrigramAtk.find(PID)->second
        && TrigramAtk.find(PID)->second < Grade) {
        Grade = TrigramAtk.find(PID)->second;
    }

    if (TrigramStr.find(PID)->second
        && TrigramStr.find(PID)->second < Grade) {
        Grade = TrigramStr.find(PID)->second;
    }

    if (TrigramAgi.find(PID)->second
        && TrigramAgi.find(PID)->second < Grade) {
        Grade = TrigramAgi.find(PID)->second;
    }

    if (TrigramInt.find(PID)->second
        && TrigramInt.find(PID)->second < Grade) {
        Grade = TrigramInt.find(PID)->second;
    }

    if (TrigramWis.find(PID)->second
        && TrigramWis.find(PID)->second < Grade) {
        Grade = TrigramWis.find(PID)->second;
    }

    if (TrigramHth.find(PID)->second
        && TrigramHth.find(PID)->second < Grade) {
        Grade = TrigramHth.find(PID)->second;
    }

    if (Grade == 20) {
        Grade = 0;
    }

    return Grade;
}

int __cdecl NewItem(int Value)
{
    if (*(DWORD *)(Value + 68) == -1)
    {
        void *Check = 0, *GetPointer = 0;
        Check = (void*)Undefined::GetMonsterValue(0x5Cu);

        if ((int)Check) {
            GetPointer = CItemOrnament::CItemOrnament(Check, Value);
        }
        else {
            GetPointer = 0;
        }

        if ((int)GetPointer)
        {
            IItem xItem(GetPointer);

            if (xItem.CheckIndex() >= 3384 && xItem.CheckIndex() <= 3386)
            {
                *(DWORD*)((int)GetPointer + 48) = 128;
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -95;
                return (int)GetPointer;
            }

            if (PetTime.count(xItem.CheckIndex()) || (xItem.CheckIndex() >= 1747
                    && xItem.CheckIndex() <= 1762) || (xItem.CheckIndex() >= 1870
                    && xItem.CheckIndex() <= 1877) || (xItem.CheckIndex() >= 2004
                    && xItem.CheckIndex() <= 2007) || (xItem.CheckIndex() >= 2421
                    && xItem.CheckIndex() <= 2423) || (xItem.CheckIndex() >= 2550
                    && xItem.CheckIndex() <= 2653) || (xItem.CheckIndex() >= 6045
                    && xItem.CheckIndex() <= 6052))
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -100;
                *(DWORD*)((int)GetPointer + 48) = 128;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() == 2986 || xItem.CheckIndex() == 2994
                || xItem.CheckIndex() == 3002)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -101;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() == 2987 || xItem.CheckIndex() == 2995
                || xItem.CheckIndex() == 3003)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -102;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() == 2988 || xItem.CheckIndex() == 2996
                || xItem.CheckIndex() == 3004)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -103;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() == 2989 || xItem.CheckIndex() == 2997
                || xItem.CheckIndex() == 3005)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -104;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() == 2990 || xItem.CheckIndex() == 2998
                || xItem.CheckIndex() == 3006)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -105;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() == 2991 || xItem.CheckIndex() == 2999
                || xItem.CheckIndex() == 3007)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -106;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() == 2992 || xItem.CheckIndex() == 3000
                || xItem.CheckIndex() == 3008)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -107;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() == 2993 || xItem.CheckIndex() == 3001
                || xItem.CheckIndex() == 3009)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -108;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() >= 3199 && xItem.CheckIndex() <= 3204)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -109;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() >= 3381 && xItem.CheckIndex() <= 3383)
            {
                *(DWORD*)((int)GetPointer + 48) = 128;
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -110;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() >= 2946 && xItem.CheckIndex() <= 2948)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -111;
                return (int)GetPointer;
            }

            if (xItem.CheckIndex() >= 3018 && xItem.CheckIndex() <= 3020)
            {
                *(DWORD*)(*(DWORD*)((int)GetPointer + 40) + 72) = -112;
                *(DWORD*)((int)GetPointer + 48) = 128;
                return (int)GetPointer;
            }
        }
    }

    return CItem::NewItem(Value);
}

int __cdecl MyCreateItem(int Index, int Prefix, int Amount, int Argument)
{
    int result = 0, Item = 0, FindItem = 0;

    if (Amount > 0)
    {
        FindItem = CItem::FindInitItem(Index);

        if (FindItem)
        {
            Item = NewItem(FindItem);

            if (Item)
            {
                if (Prefix >= 256)
                {
                    *(DWORD*)(Item + 48) = 128;
                    Prefix -= 256;
                }

                (*(void (__thiscall **)(void *, int, int, int))(*(DWORD*)Item + 76))
                ((void*)Item, Prefix, Amount, Argument);
            }
        }

        result = Item;
    } else {
        result = 0;
    }

    return result;
}

int __fastcall OrnamentPutOn(int Itemx, void *edx, int Playerx)
{
    IItem Item((void*)Itemx);
    IChar Player((void*)Playerx);
    int GetPetTime = 259200;

    if (Player.IsOnline())
    {
        if (Player.IsBuff(256))
        {
            Player.SystemMessage("You need to wait 3 seconds to put on your item.",
                TEXTCOLOR_INFOMSG);
            return 0;
        } else {
            Player.Buff(256, 2, 0);

            if (Item.CheckIndex() >= 3384 && Item.CheckIndex() <= 3386
                && !CPlayer::IsWState(Playerx, -112)) {
                return 0;
            }

            if (Item.CheckIndex() >= 3384 && Item.CheckIndex() <= 3386
                && CheckHaninMirror.find(Player.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Itemy = 0;
                Undefined::CreateMonsterValue((char*)Playerx + 1068, (int)&Value,
                    (int)&CheckHaninMirror.find(Player.GetPID())->second);
                Check = Undefined::Check((int)((char*)Playerx + 1068), (int)&Recheck);

                if (!Undefined::CheckValues(&Value, Check)) {
                    return 0;
                }

                Itemy = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                IItem Mirror((void*)Itemy);
                int Valuex = 0, Type = 0;
                double Stat = 0;
                Valuex = GetItemStat.find(Item.GetIID())->second;
                Type = Valuex % 100;

                if (Type == 12 && Player.IsBuff(418))
                {
                    Player.BoxMsg("You can wear only one speed essence.");
                    return 0;
                }
            }

            if (Item.CheckIndex() >= 3381 && Item.CheckIndex() <= 3383)
            {
                if (CheckHaninMirror.find(Player.GetPID())->second) {
                    return 0;
                }
                else {
                    CheckHaninMirror[Player.GetPID()] = Item.GetIID();
                }
            }

            if (Item.CheckIndex() >= 3384 && Item.CheckIndex() <= 3386
                && CheckHaninMirror.find(Player.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Itemy = 0;
                Undefined::CreateMonsterValue((char*)Playerx + 1068, (int)&Value,
                    (int)&CheckHaninMirror.find(Player.GetPID())->second);
                Check = Undefined::Check((int)((char*)Playerx + 1068), (int)&Recheck);

                if (!Undefined::CheckValues(&Value, Check)) {
                    return 0;
                }

                Itemy = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                IItem Mirror((void*)Itemy);
                int SlotSize = 0, TotalSlotSize = 0;
                SlotSize = GetItemStat.find(Mirror.GetIID())->second + 1;

                if (SlotSize == 1 && Mirror.CheckIndex() == 3383) {
                    SlotSize = 2;
                }

                if (CheckEssense1.find(Player.GetPID())->second) {
                    TotalSlotSize += 1;
                }

                if (CheckEssense2.find(Player.GetPID())->second) {
                    TotalSlotSize += 1;
                }

                if (CheckEssense3.find(Player.GetPID())->second) {
                    TotalSlotSize += 1;
                }

                if (CheckEssense4.find(Player.GetPID())->second) {
                    TotalSlotSize += 1;
                }

                if (CheckEssense5.find(Player.GetPID())->second) {
                    TotalSlotSize += 1;
                }

                if (TotalSlotSize >= SlotSize) {
                    return 0;
                }

                if (Mirror.CheckIndex() == 3381)
                {
                    if (!CheckEssense1.find(Player.GetPID())->second)
                    {
                        CheckEssense1[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -95;
                    } else if (!CheckEssense2.find(Player.GetPID())->second) {
                        CheckEssense2[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -96;
                    } else if (!CheckEssense3.find(Player.GetPID())->second) {
                        CheckEssense3[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -97;
                    }
                }

                if (Mirror.CheckIndex() == 3382)
                {
                    if (!CheckEssense1.find(Player.GetPID())->second)
                    {
                        CheckEssense1[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -95;
                    } else if (!CheckEssense2.find(Player.GetPID())->second) {
                        CheckEssense2[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -96;
                    } else if (!CheckEssense3.find(Player.GetPID())->second) {
                        CheckEssense3[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -97;
                    } else if (!CheckEssense4.find(Player.GetPID())->second) {
                        CheckEssense4[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -98;
                    }
                }

                if (Mirror.CheckIndex() == 3383)
                {
                    if (!CheckEssense1.find(Player.GetPID())->second)
                    {
                        CheckEssense1[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -95;
                    } else if (!CheckEssense2.find(Player.GetPID())->second) {
                        CheckEssense2[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -96;
                    } else if (!CheckEssense3.find(Player.GetPID())->second) {
                        CheckEssense3[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -97;
                    } else if (!CheckEssense4.find(Player.GetPID())->second) {
                        CheckEssense4[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -98;
                    } else if (!CheckEssense5.find(Player.GetPID())->second) {
                        CheckEssense5[Player.GetPID()] = Item.GetIID();
                        *(DWORD*)(*(DWORD*)(Itemx + 40) + 72) = -99;
                    }
                }
            }

            if ((PetTime.count(Item.CheckIndex()) || (Item.CheckIndex() >= 1747
                        && Item.CheckIndex() <= 1762) || (Item.CheckIndex() >= 1870
                        && Item.CheckIndex() <= 1877) || (Item.CheckIndex() >= 2004
                        && Item.CheckIndex() <= 2007) || (Item.CheckIndex() >= 2421
                        && Item.CheckIndex() <= 2423) || (Item.CheckIndex() >= 2550
                        && Item.CheckIndex() <= 2653) || (Item.CheckIndex() >= 6045
                        && Item.CheckIndex() <= 6052)) && !PetLifeCheck.count(Item.GetIID()))
            {
                if (PetTime.count(Item.CheckIndex())
                    && PetTime.find(Item.CheckIndex())->second.Time > 0) {
                    GetPetTime = PetTime.find(Item.CheckIndex())->second.Time;
                }

                PetLifeCheck[Item.GetIID()].Time = (int)time(0) + GetPetTime;
                PetLifeCheck[Item.GetIID()].Player = (int)Player.GetOffset();
                CDBSocket::Write(89, "ddd", Player.GetPID(), (int)time(0) + GetPetTime,
                    Item.GetIID());
                CPlayer::Write(Player.GetOffset(), 0xFF, "ddd", 230, Item.GetIID(),
                    GetPetTime * 1000);
                *(DWORD*)(Itemx + 68) = GetTickCount() + (2000 * GetPetTime);
                *(DWORD*)(Itemx + 72) = 0;
                CItem::OnTimer(Itemx, 0);
            }

            if (PetTime.count(Item.CheckIndex()) || (Item.CheckIndex() >= 1747
                    && Item.CheckIndex() <= 1762) || (Item.CheckIndex() >= 1870
                    && Item.CheckIndex() <= 1877) || (Item.CheckIndex() >= 2004
                    && Item.CheckIndex() <= 2007) || (Item.CheckIndex() >= 2421
                    && Item.CheckIndex() <= 2423) || (Item.CheckIndex() >= 2550
                    && Item.CheckIndex() <= 2653) || (Item.CheckIndex() >= 6045
                    && Item.CheckIndex() <= 6052))
            {
                if (Item.CheckIndex() >= 2004 && Item.CheckIndex() <= 2007)
                    CChar::WriteInSight(Player.GetOffset(), 221, "dwdb", Player.GetID(),
                        Item.CheckIndex(), Item.GetIID(), 2);
                else
                    CChar::WriteInSight(Player.GetOffset(), 221, "dwdb", Player.GetID(),
                        Item.CheckIndex(), Item.GetIID(), 0);
            }

            return CItemOrnament::PutOn(Itemx, Playerx);
        }
    } else {
        return 0;
    }
}

int __fastcall OrnamentPutOff(void *Itemx, void *edx, int Playerx)
{
    IItem Item(Itemx);
    IChar Player((void*)Playerx);

    if (Player.IsOnline())
    {
        if (Player.IsBuff(256))
        {
            Player.SystemMessage("You need to wait 3 seconds to put off your item.",
                TEXTCOLOR_INFOMSG);
            return 0;
        } else {
            Player.Buff(256, 2, 0);

            if (Item.CheckIndex() >= 3381 && Item.CheckIndex() <= 3383
                && (CheckEssense1.find(Player.GetPID())->second
                    || CheckEssense2.find(Player.GetPID())->second
                    || CheckEssense3.find(Player.GetPID())->second
                    || CheckEssense4.find(Player.GetPID())->second
                    || CheckEssense5.find(Player.GetPID())->second)) {
                return 0;
            }

            if (Item.CheckIndex() >= 3381 && Item.CheckIndex() <= 3383
                && CheckHaninMirror.find(Player.GetPID())->second) {
                CheckHaninMirror[Player.GetPID()] = 0;
            }

            if (Item.CheckIndex() >= 3384 && Item.CheckIndex() <= 3386
                && CheckHaninMirror.find(Player.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Itemy = 0;
                Undefined::CreateMonsterValue((char*)Playerx + 1068, (int)&Value,
                    (int)&CheckHaninMirror.find(Player.GetPID())->second);
                Check = Undefined::Check((int)((char*)Playerx + 1068), (int)&Recheck);

                if (!Undefined::CheckValues(&Value, Check)) {
                    return 0;
                }

                Itemy = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                IItem Mirror((void*)Itemy);
                int Valuex = 0, Type = 0;
                double Stat = 0;
                Valuex = GetItemStat.find(Item.GetIID())->second;
                Type = Valuex % 100;
                Stat = Valuex / 10000;

                int Str = Player.GetStr(), Wis = Player.GetWis(), Hth = Player.GetHth(),
                    Int = Player.GetInt(), Agi = Player.GetAgi();
                int Otp = (15 * Str / 54), MinPAtk = (11 * Str - 80) / 30,
                    MaxPAtk = (8 * Str - 25) / 15,
                    Eva = Agi / 3, HpPoint = ((2 * Hth * Hth) / 100);
                int MpPoint = ((Wis + 2 * Wis * Wis) / 100),
                    MinMAtk = ((7 * Int - 20) / 12) + (Wis / 7),
                    MaxMAtk = (7 * Int / 12) + (14 * Wis / 45);

                if (Stat && Mirror.CheckIndex() == 3381)
                {
                    if (Type == 0) {
                        Player.RemoveStr(((Str * Stat) / 100) + 0.5);
                    }

                    if (Type == 1) {
                        Player.RemoveWis(((Wis * Stat) / 100) + 0.5);
                    }

                    if (Type == 2) {
                        Player.RemoveInt(((Int * Stat) / 100) + 0.5);
                    }

                    if (Type == 3) {
                        Player.RemoveHp(((Hth * Stat) / 100) + 0.5);
                    }

                    if (Type == 4) {
                        Player.RemoveAgi(((Agi * Stat) / 100) + 0.5);
                    }

                    if (Type == 5) {
                        Player.RemoveOTP(((Otp * Stat) / 100) + 0.5);
                    }

                    if (Type == 6) {
                        Player.RemoveEva(((Eva * Stat) / 100) + 0.5);
                    }

                    if (Type == 7) {
                        Player.RemoveDef(Stat + 0.5);
                    }

                    if (Type == 10) {
                        Player.DecreaseMaxHp(((HpPoint * Stat) / 100) + 0.5);
                    }

                    if (Type == 11) {
                        Player.DecreaseMaxMp(((MpPoint * Stat) / 100) + 0.5);
                    }

                    if (Type == 12) {
                        Player.DecreaseMovingSpeed((3 * Stat) + 0.5);
                    }

                    if (Type == 12) {
                        Player.CancelBuff(418);
                    }

                    if (Type == 13) {
                        Player.RemoveMinAttack(((MinPAtk * Stat) / 100) + 0.5);
                    }

                    if (Type == 14) {
                        Player.RemoveMaxAttack(((MaxPAtk * Stat) / 100) + 0.5);
                    }

                    if (Type == 15) {
                        Player.DecreaseCritRate((Stat / 3) + 0.5);
                    }

                    if (Type == 16) {
                        Player.DecreaseCritDamage((Stat / 2) + 0.5);
                    }

                    if (Type == 18) {
                        Player.RemoveMinAttack(((MinMAtk * Stat) / 100) + 0.5);
                    }

                    if (Type == 19) {
                        Player.RemoveMaxAttack(((MaxMAtk * Stat) / 100) + 0.5);
                    }

                    if (Type == 20) {
                        Player.CancelBuff(298);
                    }

                    if (Type == 21) {
                        Player.CancelBuff(330);
                    }
                }

                if (Stat && Mirror.CheckIndex() == 3382)
                {
                    if (Type == 0) {
                        Player.RemoveStr(((Str * Stat) / 90) + 0.5);
                    }

                    if (Type == 1) {
                        Player.RemoveWis(((Wis * Stat) / 90) + 0.5);
                    }

                    if (Type == 2) {
                        Player.RemoveInt(((Int * Stat) / 90) + 0.5);
                    }

                    if (Type == 3) {
                        Player.RemoveHp(((Hth * Stat) / 90) + 0.5);
                    }

                    if (Type == 4) {
                        Player.RemoveAgi(((Agi * Stat) / 90) + 0.5);
                    }

                    if (Type == 5) {
                        Player.RemoveOTP(((Otp * Stat) / 90) + 0.5);
                    }

                    if (Type == 6) {
                        Player.RemoveEva(((Eva * Stat) / 90) + 0.5);
                    }

                    if (Type == 7) {
                        Player.RemoveDef(Stat + 1.5);
                    }

                    if (Type == 10) {
                        Player.DecreaseMaxHp(((HpPoint * Stat) / 90) + 0.5);
                    }

                    if (Type == 11) {
                        Player.DecreaseMaxMp(((MpPoint * Stat) / 90) + 0.5);
                    }

                    if (Type == 12) {
                        Player.DecreaseMovingSpeed((3 * Stat) + 1.5);
                    }

                    if (Type == 12) {
                        Player.CancelBuff(418);
                    }

                    if (Type == 13) {
                        Player.RemoveMinAttack(((MinPAtk * Stat) / 90) + 0.5);
                    }

                    if (Type == 14) {
                        Player.RemoveMaxAttack(((MaxPAtk * Stat) / 90) + 0.5);
                    }

                    if (Type == 15) {
                        Player.DecreaseCritRate((Stat / 3) + 1.5);
                    }

                    if (Type == 16) {
                        Player.DecreaseCritDamage((Stat / 2) + 1.5);
                    }

                    if (Type == 18) {
                        Player.RemoveMinAttack(((MinMAtk * Stat) / 90) + 0.5);
                    }

                    if (Type == 19) {
                        Player.RemoveMaxAttack(((MaxMAtk * Stat) / 90) + 0.5);
                    }

                    if (Type == 20) {
                        Player.CancelBuff(298);
                    }

                    if (Type == 21) {
                        Player.CancelBuff(330);
                    }
                }

                if (Stat && Mirror.CheckIndex() == 3383)
                {
                    if (Type == 0) {
                        Player.RemoveStr(((Str * Stat) / 80) + 0.5);
                    }

                    if (Type == 1) {
                        Player.RemoveWis(((Wis * Stat) / 80) + 0.5);
                    }

                    if (Type == 2) {
                        Player.RemoveInt(((Int * Stat) / 80) + 0.5);
                    }

                    if (Type == 3) {
                        Player.RemoveHp(((Hth * Stat) / 80) + 0.5);
                    }

                    if (Type == 4) {
                        Player.RemoveAgi(((Agi * Stat) / 80) + 0.5);
                    }

                    if (Type == 5) {
                        Player.RemoveOTP(((Otp * Stat) / 80) + 0.5);
                    }

                    if (Type == 6) {
                        Player.RemoveEva(((Eva * Stat) / 80) + 0.5);
                    }

                    if (Type == 7) {
                        Player.RemoveDef(Stat + 2.5);
                    }

                    if (Type == 10) {
                        Player.DecreaseMaxHp(((HpPoint * Stat) / 80) + 0.5);
                    }

                    if (Type == 11) {
                        Player.DecreaseMaxMp(((MpPoint * Stat) / 80) + 0.5);
                    }

                    if (Type == 12) {
                        Player.DecreaseMovingSpeed((3 * Stat) + 2.5);
                    }

                    if (Type == 12) {
                        Player.CancelBuff(418);
                    }

                    if (Type == 13) {
                        Player.RemoveMinAttack(((MinPAtk * Stat) / 80) + 0.5);
                    }

                    if (Type == 14) {
                        Player.RemoveMaxAttack(((MaxPAtk * Stat) / 80) + 0.5);
                    }

                    if (Type == 15) {
                        Player.DecreaseCritRate((Stat / 3) + 2.5);
                    }

                    if (Type == 16) {
                        Player.DecreaseCritDamage((Stat / 2) + 2.5);
                    }

                    if (Type == 18) {
                        Player.RemoveMinAttack(((MinMAtk * Stat) / 80) + 0.5);
                    }

                    if (Type == 19) {
                        Player.RemoveMaxAttack(((MaxMAtk * Stat) / 80) + 0.5);
                    }

                    if (Type == 20) {
                        Player.CancelBuff(298);
                    }

                    if (Type == 21) {
                        Player.CancelBuff(330);
                    }
                }
            }

            if (Item.CheckIndex() >= 3384 && Item.CheckIndex() <= 3386
                && CheckHaninMirror.find(Player.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Itemy = 0;
                Undefined::CreateMonsterValue((char*)Playerx + 1068, (int)&Value,
                    (int)&CheckHaninMirror.find(Player.GetPID())->second);
                Check = Undefined::Check((int)((char*)Playerx + 1068), (int)&Recheck);

                if (!Undefined::CheckValues(&Value, Check)) {
                    return 0;
                }

                Itemy = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                IItem Mirror((void*)Itemy);

                if (Mirror.CheckIndex() == 3381)
                {
                    if (CheckEssense3.find(Player.GetPID())->second)
                    {
                        CheckEssense3[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -97;
                    } else if (CheckEssense2.find(Player.GetPID())->second) {
                        CheckEssense2[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -96;
                    } else if (CheckEssense1.find(Player.GetPID())->second) {
                        CheckEssense1[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -95;
                    }
                }

                if (Mirror.CheckIndex() == 3382)
                {
                    if (CheckEssense4.find(Player.GetPID())->second)
                    {
                        CheckEssense4[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -98;
                    } else if (CheckEssense3.find(Player.GetPID())->second) {
                        CheckEssense3[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -97;
                    } else if (CheckEssense2.find(Player.GetPID())->second) {
                        CheckEssense2[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -96;
                    } else if (CheckEssense1.find(Player.GetPID())->second) {
                        CheckEssense1[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -95;
                    }
                }

                if (Mirror.CheckIndex() == 3383)
                {
                    if (CheckEssense5.find(Player.GetPID())->second)
                    {
                        CheckEssense5[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -99;
                    } else if (CheckEssense4.find(Player.GetPID())->second) {
                        CheckEssense4[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -98;
                    } else if (CheckEssense3.find(Player.GetPID())->second) {
                        CheckEssense3[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -97;
                    } else if (CheckEssense2.find(Player.GetPID())->second) {
                        CheckEssense2[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -96;
                    } else if (CheckEssense1.find(Player.GetPID())->second) {
                        CheckEssense1[Player.GetPID()] = 0;
                        *(DWORD*)(*(DWORD*)((int)Itemx + 40) + 72) = -95;
                    }
                }
            }

            if (Item.CheckIndex() >= 2986 && Item.CheckIndex() <= 3009
                && Player.IsBuff(311)) {
                return 0;
            }

            if (Item.CheckIndex() >= 3018 && Item.CheckIndex() <= 3020)
            {
                if (Player.IsBuff(311) && Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second)
                {
                    Player.DecreaseMaxHp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][0]);
                    Player.DecreaseMaxMp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][1]);
                    Player.RemoveMaxAttack(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][2]);
                    Player.RemoveMinAttack(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][2]);
                    Player.RemoveStr(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][3]);
                    Player.RemoveAgi(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][4]);
                    Player.RemoveInt(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][5]);
                    Player.RemoveWis(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][6]);
                    Player.RemoveHp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second
                                - 1)][7]);
                }

                Taegeuk[*(DWORD*)((int)Itemx + 32)] = 0;
            }

            if (Item.CheckIndex() >= 2946 && Item.CheckIndex() <= 2948)
            {
                int YinYangType = 0;

                if (Item.CheckIndex() == 2947) {
                    YinYangType = 1;
                }

                if (Item.CheckIndex() == 2948) {
                    YinYangType = 2;
                }

                Player.CancelBuff(311);
                int YinYangGrade = TrigramGrade.find(*(DWORD*)((int)Itemx + 32))->second;
                Player.DecreaseMaxHp(TrigramHP.find(*(DWORD*)((int)Itemx + 32))->second + ((
                            TrigramHP.find(*(DWORD*)((int)Itemx + 32))->second *
                            YinYangRate[YinYangType][YinYangGrade]) / 100));
                Player.DecreaseMaxMp(TrigramMP.find(*(DWORD*)((int)Itemx + 32))->second + ((
                            TrigramMP.find(*(DWORD*)((int)Itemx + 32))->second *
                            YinYangRate[YinYangType][YinYangGrade]) / 100));
                Player.RemoveMaxAttack(TrigramAtk.find(*(DWORD*)((int)Itemx + 32))->second + ((
                            TrigramAtk.find(*(DWORD*)((int)Itemx + 32))->second *
                            YinYangRate[YinYangType][YinYangGrade]) / 100));
                Player.RemoveMinAttack(TrigramAtk.find(*(DWORD*)((int)Itemx + 32))->second + ((
                            TrigramAtk.find(*(DWORD*)((int)Itemx + 32))->second *
                            YinYangRate[YinYangType][YinYangGrade]) / 100));
                Player.RemoveStr(TrigramStr.find(*(DWORD*)((int)Itemx + 32))->second + ((
                            TrigramStr.find(*(DWORD*)((int)Itemx + 32))->second *
                            YinYangRate[YinYangType][YinYangGrade]) / 100));
                Player.RemoveAgi(TrigramAgi.find(*(DWORD*)((int)Itemx + 32))->second + ((
                            TrigramAgi.find(*(DWORD*)((int)Itemx + 32))->second *
                            YinYangRate[YinYangType][YinYangGrade]) / 100));
                Player.RemoveInt(TrigramInt.find(*(DWORD*)((int)Itemx + 32))->second + ((
                            TrigramInt.find(*(DWORD*)((int)Itemx + 32))->second *
                            YinYangRate[YinYangType][YinYangGrade]) / 100));
                Player.RemoveWis(TrigramWis.find(*(DWORD*)((int)Itemx + 32))->second + ((
                            TrigramWis.find(*(DWORD*)((int)Itemx + 32))->second *
                            YinYangRate[YinYangType][YinYangGrade]) / 100));
                Player.RemoveHp(TrigramHth.find(*(DWORD*)((int)Itemx + 32))->second + ((
                            TrigramHth.find(*(DWORD*)((int)Itemx + 32))->second *
                            YinYangRate[YinYangType][YinYangGrade]) / 100));

                if (Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second)
                {
                    Player.DecreaseMaxHp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][0]);
                    Player.DecreaseMaxMp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][1]);
                    Player.RemoveMaxAttack(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][2]);
                    Player.RemoveMinAttack(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][2]);
                    Player.RemoveStr(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][3]);
                    Player.RemoveAgi(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][4]);
                    Player.RemoveInt(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][5]);
                    Player.RemoveWis(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                            int)Itemx + 32))->second - 1)][6]);
                    Player.RemoveHp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second
                                - 1)][7]);
                }
            }

            if (Item.CheckIndex() >= 2986 && Item.CheckIndex() <= 3009)
            {
                int GetCurrentGrade = (GetItemStat.find(Item.GetIID())->second % 10000) / 100;

                if (TrigramGrade.count(*(DWORD*)((int)Itemx + 32))
                    && GetCurrentGrade == TrigramGrade.find(*(DWORD*)((int)Itemx + 32))->second)
                    TrigramGrade[*(DWORD*)((int)Itemx + 32)] = GetLowestTrigramGrade(
                            Player.GetPID());

                if (Item.CheckIndex() == 2986) {
                    TrigramHP[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2994) {
                    TrigramHP[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3002) {
                    TrigramHP[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2987) {
                    TrigramMP[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2995) {
                    TrigramMP[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3003) {
                    TrigramMP[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2988) {
                    TrigramAtk[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2996) {
                    TrigramAtk[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3004) {
                    TrigramAtk[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2989) {
                    TrigramStr[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2997) {
                    TrigramStr[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3005) {
                    TrigramStr[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2990) {
                    TrigramAgi[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2998) {
                    TrigramAgi[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3006) {
                    TrigramAgi[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2991) {
                    TrigramInt[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2999) {
                    TrigramInt[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3007) {
                    TrigramInt[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2992) {
                    TrigramWis[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3000) {
                    TrigramWis[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3008) {
                    TrigramWis[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 2993) {
                    TrigramHth[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3001) {
                    TrigramHth[*(DWORD*)((int)Itemx + 32)] = 0;
                }

                if (Item.CheckIndex() == 3009) {
                    TrigramHth[*(DWORD*)((int)Itemx + 32)] = 0;
                }
            }

            if (PetTime.count(Item.CheckIndex()) || (Item.CheckIndex() >= 1747
                    && Item.CheckIndex() <= 1762) || (Item.CheckIndex() >= 1870
                    && Item.CheckIndex() <= 1877) || (Item.CheckIndex() >= 2004
                    && Item.CheckIndex() <= 2007) || (Item.CheckIndex() >= 2421
                    && Item.CheckIndex() <= 2423) || (Item.CheckIndex() >= 2550
                    && Item.CheckIndex() <= 2653) || (Item.CheckIndex() >= 6045
                    && Item.CheckIndex() <= 6052))
            {
                PlayerPet[Player.GetPID()].Owner = 0;
                PlayerPet[Player.GetPID()].IID = 0;
                CPlayer::Write(Player.GetOffset(), 0xFF, "dd", 221, 0);
            }

            return CItemOrnament::PutOff(Itemx, Playerx);
        }
    } else {
        return 0;
    }
}

int __fastcall OrnamentApplySpec(void *Itemx, void *edx, int Playerx)
{
    IItem Item(Itemx);
    IChar Player((void*)Playerx);

    if (Player.IsOnline())
    {
        if (Item.CheckIndex() >= 3381 && Item.CheckIndex() <= 3383
            && !CheckHaninMirror.find(Player.GetPID())->second) {
            CheckHaninMirror[Player.GetPID()] = Item.GetIID();
        }

        if (Item.CheckIndex() >= 3384 && Item.CheckIndex() <= 3386
            && CheckHaninMirror.find(Player.GetPID())->second)
        {
            int Recheck = 0, Check = 0, Value = 0, Itemy = 0;
            Undefined::CreateMonsterValue((char*)Playerx + 1068, (int)&Value,
                (int)&CheckHaninMirror.find(Player.GetPID())->second);
            Check = Undefined::Check((int)((char*)Playerx + 1068), (int)&Recheck);

            if (!Undefined::CheckValues(&Value, Check)) {
                return 0;
            }

            Itemy = *(DWORD*)(Undefined::GetValue(&Value) + 4);
            IItem Mirror((void*)Itemy);
            int Valuex = 0, Type = 0;
            double Stat = 0;
            Valuex = GetItemStat.find(Item.GetIID())->second;
            Type = Valuex % 100;
            Stat = Valuex / 10000;

            int Str = Player.GetStr(), Wis = Player.GetWis(), Hth = Player.GetHth(),
                Int = Player.GetInt(), Agi = Player.GetAgi();
            int Otp = (15 * Str / 54), MinPAtk = (11 * Str - 80) / 30,
                MaxPAtk = (8 * Str - 25) / 15,
                Eva = Agi / 3, HpPoint = ((2 * Hth * Hth) / 100);
            int MpPoint = ((Wis + 2 * Wis * Wis) / 100),
                MinMAtk = ((7 * Int - 20) / 12) + (Wis / 7),
                MaxMAtk = (7 * Int / 12) + (14 * Wis / 45);

            if (Stat && Mirror.CheckIndex() == 3381)
            {
                if (Type == 0) {
                    Player.AddStr(((Str * Stat) / 100) + 0.5);
                }

                if (Type == 1) {
                    Player.AddWis(((Wis * Stat) / 100) + 0.5);
                }

                if (Type == 2) {
                    Player.AddInt(((Int * Stat) / 100) + 0.5);
                }

                if (Type == 3) {
                    Player.AddHp(((Hth * Stat) / 100) + 0.5);
                }

                if (Type == 4) {
                    Player.AddAgi(((Agi * Stat) / 100) + 0.5);
                }

                if (Type == 5) {
                    Player.AddOTP(((Otp * Stat) / 100) + 0.5);
                }

                if (Type == 6) {
                    Player.AddEva(((Eva * Stat) / 100) + 0.5);
                }

                if (Type == 7) {
                    Player.AddDef(Stat + 0.5);
                }

                if (Type == 10) {
                    Player.IncreaseMaxHp(((HpPoint * Stat) / 100) + 0.5);
                }

                if (Type == 11) {
                    Player.IncreaseMaxMp(((MpPoint * Stat) / 100) + 0.5);
                }

                if (Type == 12 && !Player.IsBuff(418)) {
                    Player.IncreaseMovingSpeed((3 * Stat) + 0.5);
                }

                if (Type == 12) {
                    Player.Buff(418, 1296000, 0);
                }

                if (Type == 13) {
                    Player.AddMinAttack(((MinPAtk * Stat) / 100) + 0.5);
                }

                if (Type == 14) {
                    Player.AddMaxAttack(((MaxPAtk * Stat) / 100) + 0.5);
                }

                if (Type == 15) {
                    Player.IncreaseCritRate((Stat / 3) + 0.5);
                }

                if (Type == 16) {
                    Player.IncreaseCritDamage((Stat / 2) + 0.5);
                }

                if (Type == 18) {
                    Player.AddMinAttack(((MinMAtk * Stat) / 100) + 0.5);
                }

                if (Type == 19) {
                    Player.AddMaxAttack(((MaxMAtk * Stat) / 100) + 0.5);
                }

                if (Type == 20) {
                    Player.Buff(298, 1296000, 0);
                }

                if (Type == 21) {
                    Player.Buff(330, 1296000, 0);
                }
            }

            if (Stat && Mirror.CheckIndex() == 3382)
            {
                if (Type == 0) {
                    Player.AddStr(((Str * Stat) / 90) + 0.5);
                }

                if (Type == 1) {
                    Player.AddWis(((Wis * Stat) / 90) + 0.5);
                }

                if (Type == 2) {
                    Player.AddInt(((Int * Stat) / 90) + 0.5);
                }

                if (Type == 3) {
                    Player.AddHp(((Hth * Stat) / 90) + 0.5);
                }

                if (Type == 4) {
                    Player.AddAgi(((Agi * Stat) / 90) + 0.5);
                }

                if (Type == 5) {
                    Player.AddOTP(((Otp * Stat) / 90) + 0.5);
                }

                if (Type == 6) {
                    Player.AddEva(((Eva * Stat) / 90) + 0.5);
                }

                if (Type == 7) {
                    Player.AddDef(Stat + 1.5);
                }

                if (Type == 10) {
                    Player.IncreaseMaxHp(((HpPoint * Stat) / 90) + 0.5);
                }

                if (Type == 11) {
                    Player.IncreaseMaxMp(((MpPoint * Stat) / 90) + 0.5);
                }

                if (Type == 12 && !Player.IsBuff(418)) {
                    Player.IncreaseMovingSpeed((3 * Stat) + 1.5);
                }

                if (Type == 12) {
                    Player.Buff(418, 1296000, 0);
                }

                if (Type == 13) {
                    Player.AddMinAttack(((MinPAtk * Stat) / 90) + 0.5);
                }

                if (Type == 14) {
                    Player.AddMaxAttack(((MaxPAtk * Stat) / 90) + 0.5);
                }

                if (Type == 15) {
                    Player.IncreaseCritRate((Stat / 3) + 1.5);
                }

                if (Type == 16) {
                    Player.IncreaseCritDamage((Stat / 2) + 1.5);
                }

                if (Type == 18) {
                    Player.AddMinAttack(((MinMAtk * Stat) / 90) + 0.5);
                }

                if (Type == 19) {
                    Player.AddMaxAttack(((MaxMAtk * Stat) / 90) + 0.5);
                }

                if (Type == 20) {
                    Player.Buff(298, 1296000, 0);
                }

                if (Type == 21) {
                    Player.Buff(330, 1296000, 0);
                }
            }

            if (Stat && Mirror.CheckIndex() == 3383)
            {
                if (Type == 0) {
                    Player.AddStr(((Str * Stat) / 80) + 0.5);
                }

                if (Type == 1) {
                    Player.AddWis(((Wis * Stat) / 80) + 0.5);
                }

                if (Type == 2) {
                    Player.AddInt(((Int * Stat) / 80) + 0.5);
                }

                if (Type == 3) {
                    Player.AddHp(((Hth * Stat) / 80) + 0.5);
                }

                if (Type == 4) {
                    Player.AddAgi(((Agi * Stat) / 80) + 0.5);
                }

                if (Type == 5) {
                    Player.AddOTP(((Otp * Stat) / 80) + 0.5);
                }

                if (Type == 6) {
                    Player.AddEva(((Eva * Stat) / 80) + 0.5);
                }

                if (Type == 7) {
                    Player.AddDef(Stat + 2.5);
                }

                if (Type == 10) {
                    Player.IncreaseMaxHp(((HpPoint * Stat) / 80) + 0.5);
                }

                if (Type == 11) {
                    Player.IncreaseMaxMp(((MpPoint * Stat) / 80) + 0.5);
                }

                if (Type == 12 && !Player.IsBuff(418)) {
                    Player.IncreaseMovingSpeed((3 * Stat) + 2.5);
                }

                if (Type == 12) {
                    Player.Buff(418, 1296000, 0);
                }

                if (Type == 13) {
                    Player.AddMinAttack(((MinPAtk * Stat) / 80) + 0.5);
                }

                if (Type == 14) {
                    Player.AddMaxAttack(((MaxPAtk * Stat) / 80) + 0.5);
                }

                if (Type == 15) {
                    Player.IncreaseCritRate((Stat / 3) + 2.5);
                }

                if (Type == 16) {
                    Player.IncreaseCritDamage((Stat / 2) + 2.5);
                }

                if (Type == 18) {
                    Player.AddMinAttack(((MinMAtk * Stat) / 80) + 0.5);
                }

                if (Type == 19) {
                    Player.AddMaxAttack(((MaxMAtk * Stat) / 80) + 0.5);
                }

                if (Type == 20) {
                    Player.Buff(298, 1296000, 0);
                }

                if (Type == 21) {
                    Player.Buff(330, 1296000, 0);
                }
            }
        }

        if (Item.CheckIndex() >= 3018 && Item.CheckIndex() <= 3020
            && !Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second)
        {
            int GetTaegeukPrefix = GetItemStat.find(Item.GetIID())->second / 1000;

            if (GetTaegeukPrefix) {
                Taegeuk[*(DWORD*)((int)Itemx + 32)] = GetTaegeukPrefix;
            }

            if (Player.IsBuff(311) && Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second)
            {
                Player.IncreaseMaxHp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                        int)Itemx + 32))->second - 1)][0]);
                Player.IncreaseMaxMp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                        int)Itemx + 32))->second - 1)][1]);
                Player.AddMaxAttack(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                        int)Itemx + 32))->second - 1)][2]);
                Player.AddMinAttack(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                        int)Itemx + 32))->second - 1)][2]);
                Player.AddStr(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][3]);
                Player.AddAgi(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][4]);
                Player.AddInt(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][5]);
                Player.AddWis(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][6]);
                Player.AddHp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][7]);
            }
        }

        if (Item.CheckIndex() >= 2946 && Item.CheckIndex() <= 2948
            && TrigramHP.find(*(DWORD*)((int)Itemx + 32))->second
            && TrigramMP.find(*(DWORD*)((int)Itemx + 32))->second
            && TrigramAtk.find(*(DWORD*)((int)Itemx + 32))->second
            && TrigramStr.find(*(DWORD*)((int)Itemx + 32))->second
            && TrigramAgi.find(*(DWORD*)((int)Itemx + 32))->second
            && TrigramInt.find(*(DWORD*)((int)Itemx + 32))->second
            && TrigramWis.find(*(DWORD*)((int)Itemx + 32))->second
            && TrigramHth.find(*(DWORD*)((int)Itemx + 32))->second)
        {
            int YinYangType = 0;

            if (Item.CheckIndex() == 2947) {
                YinYangType = 1;
            }

            if (Item.CheckIndex() == 2948) {
                YinYangType = 2;
            }

            Player.Buff(311, 604800, 0);
            int YinYangGrade = TrigramGrade.find(*(DWORD*)((int)Itemx + 32))->second;
            Player.IncreaseMaxHp(TrigramHP.find(*(DWORD*)((int)Itemx + 32))->second + ((
                        TrigramHP.find(*(DWORD*)((int)Itemx + 32))->second *
                        YinYangRate[YinYangType][YinYangGrade]) / 100));
            Player.IncreaseMaxMp(TrigramMP.find(*(DWORD*)((int)Itemx + 32))->second + ((
                        TrigramMP.find(*(DWORD*)((int)Itemx + 32))->second *
                        YinYangRate[YinYangType][YinYangGrade]) / 100));
            Player.AddMaxAttack(TrigramAtk.find(*(DWORD*)((int)Itemx + 32))->second + ((
                        TrigramAtk.find(*(DWORD*)((int)Itemx + 32))->second *
                        YinYangRate[YinYangType][YinYangGrade]) / 100));
            Player.AddMinAttack(TrigramAtk.find(*(DWORD*)((int)Itemx + 32))->second + ((
                        TrigramAtk.find(*(DWORD*)((int)Itemx + 32))->second *
                        YinYangRate[YinYangType][YinYangGrade]) / 100));
            Player.AddStr(TrigramStr.find(*(DWORD*)((int)Itemx + 32))->second + ((
                        TrigramStr.find(*(DWORD*)((int)Itemx + 32))->second *
                        YinYangRate[YinYangType][YinYangGrade]) / 100));
            Player.AddAgi(TrigramAgi.find(*(DWORD*)((int)Itemx + 32))->second + ((
                        TrigramAgi.find(*(DWORD*)((int)Itemx + 32))->second *
                        YinYangRate[YinYangType][YinYangGrade]) / 100));
            Player.AddInt(TrigramInt.find(*(DWORD*)((int)Itemx + 32))->second + ((
                        TrigramInt.find(*(DWORD*)((int)Itemx + 32))->second *
                        YinYangRate[YinYangType][YinYangGrade]) / 100));
            Player.AddWis(TrigramWis.find(*(DWORD*)((int)Itemx + 32))->second + ((
                        TrigramWis.find(*(DWORD*)((int)Itemx + 32))->second *
                        YinYangRate[YinYangType][YinYangGrade]) / 100));
            Player.AddHp(TrigramHth.find(*(DWORD*)((int)Itemx + 32))->second + ((
                        TrigramHth.find(*(DWORD*)((int)Itemx + 32))->second *
                        YinYangRate[YinYangType][YinYangGrade]) / 100));

            if (Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second)
            {
                Player.IncreaseMaxHp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                        int)Itemx + 32))->second - 1)][0]);
                Player.IncreaseMaxMp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                        int)Itemx + 32))->second - 1)][1]);
                Player.AddMaxAttack(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                        int)Itemx + 32))->second - 1)][2]);
                Player.AddMinAttack(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((
                                        int)Itemx + 32))->second - 1)][2]);
                Player.AddStr(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][3]);
                Player.AddAgi(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][4]);
                Player.AddInt(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][5]);
                Player.AddWis(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][6]);
                Player.AddHp(TaegeukPrefix[(Taegeuk.find(*(DWORD*)((int)Itemx + 32))->second -
                            1)][7]);
            }
        }

        if (Item.CheckIndex() >= 2986 && Item.CheckIndex() <= 3009)
        {
            int GetCurrentGrade = (GetItemStat.find(Item.GetIID())->second % 10000) / 100;

            if (TrigramGrade.count(*(DWORD*)((int)Itemx + 32))
                && GetCurrentGrade < TrigramGrade.find(*(DWORD*)((int)Itemx + 32))->second) {
                TrigramGrade[*(DWORD*)((int)Itemx + 32)] = GetCurrentGrade;
            }

            if (!TrigramGrade.count(*(DWORD*)((int)Itemx + 32))) {
                TrigramGrade[*(DWORD*)((int)Itemx + 32)] = GetCurrentGrade;
            }

            if (Item.CheckIndex() == 2986)
                TrigramHP[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[0][GetCurrentGrade];

            if (Item.CheckIndex() == 2994)
                TrigramHP[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[1][GetCurrentGrade];

            if (Item.CheckIndex() == 3002)
                TrigramHP[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[2][GetCurrentGrade];

            if (Item.CheckIndex() == 2987)
                TrigramMP[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[3][GetCurrentGrade];

            if (Item.CheckIndex() == 2995)
                TrigramMP[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[4][GetCurrentGrade];

            if (Item.CheckIndex() == 3003)
                TrigramMP[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[5][GetCurrentGrade];

            if (Item.CheckIndex() == 2988)
                TrigramAtk[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[6][GetCurrentGrade];

            if (Item.CheckIndex() == 2996)
                TrigramAtk[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[7][GetCurrentGrade];

            if (Item.CheckIndex() == 3004)
                TrigramAtk[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[8][GetCurrentGrade];

            if (Item.CheckIndex() == 2989)
                TrigramStr[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[9][GetCurrentGrade];

            if (Item.CheckIndex() == 2997)
                TrigramStr[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[10][GetCurrentGrade];

            if (Item.CheckIndex() == 3005)
                TrigramStr[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[11][GetCurrentGrade];

            if (Item.CheckIndex() == 2990)
                TrigramAgi[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[12][GetCurrentGrade];

            if (Item.CheckIndex() == 2998)
                TrigramAgi[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[13][GetCurrentGrade];

            if (Item.CheckIndex() == 3006)
                TrigramAgi[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[14][GetCurrentGrade];

            if (Item.CheckIndex() == 2991)
                TrigramInt[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[15][GetCurrentGrade];

            if (Item.CheckIndex() == 2999)
                TrigramInt[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[16][GetCurrentGrade];

            if (Item.CheckIndex() == 3007)
                TrigramInt[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[17][GetCurrentGrade];

            if (Item.CheckIndex() == 2992)
                TrigramWis[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[18][GetCurrentGrade];

            if (Item.CheckIndex() == 3000)
                TrigramWis[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[19][GetCurrentGrade];

            if (Item.CheckIndex() == 3008)
                TrigramWis[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[20][GetCurrentGrade];

            if (Item.CheckIndex() == 2993)
                TrigramHth[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[21][GetCurrentGrade];

            if (Item.CheckIndex() == 3001)
                TrigramHth[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[22][GetCurrentGrade];

            if (Item.CheckIndex() == 3009)
                TrigramHth[*(DWORD*)((int)Itemx + 32)] =
                    TriagramStats[23][GetCurrentGrade];
        }

        if (PetTime.count(Item.CheckIndex()) || (Item.CheckIndex() >= 1747
                && Item.CheckIndex() <= 1762) || (Item.CheckIndex() >= 1870
                && Item.CheckIndex() <= 1877) || (Item.CheckIndex() >= 2004
                && Item.CheckIndex() <= 2007) || (Item.CheckIndex() >= 2421
                && Item.CheckIndex() <= 2423) || (Item.CheckIndex() >= 2550
                && Item.CheckIndex() <= 2653) || (Item.CheckIndex() >= 6045
                && Item.CheckIndex() <= 6052))
        {
            if (Item.CheckIndex() >= 2004 && Item.CheckIndex() <= 2007)
                CPlayer::Write(Player.GetOffset(), 221, "dwdb", Player.GetID(),
                    Item.CheckIndex(),
                    Item.GetIID(), 2);
            else
                CPlayer::Write(Player.GetOffset(), 221, "dwdb", Player.GetID(),
                    Item.CheckIndex(),
                    Item.GetIID(), 0);

            PlayerPet[Player.GetPID()].Owner = Item.CheckIndex();
            PlayerPet[Player.GetPID()].IID = Item.GetIID();
            CPlayer::Write(Player.GetOffset(), 0xFF, "dd", 221,
                PetTime.find(Item.CheckIndex())->second.Pick);
        }

        return CItemOrnament::ApplySpec(Itemx, Playerx);
    } else {
        return 0;
    }
}

int __fastcall ItemOnTimer(int Item, void *edx, int Argument)
{
    IItem IItem((void*)Item);

    if (!CBase::IsDeleted(Item) && (PetTime.count(IItem.CheckIndex())
            || (IItem.CheckIndex() >= 1747 && IItem.CheckIndex() <= 1762)
            || (IItem.CheckIndex() >= 1870 && IItem.CheckIndex() <= 1877)
            || (IItem.CheckIndex() >= 2004 && IItem.CheckIndex() <= 2007)
            || (IItem.CheckIndex() >= 2421 && IItem.CheckIndex() <= 2423)
            || (IItem.CheckIndex() >= 2550 && IItem.CheckIndex() <= 2653)
            || (IItem.CheckIndex() >= 6045 && IItem.CheckIndex() <= 6052)))
    {
        IChar IPlayer((void*)PetLifeCheck.find(IItem.GetIID())->second.Player);

        if (!CBase::IsDeleted(Item) && IPlayer.IsOnline()
            && PetLifeCheck.count(IItem.GetIID())
            && (int)time(0) + 3 >= PetLifeCheck.find(IItem.GetIID())->second.Time)
        {
            *(DWORD*)(Item + 68) = 0;
            int MyItem = IItem.GetItemPointerFromIID(IPlayer.GetOffset(), IItem.GetIID());

            if (MyItem && MyItem == Item)
            {
                if (CItem::IsState(Item, 1)) {
                    OrnamentPutOff((void*)Item, 0, (int)IPlayer.GetOffset());
                }

                PetLifeCheck.erase(IItem.GetIID());
                CItem::RemoveItem(IPlayer.GetOffset(), Item);
                IPlayer.BoxMsg("Your pet is vanished since the usage period has been expired.");
            }

            return 0;
        }
    }

    if (!CBase::IsDeleted(Item))
    {
        IChar IPlayer((void*)PetLifeCheck.find(IItem.GetIID())->second.Player);

        if (!CBase::IsDeleted(Item) && IPlayer.IsOnline()
            && PetLifeCheck.count(IItem.GetIID())
            && (int)time(0) >= PetLifeCheck.find(IItem.GetIID())->second.Time)
        {
            *(DWORD*)(Item + 68) = 0;
            int MyItem = IItem.GetItemPointerFromIID(IPlayer.GetOffset(), IItem.GetIID());

            if (MyItem && MyItem == Item)
            {
                if (CItem::IsState(Item, 1)) {
                    OrnamentPutOff((void*)Item, 0, (int)IPlayer.GetOffset());
                }

                PetLifeCheck.erase(IItem.GetIID());
                CItem::RemoveItem(IPlayer.GetOffset(), Item);
                IPlayer.BoxMsg("Your item is vanished since the usage period has been expired.");
            }

            return 0;
        }
    }

    return CItem::OnTimer(Item, Argument);
}

signed int __fastcall OrnamentChangePrefix(void *Item, void* _edx, int Player,
    int ID, int Chance, int Argument)
{
    IChar IPlayer((void*)Player);
    IItem IItem(Item);
    int CurrentPrefix = 0, NewPrefix = 0, AddPrefix = 0;

    if (!IPlayer.IsValid()) {
        return 0;
    }

    if (IItem.GetInfo() & 4194304)
    {
        IPlayer.BoxMsg("Item is locked.");
        return 0;
    }

    if (CItem::IsState((int)IItem.GetOffset(), 1) || ID >= 0 && ID != 2) {
        return 0;
    }

    if (IItem.Prefix()) {
        CurrentPrefix = IItem.PrefixID();
    }

    NewPrefix = CurrentPrefix;
    int Rate = CTools::Rate(1, 100);

    for (signed int i = 0; i < 2; ++i)
    {
        if (Rate <= (int) * (DWORD*)(Chance + 4 * i))
        {
            NewPrefix = *(DWORD *)(Argument + 4 * i);
            break;
        }
    }

    if (CurrentPrefix == NewPrefix)
    {
        CPlayer::Write(IPlayer.GetOffset(), 67, "b", 54);
    } else {
        if (WeaponReplace.count(IItem.CheckIndex())
            && WeaponReplaceIndex.count(IItem.CheckIndex()))
        {
            if (WeaponReplace.find(IItem.CheckIndex())->second
                && WeaponReplace.find(IItem.CheckIndex())->second == NewPrefix)
            {
                if (WeaponReplaceIndex.find(IItem.CheckIndex())->second)
                {
                    if (CBase::IsDeleted((int)Item)) {
                        return 0;
                    }

                    if (IPlayer.IsBuff(328)) {
                        return 0;
                    }
                    else {
                        IPlayer.Buff(328, 3, 0);
                    }

                    int ReplacePrefix = 0, ReplaceItem = 0, ReplaceInfo = 0;

                    if (*(DWORD *)((int)Item + 44)) {
                        ReplacePrefix = *(DWORD *)(*(DWORD *)((int)Item + 44) + 32);
                    }

                    if (*(DWORD *)((int)Item + 48)) {
                        ReplaceInfo = *(DWORD *)((int)Item + 48);
                    }

                    int ItemNewIndex = IItem.CheckIndex();
                    int DeleteCheck = (*(int (__thiscall **)(DWORD, void *, signed int,
                                    signed int))(*(DWORD*)Item + 120))((int)Item, IPlayer.GetOffset(), 9, -1);

                    if (!DeleteCheck)
                    {
                        ReplaceItem = CItem::CreateItem(WeaponReplaceIndex.find(ItemNewIndex)->second,
                                ReplacePrefix, 1, -1);

                        if (ReplaceItem)
                        {
                            CIOObject::AddRef(ReplaceItem);
                            *(DWORD *)(ReplaceItem + 48) = ReplaceInfo;

                            if (CPlayer::_InsertItem(IPlayer.GetOffset(), 27, ReplaceItem) != 1)
                            {
                                CConsole::Red("Real time ornament insert item Null error [PID (%d)] ",
                                    IPlayer.GetPID());
                                CBase::Delete((void *)ReplaceItem);
                                CIOCriticalSection::Leave((void*)((char *)IPlayer.GetOffset() + 1020));
                                return 0;
                            }

                            CIOObject::Release((void *)ReplaceItem);
                            CDBSocket::Write(21, "dddbb", *(DWORD *)(ReplaceItem + 36),
                                *(DWORD *)(ReplaceItem + 32), *(DWORD *)(ReplaceItem + 48), 8, 7);
                            CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, 0, 0, 128, 255);
                        }
                    } else {
                        return 0;
                    }

                    return 1;
                }
            }
        }

        if (WeaponReplacePrefix.count(NewPrefix))
        {
            IPlayer.BoxMsg("Enchanting item and the talisman are different.");
            return 0;
        }

        AddPrefix = CItem::FindPrefix(NewPrefix);

        if (!AddPrefix) {
            return 0;
        }

        *(DWORD *)((int)IItem.GetOffset() + 44) = AddPrefix;
        CDBSocket::Write(19, "ddbb", IItem.GetIID(), IPlayer.GetID(), NewPrefix);
        CItem::SendItemInfo(IItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
    }

    return 1;
}

int __fastcall OrnamentSetWearState(int Item, void *edx, int Player)
{
    IItem IItem((void*)Item);
    IChar IPlayer((void*)Player);

    if (IItem.CheckIndex() >= 3381 && IItem.CheckIndex() <= 3383
        && IItem.GetInfo() & 1) {
        CheckHaninMirror[IPlayer.GetPID()] = IItem.GetIID();
    }

    if (IItem.CheckIndex() >= 3384 && IItem.CheckIndex() <= 3386
        && IItem.GetInfo() & 1)
    {
        if (!CheckEssense1.find(IPlayer.GetPID())->second)
        {
            CheckEssense1[IPlayer.GetPID()] = IItem.GetIID();
            *(DWORD*)(*(DWORD*)(Item + 40) + 72) = -95;
        } else if (!CheckEssense2.find(IPlayer.GetPID())->second) {
            CheckEssense2[IPlayer.GetPID()] = IItem.GetIID();
            *(DWORD*)(*(DWORD*)(Item + 40) + 72) = -96;
        } else if (!CheckEssense3.find(IPlayer.GetPID())->second) {
            CheckEssense3[IPlayer.GetPID()] = IItem.GetIID();
            *(DWORD*)(*(DWORD*)(Item + 40) + 72) = -97;
        } else if (!CheckEssense4.find(IPlayer.GetPID())->second) {
            CheckEssense4[IPlayer.GetPID()] = IItem.GetIID();
            *(DWORD*)(*(DWORD*)(Item + 40) + 72) = -98;
        } else if (!CheckEssense5.find(IPlayer.GetPID())->second) {
            CheckEssense5[IPlayer.GetPID()] = IItem.GetIID();
            *(DWORD*)(*(DWORD*)(Item + 40) + 72) = -99;
        }
    }

    return CItemOrnament::SetWearState(Item, Player);
}
