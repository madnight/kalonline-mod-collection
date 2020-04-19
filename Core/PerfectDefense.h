void __fastcall PerfectDefense(IChar IPlayer)
{
	int pSkill = IPlayer.GetSkillPointer(40);

	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int nMana = (int)(IPlayer.GetLevel() * 4 + 20) + (((IPlayer.GetLevel() * 4 + 20) * xSkill.GetGrade()) / 10);

		if (IPlayer.IsBuff(282))
			return;

		if (IPlayer.GetCurMp() <= nMana)
			return;
		else
			IPlayer.DecreaseMana(nMana);

		if (IPlayer.IsValid() && IPlayer.IsParty())
		{
			void *Party = (void*)CParty::FindParty(IPlayer.GetPartyID());

			if (Party)
			{
				for ( int i = CParty::GetPlayerList(Party); i; i = CBaseList::Pop((void*)i) )
				{
					int Members = *(DWORD*)((void*)i);
					IChar IMembers((void*)*(DWORD*)((void*)i));

					if (IMembers.IsValid() && IPlayer.IsValid())
					{
						if (CChar::GetRange((int)IPlayer.GetOffset() + 332, Members + 332) <= 300 && !IMembers.IsBuff(282) && !IMembers.IsBuff(283))
						{
							IMembers.SendGStateEx(IMembers.GetGStateEx() + 1);
							IMembers.SetBuffIcon((10+(xSkill.GetGrade() * 5)) * 1000, 0, 1795, 200);
							IMembers.Buff(282, 9+(xSkill.GetGrade() * 5), 0);
							IMembers.Buff(283, 15+(xSkill.GetGrade() * 5), 0);

							if (IPlayer.GetOffset() == IMembers.GetOffset())
								IPlayer.Buff(284, 15+(xSkill.GetGrade() * 5), 0);
						}
					}
				}
			}
		} else {
			if (IPlayer.IsValid() && !IPlayer.IsBuff(282) && !IPlayer.IsBuff(283))
			{
				IPlayer.SendGStateEx(IPlayer.GetGStateEx() + 1);
				IPlayer.SetBuffIcon((10+(xSkill.GetGrade() * 5)) * 1000, 0, 1795, 200);
				IPlayer.Buff(282, 9+(xSkill.GetGrade() * 5), 0);
				IPlayer.Buff(283, 15+(xSkill.GetGrade() * 5), 0);
				IPlayer.Buff(284, 15+(xSkill.GetGrade() * 5), 0);
			}
		}

		IPlayer._ShowBattleAnimation(IPlayer, 40);
	}
}