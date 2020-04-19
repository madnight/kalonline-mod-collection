void __fastcall Hiding(IChar IPlayer)
{
	int pSkill = IPlayer.GetSkillPointer(6);

	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int hide = xSkill.GetGrade(), sstep = 0, time = 0, nMana = 0;
		int sstepcheck = IPlayer.GetSkillPointer(27);
		int dbreath = IPlayer.GetSkillPointer(24);
		nMana = hide * 10 + 10;
		time = (hide * 5) + 15;

		if (dbreath)
			time += 10;

		if (sstepcheck)
			sstep = 1;

		if (IPlayer.GetCurMp() < nMana)
			return;

		if (!IPlayer.IsBuff(329))
			IPlayer.SendGStateEx(IPlayer.GetGStateEx() + 16);

		if (sstep)
			IPlayer.Buff(40, time, -50 + 20);
		else
			IPlayer.Buff(40, time, -50);
		
		IPlayer.RemoveBuffIcon(0, 0, 0, 54);
		IPlayer._ShowBattleAnimation(IPlayer,6,hide);
		IPlayer.Buff(329, time, 0);
		IPlayer.DecreaseMana(nMana);
	}
}