void __fastcall Fireball(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(73);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (int)(((((nSkillGrade-1)+30) * nSkillGrade)+300) * 0.79);

        if (bType == 0 && nTargetID) {
            pTarget = CPlayer::FindPlayer(nTargetID);
        }

        if (bType == 1 && nTargetID) {
            pTarget = CMonster::FindMonster(nTargetID);
        }

        if (bType >= 2) {
            return;
        }

        if (pTarget && nSkillGrade && IPlayer.IsValid())
        {
            IChar Target(pTarget);

            if (IPlayer.GetCurMp() < nMana) {
                return;
            }

            if (pTarget == IPlayer.GetOffset()) {
                return;
            }

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target, 300)) {
                    return;
                }

                int nDmg = (IPlayer.GetMagic() * MFBMul) +
                    (xSkill.GetGrade() * CTools::Rate(MFBMin, MFBMax));

                if (Target.GetType() == 0) {
                    nDmg = (nDmg * MFBReduce) / 100;
                }

                IPlayer.OktayDamageSingle(Target, nDmg, 73);
                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}
