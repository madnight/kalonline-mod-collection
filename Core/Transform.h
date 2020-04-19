void __fastcall Transform(void *Player, void *edx, int Type, signed int Grade)
{
    IChar IPlayer(Player);
    int Rage = 0;

    if (Grade == 1)
        Rage = 34280;
    if (Grade == 2)
        Rage = 137140;
    if (Grade == 3)
        Rage = 308571;
    if (Grade == 4)
        Rage = 601650;

    if (IPlayer.IsValid() && IPlayer.IsBuff(349))
    {
        IPlayer.DisableRiding();
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.GetMap() == 21)
    {
        CPlayer::Write(Player, 67, "b", 67);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(329)
            && !CChar::IsGState((int)Player, 512))
    {
        CPlayer::Write(Player, 67, "b", 67);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(378)
            && !CChar::IsGState((int)Player, 512))
    {
        CPlayer::Write(Player, 67, "b", 67);
        return;
    }

    if (IPlayer.IsOnline() && (IPlayer.IsBuff(160) || IPlayer.IsBuff(161))
            && !CChar::IsGState((int)Player, 512))
    {
        CPlayer::Write(Player, 67, "b", 67);
        return;
    }

    if (IPlayer.IsOnline() && (IPlayer.IsBuff(162) || IPlayer.IsBuff(163))
            && !CChar::IsGState((int)Player, 512))
    {
        CPlayer::Write(Player, 67, "b", 67);
        return;
    }

    if (IPlayer.IsOnline() && (IPlayer.IsBuff(170) || IPlayer.IsBuff(171))
            && !CChar::IsGState((int)Player, 512))
    {
        CPlayer::Write(Player, 67, "b", 67);
        return;
    }

    if (IPlayer.IsOnline() && IPlayer.IsBuff(166)
            && !CChar::IsGState((int)Player, 512))
    {
        CPlayer::Write(Player, 67, "b", 67);
        return;
    }

    if (IPlayer.IsOnline() && (IPlayer.IsBuff(373) || IPlayer.IsBuff(374))
            && !CChar::IsGState((int)Player, 512))
    {
        CPlayer::Write(Player, 67, "b", 67);
        return;
    }

    if (IPlayer.IsOnline() && Type == 2)
    {
        if (IPlayer.IsBuff(327))
            IPlayer.CancelBuff(327);

        CPlayer::FreeTransform(Player);
    } else {
        if (IPlayer.IsOnline() && Grade >= 1 && Grade <= 4
                && !CChar::IsGState((int)Player, 48))
        {
            if (CSMap::IsOnTile(*(void **)((int)Player + 320), (int)Player + 332, 131072))
            {
                CPlayer::Write(Player, 67, "b", 67);
            } else {
                if (IPlayer.GetRage() >= Rage)
                {
                    CIOCriticalSection::Enter((void*)((int)Player + 1020));

                    if (!CChar::IsGState((int)Player, 512))
                    {
                        if (Type == 1)
                        {
                            if (!*(DWORD *)((int)Player + 1116))
                            {
                                if (*(DWORD*)((int)Player + 1108))
                                    CItemTransform::ApplyTransform(*(DWORD*)((int)Player + 1108), (int)Player,
                                                                   Grade);
                            }
                        } else {
                            if (!Type)
                            {
                                if (*(DWORD *)((int)Player + 1116))
                                    CPlayer::Write(Player, 67, "b", 77);
                                else
                                    CChar::WriteInSight(Player, 61, "dbb", IPlayer.GetID(), 12, Grade);
                            }
                        }
                    }

                    CIOCriticalSection::Leave((void*)((int)Player + 1020));
                } else {
                    CPlayer::Write(Player, 67, "b", 66);
                }
            }
        }
    }
}
