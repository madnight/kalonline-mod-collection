void __fastcall ContinueSwordDance(IChar IPlayer)
{
	if (IPlayer.IsValid())
	{
		int nSkillGrade = CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillGrade;
		void *pTarget = CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerTarget;
		
		if (nSkillGrade && pTarget && IPlayer.IsValid())
		{
			if (CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
			{
				IChar Target(pTarget);

				if (IPlayer.IsValid() && Target.IsValid())
				{
					CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

					if (!IPlayer.IsValid())
					{
						ResetContinueSkill(IPlayer);
						return;
					}

					if (IPlayer.IsOnline() && !CPlayer::IsWState((int)IPlayer.GetOffset(), 12))
					{
						ResetContinueSkill(IPlayer);
						return;
					}

					if (IPlayer.IsOnline() && !IPlayer.IsInRange(Target, 2))
					{
						ResetContinueSkill(IPlayer);
						return;
					}

					if (IPlayer.CheckHit(Target, 30))
					{
						int nDmg = (IPlayer.GetAttack() * KSDMul) + (nSkillGrade * CTools::Rate(KSDMin,KSDMax));

						if(Target.GetType() == 0)
							nDmg = nDmg * KSDReduce / 100;

						IPlayer.OktayDamageSingle(Target,nDmg,43);

						if (IPlayer.IsOnline())
							CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 800;

						if (IPlayer.IsOnline() && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0)
							ResetContinueSkill(IPlayer);

						return;
					} else {
						if (IPlayer.IsOnline())
							CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 800;

						IPlayer._ShowBattleMiss(Target, 43);

						if (IPlayer.IsOnline() && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0)
							ResetContinueSkill(IPlayer);

						return;
					}
				}
			}
		}
	}

	ResetContinueSkill(IPlayer);
	return;
}

void __fastcall SwordDance(IChar IPlayer, int pPacket, int pPos)
{
	int pSkill = IPlayer.GetSkillPointer(43);

	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int nTargetID = 0, nMana = 0, nSkillGrade = 0; char bType = 0; void *pTarget = 0;
		nSkillGrade = xSkill.GetGrade();
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

		if (nSkillGrade <= 1)
			nMana = 245;
		else if (nSkillGrade == 2)
			nMana = 283;
		else if (nSkillGrade == 3)
			nMana = 325;
		else if (nSkillGrade == 4)
			nMana = 371;
		else if (nSkillGrade >= 5)
			nMana = 420;

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
				IPlayer.DecreaseMana(nMana);
				CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 43;
				CheckContinueSkill[IPlayer.GetPID()].PlayerTarget = Target.GetOffset();
				CheckContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = xSkill.GetGrade();
				CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = xSkill.GetGrade() + 1;
				CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
			}
		}
	}
}