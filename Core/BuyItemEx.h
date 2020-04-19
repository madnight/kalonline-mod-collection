signed int __fastcall PlayerRemoveItem(void *Player, void *edx, int Value, int Index, int Amount)
{
    IChar IPlayer(Player);

    if (IPlayer.IsOnline() && (Index == 509 || Index == 510))
    {
        if (IPlayer.GetMap() == BFMap || IPlayer.GetMap() == ScenarioMap ||
                IPlayer.GetMap() == LMSMap || IPlayer.GetMap() == HellMap ||
                IPlayer.GetMap() == PLMap)
        {
            IPlayer.BoxMsg("Saving location is not allowed during the battle.");
            return 0;
        }
    }

    return CPlayer::RemoveItem(Player,Value,Index,Amount);
}

int __fastcall NPCTick(void *NPC, void *edx)
{
    if (Protect32::Active == true && Protect32::Time == 1200 &&
            *(DWORD*)((int)NPC + 448) == PLRNPC && !*(DWORD *)((int)NPC + 480))
    {
        (*(void (__thiscall **)(DWORD, DWORD))(*(DWORD*)(int)NPC + 100))((int)NPC, 16);
        *(DWORD *)((int)NPC + 480) = 1197000 + GetTickCount();
    }

    if (Protect32::Active == true && Protect32::Time == 1200 &&
            *(DWORD*)((int)NPC + 448) == PLBNPC && !*(DWORD *)((int)NPC + 480))
    {
        (*(void (__thiscall **)(DWORD, DWORD))(*(DWORD*)(int)NPC + 100))((int)NPC, 16);
        *(DWORD *)((int)NPC + 480) = 1197000 + GetTickCount();
    }

    return CNPCDoor::Tick(NPC);
}

void __fastcall BuyItemEx(void *Player, void *edx, char Npc, int Tax, int ItemSize, int pPacket, int pPos)
{
    IChar IPlayer(Player);

    if (IPlayer.IsOnline())
    {
        int Check = pPacket, Amount = 0, Index = 0, Item = 0, Price = 0;
        unsigned __int16 ItemIndex = 0, ItemAmount = 0;

        if (ItemSize <= 0)
            return;

        if (ItemSize > 100)
            return;

        for (int i = 0; *((DWORD*)Player + 274) && i < ItemSize; i++)
        {
            Check = CPacket::Read((char*)Check, (char*)pPos, (const char*)0x004BADB4,
                    &ItemIndex, &ItemAmount);
            Amount = ItemAmount;
            Index = ItemIndex;

            if (Amount > 0)
            {
                Item = CItem::CreateItem(Index, 0, Amount, -1);

                if (Item)
                {
                    Price = (int)*(DWORD*)(*(DWORD*)(Item + 40) + 108);

                    if (Price <= 0)
                    {
                        CBase::Delete((void*)Item);
                        return;
                    }

                    int Check = 2147483647 / Price;

                    if (Amount >= Check)
                    {
                        CBase::Delete((void*)Item);
                        return;
                    }

                    CBase::Delete((void*)Item);
                }
            }
        }

        CPlayer::BuyItemEx(Player, Npc, Tax, ItemSize, pPacket, pPos);
    }
}
