void __fastcall MentalBreakdown(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(29);

    if (!IPlayer.IsBuff(406))
        return;

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (150 + (nSkillGrade * 2));
        int ExtraDamage = 0;
        int XpSkill = IPlayer.GetSkillPointer(32);

        if (XpSkill)
        {
            ISkill xSkillx((void*)XpSkill);
            ExtraDamage = 5 * xSkillx.GetGrade();
        }

        if (bType == 0 && nTargetID)
            pTarget = CPlayer::FindPlayer(nTargetID);

        if (bType == 1 && nTargetID)
            pTarget = CMonster::FindMonster(nTargetID);

        if (bType >= 2)
            return;

        if (pTarget && nSkillGrade && IPlayer.IsValid())
        {
            IChar Target(pTarget);

            if (IPlayer.GetCurMp() < nMana)
                return;

            if (pTarget == IPlayer.GetOffset())
                return;

            if(IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                int Around = Target.GetObjectListAround(3);
                IPlayer._ShowBattleAnimation(Target, 29);
                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);

                while(Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.IsValid() && IPlayer.IsValid() && 
                            (*(int (__thiscall **)(int, int, DWORD))
                             (*(DWORD *)IPlayer.GetOffset() + 176))
                            ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                    {
                        if (IPlayer.IsOnline() && IPlayer.GetLevel() >= Object.GetLevel() - 20
                                && !Object.IsBuff(411) && !Object.IsBuff(415) && !Object.IsBuff(416))
                        {
                            int Atk = (Object.GetMaxPhyAttack() * nSkillGrade) / 100;
                            int Def = (Object.GetDef() * nSkillGrade) / 100;
                            int Otp = (CChar::GetHit((int)Object.GetOffset()) * nSkillGrade) / 100;
                            Object.Buff(411,(nSkillGrade*20)+2,Atk);
                            Object.Buff(415,(nSkillGrade*20)+2,Def);
                            Object.Buff(416,(nSkillGrade*20)+2,Otp);
                            Object.RemoveMaxAttack(Atk);
                            Object.RemoveMinAttack(Atk);
                            Object.RemoveDef(Def);
                            Object.RemoveOTP(Otp);
                        }
                    }

                    Around = CBaseList::Pop((void*)Around);
                }
            }
        } else {
            IPlayer.CouldntExecuteSkill();
        }
    }
}
