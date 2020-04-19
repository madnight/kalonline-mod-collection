void __fastcall Punishment(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(90);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (300 - (20 * (nSkillGrade - 1)));

        if (bType == 0 && nTargetID)
            pTarget = CPlayer::FindPlayer(nTargetID);

        if (bType == 1 && nTargetID)
            pTarget = CMonster::FindMonster(nTargetID);

        if (bType >= 2)
            return;

        if (pTarget && nSkillGrade && IPlayer.IsValid())
        {
            if (IPlayer.GetCurMp() < nMana)
                return;

            if (pTarget == IPlayer.GetOffset())
                return;

            IChar Target(pTarget);

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                int nDmg = (IPlayer.GetMagic() * NMPMul) +
                    (nSkillGrade * CTools::Rate(NMPMin,NMPMax));

                if (Target.GetType() == 0)
                    nDmg = (nDmg * NMPReduce) / 100;

                IPlayer.SetDirection(Target);
                IPlayer.OktayDamageSingle(Target,nDmg,90);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}
