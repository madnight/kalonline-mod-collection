void __fastcall MassiveFire(IChar IPlayer, int pPacket, int pPos)
{
	int pSkill = IPlayer.GetSkillPointer(91);

	if (pSkill && IPlayer.IsValid())
	{
		ISkill xSkill((void*)pSkill);
		int nSkillGrade = xSkill.GetGrade();
		int nTargetID = 0; char bType = 0; void *pTarget = 0;
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
		int nMana = (1.85 * (200 + (nSkillGrade * (20 + (nSkillGrade - 1)))));

		if (bType == 0 && nTargetID)
			pTarget = CPlayer::FindPlayer(nTargetID);

		if (bType == 1 && nTargetID)
			pTarget = CMonster::FindMonster(nTargetID);

		if (bType >= 2)
			return;

		if (pTarget && nSkillGrade && IPlayer.IsValid())
		{
			IChar Target(pTarget);

			if (IPlayer.GetCurMp() < nMana)
				return;

			if (pTarget == IPlayer.GetOffset())
				return;

			if (IPlayer.IsValid() && Target.IsValid())
			{
				if (!IPlayer.IsInRange(Target,300))
					return;

				int nDmg = (IPlayer.GetAttack() * NMFMul) + (nSkillGrade * CTools::Rate(NMFMin,NMFMax));

				if (Target.GetType() == 0)
					nDmg = (nDmg * NMFReduce) / 100;
				
				IPlayer.OktayDamageSingle(Target,nDmg,91);
				IPlayer.SetDirection(Target);
				IPlayer.DecreaseMana(nMana);
			}
		}
	}
}