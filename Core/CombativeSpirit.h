void __fastcall CombativeSpirit(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(51);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
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

        if (IPlayer.IsValid() && pTarget && nSkillGrade)
        {
            IChar Target(pTarget);
            int nMana = (int)(((((nSkillGrade-1)+20) * nSkillGrade)+200) * 1.85);

            if (pTarget == IPlayer.GetOffset())
                return;

            if (IPlayer.GetCurMp() < nMana)
                return;

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                IPlayer.DecreaseMana(nMana);

                if (IPlayer.CheckHit(Target,30))
                {
                    IPlayer.SetDirection(Target);
                    IPlayer._ShowBattleAnimation(Target,51);
                    int Around = Target.GetObjectListAround(3);

                    while(Around)
                    {
                        IChar Object((void*)*(DWORD*)Around);

                        if (Object.IsValid() && IPlayer.IsValid() &&
                                (*(int (__thiscall **)(int, int, DWORD))
                                 (*(DWORD *)IPlayer.GetOffset() + 176))
                                ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                        {
                            int nDmg = (IPlayer.GetAttack() * ACSMul) +
                                (nSkillGrade * CTools::Rate(ACSMin,ACSMax));

                            if (Target.GetType() == 0)
                                nDmg = (nDmg * ACSReduce) / 100;

                            if (Object.GetX() <= max(IPlayer.GetX(), Target.GetX()) &&
                                    Object.GetX() >= min(IPlayer.GetX(), Target.GetX()) &&
                                    Object.GetY() <= max(IPlayer.GetY(), Target.GetY()) &&
                                    Object.GetY() >= min(IPlayer.GetY(), Target.GetY()))
                                IPlayer.OktayDamageArea(Object,nDmg,51);
                        }

                        Around = CBaseList::Pop((void*)Around);
                    }
                } else {
                    IPlayer._ShowBattleMiss(Target,51);
                }
            }
        }
    }
}
