void __fastcall Behead(IChar IPlayer, int pPacket, int pPos)
{
	if (IPlayer.IsValid())
	{
		int nTargetID = 0; char bType = 0; void *pTarget = 0;
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
		
		if (bType == 1 && nTargetID)
			pTarget = CMonster::FindMonster(nTargetID);
		
		if (pTarget)
		{
			IChar ITarget(pTarget);

			if (IPlayer.IsValid() && ITarget.IsOnline() && CChar::IsGState((int)ITarget.GetOffset(),1))
			{
				if (!IPlayer.IsInRange(ITarget,300))
					return;

				IPlayer.IncreaseHp(CChar::GetMaxHp((int)IPlayer.GetOffset()) / 10);
				IPlayer.IncreaseMana(CChar::GetMaxMp((int)IPlayer.GetOffset()) / 10);
				CChar::WriteInSight(IPlayer.GetOffset(), 63, "bddbb", 1, IPlayer.GetID(), ITarget.GetID(), 0, 1);
				CChar::WriteInSight(pTarget, 61, "db", ITarget.GetID(), 10);
				CBaseDelete(ITarget.GetOffset(),0);
			}
		}
	}
}