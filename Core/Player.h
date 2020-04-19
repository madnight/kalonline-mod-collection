void __fastcall MyGameStart(void *Player, void *edx)
{
    IChar IPlayer(Player);

    if (IPlayer.IsOnline())
    {
        if (IPlayer.GetX() < 0 || IPlayer.GetY() < 0 || IPlayer.GetZ() < 0)
        {
            IPlayer.SetX(257514);
            IPlayer.SetY(259273);
            IPlayer.SetZ(16168);
            SaveAllProperty((int)Player, 0, 0);
            IPlayer.Kick();
            return;
        }

        CPlayer::GameStart(Player);

        if (IPlayer.IsOnline())
        {
            int First = IPlayer.GetBuffRemain(172);
            int Second = IPlayer.GetBuffRemain(173);
            int Third = IPlayer.GetBuffRemain(174);

            if (First && Second && Third)
            {
                CPlayer::Write(IPlayer.GetOffset(),204,"d",108);
                CPlayer::Write(IPlayer.GetOffset(),181,"dwd",IPlayer.GetID(),499,First);
                CPlayer::Write(IPlayer.GetOffset(),181,"dwd",IPlayer.GetID(),500,Second);
                CPlayer::Write(IPlayer.GetOffset(),181,"dwd",IPlayer.GetID(),501,Third);
            }

            if (!First && Second && Third)
            {
                CPlayer::Write(IPlayer.GetOffset(),204,"d",72);
                CPlayer::Write(IPlayer.GetOffset(),181,"dwd",IPlayer.GetID(),499,Second);
                CPlayer::Write(IPlayer.GetOffset(),181,"dwd",IPlayer.GetID(),500,Third);
            }

            if (!First && !Second && Third)
            {
                CPlayer::Write(IPlayer.GetOffset(),204,"d",36);
                CPlayer::Write(IPlayer.GetOffset(),181,"dwd",IPlayer.GetID(),499,Third);
            }
        }

        if (IPlayer.IsOnline())
        {
            std::string Date = "./Exception/IP_LOG_" + Time::GetDay() + "_" +
                               Time::GetMonth() + "_" + Time::GetYear() + ".txt";
            std::fstream IPLOG;
            IPLOG.open(Date, std::fstream::in | std::fstream::out | std::fstream::app);
            IPLOG << IPlayer.GetName() << " - " << IPlayer.GetIP() << std::endl;
            IPLOG.close();
        }

        if (IPlayer.IsOnline() && IPlayer.GetLevel() < 81)
            CPlayer::Write(IPlayer.GetOffset(),178,"db",IPlayer.GetID(),0);

        if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 81 && IPlayer.GetLevel() <= 85)
            CPlayer::Write(IPlayer.GetOffset(),178,"db",IPlayer.GetID(),1);

        if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 86 && IPlayer.GetLevel() <= 90)
            CPlayer::Write(IPlayer.GetOffset(),178,"db",IPlayer.GetID(),2);

        if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 91)
            CPlayer::Write(IPlayer.GetOffset(),178,"db",IPlayer.GetID(),3);

        if (IPlayer.IsOnline() && IPlayer.GetClass() == 3 && IPlayer.GetLevel() == 1
                && !CPlayer::FindItem(IPlayer.GetOffset(),1404,1))
            CItem::InsertItem((int)IPlayer.GetOffset(),27,1404,0,1,-1);

        if (IPlayer.IsOnline() && IPlayer.GetClass() == 4 && IPlayer.GetLevel() == 1
                && !CPlayer::FindItem(IPlayer.GetOffset(),7200,1))
            CItem::InsertItem((int)IPlayer.GetOffset(),27,7200,0,1,-1);

        if (IPlayer.IsOnline() && PlayerPet.count(IPlayer.GetPID())
                && PlayerPet.find(IPlayer.GetPID())->second.Owner)
        {
            if (PlayerPet.find(IPlayer.GetPID())->second.Owner >= 2004
                    && PlayerPet.find(IPlayer.GetPID())->second.Owner <= 2007)
                CPlayer::Write(IPlayer.GetOffset(),221,"dwdb",IPlayer.GetID(),
                               PlayerPet.find(IPlayer.GetPID())->second.Owner,
                               PlayerPet.find(IPlayer.GetPID())->second.IID,2);
            else
                CPlayer::Write(IPlayer.GetOffset(),221,"dwdb",IPlayer.GetID(),
                               PlayerPet.find(IPlayer.GetPID())->second.Owner,
                               PlayerPet.find(IPlayer.GetPID())->second.IID,0);
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(119*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(119*1000000))->second)
        {
            IPlayer.Buff(119,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (119*1000000))->second,0);

            if (IPlayer.IsBuff(119))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(119*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(120*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(120*1000000))->second)
        {
            IPlayer.Buff(120,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (120*1000000))->second,0);

            if (IPlayer.IsBuff(120))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(120*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(121*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(121*1000000))->second)
        {
            IPlayer.Buff(121,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (121*1000000))->second,0);

            if (IPlayer.IsBuff(121))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(121*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(122*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(122*1000000))->second)
        {
            IPlayer.Buff(122,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (122*1000000))->second,0);

            if (IPlayer.IsBuff(122))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(122*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(123*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(123*1000000))->second)
        {
            IPlayer.Buff(123,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (123*1000000))->second,0);

            if (IPlayer.IsBuff(123))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(123*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(124*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(124*1000000))->second)
        {
            IPlayer.Buff(124,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (124*1000000))->second,0);

            if (IPlayer.IsBuff(124))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(124*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(125*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(125*1000000))->second)
        {
            IPlayer.Buff(125,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (125*1000000))->second,0);

            if (IPlayer.IsBuff(125))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(125*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(126*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(126*1000000))->second)
        {
            IPlayer.Buff(126,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (126*1000000))->second,0);

            if (IPlayer.IsBuff(126))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(126*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(127*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(127*1000000))->second)
        {
            IPlayer.Buff(127,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (127*1000000))->second,0);

            if (IPlayer.IsBuff(127))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(127*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(128*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(128*1000000))->second)
        {
            IPlayer.Buff(128,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (128*1000000))->second,0);

            if (IPlayer.IsBuff(128))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(128*1000000));
        }

        if (IPlayer.IsOnline()
                && SetBuffx.count(IPlayer.GetPID()+4000000000+(129*1000000))
                && SetBuffx.find(IPlayer.GetPID()+4000000000+(129*1000000))->second)
        {
            IPlayer.Buff(129,SetBuffx.find(IPlayer.GetPID()+4000000000+
                                           (129*1000000))->second,0);

            if (IPlayer.IsBuff(129))
                SetBuffx.erase(IPlayer.GetPID()+4000000000+(129*1000000));
        }
    }
}

void __fastcall MySendCreate(void *Player, void *edx, int Object,
                             void *Argument)
{
    IChar IPlayer(Player);
    IChar IObject((void*)Object);
    CPlayer::SendCreate(Player,Object,Argument);

    if (IPlayer.IsOnline() && IObject.IsOnline()
            && IPlayer.GetOffset() != IObject.GetOffset())
    {
        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IPlayer.GetLevel() < 81)
            CPlayer::Write(IObject.GetOffset(),178,"db",IPlayer.GetID(),0);

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IPlayer.GetLevel() >= 81
                && IPlayer.GetLevel() <= 85)
            CPlayer::Write(IObject.GetOffset(),178,"db",IPlayer.GetID(),1);

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IPlayer.GetLevel() >= 86
                && IPlayer.GetLevel() <= 90)
            CPlayer::Write(IObject.GetOffset(),178,"db",IPlayer.GetID(),2);

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IPlayer.GetLevel() >= 91)
            CPlayer::Write(IObject.GetOffset(),178,"db",IPlayer.GetID(),3);

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IObject.GetLevel() < 81)
            CPlayer::Write(IPlayer.GetOffset(),178,"db",IObject.GetID(),0);

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IObject.GetLevel() >= 81
                && IObject.GetLevel() <= 85)
            CPlayer::Write(IPlayer.GetOffset(),178,"db",IObject.GetID(),1);

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IObject.GetLevel() >= 86
                && IObject.GetLevel() <= 90)
            CPlayer::Write(IPlayer.GetOffset(),178,"db",IObject.GetID(),2);

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IObject.GetLevel() >= 91)
            CPlayer::Write(IPlayer.GetOffset(),178,"db",IObject.GetID(),3);

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IPlayer.IsBuff(349))
            CPlayer::Write(IObject.GetOffset(),255,"ddd",227,IPlayer.GetID(),
                           IPlayer.GetRidingType());

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && IObject.IsBuff(349))
            CPlayer::Write(IPlayer.GetOffset(),255,"ddd",227,IObject.GetID(),
                           IObject.GetRidingType());

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && PlayerPet.count(IPlayer.GetPID())
                && PlayerPet.find(IPlayer.GetPID())->second.Owner)
        {
            if (PlayerPet.find(IPlayer.GetPID())->second.Owner >= 2004
                    && PlayerPet.find(IPlayer.GetPID())->second.Owner <= 2007)
                CPlayer::Write(IObject.GetOffset(),221,"dwdb",IPlayer.GetID(),
                               PlayerPet.find(IPlayer.GetPID())->second.Owner,
                               PlayerPet.find(IPlayer.GetPID())->second.IID,2);
            else
                CPlayer::Write(IObject.GetOffset(),221,"dwdb",IPlayer.GetID(),
                               PlayerPet.find(IPlayer.GetPID())->second.Owner,
                               PlayerPet.find(IPlayer.GetPID())->second.IID,0);
        }

        if (IPlayer.IsOnline() && IObject.IsOnline() && IPlayer.GetType() == 0
                && IObject.GetType() == 0 && PlayerPet.count(IObject.GetPID())
                && PlayerPet.find(IObject.GetPID())->second.Owner)
        {
            if (PlayerPet.find(IObject.GetPID())->second.Owner >= 2004
                    && PlayerPet.find(IObject.GetPID())->second.Owner <= 2007)
                CPlayer::Write(IPlayer.GetOffset(),221,"dwdb",IObject.GetID(),
                               PlayerPet.find(IObject.GetPID())->second.Owner,
                               PlayerPet.find(IObject.GetPID())->second.IID,2);
            else
                CPlayer::Write(IPlayer.GetOffset(),221,"dwdb",IObject.GetID(),
                               PlayerPet.find(IObject.GetPID())->second.Owner,
                               PlayerPet.find(IObject.GetPID())->second.IID,0);
        }
    }
}

