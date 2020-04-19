void __fastcall BlessingOfAgility(int Packet, void *edx, int Player, int Target, int a3)
{
	IChar IPlayer((void*)Player);
	IChar ITarget((void*)Target);
	ISkill ISkill((void*)Packet);

	if (IPlayer.IsValid() && ITarget.IsValid())
	{
		if (ITarget.IsParty())
		{
			void *Party = (void*)CParty::FindParty(ITarget.GetPartyID());

			if (Party)
			{
				for (int i = CParty::GetPlayerList(Party); i; i = CBaseList::Pop((void*)i))
				{
					int Members = *(DWORD*)((void*)i);
					IChar IMembers((void*)*(DWORD*)((void*)i));

					if (CChar::IsNormal(Members) && IPlayer.IsValid())
					{
						if (CChar::GetRange((int)IPlayer.GetOffset() + 332, Members + 332) <= 300)
						{
							IMembers.Buff(48,1800,8*ISkill.GetGrade()+3);
							IPlayer._ShowBattleAnimation(IMembers,ISkill.GetIndex());
						}
					}
				}
			}
		} else {
			ITarget.Buff(48,1800,8*ISkill.GetGrade()+3);
			IPlayer._ShowBattleAnimation(ITarget,ISkill.GetIndex());
		}
	}
}