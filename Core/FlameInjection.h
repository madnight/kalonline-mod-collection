void __fastcall ContinueFlameInjection(IChar IPlayer)
{
    if (IPlayer.IsValid())
    {
        int nSkillGrade = CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillGrade;

        if (nSkillGrade && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
        {
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

            if (!IPlayer.IsValid())
            {
                ResetContinueSkill(IPlayer);
                return;
            }

            if (IPlayer.IsMoved(
                        CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerX,
                        CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerY))
            {
                ResetContinueSkill(IPlayer);
                return;
            }

            int Around = IPlayer.GetObjectListAround(4);

            while(Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.IsValid() && IPlayer.IsValid() &&
                        (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))
                        ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                {
                    int nDmg = (IPlayer.GetMagic() * MFIMul) +
                        (nSkillGrade * CTools::Rate(MFIMin,MFIMax));

                    if (Object.GetType() == 0)
                        nDmg = (nDmg * MFIReduce) / 100;

                    IPlayer.OktayDamageArea(Object,nDmg,65);
                }

                Around = CBaseList::Pop((void*)Around);
            }

            if (IPlayer.IsOnline())
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 2000;

            if (IPlayer.IsOnline() &&
                    CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0)
                ResetContinueSkill(IPlayer);

            return;
        }
    }

    ResetContinueSkill(IPlayer);
    return;
}

void __fastcall FlameInjection(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(65);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = IPlayer.GetLevel() * 4 + 120;

        if (bType == 0 && nTargetID)
            pTarget = CPlayer::FindPlayer(nTargetID);

        if (bType == 1 && nTargetID)
            pTarget = CMonster::FindMonster(nTargetID);

        if (bType >= 2)
            return;

        if (pTarget && nSkillGrade && IPlayer.IsValid())
        {
            IChar Target(pTarget);

            if (IPlayer.GetCurMp() < nMana)
                return;

            if (pTarget == IPlayer.GetOffset())
                return;

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                IPlayer.DecreaseMana(nMana);
                CheckContinueSkill[IPlayer.GetPID()].PlayerX = IPlayer.GetX();
                CheckContinueSkill[IPlayer.GetPID()].PlayerY = IPlayer.GetY();
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 65;
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = xSkill.GetGrade();
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 6;
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
                IPlayer._ShowBattleAnimation(IPlayer, 65);
            }
        }
    }
}
