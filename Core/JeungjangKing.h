void __fastcall JeungjangKing(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(37);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int Mana = 300 + (nSkillGrade * 2);
        int ExtraTime = 0;
        int XpSkill = IPlayer.GetSkillPointer(40);

        if (XpSkill)
        {
            ISkill xSkillx((void*)XpSkill);
            ExtraTime = 10 * xSkillx.GetGrade();
        }

        if (IPlayer.GetCurMp() <= Mana) {
            return;
        }

        IPlayer.DecreaseMana(Mana);
        IPlayer._ShowBattleAnimation(IPlayer, 37);

        if (IPlayer.IsValid())
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
                                !IMembers.IsBuff(404))
                            {
                                IMembers.SetBuffIcon(1000*((nSkillGrade*60)+ExtraTime), 0, 9105, 1014);
                                IMembers.AddMaxAttack(15*nSkillGrade);
                                IMembers.AddMinAttack(15*nSkillGrade);
                                IMembers.Buff(403, (nSkillGrade*60)+ExtraTime, 0);
                                IMembers.Buff(404, nSkillGrade*100, 15*nSkillGrade);
                            }
                        }
                    }
                }
            } else {
                if (!IPlayer.IsBuff(404))
                {
                    IPlayer.SetBuffIcon(1000*((nSkillGrade*60)+ExtraTime), 0, 9105, 1014);
                    IPlayer.AddMaxAttack(15*nSkillGrade);
                    IPlayer.AddMinAttack(15*nSkillGrade);
                    IPlayer.Buff(403, (nSkillGrade*60)+ExtraTime, 0);
                    IPlayer.Buff(404, nSkillGrade*100, 15*nSkillGrade);
                }
            }
        }
    }
}
