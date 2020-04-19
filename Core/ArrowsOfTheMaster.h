void __fastcall ArrowsOfTheMaster(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(92);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0, nMana = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

        if (bType == 0 && nTargetID)
            pTarget = CPlayer::FindPlayer(nTargetID);

        if (bType == 1 && nTargetID)
            pTarget = CMonster::FindMonster(nTargetID);

        if (bType >= 2)
            return;

        if (pTarget && nSkillGrade && IPlayer.IsValid())
        {
            nMana = (1.85 * (200 + (nSkillGrade * (20 + (nSkillGrade - 1)))));
            IChar Target(pTarget);

            if (pTarget == IPlayer.GetOffset())
                return;

            if (IPlayer.GetCurMp() < nMana)
                return;

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                int Around = Target.GetObjectListAround(3);

                while(Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.IsValid() && IPlayer.IsValid() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                    {
                        int nDmg = (IPlayer.GetAttack() * NAOTMMul) + (nSkillGrade * CTools::Rate(NAOTMMin,NAOTMMax));

                        if (Object.GetType() == 0)
                            nDmg = (nDmg * NAOTMReduce) / 100;

                        IPlayer.OktayDamageArea(Object,nDmg,92);
                    }

                    Around = CBaseList::Pop((void*)Around);
                }

                IPlayer.DecreaseMana(nMana);
                IPlayer.SetDirection(Target);
                IPlayer._ShowBattleAnimation(Target,92);
            }
        }
    }
}