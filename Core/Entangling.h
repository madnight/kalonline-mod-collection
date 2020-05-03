void __fastcall Entangling(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(25);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (nSkillGrade * 2) + 100;
        int SetTime = 0;

        if (bType == 0 && nTargetID) {
            pTarget = CPlayer::FindPlayer(nTargetID);
        }

        if (bType == 1 && nTargetID) {
            pTarget = CMonster::FindMonster(nTargetID);
        }

        if (bType >= 2) {
            return;
        }

        if (pTarget && IPlayer.IsValid() && IPlayer.GetCurMp() >= nMana && nSkillGrade)
        {
            IChar ITarget(pTarget);

            int XpSkill = IPlayer.GetSkillPointer(31);

            if (XpSkill)
            {
                ISkill xSkillx((void*)XpSkill);
                SetTime += xSkillx.GetGrade();
            }

            if (ITarget.IsValid() && IPlayer.IsValid())
            {
                if (!IPlayer.IsInRange(ITarget, 300)) {
                    return;
                }

                IPlayer.DecreaseMana(nMana);
                IPlayer._ShowBattleAnimation(ITarget, 25);

                if (bType == 0)
                {
                    if (IPlayer.IsOnline() &&
                        IPlayer.GetLevel() >= ITarget.GetLevel() - 20) {
                        ITarget.Buff(8, (nSkillGrade*5)+2+SetTime, 0);
                    }
                } else {
                    int Around = ITarget.GetObjectListAround(2);

                    while (Around)
                    {
                        IChar Object((void*)*(DWORD*)Around);

                        if (Object.IsValid() && IPlayer.IsValid() &&
                            (*(int (__thiscall **)(int, int, DWORD))
                                (*(DWORD *)IPlayer.GetOffset() + 176))
                            ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                        {
                            if (IPlayer.IsOnline() &&
                                IPlayer.GetLevel() >= Object.GetLevel() - 20) {
                                Object.Buff(8, (nSkillGrade * 5) + 2 + SetTime, 0);
                            }
                        }

                        Around = CBaseList::Pop((void*)Around);
                    }
                }
            }
        }
    }
}
