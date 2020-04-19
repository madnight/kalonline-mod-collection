int __fastcall LevelUp(void *Player, void *edx)
{
    IChar IPlayer(Player);
    int result = 0;

    if (IPlayer.IsOnline())
        result = CPlayer::LevelUp(Player);

    if (IPlayer.IsOnline())
    {
        for (int i = (IPlayer.GetLevel()*10); i < ((IPlayer.GetLevel()*10) + 10); i++)
        {
            if (LevelReward.count(i) &&
                    (LevelReward.find(i)->second.Class == IPlayer.GetClass() ||
                     LevelReward.find(i)->second.Class == 4))
                IPlayer.GiveReward(LevelReward.find(i)->second.Index,
                                   LevelReward.find(i)->second.Prefix,LevelReward.find(i)->second.Amount,
                                   LevelReward.find(i)->second.Info,LevelReward.find(i)->second.Attack,
                                   LevelReward.find(i)->second.Magic,LevelReward.find(i)->second.Toa,
                                   LevelReward.find(i)->second.Upgrade,LevelReward.find(i)->second.Defense,
                                   LevelReward.find(i)->second.Evasion,LevelReward.find(i)->second.Endurance,
                                   LevelReward.find(i)->second.Msg.c_str());
        }
    }

    if (IPlayer.IsOnline())
    {
        if (IPlayer.GetLevel() == 81)
            CChar::WriteInSight(IPlayer.GetOffset(),178,"db",IPlayer.GetID(),1);

        if (IPlayer.GetLevel() == 86)
            CChar::WriteInSight(IPlayer.GetOffset(),178,"db",IPlayer.GetID(),2);

        if (IPlayer.GetLevel() == 91)
            CChar::WriteInSight(IPlayer.GetOffset(),178,"db",IPlayer.GetID(),3);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() == 70)
    {
        IPlayer.IncreaseMaxHp(250);
        IPlayer.IncreaseMaxMp(100);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() == 75)
    {
        IPlayer.IncreaseMaxHp(300);
        IPlayer.IncreaseMaxMp(125);

        if (IPlayer.GetSpecialty() == 43 && IPlayer.GetClass() == 1)
            IPlayer.RemoveBuffIcon(0, 0, 1998, 221);
        else
            IPlayer.RemoveBuffIcon(0, 0, 1767, 220);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() == 80)
    {
        IPlayer.IncreaseMaxHp(350);
        IPlayer.IncreaseMaxMp(150);

        if (IPlayer.GetSpecialty() == 43 && IPlayer.GetClass() == 1)
            IPlayer.RemoveBuffIcon(0, 0, 3567, 406);
        else
            IPlayer.RemoveBuffIcon(0, 0, 3561, 400);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() == 85)
    {
        IPlayer.IncreaseMaxHp(550);
        IPlayer.IncreaseMaxMp(250);

        if (IPlayer.GetSpecialty() == 43 && IPlayer.GetClass() == 1)
            IPlayer.RemoveBuffIcon(0, 0, 3568, 407);
        else
            IPlayer.RemoveBuffIcon(0, 0, 3562, 401);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() == 90)
    {
        IPlayer.IncreaseMaxHp(950);
        IPlayer.IncreaseMaxMp(450);

        if (IPlayer.GetSpecialty() == 43 && IPlayer.GetClass() == 1)
            IPlayer.RemoveBuffIcon(0, 0, 3569, 408);
        else
            IPlayer.RemoveBuffIcon(0, 0, 3563, 402);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() == 95)
    {
        IPlayer.IncreaseMaxHp(1750);
        IPlayer.IncreaseMaxMp(850);

        if (IPlayer.GetSpecialty() == 43 && IPlayer.GetClass() == 1)
            IPlayer.RemoveBuffIcon(0, 0, 3570, 409);
        else
            IPlayer.RemoveBuffIcon(0, 0, 3564, 403);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 70 && IPlayer.GetLevel() <= 74)
    {
        IPlayer.IncreaseMaxHp(6);
        IPlayer.IncreaseMaxMp(3);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 75 && IPlayer.GetLevel() <= 79)
    {
        IPlayer.IncreaseMaxHp(12);
        IPlayer.IncreaseMaxMp(6);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 80 && IPlayer.GetLevel() <= 84)
    {
        IPlayer.IncreaseMaxHp(18);
        IPlayer.IncreaseMaxMp(9);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 85 && IPlayer.GetLevel() <= 89)
    {
        IPlayer.IncreaseMaxHp(24);
        IPlayer.IncreaseMaxMp(12);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 90 && IPlayer.GetLevel() <= 94)
    {
        IPlayer.IncreaseMaxHp(30);
        IPlayer.IncreaseMaxMp(15);
    }

    if (IPlayer.IsOnline() && IPlayer.GetLevel() >= 95)
    {
        IPlayer.IncreaseMaxHp(36);
        IPlayer.IncreaseMaxMp(18);
    }

    if (IPlayer.IsOnline())
    {
        int StatBonus = 0;
        if (IPlayer.GetLevel() >= 72 && IPlayer.GetLevel() < 76) StatBonus = 2;
        if (IPlayer.GetLevel() >= 76 && IPlayer.GetLevel() < 81) StatBonus = 3;
        if (IPlayer.GetLevel() >= 81 && IPlayer.GetLevel() < 86) StatBonus = 4;
        if (IPlayer.GetLevel() >= 86 && IPlayer.GetLevel() < 91) StatBonus = 5;
        if (IPlayer.GetLevel() >= 91 && IPlayer.GetLevel() < 96) StatBonus = 6;
        if (IPlayer.GetLevel() >= 96) StatBonus = 7;

        if (StatBonus)
            IPlayer.AddStatPoint(StatBonus);
    }

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 0 && IPlayer.GetLevel() >= 71
            && IPlayer.GetLevel() < 101 && IPlayer.GetSpecialty() == 43)
        IPlayer.AddDef(5);

    return result;
}
