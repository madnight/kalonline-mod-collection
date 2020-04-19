void __fastcall ContinueZilPoong(IChar IPlayer)
{
    if (IPlayer.IsValid() && CChar::IsGState((int)IPlayer.GetOffset(),512))
    {
        void *pTarget = CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerTarget;

        if (pTarget && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
        {
            IChar Target(pTarget);
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target, 2))
                {
                    ResetContinueSkill(IPlayer);
                    return;
                }

                if (IPlayer.CheckHit(Target, 20))
                {
                    int nDmg = (IPlayer.GetAttack() * TEZilMul);

                    if(Target.GetType() == 0)
                        nDmg = nDmg * TEZilReduce / 100;

                    IPlayer.OktayDamageSingle(Target,nDmg,6);
                } else {
                    IPlayer._ShowBattleMiss(Target, 6);
                }

                if (IPlayer.IsOnline())
                    CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 800;

                if (IPlayer.IsOnline() &&
                        CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0)
                    ResetContinueSkill(IPlayer);

                return;
            }
        }
    }

    ResetContinueSkill(IPlayer);
    return;
}

void __fastcall ZilPoong(IChar IPlayer, int pPacket, int pPos)
{
    if (IPlayer.IsValid() && IPlayer.GetRage() >= 4000)
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

            if (pTarget == IPlayer.GetOffset())
                return;

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                IPlayer.DecreaseRage(4000);
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 111;
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 3;
                CheckContinueSkill[IPlayer.GetPID()].PlayerTarget = Target.GetOffset();
                IPlayer._ShowBattleAnimation(IPlayer, 111);
            }
        }
    }
}
