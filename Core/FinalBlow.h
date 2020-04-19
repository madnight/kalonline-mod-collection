void __fastcall FinalBlow(IChar IPlayer, int pPacket, int pPos)
{
	int pSkill = IPlayer.GetSkillPointer(18);

	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int nSkillGrade = xSkill.GetGrade();
		int nTargetID = 0; char bType = 0; void *pTarget = 0; int nMana = 450;
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

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
				if (CChar::GetRange((int)IPlayer.GetOffset() + 332, (int)pTarget + 332) > 300)
					return;

				if (IPlayer.CheckHit(Target, 20) && (Target.GetCurHp() <= (Target.GetMaxHp() / 2)))
				{
					int nDmg = (IPlayer.GetAttack() * TFBMul) + (nSkillGrade * CTools::Rate(TFBMin,TFBMax));

					if(Target.GetType() == 0)
						nDmg = nDmg * TFBReduce / 100;

					IPlayer.OktayDamageSingle(Target,nDmg,18);
				} else {
					IPlayer._ShowBattleMiss(Target, 18);
				}

				IPlayer.SetDirection(Target);
				IPlayer._ShowBattleAnimation(Target, 18);
				IPlayer.DecreaseMana(nMana);
			}
		}
	}
}