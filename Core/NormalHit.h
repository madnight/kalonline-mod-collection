int __fastcall NormalHit(void *Player, void *edx, int bType, int nTargetID)
{
    IChar IPlayer(Player);
    IPlayer.Buff(313,3,0);

    if (IPlayer.IsOnline() && IPlayer.GetType() == 0 && IPlayer.GetClass() == 3
            && IPlayer.IsBuff(329))
    {
        IPlayer.CancelBuff(329);
        IPlayer.CancelBuff(40);
        return 0;
    }

    if (IPlayer.IsValid() && IPlayer.IsBuff(349))
    {
        IPlayer.DisableRiding();
        return 0;
    }

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 1
            && IPlayer.GetSpecialty() == 23 && MageMICheck.count(IPlayer.GetPID())
            && MageMICheck.find(IPlayer.GetPID())->second)
        MageMICheck[IPlayer.GetPID()] = 0;

    if (IPlayer.IsOnline() && IPlayer.GetClass() == 1
            && IPlayer.GetSpecialty() == 23 && IPlayer.IsBuff(306))
    {
        int Check = 0;
        if (GetTickCount() < *(DWORD*)((int)Player + 1448)) Check = *(DWORD*)((
                        int)Player + 1448) - GetTickCount();
        if (Check > 500) return 0;
    }

    if (IPlayer.IsOnline() && IPlayer.GetType() == 0
            && CChar::IsGState((int)IPlayer.GetOffset(),512) && IPlayer.IsBuff(327))
        IPlayer.CancelBuff(327);

    if (IPlayer.IsOnline() && IPlayer.GetType() == 0
            && CheckContinueSkill.count(IPlayer.GetPID())
            && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID)
        ResetContinueSkill(IPlayer);

    if (IPlayer.IsValid() && nTargetID && IPlayer.GetType() == 0
            && IPlayer.GetClass() == 3 && !CChar::IsGState((int)IPlayer.Offset, 512)
            && IPlayer.IsBuff(333))
    {
        int Target = 0;

        if (bType == 0)
            Target = (int)CPlayer::FindPlayer(nTargetID);

        if (bType == 1)
            Target = (int)CMonster::FindMonster(nTargetID);

        if (bType >= 2)
            return 0;

        if (IPlayer.IsValid() && Target)
        {
            IChar ITarget((void*)Target);

            if(IPlayer.IsValid() && ITarget.IsValid() && IPlayer.CheckHit(ITarget, 10)
                    && IPlayer.GetMap() == ITarget.GetMap())
            {
                if (!IPlayer.IsInRange(ITarget,80))
                    return 0;

                if (ITarget.GetOffset() == IPlayer.GetOffset())
                    return 0;

                int pSkill = IPlayer.GetSkillPointer(13);

                if (IPlayer.IsValid() && pSkill)
                {
                    ISkill xSkill((void*)pSkill);
                    int nSkillGrade = xSkill.GetGrade();
                    int nDmg = (IPlayer.GetAttack() * TDOKMul) + (nSkillGrade * CTools::Rate(
                                   TDOKMin,TDOKMax));

                    if (ITarget.GetType() == 0)
                        nDmg = nDmg * TDOKReduce / 100;

                    int Check = CChar::GetASpeed((int)Player), DelayCheck = 0;
                    if (GetTickCount() < *(DWORD*)((int)Player + 1448)) DelayCheck = *(DWORD*)((
                                    int)Player + 1448) - GetTickCount();
                    *(DWORD*)((int)Player + 1448) = Check + GetTickCount();
                    if (DelayCheck > 2) return 0;
                    int CheckNormalDamage = IPlayer.OktayDamageSingle(ITarget,nDmg,13);

                    if (CheckNormalDamage && *((DWORD*)IPlayer.GetOffset() + 70) & 2146435072
                            && ((*((DWORD *)IPlayer.GetOffset() + 70) & 2147483648) != 0 ? 10 : 5) >
                            CTools::Rate(0, 99))
                    {
                        int DokBuffCheck = 0, Buff1 = 0, Buff2 = 0, Buff3 = 0, Buff4 = 0, Buff5 = 0,
                            Buff6 = 0, Buff7 = 0;
                        DokBuffCheck = *((DWORD *)IPlayer.GetOffset() + 70) & 2146435072;

                        if (DokBuffCheck > 16777216)
                        {
                            if (DokBuffCheck == 33554432)
                            {
                                Buff1 = CBuff::CreateBuff(116, 1, 5, CheckNormalDamage / 10);
                                (*(void (__thiscall **)(int, int))(*(DWORD*)ITarget.GetOffset() + 180))
                                    ((int)ITarget.GetOffset(), Buff1);
                                CChar::WriteInSight(IPlayer.GetOffset(), 73, "db", nTargetID, 34);
                            } else {
                                if (DokBuffCheck == 67108864)
                                {
                                    Buff2 = CBuff::CreateBuff(7, 2, 0, 67108864);
                                    (*(void (__thiscall **)(int, int))
                                     (*(DWORD*)ITarget.GetOffset() + 180))((int)ITarget.GetOffset(), Buff2);
                                    CChar::WriteInSight(IPlayer.GetOffset(), 73, "db", nTargetID, 35);
                                }
                            }
                        } else {
                            switch (DokBuffCheck)
                            {
                            case 16777216:
                                Buff3 = CBuff::CreateBuff(116, 1, 5, 7 * CheckNormalDamage / 100);
                                (*(void (__thiscall **)(DWORD, DWORD))
                                 (*(DWORD*)ITarget.GetOffset() + 180))((int)ITarget.GetOffset(), Buff3);
                                Buff4 = CBuff::CreateBuff(117, 5, -10, -10);
                                (*(void (__thiscall **)(DWORD, DWORD))
                                 (*(DWORD*)ITarget.GetOffset() + 180))((int)ITarget.GetOffset(), Buff4);
                                CChar::WriteInSight(IPlayer.GetOffset(), 73, "db", nTargetID, 33);
                                break;
                            case 4194304:
                                Buff5 = CBuff::CreateBuff(116, 1, 5, CheckNormalDamage / 10);
                                (*(void (__thiscall **)(DWORD, DWORD))
                                 (*(DWORD *)ITarget.GetOffset() + 180))((int)ITarget.GetOffset(), Buff5);
                                CChar::WriteInSight(IPlayer.GetOffset(), 73, "db", nTargetID, 31);
                                break;
                            case 8388608:
                                Buff6 = CBuff::CreateBuff(116, 1, 5, 7 * CheckNormalDamage / 100);
                                (*(void (__thiscall **)(DWORD, DWORD))
                                 (*(DWORD*)ITarget.GetOffset() + 180))((int)ITarget.GetOffset(), Buff6);
                                Buff7 = CBuff::CreateBuff(118, 5, -50, 0);
                                (*(void (__thiscall **)(DWORD, DWORD))
                                 (*(DWORD*)ITarget.GetOffset() + 180))((int)ITarget.GetOffset(), Buff7);
                                CChar::WriteInSight(IPlayer.GetOffset(), 73, "db", nTargetID, 32);
                                break;
                            }
                        }
                    }
                }
            } else {
                IPlayer._ShowBattleMiss(ITarget, 13);
            }

            return 0;
        }
    }

    if (IPlayer.IsOnline())
        return CPlayer::Attack(Player,bType,nTargetID);
    else
        return 0;
}
