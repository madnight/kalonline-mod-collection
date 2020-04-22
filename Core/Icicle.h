void __fastcall ContinueIcicle(IChar IPlayer)
{
    if (IPlayer.IsValid())
    {
        if (CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
        {
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

            if (IPlayer.IsMoved(CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerX,
                    CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerY))
            {
                ResetContinueSkill(IPlayer);
                return;
            }

            if (!IPlayer.IsValid())
            {
                ResetContinueSkill(IPlayer);
                return;
            }

            int Around = IPlayer.GetObjectListAround(3);

            while (Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.IsValid() && IPlayer.IsValid() &&
                    (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))
                    ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                {
                    int nDmg = (IPlayer.GetMagic() * MIcicleMul) +
                        (CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillGrade *
                            CTools::Rate(MIcicleMin, MIcicleMax));

                    if (Object.GetType() == 0) {
                        nDmg = (nDmg * MIcicleReduce) / 100;
                    }

                    IPlayer.OktayDamageArea(Object, nDmg, 66);
                }

                Around = CBaseList::Pop((void*)Around);
            }

            if (IPlayer.IsOnline()) {
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 2000;
            }

            if (IPlayer.IsOnline() &&
                CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0) {
                ResetContinueSkill(IPlayer);
            }

            return;
        }
    }

    ResetContinueSkill(IPlayer);
    return;
}

void __fastcall Icicle(IChar IPlayer)
{
    int pSkill = IPlayer.GetSkillPointer(66);

    if (IPlayer.IsValid() && pSkill)
    {
        int nMana = IPlayer.GetLevel() * 4 + 120;

        if (IPlayer.GetCurMp() < nMana) {
            return;
        }

        IPlayer.DecreaseMana(nMana);
        ISkill xSkill((void*)pSkill);
        CheckContinueSkill[IPlayer.GetPID()].PlayerX = IPlayer.GetX();
        CheckContinueSkill[IPlayer.GetPID()].PlayerY = IPlayer.GetY();
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 66;
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = xSkill.GetGrade();
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 5;
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
        IPlayer._ShowBattleAnimation(IPlayer, 66);
    }
}
