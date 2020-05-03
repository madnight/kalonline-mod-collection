void __fastcall ContinueSpinBlade(IChar IPlayer)
{
    if (IPlayer.IsValid())
    {
        if (CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
        {
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

            if (!IPlayer.IsValid())
            {
                ResetContinueSkill(IPlayer);
                return;
            }

            if (IPlayer.IsMoved(CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerX,
                    CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerY))
            {
                ResetContinueSkill(IPlayer);
                return;
            }

            int Around = IPlayer.GetObjectListAround(3);

            while (Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.IsValid() && IPlayer.IsValid()
                    && (*(int (__thiscall **)(int, int, DWORD))
                        (*(DWORD *)IPlayer.GetOffset() + 176))((int)IPlayer.GetOffset(),
                        (int)Object.GetOffset(), 0))
                {
                    int nDmg = (IPlayer.GetAttack() * TSBMul) + (CheckContinueSkill.find(
                                IPlayer.GetPID())->second.PlayerSkillGrade * CTools::Rate(TSBMin, TSBMax));

                    if (Object.GetType() == 0) {
                        nDmg = (nDmg * TSBReduce) / 100;
                    }

                    if (IPlayer.CheckHit(Object, 10) || Object.GetType() == 1) {
                        IPlayer.OktayDamageArea(Object, nDmg, 36);
                    }
                }

                Around = CBaseList::Pop((void*)Around);
            }

            IPlayer._ShowBattleAnimation(IPlayer, 36);

            if (IPlayer.IsOnline()) {
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 1000;
            }

            if (IPlayer.IsOnline()
                && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0) {
                ResetContinueSkill(IPlayer);
            }

            return;
        }
    }

    ResetContinueSkill(IPlayer);
    return;
}

void __fastcall SpinBlade(IChar IPlayer)
{
    int pSkill = IPlayer.GetSkillPointer(36);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nMana = (int)((((nSkillGrade + IPlayer.GetLevel()) * nSkillGrade) * 1.25) +
                180);

        if (IPlayer.GetCurMp() < nMana) {
            return;
        }

        if (nSkillGrade && IPlayer.IsValid())
        {
            IPlayer.DecreaseMana(nMana);
            CheckContinueSkill[IPlayer.GetPID()].PlayerX = IPlayer.GetX();
            CheckContinueSkill[IPlayer.GetPID()].PlayerY = IPlayer.GetY();
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 36;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = xSkill.GetGrade();
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = xSkill.GetGrade() + 1;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
        }
    }
}
