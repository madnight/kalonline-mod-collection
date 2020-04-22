void __fastcall AmplificationOfBlood(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(38);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (106 + (nSkillGrade * 2));

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

            if (IPlayer.GetCurMp() < nMana || pTarget == IPlayer.GetOffset()) {
                return;
            }

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target, 300)) {
                    return;
                }

                int XpSkill = IPlayer.GetSkillPointer(41);
                int decHpVal = (IPlayer.GetCurHp() * 5) / 100;

                if (XpSkill)
                {
                    ISkill xSkillx((void*)XpSkill);

                    if (xSkillx.GetGrade() <= CTools::Rate(0, 6)) {
                        IPlayer.DecreaseHp(decHpVal);
                    }

                } else {
                    IPlayer.DecreaseHp(decHpVal);
                }

                int Around = Target.GetObjectListAround(1);
                int nDmg = (IPlayer.GetMaxMagAttack() + (((IPlayer.GetMaxMagAttack() / 1) +
                                (CChar::GetInt((int)IPlayer.GetOffset()) / 1)) +
                            ((CChar::GetWis((int)IPlayer.GetOffset()) / 1) +
                                (nSkillGrade * 350)))) + (IPlayer.GetLevel() * 10);

                if (Target.GetType() == 0) {
                    nDmg = (nDmg * SHMAOB) / 100;
                }

                IPlayer._ShowBattleAnimation(Target, 38);
                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);

                while (Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.IsValid() && IPlayer.IsValid() &&
                        (*(int (__thiscall **)(int, int, DWORD))
                            (*(DWORD *)IPlayer.GetOffset() + 176))
                        ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0)) {
                        IPlayer.OktayDamageArea(Object, nDmg, 38);
                    }

                    Around = CBaseList::Pop((void*)Around);
                }
            }
        } else {
            IPlayer.CouldntExecuteSkill();
        }
    }
}
