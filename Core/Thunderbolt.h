void __fastcall ContinueThunderbolt(IChar IPlayer)
{
	if (IPlayer.IsValid())
	{
		void *pTarget = CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerTarget;
		IChar Target(pTarget);

		if (!Target.IsValid())
		{
			ResetContinueSkill(IPlayer);
			return;
		}

		if (CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount)
		{
			CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;

			if (!IPlayer.IsInRange(Target, 30))			
			{
				ResetContinueSkill(IPlayer);
				return;
			}

			if(!IPlayer.IsValid() || !Target.IsValid())
			{
				ResetContinueSkill(IPlayer);
				return;
			}

			int nDmg = (IPlayer.GetMagic() * MTBMul) + (CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillGrade * CTools::Rate(MTBMin,MTBMax));

			if (Target.GetType() == 0)
				nDmg = nDmg * MTBReduce / 100;

			IPlayer.OktayDamageSingle(Target,nDmg,75);
			IPlayer.SetDirection(Target);

			if (IPlayer.IsOnline())
				CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 200;

			if (IPlayer.IsOnline() && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount == 0)
				ResetContinueSkill(IPlayer);

			return;
		}
	}

	ResetContinueSkill(IPlayer);
	return;
}

void __fastcall Thunderbolt(IChar IPlayer, int pPacket, int pPos)
{
	int pSkill = IPlayer.GetSkillPointer(75);

	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int nTargetID = 0; char bType = 0; void* pTarget = 0;
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
		int nMana = (int)(((((xSkill.GetGrade()-1)+45) * xSkill.GetGrade())+280) * 0.75);

		if (bType == 0 && nTargetID)
			pTarget = CPlayer::FindPlayer(nTargetID);

		if (bType == 1 && nTargetID)
			pTarget = CMonster::FindMonster(nTargetID);

		if (bType >= 2)
			return;

		if (pTarget && xSkill.GetGrade() && IPlayer.IsValid())
		{
			IChar Target(pTarget);

			if (IPlayer.GetCurMp() < nMana)
				return;

			if (pTarget == IPlayer.GetOffset())
				return;

			if (IPlayer.IsValid() && Target.IsValid())
			{
				IPlayer.DecreaseMana(nMana);
				CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 75;
				CheckContinueSkill[IPlayer.GetPID()].PlayerTarget = Target.GetOffset();
				CheckContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = xSkill.GetGrade();
				CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 6;
				CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
			}
		}
	}
}