void __fastcall RefiningWeapon(void *pSkill, void *edx, int pPlayer, void *pPacket, int pPos)
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
									CChar::CancelAllBuff((void*)Members, 36);
									int AddBuff = CBuff::CreateBuff(36, 1800,  8 * *(DWORD*)((int)pSkill + 8) + 16, (int)pSkill);
									(*(int (__thiscall **)(int, int))(*(DWORD*)Members + 180))(Members, AddBuff);
									IPlayer._ShowBattleAnimation(IMembers,ISkill.GetIndex());
								}
							}
						}
					}
				} else {
					CChar::CancelAllBuff(ITarget.GetOffset(), 36);
					int AddBuff = CBuff::CreateBuff(36, 1800,  8 * *(DWORD*)((int)pSkill + 8) + 16, (int)pSkill);
					(*(int (__thiscall **)(int, int))(*(DWORD*)(int)ITarget.GetOffset() + 180))((int)ITarget.GetOffset(), AddBuff);
					IPlayer._ShowBattleAnimation(ITarget,ISkill.GetIndex());
				}
			}
		}
	}
}