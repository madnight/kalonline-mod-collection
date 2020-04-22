void __fastcall PowerfulWideningWound(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(41);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = xSkill.GetGrade() + 30;

        if (bType == 0 && nTargetID) {
            pTarget = CPlayer::FindPlayer(nTargetID);
        }

        if (bType == 1 && nTargetID) {
            pTarget = CMonster::FindMonster(nTargetID);
        }

        if (bType >= 2) {
            return;
        }

        if (pTarget && xSkill.GetGrade() && IPlayer.IsValid())
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

                if (IPlayer.CheckHit(Target,
                        10 + ((IPlayer.GetLevel() / 20) + xSkill.GetGrade() * 3)))
                {
                    int nDmg = (320 + (196 * xSkill.GetGrade())) +
                        (IPlayer.GetAttack() * KPWWMul) + (xSkill.GetGrade() *
                            CTools::Rate(KPWWMin, KPWWMax));

                    if (Target.GetType() == 0) {
                        nDmg = nDmg * KPWWReduce / 100;
                    }

                    IPlayer.OktayDamageSingle(Target, nDmg, 41);

                    if (IPlayer.IsOnline() && IPlayer.IsValid() && Target.IsOnline() &&
                        Target.IsValid() && Target.GetType() == 1 &&
                        Target.GetCurHp() > 0 && Target.IsMobAggressive() &&
                        Target.IsMobHaveTarget()) {
                        CMonsterReal::AddHostility(Target.GetOffset(), (int)IPlayer.GetOffset(), nDmg*2,
                            0);
                    }
                } else {
                    IPlayer._ShowBattleMiss(Target, 41);
                }

                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}
