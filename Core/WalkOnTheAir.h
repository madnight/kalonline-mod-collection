void __fastcall WalkOnTheAir(IChar IPlayer)
{
	if (IPlayer.IsBuff(385))
	{
		IPlayer.CancelBuff(385);
		IPlayer.CancelBuff(40);
		IPlayer.RemoveBuffIcon(-2, -1, 4246, 954);
		return;
	}

	if (IPlayer.IsOnline())
	{
		int pSkill = IPlayer.GetSkillPointer(95);

		if (pSkill && IPlayer.IsValid())
		{
			ISkill xSkill((void*)pSkill);

			if (IPlayer.GetCurMp() <= 8)
			{
				IPlayer.CouldntExecuteSkill();
				return;
			}

			IPlayer.Buff(40, 3600, 10*xSkill.GetGrade());
			IPlayer.RemoveBuffIcon(0, 0, 0, 54);
			IPlayer.Buff(385,3600,0);
			IPlayer.SetBuffIcon(-2, -1, 4246, 954);
		}
	}
}