void __fastcall Incapacitation(IChar IPlayer)
{
    int pSkill = IPlayer.GetSkillPointer(91);

    if (pSkill && IPlayer.IsValid())
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int Mana = (1.85 * (200 + (nSkillGrade * (20 + (nSkillGrade - 1)))));

        if (IPlayer.GetCurMp() < Mana)
            return;
        else
            IPlayer.DecreaseMana(Mana);

        if(IPlayer.IsValid() && nSkillGrade)
        {
            IPlayer._ShowBattleAnimation(IPlayer, 91);
            int Around = IPlayer.GetObjectListAround(3);

            while(Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.IsValid() && IPlayer.IsValid() &&
                        (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))
                        ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                {
                    if (!Object.IsBuff(395) && Object.GetDef() >= 140)
                    {
                        Object.Buff(395,8+(xSkill.GetGrade()*2),0);
                        Object.Buff(391+xSkill.GetGrade(),15+(xSkill.GetGrade()*2),0);
                        Object.RemoveDef(80+(xSkill.GetGrade()*20));

                        if (Object.GetType() == 0)
                            Object.SetBuffIcon(8000+(2000*xSkill.GetGrade()), 0, 4242, 950);
                    }
                }

                Around = CBaseList::Pop((void*)Around);
            }
        }
    }
}
