void __fastcall SpeedUp(void *pSkill, void *edx, int pPlayer, void *pPacket, int pPos)
{
	IChar IPlayer((void*)pPlayer);
	ISkill ISkill(pSkill);
	int nTargetID = 0; char bType = 0; void *pTarget = 0;
	CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

	if (bType == 0 && nTargetID)
		pTarget = CPlayer::FindPlayer(nTargetID);
	else
		return;

	if (pTarget && IPlayer.IsValid())
	{
		if ((**(int (__thiscall ***)(DWORD, DWORD, DWORD))pSkill)((int)pSkill, pPlayer, (int)pTarget))
		{
			IChar ITarget(pTarget);

			if (ITarget.IsValid() && IPlayer.IsValid())
			{
				if (IPlayer.GetCurMp() < ISkill.DecreaseMana())
					return;
				else
					IPlayer.DecreaseMana(ISkill.DecreaseMana());

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
									IMembers.Buff(12, 600 * ISkill.GetGrade(), 15 * ISkill.GetGrade());
									CChar::WriteInSight(IPlayer.GetOffset(), 63, "bddbb", ISkill.GetIndex(), IPlayer.GetID(), IMembers.GetID(), 0, ISkill.GetGrade());
								}
							}
						}
					}
				} else {
					ITarget.Buff(12, 600 * ISkill.GetGrade(), 15 * ISkill.GetGrade());
					CChar::WriteInSight(IPlayer.GetOffset(), 63, "bddbb", ISkill.GetIndex(), IPlayer.GetID(), ITarget.GetID(), 0, ISkill.GetGrade());
				}
			}
		}
	}
}