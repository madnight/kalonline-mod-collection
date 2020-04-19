void __fastcall Strangle(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(10);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = nSkillGrade * 5 + 10;

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

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                if (IPlayer.CheckHit(Target, 10))
                {
                    if (!Target.IsBuff(357))
                        Target.SendGStateEx(Target.GetGStateEx() + 128);

                    Target.Buff(357,nSkillGrade,0);
                    Target.Buff(7,nSkillGrade,0);
                    int nDmg = (IPlayer.GetAttack() * TStranMul) +
                        (nSkillGrade * CTools::Rate(TStranMin,TStranMax));

                    if (Target.GetType() == 0)
                        nDmg = nDmg * TStranReduce / 100;

                    IPlayer.OktayDamageSingle(Target,nDmg,10);
                } else {
                    IPlayer._ShowBattleMiss(Target, 10);
                }

                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}
