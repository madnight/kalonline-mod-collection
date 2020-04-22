void __fastcall DestroyingArmor(IChar IPlayer)
{
    int pSkill = IPlayer.GetSkillPointer(93);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nMana = 180 + (1.25 * (nSkillGrade * (IPlayer.GetLevel() + nSkillGrade)));

        if (IPlayer.GetCurMp() < nMana) {
            return;
        }

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
                    int nDmg = (IPlayer.GetAttack() * NDAMul) +
                        (nSkillGrade * CTools::Rate(NDAMin, NDAMax));

                    if (Object.GetType() == 0) {
                        nDmg = (nDmg * NDAReduce) / 100;
                    }

                    IPlayer.OktayDamageArea(Object, nDmg, 93);
                }

                Around = CBaseList::Pop((void*)Around);
            }

            IPlayer._ShowBattleAnimation(IPlayer, 93);
            IPlayer.DecreaseMana(nMana);
        }
    }
}
