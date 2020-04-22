void __fastcall SOB(void *Player, void *edx)
{
    IChar IPlayer(Player);

    if (IPlayer.IsOnline() && (CPlayer::FindItem(IPlayer.GetOffset(), 361, 1)
            || CPlayer::FindItem(IPlayer.GetOffset(), 501, 1)))
    {
        int ExtraStat = 0;

        if (IPlayer.GetLevel() >= 72
            && IPlayer.GetLevel() < 76) {
            ExtraStat += (2 * (IPlayer.GetLevel() - 71));
        }

        if (IPlayer.GetLevel() >= 76
            && IPlayer.GetLevel() < 81) {
            ExtraStat += (8 + (3 * (IPlayer.GetLevel() - 75)));
        }

        if (IPlayer.GetLevel() >= 81
            && IPlayer.GetLevel() < 86) {
            ExtraStat += (23 + (4 * (IPlayer.GetLevel() - 80)));
        }

        if (IPlayer.GetLevel() >= 86
            && IPlayer.GetLevel() < 91) {
            ExtraStat += (43 + (5 * (IPlayer.GetLevel() - 85)));
        }

        if (IPlayer.GetLevel() >= 91
            && IPlayer.GetLevel() < 96) {
            ExtraStat += (68 + (6 * (IPlayer.GetLevel() - 90)));
        }

        if (IPlayer.GetLevel() >= 96) {
            ExtraStat += (98 + (7 * (IPlayer.GetLevel() - 95)));
        }

        CPlayer::InitStat(Player);

        if (ExtraStat) {
            IPlayer.AddStatPoint(ExtraStat);
        }
    }
}
