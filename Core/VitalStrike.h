void __fastcall VitalStrike(IChar IPlayer, int pPacket, int pPos)
{
	int pSkill = IPlayer.GetSkillPointer(16);

	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int nSkillGrade = xSkill.GetGrade();
		int nTargetID = 0; char bType = 0; void *pTarget = 0;
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
		int nMana = nSkillGrade * 30 + 35;

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

				if (IPlayer.CheckHit(Target, 10))
				{
					if (Target.GetCurHp() <= (Target.GetMaxHp() / 2))
					{
						Target.Buff(7, nSkillGrade * 2, 0);
						Target.Buff(344,nSkillGrade * 2,0);
						Target.Buff(345,nSkillGrade * 10,0);
						Target.SetBuffIcon(nSkillGrade * 2000, 0, 2016,211);
					}

					int nDmg = (IPlayer.GetAttack() * TVSMul) + (nSkillGrade * CTools::Rate(TVSMin,TVSMax));

					if (Target.GetType() == 0)
						nDmg = nDmg * TVSReduce / 100;

					IPlayer.OktayDamageSingle(Target,nDmg,16);
				} else {
					IPlayer._ShowBattleMiss(Target, 16);
				}

				IPlayer.SetDirection(Target);
				IPlayer.DecreaseMana(nMana);
			}
		}
	}
}