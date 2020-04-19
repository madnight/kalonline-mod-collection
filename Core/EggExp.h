int __fastcall UpdateExp(int PlayerEgg,void *edx, int Player, int Check)
{
    IChar IPlayer((void*)Player);

    if (*(DWORD *)(PlayerEgg + 92) >= 100)
        return 0;

    if (Check)
    {
        if (*(DWORD *)(PlayerEgg + 100) == 179)
        {
            if (IPlayer.IsBuff(119) && IPlayer.IsBuff(120))
                *(DWORD *)(PlayerEgg + 96) += (EggExpTime + ((EggExpTime *4) / 10)) - 10;
            else if (IPlayer.IsBuff(120))
                *(DWORD *)(PlayerEgg + 96) += (EggExpTime + (EggExpTime / 10)) - 10;
            else if (IPlayer.IsBuff(119))
                *(DWORD *)(PlayerEgg + 96) += (EggExpTime + ((EggExpTime *3) / 10)) - 10;
            else
                *(DWORD *)(PlayerEgg + 96) += EggExpTime - 10;

            if (IPlayer.IsBuff(330) && EggExpTime > 100)
                *(DWORD *)(PlayerEgg + 96) += EggExpTime / 100;
        }
    } else {
        int Remove = 1;

        if (IPlayer.GetLevel() > 20)
            Remove = ((IPlayer.GetLevel() - 11) / 10) + 1;

        if (IPlayer.IsBuff(119) && IPlayer.IsBuff(120))
            *(DWORD *)(PlayerEgg + 96) += (EggExpKill + ((EggExpKill *4) / 10)) - Remove;
        else if (IPlayer.IsBuff(120))
            *(DWORD *)(PlayerEgg + 96) += (EggExpKill + (EggExpKill / 10)) - Remove;
        else if (IPlayer.IsBuff(119))
            *(DWORD *)(PlayerEgg + 96) += (EggExpKill + ((EggExpKill *3) / 10)) - Remove;
        else
            *(DWORD *)(PlayerEgg + 96) += EggExpKill - Remove;

        if (IPlayer.IsBuff(330) && EggExpKill > 100)
            *(DWORD *)(PlayerEgg + 96) += EggExpKill / 100;
    }

    return CItemTransform::UpdateExp(PlayerEgg,Player,Check);
}