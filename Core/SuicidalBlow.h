void __fastcall SuicidalBlow(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(21);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = 40 * nSkillGrade + 45;

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

                int nDmg = (IPlayer.GetAttack() * TSuBMul) +
                    (nSkillGrade * CTools::Rate(TSuBMin, TSuBMax));
                int Additional = 0;

                if (IPlayer.GetCurHp() >= 100)
                {
                    Additional = (IPlayer.GetCurHp() * 80) / 100;

                    if (Additional > 0 && IPlayer.GetCurHp() > Additional)
                    {
                        IPlayer.DecreaseHp(Additional);
                        nDmg = nDmg + (Additional / 2);
                    }
                }

                if (Target.GetType() == 0) {
                    nDmg = nDmg * TSuBReduce / 100;
                }

                if (IPlayer.CheckHit(Target, 110)) {
                    IPlayer.OktayDamageSingle(Target, nDmg, 21);
                }
                else {
                    IPlayer._ShowBattleMiss(Target, 21);
                }

                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}
