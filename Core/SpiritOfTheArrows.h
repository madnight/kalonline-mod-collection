void __fastcall SpiritOfTheArrows(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(93);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0, nMana = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        nMana = (1.85 * (200 + (nSkillGrade * (20 + (nSkillGrade - 1)))));

        if (bType == 0 && nTargetID)
            pTarget = CPlayer::FindPlayer(nTargetID);

        if (bType == 1 && nTargetID)
            pTarget = CMonster::FindMonster(nTargetID);

        if (bType >= 2)
            return;

        if (pTarget && nSkillGrade && IPlayer.IsOnline())
        {
            IChar Target(pTarget);

            if (IPlayer.GetCurMp() < nMana)
                return;

            if (pTarget == IPlayer.GetOffset())
                return;

            if (!IPlayer.IsInRange(Target,300))
                return;

            int Around = Target.GetObjectListAround(3);

            while(Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.IsValid() && IPlayer.IsValid()
                        && (*(int (__thiscall **)(int, int, DWORD))
                            (*(DWORD *)IPlayer.GetOffset() + 176))
                        ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                {
                    int nDmg = (IPlayer.GetAttack() * NSOTAMul) + (nSkillGrade * CTools::Rate(
                                   NSOTAMin,NSOTAMax));

                    if (Object.GetType() == 0)
                        nDmg = nDmg * NSOTAReduce / 100;

                    IPlayer.OktayDamageArea(Object,nDmg,93);
                }

                Around = CBaseList::Pop((void*)Around);
            }

            IPlayer.SetDirection(Target);
            IPlayer._ShowBattleAnimation(Target, 93);
            IPlayer.DecreaseMana(nMana);
        }
    }
}
