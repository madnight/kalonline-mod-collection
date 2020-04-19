void __fastcall CounterDamage(IChar IPlayer)
{
	if (IPlayer.IsValid())
	{
		void *pTarget = CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerTarget;
		IChar Target(pTarget);

		if (pTarget && IPlayer.IsValid() && Target.IsValid())
		{
			IPlayer.AddFxToTarget("Counterattack_Spear_2",1,0,0);

			if (CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
			{
				CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

				if (IPlayer.IsValid() && Target.IsValid())
				{
					if (!IPlayer.IsInRange(Target,300))
					{
						ResetFarContinueSkill(IPlayer);
						return;
					}

					if (CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerDamage > 1000)
						CheckFarContinueSkill[IPlayer.GetPID()].PlayerDamage = 1000;

					int nDmg = CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerDamage;
					IPlayer.OktayDamageArea(Target,nDmg,76);

					if (IPlayer.IsOnline() && CheckFarContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0)
						ResetFarContinueSkill(IPlayer);

					if (IPlayer.IsOnline())
						CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 2000;

					return;
				}
			}
		}
	}

	ResetFarContinueSkill(IPlayer);
	return;
}