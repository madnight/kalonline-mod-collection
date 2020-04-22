void __fastcall Doggebi(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(92);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (170 + (nSkillGrade * 2));

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

                int nDmg = ((IPlayer.GetMaxMagAttack() +
                            (((IPlayer.GetMaxMagAttack() / 1) +
                                    (CChar::GetInt((int)IPlayer.GetOffset()) / 1)) +
                                ((CChar::GetWis((int)IPlayer.GetOffset()) / 1) +
                                    (nSkillGrade * 2500)))) * 12) +
                    (IPlayer.GetLevel() * 10);

                if (Target.GetType() == 0) {
                    nDmg = (nDmg * SHMD) / 100;
                }

                IPlayer.OktayDamageSingle(Target, nDmg, 92);
                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);
            }
        } else {
            IPlayer.CouldntExecuteSkill();
        }
    }
}
