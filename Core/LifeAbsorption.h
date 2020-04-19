void __fastcall SoulDestruction(void *pSkill, void *pPlayer, int pPacket, int pPos)
{
	ISkill ISkill(pSkill);
	int nSkillGrade = ISkill.GetGrade();

	if (!nSkillGrade)
		return;

	IChar IPlayer(pPlayer);
	int nTargetID = 0; char bType = 0; void *pTarget = 0;
	CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
	int nMana = ISkill.DecreaseMana();

	if (bType == 0 && nTargetID)
		pTarget = CPlayer::FindPlayer(nTargetID);

	if (bType == 1 && nTargetID)
		pTarget = CMonster::FindMonster(nTargetID);

	if (bType >= 2)
		return;

	IChar ITarget(pTarget);

	if (pTarget && ITarget.IsValid() && IPlayer.IsValid() && nTargetID != IPlayer.GetID())
	{
		if (IPlayer.GetCurMp() < nMana)
			return;

		if (!IPlayer.IsInRange(ITarget,300))
			return;

		IPlayer.SetDirection(ITarget);
		(*(void (__thiscall **)(int, int))(*(DWORD*)ITarget.GetOffset() + 80))((int)ITarget.GetOffset(), (int)IPlayer.GetOffset());
		int GetWisdom = CChar::GetWis((int)IPlayer.GetOffset());
		int nDmg = ((GetWisdom * ISkill.GetGrade() + CTools::Rate(MSDMin,MSDMax)) * IPlayer.GetMagic() / 500) * MSDMul;

		if (ITarget.GetType() == 0)
			nDmg = (nDmg * MSDReduce) / 100;

		IPlayer.OktayDamageSingle(ITarget,nDmg,40);
		IPlayer.DecreaseMana(nMana);
	}
}

void __fastcall LifeAbsorption(void *pSkill, void *edx, void *pPlayer, char *pPacket, char *pPos)
{
	ISkill ISkill(pSkill);
	int nSkillGrade = ISkill.GetGrade();

	if (!nSkillGrade)
		return;

	IChar IPlayer(pPlayer);
	int nTargetID = 0; char bType = 0; void *pTarget = 0;
	CPacket::Read(pPacket, pPos, "bd", &bType, &nTargetID);
	int nMana = ISkill.GetGrade() * 6 + 20;

	if (bType == 0 && nTargetID)
		pTarget = CPlayer::FindPlayer(nTargetID);

	if (bType == 1 && nTargetID)
		pTarget = CMonster::FindMonster(nTargetID);

	if (bType >= 2)
		return;

	IChar ITarget(pTarget);

	if (pTarget && ITarget.IsValid() && IPlayer.IsValid() && nTargetID != IPlayer.GetID())
	{
		if (IPlayer.GetCurMp() < nMana)
			return;

		if (!IPlayer.IsInRange(ITarget,300))
			return;

		(*(void (__thiscall **)(int, int))(*(DWORD*)ITarget.GetOffset() + 80))((int)ITarget.GetOffset(), (int)IPlayer.GetOffset());
		int nDmg = ((40 * ISkill.GetGrade() + 50) * CChar::GetAttack(IPlayer.GetOffset()) / 50) * ALAMul;

		if (ITarget.GetType() == 0)
			nDmg = (nDmg * ALAReduce) / 100;

		if (IPlayer.CheckHit(ITarget.GetOffset(), 50))
		{
			unsigned int GetAttackSpeed = CChar::GetASpeed((int)IPlayer.GetOffset());
			unsigned int GetASpeedValue = GetAttackSpeed;
			int NormalDamage = 0, DamageArgument = 0, EBDamage = 0, Check = 0, TypeKind = 0, GetType = 0;
			TypeKind = (*(int (__thiscall **)(LONG, void *))(*(DWORD *)ITarget.GetOffset() + 148))((int)ITarget.GetOffset(), IPlayer.GetOffset());
			Check = (*(int (__thiscall**)(LONG,void*,unsigned int,int*,int*,int*, DWORD))(*(DWORD*)ITarget.GetOffset() + 72))((int)ITarget.GetOffset(),IPlayer.GetOffset(),GetASpeedValue * nDmg / GetAttackSpeed,&NormalDamage,&DamageArgument,&EBDamage,0);
			GetType = Check | 2 * DamageArgument | 4 * TypeKind;

			if (NormalDamage > 0)
				IPlayer.IncreaseHp((NormalDamage * (10 * ISkill.GetGrade() + 20) / 75));

			CChar::WriteInSight(IPlayer.GetOffset(), 63, "bddbbwwb", ISkill.GetIndex(), IPlayer.GetID(), ITarget.GetID(), 1, 1, NormalDamage, 0, GetType);
		} else {
			IPlayer._ShowBattleMiss(ITarget, ISkill.GetIndex());
		}

		IPlayer.DecreaseMana(nMana);
	}
}