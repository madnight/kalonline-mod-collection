void __fastcall Bombing(IChar IPlayer)
{
    int pSkill = IPlayer.GetSkillPointer(93);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();

        if (IPlayer.IsValid() && nSkillGrade)
        {
            int nMana = 180 + (1.25 * (nSkillGrade * (IPlayer.GetLevel() + nSkillGrade)));

            if (IPlayer.GetCurMp() < nMana) {
                return;
            }

            int Around = IPlayer.GetObjectListAround(3);

            while (Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.IsValid() && IPlayer.IsValid() &&
                    (*(int (__thiscall **)(int, int, DWORD))
                        (*(DWORD *)IPlayer.GetOffset() + 176))
                    ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                {
                    int nDmg = (IPlayer.GetMagic() * NBOMMul) +
                        (nSkillGrade * CTools::Rate(NBOMMin, NBOMMax));

                    if (Object.GetType() == 0) {
                        nDmg = (nDmg * NBOMReduce) / 100;
                    }

                    IPlayer.OktayDamageArea(Object, nDmg, 93);
                }

                Around = CBaseList::Pop((void*)Around);
            }

            IPlayer.DecreaseMana(nMana);
            IPlayer._ShowBattleAnimation(IPlayer, 93);
        }
    }
}
