void __fastcall TheWaveOfEarth(IChar IPlayer)
{
    if (IPlayer.IsOnline())
    {
        int pSkill = IPlayer.GetSkillPointer(93);

        if (IPlayer.IsValid() && pSkill)
        {
            if (CPlayer::IsWState((int)IPlayer.GetOffset(), 12)) {
                return;
            }

            ISkill xSkill((void*)pSkill);
            int Mana = 180 + (1.25 * (xSkill.GetGrade() * (IPlayer.GetLevel() +
                            xSkill.GetGrade())));

            if (IPlayer.GetCurMp() <= Mana) {
                return;
            }

            IPlayer.DecreaseMana(Mana);
            IPlayer._ShowBattleAnimation(IPlayer, 93);

            if (IPlayer.IsValid())
            {
                int Around = IPlayer.GetObjectListAround(3);

                while (Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.IsValid() && IPlayer.IsValid() &&
                        (*(int (__thiscall **)(int, int, DWORD))
                            (*(DWORD *)IPlayer.GetOffset() + 176))
                        ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                    {
                        int nDmg = (IPlayer.GetAttack() * NWOEMul) +
                            (xSkill.GetGrade() * CTools::Rate(NWOEMin, NWOEMax));

                        if (Object.GetType() == 0) {
                            nDmg = nDmg * NWOEReduce / 100;
                        }

                        IPlayer.OktayDamageArea(Object, nDmg, 93);
                    }

                    Around = CBaseList::Pop((void*)Around);
                }
            }
        }
    }
}
