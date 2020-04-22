signed int __fastcall DefenseChangePrefix(void *Item, void* edx, int Player,
    int ID,
    int Chance, int Argument)
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

    if (CItem::IsState((int)IItem.GetOffset(), 1) || ID >= 0 && ID != 1) {
        return 0;
    }

    if (IItem.Prefix()) {
        CurrentPrefix = IItem.PrefixID();
    }

    NewPrefix = CurrentPrefix;
    int Rate = CTools::Rate(1, 100);
    int CheckPolish = CItem::IsState((int)IItem.GetOffset(), 64);

    for (signed int i = 0; i < 2; ++i)
    {
        if (Rate <= (int)*(DWORD*)(Chance + 4 * i))
        {
            NewPrefix = *(DWORD *)(Argument + 4 * i);
            break;
        }
    }

    if (CurrentPrefix == NewPrefix)
    {
        if (CheckPolish)
        {
            CDBSocket::Write(21, "dddbb", IItem.GetIID(), IPlayer.GetID(), 64, 0, 255);
            CItem::SubState((int)IItem.GetOffset(), 64);
            CItem::SendItemInfo(IItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
            return 1;
        }

        if (IItem.GetEndurance() >= 5) {
            IItem.DecreaseEndurance(5);
        }
        else {
            IItem.DecreaseEndurance(IItem.GetEndurance());
        }

        if (IItem.GetEndurance() <= 0)
        {
            CPlayer::Write(IPlayer.GetOffset(), 91, "db", IItem.GetIID(),
                IItem.GetEndurance());
            CDBSocket::Write(3, "ddwdbddd", IItem.GetIID(), IPlayer.GetID(),
                IItem.CheckIndex(), 1, 27, 0, 0,
                0);

            if (CItem::GetLevel((int)IItem.GetOffset()) >= 40) {
                CItem::InsertItem((int)IPlayer.GetOffset(), 27, 517, 0, 15, -1);
            }

            CBase::Delete(IItem.GetOffset());
        } else {
            CPlayer::Write(IPlayer.GetOffset(), 91, "db", IItem.GetIID(),
                IItem.GetEndurance());
            CDBSocket::Write(18, "ddb", IItem.GetIID(), IPlayer.GetID(),
                IItem.GetEndurance());
        }
    } else {
        int CurrentInfo = 0;

        if (IItem.GetInfo()) {
            CurrentInfo = IItem.GetInfo();
        }

        if (NewPrefix == BofConfigRead)
        {
            if (CurrentInfo & 2097152)
            {
                IPlayer.BoxMsg("Bead of Fire is already equipped.");
                return 0;
            } else if (CItem::GetLevel((int)IItem.GetOffset()) < 46)
            {
                IPlayer.BoxMsg("Bead of Fire can not be equipped on this armor.");
                return 0;
            } else {
                CDBSocket::Write(21, "dddbb", IItem.GetIID(), IPlayer.GetID(), IItem.GetInfo(),
                    0, 0);
                IItem.SetInfo(2097152 + CurrentInfo);
                CDBSocket::Write(21, "dddbb", IItem.GetIID(), IPlayer.GetID(),
                    2097152 + CurrentInfo, 8, 7);
                CItem::SendItemInfo(IItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
                IPlayer.BoxMsg("Equipping the Bead of Fire has succeeded.");
                return 1;
            }
        }

        if (WeaponReplace.count(IItem.CheckIndex()) &&
            WeaponReplaceIndex.count(IItem.CheckIndex()))
        {
            if (WeaponReplace.find(IItem.CheckIndex())->second == NewPrefix)
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
                int ReplaceDef = 0, ReplaceEva = 0, ReplaceGem = 0;
                int ItemStat = GetItemStat.find(IItem.GetIID())->second;

                if (*(DWORD *)((int)Item + 44)) {
                    ReplacePrefix = *(DWORD *)(*(DWORD *)((int)Item + 44) + 32);
                }

                if (*(DWORD *)((int)Item + 48)) {
                    ReplaceInfo = *(DWORD *)((int)Item + 48);
                }

                if (*(DWORD *)((int)Item + 108)) {
                    ReplaceDef = *(DWORD *)((int)Item + 108);
                }

                if (*(DWORD *)((int)Item + 116)) {
                    ReplaceEva = *(DWORD *)((int)Item + 116);
                }

                if (*(DWORD *)((int)Item + 84)) {
                    ReplaceGem = *(DWORD *)((int)Item + 84);
                }

                int ItemNewIndex = IItem.CheckIndex();
                int DeleteCheck = (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                        (*(DWORD*)Item + 120))((int)Item, IPlayer.GetOffset(), 9, -1);

                if (!DeleteCheck)
                {
                    ReplaceItem = CItem::CreateItem(
                            WeaponReplaceIndex.find(ItemNewIndex)->second, ReplacePrefix, 1, -1);

                    if (ReplaceItem)
                    {
                        CIOObject::AddRef(ReplaceItem);
                        *(DWORD *)(ReplaceItem + 48) = ReplaceInfo;
                        *(DWORD *)(ReplaceItem + 108) = ReplaceDef;
                        *(DWORD *)(ReplaceItem + 116) = ReplaceEva;
                        *(DWORD *)(ReplaceItem + 84) = ReplaceGem;

                        if (CPlayer::_InsertItem(IPlayer.GetOffset(), 27, ReplaceItem) != 1)
                        {
                            CConsole::Red("Real time armor insert item Null error [PID (%d)] ",
                                IPlayer.GetPID());
                            CBase::Delete((void *)ReplaceItem);
                            CIOCriticalSection::Leave((void*)((char *)IPlayer.GetOffset() + 1020));
                            return 0;
                        }

                        CIOObject::Release((void *)ReplaceItem);
                        GetItemStat[*(DWORD *)(ReplaceItem + 36)] = ItemStat;
                        CDBSocket::Write(90, "ddd", IPlayer.GetPID(), ItemStat,
                            *(DWORD *)(ReplaceItem + 36));
                        CDBSocket::Write(87, "ddd", IPlayer.GetPID(), *(DWORD *)(ReplaceItem + 84),
                            *(DWORD *)(ReplaceItem + 36));
                        CDBSocket::Write(21, "dddbb", *(DWORD *)(ReplaceItem + 36),
                            *(DWORD *)(ReplaceItem + 32), *(DWORD *)(ReplaceItem + 48), 8, 7);
                        CDBSocket::Write(17, "ddbbb", *(DWORD *)(ReplaceItem + 36),
                            *(DWORD *)(ReplaceItem + 32), 15, *(DWORD *)(ReplaceItem + 108), 0);
                        CDBSocket::Write(17, "ddbbb", *(DWORD *)(ReplaceItem + 36),
                            *(DWORD *)(ReplaceItem + 32), 10, *(DWORD *)(ReplaceItem + 116), 0);
                        CItem::SendItemInfo((void*)ReplaceItem, (int)IPlayer.GetOffset(), 92);
                        CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, 0, 0, 128, 255);
                    }
                } else {
                    return 0;
                }

                return 1;
            }
        }

        if (WeaponReplacePrefix.count(NewPrefix))
        {
            IPlayer.BoxMsg("Enchanting item and the talisman are different.");
            return 0;
        }

        if (ArmorPimpConfig.count(NewPrefix))
        {
            *(DWORD *)((int)Item + 108) = ArmorPimpConfig.find(NewPrefix)->second;
            *(DWORD *)((int)Item + 116) = 1;
            CDBSocket::Write(17, "ddbbb", *(DWORD *)((int)Item + 36),
                *(DWORD *)((int)Item + 32),
                15, *(DWORD *)((int)Item + 108), 0);
            CDBSocket::Write(17, "ddbbb", *(DWORD *)((int)Item + 36),
                *(DWORD *)((int)Item + 32),
                10, *(DWORD *)((int)Item + 116), 0);
            CItem::SendItemInfo(IItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
            return 1;
        }

        AddPrefix = CItem::FindPrefix(NewPrefix);

        if (!AddPrefix) {
            return 0;
        }

        *(DWORD *)((int)IItem.GetOffset() + 44) = AddPrefix;
        CDBSocket::Write(19, "ddbb", IItem.GetIID(), IPlayer.GetID(), NewPrefix);

        if (CheckPolish) {
            CItem::SubState((int)IItem.GetOffset(), 64);
        }

        CItem::SendItemInfo(IItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
    }

    return 1;
}
