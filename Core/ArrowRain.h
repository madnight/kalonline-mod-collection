void __fastcall ContinueArrowRain(IChar IPlayer)
{
    if (IPlayer.IsValid())
    {
        int nSkillGrade = CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillGrade;
        void *pTarget = CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerTarget;

        if (pTarget && nSkillGrade &&
                CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
        {
            IChar Target(pTarget);
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

            if (!IPlayer.IsValid() || !Target.IsValid())
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

            int Around = Target.GetObjectListAround(3);

            while(Around)
            {
                IChar Object((void*)*(DWORD*)Around);

                if (Object.IsValid() && IPlayer.IsValid() &&
                        (*(int (__thiscall **)(int, int, DWORD))
                         (*(DWORD *)IPlayer.GetOffset() + 176))
                        ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                {
                    int nDmg = (IPlayer.GetAttack() * AARMul) +
                        (nSkillGrade * CTools::Rate(AARMin,AARMax));

                    if (Object.GetType() == 0)
                        nDmg = (nDmg * AARReduce) / 100;

                    IPlayer.OktayDamageArea(Object,nDmg,47);
                }

                Around = CBaseList::Pop((void*)Around);
            }

            if (IPlayer.IsOnline())
                CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 2000;

            if (IPlayer.IsOnline()
                    && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0)
                ResetContinueSkill(IPlayer);

            return;
        }
    }

    ResetContinueSkill(IPlayer);
    return;
}

void __fastcall ArrowRain(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(47);

    if (IPlayer.IsValid() && pSkill)
    {
        int x = 0, y = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "dd", &x, &y);
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nMana = 20 + (IPlayer.GetLevel() * 4);

        if (x <= 0 || y <= 0)
            return;

        if (nSkillGrade && IPlayer.IsValid())
        {
            if (IPlayer.GetCurMp() < nMana)
                return;

            IPlayer.DecreaseMana(nMana);
            IPlayer._ShowBattleAnimation(IPlayer,47);
            int *GetSetXY = new int[1];
            GetSetXY[0] = x;
            GetSetXY[1] = y;
            int check = CMonsterMagic::Create(567,IPlayer.GetMap(),
                    (int)GetSetXY,1,(int)IPlayer.GetOffset(),0,10000);
            delete[] GetSetXY;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 47;
            CheckContinueSkill[IPlayer.GetPID()].PlayerTarget = (void*)check;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = nSkillGrade;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 5;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
            CheckContinueSkill[IPlayer.GetPID()].PlayerX = IPlayer.GetX();
            CheckContinueSkill[IPlayer.GetPID()].PlayerY = IPlayer.GetY();
        }
    }
}
