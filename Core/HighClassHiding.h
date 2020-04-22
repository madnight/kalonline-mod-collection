void __fastcall HighClassHiding(IChar IPlayer)
{
    if (IPlayer.IsValid())
    {
        if (IPlayer.GetRage() < 9) {
            return;
        }

        if (!IPlayer.IsBuff(327)) {
            IPlayer.SendGStateEx(IPlayer.GetGStateEx() + 2048);
        }

        IPlayer.Buff(327, 30, 0);
        IPlayer._ShowBattleAnimation(IPlayer, 110);
        IPlayer.DecreaseRage(9);
    }
}