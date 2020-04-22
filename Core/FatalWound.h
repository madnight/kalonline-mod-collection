void __fastcall ContinueFatalWound(IChar IPlayer)
{
    if (IPlayer.IsValid())
    {
        int nSkillGrade = CheckFarContinueSkill.find(
                IPlayer.GetPID())->second.PlayerSkillGrade;
        void *pTarget = CheckFarContinueSkill.find(
                IPlayer.GetPID())->second.PlayerTarget;

        if (nSkillGrade && pTarget &&
            CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
        {
            IChar Target(pTarget);
            CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

            if (!Target.IsValid() || !IPlayer.IsValid())
            {
                ResetFarContinueSkill(IPlayer);
                return;
            }

            if (!IPlayer.IsInRange(Target, 300))
            {
                ResetFarContinueSkill(IPlayer);
                return;
            }

            if (IPlayer.IsValid() && Target.IsValid())
            {
                int nDmg = (IPlayer.GetAttack() * TFWMul) + (nSkillGrade * CTools::Rate(TFWMin,
                            TFWMax));

                if (Target.GetType() == 0) {
                    nDmg = (nDmg * TFWReduce) / 100;
                }

                IPlayer.OktayDamageArea(Target, nDmg, 14);
            }

            if (IPlayer.IsOnline()) {
                CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() +
                    2000;
            }

            if (IPlayer.IsOnline() &&
                CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0) {
                ResetFarContinueSkill(IPlayer);
            }

            return;
        }
    }

    ResetFarContinueSkill(IPlayer);
    return;
}

void __fastcall FatalWound(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(14);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (int)(30 * nSkillGrade + 15);

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

                if (!Target.IsBuff(348))
                {
                    Target.SendGStateEx(Target.GetGStateEx() + 32768);
                    Target.Buff(348, 16, 0);
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerTarget = Target.GetOffset();
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillID = 14;
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 8;
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = nSkillGrade;
                }

                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(nMana);
                IPlayer._ShowBattleAnimation(Target, 14, nSkillGrade);
            }
        }
    }
}