int __fastcall Tick(void *Player, void *edx)
{
    IChar IPlayer(Player);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(414) && !IPlayer.IsBuff(413))
    {
        int Buff = CChar::FindBuff((int)IPlayer.GetOffset(),414);
        IPlayer.RemoveBuffIcon(0, 0, 9109, 1018);
        IPlayer.RemoveAgi(*(DWORD*)(Buff + 12));
        IPlayer.CancelBuff(414);
        IPlayer.CancelBuff(413);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(410) && !IPlayer.IsBuff(409))
    {
        int Buff = CChar::FindBuff((int)IPlayer.GetOffset(),410);
        IPlayer.RemoveBuffIcon(0, 0, 9107, 1016);
        IPlayer.DecreaseMaxHp(*(DWORD*)(Buff + 12));
        IPlayer.CancelBuff(410);
        IPlayer.CancelBuff(409);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(408) && !IPlayer.IsBuff(407))
    {
        int Buff = CChar::FindBuff((int)IPlayer.GetOffset(),408);
        IPlayer.RemoveBuffIcon(0, 0, 9108, 1017);
        IPlayer.RemoveMaxAttack(*(DWORD*)(Buff + 12));
        IPlayer.RemoveMinAttack(*(DWORD*)(Buff + 12));
        IPlayer.CancelBuff(408);
        IPlayer.CancelBuff(407);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(406) && !IPlayer.IsBuff(405))
    {
        IPlayer.RemoveBuffIcon(0,0,9103,1012);
        IPlayer.CancelBuff(406);
        IPlayer.CancelBuff(405);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(402) && !IPlayer.IsBuff(401))
    {
        int Buff = CChar::FindBuff((int)IPlayer.GetOffset(),402);
        IPlayer.RemoveBuffIcon(0, 0, 9104, 1013);
        IPlayer.DecreaseMaxHp(*(DWORD*)(Buff + 12));
        IPlayer.CancelBuff(402);
        IPlayer.CancelBuff(401);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(404) && !IPlayer.IsBuff(403))
    {
        int Buff = CChar::FindBuff((int)IPlayer.GetOffset(),404);
        IPlayer.RemoveBuffIcon(0, 0, 9105, 1014);
        IPlayer.RemoveMaxAttack(*(DWORD*)(Buff + 12));
        IPlayer.RemoveMinAttack(*(DWORD*)(Buff + 12));
        IPlayer.CancelBuff(404);
        IPlayer.CancelBuff(403);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(399) && IPlayer.IsBuff(398))
    {
        int BuffTime = IPlayer.GetBuffRemain(398);

        if (BuffTime >= 1 && BuffTime <= 5)
        {
            IPlayer.RemoveDef(1);
            IPlayer.RemoveAbsorb(1);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }

        if (BuffTime >= 875 && BuffTime <= 880)
        {
            IPlayer.RemoveDef(2);
            IPlayer.RemoveAbsorb(2);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }

        if (BuffTime >= 1815 && BuffTime <= 1820)
        {
            IPlayer.RemoveDef(3);
            IPlayer.RemoveAbsorb(3);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }

        if (BuffTime >= 2755 && BuffTime <= 2760)
        {
            IPlayer.RemoveDef(4);
            IPlayer.RemoveAbsorb(4);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }

        if (BuffTime >= 3695 && BuffTime <= 3700)
        {
            IPlayer.RemoveDef(5);
            IPlayer.RemoveAbsorb(5);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }

        if (BuffTime >= 4635 && BuffTime <= 4640)
        {
            IPlayer.RemoveDef(6);
            IPlayer.RemoveAbsorb(6);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }

        if (BuffTime >= 5575 && BuffTime <= 5580)
        {
            IPlayer.RemoveDef(7);
            IPlayer.RemoveAbsorb(7);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }

        if (BuffTime >= 6515 && BuffTime <= 6520)
        {
            IPlayer.RemoveDef(8);
            IPlayer.RemoveAbsorb(8);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }

        if (BuffTime >= 7455 && BuffTime <= 7460)
        {
            IPlayer.RemoveDef(9);
            IPlayer.RemoveAbsorb(9);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }

        if (BuffTime >= 8395 && BuffTime <= 8400)
        {
            IPlayer.RemoveDef(10);
            IPlayer.RemoveAbsorb(10);
            IPlayer.CancelBuff(399);
            IPlayer.CancelBuff(398);
            IPlayer.RemoveBuffIcon(0,0,9101,1010);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(397) && IPlayer.IsBuff(396))
    {
        int BuffTime = IPlayer.GetBuffRemain(396);

        if (BuffTime >= 1 && BuffTime <= 5)
        {
            IPlayer.RemoveDef(6);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }

        if (BuffTime >= 815 && BuffTime <= 820)
        {
            IPlayer.RemoveDef(12);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }

        if (BuffTime >= 1755 && BuffTime <= 1760)
        {
            IPlayer.RemoveDef(18);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }

        if (BuffTime >= 2695 && BuffTime <= 2700)
        {
            IPlayer.RemoveDef(24);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }

        if (BuffTime >= 3635 && BuffTime <= 3640)
        {
            IPlayer.RemoveDef(30);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }

        if (BuffTime >= 4575 && BuffTime <= 4580)
        {
            IPlayer.RemoveDef(36);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }

        if (BuffTime >= 5515 && BuffTime <= 5520)
        {
            IPlayer.RemoveDef(42);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }

        if (BuffTime >= 6455 && BuffTime <= 6460)
        {
            IPlayer.RemoveDef(48);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }

        if (BuffTime >= 7395 && BuffTime <= 7400)
        {
            IPlayer.RemoveDef(54);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }

        if (BuffTime >= 8335 && BuffTime <= 8340)
        {
            IPlayer.RemoveDef(60);
            IPlayer.CancelBuff(397);
            IPlayer.CancelBuff(396);
            IPlayer.RemoveBuffIcon(0,0,9100,1009);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(174)
            && IPlayer.GetBuffRemain(174) <= 5)
    {
        if (!IPlayer.IsBuff(172) && !IPlayer.IsBuff(173) && IPlayer.IsBuff(174))
        {
            IPlayer.CancelBuff(174);
            CPlayer::Write(IPlayer.GetOffset(),204,"d",0);
            CPlayer::Write(IPlayer.GetOffset(),181,"dwd",IPlayer.GetID(),499,0);
        }

        if (!IPlayer.IsBuff(172) && IPlayer.IsBuff(173) && IPlayer.IsBuff(174))
        {
            int First = IPlayer.GetBuffRemain(173);
            IPlayer.CancelBuff(174);
            IPlayer.CancelBuff(173);
            IPlayer.Buff(174,First,0);
            CPlayer::Write(IPlayer.GetOffset(),204,"d",36);
            CPlayer::Write(IPlayer.GetOffset(),181,"dwd",IPlayer.GetID(),500,0);
        }

        if (IPlayer.IsBuff(172) && IPlayer.IsBuff(173) && IPlayer.IsBuff(174))
        {
            int First = IPlayer.GetBuffRemain(173), Second = IPlayer.GetBuffRemain(172);
            IPlayer.CancelBuff(174);
            IPlayer.CancelBuff(173);
            IPlayer.CancelBuff(172);
            IPlayer.Buff(174,First,0);
            IPlayer.Buff(173,Second,0);
            CPlayer::Write(IPlayer.GetOffset(),204,"d",72);
            CPlayer::Write(IPlayer.GetOffset(),181,"dwd",IPlayer.GetID(),501,0);
        }
    }

    if (IPlayer.IsOnline() && (GetTickCount() / 1000) % 2 == 0
            && !CChar::IsGState((int)IPlayer.GetOffset(),2)
            && IPlayer.GetCurHp() < IPlayer.GetMaxHp()
            && PetTime.find(PlayerPet.find(IPlayer.GetPID())->second.Owner)->second.Heal)
        IPlayer.IncreaseHp(PetTime.find(PlayerPet.find(
                                            IPlayer.GetPID())->second.Owner)->second.Heal);

    if (IPlayer.IsOnline() && !CheckMining.find(IPlayer.GetPID())->second.Time
            && MiningLimit.count(IPlayer.GetIP())
            && MiningLimit.find(IPlayer.GetIP())->second && IPlayer.IsBuff(296))
    {
        IPlayer.CancelBuff(296);
        MiningLimit[IPlayer.GetIP()] = 0;
    }

    if (IPlayer.IsOnline() && !CChar::IsGState((int)IPlayer.GetOffset(),16)
            && ShopLimit.count(IPlayer.GetIP()) && ShopLimit.find(IPlayer.GetIP())->second
            && IPlayer.IsBuff(297))
    {
        IPlayer.CancelBuff(297);
        ShopLimit[IPlayer.GetIP()] = 0;
    }

    if (IPlayer.IsOnline() && CheckMining.count(IPlayer.GetPID()))
    {
        if (CheckMining.find(IPlayer.GetPID())->second.Time
                && CChar::IsGState((int)IPlayer.GetOffset(),16))
        {
            IPlayer.CloseWindow("minebar");
            CheckMining[IPlayer.GetPID()].Time = 0;
            CheckMining[IPlayer.GetPID()].Cycle = 0;
            CheckMining[IPlayer.GetPID()].Index = 0;
            CheckMining[IPlayer.GetPID()].Amount = 0;
        }

        if (CheckMining.find(IPlayer.GetPID())->second.Time
                && CChar::IsGState((int)IPlayer.GetOffset(),32))
        {
            IPlayer.CloseWindow("minebar");
            CheckMining[IPlayer.GetPID()].Time = 0;
            CheckMining[IPlayer.GetPID()].Cycle = 0;
            CheckMining[IPlayer.GetPID()].Index = 0;
            CheckMining[IPlayer.GetPID()].Amount = 0;
        }

        if (CheckMining.find(IPlayer.GetPID())->second.Time)
        {
            if (IPlayer.GetRectX() < 8198 || IPlayer.GetRectX() > 8433
                    || IPlayer.GetRectY() < 8790 || IPlayer.GetRectY() > 8966)
            {
                CPlayer::Write(IPlayer.GetOffset(),220,"bb",0,7);
                IPlayer.CloseWindow("minebar");
                CheckMining[IPlayer.GetPID()].Time = 0;
                CheckMining[IPlayer.GetPID()].Cycle = 0;
                CheckMining[IPlayer.GetPID()].Index = 0;
                CheckMining[IPlayer.GetPID()].Amount = 0;
            }
        }

        if (CheckMining.find(IPlayer.GetPID())->second.Time
                && GetTickCount() >= CheckMining.find(IPlayer.GetPID())->second.Time)
        {
            int Chance = 0, Type = 0;
            Chance = CTools::Rate(0,1000);
            if (Chance < 5) Type = 2;
            if (Chance < 200) Type = 1;

            if (CheckMining.find(IPlayer.GetPID())->second.Index == 2524)
                CItem::InsertItem((int)Player,27,NormalPickaxe[Type][CTools::Rate(0,2)],0,1,-1);

            if (CheckMining.find(IPlayer.GetPID())->second.Index == 2525)
                CItem::InsertItem((int)Player,27,BlueDragonPickaxe[Type][CTools::Rate(0,10)],0,
                                  1,-1);

            if (CheckMining.find(IPlayer.GetPID())->second.Index == 2526)
            {
                CItem::InsertItem((int)Player,27,WhiteTigerPickaxe[Type][CTools::Rate(0,10)],0,
                                  1,-1);
                CItem::InsertItem((int)Player,27,WhiteTigerPickaxe[Type][CTools::Rate(0,10)],0,
                                  1,-1);
                CItem::InsertItem((int)Player,27,WhiteTigerPickaxe[Type][CTools::Rate(0,10)],0,
                                  1,-1);
            }

            if (CheckMining.find(IPlayer.GetPID())->second.Index == 2527)
            {
                CItem::InsertItem((int)Player,27,RedBirdPickaxe[Type][CTools::Rate(0,10)],0,1,
                                  -1);
                CItem::InsertItem((int)Player,27,RedBirdPickaxe[Type][CTools::Rate(0,10)],0,1,
                                  -1);
            }

            if (CheckMining.find(IPlayer.GetPID())->second.Index == 2528)
            {
                CItem::InsertItem((int)Player,27,BlackTorotisePickaxe[Type][CTools::Rate(0,10)],
                                  0,1,-1);
                CItem::InsertItem((int)Player,27,BlackTorotisePickaxe[Type][CTools::Rate(0,10)],
                                  0,1,-1);
                CItem::InsertItem((int)Player,27,BlackTorotisePickaxe[Type][CTools::Rate(0,10)],
                                  0,1,-1);
            }

            if (CheckMining.find(IPlayer.GetPID())->second.Index == 2529)
            {
                CItem::InsertItem((int)Player,27,MysteriousPickaxe[Type][CTools::Rate(0,10)],0,
                                  1,-1);
                CItem::InsertItem((int)Player,27,MysteriousPickaxe[Type][CTools::Rate(0,10)],0,
                                  1,-1);
                CItem::InsertItem((int)Player,27,MysteriousPickaxe[Type][CTools::Rate(0,10)],0,
                                  1,-1);
            }

            CheckMining[IPlayer.GetPID()].Cycle = CheckMining.find(
                    IPlayer.GetPID())->second.Cycle + 1;
            bool ContinueMining = true;

            if (CheckMining.find(IPlayer.GetPID())->second.Cycle >= 3)
            {
                if (CheckMining.find(IPlayer.GetPID())->second.Amount >= 1
                        && CPlayer::RemoveItem(IPlayer.GetOffset(),9,
                                               CheckMining.find(IPlayer.GetPID())->second.Index,1))
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
                    CPlayer::Write(IPlayer.GetOffset(),220,"bb",0,3);
                    ContinueMining = false;
                }
            }

            if (ContinueMining == true)
            {
                CPlayer::Write(IPlayer.GetOffset(),220,"bbw",0,4,
                               CheckMining.find(IPlayer.GetPID())->second.Index);
                CheckMining[IPlayer.GetPID()].Time = GetTickCount() + 300000;
            }
        }
    }

    if ((IPlayer.IsBuff(18) || IPlayer.IsBuff(19)) && IPlayer.IsBuff(349))
    {
        IPlayer.CancelBuff(18);
        IPlayer.CancelBuff(19);
        IPlayer.DisableRiding();
    }

    if (CChar::IsGState((int)IPlayer.GetOffset(),2) && IPlayer.IsBuff(349))
        IPlayer.DisableRiding();

    if (IPlayer.IsOnline()
            && CSMap::IsOnTile(*(void **)((int)IPlayer.Offset + 320),
                               (int)IPlayer.Offset + 332, 1048576) && IPlayer.IsBuff(349))
        IPlayer.DisableRiding();

    if (IPlayer.IsOnline() && IPlayer.IsBuff(349) && (IPlayer.IsBuff(378)
            || IPlayer.IsBuff(160) || IPlayer.IsBuff(161) || IPlayer.IsBuff(162)
            || IPlayer.IsBuff(163) || IPlayer.IsBuff(166) || IPlayer.IsBuff(373)
            || IPlayer.IsBuff(374) || IPlayer.IsBuff(170) || IPlayer.IsBuff(171)))
        IPlayer.DisableRiding();

    if (IPlayer.IsOnline() && CChar::IsMState((int)IPlayer.GetOffset(),1)
            && IPlayer.IsBuff(385))
        CChar::SubMState(IPlayer.GetOffset(),1,0);

    if (IPlayer.IsOnline() && Hunting::Active == true && IPlayer.GetMap() == HGMapI
            && Hunting::Guild && Hunting::Guild != IPlayer.GetGID())
        IPlayer.Teleport(0, 257514, 259273);

    if (IPlayer.IsOnline() && F10::Active == true && IPlayer.IsBuff(165)
            && F10::ShowTime > 10 && F10::ShowTime && !IPlayer.IsBuff(308))
    {
        IPlayer.Buff(308,F10::ShowTime,0);
        IPlayer.ScreenTime(F10::ShowTime);
    }

    if (IPlayer.IsOnline() && Protect32::Active == false
            && IPlayer.GetMap() == PLMap)
    {
        if (Protect32::Winner && IPlayer.GetGID() == Protect32::Winner
                && (IPlayer.IsBuff(170) || IPlayer.IsBuff(171)))
        {
            CheckHonor[IPlayer.GetPID()].RPx += 1000;
            CheckHonor[IPlayer.GetPID()].HPx += 1500;
        }

        IPlayer.RemoveSetBlue();
        IPlayer.RemoveSetRed();
        IPlayer.CloseSpScore();
        IPlayer.CancelBuff(170);
        IPlayer.CancelBuff(171);
        IPlayer.Teleport(0, 257514, 259273);
    }

    if (IPlayer.IsOnline() && Protect32::Active == true
            && (GetTickCount() / 1000) % 5 == 0 && IPlayer.GetMap() == PLMap
            && !IPlayer.IsBuff(170) && !IPlayer.IsBuff(171))
        IPlayer.Teleport(0, 257514, 259273);

    if (IPlayer.IsOnline() && Protect32::Active == true && Protect32::GuildFirst
            && IPlayer.GetGID() == Protect32::GuildFirst)
    {
        if (IPlayer.IsValid() && !IPlayer.IsBuff(170))
            IPlayer.Buff(170,4000,0);

        if (IPlayer.IsValid() && IPlayer.GetMap() != PLMap)
            IPlayer.Teleport(PLMap,308588+CTools::Rate(-100,100),284483+CTools::Rate(-100,
                             100));

        if (CChar::IsGState((int)IPlayer.GetOffset(),2))
        {
            if (IPlayer.GetPID() == IPlayer.GetGID()
                    && IPlayer.GetGID() == Protect32::GuildFirst && Protect32::Prayer == 1)
            {
                IPlayer.Buff(352,30,0);
                Protect32::Prayer = 0;
                Protect32::BluePrayerTime = 0;
            }

            if ((*(DWORD*)((int)IPlayer.GetOffset() + 1452)-GetTickCount())/1000 <= 580)
                IPlayer.Teleport(PLMap,308588+CTools::Rate(-100,100),284483+CTools::Rate(-100,
                                 100));
        }
    }

    if (IPlayer.IsOnline() && Protect32::Active == true && Protect32::GuildSecond
            && IPlayer.GetGID() == Protect32::GuildSecond)
    {
        if (IPlayer.IsValid() && !IPlayer.IsBuff(171))
            IPlayer.Buff(171,4000,0);

        if (IPlayer.IsValid() && IPlayer.GetMap() != PLMap)
            IPlayer.Teleport(PLMap,310264+CTools::Rate(-100,100),284486+CTools::Rate(-100,
                             100));

        if (CChar::IsGState((int)IPlayer.GetOffset(),2))
        {
            if (IPlayer.GetPID() == IPlayer.GetGID()
                    && IPlayer.GetGID() == Protect32::GuildSecond && Protect32::Prayer == 2)
            {
                IPlayer.Buff(352,30,0);
                Protect32::Prayer = 0;
                Protect32::RedPrayerTime = 0;
            }

            if ((*(DWORD*)((int)IPlayer.GetOffset() + 1452)-GetTickCount())/1000 <= 580)
                IPlayer.Teleport(PLMap,310264+CTools::Rate(-100,100),284486+CTools::Rate(-100,
                                 100));
        }
    }

    if (IPlayer.IsOnline() && Protect32::Active == true
            && IPlayer.GetGID() == Protect32::GuildFirst && IPlayer.IsBuff(170))
    {
        if (IPlayer.GetPID() != IPlayer.GetGID())
            IPlayer.SetBlue();

        if (IPlayer.GetPID() == IPlayer.GetGID())
        {
            if (Protect32::Prayer == 1)
                CChar::WriteInSight(IPlayer.GetOffset(),46,"dI",IPlayer.GetID(),
                                    __int64(0x00640000) << 32);
            else
                IPlayer.SetBlue();
        }

        if (Protect32::Prayer == 0 && IPlayer.IsValid() && Protect32::Time > 10
                && Protect32::Time < 1201 && IPlayer.IsValid()
                && IPlayer.GetPID() == IPlayer.GetGID()
                && IPlayer.GetGID() == Protect32::GuildFirst && IPlayer.GetRectX() > 9668
                && IPlayer.GetRectX() < 9672 && IPlayer.GetRectY() > 9001
                && IPlayer.GetRectY() < 9005 && !IPlayer.IsBuff(352))
            Protect32::Prayer = 1;

        if (Protect32::Prayer == 1 && IPlayer.IsValid()
                && IPlayer.GetPID() == IPlayer.GetGID()
                && IPlayer.GetGID() == Protect32::GuildFirst)
        {
            if (IPlayer.GetRectX() < 9668 || IPlayer.GetRectX() > 9672
                    || IPlayer.GetRectY() < 9001 || IPlayer.GetRectY() > 9005)
                Protect32::Prayer = 0;
        }

        if (Protect32::Prayer == 1 && IPlayer.IsValid()
                && IPlayer.GetPID() == IPlayer.GetGID()
                && IPlayer.GetGID() == Protect32::GuildFirst)
        {
            if (Protect32::BluePrayerTime >= 21)
            {
                Protect32::BlueScore += 25;
                Protect32::BluePrayerTime = 0;
            }

            Protect32::BluePrayerTime++;
        }

        if (IPlayer.GetRectX() > 9686 && IPlayer.GetRectX() < 9705
                && IPlayer.GetRectY() > 8879 && IPlayer.GetRectY() < 8914)
            IPlayer.Teleport(PLMap,308588+CTools::Rate(-100,100),284483+CTools::Rate(-100,
                             100));

        if (Protect32::Time >= 1200)
        {
            if (IPlayer.GetRectX() < 9631 || IPlayer.GetRectX() > 9653
                    || IPlayer.GetRectY() < 8879 || IPlayer.GetRectY() > 8897)
                IPlayer.Teleport(PLMap,308588+CTools::Rate(-100,100),284483+CTools::Rate(-100,
                                 100));

            IPlayer.CloseSpScore();
            std::string timecheck = "The battle is started.";

            if (Protect32::Time == 1200)
                timecheck = timecheck;
            else
                timecheck = "The battle is starting in " + Int2String(Protect32::Time-1200) +
                            " seconds.";

            CPlayer::Write(IPlayer.GetOffset(),0xFF,"dsd",247,timecheck.c_str(),0);
        }

        if (Protect32::Time <= 1200)
            IPlayer.SpScore(Protect32::Time,Protect32::Prayer,Protect32::RedScore,
                            Protect32::BlueScore,Protect32::RedWin,Protect32::BlueWin);

        if (Protect32::Time == 0 && (IPlayer.GetRectX() < 9631
                                     || IPlayer.GetRectX() > 9653 || IPlayer.GetRectY() < 8879
                                     || IPlayer.GetRectY() > 8897))
            IPlayer.Teleport(PLMap,308588+CTools::Rate(-100,100),284483+CTools::Rate(-100,
                             100));
    }

    if (IPlayer.IsOnline() && Protect32::Active == true
            && IPlayer.GetGID() == Protect32::GuildSecond && IPlayer.IsBuff(171))
    {
        if (IPlayer.GetPID() != IPlayer.GetGID())
            IPlayer.SetRed();

        if (IPlayer.GetPID() == IPlayer.GetGID())
        {
            if (Protect32::Prayer == 2)
                CChar::WriteInSight(IPlayer.GetOffset(),46,"dI",IPlayer.GetID(),
                                    __int64(0x00620000) << 32);
            else
                IPlayer.SetRed();
        }

        if (Protect32::Prayer == 0 && IPlayer.IsValid() && Protect32::Time > 10
                && Protect32::Time < 1201 && IPlayer.IsValid()
                && IPlayer.GetPID() == IPlayer.GetGID()
                && IPlayer.GetGID() == Protect32::GuildSecond && IPlayer.GetRectX() > 9668
                && IPlayer.GetRectX() < 9672 && IPlayer.GetRectY() > 9001
                && IPlayer.GetRectY() < 9005 && !IPlayer.IsBuff(352))
            Protect32::Prayer = 2;

        if (Protect32::Prayer == 2 && IPlayer.IsValid()
                && IPlayer.GetPID() == IPlayer.GetGID()
                && IPlayer.GetGID() == Protect32::GuildSecond)
        {
            if (IPlayer.GetRectX() < 9668 || IPlayer.GetRectX() > 9672
                    || IPlayer.GetRectY() < 9001 || IPlayer.GetRectY() > 9005)
                Protect32::Prayer = 0;
        }

        if (Protect32::Prayer == 2 && IPlayer.IsValid()
                && IPlayer.GetPID() == IPlayer.GetGID()
                && IPlayer.GetGID() == Protect32::GuildSecond)
        {
            if (Protect32::RedPrayerTime >= 21)
            {
                Protect32::RedScore += 25;
                Protect32::RedPrayerTime = 0;
            }

            Protect32::RedPrayerTime++;
        }

        if (IPlayer.GetRectX() > 9633 && IPlayer.GetRectX() < 9655
                && IPlayer.GetRectY() > 8877 && IPlayer.GetRectY() < 8914)
            IPlayer.Teleport(PLMap,310264+CTools::Rate(-100,100),284486+CTools::Rate(-100,
                             100));

        if (Protect32::Time >= 1200)
        {
            if (IPlayer.GetRectX() < 9685 || IPlayer.GetRectX() > 9707
                    || IPlayer.GetRectY() < 8879 || IPlayer.GetRectY() > 8896)
                IPlayer.Teleport(PLMap,310264+CTools::Rate(-100,100),284486+CTools::Rate(-100,
                                 100));

            IPlayer.CloseSpScore();
            std::string timecheck = "The battle is started.";

            if (Protect32::Time == 1200)
                timecheck = timecheck;
            else
                timecheck = "The battle is starting in " + Int2String(Protect32::Time-1200) +
                            " seconds.";

            CPlayer::Write(IPlayer.GetOffset(),0xFF,"dsd",247,timecheck.c_str(),1);
        }

        if (Protect32::Time <= 1200)
            IPlayer.SpScore(Protect32::Time,Protect32::Prayer,Protect32::RedScore,
                            Protect32::BlueScore,Protect32::RedWin,Protect32::BlueWin);

        if (Protect32::Time == 0 && (IPlayer.GetRectX() < 9685
                                     || IPlayer.GetRectX() > 9707 || IPlayer.GetRectY() < 8879
                                     || IPlayer.GetRectY() > 8896))
            IPlayer.Teleport(PLMap,310264+CTools::Rate(-100,100),284486+CTools::Rate(-100,
                             100));
    }

    if (IPlayer.IsOnline() && (GetTickCount() / 1000) % 5 == 0
            && PlayerPet.count(IPlayer.GetPID())
            && !PetLifeCheck.count(PlayerPet.find(IPlayer.GetPID())->second.IID))
    {
        if (PlayerPet.find(IPlayer.GetPID())->second.IID
                && PlayerPet.find(IPlayer.GetPID())->second.Owner)
        {
            int Value = 0, Item = 0, Recheck = 0, Check = 0;
            Undefined::CreateMonsterValue((char *)Player + 1068, (int)&Value,
                                          (int)&PlayerPet.find(IPlayer.GetPID())->second.IID);
            Check = Undefined::Check((int)((char *)Player + 1068), (int)&Recheck);

            if (Undefined::CheckValues(&Value, Check))
            {
                Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);

                if (Item && PlayerPet.find(IPlayer.GetPID())->second.IID)
                {
                    IItem Itemx((void*)Item);

                    if (CItem::IsState(Item,1))
                        OrnamentPutOff(Itemx.GetOffset(),0,(int)IPlayer.GetOffset());
                }
            }
        }
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(392) && !IPlayer.IsBuff(395))
    {
        IPlayer.CancelBuff(392);
        IPlayer.CancelBuff(395);
        IPlayer.RemoveBuffIcon(0,0,4242,950);
        IPlayer.AddDef(100);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(393) && !IPlayer.IsBuff(395))
    {
        IPlayer.CancelBuff(393);
        IPlayer.CancelBuff(395);
        IPlayer.RemoveBuffIcon(0,0,4242,950);
        IPlayer.AddDef(120);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(394) && !IPlayer.IsBuff(395))
    {
        IPlayer.CancelBuff(394);
        IPlayer.CancelBuff(395);
        IPlayer.RemoveBuffIcon(0,0,4242,950);
        IPlayer.AddDef(140);
    }

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 1 && IPlayer.IsBuff(391)
            && !IPlayer.IsBuff(390))
    {
        IPlayer.CancelBuff(391);
        IPlayer.CancelBuff(390);
        IPlayer.RemoveBuffIcon(0,0,4244,952);
        int pSkill = IPlayer.GetSkillPointer(92);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            IPlayer.DecreaseMaxHp(500*xSkill.GetGrade());
            IPlayer.RemoveMaxAttack(100*xSkill.GetGrade());
            IPlayer.RemoveMinAttack(100*xSkill.GetGrade());
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 81 && IPlayer.IsBuff(385))
    {
        IPlayer.CancelBuff(12);
        IPlayer.CancelBuff(82);

        if (IPlayer.GetCurMp() < 8)
        {
            IPlayer.CancelBuff(385);
            IPlayer.CancelBuff(40);
            IPlayer.RemoveBuffIcon(-2, -1, 4246, 954);
        } else {
            IPlayer.DecreaseMana(8);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(386) && !IPlayer.IsBuff(389))
    {
        IPlayer.CancelBuff(386);
        IPlayer.CancelBuff(389);
        IPlayer.RemoveBuffIcon(0,0,4245,953);
        IPlayer.DecreaseCritRate(20);
        IPlayer.DecreaseCritDamage(20);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(387) && !IPlayer.IsBuff(389))
    {
        IPlayer.CancelBuff(387);
        IPlayer.CancelBuff(389);
        IPlayer.RemoveBuffIcon(0,0,4245,953);
        IPlayer.DecreaseCritRate(30);
        IPlayer.DecreaseCritDamage(30);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(388) && !IPlayer.IsBuff(389))
    {
        IPlayer.CancelBuff(388);
        IPlayer.CancelBuff(389);
        IPlayer.RemoveBuffIcon(0,0,4245,953);
        IPlayer.DecreaseCritRate(40);
        IPlayer.DecreaseCritDamage(40);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(381) && !IPlayer.IsBuff(384))
    {
        IPlayer.CancelBuff(381);
        IPlayer.CancelBuff(384);
        IPlayer.RemoveBuffIcon(0,0,4243,951);
        IPlayer.RemoveMaxAttack(200);
        IPlayer.RemoveMinAttack(200);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(382) && !IPlayer.IsBuff(384))
    {
        IPlayer.CancelBuff(382);
        IPlayer.CancelBuff(384);
        IPlayer.RemoveBuffIcon(0,0,4243,951);
        IPlayer.RemoveMaxAttack(400);
        IPlayer.RemoveMinAttack(400);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(383) && !IPlayer.IsBuff(384))
    {
        IPlayer.CancelBuff(383);
        IPlayer.CancelBuff(384);
        IPlayer.RemoveBuffIcon(0,0,4243,951);
        IPlayer.RemoveMaxAttack(600);
        IPlayer.RemoveMinAttack(600);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(379) && IPlayer.IsBuff(380))
    {
        IPlayer.CancelBuff(379);
        IPlayer.CancelBuff(380);
        IPlayer.RemoveBuffIcon(0,0,4240,948);
        int pSkill = IPlayer.GetSkillPointer(90);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            IPlayer.RemoveDef(50 + (xSkill.GetGrade() * 50));
        }
    }

    if (IPlayer.IsOnline() && CGuild::IsWarringPeriod() && IPlayer.IsWarRelated()
            && CCastle::IsAllCastleWarRelation(IPlayer.IsWarRelated())
            && !IPlayer.IsBuff(377))
        IPlayer.Buff(377,7500,0);

    if (IPlayer.IsValid() && PlayerPet.count(IPlayer.GetPID())
            && PlayerPet.find(IPlayer.GetPID())->second.Owner)
    {
        if (IPlayer.IsOnline() && !PlayerPet.find(IPlayer.GetPID())->second.Buff)
            PlayerPet[IPlayer.GetPID()].Buff = GetTickCount() + 600000;

        if (IPlayer.IsOnline())
        {
            if (GetTickCount() >= PlayerPet.find(IPlayer.GetPID())->second.Buff)
            {
                PlayerPet[IPlayer.GetPID()].Buff = GetTickCount() + 600000;
                int Number = rand() % 8 + 1;

                if (Number == 0 || Number == 1)
                {
                    IPlayer.Buff(301, 180, 0);
                    IPlayer.Buff(302, 185, 0);
                    IPlayer.SetBuffIcon(180000, 0, 2360, 299);
                    IPlayer.AddMaxAttack(32);
                    IPlayer.AddMinAttack(32);
                    IPlayer.AddDef(5);
                    IPlayer.AddFxToTarget("Pet_Attackbuff_02",1,0,0);
                } else if (Number == 2)
                {
                    IPlayer.Buff(303, 180, 0);
                    IPlayer.Buff(314, 185, 0);
                    IPlayer.SetBuffIcon(180000, 0, 2362, 302);
                    IPlayer.AddMaxAttack(16);
                    IPlayer.AddMinAttack(16);
                    IPlayer.AddFxToTarget("Pet_Blowbuff_02",1,0,0);
                } else if (Number == 3)
                {
                    IPlayer.Buff(315, 180, 0);
                    IPlayer.Buff(316, 185, 0);
                    IPlayer.SetBuffIcon(180000, 0, 2361, 300);
                    IPlayer.AddMaxAttack(16);
                    IPlayer.AddMinAttack(16);
                    IPlayer.AddDef(8);
                    IPlayer.AddFxToTarget("Pet_Defensebuff_02",1,0,0);
                } else if (Number == 4)
                {
                    IPlayer.Buff(317, 180, 0);
                    IPlayer.Buff(318, 185, 0);
                    IPlayer.SetBuffIcon(180000, 0, 2359, 301);
                    IPlayer.AddDef(5);
                    IPlayer.AddEva(3);
                    IPlayer.AddFxToTarget("Pet_Avoidbuff_02",1,0,0);
                } else if (Number == 5)
                {
                    IPlayer.Buff(319, 180, 0);
                    IPlayer.Buff(320, 185, 0);
                    IPlayer.SetBuffIcon(180000, 0, 2375, 303);
                    IPlayer.AddMaxAttack(45);
                    IPlayer.AddMinAttack(45);
                    IPlayer.AddDef(7);
                    IPlayer.AddFxToTarget("Pet_Attackbuff_03",1,0,0);
                } else if (Number == 6)
                {
                    IPlayer.Buff(321, 180, 0);
                    IPlayer.Buff(322, 185, 0);
                    IPlayer.SetBuffIcon(180000, 0, 2377, 306);
                    IPlayer.AddMaxAttack(24);
                    IPlayer.AddMinAttack(24);
                    IPlayer.AddFxToTarget("Pet_Blowbuff_03",1,0,0);
                } else if (Number == 7)
                {
                    IPlayer.Buff(323, 180, 0);
                    IPlayer.Buff(324, 185, 0);
                    IPlayer.SetBuffIcon(180000, 0, 2376, 304);
                    IPlayer.AddMaxAttack(24);
                    IPlayer.AddMinAttack(24);
                    IPlayer.AddDef(10);
                    IPlayer.AddFxToTarget("Pet_Defensebuff_03",1,0,0);
                } else if (Number == 8)
                {
                    IPlayer.Buff(325, 180-2, 0);
                    IPlayer.Buff(326, 185, 0);
                    IPlayer.SetBuffIcon(180000, 0, 2374, 305);
                    IPlayer.AddDef(7);
                    IPlayer.AddEva(4);
                    IPlayer.AddFxToTarget("Pet_Avoidbuff_03",1,0,0);
                }
            }
        }
    }

    if (IPlayer.IsOnline() && CChar::IsGState((int)Player,2)
            && (IPlayer.IsBuff(373) || IPlayer.IsBuff(374)))
        IPlayer.Teleport(0,214806+CTools::Rate(-100,100),280796+CTools::Rate(-100,100));

    if (IPlayer.IsOnline() && IPlayer.GetRectX() >= 6703
            && IPlayer.GetRectX() <= 6721 && IPlayer.GetRectY() >= 8768
            && IPlayer.GetRectY() <= 8781 && !IPlayer.IsBuff(373) && !IPlayer.IsBuff(374))
        IPlayer.Teleport(0,215294,280808);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(373))
    {
        IPlayer.SetRed();

        if (!IPlayer.IsBuff(375))
        {
            IPlayer.Buff(375,3650,0);
            IPlayer.OpenWindow("Scenario3_3_timescore",0,0);
            IPlayer.SetBuffIcon(-2,-1,0,20);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(374))
    {
        IPlayer.SetBlue();

        if (!IPlayer.IsBuff(376))
        {
            IPlayer.Buff(376,3650,0);
            IPlayer.OpenWindow("Scenario3_3_timescore",0,0);
            IPlayer.SetBuffIcon(-2,-1,0,20);
        }
    }

    if (IPlayer.IsOnline() && DuelTournament::Active == true
            && (IPlayer.IsBuff(373) || IPlayer.IsBuff(374)))
        IPlayer.Scenario3_3Score(DuelTournament::RoundTime,DuelTournament::RedScore,
                                 DuelTournament::BlueScore);

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(373) && IPlayer.IsBuff(375))
    {
        IPlayer.RemoveSetRed();
        IPlayer.CancelBuff(375);
        IPlayer.CloseWindow("Scenario3_3_timescore");
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(374) && IPlayer.IsBuff(376))
    {
        IPlayer.RemoveSetBlue();
        IPlayer.CancelBuff(376);
        IPlayer.CloseWindow("Scenario3_3_timescore");
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(368) && IPlayer.IsBuff(369))
    {
        IPlayer.CancelBuff(369);
        IPlayer.CancelBuff(40);
        IPlayer.AddEva(10);
        IPlayer.RemoveBuffIcon(0,0,2042,226);
    }

    if (IPlayer.IsOnline() && IPlayer.GetCurHp() > 500 && IPlayer.IsBuff(370)
            && IPlayer.IsBuff(371))
        IPlayer.DecreaseHp(500);

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(370) && IPlayer.IsBuff(371))
    {
        IPlayer.CancelBuff(371);
        IPlayer.RemoveBuffIcon(0,0,2038,224);
    }

    if (IPlayer.IsOnline() && Hell::Active == true
            && CChar::IsGState((int)IPlayer.GetOffset(),2) && IPlayer.IsBuff(166))
    {
        if (Hell::Rebirth > 0)
        {
            if (Hell::Rebirth == 1)
                CChar::WriteInSight(IPlayer.GetOffset(), 0xFF, "ddddd", 242, 89, 255, 255, 255);

            Hell::Rebirth -= 1;
            IPlayer.Revive();
            IPlayer.Buff(24, 6, 40);
            IPlayer.RemoveBuffIcon(0,0,703,34);
            CChar::AddMState(IPlayer.GetOffset(), 0, 2147483648);
            IPlayer.SetBuffIcon(6000,0,1793,201);
        } else {
            CChar::WriteInSight(IPlayer.GetOffset(), 0xFF, "ddddd", 242, 91, 255, 255, 255);
            Hell::Active = false;
            Hell::Time = 0;
        }
    }

    if (IPlayer.IsOnline() && Hell::Active == true && IPlayer.IsBuff(166))
        IPlayer.SetRebirthTalisman(Hell::Rebirth);

    if (IPlayer.IsOnline() && Hell::Active == true && IPlayer.GetMap() != HellMap
            && IPlayer.IsBuff(166))
        IPlayer.Teleport(HellMap,HellX,HellY);

    if (IPlayer.IsOnline() && Hell::Active == true && IPlayer.GetMap() == HellMap
            && !IPlayer.IsBuff(166))
    {
        if (CChar::IsGState((int)IPlayer.GetOffset(),2))
            IPlayer.Revive();

        IPlayer.Buff(167,3600,0);
        IPlayer.Teleport(0, HellReturnX, HellReturnY);
        IPlayer.CloseScreenTime();
        IPlayer.CloseRebirthTalisman();
    }

    if (IPlayer.IsOnline() && !IPlayer.IsParty() && IPlayer.IsBuff(166))
    {
        if (CChar::IsGState((int)IPlayer.GetOffset(),2))
            IPlayer.Revive();

        IPlayer.Buff(167,3600,0);
        IPlayer.CancelBuff(166);
        IPlayer.Teleport(0, HellReturnX, HellReturnY);
        IPlayer.CloseScreenTime();
        IPlayer.CloseRebirthTalisman();
    }

    if (IPlayer.IsOnline() && Hell::Active == false && (IPlayer.GetMap() == HellMap
            || IPlayer.IsBuff(166)))
    {
        if (CChar::IsGState((int)IPlayer.GetOffset(),2))
            IPlayer.Revive();

        IPlayer.Buff(167,3600,0);
        IPlayer.CancelBuff(166);
        IPlayer.Teleport(0, HellReturnX, HellReturnY);
        IPlayer.CloseScreenTime();
        IPlayer.CloseRebirthTalisman();
    }

    if (IPlayer.IsOnline() && F10::Active == true
            && F10Registration.count(IPlayer.GetPID())
            && F10Registration.find(IPlayer.GetPID())->second)
    {
        F10Registration.erase(IPlayer.GetPID());

        if (IPlayer.IsValid())
        {
            IPlayer.Teleport(21,117339,36409);
            IPlayer.Buff(165,3700,0);
        }
    }

    if (IPlayer.IsOnline() && F10::Active == true && IPlayer.GetMap() != 21
            && IPlayer.IsBuff(165))
        IPlayer.Teleport(21,117339,36409);

    if (IPlayer.IsOnline() && F10::Active == true && IPlayer.GetMap() == 21
            && !IPlayer.IsBuff(165))
        IPlayer.Teleport(0, 257514, 259273);

    if (IPlayer.IsOnline() && (Time::GetHour() == "18" || Time::GetHour() == "19"))
    {
        if (IPlayer.IsOnline() && (GetTickCount() / 1000) % 5 == 0
                && !IPlayer.IsBuff(362))
        {
            IPlayer.Buff(362, 7200, 0);
            IPlayer.SetBuffIcon(-2, -1, 1657, 188);
            IPlayer.AddOTP(5);
        }

        if(IPlayer.IsOnline() && (GetTickCount() / 1000) % 5 == 0
                && !IPlayer.IsBuff(363))
        {
            IPlayer.Buff(363, 7200, 0);
            IPlayer.SetBuffIcon(-2, -1, 1663, 194);
            IPlayer.AddStr(2);
            IPlayer.AddHp(5);
            IPlayer.AddInt(2);
            IPlayer.AddWis(5);
            IPlayer.AddAgi(3);
        }

        if(IPlayer.IsOnline() && (GetTickCount() / 1000) % 5 == 0
                && !IPlayer.IsBuff(364))
        {
            IPlayer.Buff(364, 7200, 0);
            IPlayer.SetBuffIcon(-2, -1, 1655, 186);
            IPlayer.AddStr(7);
            IPlayer.AddInt(7);
        }

        if(IPlayer.IsOnline() && Time::GetTime() == "19:59:59")
        {
            if(IPlayer.IsOnline() && IPlayer.IsBuff(362))
            {
                IPlayer.CancelBuff(362);
                IPlayer.RemoveBuffIcon(0, 0, 1657, 188);
                IPlayer.RemoveOTP(5);
            }

            if(IPlayer.IsOnline() && IPlayer.IsBuff(363))
            {
                IPlayer.CancelBuff(363);
                IPlayer.RemoveBuffIcon(0, 0, 1663, 194);
                IPlayer.RemoveStr(2);
                IPlayer.RemoveHp(5);
                IPlayer.RemoveInt(2);
                IPlayer.RemoveWis(5);
                IPlayer.RemoveAgi(3);
            }

            if(IPlayer.IsOnline() && IPlayer.IsBuff(364))
            {
                IPlayer.CancelBuff(364);
                IPlayer.RemoveBuffIcon(0, 0, 1655, 186);
                IPlayer.RemoveStr(7);
                IPlayer.RemoveInt(7);
            }
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() < 50
            && (GetTickCount() / 1000) % 5 == 0 && !IPlayer.IsBuff(366))
    {
        IPlayer.Buff(366,648000,0);
        IPlayer.SetBuffIcon(648000000,0, 3756, 433);
        IPlayer.AddDef(50);
        IPlayer.AddMaxAttack(50);
        IPlayer.AddMinAttack(50);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 50 && IPlayer.IsBuff(366))
    {
        IPlayer.CancelBuff(366);
        IPlayer.RemoveBuffIcon(0, 0, 3756, 433);
        IPlayer.RemoveDef(50);
        IPlayer.RemoveMaxAttack(50);
        IPlayer.RemoveMinAttack(50);
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() == BFMap
            && IPlayer.GetRectX() >= 8560 && IPlayer.IsBuff(160)
            && IPlayer.GetRectX() <= 8579)
        IPlayer.Teleport(BFMap,282821+CTools::Rate(-50,50),217307+CTools::Rate(-50,50));

    if (IPlayer.IsOnline() && IPlayer.GetMap() == BFMap
            && IPlayer.GetRectX() >= 8828 && IPlayer.IsBuff(161)
            && IPlayer.GetRectX() <= 8847)
        IPlayer.Teleport(BFMap,274256+CTools::Rate(-50,50),208690+CTools::Rate(-50,50));

    if (IPlayer.IsOnline() && IPlayer.GetMap() == ScenarioMap
            && IPlayer.GetRectX() < 9021 && IPlayer.IsBuff(163) || IPlayer.IsOnline()
            && IPlayer.GetMap() == ScenarioMap && IPlayer.GetRectX() > 9034
            && IPlayer.IsBuff(163))
    {
        if (IPlayer.IsOnline() && IPlayer.IsBuff(163)
                && IPlayer.GetMap() == ScenarioMap && IPlayer.GetRectX() < 8920
                || IPlayer.IsOnline() && IPlayer.IsBuff(163) && IPlayer.GetMap() == ScenarioMap
                && IPlayer.GetRectX() > 9005)
            IPlayer.Teleport(ScenarioMap,288802,350986);
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() == ScenarioMap
            && IPlayer.GetRectX() < 8891 && IPlayer.IsBuff(162) || IPlayer.IsOnline()
            && IPlayer.GetMap() == ScenarioMap && IPlayer.GetRectX() > 8904
            && IPlayer.IsBuff(162))
    {
        if (IPlayer.IsOnline() && IPlayer.IsBuff(162)
                && IPlayer.GetMap() == ScenarioMap && IPlayer.GetRectX() < 8920
                || IPlayer.IsOnline() && IPlayer.IsBuff(162) && IPlayer.GetMap() == ScenarioMap
                && IPlayer.GetRectX() > 9005)
            IPlayer.Teleport(ScenarioMap,284840,351088);
    }

    if (IPlayer.IsOnline() && LastManStand::Active == true
            && LastManRegistration.count(IPlayer.GetPID())
            && LastManRegistration.find(IPlayer.GetPID())->second)
    {
        LastManRegistration.erase(IPlayer.GetPID());

        if (IPlayer.IsValid())
        {
            IPlayer.Buff(24, 6, 40);
            IPlayer.RemoveBuffIcon(0,0,703,34);
            CChar::AddMState(IPlayer.GetOffset(), 0, 2147483648);
            IPlayer.SetBuffIcon(6000,0,1793,201);
            IPlayer.Buff(378,86400,0);
            LastManStand::RegisterAmount += 1;
        }
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(378))
    {
        IPlayer.SetRed();
        CPlayer::Write(IPlayer.GetOffset(),46,"dI",IPlayer.GetID(),
                       __int64(0x00040000) << 32);
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() == LMSMap && !IPlayer.IsBuff(378))
        IPlayer.Teleport(0, 257514, 259273);

    if (IPlayer.IsOnline() && IPlayer.GetMap() != LMSMap && IPlayer.IsBuff(378))
        IPlayer.Teleport(LMSMap,LMSX+CTools::Rate(-200,200),LMSY+CTools::Rate(-200,
                         200));

    if (IPlayer.IsOnline() && CChar::IsGState((int)Player,2) && IPlayer.IsBuff(378)
            && LastManStand::RegisterAmount > 1)
    {
        IPlayer.CancelBuff(378);
        IPlayer.RemoveSetRed();
        IPlayer.RemoveSetBlue();
        IPlayer.Teleport(0, 257514, 259273);
        LastManStand::RegisterAmount -= 1;
    }

    if (IPlayer.IsOnline() && LastManStand::Time == 0
            && LastManStand::RegisterAmount == 1 && LastManStand::Active == true
            && IPlayer.IsBuff(378))
    {
        LastManStand::Active = false;
        LastManStand::RegisterAmount = 0;
        std::string msg = (std::string)IPlayer.GetName() +
                          " won the Last Man Standing.";
        CPlayer::WriteAll(0xFF, "dsd", 247, msg.c_str(), 2);
        IPlayer.CancelBuff(378);
        IPlayer.RemoveSetRed();
        IPlayer.RemoveSetBlue();
        IPlayer.Teleport(0, 257514, 259273);
        CheckHonor[IPlayer.GetPID()].RPx += 1000;
        CheckHonor[IPlayer.GetPID()].HPx += 1000;
    }

    if (IPlayer.IsOnline() && Battlefield::Active == true
            && BattlefieldRegistration.find(IPlayer.GetPID())->second)
    {
        if (Battlefield::BFBuff == 160)
            Battlefield::BFBuff = 161;
        else
            Battlefield::BFBuff = 160;

        BattlefieldRegistration.erase(IPlayer.GetPID());

        if (IPlayer.IsValid())
            IPlayer.Buff(Battlefield::BFBuff,3650,0);
    }

    if (IPlayer.IsOnline() && Scenario::Active == true)
    {
        if (IPlayer.IsOnline() && IPlayer.IsValid() && IPlayer.GetGID()
                && Scenario::GuildFirst && IPlayer.GetGID() == Scenario::GuildFirst
                && !IPlayer.IsBuff(162))
            IPlayer.Buff(162,3650,0);

        if (IPlayer.IsOnline() && IPlayer.IsValid() && IPlayer.GetGID()
                && Scenario::GuildFirst && IPlayer.GetGID() == Scenario::GuildSecond
                && !IPlayer.IsBuff(163))
            IPlayer.Buff(163,3650,0);
    }

    if (IPlayer.IsOnline() && Scenario::Active == false && IPlayer.IsBuff(162))
    {
        IPlayer.Teleport(0, 257514, 259273);
        IPlayer.RemoveSetRed();
        IPlayer.RemoveSetBlue();
        IPlayer.CloseScenario3_3Score();
        IPlayer.RemoveBuffIcon(0, 0, 0, 20);
        IPlayer.CancelBuff(365);
        int Reward = 0;
        int Overlay = 0;

        if (Scenario::RedScore > Scenario::BlueScore)
        {
            Reward = 1500;

            if (Scenario::RedTeamTowerCount == 8)
                Overlay = 25;
            else
                Overlay = 26;
        }

        if (Scenario::BlueScore > Scenario::RedScore)
        {
            Reward = 800;

            if (Scenario::BlueTeamTowerCount == 8)
                Overlay = 14;
            else
                Overlay = 15;
        }

        if (Scenario::RedScore == Scenario::BlueScore)
        {
            Reward = 1000;
            Overlay = 4;
        }

        if (Overlay)
            CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, Overlay, 255, 255, 255);

        IPlayer.CancelBuff(162);
        CheckHonor[IPlayer.GetPID()].HPx += Reward;
        CheckHonor[IPlayer.GetPID()].RPx += Reward;
    }

    if (IPlayer.IsOnline() && Scenario::Active == false && IPlayer.IsBuff(163))
    {
        IPlayer.Teleport(0, 257514, 259273);
        IPlayer.RemoveSetRed();
        IPlayer.RemoveSetBlue();
        IPlayer.CloseScenario3_3Score();
        IPlayer.RemoveBuffIcon(0, 0, 0, 20);
        IPlayer.CancelBuff(365);
        int Reward = 0;
        int Overlay = 0;

        if (Scenario::BlueScore > Scenario::RedScore)
        {
            Reward = 1500;

            if (Scenario::BlueTeamTowerCount == 8)
                Overlay = 14;
            else
                Overlay = 15;
        }

        if (Scenario::RedScore > Scenario::BlueScore)
        {
            Reward = 800;

            if (Scenario::BlueTeamTowerCount == 8)
                Overlay = 25;
            else
                Overlay = 26;
        }

        if (Scenario::RedScore == Scenario::BlueScore)
        {
            Reward = 1000;
            Overlay = 4;
        }

        if (Overlay)
            CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, Overlay, 255, 255, 255);

        IPlayer.CancelBuff(163);
        CheckHonor[IPlayer.GetPID()].HPx += Reward;
        CheckHonor[IPlayer.GetPID()].RPx += Reward;
    }

    if (IPlayer.IsOnline() && Battlefield::Active == false && IPlayer.IsBuff(160))
    {
        IPlayer.Teleport(0, 257514, 259273);
        IPlayer.RemoveSetRed();
        IPlayer.RemoveSetBlue();
        IPlayer.CloseScenario3_3Score();
        IPlayer.RemoveBuffIcon(0, 0, 0, 20);
        IPlayer.CancelBuff(361);
        int Reward = 0;
        int Overlay = 0;

        if (Battlefield::RedScore > Battlefield::BlueScore)
        {
            Reward = 1500;
            Overlay = 53;
            IPlayer.Buff(119,43200,0);
        }

        if (Battlefield::BlueScore > Battlefield::RedScore)
        {
            Reward = 800;
            Overlay = 52;
        }

        if (Battlefield::RedScore == Battlefield::BlueScore)
        {
            Reward = 1000;
            Overlay = 4;
        }

        if (Overlay)
            CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, Overlay, 255, 255, 255);

        IPlayer.CancelBuff(160);
        CheckHonor[IPlayer.GetPID()].HPx += Reward;
        CheckHonor[IPlayer.GetPID()].RPx += Reward;
    }

    if (IPlayer.IsOnline() && Battlefield::Active == false && IPlayer.IsBuff(161))
    {
        IPlayer.Teleport(0, 257514, 259273);
        IPlayer.RemoveSetRed();
        IPlayer.RemoveSetBlue();
        IPlayer.CloseScenario3_3Score();
        IPlayer.RemoveBuffIcon(0, 0, 0, 20);
        IPlayer.CancelBuff(361);
        int Reward = 0;
        int Overlay = 0;

        if (Battlefield::BlueScore > Battlefield::RedScore)
        {
            Reward = 1500;
            Overlay = 52;
            IPlayer.Buff(119,43200,0);
        }

        if (Battlefield::RedScore > Battlefield::BlueScore)
        {
            Reward = 800;
            Overlay = 53;
        }

        if (Battlefield::RedScore == Battlefield::BlueScore)
        {
            Reward = 1000;
            Overlay = 4;
        }

        if (Overlay)
            CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, Overlay, 255, 255, 255);

        IPlayer.CancelBuff(161);
        CheckHonor[IPlayer.GetPID()].HPx += Reward;
        CheckHonor[IPlayer.GetPID()].RPx += Reward;
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() != ScenarioMap
            && IPlayer.IsBuff(162))
    {
        if (CChar::IsGState((int)Player, 512))
            CPlayer::FreeTransform(Player);

        IPlayer.Teleport(ScenarioMap,284840,351088);
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() != ScenarioMap
            && IPlayer.IsBuff(163))
    {
        if (CChar::IsGState((int)Player, 512))
            CPlayer::FreeTransform(Player);

        IPlayer.Teleport(ScenarioMap,288802,350986);
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() != BFMap && IPlayer.IsBuff(160))
    {
        if (CChar::IsGState((int)Player, 512))
            CPlayer::FreeTransform(Player);

        IPlayer.Teleport(BFMap,282821+CTools::Rate(-50,50),217307+CTools::Rate(-50,50));
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() != BFMap && IPlayer.IsBuff(161))
    {
        if (CChar::IsGState((int)Player, 512))
            CPlayer::FreeTransform(Player);

        IPlayer.Teleport(BFMap,274256+CTools::Rate(-50,50),208690+CTools::Rate(-50,50));
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(162))
    {
        IPlayer.SetRed();

        if ( !IPlayer.IsBuff(365) )
        {
            IPlayer.Buff(365,3650,0);
            IPlayer.Scenario3_3Score(Scenario::Time,Scenario::RedScore,Scenario::BlueScore);
            IPlayer.SetBuffIcon(-2,-1,0,20);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(163))
    {
        IPlayer.SetBlue();

        if (!IPlayer.IsBuff(365))
        {
            IPlayer.Buff(365,3650,0);
            IPlayer.Scenario3_3Score(Scenario::Time,Scenario::RedScore,Scenario::BlueScore);
            IPlayer.SetBuffIcon(-2,-1,0,20);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(160))
    {
        IPlayer.SetRed();

        if (!IPlayer.IsBuff(361))
        {
            IPlayer.Buff(361,3650,0);
            IPlayer.Scenario3_3Score(Battlefield::Time,Battlefield::RedScore,
                                     Battlefield::BlueScore);
            IPlayer.SetBuffIcon(-2,-1,0,20);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(161))
    {
        IPlayer.SetBlue();

        if (!IPlayer.IsBuff(361))
        {
            IPlayer.Buff(361,3650,0);
            IPlayer.Scenario3_3Score(Battlefield::Time,Battlefield::RedScore,
                                     Battlefield::BlueScore);
            IPlayer.SetBuffIcon(-2,-1,0,20);
        }
    }

    if (IPlayer.IsOnline() && CChar::IsGState((int)IPlayer.GetOffset(),2)
            && (GetTickCount() / 1000) % 5 == 0 && IPlayer.IsBuff(162))
    {
        IPlayer.Teleport(ScenarioMap,284840,351088);
        IPlayer.Revive();
    }

    if (IPlayer.IsOnline() && CChar::IsGState((int)IPlayer.GetOffset(),2)
            && (GetTickCount() / 1000) % 5 == 0 && IPlayer.IsBuff(163))
    {
        IPlayer.Teleport(ScenarioMap,288802,350986);
        IPlayer.Revive();
    }

    if (IPlayer.IsOnline() && CChar::IsGState((int)IPlayer.GetOffset(),2)
            && (GetTickCount() / 1000) % 5 == 0 && IPlayer.IsBuff(160))
    {
        Battlefield::BlueScore += 1;
        IPlayer.Teleport(BFMap,282821+CTools::Rate(-50,50),217307+CTools::Rate(-50,50));
        IPlayer.Revive();
    }

    if (IPlayer.IsOnline() && CChar::IsGState((int)IPlayer.GetOffset(),2)
            && (GetTickCount() / 1000) % 5 == 0 && IPlayer.IsBuff(161))
    {
        Battlefield::RedScore += 1;
        IPlayer.Teleport(BFMap,274256+CTools::Rate(-50,50),208690+CTools::Rate(-50,50));
        IPlayer.Revive();
    }

    if (IPlayer.IsBuff(162) || IPlayer.IsBuff(163))
        IPlayer.Scenario3_3Score(Scenario::Time,Scenario::RedScore,Scenario::BlueScore);

    if (IPlayer.IsBuff(160) || IPlayer.IsBuff(161))
        IPlayer.Scenario3_3Score(Battlefield::Time,Battlefield::RedScore,
                                 Battlefield::BlueScore);

    if (IPlayer.IsOnline() && IPlayer.GetMap() == ScenarioMap
            && !IPlayer.IsBuff(162) && !IPlayer.IsBuff(163))
        IPlayer.Teleport(0, 257514, 259273);

    if (IPlayer.IsOnline() && IPlayer.GetMap() == BFMap && !IPlayer.IsBuff(160)
            && !IPlayer.IsBuff(161))
        IPlayer.Teleport(0, 257514, 259273);

    if (!Lisans)
        exit(1);

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(358) && IPlayer.IsBuff(359))
    {
        IPlayer.CancelBuff(359);
        IPlayer.RemoveBuffIcon(0,0,2009,207);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(354) && IPlayer.IsBuff(355))
    {
        IPlayer.CancelBuff(355);
        IPlayer.RemoveBuffIcon(0,0,2012,214);
        int pSkill = IPlayer.GetSkillPointer(12);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int nSkillGrade = xSkill.GetGrade();
            IPlayer.RemoveOTP(nSkillGrade * 2);
            IPlayer.RemoveEva(nSkillGrade * 3);
        }
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(344) && IPlayer.IsBuff(345))
    {
        IPlayer.CancelBuff(345);
        IPlayer.RemoveBuffIcon(0,0,2016,211);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(339) && IPlayer.IsBuff(340))
    {
        IPlayer.CancelBuff(339);
        IPlayer.RemoveBuffIcon(0,0,2021,219);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(337) && IPlayer.IsBuff(338))
    {
        IPlayer.CancelBuff(338);
        IPlayer.RemoveBuffIcon(0,0,2427,323);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(335) && IPlayer.IsBuff(336))
    {
        IPlayer.CancelBuff(336);
        IPlayer.RemoveBuffIcon(0,0,2019,217);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(301) && IPlayer.IsBuff(302))
    {
        IPlayer.CancelBuff(302);
        IPlayer.RemoveMaxAttack(32);
        IPlayer.RemoveMinAttack(32);
        IPlayer.RemoveDef(5);
        IPlayer.RemoveBuffIcon(0,0,2360,299);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(303) && IPlayer.IsBuff(314))
    {
        IPlayer.CancelBuff(314);
        IPlayer.RemoveMaxAttack(16);
        IPlayer.RemoveMinAttack(16);
        IPlayer.RemoveBuffIcon(0,0,2362,302);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(315) && IPlayer.IsBuff(316))
    {
        IPlayer.CancelBuff(316);
        IPlayer.RemoveMaxAttack(16);
        IPlayer.RemoveMinAttack(16);
        IPlayer.RemoveDef(8);
        IPlayer.RemoveBuffIcon(0,0,2361,300);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(317) && IPlayer.IsBuff(318))
    {
        IPlayer.CancelBuff(318);
        IPlayer.RemoveDef(5);
        IPlayer.RemoveEva(3);
        IPlayer.RemoveBuffIcon(0,0,2359,301);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(319) && IPlayer.IsBuff(320))
    {
        IPlayer.CancelBuff(320);
        IPlayer.RemoveMaxAttack(45);
        IPlayer.RemoveMinAttack(45);
        IPlayer.RemoveDef(7);
        IPlayer.RemoveBuffIcon(0,0,2375,303);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(321) && IPlayer.IsBuff(322))
    {
        IPlayer.CancelBuff(322);
        IPlayer.RemoveMaxAttack(24);
        IPlayer.RemoveMinAttack(24);
        IPlayer.RemoveBuffIcon(0,0,2377,306);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(323) && IPlayer.IsBuff(324))
    {
        IPlayer.CancelBuff(324);
        IPlayer.RemoveMaxAttack(24);
        IPlayer.RemoveMinAttack(24);
        IPlayer.RemoveDef(10);
        IPlayer.RemoveBuffIcon(0,0,2376,304);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(325) && IPlayer.IsBuff(326))
    {
        IPlayer.CancelBuff(326);
        IPlayer.RemoveDef(7);
        IPlayer.RemoveEva(4);
        IPlayer.RemoveBuffIcon(0,0,2374,305);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(309) && IPlayer.IsBuff(310))
    {
        IPlayer.CancelBuff(310);
        IPlayer.RemoveBuffIcon(0,0,2356,298);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(305) && IPlayer.IsBuff(306))
    {
        IPlayer.CancelBuff(306);
        IPlayer.RemoveBuffIcon(0,0,1794,202);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(288) && IPlayer.IsBuff(289))
    {
        IPlayer.CancelBuff(40);
        IPlayer.CancelBuff(289);
        IPlayer.RemoveBuffIcon(0,0,2101,227);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(286) && IPlayer.IsBuff(287))
    {
        IPlayer.RemoveDef(100);
        IPlayer.RemoveAbsorb(5);
        IPlayer.CancelBuff(287);
        IPlayer.RemoveBuffIcon(0,0,1414,147);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(282) && IPlayer.IsBuff(283))
    {
        IPlayer.CancelBuff(283);
        IPlayer.CancelBuff(284);
    }

    if (IPlayer.IsOnline() && CheckShiny.count((int)IPlayer.GetOffset())
            && CheckShiny.find((int)IPlayer.GetOffset())->second.Target
            && IPlayer.IsBuff(307))
    {
        IChar Caster(CheckShiny.find((int)IPlayer.GetOffset())->second.Target);

        if (!Caster.IsOnline())
        {
            IPlayer.CancelBuff(307);
            CheckShiny[(int)IPlayer.GetOffset()].Target = 0;
        }

        if (!IPlayer.IsValid())
        {
            IPlayer.CancelBuff(307);
            CheckShiny[(int)IPlayer.GetOffset()].Target = 0;
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(264) < 10
            && IPlayer.IsBuff(265))
    {
        IPlayer.RemoveBuffIcon(0,0,3601,415);
        IPlayer.DecreaseMaxHp(500);
        IPlayer.DecreaseMaxMp(500);
        IPlayer.CancelBuff(265);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(121)
            && IPlayer.GetBuffRemain(121) > 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(121)*1000,0,3877,442);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(121) && !IPlayer.IsBuff(273))
        IPlayer.Buff(273,7200,0);

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(121) && IPlayer.IsBuff(273))
    {
        IPlayer.RemoveBuffIcon(0,0,3877,442);
        IPlayer.CancelBuff(273);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(122)
            && IPlayer.GetBuffRemain(122) > 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(122)*1000,0,3879,444);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(122) && !IPlayer.IsBuff(274))
        IPlayer.Buff(274,7200,0);

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(122) && IPlayer.IsBuff(274))
    {
        IPlayer.RemoveBuffIcon(0,0,3879,444);
        IPlayer.CancelBuff(274);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(123)
            && IPlayer.GetBuffRemain(123) > 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(123)*1000,0,3886,451);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(123) && !IPlayer.IsBuff(275))
    {
        IPlayer.Buff(275,7200,0);
        IPlayer.AddOTP(15);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(123) < 10
            && IPlayer.IsBuff(275))
    {
        IPlayer.RemoveBuffIcon(0,0,3886,451);
        IPlayer.RemoveOTP(15);
        IPlayer.CancelBuff(275);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(124)
            && IPlayer.GetBuffRemain(124) > 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(124)*1000,0,3880,445);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(124) && !IPlayer.IsBuff(276))
    {
        IPlayer.Buff(276,7200,0);
        IPlayer.AddEva(7);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(124) < 10
            && IPlayer.IsBuff(276))
    {
        IPlayer.RemoveBuffIcon(0,0,3880,445);
        IPlayer.RemoveEva(7);
        IPlayer.CancelBuff(276);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(125)
            && IPlayer.GetBuffRemain(125) > 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(125)*1000,0,3885,450);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(125) && !IPlayer.IsBuff(277))
    {
        IPlayer.Buff(277,7200,0);
        IPlayer.AddHp(12);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(125) < 10
            && IPlayer.IsBuff(277))
    {
        IPlayer.RemoveBuffIcon(0,0,3885,450);
        IPlayer.RemoveHp(12);
        IPlayer.CancelBuff(277);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(126)
            && IPlayer.GetBuffRemain(126) > 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(126)*1000,0,3884,449);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(126) && !IPlayer.IsBuff(278))
    {
        IPlayer.Buff(278,7200,0);
        IPlayer.AddWis(12);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(126) < 10
            && IPlayer.IsBuff(278))
    {
        IPlayer.RemoveBuffIcon(0,0,3884,449);
        IPlayer.RemoveWis(12);
        IPlayer.CancelBuff(278);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(127)
            && IPlayer.GetBuffRemain(127) > 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(127)*1000,0,3883,448);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(127) && !IPlayer.IsBuff(279))
    {
        IPlayer.Buff(279,7200,0);
        IPlayer.AddInt(7);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(127) < 10
            && IPlayer.IsBuff(279))
    {
        IPlayer.RemoveBuffIcon(0,0,3883,448);
        IPlayer.RemoveInt(7);
        IPlayer.CancelBuff(279);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(128)
            && IPlayer.GetBuffRemain(128) > 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(128)*1000,0,3882,447);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(128) && !IPlayer.IsBuff(280))
    {
        IPlayer.Buff(280,7200,0);
        IPlayer.AddAgi(7);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(128) < 10
            && IPlayer.IsBuff(280))
    {
        IPlayer.RemoveBuffIcon(0,0,3882,447);
        IPlayer.RemoveAgi(7);
        IPlayer.CancelBuff(280);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(129)
            && IPlayer.GetBuffRemain(129) > 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(129)*1000,0,3881,446);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(129) && !IPlayer.IsBuff(281))
    {
        IPlayer.Buff(281,7200,0);
        IPlayer.AddStr(7);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(129) < 10
            && IPlayer.IsBuff(281))
    {
        IPlayer.RemoveBuffIcon(0,0,3881,446);
        IPlayer.RemoveStr(7);
        IPlayer.CancelBuff(281);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(266) < 10
            && IPlayer.IsBuff(267))
    {
        IPlayer.RemoveBuffIcon(0,0,3604,418);
        IPlayer.RemoveMaxAttack(75);
        IPlayer.RemoveMinAttack(50);
        IPlayer.RemoveEva(10);
        IPlayer.CancelBuff(267);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(268) < 10
            && IPlayer.IsBuff(269))
    {
        IPlayer.RemoveBuffIcon(0,0,3603,417);
        IPlayer.RemoveMaxAttack(100);
        IPlayer.CancelBuff(269);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(270) < 10
            && IPlayer.IsBuff(271))
    {
        IPlayer.RemoveBuffIcon(0,0,3602,416);
        IPlayer.RemoveMinAttack(75);
        IPlayer.RemoveOTP(10);
        IPlayer.CancelBuff(271);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(272) < 10
            && IPlayer.IsBuff(261))
    {
        IPlayer.RemoveBuffIcon(0,0,3645,430);
        IPlayer.DecreaseMaxHp(1450);
        IPlayer.CancelBuff(261);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(262) < 10
            && IPlayer.IsBuff(263))
    {
        IPlayer.RemoveBuffIcon(0,0,3646,431);
        IPlayer.DecreaseMaxMp(900);
        IPlayer.CancelBuff(263);
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() == 6
            && (GetTickCount() / 1000) % 5 == 0)
    {
        int Item = CPlayer::FindItem(Player,1620,1);

        if (!Item)
            IPlayer.Teleport(0, 257514, 259273);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(120) && IPlayer.IsBuff(259))
    {
        IPlayer.CancelBuff(259);
        IPlayer.RemoveBuffIcon(0, 0, 3691, 423);
        CPlayer::Write(Player,0xFF,"dd",238,128);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(120))
    {
        IPlayer.Buff(259,604800,0);
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(120)*1000, 0, 3691, 423);
        CPlayer::Write(Player,0xFF,"dd",238,0);
    }

    if (IPlayer.IsOnline() && !IPlayer.IsBuff(119) && IPlayer.IsBuff(260))
    {
        IPlayer.CancelBuff(260);
        IPlayer.RemoveBuffIcon(0, 0, 3511, 370);
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(119))
    {
        IPlayer.Buff(260,604800,0);
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(119)*1000, 0, 3511, 370);
    }

    if (IPlayer.IsOnline() && IPlayer.IsParty())
    {
        int Knight = 0, Archer = 0, Mage = 0, Thief = 0, KnightAtk = 0, KnightDef = 0,
            MageAtk = 0, MageDef = 0, ArcherAtk = 0, ArcherDef = 0, ThiefAtk = 0,
            ThiefDef = 0;
        void *Party = (void *)CParty::FindParty(IPlayer.GetPartyID());

        if (Party && CParty::GetSize(Party) == 8)
        {
            for (int i = CParty::GetPlayerList(Party); i; i = CBaseList::Pop((void*)i))
            {
                IChar IMembers((void*)*(DWORD*)((void*)i));

                if (IMembers.IsOnline())
                {
                    if (IMembers.GetClass() == 0)
                        Knight++;

                    if (IMembers.GetClass() == 0 && (IMembers.GetSpecialty() == 11
                                                     || IMembers.GetSpecialty() == 43))
                        KnightDef++;

                    if (IMembers.GetClass() == 0 && (IMembers.GetSpecialty() == 7
                                                     || IMembers.GetSpecialty() == 23))
                        KnightAtk++;

                    if (IMembers.GetClass() == 1)
                        Mage++;

                    if (IMembers.GetClass() == 1 && (IMembers.GetSpecialty() == 11
                                                     || IMembers.GetSpecialty() == 43))
                        MageDef++;

                    if (IMembers.GetClass() == 1 && (IMembers.GetSpecialty() == 7
                                                     || IMembers.GetSpecialty() == 23))
                        MageAtk++;

                    if (IMembers.GetClass() == 2)
                        Archer++;

                    if (IMembers.GetClass() == 2 && (IMembers.GetSpecialty() == 11
                                                     || IMembers.GetSpecialty() == 43))
                        ArcherDef++;

                    if (IMembers.GetClass() == 2 && (IMembers.GetSpecialty() == 7
                                                     || IMembers.GetSpecialty() == 23))
                        ArcherAtk++;

                    if (IMembers.GetClass() == 3)
                        Thief++;

                    if (IMembers.GetClass() == 3 && (IMembers.GetSpecialty() == 11
                                                     || IMembers.GetSpecialty() == 43))
                        ThiefDef++;

                    if (IMembers.GetClass() == 3 && (IMembers.GetSpecialty() == 7
                                                     || IMembers.GetSpecialty() == 23))
                        ThiefAtk++;
                }
            }

            if (Knight == 2 && Mage == 2 && Archer == 2 && Thief == 2)
            {
                if (KnightAtk == 1 && KnightDef == 1 && MageAtk == 1 && MageDef == 1
                        && ArcherAtk == 1 && ArcherDef == 1 && ThiefAtk == 1 && ThiefDef == 1)
                {
                    IPlayer.SetBuffIcon(-2,-1, 2268, 252);
                    IPlayer.Buff(258,604800,0);
                }
            }
        } else {
            if (IPlayer.IsOnline() && IPlayer.IsBuff(258))
            {
                IPlayer.RemoveBuffIcon(0,0,2268,252);
                IPlayer.CancelBuff(258);
            }
        }
    } else {
        if (IPlayer.IsOnline() && IPlayer.IsBuff(258))
        {
            IPlayer.RemoveBuffIcon(0,0,2268,252);
            IPlayer.CancelBuff(258);
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 0 && IPlayer.GetLevel() >= 70
            && IPlayer.GetSpecialty() == 43)
        IPlayer.SetBuffIcon(-2, -1, 2350, 295);

    if (IPlayer.IsOnline())
    {
        if (((IPlayer.GetClass() == 4 && IPlayer.GetSpecialty() >= 23)
                || (IPlayer.GetClass() == 0 && IPlayer.GetSpecialty() >= 23)
                || (IPlayer.GetClass() == 2 && IPlayer.GetSpecialty() >= 23)
                || (IPlayer.GetClass() == 3 && IPlayer.GetSpecialty() >= 23)
                || (IPlayer.GetClass() == 1 && IPlayer.GetSpecialty() == 23))
                && IPlayer.GetLevel() >= 70)
        {
            int pSkill = IPlayer.GetSkillPointer(70);

            if (pSkill)
            {
                ISkill xSkill((void*)pSkill);

                if (xSkill.GetGrade() == 1)
                    IPlayer.SetBuffIcon(-2, -1, 1767, 220);
                else
                    IPlayer.SetBuffIcon(-2, -1, 3559+xSkill.GetGrade(), 398+xSkill.GetGrade());
            }

            pSkill = IPlayer.GetSkillPointer(71);

            if (pSkill && IPlayer.GetClass() == 4 && IPlayer.GetSpecialty() >= 43)
            {
                ISkill xSkill((void*)pSkill);

                if (xSkill.GetGrade() == 1)
                    IPlayer.SetBuffIcon(-2, -1, 1767, 220);
                else
                    IPlayer.SetBuffIcon(-2, -1, 3559+xSkill.GetGrade(), 398+xSkill.GetGrade());
            }
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 1
            && IPlayer.GetSpecialty() == 43 && IPlayer.GetLevel() >= 70)
    {
        int pSkill = IPlayer.GetSkillPointer(71);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);

            if (xSkill.GetGrade() == 1)
                IPlayer.SetBuffIcon(-2, -1, 1998, 221);
            else
                IPlayer.SetBuffIcon(-2, -1, 3565+xSkill.GetGrade(), 404+xSkill.GetGrade());
        }
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 81
            && IPlayer.GetSpecialty() >= 23)
    {
        int pSkill = IPlayer.GetSkillPointer(79);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            IPlayer.IncreaseMana(2*xSkill.GetGrade());
        }

        IPlayer.SetBuffIcon(-2, -1, 4259, 956);
    }

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 0 && IPlayer.GetLevel() >= 50
            && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43))
    {
        IPlayer.IncreaseMana(KnightManaCirculation);
        IPlayer.SetBuffIcon(-2, -1, 2260, 251);
    }

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 1 && IPlayer.GetLevel() >= 50
            && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43
                || IPlayer.GetSpecialty() == 7 || IPlayer.GetSpecialty() == 23))
    {
        IPlayer.IncreaseMana(MageManaCirculation);
        IPlayer.SetBuffIcon(-2, -1, 2260, 251);
    }

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 2 && IPlayer.GetLevel() >= 50
            && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43))
    {
        IPlayer.IncreaseMana(ArcherManaCirculation);
        IPlayer.SetBuffIcon(-2, -1, 2260, 251);
    }

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 4 && IPlayer.GetLevel() >= 50
            && IPlayer.GetSpecialty() > 3)
    {
        IPlayer.IncreaseMana(MageManaCirculation);
        IPlayer.SetBuffIcon(-2, -1, 2260, 251);
    }

    if (IPlayer.IsOnline() && IPlayer.GetBuffRemain(156) >= 10)
        IPlayer.SetBuffIcon(IPlayer.GetBuffRemain(156) * 1000,0,3543,385);

    if (IPlayer.IsOnline() && Time::GetTime() == "00:00:01" && IPlayer.IsBuff(156))
    {
        int honor = 0, addtime = 0;

        if (CheckHonor.count(IPlayer.GetPID()))
            honor = CheckHonor.find(IPlayer.GetPID())->second.HPx;

        if(honor >= 2790 && honor < 12090)
            addtime = 30;
        else if(honor >= 12090 && honor < 44640)
            addtime = 40;
        else if(honor >= 44640 && honor < 78740)
            addtime = 50;
        else if(honor >= 78740)
            addtime = 60;

        IPlayer.Buff(156,3600+addtime,0);
        CheckEmok[IPlayer.GetPID()].Day = String2Int(Time::GetDay());
    }

    if (IPlayer.IsOnline() && (GetTickCount() / 1000) % 5 == 0
            && IPlayer.IsBuff(156) && IPlayer.GetBuffRemain(156) > 10)
    {
        CheckEmok[IPlayer.GetPID()].Time = IPlayer.GetBuffRemain(156);
        CDBSocket::Write(83,"ddd",IPlayer.GetPID(),
                         CheckEmok.find(IPlayer.GetPID())->second.Day,
                         CheckEmok.find(IPlayer.GetPID())->second.Time);
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() == EmokMap
            && IPlayer.GetBuffRemain(156) == 2)
    {
        IPlayer.CancelBuff(156);
        CheckEmok[IPlayer.GetPID()].Time = 0;
        CDBSocket::Write(83,"ddd",IPlayer.GetPID(),
                         CheckEmok.find(IPlayer.GetPID())->second.Day,0);
        IPlayer.RemoveBuffIcon(0,0,3543,385);
        IPlayer.Teleport(0, 257514, 259273);
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() == EmokMap && !IPlayer.IsBuff(157)
            && !IPlayer.IsBuff(156))
        IPlayer.Buff(157,5,0);

    if (IPlayer.IsOnline() && IPlayer.GetMap() == EmokMap && IPlayer.IsBuff(157)
            && IPlayer.GetBuffRemain(157) == 2 && !IPlayer.IsBuff(156))
    {
        IPlayer.CancelBuff(157);
        IPlayer.Teleport(0, 257514, 259273);
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() != EmokMap && !IPlayer.IsBuff(158)
            && IPlayer.IsBuff(156))
        IPlayer.Buff(158,5,0);

    if (IPlayer.IsOnline() && IPlayer.IsBuff(158)
            && IPlayer.GetBuffRemain(158) == 2)
    {
        if (IPlayer.IsBuff(156) && IPlayer.GetMap() != EmokMap )
        {
            CheckEmok[IPlayer.GetPID()].Time = IPlayer.GetBuffRemain(156);
            CDBSocket::Write(83,"ddd",IPlayer.GetPID(),
                             CheckEmok.find(IPlayer.GetPID())->second.Day,
                             CheckEmok.find(IPlayer.GetPID())->second.Time);
            IPlayer.RemoveBuffIcon(0,0,3543,385);
            IPlayer.CancelBuff(156);
            IPlayer.CancelBuff(158);
        }
    }

    if (Time::GetTime() == "01:59:59" || Time::GetTime() == "03:59:59"
            || Time::GetTime() == "05:59:59" || Time::GetTime() == "07:59:59"
            || Time::GetTime() == "09:59:59" || Time::GetTime() == "11:59:59"
            || Time::GetTime() == "13:59:59" || Time::GetTime() == "15:59:59"
            || Time::GetTime() == "17:59:59" || Time::GetTime() == "19:59:59"
            || Time::GetTime() == "21:59:59" || Time::GetTime() == "23:59:59")
        IPlayer.SystemMessage("Caution: Playing for long time may harm your health.",
                              TEXTCOLOR_RED);

    if (IPlayer.IsOnline())
    {
        if (IPlayer.GetSpecialty() > 11 && IPlayer.GetSpecialty() < 20
                && IPlayer.GetAdmin() <= 3 || IPlayer.GetSpecialty() > 43
                && IPlayer.GetAdmin() <= 3)
        {
            IPlayer.SystemMessage("Job hack detected.", TEXTCOLOR_RED);
            IPlayer.Kick();
            return 0;
        }
    }

    if (IPlayer.IsOnline() && *(DWORD*)((int)IPlayer.GetOffset() + 1440) >= 10)
        SaveAllProperty((int)IPlayer.GetOffset(), 0, 0);

    if (IPlayer.IsOnline())
    {
        if (IPlayer.GetX() < 0 || IPlayer.GetY() < 0 || IPlayer.GetZ() < 0
                || IPlayer.GetZ() > 199000)
        {
            IPlayer.SetX(257514);
            IPlayer.SetY(259273);
            IPlayer.SetZ(16168);
            SaveAllProperty((int)Player, 0, 0);
            IPlayer.Kick();
            return 0;
        }
    }

    if (IPlayer.IsOnline() && strlen(ConfigCheck) && strlen(ConfigClient)
            && strlen(ConfigEngine) && strlen(ConfigConfig) && strlen(ConfigMConfig)
            && strlen(ConfigEpk))
    {
        if ((GetTickCount() / 1000) % 60 == 0)
            CPlayer::Write(IPlayer.GetOffset(),0xFF,"d",235);

        if ((GetTickCount() / 1000) % 60 == 0 && (std::string)ConfigCheck == "true")
            CPlayer::Write(IPlayer.GetOffset(), 0xFF, "dsssss",255,ConfigClient,
                           ConfigEngine,ConfigConfig,ConfigMConfig,ConfigEpk);
    }

    if (IPlayer.IsOnline() && (GetTickCount() / 1000) % 10 == 0)
    {
        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 46)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_01460" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_01460" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 46)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_02460" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_02460" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 50
                && IPlayer.GetClass() != 3)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_01550" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_01550" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 50
                && IPlayer.GetClass() == 3)
            IPlayer.AddFxToTarget("ef_setitem_015003",1,0,0);

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 50
                && IPlayer.GetClass() != 3)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_02550" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_02550" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 50
                && IPlayer.GetClass() == 3)
            IPlayer.AddFxToTarget("ef_setitem_025003",1,0,0);

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 55
                && IPlayer.GetClass() != 3)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_01500" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_01500" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 55
                && IPlayer.GetClass() == 3)
            IPlayer.AddFxToTarget("ef_setitem_015503",1,0,0);

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 55
                && IPlayer.GetClass() != 3)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_02500" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_02500" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 55
                && IPlayer.GetClass() == 3)
            IPlayer.AddFxToTarget("ef_setitem_025503",1,0,0);

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 60)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_01600" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_01600" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 60)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_02600" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_02600" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.HalfSet == 65 )
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_01650" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_01650" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.FullSet == 65 )
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_02650" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_02650" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.HalfSet >= 70
                && IPlayer.GetClass() != 3)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_01550" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_01550" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.HalfSet >= 70
                && IPlayer.GetClass() == 3)
            IPlayer.AddFxToTarget("ef_setitem_015003",1,0,0);

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.FullSet >= 70
                && IPlayer.GetClass() != 3)
        {
            if (IPlayer.GetClass() == 4)
            {
                std::string Effect = "ef_setitem_02550" + Int2String(IPlayer.GetClass()-2);
                IPlayer.AddFxToTarget(Effect,1,0,0);
            } else {
                std::string Effect = "ef_setitem_02550" + Int2String(IPlayer.GetClass());
                IPlayer.AddFxToTarget(Effect,1,0,0);
            }
        }

        if (BeadOfFire.count(IPlayer.GetPID())
                && BeadOfFire.find(IPlayer.GetPID())->second.FullSet >= 70
                && IPlayer.GetClass() == 3)
            IPlayer.AddFxToTarget("ef_setitem_025003",1,0,0);
    }

    if (IPlayer.IsOnline()
            && *(DWORD*)((int)IPlayer.GetOffset() + 292) & 2147483648
            && !IPlayer.IsBuff(24))
        CChar::SubMState(IPlayer.GetOffset(), 0, 2147483648);

    if (IPlayer.IsOnline() && CChar::IsGState((int)Player, 512)
            && GetTickCount() >= *(DWORD*)((int)Player + 1480))
    {
        if ( IPlayer.GetRage() <= 0 )
        {
            CPlayer::FreeTransform(Player);
        } else {
            int RageAmount = IPlayer.GetTransformGrade() & 0xF;

            if ( RageAmount > 0 )
            {
                if (RageAmount == 1)
                    IPlayer.DecreaseRage(357);
                if (RageAmount == 2)
                    IPlayer.DecreaseRage(761);
                if (RageAmount == 3)
                    IPlayer.DecreaseRage(857);
                if (RageAmount == 4)
                    IPlayer.DecreaseRage(1261);
            }

            *(DWORD*)((int)Player + 1480) = GetTickCount() + (((IPlayer.GetRage() <= 0) - 1)
                                            & 0xFFFF2928) + 60000;
        }
    }

    if (IPlayer.IsOnline() && CChar::IsGState((int)IPlayer.GetOffset(),16)
            && strlen(ShopRewardCheck) && ((std::string)ShopRewardCheck == "true"
                                           || (std::string)ShopRewardCheck == "True"))
    {
        if (!IPlayer.IsBuff(169))
            IPlayer.Buff(169,ShopRewardTime,0);

        if (IPlayer.IsBuff(169) && IPlayer.GetBuffRemain(169) < 5)
        {
            IPlayer.Buff(169,ShopRewardTime,0);
            int ItemCheck = CPlayer::FindItem(IPlayer.GetOffset(),ShopRewardIndex,1);

            if (IPlayer.IsOnline() && ItemCheck)
            {
                (*(int (__thiscall **)(DWORD, void *, signed int,
                                       signed int))(*(DWORD*)ItemCheck + 120))(ItemCheck,IPlayer.GetOffset(),9,
                                               ShopRewardAmount);
            } else {
                if (IPlayer.IsOnline()
                        && CPlayer::GetInvenSize((int)Player) < IPlayer.MaxInventorySize())
                {
                    int Item = CItem::CreateItem(ShopRewardIndex, 0, ShopRewardAmount, -1);

                    if (IPlayer.IsOnline() && Item)
                    {
                        IItem IItem((void*)Item);
                        int ValidItem = CPlayer::_InsertItem(IPlayer.GetOffset(), 7, Item);

                        if (IPlayer.IsOnline() && ValidItem == 1)
                        {
                            *(DWORD *)(Item + 48) = 128;
                            CDBSocket::Write(21, "dddbb",IItem.GetIID(),*(DWORD*)(Item + 28),128,8,7);
                            CItem::SendItemInfo((void *)Item, (int)IPlayer.GetOffset(), 92);
                        }
                    }
                }
            }
        }
    }

    if (IPlayer.IsOnline() && !CChar::IsGState((int)IPlayer.GetOffset(),16)
            && IPlayer.IsBuff(169))
        IPlayer.CancelBuff(169);

    if (IPlayer.IsValid() && CChar::IsGState((int)IPlayer.GetOffset(),16)
            && CChar::IsGState((int)IPlayer.GetOffset(),32))
        (*(int (__thiscall **)(int, signed int))(*(DWORD*)Player + 112))((int)Player,
                96);

    if (IPlayer.IsValid()
            && !CSMap::IsOnTile(*(void **)((int)Player + 320), (int)Player + 332, 131072)
            && !CChar::IsGState((int)IPlayer.GetOffset(),16)
            && !CChar::IsGState((int)IPlayer.GetOffset(),32))
    {
        int Around = IPlayer.GetObjectListAround(10);

        while(Around)
        {
            IChar Object((void*)*(DWORD*)Around);

            if (Object.IsValid() && IPlayer.IsValid())
            {
                if (Object.GetType() == 1 && !Object.IsBuff(367))
                {
                    Object.Buff(367,1,0);
                    Object.SendGStateEx(Object.GetGStateEx());

                    if (IPlayer.IsValid() && Object.IsValid() && !Object.IsMobHaveTarget()
                            && Object.IsMobAggressive() && !IPlayer.IsBuff(327) && !IPlayer.IsBuff(329))
                    {
                        int Target = CMonsterReal::ScanSight((int)Object.GetOffset());
                        IChar xPlayer((void*)Target);

                        if (xPlayer.IsValid())
                            Object.SetMobTarget(Target);
                    }
                }
            }

            Around = CBaseList::Pop((void*)Around);
        }
    }

    if (IPlayer.IsOnline() && CheckHonor.count(IPlayer.GetPID()))
    {
        if (CheckHonor.find(IPlayer.GetPID())->second.HPx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurHPx
                || CheckHonor.find(IPlayer.GetPID())->second.HKx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurHKx
                || CheckHonor.find(IPlayer.GetPID())->second.HDx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurHDx
                || CheckHonor.find(IPlayer.GetPID())->second.DKPTx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurDKPTx
                || CheckHonor.find(IPlayer.GetPID())->second.DKPWx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurDKPWx
                || CheckHonor.find(IPlayer.GetPID())->second.PLTx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurPLTx
                || CheckHonor.find(IPlayer.GetPID())->second.PLWx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurPLWx
                || CheckHonor.find(IPlayer.GetPID())->second.SVTx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurSVTx
                || CheckHonor.find(IPlayer.GetPID())->second.SVWx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurSVWx
                || CheckHonor.find(IPlayer.GetPID())->second.RPx != CheckCurHonor.find(
                    IPlayer.GetPID())->second.CurRPx)
        {
            IPlayer.UpdateHonor(CheckHonor.find(IPlayer.GetPID())->second.HPx,
                                CheckHonor.find(IPlayer.GetPID())->second.HKx,
                                CheckHonor.find(IPlayer.GetPID())->second.HDx,
                                CheckHonor.find(IPlayer.GetPID())->second.DKPTx,
                                CheckHonor.find(IPlayer.GetPID())->second.DKPWx,
                                CheckHonor.find(IPlayer.GetPID())->second.PLTx,
                                CheckHonor.find(IPlayer.GetPID())->second.PLWx,
                                CheckHonor.find(IPlayer.GetPID())->second.SVTx,
                                CheckHonor.find(IPlayer.GetPID())->second.SVWx,
                                CheckHonor.find(IPlayer.GetPID())->second.RPx);
            CheckCurHonor[IPlayer.GetPID()].CurHPx = CheckHonor.find(
                        IPlayer.GetPID())->second.HPx;
            CheckCurHonor[IPlayer.GetPID()].CurHKx = CheckHonor.find(
                        IPlayer.GetPID())->second.HKx;
            CheckCurHonor[IPlayer.GetPID()].CurHDx = CheckHonor.find(
                        IPlayer.GetPID())->second.HDx;
            CheckCurHonor[IPlayer.GetPID()].CurDKPTx = CheckHonor.find(
                        IPlayer.GetPID())->second.DKPTx;
            CheckCurHonor[IPlayer.GetPID()].CurDKPWx = CheckHonor.find(
                        IPlayer.GetPID())->second.DKPWx;
            CheckCurHonor[IPlayer.GetPID()].CurPLTx = CheckHonor.find(
                        IPlayer.GetPID())->second.PLTx;
            CheckCurHonor[IPlayer.GetPID()].CurPLWx = CheckHonor.find(
                        IPlayer.GetPID())->second.PLWx;
            CheckCurHonor[IPlayer.GetPID()].CurSVTx = CheckHonor.find(
                        IPlayer.GetPID())->second.SVTx;
            CheckCurHonor[IPlayer.GetPID()].CurSVWx = CheckHonor.find(
                        IPlayer.GetPID())->second.SVWx;
            CheckCurHonor[IPlayer.GetPID()].CurRPx = CheckHonor.find(
                        IPlayer.GetPID())->second.RPx;
        }
    }

    if (IPlayer.IsValid())
        IPlayer.SendGStateEx(IPlayer.GetGStateEx());

    if (IPlayer.IsOnline() && CheckHonor.count(IPlayer.GetPID())
            && (GetTickCount() / 1000) % 5 == 0)
        IPlayer.ShowHonor(CheckHonor.find(IPlayer.GetPID())->second.HPx,
                          CheckHonor.find(IPlayer.GetPID())->second.HKx,
                          CheckHonor.find(IPlayer.GetPID())->second.HDx,
                          CheckHonor.find(IPlayer.GetPID())->second.DKPTx,
                          CheckHonor.find(IPlayer.GetPID())->second.DKPWx,
                          CheckHonor.find(IPlayer.GetPID())->second.PLTx,
                          CheckHonor.find(IPlayer.GetPID())->second.PLWx,
                          CheckHonor.find(IPlayer.GetPID())->second.SVTx,
                          CheckHonor.find(IPlayer.GetPID())->second.SVWx,
                          CheckHonor.find(IPlayer.GetPID())->second.RPx);

    if (IPlayer.IsOnline() && CChar::IsGState((int)Player,32)
            && GetTickCount() >= *(DWORD *)((int)Player + 1468))
    {
        int Rate = CTools::Rate(1,1000);

        if (Rate > 0 && Rate <= 10)
            CItem::InsertItem((int)Player,27,FishHardest,0,1,-1);
        else if (Rate > 2 && Rate <= 20)
            CItem::InsertItem((int)Player,27,FishHard,0,1,-1);
        else if (Rate > 4 && Rate <= 30)
            CItem::InsertItem((int)Player,27,FishNormal,0,1,-1);
        else if (Rate > 6 && Rate <= 60)
            CItem::InsertItem((int)Player,27,FishLow,0,1,-1);
        else if (Rate > 12 && Rate <= 100)
            CItem::InsertItem((int)Player,27,FishLowest,0,1,-1);
    }

    if (IPlayer.IsOnline() && (GetTickCount() / 1000) % 5 == 0
            && !IPlayer.IsBuff(417))
    {
        for (int i = 30; i <= 32; i++)
        {
            int Buff = CChar::FindBuff((int)IPlayer.GetOffset(),i);

            if (Buff)
            {
                CPlayer::Write(IPlayer.GetOffset(),68,"bI",75,*(DWORD*)(Buff + 24),0);
                CPlayer::Write(IPlayer.GetOffset(),68,"bId",74,*(DWORD*)(Buff + 24),0,
                               *(DWORD*)(Buff + 8) - time(0));
            }
        }

        for (int i = 51; i <= 64; i++)
        {
            int Buff = CChar::FindBuff((int)IPlayer.GetOffset(),i);

            if (Buff)
            {
                CPlayer::Write(IPlayer.GetOffset(),68,"bI",75,*(DWORD*)(Buff + 24),0);
                CPlayer::Write(IPlayer.GetOffset(),68,"bId",74,*(DWORD*)(Buff + 24),0,
                               *(DWORD*)(Buff + 8));
            }
        }

        for (int i = 99; i <= 101; i++)
        {
            int Buff = CChar::FindBuff((int)IPlayer.GetOffset(),i);

            if (Buff)
            {
                if (i == 100)
                {
                    CPlayer::Write(IPlayer.GetOffset(),68,"bI",75,*(DWORD*)(Buff + 24),0);
                    CPlayer::Write(IPlayer.GetOffset(),68,"bId",74,*(DWORD*)(Buff + 24),0,
                                   *(DWORD*)(Buff + 8));
                } else {
                    CPlayer::Write(IPlayer.GetOffset(),68,"bI",75,*(DWORD*)(Buff + 24),0);
                    CPlayer::Write(IPlayer.GetOffset(),68,"bId",74,*(DWORD*)(Buff + 24),0,
                                   *(DWORD*)(Buff + 8) - time(0));
                }
            }
        }

        IPlayer.Buff(417,1296000,0);
    }

    return CPlayer::Tick(Player);
}
