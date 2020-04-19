void __fastcall Gangshin4th(IChar IPlayer, int pPacket, int pPos)
{
	int pSkill = IPlayer.GetSkillPointer(93);

	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int nSkillGrade = xSkill.GetGrade();
		int Mana = 10;

		if (IPlayer.GetCurMp() <= Mana)
			return;

		IPlayer.DecreaseMana(Mana);
		IPlayer._ShowBattleAnimation(IPlayer, 93);

		if(IPlayer.IsValid())
		{
			if (IPlayer.IsParty())
			{
				void *Party = (void *)CParty::FindParty(IPlayer.GetPartyID());

				if (Party)
				{
					for (int i = CParty::GetPlayerList(Party); i; i = CBaseList::Pop((void *)i))
					{
						int Members = *(DWORD*)((void*)i);
						IChar IMembers((void*)*(DWORD*)((void*)i));

						if (CChar::IsNormal(Members) && IPlayer.IsValid())
						{
							if (CChar::GetRange((int)IPlayer.GetOffset() + 332, Members + 332) <= 300 && !IMembers.IsBuff(414))
							{
								IMembers.SetBuffIcon(1000*((nSkillGrade*60)+240), 0, 9109, 1018);
								IMembers.AddAgi(60*nSkillGrade);
								IMembers.Buff(413,(nSkillGrade*60)+240,0);
								IMembers.Buff(414,(nSkillGrade*100)+240,60*nSkillGrade);
							}
						}
					}
				}
			} else {
				if (!IPlayer.IsBuff(414))
				{
					IPlayer.SetBuffIcon(1000*((nSkillGrade*60)+240), 0, 9109, 1018);
					IPlayer.AddAgi(60*nSkillGrade);
					IPlayer.Buff(413,(nSkillGrade*60)+240,0);
					IPlayer.Buff(414,(nSkillGrade*100)+240,60*nSkillGrade);
				}
			}
		}
	}
}