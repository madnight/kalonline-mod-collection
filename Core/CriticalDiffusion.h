void __fastcall CriticalDiffusion(IChar IPlayer)
{
    int pSkill = IPlayer.GetSkillPointer(92);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int Mana = 180 + (1.25 * (nSkillGrade * (IPlayer.GetLevel() + nSkillGrade)));

        if (IPlayer.GetCurMp() <= Mana)
            return;

        IPlayer.DecreaseMana(Mana);
        IPlayer._ShowBattleAnimation(IPlayer, 92);

        if(IPlayer.IsValid())
        {
            if (IPlayer.IsParty())
            {
                void *Party = (void *)CParty::FindParty(IPlayer.GetPartyID());

                if (Party)
                {
                    for (int i = CParty::GetPlayerList(Party); i; i = CBaseList::Pop((void *)i))
                    {
                        int Members = *(DWORD*)((void*)i);
                        IChar IMembers((void*)*(DWORD*)((void*)i));

                        if (CChar::IsNormal(Members) && IPlayer.IsValid())
                        {
                            if (CChar::GetRange((int)IPlayer.GetOffset() + 332, Members + 332) <= 300 &&
                                    !IMembers.IsBuff(388) && !IMembers.IsBuff(387) && !IMembers.IsBuff(386))
                            {
                                IMembers.SetBuffIcon(1000*(5+(nSkillGrade*5)), 0, 4245, 953);
                                IMembers.Buff(385+nSkillGrade,7+(nSkillGrade*5),0);
                                IMembers.Buff(389,5+(nSkillGrade*5),0);
                                IMembers.IncreaseCritRate((nSkillGrade*10)+10);
                                IMembers.IncreaseCritDamage((nSkillGrade*10)+10);
                            }
                        }
                    }
                }
            } else {
                if (!IPlayer.IsBuff(388) && !IPlayer.IsBuff(387) && !IPlayer.IsBuff(386))
                {
                    IPlayer.SetBuffIcon(1000*(5+(nSkillGrade*5)), 0, 4245, 953);
                    IPlayer.Buff(385+nSkillGrade,7+(nSkillGrade*5),0);
                    IPlayer.Buff(389,5+(nSkillGrade*5),0);
                    IPlayer.IncreaseCritRate((nSkillGrade*10)+10);
                    IPlayer.IncreaseCritDamage((nSkillGrade*10)+10);
                }
            }
        }
    }
}
