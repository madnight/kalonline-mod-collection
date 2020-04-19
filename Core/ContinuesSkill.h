void ContinuesSkill(void *Pack)
{
    CConsole::Blue("Core.dll loaded . . .");

    while (true)
    {
        CIOCriticalSection::Enter((void*)0x004e2078);
        CIOCriticalSection::Enter((void*)0x004e2098);
        CLink::MoveTo((void*)0x004e200c,(int)0x004e2004);
        CIOCriticalSection::Leave((void*)0x004e2098);
        for ( DWORD i = *(DWORD*)0x004E2004; i != 0x004E2004; i = *(DWORD*)i )
        {
            if ((void*)(i - 428))
            {
                IChar IPlayer((void*)(i - 428));

                if (IPlayer.IsOnline())
                {
                    if (IPlayer.IsOnline() && IPlayer.GetClass() == 3
                            && CheckContinueSkill.count(IPlayer.GetPID())
                            && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID
                            && IPlayer.IsBuff(329))
                        ResetContinueSkill(IPlayer);

                    if (IPlayer.IsOnline() && CChar::IsGState((int)IPlayer.GetOffset(),2)
                            && IPlayer.GetClass() == 3 && CheckRuptureContinueSkill.count(IPlayer.GetPID())
                            && CheckRuptureContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID)
                        ResetRuptureContinueSkill(IPlayer);

                    if (IPlayer.IsOnline() && IPlayer.GetClass() == 3
                            && CheckRuptureContinueSkill.count(IPlayer.GetPID())
                            && CheckRuptureContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID)
                    {
                        if (IPlayer.IsOnline()
                                && CheckRuptureContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 17
                                && GetTickCount() >= CheckRuptureContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckRuptureContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueRupture(IPlayer);
                    }

                    if (IPlayer.IsOnline() && CChar::IsGState((int)IPlayer.GetOffset(),2)
                            && CheckFarContinueSkill.count(IPlayer.GetPID())
                            && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID)
                        ResetFarContinueSkill(IPlayer);

                    if (IPlayer.IsOnline() && CheckFarContinueSkill.count(IPlayer.GetPID())
                            && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID)
                    {
                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 1
                                && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 76
                                && GetTickCount() >= CheckFarContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            CounterDamage(IPlayer);

                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 3
                                && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 23
                                && GetTickCount() >= CheckFarContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueTwinBladeStrike(IPlayer);

                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 3
                                && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 14
                                && GetTickCount() >= CheckFarContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueFatalWound(IPlayer);
                    }

                    if (IPlayer.IsOnline() && CChar::IsGState((int)IPlayer.GetOffset(),2)
                            && CheckContinueSkill.count(IPlayer.GetPID())
                            && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID)
                        ResetContinueSkill(IPlayer);

                    if (IPlayer.IsOnline() && CheckContinueSkill.count(IPlayer.GetPID())
                            && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID)
                    {
                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 0
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 43
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueSwordDance(IPlayer);

                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 1
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 65
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueFlameInjection(IPlayer);

                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 1
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 66
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueIcicle(IPlayer);

                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 1
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 75
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueThunderbolt(IPlayer);

                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 2
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 49
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueArrowExplosion(IPlayer);

                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 2
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 47
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueArrowRain(IPlayer);

                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 3
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 36
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueSpinBlade(IPlayer);

                        if (IPlayer.IsOnline() && IPlayer.GetClass() == 3
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 28
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueLightningSlash(IPlayer);

                        if (IPlayer.IsOnline()
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 111
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueZilPoong(IPlayer);

                        if (IPlayer.IsOnline()
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 114
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueWhirlwindFeather(IPlayer);

                        if (IPlayer.IsOnline()
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID == 116
                                && GetTickCount() >= CheckContinueSkill.find(
                                    IPlayer.GetPID())->second.PlayerSkillDelay
                                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
                            ContinueEggThunderbolt(IPlayer);
                    }
                }
            }
        }
        CIOCriticalSection::Leave((void*)0x004e2078);
        Sleep(100);
    }
}
