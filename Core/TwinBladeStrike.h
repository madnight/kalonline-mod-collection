void __fastcall ContinueTwinBladeStrike(IChar IPlayer)
{
    if (IPlayer.IsValid())
    {
        void *pTarget = CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerTarget;
        IChar Target(pTarget);

        if (pTarget && Target.IsValid() && IPlayer.IsValid())
        {
            if (CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
            {
                CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

                if (CChar::GetRange((int)IPlayer.GetOffset() + 332, (int)pTarget + 332) > 300)
                {
                    ResetFarContinueSkill(IPlayer);
                    return;
                }

                if (IPlayer.CheckHit(Target, 10))
                {
                    int nDmg = (IPlayer.GetAttack() * TTBSMul) + (CTools::Rate(TTBSMin,TTBSMax));

                    if(Target.GetType() == 0)
                        nDmg = nDmg * TTBSReduce / 100;

                    IPlayer.OktayDamageArea(Target,nDmg,23);
                }

                if (IPlayer.IsOnline())
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 2000;

                if (IPlayer.IsOnline() && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0)
                    ResetFarContinueSkill(IPlayer);

                return;
            }
        }
    }

    ResetFarContinueSkill(IPlayer);
    return;
}

void __fastcall TwinBladeStrike(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(23);

    if (IPlayer.IsValid() && pSkill)
    {
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

        if (bType == 0 && nTargetID)
            pTarget = CPlayer::FindPlayer(nTargetID);

        if (bType == 1 && nTargetID)
            pTarget = CMonster::FindMonster(nTargetID);

        if (bType >= 2)
            return;

        if (pTarget && IPlayer.IsValid())
        {
            IChar Target(pTarget);

            if (IPlayer.GetCurMp() < 65)
                return;

            if (pTarget == IPlayer.GetOffset())
                return;

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                if (IPlayer.CheckHit(Target, 10))
                {
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerTarget = Target.GetOffset();
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillID = 23;
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 4;
                    CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 2000;

                    if (!Target.IsBuff(339))
                        Target.SendGStateEx(Target.GetGStateEx() + 262144);

                    Target.Buff(339,8,0);
                    Target.Buff(340,12,0);
                    IPlayer.Buff(341,20,0);

                    if (Target.GetType() == 0)
                    {
                        IPlayer.RemoveBuffIcon(0,0,0,219);
                        Target.SetBuffIcon(10000, 0, 2021,219);
                    }

                    int nDmg = (IPlayer.GetAttack() * TTBSMul) + (CTools::Rate(TTBSMin,TTBSMax));

                    if (Target.GetType() == 0)
                        nDmg = nDmg * TTBSReduce / 100;

                    IPlayer.OktayDamageSingle(Target,nDmg,23);
                } else {
                    IPlayer._ShowBattleMiss(Target, 23);
                }

                IPlayer.SetDirection(Target);
                IPlayer.DecreaseMana(65);
            }
        }
    }
}