void __fastcall ContinueEggThunderbolt(IChar IPlayer)
{
    if (IPlayer.IsValid() && CChar::IsGState((int)IPlayer.GetOffset(), 512))
    {
        void *pTarget = CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerTarget;

        if (pTarget &&
            CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
        {
            IChar Target(pTarget);
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

            if (!IPlayer.IsValid() || !Target.IsValid())
            {
                ResetContinueSkill(IPlayer);
                return;
            }

            int Around = Target.GetObjectListAround(2);

            while (Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.IsValid() && IPlayer.IsValid() &&
                    (*(int (__thiscall **)(int, int, DWORD))
                        (*(DWORD *)IPlayer.GetOffset() + 176))
                    ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                {
                    int nDmg = (IPlayer.GetMagic() * ETBMul);

                    if (Object.GetType() == 0) {
                        nDmg = (nDmg * ETBReduce) / 100;
                    }

                    IPlayer.OktayDamageArea(Object, nDmg, 116);
                }

                Around = CBaseList::Pop((void*)Around);
            }

            if (IPlayer.IsOnline()) {
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 1500;
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

void __fastcall EggThunderbolt(IChar IPlayer)
{
    if (IPlayer.IsValid() && IPlayer.GetRage() >= 15000)
    {
        IPlayer.DecreaseRage(15000);
        int *GetSetXY = new int[1];
        GetSetXY[0] = IPlayer.GetX();
        GetSetXY[1] = IPlayer.GetY();
        int check = CMonsterMagic::Create(568, IPlayer.GetMap(),
                (int)GetSetXY, 1, (int)IPlayer.GetOffset(), 0, 8000);
        delete[] GetSetXY;
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 116;
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
        CheckContinueSkill[IPlayer.GetPID()].PlayerX = IPlayer.GetX();
        CheckContinueSkill[IPlayer.GetPID()].PlayerY = IPlayer.GetY();
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 6;
        CheckContinueSkill[IPlayer.GetPID()].PlayerTarget = (void*)check;
        IPlayer._ShowBattleAnimation(IPlayer, 116);
    }
}
