int __fastcall CutdownExp(int Player, void* edx, signed int expLoss)
{
    IChar IPlayer((void*)Player);

    if (!IPlayer.IsOnline()) {
        return 0;
    }

    if (IPlayer.IsBuff(160) || IPlayer.IsBuff(161)) {
        return 0;
    }

    if (IPlayer.IsBuff(162) || IPlayer.IsBuff(163)) {
        return 0;
    }

    if (IPlayer.IsBuff(166)) {
        return 0;
    }

    if (IPlayer.IsBuff(170) || IPlayer.IsBuff(171)) {
        return 0;
    }

    if (IPlayer.IsBuff(378)) {
        return 0;
    }

    if (IPlayer.IsBuff(373) || IPlayer.IsBuff(374)) {
        return 0;
    }

    return CPlayer::CutdownExp(Player, expLoss);
}
