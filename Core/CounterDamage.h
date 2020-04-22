#define CFCS CheckFarContinueSkill

void __fastcall CounterDamage(IChar IPlayer)
{
    if (IPlayer.IsValid())
    {
        void *pTarget = CFCS.find(IPlayer.GetPID())->second.PlayerTarget;
        IChar Target(pTarget);

        if (pTarget && IPlayer.IsValid() && Target.IsValid())
        {
            IPlayer.AddFxToTarget("Counterattack_Spear_2", 1, 0, 0);

            if (CFCS.find(IPlayer.GetPID())->second.PlayerSkillCount)
            {
                CFCS[IPlayer.GetPID()].PlayerSkillCount--;

                if (IPlayer.IsValid() && Target.IsValid())
                {
                    if (!IPlayer.IsInRange(Target, 300))
                    {
                        ResetFarContinueSkill(IPlayer);
                        return;
                    }

                    if (CFCS.find(IPlayer.GetPID())->second.PlayerDamage > 1000) {
                        CFCS[IPlayer.GetPID()].PlayerDamage = 1000;
                    }

                    int nDmg = CFCS.find(IPlayer.GetPID())->second.PlayerDamage;
                    IPlayer.OktayDamageArea(Target, nDmg, 76);

                    if (IPlayer.IsOnline()
                        && CFCS.find(IPlayer.GetPID())->second.PlayerSkillCount == 0) {
                        ResetFarContinueSkill(IPlayer);
                    }

                    if (IPlayer.IsOnline()) {
                        CFCS[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 2000;
                    }

                    return;
                }
            }
        }
    }

    ResetFarContinueSkill(IPlayer);
    return;
}
