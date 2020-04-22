#define ICI Item.CheckIndex()


int __fastcall ItemUse(void *ItemOffset, void *edx, int PlayerOffset)
{
    IItem Item(ItemOffset);
    IChar IPlayer((void*)PlayerOffset);

    if (IPlayer.IsOnline() && ICI == 3387)
    {
        if (CPlayer::GetInvenSize((int)IPlayer.GetOffset()) <
            IPlayer.MaxInventorySize())
        {
            int xItem = CItem::CreateItem(3384, 0, 1, -1);

            if (xItem)
            {
                IItem IItem((void*)xItem);

                if (CPlayer::_InsertItem(IPlayer.GetOffset(), 27, xItem) != 1) {
                    return Item.GetAmount();
                }

                int Value = CTools::Rate(0, 12);
                int Add = 50;

                if (Value == 12) {
                    Add = CTools::Rate(10, 100);
                }

                CPlayer::Write(IPlayer.GetOffset(), 193, "ddd", IItem.GetIID(), Value, Add);
                GetItemStat[IItem.GetIID()] = Value+(Add*1000);
                CDBSocket::Write(90, "ddd", IPlayer.GetPID(), Value+(Add*1000), IItem.GetIID());
            }
        } else {
            IPlayer.SystemMessage("Inventory is full.", TEXTCOLOR_PINK);
            return Item.GetAmount();
        }

        (*(int (__thiscall **)(DWORD, void *, signed int,
                    signed int))(*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(),
                        9,
                        -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 3104 && IPlayer.IsBuff(334)) {
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 3104 && !IPlayer.IsBuff(334))
    {
        IPlayer.Buff(334, 3, 0);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ((ICI >= 3412
                && ICI <= 3419) || (ICI >= 4149
                && ICI <= 4153) || (ICI >= 4156
                && ICI <= 4160) || (ICI >= 6021
                && ICI <= 6024)) && CChar::IsGState((int)IPlayer.GetOffset(), 4)) {
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ((ICI >= 3412
                && ICI <= 3419) || (ICI >= 4149
                && ICI <= 4153) || (ICI >= 4156
                && ICI <= 4160) || (ICI >= 6021
                && ICI <= 6024)) && CChar::IsGState((int)IPlayer.GetOffset(), 512)) {
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ((ICI >= 3412
                && ICI <= 3419) || (ICI >= 4149
                && ICI <= 4153) || (ICI >= 4156
                && ICI <= 4160) || (ICI >= 6021
                && ICI <= 6024)) && (IPlayer.IsBuff(18) || IPlayer.IsBuff(19)
            || IPlayer.IsBuff(313) || IPlayer.IsBuff(329))) {
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ((ICI >= 3412
                && ICI <= 3419) || (ICI >= 4149
                && ICI <= 4153) || (ICI >= 4156
                && ICI <= 4160) || (ICI >= 6021
                && ICI <= 6024)) && !IPlayer.IsBuff(349)) {
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ((ICI >= 3412
                && ICI <= 3419) || (ICI >= 4149
                && ICI <= 4153) || (ICI >= 4156
                && ICI <= 4160) || (ICI >= 6021
                && ICI <= 6024)) && IPlayer.IsBuff(349)) {
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && BufferCheck.count(ICI)
        && BufferCheck.find(ICI)->second.Index == ICI)
    {
        if (IPlayer.GetLevel() <= BufferCheck.find(ICI)->second.Limit)
        {
            IPlayer.Buff(48, 1800, 8*(BufferCheck.find(ICI)->second.Grade)+3);
            IPlayer.Buff(50, 1800, 8*(BufferCheck.find(ICI)->second.Grade)+3);
            IPlayer.Buff(47, 1800, 8*(BufferCheck.find(ICI)->second.Grade)+3);
            IPlayer.Buff(49, 1800, 8*(BufferCheck.find(ICI)->second.Grade)+3);
            IPlayer.Buff(46, 1800, 8*(BufferCheck.find(ICI)->second.Grade)+3);
            IPlayer.Buff(36, 1800, 8*(BufferCheck.find(ICI)->second.Grade)+16);
            CChar::CancelAllBuff(IPlayer.GetOffset(), 37);
            int AddBuff = CBuff::CreateBuff(37, 1800,
                    30*(BufferCheck.find(ICI)->second.Grade)+5,
                    20*(BufferCheck.find(ICI)->second.Grade)+5);
            (*(int (__thiscall **)(int, int))(*(DWORD *)PlayerOffset + 180))(PlayerOffset,
                AddBuff);
            IPlayer.Buff(12, 1800, 45);
        } else {
            IPlayer.SystemMessage("Your level is too high!", TEXTCOLOR_RED);
            return Item.GetAmount();
        }

        if (BufferCheck.find(ICI)->second.Delete)
            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);

        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && (ICI >= 187 && ICI <= 196) || ICI == 484 ||
        ICI == 485 || (ICI >= 2157 && ICI <= 2160))
    {
        if ((IPlayer.IsBuff(160) || IPlayer.IsBuff(161) || IPlayer.IsBuff(162)
                || IPlayer.IsBuff(163) || IPlayer.IsBuff(170) || IPlayer.IsBuff(171)
                || IPlayer.IsBuff(373) || IPlayer.IsBuff(374) || IPlayer.IsBuff(378)))
        {
            IPlayer.SystemMessage("You can not teleport while in battle.", TEXTCOLOR_RED);
            return Item.GetAmount();
        }
    }

    if (IPlayer.IsOnline() && SkillBook.count(ICI)
        && SkillBook.find(ICI)->second.Index)
    {
        if (IPlayer.GetClass() == SkillBook.find(ICI)->second.Class)
        {
            if (IPlayer.GetSkillPointer(SkillBook.find(ICI)->second.Action))
            {
                ISkill ISkill((void*)IPlayer.GetSkillPointer(SkillBook.find(
                            ICI)->second.Action));

                if (ISkill.GetGrade() < SkillBook.find(ICI)->second.UpgradeMax)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(),
                        SkillBook.find(ICI)->second.Action,
                        ISkill.GetGrade() + SkillBook.find(ICI)->second.UpgradeAmount,
                        56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb",
                        SkillBook.find(ICI)->second.Action,
                        ISkill.GetGrade() + SkillBook.find(ICI)->second.UpgradeAmount);
                    *(DWORD*)((int)ISkill.GetOffset() + 8) = ISkill.GetGrade() + SkillBook.find(
                            ICI)->second.UpgradeAmount;
                    (*(int (__thiscall **)(DWORD, void *, signed int,
                                signed int))(*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(),
                                    9,
                                    -1);
                    IPlayer.SystemMessage("Skill successfully upgraded.", TEXTCOLOR_GREEN);
                    return Item.GetAmount();
                } else {
                    IPlayer.SystemMessage("You already have max grade of skill.", TEXTCOLOR_RED);
                    return Item.GetAmount();
                }
            } else {
                IPlayer.SystemMessage("First you must to get skill to upgrade it.",
                    TEXTCOLOR_RED);
                return Item.GetAmount();
            }
        } else {
            IPlayer.SystemMessage("Skill book is not for your class.", TEXTCOLOR_RED);
            return Item.GetAmount();
        }
    }

    if (IPlayer.IsOnline() && ICI == 482)
    {
        if (Protect32::Active == true && IPlayer.GetGID())
        {
            if (IPlayer.GetGID() == Protect32::GuildFirst
                || IPlayer.GetGID() == Protect32::GuildSecond) {
                return Item.GetAmount();
            }
        }

        if (CGuild::IsWarringPeriod())
        {
            if (CSMap::IsOnTile(*(void **)((int)IPlayer.Offset + 320),
                    (int)IPlayer.Offset + 332, 1048576)) {
                return Item.GetAmount();
            }
        }
    }

    if (IPlayer.IsOnline() && (ICI == 47 || ICI == 2441
            || ICI == 48 || ICI == 2442
            || ICI == 2055 || ICI == 2443)
        && IPlayer.IsBuff(120))
    {
        if (CInitItem::Use(*((DWORD *)ItemOffset + 10), PlayerOffset))
        {
            if ((ICI == 47 || ICI == 2441)
                && IPlayer.IsBuff(120)
                && (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                    (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1))
            {
                if (IPlayer.IsValid()) {
                    IPlayer.IncreaseHp(10);
                }
            }

            if ((ICI == 48 || ICI == 2442)
                && IPlayer.IsBuff(120)
                && (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                    (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9,
                    -1))
            {
                if (IPlayer.IsValid()) {
                    IPlayer.IncreaseHp(30);
                }
            }

            if ((ICI == 2055 || ICI == 2443)
                && IPlayer.IsBuff(120)
                && (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                    (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1))
            {
                if (IPlayer.IsValid()) {
                    IPlayer.IncreaseHp(50);
                }
            }

            if (*(DWORD *)(*((DWORD *)ItemOffset + 10) + 172))
                CChar::WriteInRect((int)IPlayer.GetOffset(), 73, 15, "db", IPlayer.GetID(),
                    *(DWORD *)(*((DWORD *)ItemOffset + 10) + 172));

            return Item.GetAmount();
        }
    }

    if (IPlayer.IsOnline() && ICI == 2001)
    {
        IPlayer.Buff(119, 1296000, 0);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9,
                -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2198)
    {
        IPlayer.Buff(120, 1296000, 0);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9,
                -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2160)
    {
        IPlayer.Teleport(6, 359660, 233716);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9,
                -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2159)
    {
        if (IPlayer.IsParty())
        {
            void *Party = (void*)CParty::FindParty(IPlayer.GetPartyID());

            if (Party)
            {
                for (int i = CParty::GetPlayerList(Party); i; i = CBaseList::Pop((void*)i))
                {
                    IChar IMembers((void*)*(DWORD*)((void*)i));

                    if (IPlayer.IsOnline() && IMembers.IsOnline()) {
                        IMembers.Teleport(6, 359660, 233716);
                    }
                }
            }

            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
            return Item.GetAmount();

        } else {

            IPlayer.Teleport(6, 359660, 233716);
            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
            return Item.GetAmount();
        }
    }

    if (IPlayer.IsOnline() && ICI == 2158)
    {
        IPlayer.Teleport(6, 360931, 187024);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2157)
    {
        if (IPlayer.IsParty())
        {
            void *Party = (void*)CParty::FindParty(IPlayer.GetPartyID());

            if (Party)
            {
                for (int i = CParty::GetPlayerList(Party); i; i = CBaseList::Pop((void*)i))
                {
                    IChar IMembers((void*)*(DWORD*)((void*)i));

                    if (IPlayer.IsOnline() && IMembers.IsOnline()) {
                        IMembers.Teleport(6, 360931, 187024);
                    }
                }
            }

            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9,
                    -1);
            return Item.GetAmount();
        } else {
            IPlayer.Teleport(6, 360931, 187024);
            (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
            return Item.GetAmount();
        }
    }

    if (IPlayer.IsOnline() && ICI == 447)
    {
        if (IPlayer.IsBuff(12)) {
            IPlayer.CancelBuff(12);
        }
    }

    if (IPlayer.IsOnline() && ICI == 2366 && !IPlayer.IsBuff(272))
    {
        IPlayer.Buff(272, 1800, 0);
        IPlayer.Buff(261, 1810, 0);
        IPlayer.SetBuffIcon(1800000, 0, 3645, 430);
        IPlayer.IncreaseMaxHp(1450);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9,
                -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2367 && !IPlayer.IsBuff(262))
    {
        IPlayer.Buff(262, 1800, 0);
        IPlayer.Buff(263, 1810, 0);
        IPlayer.SetBuffIcon(1800000, 0, 3646, 431);
        IPlayer.IncreaseMaxMp(900);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9,
                -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2076 && !IPlayer.IsBuff(264))
    {
        IPlayer.Buff(264, 3600, 0);
        IPlayer.Buff(265, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3601, 415);
        IPlayer.IncreaseMaxHp(500);
        IPlayer.IncreaseMaxMp(500);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2079 && !IPlayer.IsBuff(266))
    {
        IPlayer.Buff(266, 3600, 0);
        IPlayer.Buff(267, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3604, 418);
        IPlayer.AddMaxAttack(75);
        IPlayer.AddMinAttack(50);
        IPlayer.AddEva(10);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2078 && !IPlayer.IsBuff(268))
    {
        IPlayer.Buff(268, 3600, 0);
        IPlayer.Buff(269, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3603, 417);
        IPlayer.AddMaxAttack(100);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2077 && !IPlayer.IsBuff(270))
    {
        IPlayer.Buff(270, 3600, 0);
        IPlayer.Buff(271, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3602, 416);
        IPlayer.AddMinAttack(75);
        IPlayer.AddOTP(10);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == EmokCert)
    {
        if (IPlayer.IsBuff(156)) {
            IPlayer.Buff(156, IPlayer.GetBuffRemain(156)+3600, 0);
        }
        else {
            IPlayer.Buff(156, CheckEmok.find(IPlayer.GetPID())->second.Time+3600, 0);
        }

        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2430 && !IPlayer.IsBuff(121))
    {
        IPlayer.Buff(121, 3600, 0);
        IPlayer.Buff(273, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3877, 442);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2431 && !IPlayer.IsBuff(122))
    {
        IPlayer.Buff(122, 3600, 0);
        IPlayer.Buff(274, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3879, 444);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2433 && !IPlayer.IsBuff(123))
    {
        IPlayer.Buff(123, 3600, 0);
        IPlayer.Buff(275, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3886, 451);
        IPlayer.AddOTP(15);
        (*(int (__thiscall **)(DWORD, void *, signed int,
                    signed int))(*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(),
                        9,
                        -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2434 && !IPlayer.IsBuff(124))
    {
        IPlayer.Buff(124, 3600, 0);
        IPlayer.Buff(276, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3880, 445);
        IPlayer.AddEva(7);
        (*(int (__thiscall **)(DWORD, void *, signed int,
                    signed int))(*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(),
                        9,
                        -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2438 && !IPlayer.IsBuff(125))
    {
        IPlayer.Buff(125, 3600, 0);
        IPlayer.Buff(277, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3885, 450);
        IPlayer.AddHp(12);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2439 && !IPlayer.IsBuff(126))
    {
        IPlayer.Buff(126, 3600, 0);
        IPlayer.Buff(278, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3884, 449);
        IPlayer.AddWis(12);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2436 && !IPlayer.IsBuff(127))
    {
        IPlayer.Buff(127, 3600, 0);
        IPlayer.Buff(279, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3883, 448);
        IPlayer.AddInt(7);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2437 && !IPlayer.IsBuff(128))
    {
        IPlayer.Buff(128, 3600, 0);
        IPlayer.Buff(280, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3882, 447);
        IPlayer.AddAgi(7);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 2435 && !IPlayer.IsBuff(129))
    {
        IPlayer.Buff(129, 3600, 0);
        IPlayer.Buff(281, 3610, 0);
        IPlayer.SetBuffIcon(3600000, 0, 3881, 446);
        IPlayer.AddStr(7);
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI >= 1299
        && ICI <= 1317)
    {
        IPlayer.OpenHTML(598702+ICI);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI >= 1328
        && ICI <= 1365)
    {
        IPlayer.OpenHTML(598692+ICI);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI >= 1741
        && ICI <= 1745)
    {
        IPlayer.OpenHTML(598317+ICI);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI >= 1796
        && ICI <= 1800)
    {
        IPlayer.OpenHTML(598267+ICI);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI >= 2061
        && ICI <= 2069)
    {
        IPlayer.OpenHTML(598007+ICI);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI >= 2417
        && ICI <= 2419)
    {
        IPlayer.OpenHTML(597660+ICI);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI >= 3060
        && ICI <= 3069)
    {
        IPlayer.OpenHTML(597020+ICI);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 3090)
    {
        IPlayer.OpenHTML(600090);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 1118)
    {
        CheckHonor[IPlayer.GetPID()].HPx += 1;
        CheckHonor[IPlayer.GetPID()].RPx += 10;
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 1119)
    {
        CheckHonor[IPlayer.GetPID()].HPx += 3;
        CheckHonor[IPlayer.GetPID()].RPx += 30;
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 1120)
    {
        CheckHonor[IPlayer.GetPID()].HPx += 5;
        CheckHonor[IPlayer.GetPID()].RPx += 50;
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    if (IPlayer.IsOnline() && ICI == 1121)
    {
        CheckHonor[IPlayer.GetPID()].HPx += 10;
        CheckHonor[IPlayer.GetPID()].RPx += 100;
        (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
            (*(DWORD*)ItemOffset + 120))((int)ItemOffset, IPlayer.GetOffset(), 9, -1);
        return Item.GetAmount();
    }

    return CItemGeneral::Use(ItemOffset, PlayerOffset);
}
