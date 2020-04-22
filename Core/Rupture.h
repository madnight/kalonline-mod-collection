void __fastcall ContinueRupture(IChar IPlayer)
{
    if (IPlayer.IsValid())
    {
        int nSkillGrade = CheckRuptureContinueSkill.find(
                IPlayer.GetPID())->second.PlayerSkillGrade;
        void *pTarget = CheckRuptureContinueSkill.find(
                IPlayer.GetPID())->second.PlayerTarget;

        if (nSkillGrade && pTarget
            && CheckRuptureContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
        {
            IChar Target(pTarget);
            CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

            if (!Target.IsValid() || !IPlayer.IsValid())
            {
                ResetRuptureContinueSkill(IPlayer);
                return;
            }

            if (CChar::GetRange((int)IPlayer.GetOffset() + 332, (int)pTarget + 332) > 300)
            {
                ResetRuptureContinueSkill(IPlayer);
                return;
            }

            if (IPlayer.IsValid() && Target.IsValid())
            {
                int nDmg = (IPlayer.GetAttack() * TRupMul) + (nSkillGrade * CTools::Rate(
                            TRupMin, TRupMax));

                if (Target.GetType() == 0) {
                    nDmg = nDmg * TRupReduce / 100;
                }

                IPlayer.OktayDamageArea(Target, nDmg, 17);
            }

            if (IPlayer.IsOnline())
                CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() +
                    2000;

            if (IPlayer.IsOnline()
                && CheckRuptureContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount ==
                0) {
                ResetRuptureContinueSkill(IPlayer);
            }

            return;
        }
    }

    ResetRuptureContinueSkill(IPlayer);
    return;
}

void __fastcall Rupture(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(17);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (int)(30 * nSkillGrade + 35);

        if (bType == 0 && nTargetID) {
            pTarget = CPlayer::FindPlayer(nTargetID);
        }

        if (bType == 1 && nTargetID) {
            pTarget = CMonster::FindMonster(nTargetID);
        }

        if (bType >= 2) {
            return;
        }

        if (pTarget && IPlayer.IsValid() && nSkillGrade)
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

                if (IPlayer.CheckHit(Target, 10))
                {
                    IPlayer.Buff(353, 20, 0);

                    if (!Target.IsBuff(350)) {
                        Target.SendGStateEx(Target.GetGStateEx() + 65536);
                    }

                    Target.Buff(350, 18, 0);
                    CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerTarget = Target.GetOffset();
                    CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillID = 17;
                    CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 9;
                    CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() +
                        1000;
                    CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = nSkillGrade;
                    IPlayer._ShowBattleAnimation(IPlayer, 17, nSkillGrade);
                } else {
                    IPlayer._ShowBattleMiss(Target, 17);
                }

                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}
