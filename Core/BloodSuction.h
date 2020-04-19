void __fastcall BloodSuction(IChar IPlayer, int pPacket, int pPos)
{
	if (IPlayer.IsValid() && IPlayer.GetRage() >= 15000 && CChar::IsGState((int)IPlayer.GetOffset(),512))
	{
		int nTargetID = 0; char bType = 0; void *pTarget = 0;
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

		if (bType == 0 && nTargetID)
			pTarget = CPlayer::FindPlayer(nTargetID);

		if (bType == 1 && nTargetID)
			pTarget = CMonster::FindMonster(nTargetID);

		if (bType >= 2)
			return;

		if (pTarget && IPlayer.IsValid())
		{
			IChar ITarget(pTarget);

			if (ITarget.IsValid() && IPlayer.IsValid())
			{
				if (pTarget == IPlayer.GetOffset())
					return;

				if (!IPlayer.IsInRange(ITarget,300))
					return;

				int nDmg = (IPlayer.GetAttack() * EBSMul);

				if (ITarget.GetType() == 0)
					nDmg = (nDmg * EBSReduce) / 100;

				int realDamage = IPlayer.OktayDamageSingle(ITarget,nDmg,115);

				if (realDamage > 5)
					IPlayer.IncreaseHp(realDamage * 30 / 75);

				IPlayer.DecreaseRage(15000);
			}
		}
	}
}