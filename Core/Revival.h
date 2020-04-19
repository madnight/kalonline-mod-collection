void __fastcall RevivalSkill(void *Player, void *edx, int Argument, int Target)
{
    CPlayer::RevivalSkill(Player,Argument,Target);
    IChar IPlayer(Player);

    if (IPlayer.IsOnline())
    {
        if (IPlayer.IsBuff(4))
        {
            IPlayer.Buff(24, 6, 40);
            IPlayer.RemoveBuffIcon(0,0,703,34);
            CChar::AddMState(IPlayer.GetOffset(), 0, 2147483648);
            IPlayer.SetBuffIcon(6000,0,1793,201);

            if (Protect32::Active == true && IPlayer.GetGID() == IPlayer.GetPID())
            {
                if (IPlayer.GetGID() == Protect32::GuildFirst)
                    IPlayer.CancelBuff(352);

                if (IPlayer.GetGID() == Protect32::GuildSecond)
                    IPlayer.CancelBuff(352);
            }
        }
    }
}

void __fastcall RevivalItem(void *Player, void *edx, int Argument)
{
    CPlayer::RevivalItem(Player,Argument);
    IChar IPlayer(Player);

    if (IPlayer.IsOnline())
    {
        IPlayer.Buff(24, 6, 40);
        IPlayer.RemoveBuffIcon(0,0,703,34);
        CChar::AddMState(IPlayer.GetOffset(), 0, 2147483648);
        IPlayer.SetBuffIcon(6000,0,1793,201);
    }
}