void __fastcall IceArrow(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(74);
    __int64 GState = 536870912, State = 64, StateEx = 65, CancelState = 1;

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

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

            if (pTarget == IPlayer.GetOffset()) {
                return;
            }

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target, 300)) {
                    return;
                }

                if (CheckIceArrow.find(IPlayer.GetPID())->second.Cooldown < GetTickCount())
                {
                    CheckIceArrow[IPlayer.GetPID()].Cooldown = GetTickCount() + 70000;
                    CheckIceArrow[IPlayer.GetPID()].Delay = GetTickCount() + 200;
                }

                if (IPlayer.IsValid() && IPlayer.IsBuff(294))
                {
                    IPlayer.CancelBuff(294);
                    IPlayer.Buff(293, 18, 0);
                    IPlayer.Buff(295, 18, 0);
                    IPlayer.SendGStateExIceArrow(GState*8);
                    IPlayer.SendGStateExIceArrow(State << 32);
                } else if (IPlayer.IsValid() && IPlayer.IsBuff(293))
                {
                    IPlayer.CancelBuff(293);
                    IPlayer.Buff(292, 18, 0);
                    IPlayer.Buff(295, 18, 0);
                    IPlayer.SendGStateExIceArrow(GState*4);
                    IPlayer.SendGStateExIceArrow(State << 32);
                } else if (IPlayer.IsValid() && IPlayer.IsBuff(292))
                {
                    IPlayer.CancelBuff(292);
                    IPlayer.Buff(291, 18, 0);
                    IPlayer.Buff(295, 18, 0);
                    IPlayer.SendGStateExIceArrow(GState*2);
                    IPlayer.SendGStateExIceArrow(State << 32);
                } else if (IPlayer.IsValid() && IPlayer.IsBuff(291))
                {
                    IPlayer.CancelBuff(291);
                    IPlayer.Buff(290, 18, 0);
                    IPlayer.Buff(295, 18, 0);
                    IPlayer.SendGStateExIceArrow(GState);
                    IPlayer.SendGStateExIceArrow(State << 32);
                } else if (IPlayer.IsValid() && IPlayer.IsBuff(290))
                {
                    IPlayer.CancelBuff(290);
                    IPlayer.CancelBuff(295);
                } else {
                    return;
                }

                int nDmg = (IPlayer.GetMagic() * MIAMul) +
                    (xSkill.GetGrade() * CTools::Rate(MIAMin, MIAMax));

                if (Target.GetType() == 0) {
                    nDmg = (nDmg * MIAReduce) / 100;
                }

                IPlayer.OktayDamageSingle(Target, nDmg, 74);
                IPlayer.SetDirection(Target);
            }
        }
    }
}
