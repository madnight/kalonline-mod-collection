void __fastcall Packet(__int32 Player, void *edx, int packet, void *pPacket,
    int pPos)
{
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline())
    {
        if ((packet == 31 || packet == 61) && IPlayer.IsBuff(349)) {
            return;
        }

        if (packet == 167 || packet == 177) {
            return;
        }

        if (packet == 188)
        {
            char Type = 0;
            int Value = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "bd", &Type, &Value);

            if (Type == -13 || Type == -12 || Type == -11)
            {
                int JewelCheck = CPlayer::FindItem(IPlayer.GetOffset(), 3360, 39);

                if (JewelCheck)
                {
                    CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3360, 39);

                    if (IPlayer.IsBuff(172) && IPlayer.IsBuff(173) && IPlayer.IsBuff(174))
                    {
                        IPlayer.SystemMessage("You cannot add more the inventory slot(s).",
                            TEXTCOLOR_RED);
                        return;
                    }

                    if (!IPlayer.IsBuff(172) && !IPlayer.IsBuff(173) && !IPlayer.IsBuff(174))
                    {
                        IPlayer.Buff(174, 2592000, 0);
                        CPlayer::Write(IPlayer.GetOffset(), 204, "d", 36);
                        CPlayer::Write(IPlayer.GetOffset(), 181, "dwd", IPlayer.GetID(), 499, 2592000);
                        return;
                    }

                    if (!IPlayer.IsBuff(172) && !IPlayer.IsBuff(173) && IPlayer.IsBuff(174))
                    {
                        IPlayer.Buff(173, 2592000, 0);
                        CPlayer::Write(IPlayer.GetOffset(), 204, "d", 72);
                        CPlayer::Write(IPlayer.GetOffset(), 181, "dwd", IPlayer.GetID(), 500, 2592000);
                        return;
                    }

                    if (!IPlayer.IsBuff(172) && IPlayer.IsBuff(173) && IPlayer.IsBuff(174))
                    {
                        IPlayer.Buff(172, 2592000, 0);
                        CPlayer::Write(IPlayer.GetOffset(), 204, "d", 108);
                        CPlayer::Write(IPlayer.GetOffset(), 181, "dwd", IPlayer.GetID(), 501, 2592000);
                        return;
                    }
                } else {
                    IPlayer.SystemMessage("You can not extend the period because there are not enough jewels.",
                        TEXTCOLOR_RED);
                    return;
                }
            }

            return;
        }

        if (packet == 19)
        {
            if (CheckHaninMirror.find(IPlayer.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Item = 0;
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value,
                    (int)&CheckHaninMirror.find(IPlayer.GetPID())->second);
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (Undefined::CheckValues(&Value, Check))
                {
                    Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                    IItem Mirror((void*)Item);
                    *(DWORD*)((int)Mirror.GetOffset() + 48) = 0;
                    CItem::SendItemInfo(Mirror.GetOffset(), (int)IPlayer.GetOffset(), 92);
                    CPlayer::Write(IPlayer.GetOffset(), 6, "ddw", IPlayer.GetID(), Mirror.GetIID(),
                        Mirror.CheckIndex());
                }
            }

            if (CheckEssense1.find(IPlayer.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Item = 0;
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value,
                    (int)&CheckEssense1.find(IPlayer.GetPID())->second);
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (Undefined::CheckValues(&Value, Check))
                {
                    Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                    IItem Essense1((void*)Item);
                    *(DWORD*)((int)Essense1.GetOffset() + 48) = 0;
                    CItem::SendItemInfo(Essense1.GetOffset(), (int)IPlayer.GetOffset(), 92);
                    CPlayer::Write(IPlayer.GetOffset(), 6, "ddw", IPlayer.GetID(),
                        Essense1.GetIID(),
                        Essense1.CheckIndex());
                }
            }

            if (CheckEssense2.find(IPlayer.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Item = 0;
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value,
                    (int)&CheckEssense2.find(IPlayer.GetPID())->second);
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (Undefined::CheckValues(&Value, Check))
                {
                    Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                    IItem Essense2((void*)Item);
                    *(DWORD*)((int)Essense2.GetOffset() + 48) = 0;
                    CItem::SendItemInfo(Essense2.GetOffset(), (int)IPlayer.GetOffset(), 92);
                    CPlayer::Write(IPlayer.GetOffset(), 6, "ddw", IPlayer.GetID(),
                        Essense2.GetIID(),
                        Essense2.CheckIndex());
                }
            }

            if (CheckEssense3.find(IPlayer.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Item = 0;
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value,
                    (int)&CheckEssense3.find(IPlayer.GetPID())->second);
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (Undefined::CheckValues(&Value, Check))
                {
                    Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                    IItem Essense3((void*)Item);
                    *(DWORD*)((int)Essense3.GetOffset() + 48) = 0;
                    CItem::SendItemInfo(Essense3.GetOffset(), (int)IPlayer.GetOffset(), 92);
                    CPlayer::Write(IPlayer.GetOffset(), 6, "ddw", IPlayer.GetID(),
                        Essense3.GetIID(),
                        Essense3.CheckIndex());
                }
            }

            if (CheckEssense4.find(IPlayer.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Item = 0;
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value,
                    (int)&CheckEssense4.find(IPlayer.GetPID())->second);
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (Undefined::CheckValues(&Value, Check))
                {
                    Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                    IItem Essense4((void*)Item);
                    *(DWORD*)((int)Essense4.GetOffset() + 48) = 0;
                    CItem::SendItemInfo(Essense4.GetOffset(), (int)IPlayer.GetOffset(), 92);
                    CPlayer::Write(IPlayer.GetOffset(), 6, "ddw", IPlayer.GetID(),
                        Essense4.GetIID(),
                        Essense4.CheckIndex());
                }
            }

            if (CheckEssense5.find(IPlayer.GetPID())->second)
            {
                int Recheck = 0, Check = 0, Value = 0, Item = 0;
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value,
                    (int)&CheckEssense5.find(IPlayer.GetPID())->second);
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (Undefined::CheckValues(&Value, Check))
                {
                    Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                    IItem Essense5((void*)Item);
                    *(DWORD*)((int)Essense5.GetOffset() + 48) = 0;
                    CItem::SendItemInfo(Essense5.GetOffset(), (int)IPlayer.GetOffset(), 92);
                    CPlayer::Write(IPlayer.GetOffset(), 6, "ddw", IPlayer.GetID(),
                        Essense5.GetIID(),
                        Essense5.CheckIndex());
                }
            }
        }

        if (packet == 187)
        {
            char Type = 0, Jewel = 0, Amount = 0;
            int IID = 0, xIIDx = 0;
            unsigned short Class = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "bddbwb", &Type, &IID, &xIIDx,
                &Jewel, &Class, &Amount);
            int Recheck = 0, Check = 0, Value = 0, Item = 0;
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (IID == xIIDx) {
                return;
            }

            if (!Undefined::CheckValues(&Value, Check)) {
                return;
            }

            Item = *(DWORD *)(Undefined::GetValue(&Value) + 4);
            IItem MainItem((void*)Item);

            if (Type == 2 && MainItem.CheckIndex() == 3381
                && GetItemStat.find(IID)->second >= 2)
            {
                CPlayer::Write(IPlayer.GetOffset(), 192, "b", 8);
                return;
            }

            if (Type == 2 && MainItem.CheckIndex() == 3382
                && GetItemStat.find(IID)->second >= 3)
            {
                CPlayer::Write(IPlayer.GetOffset(), 192, "b", 8);
                return;
            }

            if (Type == 2 && GetItemStat.find(IID)->second >= 4) {
                return;
            }

            if (Type == 0 && IID && xIIDx && Class == 102)
            {
                int Recheckx = 0, Checkx = 0, Valuex = 0, Itemx = 0;
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Valuex, (int)&xIIDx);
                Checkx = Undefined::Check((int)((char *)Player + 1068), (int)&Recheckx);

                if (!Undefined::CheckValues(&Valuex, Checkx)) {
                    return;
                }

                Itemx = *(DWORD *)(Undefined::GetValue(&Valuex) + 4);
                IItem NextItem((void*)Itemx);

                if (NextItem.CheckIndex() != MainItem.CheckIndex()) {
                    return;
                }

                if (Jewel == 1 && Amount == 1)
                {
                    int JewelAmount = 1;

                    if (MainItem.CheckIndex() == 3385) {
                        JewelAmount = 10;
                    }

                    if (MainItem.CheckIndex() == 3386) {
                        JewelAmount = 50;
                    }

                    int JewelCheck = CPlayer::FindItem(IPlayer.GetOffset(), 3360, JewelAmount);

                    if (JewelCheck && CPlayer::FindItem(IPlayer.GetOffset(), 3360, JewelAmount))
                        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                            (*(DWORD*)JewelCheck + 120))((int)JewelCheck, IPlayer.GetOffset(), 9,
                                -JewelAmount);
                    else {
                        return;
                    }

                    if (!CBase::IsDeleted((int)NextItem.GetOffset()))
                        CItem::RemoveItem(
                            IPlayer.GetOffset(), (int)NextItem.GetOffset());

                    if (MainItem.CheckIndex() == 3384)
                    {
                        int Value = CTools::Rate(0, 12);
                        int Add = 50;

                        if (Value == 12) {
                            Add = CTools::Rate(10, 100);
                        }

                        CPlayer::Write(IPlayer.GetOffset(), 194, "dd", MainItem.GetIID(),
                            (GetItemStat.find(MainItem.GetIID())->second % 100));
                        CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", MainItem.GetIID(), Value, Add);
                        CPlayer::Write(IPlayer.GetOffset(), 192, "bddd", 3, MainItem.GetIID(), Value,
                            Add);
                        GetItemStat[IID] = Value + (Add * 1000);
                        CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000), IID);
                    }

                    if (MainItem.CheckIndex() == 3385)
                    {
                        int Value = CTools::Rate(0, 19);
                        int Add = CTools::Rate(50, 100);

                        if (Value == 12) {
                            Add = CTools::Rate(50, 200);
                        }

                        if (Value == 15) {
                            Add = CTools::Rate(10, 20);
                        }

                        if (Value == 16) {
                            Add = CTools::Rate(10, 20);
                        }

                        if (Value == 17) {
                            Add = CTools::Rate(10, 20);
                        }

                        CPlayer::Write(IPlayer.GetOffset(), 194, "dd", MainItem.GetIID(),
                            (GetItemStat.find(MainItem.GetIID())->second % 100));
                        CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", MainItem.GetIID(), Value, Add);
                        CPlayer::Write(IPlayer.GetOffset(), 192, "bddd", 3, MainItem.GetIID(), Value,
                            Add);
                        GetItemStat[IID] = Value + (Add * 1000);
                        CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000), IID);
                    }

                    if (MainItem.CheckIndex() == 3386)
                    {
                        int Value = CTools::Rate(0, 21);
                        int Add = CTools::Rate(100, 150);

                        if (Value == 12) {
                            Add = CTools::Rate(100, 300);
                        }

                        if (Value == 15) {
                            Add = CTools::Rate(20, 30);
                        }

                        if (Value == 16) {
                            Add = CTools::Rate(20, 30);
                        }

                        if (Value == 17) {
                            Add = CTools::Rate(20, 30);
                        }

                        if (Value == 20) {
                            Add = CTools::Rate(10, 100);
                        }

                        if (Value == 21) {
                            Add = CTools::Rate(10, 100);
                        }

                        CPlayer::Write(IPlayer.GetOffset(), 194, "dd", MainItem.GetIID(),
                            (GetItemStat.find(MainItem.GetIID())->second % 100));
                        CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", MainItem.GetIID(), Value, Add);
                        CPlayer::Write(IPlayer.GetOffset(), 192, "bddd", 3, MainItem.GetIID(), Value,
                            Add);
                        GetItemStat[IID] = Value + (Add * 1000);
                        CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000), IID);
                    }
                } else {
                    if (!CBase::IsDeleted((int)NextItem.GetOffset()))
                        CItem::RemoveItem(
                            IPlayer.GetOffset(), (int)NextItem.GetOffset());

                    int SuccessRate = CTools::Rate(1, 1000);

                    if (MainItem.CheckIndex() == 3384)
                    {
                        if (SuccessRate >= 550)
                        {
                            int Value = CTools::Rate(0, 12);
                            int Add = 50;

                            if (Value == 12) {
                                Add = CTools::Rate(10, 100);
                            }

                            CPlayer::Write(IPlayer.GetOffset(), 194, "dd", MainItem.GetIID(),
                                (GetItemStat.find(MainItem.GetIID())->second % 100));
                            CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", MainItem.GetIID(), Value, Add);
                            CPlayer::Write(IPlayer.GetOffset(), 192, "bddd", 3, MainItem.GetIID(), Value,
                                Add);
                            GetItemStat[IID] = Value + (Add * 1000);
                            CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000), IID);
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 192, "b", 4);
                        }
                    }

                    if (MainItem.CheckIndex() == 3385)
                    {
                        if (SuccessRate >= 850)
                        {
                            int Value = CTools::Rate(0, 19);
                            int Add = CTools::Rate(50, 100);

                            if (Value == 12) {
                                Add = CTools::Rate(50, 200);
                            }

                            if (Value == 15) {
                                Add = CTools::Rate(10, 20);
                            }

                            if (Value == 16) {
                                Add = CTools::Rate(10, 20);
                            }

                            if (Value == 17) {
                                Add = CTools::Rate(10, 20);
                            }

                            CPlayer::Write(IPlayer.GetOffset(), 194, "dd", MainItem.GetIID(),
                                (GetItemStat.find(MainItem.GetIID())->second % 100));
                            CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", MainItem.GetIID(), Value, Add);
                            CPlayer::Write(IPlayer.GetOffset(), 192, "bddd", 3, MainItem.GetIID(), Value,
                                Add);
                            GetItemStat[IID] = Value + (Add * 1000);
                            CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000), IID);
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 192, "b", 4);
                        }
                    }

                    if (MainItem.CheckIndex() == 3386)
                    {
                        if (SuccessRate >= 950)
                        {
                            int Value = CTools::Rate(0, 21);
                            int Add = CTools::Rate(100, 150);

                            if (Value == 12) {
                                Add = CTools::Rate(100, 300);
                            }

                            if (Value == 15) {
                                Add = CTools::Rate(20, 30);
                            }

                            if (Value == 16) {
                                Add = CTools::Rate(20, 30);
                            }

                            if (Value == 17) {
                                Add = CTools::Rate(20, 30);
                            }

                            if (Value == 20) {
                                Add = CTools::Rate(10, 100);
                            }

                            if (Value == 21) {
                                Add = CTools::Rate(10, 100);
                            }

                            CPlayer::Write(IPlayer.GetOffset(), 194, "dd", MainItem.GetIID(),
                                (GetItemStat.find(MainItem.GetIID())->second % 100));
                            CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", MainItem.GetIID(), Value, Add);
                            CPlayer::Write(IPlayer.GetOffset(), 192, "bddd", 3, MainItem.GetIID(), Value,
                                Add);
                            GetItemStat[IID] = Value + (Add * 1000);
                            CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000), IID);
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 192, "b", 4);
                        }
                    }
                }
            }

            if (Type == 1 && IID && xIIDx && Class == 103)
            {
                int Recheckx = 0, Checkx = 0, Valuex = 0, Itemx = 0;
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Valuex, (int)&xIIDx);
                Checkx = Undefined::Check((int)((char *)Player + 1068), (int)&Recheckx);

                if (!Undefined::CheckValues(&Valuex, Checkx)) {
                    return;
                }

                Itemx = *(DWORD *)(Undefined::GetValue(&Valuex) + 4);
                IItem NextItem((void*)Itemx);

                if (NextItem.CheckIndex() != MainItem.CheckIndex()) {
                    return;
                }

                if (MainItem.CheckIndex() == 3386) {
                    return;
                }

                if (NextItem.CheckIndex() == 3386) {
                    return;
                }

                if (Jewel == 1 && Amount == 1)
                {
                    int JewelAmount = 5;
                    int Index = MainItem.CheckIndex();

                    if (MainItem.CheckIndex() == 3385) {
                        JewelAmount = 10;
                    }

                    int JewelCheck = CPlayer::FindItem(IPlayer.GetOffset(), 3360, JewelAmount);

                    if (CPlayer::GetInvenSize((int)IPlayer.GetOffset()) >=
                        IPlayer.MaxInventorySize())
                    {
                        IPlayer.SystemMessage("Inventory is full.", TEXTCOLOR_PINK);
                        return;
                    }

                    if (JewelCheck && CPlayer::FindItem(IPlayer.GetOffset(), 3360, JewelAmount))
                        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                            (*(DWORD*)JewelCheck + 120))((int)JewelCheck, IPlayer.GetOffset(), 9,
                                -JewelAmount);
                    else {
                        return;
                    }

                    if (!CBase::IsDeleted((int)MainItem.GetOffset()))
                        CItem::RemoveItem(
                            IPlayer.GetOffset(), (int)MainItem.GetOffset());

                    if (!CBase::IsDeleted((int)NextItem.GetOffset()))
                        CItem::RemoveItem(
                            IPlayer.GetOffset(), (int)NextItem.GetOffset());

                    if (Index == 3384)
                    {
                        int xItem = CItem::CreateItem(3385, 0, 1, -1);

                        if (xItem)
                        {
                            IItem IItem((void*)xItem);

                            if (CPlayer::_InsertItem(IPlayer.GetOffset(), 27, xItem) != 1) {
                                return;
                            }

                            int Value = CTools::Rate(0, 19);
                            int Add = CTools::Rate(50, 100);

                            if (Value == 12) {
                                Add = CTools::Rate(50, 200);
                            }

                            if (Value == 15) {
                                Add = CTools::Rate(10, 20);
                            }

                            if (Value == 16) {
                                Add = CTools::Rate(10, 20);
                            }

                            if (Value == 17) {
                                Add = CTools::Rate(10, 20);
                            }

                            CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", IItem.GetIID(), Value, Add);
                            CPlayer::Write(IPlayer.GetOffset(), 192, "bd", 5, IItem.GetIID());
                            GetItemStat[IItem.GetIID()] = Value + (Add * 1000);
                            CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000),
                                IItem.GetIID());
                        }
                    }

                    if (Index == 3385)
                    {
                        int xItem = CItem::CreateItem(3386, 0, 1, -1);

                        if (xItem)
                        {
                            IItem IItem((void*)xItem);

                            if (CPlayer::_InsertItem(IPlayer.GetOffset(), 27, xItem) != 1) {
                                return;
                            }

                            int Value = CTools::Rate(0, 21);
                            int Add = CTools::Rate(100, 150);

                            if (Value == 12) {
                                Add = CTools::Rate(100, 300);
                            }

                            if (Value == 15) {
                                Add = CTools::Rate(20, 30);
                            }

                            if (Value == 16) {
                                Add = CTools::Rate(20, 30);
                            }

                            if (Value == 17) {
                                Add = CTools::Rate(20, 30);
                            }

                            if (Value == 20) {
                                Add = CTools::Rate(10, 100);
                            }

                            if (Value == 21) {
                                Add = CTools::Rate(10, 100);
                            }

                            CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", IItem.GetIID(), Value, Add);
                            CPlayer::Write(IPlayer.GetOffset(), 192, "bd", 5, IItem.GetIID());
                            GetItemStat[IItem.GetIID()] = Value + (Add * 1000);
                            CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000),
                                IItem.GetIID());
                        }
                    }
                } else {
                    int Index = MainItem.CheckIndex();

                    if (CPlayer::GetInvenSize((int)IPlayer.GetOffset()) >=
                        IPlayer.MaxInventorySize())
                    {
                        IPlayer.SystemMessage("Inventory is full.", TEXTCOLOR_PINK);
                        return;
                    }

                    if (!CBase::IsDeleted((int)MainItem.GetOffset()))
                        CItem::RemoveItem(
                            IPlayer.GetOffset(), (int)MainItem.GetOffset());

                    if (!CBase::IsDeleted((int)NextItem.GetOffset()))
                        CItem::RemoveItem(
                            IPlayer.GetOffset(), (int)NextItem.GetOffset());

                    int SuccessRate = CTools::Rate(1, 1000);

                    if (Index == 3384)
                    {
                        if (SuccessRate >= 850)
                        {
                            int xItem = CItem::CreateItem(3385, 0, 1, -1);

                            if (xItem)
                            {
                                IItem IItem((void*)xItem);

                                if (CPlayer::_InsertItem(IPlayer.GetOffset(), 27, xItem) != 1) {
                                    return;
                                }

                                int Value = CTools::Rate(0, 19);
                                int Add = CTools::Rate(50, 100);

                                if (Value == 12) {
                                    Add = CTools::Rate(50, 200);
                                }

                                if (Value == 15) {
                                    Add = CTools::Rate(10, 20);
                                }

                                if (Value == 16) {
                                    Add = CTools::Rate(10, 20);
                                }

                                if (Value == 17) {
                                    Add = CTools::Rate(10, 20);
                                }

                                CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", IItem.GetIID(), Value, Add);
                                CPlayer::Write(IPlayer.GetOffset(), 192, "bd", 5, IItem.GetIID());
                                GetItemStat[IItem.GetIID()] = Value + (Add * 1000);
                                CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000),
                                    IItem.GetIID());
                            }
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 192, "b", 6);
                        }
                    }

                    if (Index == 3385)
                    {
                        if (SuccessRate >= 950)
                        {
                            int xItem = CItem::CreateItem(3386, 0, 1, -1);

                            if (xItem)
                            {
                                IItem IItem((void*)xItem);

                                if (CPlayer::_InsertItem(IPlayer.GetOffset(), 27, xItem) != 1) {
                                    return;
                                }

                                int Value = CTools::Rate(0, 21);
                                int Add = CTools::Rate(100, 150);

                                if (Value == 12) {
                                    Add = CTools::Rate(100, 300);
                                }

                                if (Value == 15) {
                                    Add = CTools::Rate(20, 30);
                                }

                                if (Value == 16) {
                                    Add = CTools::Rate(20, 30);
                                }

                                if (Value == 17) {
                                    Add = CTools::Rate(20, 30);
                                }

                                if (Value == 20) {
                                    Add = CTools::Rate(10, 100);
                                }

                                if (Value == 21) {
                                    Add = CTools::Rate(10, 100);
                                }

                                CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", IItem.GetIID(), Value, Add);
                                CPlayer::Write(IPlayer.GetOffset(), 192, "bd", 5, IItem.GetIID());
                                GetItemStat[IItem.GetIID()] = Value + (Add * 1000);
                                CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value + (Add * 1000),
                                    IItem.GetIID());
                            }
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 192, "b", 6);
                        }
                    }
                }
            }

            if (Type == 2 && IID && MainItem.CheckIndex() == 3383
                && GetItemStat.find(IID)->second == 0) {
                GetItemStat[IID] = 1;
            }

            if (Type == 2 && IID && GetItemStat.find(IID)->second >= 1)
            {
                int JewelCheck = CPlayer::FindItem(IPlayer.GetOffset(), 3360,
                        GetItemStat.find(IID)->second * 60);

                if (JewelCheck
                    && CPlayer::FindItem(IPlayer.GetOffset(), 3360,
                        GetItemStat.find(IID)->second * 60))
                {
                    (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                        (*(DWORD*)JewelCheck + 120))((int)JewelCheck, IPlayer.GetOffset(), 9,
                            -(GetItemStat.find(IID)->second * 60));
                    GetItemStat[IID] = GetItemStat.find(IID)->second + 1;
                    CPlayer::Write(IPlayer.GetOffset(), 194, "dd", IID, 100);
                    CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", IID, 100,
                        GetItemStat.find(IID)->second + 1);
                    CDBSocket::Write(90, "ddd", IPlayer.GetPID(), GetItemStat.find(IID)->second,
                        IID);
                    CPlayer::Write(IPlayer.GetOffset(), 192, "b", 7);
                } else {
                    IPlayer.BoxMsg("You do not have enough jewels.");
                }
            }

            if (Type == 2 && IID && GetItemStat.find(IID)->second == 0)
            {
                if (CPlayer::FindItem(IPlayer.GetOffset(), 31, 1000000))
                {
                    if (!(*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                            (**((DWORD**)Player + 274) + 120))(*((DWORD *)Player + 274),
                            IPlayer.GetOffset(), 9, -1000000)) {
                        CPlayer::_OutOfInven(IPlayer.GetOffset(), *((DWORD *)Player + 274));
                    }

                    GetItemStat[IID] = GetItemStat.find(IID)->second + 1;
                    CPlayer::Write(IPlayer.GetOffset(), 194, "dd", IID, 100);
                    CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", IID, 100,
                        GetItemStat.find(IID)->second + 1);
                    CDBSocket::Write(90, "ddd", IPlayer.GetPID(), GetItemStat.find(IID)->second,
                        IID);
                    CPlayer::Write(IPlayer.GetOffset(), 192, "b", 7);
                } else {
                    IPlayer.BoxMsg("You do not have enough zamogeon.");
                }
            }

            return;
        }

        if (packet == 183)
        {
            char Type = 0, Value = 0;
            int BillCode = 0;
            unsigned short Amount = 0;
            const char *GiftName = "none";
            CPacket::Read((char*)pPacket, (char*)pPos, "bbdws", &Type, &Value, &BillCode,
                &Amount, &GiftName);

            if (Type == 1 && Value == 0)
                CPlayer::Write(IPlayer.GetOffset(), 186, "bbwwm", 3, 1, 1, ItemShopCheck.size(),
                    ItemShopPacket, ItemShopCheck.size() * 12);

            if (Type == 1 && Value == 1)
            {
                int Jewel = 0, GoldKC = 0, SilverKC = 0, JewelAmount = 0, GoldKCAmount = 0,
                    SilverKCAmount = 0;
                Jewel = CPlayer::FindItem(IPlayer.GetOffset(), ShopJewelIndex, 1);
                GoldKC = CPlayer::FindItem(IPlayer.GetOffset(), ShopGoldIndex, 1);
                SilverKC = CPlayer::FindItem(IPlayer.GetOffset(), ShopSilverIndex, 1);

                if (Jewel)
                {
                    IItem xJewel((void*)Jewel);
                    JewelAmount = xJewel.GetAmount();
                }

                if (GoldKC)
                {
                    IItem xGold((void*)GoldKC);
                    GoldKCAmount = xGold.GetAmount();
                }

                if (SilverKC)
                {
                    IItem xSilver((void*)SilverKC);
                    SilverKCAmount = xSilver.GetAmount();
                }

                CPlayer::Write(IPlayer.GetOffset(), 186, "b", 0);
                CPlayer::Write(IPlayer.GetOffset(), 186, "bdddd", 4, GoldKCAmount,
                    SilverKCAmount,
                    CheckHonor.find(IPlayer.GetPID())->second.RPx, JewelAmount);
            }

            if ((Type == 2 || Type == 4) && ItemShopCheck.count(BillCode)
                && ItemShopCheck.find(BillCode)->second.Priority == 4)
            {
                CPlayer::Write(IPlayer.GetOffset(), 186, "b", 11);
                return;
            }

            if (Type == 2)
            {
                if (ItemShopCheck.count(BillCode))
                {
                    const char *PlayerName = GiftName;
                    IChar Target((void*)CPlayer::FindPlayerByName((char)PlayerName));

                    if (!Target.IsOnline())
                    {
                        CPlayer::Write(IPlayer.GetOffset(), 186, "b", 18);
                        return;
                    }

                    if (Amount <= 0)
                    {
                        CPlayer::Write(IPlayer.GetOffset(), 186, "b", 17);
                        return;
                    }

                    int Price = 0;
                    Price = ItemShopCheck.find(BillCode)->second.Price * Amount;

                    if (Price <= 0)
                    {
                        CPlayer::Write(IPlayer.GetOffset(), 186, "b", 17);
                        return;
                    }

                    int Check = 2147483647 / Price;

                    if (Amount >= Check)
                    {
                        CPlayer::Write(IPlayer.GetOffset(), 186, "b", 17);
                        return;
                    }

                    if (ItemShopCheck.find(BillCode)->second.Discount)
                        Price -= ((
                                    Price * ItemShopCheck.find(BillCode)->second.Discount) / 100);

                    int Jewel = 0, GoldKC = 0, SilverKC = 0, JewelAmount = 0, GoldKCAmount = 0,
                        SilverKCAmount = 0;
                    Jewel = CPlayer::FindItem(IPlayer.GetOffset(), ShopJewelIndex, 1);
                    GoldKC = CPlayer::FindItem(IPlayer.GetOffset(), ShopGoldIndex, 1);
                    SilverKC = CPlayer::FindItem(IPlayer.GetOffset(), ShopSilverIndex, 1);
                    IItem xJewel((void*)Jewel);
                    IItem xGold((void*)GoldKC);
                    IItem xSilver((void*)SilverKC);

                    if (Jewel) {
                        JewelAmount = xJewel.GetAmount();
                    }

                    if (GoldKC) {
                        GoldKCAmount = xGold.GetAmount();
                    }

                    if (SilverKC) {
                        SilverKCAmount = xSilver.GetAmount();
                    }

                    if (ItemShopCheck.find(BillCode)->second.Type == 1)
                    {
                        if (GoldKC && GoldKCAmount > Price && Target.IsOnline() && IPlayer.IsOnline())
                        {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bdddd", 4, GoldKCAmount - Price,
                                SilverKCAmount, CheckHonor.find(IPlayer.GetPID())->second.RPx, JewelAmount);
                            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                                (*(DWORD*)(int)xGold.GetOffset() + 120))((int)xGold.GetOffset(),
                                    IPlayer.GetOffset(), 9, -Price);
                            std::string name = IPlayer.GetName();
                            std::string msg = "KalOnline Item Shop Gift From Player " + name;
                            Target.GiveReward(ItemShopCheck.find(BillCode)->second.ItemIndex, 0,
                                ItemShopCheck.find(BillCode)->second.Amount * Amount, 0, 0, 0, 0, 0, 0, 0, 0,
                                msg.c_str());
                            CPlayer::Write(IPlayer.GetOffset(), 186, "b", 16);
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "b", 17);
                        }
                    }

                    if (ItemShopCheck.find(BillCode)->second.Type == 4)
                    {
                        if (Jewel && JewelAmount > Price)
                        {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bdddd", 4, GoldKCAmount,
                                SilverKCAmount,
                                CheckHonor.find(IPlayer.GetPID())->second.RPx, JewelAmount - Price);
                            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                                (*(DWORD*)(int)xJewel.GetOffset() + 120))((int)xJewel.GetOffset(),
                                    IPlayer.GetOffset(), 9, -Price);
                            std::string name = IPlayer.GetName();
                            std::string msg = "KalOnline Item Shop Gift From Player " + name;
                            Target.GiveReward(ItemShopCheck.find(BillCode)->second.ItemIndex, 0,
                                ItemShopCheck.find(BillCode)->second.Amount * Amount, 0, 0, 0, 0, 0, 0, 0, 0,
                                msg.c_str());
                            CPlayer::Write(IPlayer.GetOffset(), 186, "b", 16);
                            CPlayer::Write(IPlayer.GetOffset(), 186, "b", 16);
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "b", 17);
                        }
                    }
                }
            }

            if (Type == 4)
            {
                if (ItemShopCheck.count(BillCode))
                {
                    if (Amount <= 0)
                    {
                        CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 6, 5);
                        return;
                    }

                    int Price = 0;
                    Price = ItemShopCheck.find(BillCode)->second.Price * Amount;

                    if (Price <= 0)
                    {
                        CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 6, 5);
                        return;
                    }

                    int Check = 2147483647 / Price;

                    if (Amount >= Check)
                    {
                        CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 6, 5);
                        return;
                    }

                    if (ItemShopCheck.find(BillCode)->second.Discount)
                        Price -= ((
                                    Price * ItemShopCheck.find(BillCode)->second.Discount) / 100);

                    int Jewel = 0, GoldKC = 0, SilverKC = 0, JewelAmount = 0, GoldKCAmount = 0,
                        SilverKCAmount = 0;
                    Jewel = CPlayer::FindItem(IPlayer.GetOffset(), ShopJewelIndex, 1);
                    GoldKC = CPlayer::FindItem(IPlayer.GetOffset(), ShopGoldIndex, 1);
                    SilverKC = CPlayer::FindItem(IPlayer.GetOffset(), ShopSilverIndex, 1);
                    IItem xJewel((void*)Jewel);
                    IItem xGold((void*)GoldKC);
                    IItem xSilver((void*)SilverKC);

                    if (Jewel) {
                        JewelAmount = xJewel.GetAmount();
                    }

                    if (GoldKC) {
                        GoldKCAmount = xGold.GetAmount();
                    }

                    if (SilverKC) {
                        SilverKCAmount = xSilver.GetAmount();
                    }

                    if (ItemShopCheck.find(BillCode)->second.Type == 1)
                    {
                        if (GoldKC && GoldKCAmount > Price)
                        {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bdddd", 4, GoldKCAmount - Price,
                                SilverKCAmount, CheckHonor.find(IPlayer.GetPID())->second.RPx, JewelAmount);
                            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                                (*(DWORD*)(int)xGold.GetOffset() + 120))((int)xGold.GetOffset(),
                                    IPlayer.GetOffset(), 9, -Price);
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27,
                                ItemShopCheck.find(BillCode)->second.ItemIndex, 0,
                                ItemShopCheck.find(BillCode)->second.Amount * Amount, -1);
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 5, 5);
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 6, 5);
                        }
                    }

                    if (ItemShopCheck.find(BillCode)->second.Type == 2)
                    {
                        if (SilverKC && SilverKCAmount > Price)
                        {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bdddd", 4, GoldKCAmount,
                                SilverKCAmount - Price, CheckHonor.find(IPlayer.GetPID())->second.RPx,
                                JewelAmount);
                            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                                (*(DWORD*)(int)xSilver.GetOffset() + 120))((int)xSilver.GetOffset(),
                                    IPlayer.GetOffset(), 9, -Price);
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27,
                                ItemShopCheck.find(BillCode)->second.ItemIndex, 0,
                                ItemShopCheck.find(BillCode)->second.Amount * Amount, -1);
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 5, 5);
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 6, 5);
                        }
                    }

                    if (ItemShopCheck.find(BillCode)->second.Type == 3)
                    {
                        if (CheckHonor.find(IPlayer.GetPID())->second.RPx
                            && CheckHonor.find(IPlayer.GetPID())->second.RPx > Price)
                        {
                            CheckHonor[IPlayer.GetPID()].RPx -= Price;
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bdddd", 4, GoldKCAmount,
                                SilverKCAmount,
                                CheckHonor.find(IPlayer.GetPID())->second.RPx, JewelAmount);
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27,
                                ItemShopCheck.find(BillCode)->second.ItemIndex, 0,
                                ItemShopCheck.find(BillCode)->second.Amount * Amount, -1);
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 5, 5);
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 6, 5);
                        }
                    }

                    if (ItemShopCheck.find(BillCode)->second.Type == 4)
                    {
                        if (Jewel && JewelAmount > Price)
                        {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bdddd", 4, GoldKCAmount,
                                SilverKCAmount,
                                CheckHonor.find(IPlayer.GetPID())->second.RPx, JewelAmount - Price);
                            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                                (*(DWORD*)(int)xJewel.GetOffset() + 120))((int)xJewel.GetOffset(),
                                    IPlayer.GetOffset(), 9, -Price);
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27,
                                ItemShopCheck.find(BillCode)->second.ItemIndex, 0,
                                ItemShopCheck.find(BillCode)->second.Amount * Amount, -1);
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 5, 4);
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 186, "bb", 6, 4);
                        }
                    }
                }
            }

            return;
        }

        if (packet == 101)
        {
            int QuestID = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "w", &QuestID);

            if (PlayerQuest.find((QuestID * 1000000000000) +
                    IPlayer.GetPID())->second.Active == 1) {
                PlayerQuest[(QuestID * 1000000000000) + IPlayer.GetPID()].Active = 0;
            }

            if (PlayerQuest.find((QuestID * 1000000000000) +
                    IPlayer.GetPID())->second.MobAmount > 0) {
                PlayerQuest[(QuestID * 1000000000000) + IPlayer.GetPID()].MobAmount = 0;
            }

            IPlayer.QuitQuest(QuestID);
            return;
        }

        if (packet == 67 && ShopLimit.count(IPlayer.GetIP())
            && ShopLimit.find(IPlayer.GetIP())->second && !IPlayer.IsBuff(297))
        {
            IPlayer.SystemMessage("Exceeded the maximum shop limit.", TEXTCOLOR_RED);
            return;
        }

        if (packet == 92)
        {
            char Type = 0;
            int Amount = 0;
            int LeftData = CPacket::Read((char*)pPacket, (char*)pPos, "bd", &Type, &Amount);

            if (Type == 12 && Amount > 0)
            {
                if (Amount > 50)
                {
                    IPlayer.SystemMessage("You can delete maximum 50 mails in a row.",
                        TEXTCOLOR_RED);
                    return;
                }

                for (int i = 0; i < Amount; i++)
                {
                    int MAILID = 0;
                    LeftData = CPacket::Read((char*)LeftData, (char*)pPos, "d", &MAILID);

                    if (MAILID > 0 && IPlayer.IsOnline()) {
                        CPlayer::Write(IPlayer.GetOffset(), 255, "dd", 223, MAILID);
                    }
                }

                return;
            }
        }

        if (packet == 54)
        {
            char Type = 0;
            int Key = 0, Rate = CTools::Rate(1, 1000);
            CPacket::Read((char*)pPacket, (char*)pPos, "bd", &Type, &Key);

            if (Type == 1 && Key)
            {
                if (CPlayer::GetInvenSize(Player) >= IPlayer.MaxInventorySize())
                {
                    IPlayer.BoxMsg("Your inventory is full.");
                    return;
                }

                if (Key == 1205 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 11000000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 400)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2663, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2668, 80)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2666, 15)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2672, 10)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2675, 6))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2705, 0, 1, -1);
                    return;
                }

                if (Key == 1204 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 11000000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2671, 300)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2663, 130)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2668, 85)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2665, 25)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2669, 25)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2675, 6))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2704, 0, 1, -1);
                    return;
                }

                if (Key == 1203 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 11000000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2656, 350)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2664, 60)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2667, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2666, 12)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2669, 30)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2675, 6))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2703, 0, 1, -1);
                    return;
                }

                if (Key == 1202 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 11000000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 400)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2658, 30)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2661, 100)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2666, 15)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2672, 12)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2675, 6))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2702, 0, 1, -1);
                    return;
                }

                if (Key == 1201 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 11000000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2659, 400)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2657, 120)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2662, 38)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2666, 12)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2669, 12)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2675, 6))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2701, 0, 1, -1);
                    return;
                }

                if (Key == 1200 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 11000000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2660, 350)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2658, 35)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2667, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2665, 28)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2672, 15)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2675, 6))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2700, 0, 1, -1);
                    return;
                }

                if (Key == 1105 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 4400000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2671, 240)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2657, 100)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2664, 50)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2665, 20)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2674, 4))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2693, 0, 1, -1);
                    return;
                }

                if (Key == 1104 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 4400000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 300)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2663, 120)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2667, 120)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2669, 20)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2674, 4))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2692, 0, 1, -1);
                    return;
                }

                if (Key == 1103 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 4400000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2671, 240)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2664, 50)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2667, 120)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2672, 15)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2674, 4))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2691, 0, 1, -1);
                    return;
                }

                if (Key == 1102 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 4400000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2659, 300)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2658, 25)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2668, 40)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2666, 10)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2674, 4))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2690, 0, 1, -1);
                    return;
                }

                if (Key == 1101 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 4400000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2656, 200)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2664, 50)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2661, 70)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2666, 10)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2674, 4))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2689, 0, 1, -1);
                    return;
                }

                if (Key == 1100 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 4400000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2656, 200)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2663, 120)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2661, 70)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2672, 15)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2674, 4))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2688, 0, 1, -1);
                    return;
                }

                if (Key == 1006 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 880000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 120)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2660, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2657, 50)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2669, 10)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2673, 2))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2682, 0, 1, -1);
                    return;
                }

                if (Key == 1005 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 880000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2659, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2658, 12)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2664, 30)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2673, 2))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2681, 0, 1, -1);
                    return;
                }

                if (Key == 1004 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 880000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2659, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2671, 80)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2667, 60)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2665, 10)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2673, 2))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2680, 0, 1, -1);
                    return;
                }

                if (Key == 1003 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 880000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2656, 100)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2671, 80)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2668, 30)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2665, 10)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2673, 2))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2679, 0, 1, -1);
                    return;
                }

                if (Key == 1002 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 880000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2656, 100)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2660, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2663, 60)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2668, 30)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2673, 2))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2678, 0, 1, -1);
                    return;
                }

                if (Key == 1001 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 880000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2656, 100)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2659, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2664, 30)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2662, 12)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2673, 2))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2677, 0, 1, -1);
                    return;
                }

                if (Key == 1000 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 880000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2671, 80)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2664, 30)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2661, 30)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2673, 2))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2676, 0, 1, -1);
                    return;
                }

                if (Key == 702 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2539, 400)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2538, 0, 1, -1);
                    return;
                }

                if (Key == 701 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2539, 400))
                {
                    if (Rate >= 550)
                    {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2538, 0, 1, -1);
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 602 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2536, 400)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2675, 0, 1, -1);
                    return;
                }

                if (Key == 601 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2536, 400))
                {
                    if (Rate >= 550)
                    {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2675, 0, 1, -1);
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 502 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2535, 350)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2674, 0, 1, -1);
                    return;
                }

                if (Key == 501 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2535, 350))
                {
                    if (Rate >= 550)
                    {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2674, 0, 1, -1);
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 405 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2534, 300))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 650)
                        {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2671, 0, 1, -1);
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2672, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2673, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 404 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2534, 225)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 650)
                        {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2671, 0, 1, -1);
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2672, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2673, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 403 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2534, 225))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 650)
                        {
                            if (Rate >= 850)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2671, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2672, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2673, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 402 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2534, 100)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 550)
                    {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2671, 0, 1, -1);
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2672, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 401 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2534, 100))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 750)
                        {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2671, 0, 1, -1);
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2672, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 307 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2533, 300))
                {
                    if (Rate >= 350)
                    {
                        if (Rate >= 550)
                        {
                            if (Rate >= 750)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2669, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2670, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 306 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2533, 225)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            if (Rate >= 800)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2669, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2670, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 305 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2533, 225))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            if (Rate >= 800)
                            {
                                if (Rate >= 900)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 1, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 1, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2669, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2670, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 304 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2533, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 1, -1);
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2669, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 303 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2533, 150))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 650)
                        {
                            if (Rate >= 850)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2669, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 302 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2533, 75)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 550)
                    {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 1, -1);
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 301 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2533, 75))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 750)
                        {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 1, -1);
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 207 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2532, 300))
                {
                    if (Rate >= 350)
                    {
                        if (Rate >= 550)
                        {
                            if (Rate >= 750)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2665, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2666, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 206 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2532, 225)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            if (Rate >= 800)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2665, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2666, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 205 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2532, 225))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            if (Rate >= 800)
                            {
                                if (Rate >= 900)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 1, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 1, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2665, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2666, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 204 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2532, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 1, -1);
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2665, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 203 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2532, 150))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 650)
                        {
                            if (Rate >= 850)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2665, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 202 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2532, 75)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 550)
                    {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 1, -1);
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 201 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2532, 75))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 750)
                        {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 1, -1);
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 107 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2531, 200))
                {
                    if (Rate >= 350)
                    {
                        if (Rate >= 550)
                        {
                            if (Rate >= 750)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2661, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2662, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 106 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2531, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            if (Rate >= 800)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2661, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2662, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 105 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2531, 150))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            if (Rate >= 800)
                            {
                                if (Rate >= 900)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 1, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 1, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2661, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2662, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 104 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2531, 100)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 1, -1);
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2661, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 103 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2531, 100))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 650)
                        {
                            if (Rate >= 850)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2661, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 102 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2531, 50)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 550)
                    {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 1, -1);
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 101 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2531, 50))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                if (Rate >= 950)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 1, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 1, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2661, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2662, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 7 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2530, 200))
                {
                    if (Rate >= 350)
                    {
                        if (Rate >= 550)
                        {
                            if (Rate >= 750)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2657, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2658, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 6 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2530, 150)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            if (Rate >= 800)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2657, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2658, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 5 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2530, 150))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            if (Rate >= 800)
                            {
                                if (Rate >= 900)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 1, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 1, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2657, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2658, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 4 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2530, 100)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 400)
                    {
                        if (Rate >= 600)
                        {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 1, -1);
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2657, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 3 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2530, 100))
                {
                    if (Rate >= 450)
                    {
                        if (Rate >= 650)
                        {
                            if (Rate >= 850)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2657, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 2 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2530, 50)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2654, 1))
                {
                    if (Rate >= 550)
                    {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 1, -1);
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 1 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2530, 50))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 950)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 1, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2657, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2537, 0, 1, -1);
                    }

                    return;
                }
            }
        }

        if (packet == 181)
        {
            int Type = 0, IID = 0, PerfIID = 0, JewelCheck = 0, Argument = 0,
                JewelAmount = 0, JewelCalculation = 0, GongValue = 0, Value = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "dddbwb", &IID, &PerfIID, &Type,
                &JewelCheck, &Argument, &JewelAmount);
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&GongValue,
                (int)&PerfIID);
            int PerfRecheck = 0, PerfCheck = 0, PerfItem = 0, ItemGet = 0;
            PerfCheck = Undefined::Check((int)((char *)Player + 1068), (int)&PerfRecheck);

            if (IID == PerfIID) {
                return;
            }

            if (!Undefined::CheckValues(&GongValue, PerfCheck)) {
                return;
            }

            PerfItem = *(DWORD*)(Undefined::GetValue(&GongValue) + 4);
            IItem PerfItemx((void*)PerfItem);
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
            int Recheck = 0, Check = 0;
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (!Undefined::CheckValues(&Value, Check)) {
                return;
            }

            ItemGet = *(DWORD*)(Undefined::GetValue(&Value) + 4);
            IItem MainItem((void*)ItemGet);
            int GetRate = 0, PrefixMainItem = MainItem.PrefixID(),
                PrefixStone = PerfItemx.PrefixID(), Rate = CTools::Rate(0, 10000);

            if (PrefixStone == 0) {
                PrefixStone = 1;
            }

            if (PrefixMainItem == 0) {
                PrefixMainItem = 1;
            }

            GetRate = DemonGongStoneEnchant[PrefixMainItem - 1][PrefixStone - 1];

            if (MainItem.GetInfo() & 4194304)
            {
                IPlayer.SystemMessage("Refining the Stone of Demon Gong can not be use on locked items.",
                    TEXTCOLOR_RED);
                return;
            }

            if (PerfItemx.CheckIndex() < 3199 || PerfItemx.CheckIndex() > 3201)
            {
                IPlayer.BoxMsg("This is wrong material item.");
                return;
            }

            if (MainItem.CheckIndex() < 3199 || MainItem.CheckIndex() > 3201)
            {
                IPlayer.BoxMsg("This is wrong material item.");
                return;
            }

            if (MainItem.PrefixID() >= 10)
            {
                IPlayer.BoxMsg("Material grade already maximum.");
                return;
            }

            if (!CBase::IsDeleted((int)PerfItemx.GetOffset())) {
                CItem::RemoveItem(IPlayer.GetOffset(), (int)PerfItemx.GetOffset());
            }

            if (JewelCheck == 1 && JewelAmount >= 1 && JewelAmount <= 10)
            {
                if (CPlayer::FindItem(IPlayer.Offset, 3360, (50 * JewelAmount)))
                {
                    CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3360, (50 * JewelAmount));
                    JewelCalculation = JewelAmount;
                    GetRate += (JewelCalculation * 500);
                } else {
                    return;
                }
            }

            if (Rate <= GetRate)
            {
                int AddPrefix = CItem::FindPrefix(PrefixMainItem + 1);

                if (!AddPrefix) {
                    return;
                }

                *(DWORD *)((int)MainItem.GetOffset() + 44) = AddPrefix;
                CDBSocket::Write(19, "ddbb", MainItem.GetIID(), IPlayer.GetID(),
                    PrefixMainItem + 1);
                CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                CPlayer::Write(IPlayer.GetOffset(), 255, "dbdb", 225, 0, MainItem.GetIID(),
                    PrefixMainItem + 1);
            } else {
                IPlayer.BoxMsg("Refining the Stone of Demon Gong has failed.");
                CPlayer::Write(IPlayer.GetOffset(), 255, "dbdb", 225, 1, 20);
            }

            return;
        }

        if (packet == 186)
        {
            char Type = 0;
            int Index = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "wb", &Index, &Type);

            if (Index && Type)
            {
                if (CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3360, 1))
                {
                    int Chance = 0, Type = 0;
                    Chance = CTools::Rate(0, 1000);

                    if (Chance < 5) {
                        Type = 2;
                    }

                    if (Chance < 200) {
                        Type = 1;
                    }

                    if (CheckMining.find(IPlayer.GetPID())->second.Index == 2524) {
                        CItem::InsertItem((int)Player, 27, NormalPickaxe[Type][CTools::Rate(0, 2)], 0,
                            1, -1);
                    }

                    if (CheckMining.find(IPlayer.GetPID())->second.Index == 2525)
                        CItem::InsertItem((int)Player, 27, BlueDragonPickaxe[Type][CTools::Rate(0, 10)],
                            0,
                            1, -1);

                    if (CheckMining.find(IPlayer.GetPID())->second.Index == 2526)
                    {
                        CItem::InsertItem((int)Player, 27, WhiteTigerPickaxe[Type][CTools::Rate(0, 10)],
                            0,
                            1, -1);
                        CItem::InsertItem((int)Player, 27, WhiteTigerPickaxe[Type][CTools::Rate(0, 10)],
                            0,
                            1, -1);
                        CItem::InsertItem((int)Player, 27, WhiteTigerPickaxe[Type][CTools::Rate(0, 10)],
                            0,
                            1, -1);
                    }

                    if (CheckMining.find(IPlayer.GetPID())->second.Index == 2527)
                    {
                        CItem::InsertItem((int)Player, 27, RedBirdPickaxe[Type][CTools::Rate(0, 10)], 0,
                            1,
                            -1);
                        CItem::InsertItem((int)Player, 27, RedBirdPickaxe[Type][CTools::Rate(0, 10)], 0,
                            1,
                            -1);
                    }

                    if (CheckMining.find(IPlayer.GetPID())->second.Index == 2528)
                    {
                        CItem::InsertItem((int)Player, 27, BlackTorotisePickaxe[Type][CTools::Rate(0,
                                    10)],
                            0, 1, -1);
                        CItem::InsertItem((int)Player, 27, BlackTorotisePickaxe[Type][CTools::Rate(0,
                                    10)],
                            0, 1, -1);
                        CItem::InsertItem((int)Player, 27, BlackTorotisePickaxe[Type][CTools::Rate(0,
                                    10)],
                            0, 1, -1);
                    }

                    if (CheckMining.find(IPlayer.GetPID())->second.Index == 2529)
                    {
                        CItem::InsertItem((int)Player, 27, MysteriousPickaxe[Type][CTools::Rate(0, 10)],
                            0,
                            1, -1);
                        CItem::InsertItem((int)Player, 27, MysteriousPickaxe[Type][CTools::Rate(0, 10)],
                            0,
                            1, -1);
                        CItem::InsertItem((int)Player, 27, MysteriousPickaxe[Type][CTools::Rate(0, 10)],
                            0,
                            1, -1);
                    }

                    CheckMining[IPlayer.GetPID()].Cycle = CheckMining.find(
                            IPlayer.GetPID())->second.Cycle + 1;

                    if (CheckMining.find(IPlayer.GetPID())->second.Cycle >= 3)
                    {
                        if (CheckMining.find(IPlayer.GetPID())->second.Amount >= 1
                            && CPlayer::RemoveItem(IPlayer.GetOffset(), 9,
                                CheckMining.find(IPlayer.GetPID())->second.Index, 1))
                        {
                            CheckMining[IPlayer.GetPID()].Amount = CheckMining.find(
                                    IPlayer.GetPID())->second.Amount - 1;
                            CheckMining[IPlayer.GetPID()].Cycle = 0;
                        } else {
                            IPlayer.CloseWindow("minebar");
                            CheckMining[IPlayer.GetPID()].Time = 0;
                            CheckMining[IPlayer.GetPID()].Cycle = 0;
                            CheckMining[IPlayer.GetPID()].Index = 0;
                            CheckMining[IPlayer.GetPID()].Amount = 0;
                            CPlayer::Write(IPlayer.GetOffset(), 220, "bb", 0, 3);
                            return;
                        }
                    }

                    CPlayer::Write(IPlayer.GetOffset(), 220, "bbw", 0, 4,
                        CheckMining.find(IPlayer.GetPID())->second.Index);
                    CheckMining[IPlayer.GetPID()].Time = GetTickCount() + 300000;
                    return;
                } else {
                    IPlayer.CloseWindow("minebar");
                    CheckMining[IPlayer.GetPID()].Time = 0;
                    CheckMining[IPlayer.GetPID()].Cycle = 0;
                    CheckMining[IPlayer.GetPID()].Index = 0;
                    CheckMining[IPlayer.GetPID()].Amount = 0;
                    return;
                }
            }

            return;
        }

        if (packet == 178)
        {
            int Type = 0, IID = 0, PerfIID = 0, JewelCheck = 0, Argument = 0,
                JewelAmount = 0, JewelCalculation = 0, PerfValue = 0, Value = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "bddbwb", &Type, &IID, &PerfIID,
                &JewelCheck, &Argument, &JewelAmount);

            if (IID == PerfIID) {
                return;
            }

            if (Type == 0)
            {
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&PerfValue,
                    (int)&PerfIID);
                int PerfRecheck = 0, PerfCheck = 0, PerfItem = 0, ItemGet = 0;
                PerfCheck = Undefined::Check((int)((char *)Player + 1068), (int)&PerfRecheck);

                if (!Undefined::CheckValues(&PerfValue, PerfCheck)) {
                    return;
                }

                PerfItem = *(DWORD*)(Undefined::GetValue(&PerfValue) + 4);
                IItem PerfItemx((void*)PerfItem);
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
                int Recheck = 0, Check = 0;
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (!Undefined::CheckValues(&Value, Check)) {
                    return;
                }

                ItemGet = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                IItem MainItem((void*)ItemGet);
                int PerfGradeCheck = 0;

                if (GetItemStat.count(IID)) {
                    PerfGradeCheck = GetItemStat.find(IID)->second / 100000000;
                }

                if (PerfGradeCheck >= 1 && PerfItemx.CheckIndex() == 3057)
                {
                    IPlayer.SystemMessage("Perforation shot can not be use on item anymore.",
                        TEXTCOLOR_RED);
                    return;
                }

                if (MainItem.GetInfo() & 4194304 && PerfItemx.CheckIndex() == 3057)
                {
                    IPlayer.SystemMessage("You can not add qigong ability on locked items.",
                        TEXTCOLOR_RED);
                    return;
                }

                if (PerfGradeCheck < 1 && PerfItemx.CheckIndex() == 3166) {
                    return;
                }

                if (MainItem.GetGrade() < 65 && PerfItemx.CheckIndex() == 3166) {
                    return;
                }

                if (PerfGradeCheck >= 3 && PerfItemx.CheckIndex() == 3166)
                {
                    IPlayer.SystemMessage("Gun of demon gong can not be use on item anymore.",
                        TEXTCOLOR_RED);
                    return;
                }

                if (MainItem.GetInfo() & 4194304 && PerfItemx.CheckIndex() == 3166)
                {
                    IPlayer.SystemMessage("You can not add demon gong ability on locked items.",
                        TEXTCOLOR_RED);
                    return;
                }

                if (JewelCheck == 1 && JewelAmount >= 1 && JewelAmount <= 10)
                {
                    int Multiply = 10;

                    if (PerfItemx.CheckIndex() == 3166) {
                        Multiply = 20;
                    }

                    if (CPlayer::FindItem(IPlayer.Offset, 3360, (Multiply * JewelAmount)))
                    {
                        CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3360, (Multiply * JewelAmount));
                        JewelCalculation = JewelAmount;
                    } else {
                        return;
                    }
                }

                if (PerfItemx.CheckIndex() == 3057
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3057, 1))
                {
                    int PerfRate = CTools::Rate(1, 1000);

                    if (PerfRate >= (900 - (JewelCalculation * 70)))
                    {
                        GetItemStat[IID] = GetItemStat.find(IID)->second + 100000000;
                        CDBSocket::Write(90, "ddd", IPlayer.GetPID(), GetItemStat.find(IID)->second,
                            MainItem.GetIID());

                        if (CItem::IsState((int)MainItem.GetOffset(), 64)) {
                            CItem::SubState((int)MainItem.GetOffset(), 64);
                        }

                        CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                        CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, 0, 0, 128, 255);
                        return;
                    } else {
                        if (CItem::IsState((int)MainItem.GetOffset(), 64))
                        {
                            CDBSocket::Write(21, "dddbb", MainItem.GetIID(), IPlayer.GetID(), 64, 0, 255);
                            CItem::SubState((int)MainItem.GetOffset(), 64);
                            CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                            return;
                        }

                        if (MainItem.GetEndurance() >= 5) {
                            MainItem.DecreaseEndurance(5);
                        }
                        else {
                            MainItem.DecreaseEndurance(MainItem.GetEndurance());
                        }

                        if (MainItem.GetEndurance() <= 0)
                        {
                            CPlayer::Write(IPlayer.GetOffset(), 91, "db", MainItem.GetIID(),
                                MainItem.GetEndurance());
                            CDBSocket::Write(3, "ddwdbddd", MainItem.GetIID(), IPlayer.GetID(),
                                MainItem.CheckIndex(), 1, 27, 0, 0, 0);

                            if (CItem::GetLevel((int)MainItem.GetOffset()) >= 40) {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 517, 0, 15, -1);
                            }

                            CBase::Delete(MainItem.GetOffset());
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 91, "db", MainItem.GetIID(),
                                MainItem.GetEndurance());
                            CDBSocket::Write(18, "ddb", MainItem.GetIID(), IPlayer.GetID(),
                                MainItem.GetEndurance());
                        }

                        return;
                    }
                }

                if (PerfItemx.CheckIndex() == 3166
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3166, 1))
                {
                    int PerfRate = CTools::Rate(1, 1000);

                    if (PerfRate >= (900 - (JewelCalculation * 70)))
                    {
                        GetItemStat[IID] = GetItemStat.find(IID)->second + 100000000;
                        CDBSocket::Write(90, "ddd", IPlayer.GetPID(), GetItemStat.find(IID)->second,
                            MainItem.GetIID());

                        if (CItem::IsState((int)MainItem.GetOffset(), 64)) {
                            CItem::SubState((int)MainItem.GetOffset(), 64);
                        }

                        CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                        CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, 0, 0, 128, 255);
                        return;
                    } else {
                        if (CItem::IsState((int)MainItem.GetOffset(), 64))
                        {
                            CDBSocket::Write(21, "dddbb", MainItem.GetIID(), IPlayer.GetID(), 64, 0, 255);
                            CItem::SubState((int)MainItem.GetOffset(), 64);
                            CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                            return;
                        }

                        if (MainItem.GetEndurance() >= 5) {
                            MainItem.DecreaseEndurance(5);
                        }
                        else {
                            MainItem.DecreaseEndurance(MainItem.GetEndurance());
                        }

                        if (MainItem.GetEndurance() <= 0)
                        {
                            CPlayer::Write(IPlayer.GetOffset(), 91, "db", MainItem.GetIID(),
                                MainItem.GetEndurance());
                            CDBSocket::Write(3, "ddwdbddd", MainItem.GetIID(), IPlayer.GetID(),
                                MainItem.CheckIndex(), 1, 27, 0, 0, 0);

                            if (CItem::GetLevel((int)MainItem.GetOffset()) >= 40) {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 517, 0, 15, -1);
                            }

                            CBase::Delete(MainItem.GetOffset());
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 91, "db", MainItem.GetIID(),
                                MainItem.GetEndurance());
                            CDBSocket::Write(18, "ddb", MainItem.GetIID(), IPlayer.GetID(),
                                MainItem.GetEndurance());
                        }

                        return;
                    }
                }
            }

            if (Type == 1)
            {
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&PerfValue,
                    (int)&PerfIID);
                int PerfRecheck = 0, PerfCheck = 0, PerfItem = 0, ItemGet = 0, SetType = 0;
                PerfCheck = Undefined::Check((int)((char *)Player + 1068), (int)&PerfRecheck);

                if (!Undefined::CheckValues(&PerfValue, PerfCheck)) {
                    return;
                }

                PerfItem = *(DWORD*)(Undefined::GetValue(&PerfValue) + 4);
                IItem QigongItemx((void*)PerfItem);
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
                int Recheck = 0, Check = 0;
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (!Undefined::CheckValues(&Value, Check)) {
                    return;
                }

                ItemGet = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                IItem MainItem((void*)ItemGet);
                int QigongGradeCheck = 0;

                if (MainItem.GetInfo() & 4194304)
                {
                    IPlayer.SystemMessage("Qigong can not be use on locked items.", TEXTCOLOR_RED);
                    return;
                }

                if (GetItemStat.count(IID)) {
                    QigongGradeCheck = GetItemStat.find(IID)->second % 100;
                }

                if (JewelCheck == 1 && JewelAmount >= 1 && JewelAmount <= 10)
                {
                    if (CPlayer::FindItem(IPlayer.Offset, 3360, (10 * JewelAmount)))
                    {
                        CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3360, (10 * JewelAmount));
                        JewelCalculation = JewelAmount;
                    } else {
                        return;
                    }
                }

                if (QigongItemx.CheckIndex() == 3056
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3056, 1))
                {
                    int QigongRate = CTools::Rate(1, 1000);

                    if (QigongRate >= (550 - (JewelCalculation * 50)))
                    {
                        if (QigongRate >= (750 - (JewelCalculation * 60)))
                        {
                            if (QigongRate >= (850 - (JewelCalculation * 60)))
                            {
                                if (QigongRate >= (950 - (JewelCalculation * 70)))
                                {
                                    if (QigongRate >= (970 - (JewelCalculation * 70)))
                                    {
                                        if (QigongRate >= (980 - (JewelCalculation * 80)))
                                        {
                                            if (QigongRate >= (990 - (JewelCalculation * 80)))
                                            {
                                                int Rate = CTools::Rate(71, 80);
                                                SetType += Rate;
                                                std::string msg = (std::string)IPlayer.GetName();
                                                msg = msg + " has been fused with the Black Spirit Of Insanity!";
                                                CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 8);
                                            } else {
                                                int Rate = CTools::Rate(61, 70);
                                                SetType += Rate;
                                                std::string msg = (std::string)IPlayer.GetName();
                                                msg = msg + " has been fused with the Black Spirit Of Thunder!";
                                                CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 8);
                                            }
                                        } else {
                                            int Rate = CTools::Rate(51, 60);
                                            SetType += Rate;
                                        }
                                    } else {
                                        int Rate = CTools::Rate(41, 50);
                                        SetType += Rate;
                                    }
                                } else {
                                    int Rate = CTools::Rate(31, 40);
                                    SetType += Rate;
                                }
                            } else {
                                int Rate = CTools::Rate(21, 30);
                                SetType += Rate;
                            }
                        } else {
                            int Rate = CTools::Rate(11, 20);
                            SetType += Rate;
                        }
                    } else {
                        int Rate = CTools::Rate(1, 10);
                        SetType += Rate;
                    }

                    GetItemStat[IID] = (GetItemStat.find(IID)->second + SetType) - QigongGradeCheck;
                    CDBSocket::Write(90, "ddd", IPlayer.GetPID(), GetItemStat.find(IID)->second,
                        MainItem.GetIID());
                    CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                    CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddd", 235, MainItem.GetIID(),
                        SetType);
                    return;
                }
            }

            if (Type == 2)
            {
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&PerfValue,
                    (int)&PerfIID);
                int PerfRecheck = 0, PerfCheck = 0, PerfItem = 0, ItemGet = 0, SetType = 0;
                PerfCheck = Undefined::Check((int)((char *)Player + 1068), (int)&PerfRecheck);

                if (!Undefined::CheckValues(&PerfValue, PerfCheck)) {
                    return;
                }

                PerfItem = *(DWORD*)(Undefined::GetValue(&PerfValue) + 4);
                IItem DemonGongItemx((void*)PerfItem);
                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
                int Recheck = 0, Check = 0;
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (!Undefined::CheckValues(&Value, Check)) {
                    return;
                }

                ItemGet = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                IItem MainItem((void*)ItemGet);
                int FirstDemonGongType = 0, DemonGongStyle = 0, GetStonePrefix = 1,
                    FirstDemonGongStat = 0;

                if (MainItem.GetInfo() & 4194304)
                {
                    IPlayer.SystemMessage("Demon Gong can not be use on locked items.",
                        TEXTCOLOR_RED);
                    return;
                }

                if (DemonGongItemx.CheckIndex() < 3199 || DemonGongItemx.CheckIndex() > 3201)
                {
                    IPlayer.BoxMsg("This is wrong material item.");
                    return;
                }

                if (DemonGongItemx.PrefixID() > 1) {
                    GetStonePrefix = DemonGongItemx.PrefixID();
                }

                if (DemonGongItemx.CheckIndex() == 3199) {
                    DemonGongStyle = 1;
                }

                if (DemonGongItemx.CheckIndex() == 3200) {
                    DemonGongStyle = 3;
                }

                if (DemonGongItemx.CheckIndex() == 3201) {
                    DemonGongStyle = 2;
                }

                if (!DemonGongStyle) {
                    return;
                }

                if (GetItemStat.count(IID)) {
                    FirstDemonGongType = (GetItemStat.find(IID)->second % 100000000) / 10000000;
                }

                if (JewelCheck == 2 && MainItem.GetGrade() >= 90)
                {
                    int SecondDemonGongType = (GetItemStat.find(IID)->second % 1000000) / 100000,
                        SecondDemonGongStat = 0;

                    if (SecondDemonGongType)
                    {
                        IPlayer.SystemMessage("This is wrong material item.", TEXTCOLOR_RED);
                        return;
                    }

                    if (SecondDemonGongType && SecondDemonGongType != DemonGongStyle)
                    {
                        IPlayer.SystemMessage("This is wrong material item.", TEXTCOLOR_RED);
                        return;
                    }

                    if (!CBase::IsDeleted((int)DemonGongItemx.GetOffset())) {
                        CItem::RemoveItem(IPlayer.GetOffset(), (int)DemonGongItemx.GetOffset());
                    }

                    if (!SecondDemonGongType) {
                        GetItemStat[IID] = GetItemStat.find(IID)->second + (DemonGongStyle * 100000);
                    }

                    SecondDemonGongStat = (GetItemStat.find(IID)->second % 100000) / 10000;

                    if (SecondDemonGongStat) {
                        return;
                    }

                    GetItemStat[IID] = GetItemStat.find(IID)->second + (GetStonePrefix * 10000) -
                        10000;
                    CDBSocket::Write(90, "ddd", IPlayer.GetPID(), GetItemStat.find(IID)->second,
                        MainItem.GetIID());

                    if (DemonGongStyle == 1)
                        CPlayer::Write(IPlayer.GetOffset(), 255, "dddb", 224, MainItem.GetIID(), 10,
                            JewelCheck);
                    else
                        CPlayer::Write(IPlayer.GetOffset(), 255, "dddb", 224, MainItem.GetIID(),
                            (DemonGongStyle - 1) << 24, JewelCheck);

                    CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                    return;
                }

                if (JewelCheck == 1)
                {
                    if (FirstDemonGongType)
                    {
                        IPlayer.SystemMessage("This is wrong material item.", TEXTCOLOR_RED);
                        return;
                    }

                    if (FirstDemonGongType && FirstDemonGongType != DemonGongStyle)
                    {
                        IPlayer.SystemMessage("This is wrong material item.", TEXTCOLOR_RED);
                        return;
                    }

                    if (!CBase::IsDeleted((int)DemonGongItemx.GetOffset())) {
                        CItem::RemoveItem(IPlayer.GetOffset(), (int)DemonGongItemx.GetOffset());
                    }

                    if (!FirstDemonGongType) {
                        GetItemStat[IID] = GetItemStat.find(IID)->second + (DemonGongStyle * 10000000);
                    }

                    FirstDemonGongStat = (GetItemStat.find(IID)->second % 10000000) / 1000000;

                    if (FirstDemonGongStat && MainItem.GetGrade() < 90) {
                        return;
                    }

                    GetItemStat[IID] = GetItemStat.find(IID)->second + (GetStonePrefix * 1000000) -
                        1000000;
                    CDBSocket::Write(90, "ddd", IPlayer.GetPID(), GetItemStat.find(IID)->second,
                        MainItem.GetIID());

                    if (DemonGongStyle == 1)
                        CPlayer::Write(IPlayer.GetOffset(), 255, "dddb", 224, MainItem.GetIID(), 10,
                            JewelCheck);
                    else
                        CPlayer::Write(IPlayer.GetOffset(), 255, "dddb", 224, MainItem.GetIID(),
                            (DemonGongStyle - 1) << 24, JewelCheck);

                    CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                    return;
                }

                return;
            }

            return;
        }

        if (packet == 99)
        {
            char  mtype = 0, yintype = 0;
            int key = 0, TargetIID = 0, Value = 0, Item = 0, CheckWater = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "bbdd", &mtype, &yintype, &key,
                &TargetIID);
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value,
                (int)&TargetIID);
            int Recheck = 0, Check = 0;
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (!Undefined::CheckValues(&Value, Check)) {
                return;
            }

            Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);
            IItem MainItem((void*)Item);

            if (key > 1000)
            {
                key -= 1000;
                CheckWater = 1;
            }

            if (mtype == 10 && yintype == 1)
            {
                if (key > 28) {
                    key -= 6;
                }
                else if (key > 18) {
                    key -= 4;
                }
                else if (key > 8) {
                    key -= 2;
                }

                if (IPlayer.IsOnline()
                    && CPlayer::GetInvenSize((int)IPlayer.GetOffset()) < IPlayer.MaxInventorySize())
                {
                    if (CPlayer::RemoveItem(IPlayer.GetOffset(), 9, (key + 2953), 2))
                    {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, (key + 2985), 0, 1, -1);
                        IPlayer.CloseWindow("yinyang_enchant");
                        IPlayer.OpenWindow("yinyang_enchant", 0, 0);
                    }
                } else {
                    IPlayer.SystemMessage("Inventory is full.", TEXTCOLOR_RED);
                }
            }

            if (mtype == 20 && yintype == 2)
            {
                if (key > 128) {
                    key -= 6;
                }
                else if (key > 118) {
                    key -= 4;
                }
                else if (key > 108) {
                    key -= 2;
                }

                if (CPlayer::RemoveItem(IPlayer.GetOffset(), 9, (key + 2853), 1))
                {
                    if (CheckWater == 1) {
                        CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3024, 1);
                    }

                    int GetCurrentGrade = (GetItemStat.find(TargetIID)->second % 10000) / 100;

                    if (GetCurrentGrade == 0) {
                        GetCurrentGrade = 1;
                    }

                    int GetRate = TriagramUpgradeRate[0][GetCurrentGrade - 1],
                        Rate = CTools::Rate(1,
                                10000);

                    if (Rate <= GetRate + (CheckWater * 1000))
                    {
                        GetItemStat[TargetIID] = GetItemStat.find(TargetIID)->second + 100;
                        CDBSocket::Write(90, "ddd", IPlayer.GetPID(),
                            GetItemStat.find(TargetIID)->second,
                            MainItem.GetIID());
                        CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                        CPlayer::Write(IPlayer.GetOffset(), 176, "bbdd", 0, 2, 0, MainItem.GetIID());
                    } else {
                        if (GetCurrentGrade > 4)
                        {
                            int Rate = CTools::Rate(0, 2);

                            if (!Rate && !CheckWater)
                            {
                                CPlayer::Write(IPlayer.GetOffset(), 176, "bb", 0, 3);
                                GetItemStat[TargetIID] = GetItemStat.find(TargetIID)->second - 100;
                                CDBSocket::Write(90, "ddd", IPlayer.GetPID(),
                                    GetItemStat.find(TargetIID)->second,
                                    MainItem.GetIID());
                                CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                            } else {
                                CPlayer::Write(IPlayer.GetOffset(), 176, "bb", 0, 4);
                            }
                        } else {
                            CPlayer::Write(IPlayer.GetOffset(), 176, "bb", 0, 4);
                        }
                    }
                }
            }

            if (mtype == 30 && yintype == 3)
            {
                if (key == 2000 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 5000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 3)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2659, 3)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2660, 1))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 3018, 0, 1, -1);
                    return;
                }

                if (key == 2001 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 1000000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 36)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2659, 36)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2660, 9)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2671, 9))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 3019, 0, 1, -1);
                    return;
                }

                if (key == 2002 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 14000000)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 144)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2659, 144)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2660, 24)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2671, 24)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2673, 4))
                {
                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 3020, 0, 1, -1);
                    return;
                }
            }

            if (mtype == 100 && yintype == 10 && MainItem.CheckIndex() >= 3018
                && MainItem.CheckIndex() <= 3020)
            {
                if (TrigramGrade.find(IPlayer.GetPID())->second >= 4
                    && TrigramHP.find(IPlayer.GetPID())->second
                    && TrigramMP.find(IPlayer.GetPID())->second
                    && TrigramAtk.find(IPlayer.GetPID())->second
                    && TrigramStr.find(IPlayer.GetPID())->second
                    && TrigramAgi.find(IPlayer.GetPID())->second
                    && TrigramInt.find(IPlayer.GetPID())->second
                    && TrigramWis.find(IPlayer.GetPID())->second
                    && TrigramHth.find(IPlayer.GetPID())->second
                    && !GetItemStat.find(TargetIID)->second)
                {
                    int SetPrefix = 0, CurrentGrade = (TrigramGrade.find(IPlayer.GetPID())->second +
                                1);

                    if (MainItem.CheckIndex() == 3020)
                    {
                        if (CurrentGrade == 5) {
                            SetPrefix = CTools::Rate(97, 104);
                        }

                        if (CurrentGrade == 6) {
                            SetPrefix = CTools::Rate(105, 112);
                        }

                        if (CurrentGrade == 7) {
                            SetPrefix = CTools::Rate(121, 128);
                        }

                        if (CurrentGrade == 8) {
                            SetPrefix = CTools::Rate(153, 160);
                        }

                        if (CurrentGrade == 9) {
                            SetPrefix = CTools::Rate(113, 120);
                        }

                        if (CurrentGrade == 10) {
                            SetPrefix = CTools::Rate(129, 136);
                        }

                        if (CurrentGrade == 11) {
                            SetPrefix = CTools::Rate(161, 168);
                        }

                        if (CurrentGrade == 12) {
                            SetPrefix = CTools::Rate(137, 144);
                        }

                        if (CurrentGrade >= 13) {
                            SetPrefix = CTools::Rate(169, 176);
                        }
                    } else {
                        if (CurrentGrade == 5) {
                            SetPrefix = CTools::Rate(1, 8);
                        }

                        if (CurrentGrade == 6) {
                            SetPrefix = CTools::Rate(9, 16);
                        }

                        if (CurrentGrade == 7) {
                            SetPrefix = CTools::Rate(33, 40);
                        }

                        if (CurrentGrade == 8) {
                            SetPrefix = CTools::Rate(65, 72);
                        }

                        if (CurrentGrade == 9) {
                            SetPrefix = CTools::Rate(17, 24);
                        }

                        if (CurrentGrade == 10) {
                            SetPrefix = CTools::Rate(41, 18);
                        }

                        if (CurrentGrade == 11) {
                            SetPrefix = CTools::Rate(73, 80);
                        }

                        if (CurrentGrade == 12) {
                            SetPrefix = CTools::Rate(49, 56);
                        }

                        if (CurrentGrade == 13) {
                            SetPrefix = CTools::Rate(81, 88);
                        }

                        if (CurrentGrade == 14) {
                            SetPrefix = CTools::Rate(145, 152);
                        }

                        if (CurrentGrade == 15) {
                            SetPrefix = CTools::Rate(177, 184);
                        }
                    }

                    CPlayer::Write(IPlayer.GetOffset(), 176, "bbdd", 0, 7, SetPrefix,
                        MainItem.GetIID());
                    GetItemStat[TargetIID] = (1000 * SetPrefix);
                    CDBSocket::Write(90, "ddd", IPlayer.GetPID(),
                        GetItemStat.find(TargetIID)->second,
                        MainItem.GetIID());
                    CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                }
            }

            if (mtype == 110 && yintype == 11 && MainItem.CheckIndex() >= 3018
                && MainItem.CheckIndex() <= 3020
                && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3023, 1))
            {
                CPlayer::Write(IPlayer.GetOffset(), 176, "bbdd", 0, 6);
                GetItemStat[TargetIID] = 0;
                CDBSocket::Write(90, "ddd", IPlayer.GetPID(),
                    GetItemStat.find(TargetIID)->second,
                    MainItem.GetIID());
                CItem::SendItemInfo(MainItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
            }

            return;
        }

        if (packet == 142)
        {
            int MSSIID = 0, MSSX = 0, MSSY = 0, MSSMap = 0, MSSValue = 0, Value = 0,
                Item = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "ddddd", &MSSIID, &MSSMap, &MSSX,
                &MSSY, &MSSValue);

            if (MSSIID)
            {
                if (!IPlayer.IsValid()) {
                    return;
                }

                if (CSMap::IsOnTile(*(void **)((int)IPlayer.Offset + 320),
                        (int)IPlayer.Offset + 332, 131072)
                    || CSMap::IsOnTile(*(void **)((int)IPlayer.Offset + 320),
                        (int)IPlayer.Offset + 332, 1048576))
                {
                    IPlayer.SystemMessage("Can not be use in safezones.", TEXTCOLOR_ORANGE);
                    return;
                }

                if (MSSMap)
                {
                    IPlayer.SystemMessage("Can not be use in dungeon and battle areas.",
                        TEXTCOLOR_ORANGE);
                    return;
                }

                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&MSSIID);
                int Recheck = 0, Check = 0;
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (!Undefined::CheckValues(&Value, Check)) {
                    return;
                }

                Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);
                IItem MainItem((void*)Item);
                int ItemIndex = MainItem.CheckIndex();

                if (IPlayer.IsValid() && MSS.size() >= 4 && Item && MainItem.GetAmount() >= 1
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, MainItem.CheckIndex(), 1))
                {
                    for (int i = 0; i < (int)MSS.size(); i += 4)
                    {
                        int Amount = MSS[i + 2], Index = MSS[i + 1], It = MSS[i],
                            Dis = (MSS[i + 3] * 1000);

                        if (It && ItemIndex == It)
                        {
                            for (int i = 0; i < Amount; i++)
                            {
                                IChar Monster((void*)Summon(0, MSSMap, MSSX, MSSY, Index, 1, 1, 0, Dis, 0));

                                if (Monster.IsValid() && IPlayer.IsValid())
                                {
                                    Monster.Buff(367, 1296000, 0);
                                    SummonAi[(int)Monster.GetOffset()] = IPlayer.GetOffset();
                                } else {
                                    Monster.Blob();
                                }
                            }
                        }
                    }
                }
            }

            return;
        }

        if (packet == 254)
        {
            int Type = 100;
            const char *Caller = "", *Recall = "";
            CPacket::Read((char*)pPacket, (char*)pPos, "dss", &Type, &Caller, 21, &Recall,
                21);

            if (strlen(Caller) > 0 && strlen(Recall) > 0)
            {
                IChar RCT((void*)CPlayer::FindPlayerByName((char)Caller));
                IChar RC((void*)CPlayer::FindPlayerByName((char)Recall));

                if (Type == 1)
                {
                    if (RCT.IsValid() && RC.IsValid() && RCT.IsBuff(304))
                    {
                        RC.Teleport(RCT.GetMap(), RCT.GetX(), RCT.GetY());
                        return;
                    }

                    if (RCT.IsValid() && !RC.IsValid())
                    {
                        std::string name = Recall;
                        std::string msg = name + " is not valid or offline.";
                        RCT.BoxMsg(msg);
                        return;
                    }

                    if (!RCT.IsValid() && RC.IsValid())
                    {
                        std::string name = Caller;
                        std::string msg = name + " is not valid or offline.";
                        RC.BoxMsg(msg);
                        return;
                    }

                    return;
                }

                if (Type == 0 && RCT.IsValid())
                {
                    std::string name = Recall;
                    std::string msg = name + " refused your recall.";
                    RCT.BoxMsg(msg);
                    return;
                }
            }

            return;
        }

        if (packet == 118)
        {
            int Type = 0, IID = 0;
            const char *Name = "";
            CPacket::Read((char*)pPacket, (char*)pPos, "bds", &Type, &IID, &Name, 21);
            int Recheck = 0, Check = 0, Value = 0, Item = 0;
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (!Undefined::CheckValues(&Value, Check)) {
                return;
            }

            Item = *(DWORD *)(Undefined::GetValue(&Value) + 4);
            IItem Itemx((void*)Item);

            if (strlen(Name) > 0 && Item && Itemx.CheckIndex() == 1472)
            {
                IChar Target((void*)CPlayer::FindPlayerByName((char)Name));

                if (Target.IsValid() && IPlayer.IsValid())
                {
                    if (CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 1472, 1))
                    {
                        std::string getname = IPlayer.GetName();
                        std::string send = getname +
                            " will recall you to him(her). Do you accept the recall?";
                        CPlayer::Write(Target.GetOffset(), 0xFF, "ddsss", 228, 1000, send.c_str(),
                            IPlayer.GetName(), Target.GetName());
                        IPlayer.Buff(304, 1296000, 0);
                        IPlayer.SystemMessage("Recall scroll used.", TEXTCOLOR_GREEN);
                    }
                } else {
                    std::string getname = Name;
                    std::string send = getname + " is not valid or offline.";
                    IPlayer.BoxMsg(send);
                }

                return;
            }

            if (Itemx.CheckIndex() == 1473)
            {
                if (IPlayer.IsValid() && IPlayer.IsParty())
                {
                    IPlayer.SystemMessage("Recall scroll used.", TEXTCOLOR_GREEN);
                    IPlayer.Buff(304, 1296000, 0);

                    if (CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 1473, 1))
                    {
                        int Party = CParty::FindParty(IPlayer.GetPartyID());

                        for (int i = CParty::GetPlayerList((void*)Party); i;
                            i = CBaseList::Pop((void *)i))
                        {
                            IChar Member((void*) * (DWORD*)((void*)i));

                            if (Member.IsValid() && IPlayer.IsValid()
                                && Member.GetOffset() != IPlayer.GetOffset())
                            {
                                std::string getname = IPlayer.GetName();
                                std::string send = getname +
                                    " will recall you to him(her). Do you accept the recall?";
                                CPlayer::Write(Member.GetOffset(), 0xFF, "ddsss", 228, 1000, send.c_str(),
                                    IPlayer.GetName(), Member.GetName());
                            }
                        }
                    }
                } else {
                    IPlayer.BoxMsg("You are not in party.");
                }

                return;
            }

            if (Itemx.CheckIndex() == 1474)
            {
                if (IPlayer.IsValid() && IPlayer.GetGID())
                {
                    IPlayer.SystemMessage("Recall scroll used.", TEXTCOLOR_GREEN);
                    IPlayer.Buff(304, 1296000, 0);

                    if (CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 1474, 1))
                    {
                        CIOCriticalSection::Enter((void*)0x004e2078);
                        CIOCriticalSection::Enter((void*)0x004e2098);
                        CLink::MoveTo((void*)0x004e200c, (int)0x004e2004);
                        CIOCriticalSection::Leave((void*)0x004e2098);

                        for (DWORD i = *(DWORD*)0x004E2004; i != 0x004E2004; i = *(DWORD*)i)
                        {
                            if ((void*)(i - 428))
                            {
                                IChar Check((void*)(i - 428));

                                if (Check.IsValid() && Check.GetGID() && Check.GetGID() == IPlayer.GetGID()
                                    && Check.GetOffset() != IPlayer.GetOffset())
                                {
                                    std::string getname = IPlayer.GetName();
                                    std::string send = getname +
                                        " will recall you to him(her). Do you accept the recall?";
                                    CPlayer::Write(Check.GetOffset(), 0xFF, "ddsss", 228, 1000, send.c_str(),
                                        IPlayer.GetName(), Check.GetName());
                                }
                            }
                        }
                    }
                } else {
                    IPlayer.BoxMsg("You do not have a guild.");
                }

                return;
            }

            return;
        }

        if (packet == 17 && Mute.count(IPlayer.GetPID())
            && Mute.find(IPlayer.GetPID())->second)
        {
            if (Mute.find(IPlayer.GetPID())->second > GetTickCount())
            {
                std::string msg = "You are muted. You can talk again in " + Int2String(
                        IPlayer.GetBuffRemain(164)) + " seconds.";
                IPlayer.BoxMsg(msg);
                return;
            } else {
                Mute.erase(IPlayer.GetPID());
            }
        }

        if (packet == 34 || packet == 44 || packet == 80 || packet == 85
            || packet == 64)
        {
            if (IPlayer.IsBuff(285)) {
                return;
            }
            else {
                IPlayer.Buff(285, 2, 0);
            }
        }

        if (packet == 173) {
            return;
        }

        if (packet == 37 && IPlayer.IsBuff(378)) {
            return;
        }

        if (packet == 37 && (IPlayer.IsBuff(160) || IPlayer.IsBuff(161))) {
            return;
        }

        if (packet == 37 && (IPlayer.IsBuff(162) || IPlayer.IsBuff(163))) {
            return;
        }

        if (packet == 37 && IPlayer.IsBuff(166)) {
            return;
        }

        if (packet == 37 && (IPlayer.IsBuff(373) || IPlayer.IsBuff(374))) {
            return;
        }

        if (packet == 37 && (IPlayer.IsBuff(170) || IPlayer.IsBuff(171))) {
            return;
        }

        if (packet == 26)
        {
            int IID = 0, Amount = 0, Value = 0, Item = 0, Recheck = 0, Check = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "dd", &IID, &Amount);

            if (Amount > 0 && IID)
            {
                if (strlen(PlayerCheck) && ((std::string)PlayerCheck == "disable"
                        || (std::string)PlayerCheck == "Disable")) {
                    return;
                }

                if (IPlayer.IsBuff(372)) {
                    return;
                }
                else {
                    IPlayer.Buff(372, 2, 0);
                }

                Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
                Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

                if (Undefined::CheckValues(&Value, Check))
                {
                    Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);

                    if (Item && IID)
                    {
                        IItem Itemx((void*)Item);

                        if (Itemx.GetInfo() & 4194304) {
                            return;
                        }
                    }
                }
            }
        }

        if (packet == 109)
        {
            const char *Password, *Question, *Answer;
            int LockIID = 0, IID = 0, LockValue = 0, Value = 0, LockItem = 0, Itemx = 0,
                Recheckx = 0, Checkx = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "ddsss", &LockIID, &IID, &Password,
                13, &Question, 13, &Answer, 13);
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&LockValue,
                (int)&LockIID);
            Checkx = Undefined::Check((int)((char *)Player + 1068), (int)&Recheckx);

            if (IID == LockIID) {
                return;
            }

            if (!strlen(Password) || !strlen(Question) || !strlen(Answer)) {
                return;
            }

            if (!Undefined::CheckValues(&LockValue, Checkx)) {
                return;
            }

            LockItem = *(DWORD*)(Undefined::GetValue(&LockValue) + 4);
            IItem ItemLock((void*)LockItem);
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
            int Recheck = 0, Check;
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (!Undefined::CheckValues(&Value, Check)) {
                return;
            }

            Itemx = *(DWORD *)(Undefined::GetValue(&Value) + 4);
            IItem xItem((void*)Itemx);

            if (ItemLock.CheckIndex() == 1181)
            {
                CItem::RemoveItem((void*)Player, (int)ItemLock.GetOffset());
            } else {
                return;
            }

            if (xItem.GetInfo() & 4194304) {
                return;
            }

            if (xItem.CheckIndex())
            {
                int CurrentInfo = *(DWORD *)(Itemx + 48) + 4194304;
                CDBSocket::Write(21, "dddbb", xItem.GetIID(), IPlayer.GetID(), xItem.GetInfo(),
                    0,
                    0);
                *(DWORD *)(Itemx + 48) = CurrentInfo;
                CDBSocket::Write(21, "dddbb", xItem.GetIID(), *(DWORD*)(Itemx + 28),
                    CurrentInfo, 8,
                    7);
                CItem::SendItemInfo((void *)Itemx, (int)IPlayer.GetOffset(), 92);
                IPlayer.BoxMsg("You have successfully locked your item.");
                CDBSocket::Write(88, "dsd", IPlayer.GetPID(), Password, xItem.GetIID());
                ItemLockCheck[xItem.GetIID()] = Password;
            } else {
                return;
            }

            return;
        }

        if (packet == 110)
        {
            const char *Password;
            int KeyIID = 0, IID = 0, KeyValue = 0, Value = 0, KeyItem = 0, Itemx = 0,
                Recheckx = 0, Checkx = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "dds", &KeyIID, &IID, &Password, 13);
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&KeyValue,
                (int)&KeyIID);
            Checkx = Undefined::Check((int)((char *)Player + 1068), (int)&Recheckx);

            if (IID == KeyIID) {
                return;
            }

            if (!strlen(Password)) {
                return;
            }

            if (!Undefined::CheckValues(&KeyValue, Checkx)) {
                return;
            }

            KeyItem = *(DWORD *)(Undefined::GetValue(&KeyValue) + 4);
            IItem KeyLock((void*)KeyItem);
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
            int Recheck = 0, Check;
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (!Undefined::CheckValues(&Value, Check)) {
                return;
            }

            Itemx = *(DWORD *)(Undefined::GetValue(&Value) + 4);
            IItem xItem((void*)Itemx);

            if (KeyLock.CheckIndex() == 1182)
            {
                CItem::RemoveItem((void*)Player, (int)KeyLock.GetOffset());
            } else {
                return;
            }

            if (xItem.CheckIndex() && (xItem.GetInfo() & 4194304)
                && ItemLockCheck.count(IID))
            {
                if (Password != ItemLockCheck.find(IID)->second)
                {
                    IPlayer.BoxMsg("You typed wrong password. A Key is consumed.");
                    return;
                }

                int CurrentInfo = *(DWORD *)(Itemx + 48) - 4194304;
                CDBSocket::Write(21, "dddbb", xItem.GetIID(), IPlayer.GetID(), xItem.GetInfo(),
                    0,
                    0);
                *(DWORD *)(Itemx + 48) = CurrentInfo;
                CDBSocket::Write(21, "dddbb", xItem.GetIID(), *(DWORD*)(Itemx + 28),
                    CurrentInfo, 8,
                    7);
                CItem::SendItemInfo((void *)Itemx, (int)IPlayer.GetOffset(), 92);
                IPlayer.BoxMsg("You completely unlocked your item. A Key is consumed.");
                CDBSocket::Write(88, "dsd", IPlayer.GetPID(), "nopwd", xItem.GetIID());
                ItemLockCheck.erase(xItem.GetIID());
            } else {
                return;
            }

            return;
        }

        if (packet == 75 && IPlayer.GetClass() == 3)
        {
            int SkillID = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "b", &SkillID);
            int SkillPointer = IPlayer.GetSkillPointer(SkillID);

            if (SkillPointer && SkillID < 90 && SkillID != 79 && SkillID != 37
                && SkillID != 50 && SkillID != 70 && SkillID != 87 && SkillID != 88
                && SkillID != 89 && (CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 362, 1)
                    || CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 502, 1)))
            {
                if (IPlayer.IsOnline() && IPlayer.GetClass() == 3 && SkillID == 4)
                {
                    IPlayer.DecreaseCritRate(*(DWORD*)(SkillPointer + 8));
                    IPlayer.DecreaseCritDamage(*(DWORD*)(SkillPointer + 8));
                }

                if (IPlayer.IsOnline() && IPlayer.GetClass() == 3 && SkillID == 5)
                {
                    IPlayer.DecreaseCritRate(*(DWORD*)(SkillPointer + 8));
                    IPlayer.DecreaseCritDamage(*(DWORD*)(SkillPointer + 8));
                }

                IPlayer.AddSkillPoint(*(DWORD*)(SkillPointer + 8));
                *(DWORD*)(SkillPointer + 8) = 0;
                CPlayer::Write(IPlayer.GetOffset(), 11, "bb", *(DWORD*)(SkillPointer + 4), 0);
                CDBSocket::Write(22, "dbbw", IPlayer.GetPID(), *(DWORD*)(SkillPointer + 4),
                    *(DWORD*)(SkillPointer + 8), *(DWORD*)((int)IPlayer.GetOffset() + 548));
                *(DWORD*)((int)IPlayer.GetOffset() + 4 * *(DWORD*)(SkillPointer + 4) + 632) = 0;
            } else {
                return;
            }
        }

        if (packet == 96)
        {
            void *xpPacket = pPacket;
            int xpPos = pPos, Npc = 0, Amount = 0, Index = 0, Item = 0, ValidItem = 0;
            unsigned __int16 ItemIndex = 0, ItemAmount = 0;
            unsigned __int8 Tax = 0, Size = 0;
            int NewpPacket = CPacket::Read((char*)xpPacket, (char*)xpPos, "dbb", &Npc, &Tax,
                    &Size);

            if (Size > 0 && Size < 100)
            {
                for (int i = 0; *((DWORD*)Player + 274) && i < Size; i++)
                {
                    NewpPacket = CPacket::Read((char*)NewpPacket, (char*)xpPos,
                            (const char*)0x004BADB4, &ItemIndex, &ItemAmount);
                    Amount = ItemAmount;
                    Index = ItemIndex;

                    if (Amount > 0 && HonorIndex.count(ItemIndex)
                        && HonorIndex.find(ItemIndex)->second)
                    {
                        int TotalHonorRemove = Amount * HonorIndex.find(ItemIndex)->second;

                        if (TotalHonorRemove > CheckHonor[IPlayer.GetPID()].RPx)
                        {
                            IPlayer.SystemMessage("You do not have enough reward points.", TEXTCOLOR_RED);
                            return;
                        } else {
                            if (CPlayer::GetInvenSize(Player) >= IPlayer.MaxInventorySize())
                            {
                                IPlayer.SystemMessage("There is no free space on the storage.", TEXTCOLOR_RED);
                                return;
                            } else {
                                Item = CItem::CreateItem(ItemIndex, 0, ItemAmount, -1);

                                if (Item)
                                {
                                    IItem IItem((void*)Item);
                                    ValidItem = CPlayer::_InsertItem(IPlayer.GetOffset(), 7, Item);

                                    if (ValidItem == 1)
                                    {
                                        CheckHonor[IPlayer.GetPID()].RPx -= TotalHonorRemove;
                                        *(DWORD*)(Item + 48) = 128;
                                        CDBSocket::Write(21, "dddbb", IItem.GetIID(), *(DWORD*)(Item + 28), 128, 8, 7);
                                        CItem::SendItemInfo((void *)Item, (int)IPlayer.GetOffset(), 92);
                                    }
                                }

                                return;
                            }
                        }
                    }
                }
            }
        }

        if (packet == 33)
        {
            int IID = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "d", &IID);
            int Recheck = 0, Check = 0, Value = 0, Item = 0;
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (!Undefined::CheckValues(&Value, Check)) {
                return;
            }

            Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);

            if (Item && IID)
            {
                IItem Itemx((void*)Item);

                if (Itemx.CheckIndex() == 1620)
                {
                    if (IPlayer.GetLevel() < 80)
                    {
                        IPlayer.SystemMessage("Your character must be level 80 or above.",
                            TEXTCOLOR_RED);
                        return;
                    }

                    if (IPlayer.IsValid()) {
                        IPlayer.Teleport(6, 360931, 187024);
                    }
                    else {
                        return;
                    }
                }
            }
        }

        if (packet == 63)
        {
            int IID = 0, Value = 0, Item = 0;;
            CPacket::Read((char*)pPacket, (char*)pPos, "d", &IID);
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
            int Recheck = 0, Check;
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (!Undefined::CheckValues(&Value, Check)) {
                return;
            }

            Item = *(DWORD *)(Undefined::GetValue(&Value) + 4);

            if (Item && IID)
            {
                IItem Itemx((void*)Item);

                if (Itemx.GetInfo() & 4194304) {
                    return;
                }
            }
        }

        if (packet == 172)
        {
            int Str = 0, Hp = 0, Int = 0, Wis = 0, Agi = 0;
            int LeftPacket = CPacket::Read((char*)pPacket, (char*)pPos, "bbbbb", &Str, &Hp,
                    &Int, &Wis, &Agi);
            int GetStr = IPlayer.GetStr(), GetHth = IPlayer.GetHth(),
                GetInt = IPlayer.GetInt(), GetWis = IPlayer.GetWis(), GetAgi = IPlayer.GetAgi();
            int NeedStatPoint = 0;

            if (Str)
            {
                if (IPlayer.GetStr() + Str >= 255)
                {
                    IPlayer.SystemMessage("Base stats can not be higher then 255!", TEXTCOLOR_RED);
                    return;
                }

                if (IPlayer.GetClass() == 0)
                {
                    for (int i = 0; i < Str; i++)
                    {
                        NeedStatPoint += _StatTable[GetStr];
                        GetStr++;
                    }
                } else {
                    for (int i = 0; i < Str; i++)
                    {
                        NeedStatPoint += StatTable[GetStr];
                        GetStr++;
                    }
                }
            }

            if (Hp)
            {
                if (IPlayer.GetHth() + Hp >= 255)
                {
                    IPlayer.SystemMessage("Base stats can not be higher then 255!", TEXTCOLOR_RED);
                    return;
                }

                if (IPlayer.GetClass() == 3)
                {
                    int pSkill = *((DWORD*)((int)IPlayer.GetOffset() + 624) + 30 + 2);

                    if (pSkill)
                    {
                        ISkill xSkill((void*)pSkill);
                        IPlayer.IncreaseMaxHp((5 * xSkill.GetGrade()) * Hp);
                    }
                }

                for (int i = 0; i < Hp; i++)
                {
                    NeedStatPoint += StatTable[GetHth];
                    GetHth++;
                }
            }

            if (Int)
            {
                if (IPlayer.GetInt() + Int >= 255)
                {
                    IPlayer.SystemMessage("Base stats can not be higher then 255!", TEXTCOLOR_RED);
                    return;
                }

                if (IPlayer.GetClass() == 1)
                {
                    for (int i = 0; i < Int; i++)
                    {
                        NeedStatPoint += _StatTable[GetInt];
                        GetInt++;
                    }
                } else {
                    for (int i = 0; i < Int; i++)
                    {
                        NeedStatPoint += StatTable[GetInt];
                        GetInt++;
                    }
                }
            }

            if (Wis)
            {
                if (IPlayer.GetWis() + Wis >= 255)
                {
                    IPlayer.SystemMessage("Base stats can not be higher then 255!", TEXTCOLOR_RED);
                    return;
                }

                for (int i = 0; i < Wis; i++)
                {
                    NeedStatPoint += StatTable[GetWis];
                    GetWis++;
                }
            }

            if (Agi)
            {
                if (IPlayer.GetAgi() + Agi >= 255)
                {
                    IPlayer.SystemMessage("Base stats can not be higher then 255!", TEXTCOLOR_RED);
                    return;
                }

                if (IPlayer.GetClass() == 2 || IPlayer.GetClass() == 3)
                {
                    for (int i = 0; i < Agi; i++)
                    {
                        NeedStatPoint += _StatTable[GetAgi];
                        GetAgi++;
                    }
                } else {
                    for (int i = 0; i < Agi; i++)
                    {
                        NeedStatPoint += StatTable[GetAgi];
                        GetAgi++;
                    }
                }
            }

            if (IPlayer.GetStatPoint() < NeedStatPoint || IPlayer.GetStatPoint() <= 0
                || NeedStatPoint == 0)
            {
                CPlayer::Write(IPlayer.GetOffset(), 68, "bb", 26, NeedStatPoint);
                return;
            }

            if (Str)
            {
                IPlayer.IncreaseStat(Str, 0);
                CDBSocket::Write(16, "dbwbb", IPlayer.GetPID(), 23, IPlayer.GetStatPoint(), 0,
                    *(DWORD *)(Player + 4 * 0 + 64));
            }

            if (Hp)
            {
                IPlayer.IncreaseStat(Hp, 1);
                CDBSocket::Write(16, "dbwbb", IPlayer.GetPID(), 23, IPlayer.GetStatPoint(), 1,
                    *(DWORD *)(Player + 4 * 1 + 64));
            }

            if (Int)
            {
                IPlayer.IncreaseStat(Int, 2);
                CDBSocket::Write(16, "dbwbb", IPlayer.GetPID(), 23, IPlayer.GetStatPoint(), 2,
                    *(DWORD *)(Player + 4 * 2 + 64));
            }

            if (Wis)
            {
                IPlayer.IncreaseStat(Wis, 3);
                CDBSocket::Write(16, "dbwbb", IPlayer.GetPID(), 23, IPlayer.GetStatPoint(), 3,
                    *(DWORD *)(Player + 4 * 3 + 64));
            }

            if (Agi)
            {
                IPlayer.IncreaseStat(Agi, 4);
                CDBSocket::Write(16, "dbwbb", IPlayer.GetPID(), 23, IPlayer.GetStatPoint(), 4,
                    *(DWORD *)(Player + 4 * 4 + 64));
            }

            if (NeedStatPoint) {
                IPlayer.RemoveStatPoint(NeedStatPoint);
            }

            return;
        }

        if (packet == 162)
        {
            int Type = 0, IID = 0, Value = 0, item = 0, ItemIndex = 0, JewelCheck = 0,
                Argument = 0, JewelAmount = 0;
            Interface<ITools> Tools;
            Tools->ParseData((char*)pPacket, "bddbwb", &Type, &IID, &ItemIndex, &JewelCheck,
                &Argument, &JewelAmount);

            if (Type == 1 && IID && ItemIndex)
            {
                CPlayer::Write(IPlayer.GetOffset(), 0xFF, "dd", 240, 1);
                return;
            }

            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value, (int)&IID);
            int Recheck = 0, Check = 0, SetType = 200, JewelCalculation = 0;
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (!Undefined::CheckValues(&Value, Check)) {
                return;
            }

            item = *(DWORD *)(Undefined::GetValue(&Value) + 4);
            IItem MainItem((void*)item);

            if (JewelCheck == 1 && JewelAmount >= 1 && JewelAmount <= 10)
            {
                int Multiply = 10;

                if (MainItem.GetType() >= 1 && MainItem.GetType() <= 6) {
                    Multiply = 5;
                }

                if (CPlayer::FindItem(IPlayer.Offset, 3360, (Multiply * JewelAmount)))
                {
                    CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 3360, (Multiply * JewelAmount));
                    JewelCalculation = JewelAmount;
                } else {
                    return;
                }
            }

            if (ItemIndex == 2365 && CPlayer::FindItem(IPlayer.Offset, 2365, 1))
            {
                int Type = 0, DssRate = CTools::Rate(1, 1000);

                if (DssRate >= (550 - (JewelCalculation * 50)))
                {
                    if (DssRate >= (750 - (JewelCalculation * 60)))
                    {
                        if (DssRate >= (850 - (JewelCalculation * 60)))
                        {
                            if (DssRate >= (950 - (JewelCalculation * 70)))
                            {
                                if (DssRate >= (970 - (JewelCalculation * 70)))
                                {
                                    if (DssRate >= (980 - (JewelCalculation * 80)))
                                    {
                                        if (DssRate >= (990 - (JewelCalculation * 80)))
                                        {
                                            int Rate = CTools::Rate(36, 40);
                                            SetType += Rate;
                                            Type = 1;
                                            std::string msg = (std::string)IPlayer.GetName();
                                            msg = msg + " has been fused with the Spirit Of Insanity!";
                                            CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 8);
                                        } else {
                                            int Rate = CTools::Rate(31, 35);
                                            SetType += Rate;
                                            Type = 2;
                                            std::string msg = (std::string)IPlayer.GetName();
                                            msg = msg + " has been fused with the Spirit Of Thunder!";
                                            CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 8);
                                        }
                                    } else {
                                        int Rate = CTools::Rate(26, 30);
                                        SetType += Rate;
                                        Type = 3;
                                    }
                                } else {
                                    int Rate = CTools::Rate(21, 25);
                                    SetType += Rate;
                                    Type = 4;
                                }
                            } else {
                                int Rate = CTools::Rate(16, 20);
                                SetType += Rate;
                                Type = 5;
                            }
                        } else {
                            int Rate = CTools::Rate(11, 15);
                            SetType += Rate;
                            Type = 6;
                        }
                    } else {
                        int Rate = CTools::Rate(6, 10);
                        SetType += Rate;
                        Type = 7;
                    }
                } else {
                    int Rate = CTools::Rate(1, 5);
                    SetType += Rate;
                    Type = 8;
                }

                MainItem.SetSetGem(SetType);
                CDBSocket::Write(87, "ddd", IPlayer.GetPID(), SetType, MainItem.GetIID());
                CItem::SendItemInfo((void *)item, (int)IPlayer.GetOffset(), 92);
                CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2365, 1);
                CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddb", 241, MainItem.GetIID(), Type);
                return;
            }

            return;
        }

        if (packet == 41)
        {
            int SkillID = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "b", &SkillID);

            if (SkillID == 85) {
                SkillID = 87;
            }
            else if (SkillID == 86) {
                SkillID = 88;
            }
            else if (SkillID == 87) {
                SkillID = 89;
            }

            if (SkillID >= 90) {
                return;
            }

            if (SkillID == 79) {
                return;
            }

            if (IPlayer.GetLevel() >= 81 && SkillID >= 87 && SkillID <= 89
                && IPlayer.GetSpecialty() > 1)
            {
                int OTP = IPlayer.GetSkillPointer(87);
                int EVA = IPlayer.GetSkillPointer(88);
                int DEF = IPlayer.GetSkillPointer(89);

                if (OTP || EVA || DEF)
                {
                    IPlayer.SystemMessage("You can only learn one mystery skill.", TEXTCOLOR_RED);
                    return;
                }

                if (SkillID == 87)
                {
                    int Value = 0, Argument = 0, Arg = 0, Check = 0, Recheck = 0;
                    Value = SkillID + (*((DWORD*)((DWORD*)((int)IPlayer.GetOffset() + 624)) + 1) <<
                            16);
                    Undefined::CreateSkillValue((void*)0x004E218C, (int)&Argument, (int)&Value);
                    Check = Undefined::Check((int)0x004E218C, (int)&Arg);

                    if (*(DWORD*)&Argument != *(DWORD*)Check)
                    {
                        Recheck = *(DWORD*)(Undefined::GetValue(&Argument) + 4);

                        if ((*(int (__thiscall**)(int, DWORD, DWORD))(*(DWORD*)Recheck + 60))(Recheck,
                                *(DWORD *)((int)IPlayer.GetOffset() + 60),
                                *(DWORD*)((int)IPlayer.GetOffset() + 464)))
                        {
                            if (Undefined::CheckSkillValue((DWORD*)((int)IPlayer.GetOffset() + 624),
                                    *(DWORD*)(Recheck + 20), *(DWORD *)(Recheck + 24)))
                            {
                                Recheck = (int)Undefined::CheckSkillX((void*)Recheck);
                                Undefined::CheckSkillY(Recheck, SkillID, 1);
                                (*(void (__thiscall **)(int, DWORD, DWORD, DWORD))
                                    (*(DWORD*)Recheck + 8))(Recheck, (int)IPlayer.GetOffset(), 0, 0);
                                *((DWORD*)(DWORD*)((int)IPlayer.GetOffset() + 624) + SkillID + 2) = Recheck;
                                IPlayer.AddOTP(8);
                                CDBSocket::Write(9, "dbw", IPlayer.GetPID(), SkillID, 1);
                                CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 85, 1);
                            }
                        }
                    }

                    if (IPlayer.GetLevel() > 81) {
                        AutoLearn((void*)(DWORD*)(Player + 624), 0, 0);
                    }
                }

                if (SkillID == 88)
                {
                    int Value = 0, Argument = 0, Arg = 0, Check = 0, Recheck = 0;
                    Value = SkillID + (*((DWORD*)((DWORD*)((int)IPlayer.GetOffset() + 624)) + 1) <<
                            16);
                    Undefined::CreateSkillValue((void*)0x004E218C, (int)&Argument, (int)&Value);
                    Check = Undefined::Check((int)0x004E218C, (int)&Arg);

                    if (*(DWORD*)&Argument != *(DWORD*)Check)
                    {
                        Recheck = *(DWORD*)(Undefined::GetValue(&Argument) + 4);

                        if ((*(int (__thiscall**)(int, DWORD, DWORD))(*(DWORD*)Recheck + 60))(Recheck,
                                *(DWORD *)((int)IPlayer.GetOffset() + 60),
                                *(DWORD*)((int)IPlayer.GetOffset() + 464)))
                        {
                            if (Undefined::CheckSkillValue((DWORD*)((int)IPlayer.GetOffset() + 624),
                                    *(DWORD*)(Recheck + 20), *(DWORD *)(Recheck + 24)))
                            {
                                Recheck = (int)Undefined::CheckSkillX((void*)Recheck);
                                Undefined::CheckSkillY(Recheck, SkillID, 1);
                                (*(void (__thiscall **)(int, DWORD, DWORD, DWORD))
                                    (*(DWORD*)Recheck + 8))(Recheck, (int)IPlayer.GetOffset(), 0, 0);
                                *((DWORD*)(DWORD*)((int)IPlayer.GetOffset() + 624) + SkillID + 2) = Recheck;
                                IPlayer.AddEva(6);
                                CDBSocket::Write(9, "dbw", IPlayer.GetPID(), SkillID, 1);
                                CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 86, 1);
                            }
                        }
                    }

                    if (IPlayer.GetLevel() > 81) {
                        AutoLearn((void*)(DWORD*)(Player + 624), 0, 0);
                    }
                }

                if (SkillID == 89)
                {
                    int Value = 0, Argument = 0, Arg = 0, Check = 0, Recheck = 0;
                    Value = SkillID + (*((DWORD*)((DWORD*)((int)IPlayer.GetOffset() + 624)) + 1) <<
                            16);
                    Undefined::CreateSkillValue((void*)0x004E218C, (int)&Argument, (int)&Value);
                    Check = Undefined::Check((int)0x004E218C, (int)&Arg);

                    if (*(DWORD*)&Argument != *(DWORD*)Check)
                    {
                        Recheck = *(DWORD*)(Undefined::GetValue(&Argument) + 4);

                        if ((*(int (__thiscall**)(int, DWORD, DWORD))(*(DWORD*)Recheck + 60))(Recheck,
                                *(DWORD *)((int)IPlayer.GetOffset() + 60),
                                *(DWORD*)((int)IPlayer.GetOffset() + 464)))
                        {
                            if (Undefined::CheckSkillValue((DWORD*)((int)IPlayer.GetOffset() + 624),
                                    *(DWORD*)(Recheck + 20), *(DWORD *)(Recheck + 24)))
                            {
                                Recheck = (int)Undefined::CheckSkillX((void*)Recheck);
                                Undefined::CheckSkillY(Recheck, SkillID, 1);
                                (*(void (__thiscall **)(int, DWORD, DWORD, DWORD))
                                    (*(DWORD*)Recheck + 8))(Recheck, (int)IPlayer.GetOffset(), 0, 0);
                                *((DWORD*)(DWORD*)((int)IPlayer.GetOffset() + 624) + SkillID + 2) = Recheck;
                                IPlayer.AddDef(31);
                                CDBSocket::Write(9, "dbw", IPlayer.GetPID(), SkillID, 1);
                                CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 87, 1);
                            }
                        }
                    }

                    if (IPlayer.GetLevel() > 81) {
                        AutoLearn((void*)(DWORD*)(Player + 624), 0, 0);
                    }
                }

                return;
            }

            if (IPlayer.GetClass() == 0 && ((SkillID >= 37 && SkillID <= 44) ||
                    (SkillID >= 87 && SkillID <= 89) || SkillID == 70 ||
                    SkillID == 71 || SkillID == 82))
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (!SkillPointer)
                {
                    if (IPlayer.GetSkillPoint() <= 0
                        || !SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 0)) {
                        return;
                    }
                }
            }

            if (IPlayer.GetClass() == 1 && ((SkillID >= 63 && SkillID <= 76)
                    || (SkillID >= 87 && SkillID <= 89) || SkillID == 82))
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (!SkillPointer)
                {
                    if (IPlayer.GetSkillPoint() <= 0
                        || !SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 0)) {
                        return;
                    }
                }
            }

            if (IPlayer.GetClass() == 2 && ((SkillID >= 46 && SkillID <= 51)
                    || (SkillID >= 87 && SkillID <= 89) || SkillID == 82))
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (!SkillPointer)
                {
                    if (IPlayer.GetSkillPoint() <= 0
                        || !SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 0)) {
                        return;
                    }
                }
            }

            if (IPlayer.GetClass() == 3 && ((SkillID >= 0 && SkillID <= 37) ||
                    (SkillID >= 87 && SkillID <= 89) || SkillID == 70 || SkillID == 63))
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (!SkillPointer)
                {
                    if (IPlayer.GetSkillPoint() <= 0
                        || !SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 0)) {
                        return;
                    }
                }
            }

            if (IPlayer.GetClass() == 4 && SkillID >= 0 && SkillID <= 89)
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (!SkillPointer)
                {
                    if (IPlayer.GetSkillPoint() <= 0
                        || !SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 0)) {
                        return;
                    }
                }
            }
        }

        if (packet == 42)
        {
            int SkillID = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "b", &SkillID);

            if (SkillID == 85) {
                SkillID = 87;
            }
            else if (SkillID == 86) {
                SkillID = 88;
            }
            else if (SkillID == 87) {
                SkillID = 89;
            }

            if (SkillID >= 90) {
                return;
            }

            if (SkillID >= 79) {
                return;
            }

            if (IPlayer.GetLevel() >= 81 && SkillID >= 87 && SkillID <= 89) {
                return;
            }

            if (IPlayer.GetClass() == 0 && ((SkillID >= 37 && SkillID <= 44) ||
                    (SkillID >= 87 && SkillID <= 89) || SkillID == 70 ||
                    SkillID == 71 || SkillID == 82))
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (SkillPointer)
                {
                    ISkill xSkill((void*)SkillPointer);

                    if (IPlayer.GetSkillPoint() > 0
                        && SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 1))
                    {
                        CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), SkillID, xSkill.GetGrade() + 1,
                            56);
                        CPlayer::Write(IPlayer.GetOffset(), 81, "bb", SkillID, xSkill.GetGrade() + 1);
                        *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                        IPlayer.RemoveSkillPoint(1);
                    }
                }

                return;
            }

            if (IPlayer.GetClass() == 1 && SkillID == 40)
            {
                int SkillPointer = IPlayer.GetSkillPointer(40);

                if (IPlayer.GetSkillPoint() > 0 && SkillPointer)
                {
                    ISkill xSkill((void*)SkillPointer);

                    if (xSkill.GetGrade() >= 1 && xSkill.GetGrade() < 5)
                    {
                        int Check = (IPlayer.GetLevel() - 47) / 5;

                        if (Check > xSkill.GetGrade())
                        {
                            CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), SkillID, xSkill.GetGrade() + 1,
                                56);
                            CPlayer::Write(IPlayer.GetOffset(), 81, "bb", SkillID, xSkill.GetGrade() + 1);
                            *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                            IPlayer.RemoveSkillPoint(1);
                            return;
                        }
                    }
                }
            }

            if (IPlayer.GetClass() == 1 && SkillID == 26)
            {
                int SkillPointer = IPlayer.GetSkillPointer(26);

                if (IPlayer.GetSkillPoint() > 0 && SkillPointer)
                {
                    ISkill xSkill((void*)SkillPointer);

                    if (xSkill.GetGrade() >= 1 && xSkill.GetGrade() < 5)
                    {
                        if (IPlayer.GetLevel() >= 30)
                        {
                            CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), SkillID, xSkill.GetGrade() + 1,
                                56);
                            CPlayer::Write(IPlayer.GetOffset(), 81, "bb", SkillID, xSkill.GetGrade() + 1);
                            *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                            IPlayer.RemoveSkillPoint(1);
                            return;
                        }
                    }
                }
            }

            if (IPlayer.GetClass() == 1 && ((SkillID >= 63 && SkillID <= 76)
                    || (SkillID >= 87 && SkillID <= 89) || SkillID == 82))
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (SkillPointer)
                {
                    ISkill xSkill((void*)SkillPointer);

                    if (IPlayer.GetSkillPoint() > 0
                        && SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 1))
                    {
                        CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), SkillID, xSkill.GetGrade() + 1,
                            56);
                        CPlayer::Write(IPlayer.GetOffset(), 81, "bb", SkillID, xSkill.GetGrade() + 1);
                        *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                        IPlayer.RemoveSkillPoint(1);
                    }
                }

                return;
            }

            if (IPlayer.GetClass() == 2 && ((SkillID >= 46 && SkillID <= 51) ||
                    (SkillID >= 87 && SkillID <= 89) || SkillID == 70 ||
                    SkillID == 71 || SkillID == 82))
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (SkillPointer)
                {
                    ISkill xSkill((void*)SkillPointer);

                    if (IPlayer.GetSkillPoint() > 0
                        && SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 1))
                    {
                        CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), SkillID, xSkill.GetGrade() + 1,
                            56);
                        CPlayer::Write(IPlayer.GetOffset(), 81, "bb", SkillID, xSkill.GetGrade() + 1);
                        *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                        IPlayer.RemoveSkillPoint(1);
                    }
                }

                return;
            }

            if (IPlayer.GetClass() == 3 && ((SkillID >= 0 && SkillID <= 37) ||
                    (SkillID >= 87 && SkillID <= 89) || SkillID == 70 || SkillID == 63))
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (SkillPointer)
                {
                    ISkill xSkill((void*)SkillPointer);

                    if (IPlayer.GetSkillPoint() > 0 &&
                        SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 1))
                    {
                        CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), SkillID, xSkill.GetGrade() + 1,
                            56);
                        CPlayer::Write(IPlayer.GetOffset(), 81, "bb", SkillID, xSkill.GetGrade() + 1);
                        *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                        IPlayer.RemoveSkillPoint(1);
                    }
                }

                return;
            }

            if (IPlayer.GetClass() == 4 && SkillID >= 0 && SkillID <= 89)
            {
                int SkillPointer = IPlayer.GetSkillPointer(SkillID);

                if (SkillPointer)
                {
                    ISkill xSkill((void*)SkillPointer);

                    if (IPlayer.GetSkillPoint() > 0
                        && SkillUpgradeCheck(IPlayer.GetOffset(), SkillID, 1))
                    {
                        CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), SkillID,
                            xSkill.GetGrade() + 1, 56);
                        CPlayer::Write(IPlayer.GetOffset(), 81, "bb", SkillID,
                            xSkill.GetGrade() + 1);
                        *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                        IPlayer.RemoveSkillPoint(1);
                    }
                }

                return;
            }
        }

        if (packet == 255)
        {
            int TypeCheck = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "d", &TypeCheck);

            if (TypeCheck == 5)
            {
                if (CheckBlob.find(IPlayer.GetPID())->second)
                {
                    CheckBlob[IPlayer.GetPID()] = 0;
                    IPlayer.SystemMessage("Monster blob enabled.", TEXTCOLOR_INFOMSG);
                } else {
                    CheckBlob[IPlayer.GetPID()] = 1;
                    IPlayer.SystemMessage("Monster blob disabled.", TEXTCOLOR_INFOMSG);
                }
            }

            return;
        }

        if (packet == 61)
        {
            int ID = 0;
            char Type;
            CPacket::Read((char*)pPacket, (char*)pPos, "db", &ID, &Type);

            if (IPlayer.IsOnline() && IPlayer.GetID() != ID)
            {
                IPlayer.Kick();
                return;
            }
        }

        if (packet == 43)
        {
            if (IPlayer.IsValid() && IPlayer.IsBuff(349))
            {
                IPlayer.DisableRiding();
                return;
            }

            unsigned __int8 AnimationID = 0;
            int ID = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "bd", &AnimationID, &ID);

            if (IPlayer.IsOnline() && IPlayer.GetID() != ID && (int)AnimationID == 1)
            {
                IPlayer.Kick();
                return;
            }

            if (IPlayer.IsOnline() && AnimationID >= 100 && AnimationID <= 120
                && CChar::IsGState((int)IPlayer.GetOffset(), 512))
            {
                CChar::WriteInSight((void*)Player, 61, "dbbd", IPlayer.GetID(), 5, AnimationID,
                    ID);
                return;
            }

            if (IPlayer.IsOnline() && AnimationID == 74 && IPlayer.GetClass() == 1
                && ID == IPlayer.GetID())
            {
                int pSkill = IPlayer.GetSkillPointer(74);

                if (pSkill)
                {
                    if (CheckIceArrow.count(IPlayer.GetPID()) &&
                        CheckIceArrow.find(IPlayer.GetPID())->second.Delay > GetTickCount())
                    {
                        IPlayer.SystemMessage("Invalid skill prepare time detected!", TEXTCOLOR_RED);
                        return;
                    }

                    if (CheckIceArrow.count(IPlayer.GetPID()) &&
                        CheckIceArrow.find(IPlayer.GetPID())->second.Cooldown > GetTickCount())
                    {
                        IPlayer.SystemMessage("Invalid skill cooldown time detected!", TEXTCOLOR_RED);
                        return;
                    }

                    ISkill xSkill((void*)pSkill);
                    int IceArrowGrade = xSkill.GetGrade();
                    int Mana = ((450 + (IceArrowGrade * ((IceArrowGrade - 1) + 100)))) * 0.42;
                    __int64 GState = 536870912, State = 64, StateEx = 65;

                    if (IPlayer.GetCurMp() <= Mana) {
                        return;
                    }
                    else {
                        IPlayer.DecreaseMana(Mana);
                    }

                    CChar::WriteInSight((void*)Player, 61, "dbbd",
                        IPlayer.GetID(), 5, AnimationID, ID);

                    if (IceArrowGrade == 1)
                    {
                        IPlayer.Buff(290, 18, 0);
                        IPlayer.Buff(295, 18, 0);
                        IPlayer.SendGStateExIceArrow(GState);
                        IPlayer.SendGStateExIceArrow(State << 32);
                    } else if (IceArrowGrade == 2)
                    {
                        IPlayer.Buff(291, 18, 0);
                        IPlayer.Buff(295, 18, 0);
                        IPlayer.SendGStateExIceArrow(GState * 2);
                        IPlayer.SendGStateExIceArrow(State << 32);
                    } else if (IceArrowGrade == 3)
                    {
                        IPlayer.Buff(292, 18, 0);
                        IPlayer.Buff(295, 18, 0);
                        IPlayer.SendGStateExIceArrow(GState * 4);
                        IPlayer.SendGStateExIceArrow(State << 32);
                    } else if (IceArrowGrade == 4)
                    {
                        IPlayer.Buff(293, 18, 0);
                        IPlayer.Buff(295, 18, 0);
                        IPlayer.SendGStateExIceArrow(GState * 8);
                        IPlayer.SendGStateExIceArrow(State << 32);
                    } else if (IceArrowGrade == 5)
                    {
                        IPlayer.Buff(294, 18, 0);
                        IPlayer.Buff(295, 18, 0);
                        IPlayer.SendGStateExIceArrow(GState * 16);
                        IPlayer.SendGStateExIceArrow(StateEx << 32);
                    } else {
                        return;
                    }
                }

                return;
            }
        }

        if (packet == 85)
        {
            int ID = 0;
            unsigned __int8 Type = 0;
            char Kind = 0;
            int Check = CPacket::Read((char*)pPacket, (char*)pPos, "b", &Type);

            if (Type == 1)
            {
                CPacket::Read((char*)Check, (char*)pPos, "db", &ID, &Kind);
                void *GetPlayer = CPlayer::FindPlayer(ID);

                if (GetPlayer)
                {
                    IChar Player(GetPlayer);

                    if (Player.IsOnline())
                    {
                        if (Player.GetLevel() > 15)
                        {
                            IPlayer.Kick();
                            return;
                        }
                    }
                }
            }
        }

        if (packet == 179)
        {
            char Type = 0;
            int Key = 0;
            CPacket::Read((char*)pPacket, (char*)pPos, "bw", &Type, &Key);
            int Rate = CTools::Rate(1, 1000);

            if (Type == 1 && Key)
            {
                if (CPlayer::GetInvenSize(Player) >= IPlayer.MaxInventorySize())
                {
                    IPlayer.BoxMsg("Your inventory is full.");
                    return;
                }

                if (Key == 1 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2655, 20)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 1000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 20, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2657, 0, 5, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2658, 0, 2, -1);
                    }

                    return;
                }

                if (Key == 2 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2656, 5)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 1000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 20, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2657, 0, 5, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2658, 0, 2, -1);
                    }

                    return;
                }

                if (Key == 3 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2657, 5)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 1000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2655, 0, 20, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2656, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2657, 0, 5, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2658, 0, 2, -1);
                    }

                    return;
                }

                if (Key == 4 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2659, 20)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 5000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 20, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2661, 0, 5, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2662, 0, 2, -1);
                    }

                    return;
                }

                if (Key == 5 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2660, 5)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 5000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 20, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2661, 0, 5, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2662, 0, 2, -1);
                    }

                    return;
                }

                if (Key == 6 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2661, 5)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 5000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2659, 0, 20, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2660, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2661, 0, 5, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2662, 0, 2, -1);
                    }

                    return;
                }

                if (Key == 7 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2663, 10)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 5000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 10, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2665, 0, 5, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2666, 0, 2, -1);
                    }

                    return;
                }

                if (Key == 8 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2664, 5)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 5000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 10, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2665, 0, 5, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2666, 0, 2, -1);
                    }

                    return;
                }

                if (Key == 9 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2665, 5)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 5000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2663, 0, 10, -1);
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2664, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2665, 0, 5, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2666, 0, 2, -1);
                    }

                    return;
                }

                if (Key == 10 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2667, 10)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 10000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                if (Rate >= 950)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 10, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 5, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2669, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2670, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2538, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 11 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2668, 5)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 10000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                if (Rate >= 950)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 10, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 5, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2669, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2670, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2538, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 12 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2669, 5)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 10000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                if (Rate >= 950)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 10, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 5, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2669, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2670, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2538, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 13 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2670, 1)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 10000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                if (Rate >= 950)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2667, 0, 10, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2668, 0, 5, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2669, 0, 5, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2670, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2538, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 14 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2671, 10)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 30000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                if (Rate >= 950)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2671, 0, 10, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2672, 0, 5, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2673, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2674, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2675, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 15 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2672, 5)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 30000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                if (Rate >= 950)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2671, 0, 10, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2672, 0, 5, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2673, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2674, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2675, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 16 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2673, 1)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 30000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                if (Rate >= 950)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2671, 0, 10, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2672, 0, 5, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2673, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2674, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2675, 0, 1, -1);
                    }

                    return;
                }

                if (Key == 17 && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 2674, 1)
                    && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, 31, 30000))
                {
                    if (Rate >= 550)
                    {
                        if (Rate >= 750)
                        {
                            if (Rate >= 900)
                            {
                                if (Rate >= 950)
                                {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2671, 0, 10, -1);
                                } else {
                                    CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2672, 0, 5, -1);
                                }
                            } else {
                                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2673, 0, 1, -1);
                            }
                        } else {
                            CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2674, 0, 1, -1);
                        }
                    } else {
                        CItem::InsertItem((int)IPlayer.GetOffset(), 27, 2675, 0, 1, -1);
                    }

                    return;
                }
            }

            return;
        }

        CPlayer::Process((void*)Player, packet, (void*)pPacket, pPos);

        if (IPlayer.IsOnline() && packet == 18 && IPlayer.GetClass() == 4
            && IPlayer.IsBuff(406)) {
            CPlayer::Write(IPlayer.GetOffset(), 148, "dI", IPlayer.GetID(), (__int64)0);
        }

        if (IPlayer.IsOnline() && packet == 67 && CChar::IsGState(Player, 16)
            && !IPlayer.IsBuff(297))
        {
            IPlayer.Buff(297, 604800, 0);
            ShopLimit[IPlayer.GetIP()] = 1;
        }
    }
}
