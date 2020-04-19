void __fastcall ShoutOfFightingSpirit(IChar IPlayer)
{
	if (IPlayer.IsOnline())
	{
		int pSkill = IPlayer.GetSkillPointer(92);

		if (IPlayer.IsValid() && pSkill)
		{
			ISkill xSkill((void*)pSkill);
			int Mana = 180 + (1.25 * (xSkill.GetGrade() * (IPlayer.GetLevel() + xSkill.GetGrade())));

			if (IPlayer.GetCurMp() <= Mana)
				return;

			IPlayer.DecreaseMana(Mana);
			IPlayer._ShowBattleAnimation(IPlayer, 92);

			if (IPlayer.IsValid())
			{
				if (IPlayer.IsParty())
				{
					void *Party = (void *)CParty::FindParty(IPlayer.GetPartyID());

					if (Party)
					{
						for (int i = CParty::GetPlayerList(Party); i; i = CBaseList::Pop((void*)i))
						{
							int Members = *(DWORD*)((void*)i);
							IChar IMembers((void*)*(DWORD*)((void*)i));

							if (CChar::IsNormal(Members) && IPlayer.IsValid())
							{
								if (CChar::GetRange((int)IPlayer.GetOffset() + 332, Members + 332) <= 300 && !IMembers.IsBuff(383) && !IMembers.IsBuff(382) && !IMembers.IsBuff(381))
								{
									IMembers.SetBuffIcon(1000*(4+(xSkill.GetGrade()*3)), 0, 4243, 951);
									IMembers.Buff(380+xSkill.GetGrade(),6+(xSkill.GetGrade()*3),0);
									IMembers.Buff(384,4+(xSkill.GetGrade()*3),0);
									IMembers.AddMaxAttack(xSkill.GetGrade()*200);
									IMembers.AddMinAttack(xSkill.GetGrade()*200);
								}
							}
						}
					}
				} else {
					if (!IPlayer.IsBuff(383) && !IPlayer.IsBuff(382) && !IPlayer.IsBuff(381))
					{
						IPlayer.SetBuffIcon(1000*(4+(xSkill.GetGrade()*3)), 0, 4243, 951);
						IPlayer.Buff(380+xSkill.GetGrade(),6+(xSkill.GetGrade()*3),0);
						IPlayer.Buff(384,4+(xSkill.GetGrade()*3),0);
						IPlayer.AddMaxAttack(xSkill.GetGrade()*200);
						IPlayer.AddMinAttack(xSkill.GetGrade()*200);
					}
				}
			}
		}
	}
}