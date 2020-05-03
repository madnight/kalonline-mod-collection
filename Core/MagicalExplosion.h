void __fastcall MagicalExplosion(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(54);

    if (!IPlayer.IsBuff(406)) {
        return;
    }

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (90 + (nSkillGrade * 2));
        int ExtraDamage = 0;
        int XpSkill = IPlayer.GetSkillPointer(32);

        if (XpSkill)
        {
            ISkill xSkillx((void*)XpSkill);
            ExtraDamage = 5 * xSkillx.GetGrade();
        }

        if (IPlayer.IsBuff(412))
        {
            int Buff = CChar::FindBuff((int)IPlayer.GetOffset(), 412);
            ExtraDamage += *(DWORD*)(Buff + 12);
        }

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

                int nDmg = (((IPlayer.GetMaxMagAttack() + ExtraDamage) +
                            ((((IPlayer.GetMaxMagAttack() + ExtraDamage) / 4) +
                                    (CChar::GetInt((int)IPlayer.GetOffset()) / 4)) +
                                ((CChar::GetWis((int)IPlayer.GetOffset()) / 4) +
                                    (nSkillGrade * 450))))) + (IPlayer.GetLevel() * 2);

                if (Target.GetType() == 0) {
                    nDmg = (nDmg * SHMME) / 100;
                }

                IPlayer.OktayDamageSingle(Target, nDmg, 54);
                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);
            }
        } else {
            IPlayer.CouldntExecuteSkill();
        }
    }
}
