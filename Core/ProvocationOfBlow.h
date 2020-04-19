void __fastcall ProvocationOfBlow(IChar IPlayer, int pPacket, int pPos)
{
	int pSkill = IPlayer.GetSkillPointer(42);

	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int nSkillGrade = xSkill.GetGrade();
		int nTargetID = 0, nMana = 0; char bType = 0; void *pTarget = 0;
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

		if (bType == 0 && nTargetID)
			pTarget = CPlayer::FindPlayer(nTargetID);

		if (bType == 1 && nTargetID)
			pTarget = CMonster::FindMonster(nTargetID);

		if (bType >= 2)
			return;

		if (pTarget && nSkillGrade && IPlayer.IsValid())
		{
			if (nSkillGrade <= 1)
				nMana = 220;
			else if (nSkillGrade == 2)
				nMana = 242;
			else if (nSkillGrade == 3)
				nMana = 266;
			else if (nSkillGrade == 4)
				nMana = 292;
			else if (nSkillGrade >= 5)
				nMana = 320;

			if (IPlayer.IsOnline() && CPlayer::IsWState((int)IPlayer.GetOffset(), 12))
				return;

			if (IPlayer.GetCurMp() < nMana)
				return;

			if (pTarget == IPlayer.GetOffset())
				return;

			if (pTarget && IPlayer.IsOnline())
			{
				IChar Target(pTarget);

				if (!IPlayer.IsInRange(Target,300))
					return;

				int Around = IPlayer.GetObjectListAround(2);

				while(Around)
				{
					IChar Object((void*)*(DWORD*)Around);

					if (Object.IsValid() && IPlayer.IsValid() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
					{
						int nDmg = (IPlayer.GetAttack() * KPOBMul) + (nSkillGrade * CTools::Rate(KPOBMin,KPOBMax));

						if (Object.GetType() == 0)
							nDmg = nDmg * KPOBReduce / 100;

						IPlayer.OktayDamageArea(Object,nDmg,42);

						if (IPlayer.IsOnline() && IPlayer.IsValid() && Object.IsOnline() && Object.IsValid() && Object.GetType() == 1 && Object.GetCurHp() > 0 && Object.IsMobAggressive() && Object.IsMobHaveTarget())
							CMonsterReal::AddHostility(Object.GetOffset(),(int)IPlayer.GetOffset(),nDmg*3,0);
					}

					Around = CBaseList::Pop((void*)Around);
				}

				IPlayer._ShowBattleAnimation(Target, 42);
				IPlayer.SetDirection(Target);
				IPlayer.DecreaseMana(nMana);
			}
		}
	}
}