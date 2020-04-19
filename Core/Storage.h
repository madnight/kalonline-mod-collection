signed int __fastcall CItemGeneralStorageIn(int Item, void *edx, int Player, int Argument)
{
    IItem IItem((void*)Item);
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline())
    {
        if (IItem.GetInfo() & 128)
        {
            IPlayer.SystemMessage("Bound items can not be check in.", TEXTCOLOR_RED);
            return 0;
        } else if (IItem.GetInfo() & 4194304)
        {
            IPlayer.SystemMessage("Locked items can not be check in.", TEXTCOLOR_RED);
            return 0;
        } else {
            return CItemGeneral::StorageIn(Item,Player,Argument);
        }
    } else {
        return 0;
    }
}

signed int __fastcall CItemWeaponStorageIn(void *Item, void *edx, int Player, int Argument)
{
    IItem IItem(Item);
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline())
    {
        if (IItem.GetInfo() & 128)
        {
            IPlayer.SystemMessage("Bound items can not be check in.", TEXTCOLOR_RED);
            return 0;
        } else if (IItem.GetInfo() & 4194304)
        {
            IPlayer.SystemMessage("Locked weapons can not be check in.", TEXTCOLOR_RED);
            return 0;
        } else {
            return CItemWeapon::StorageIn(Item,Player,Argument);
        }
    } else {
        return 0;
    }
}

signed int __fastcall CItemDefenseStorageIn(void *Item, void *edx, int Player, int Argument)
{
    IItem IItem(Item);
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline())
    {
        if (IItem.GetInfo() & 128)
        {
            IPlayer.SystemMessage("Bound items can not be check in.", TEXTCOLOR_RED);
            return 0;
        } else if (IItem.GetInfo() & 4194304)
        {
            IPlayer.SystemMessage("Locked armors can not be check in.", TEXTCOLOR_RED);
            return 0;
        } else {
            return CItemDefense::StorageIn(Item,Player,Argument);
        }
    } else {
        return 0;
    }
}

signed int __fastcall CItemOrnamentStorageIn(int Item, void *edx, int Player, int Argument)
{
    IItem IItem((void*)Item);
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline())
    {
        if (IItem.GetInfo() & 128)
        {
            IPlayer.SystemMessage("Bound items can not be check in.", TEXTCOLOR_RED);
            return 0;
        } else if (IItem.GetInfo() & 4194304)
        {
            IPlayer.SystemMessage("Locked ornaments can not be check in.", TEXTCOLOR_RED);
            return 0;
        } else {
            return CItemOrnament::StorageIn(Item,Player,Argument);
        }
    } else {
        return 0;
    }
}