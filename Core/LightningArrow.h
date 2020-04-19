void __fastcall StormActivateShiny(IChar IPlayer, IChar Target)
{
	if (Target.IsValid() && IPlayer.IsValid() && CheckShiny.count((int)Target.GetOffset()))
	{
		if (CheckShiny.find((int)Target.GetOffset())->second.Delay >= GetTickCount())
			return;

		if (CheckShiny.find((int)Target.GetOffset())->second.Target && Target.IsBuff(307))
		{
			IChar Caster(CheckShiny.find((int)Target.GetOffset())->second.Target);
			CheckShiny[(int)Target.GetOffset()].Delay = GetTickCount() + 500;

			if (IPlayer.IsValid() && Caster.IsValid() && Target.IsValid())
			{
				if (!IPlayer.IsInRange(Target,300))
					return;

				if (!Caster.IsInRange(Target,300))
					return;

				int pSkill = Caster.GetSkillPointer(67);

				if (pSkill && Target.IsValid())
				{
					ISkill xSkill((void*)pSkill);
					int nSkillGrade = xSkill.GetGrade();
					int Around = Target.GetObjectListAround(3);

					while(Around)
					{
						IChar Object((void*)*(DWORD*)Around);

						if (Object.IsValid() && Caster.IsValid() && IPlayer.IsValid() && Target.IsValid() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)Caster.GetOffset() + 176))((int)Caster.GetOffset(), (int)Object.GetOffset(), 0))
						{
							if (Target.GetType() == 0 && CChar::IsGState((int)IPlayer.Offset, 128) && !CChar::IsGState((int)Object.Offset, 128)) {
							} else if (Target.GetType() == 0 && CChar::IsGState((int)Target.Offset, 256) && Object.GetID() != Target.GetID()) {
							} else {
								int nDmg = (IPlayer.GetMagic() * MLAMul) + (nSkillGrade * CTools::Rate(MLAMin,MLAMax));

								if (Object.GetType() == 0)
									nDmg = nDmg * MLAReduce / 100;

								Caster.OktayDamageArea(Object, nDmg, 67);

								if (Object.GetType() == 0 && Caster.GetID() != Object.GetID() && Object.GetID() != IPlayer.GetID())
									Object.AddFxToTarget("davi_ef129", 1, 0, 0);

								if (Object.GetType() == 1)
									Object.AddFxToTarget("davi_ef129", 1, 0, 0);
							}
						}

						Around = CBaseList::Pop((void*)Around);
					}
				}
			} else {
				if (Target.IsValid())
				{
					Target.CancelBuff(307);
					CheckShiny[(int)Target.GetOffset()].Target = 0;
				}
			}
		}
	}
}

void __fastcall ActivateShiny(IChar IPlayer, int pPacket, int pPos)
{
	int nTargetID = 0; char bType = 0; void *pTarget = 0;
	CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

	if (bType == 0 && nTargetID)
		pTarget = CPlayer::FindPlayer(nTargetID);

	if (bType == 1 && nTargetID)
		pTarget = CMonster::FindMonster(nTargetID);

	if (bType >= 2)
		return;

	IChar Target(pTarget);

	if (pTarget && IPlayer.IsValid() && Target.IsValid() && CheckShiny.count((int)Target.GetOffset()))
	{
		if (CheckShiny.find((int)Target.GetOffset())->second.Delay >= GetTickCount())
			return;

		if (CheckShiny.find((int)Target.GetOffset())->second.Target && Target.IsBuff(307))
		{
			IChar Caster(CheckShiny.find((int)Target.GetOffset())->second.Target);
			CheckShiny[(int)Target.GetOffset()].Delay = GetTickCount() + 500;

			if (IPlayer.IsValid() && Caster.IsValid() && Target.IsValid())
			{
				if (!IPlayer.IsInRange(Target,300))
					return;

				if (!Caster.IsInRange(Target,300))
					return;

				int pSkill = Caster.GetSkillPointer(67);

				if (pSkill && Target.IsValid())
				{
					ISkill xSkill((void*)pSkill);
					int nSkillGrade = xSkill.GetGrade();
					int Around = Target.GetObjectListAround(3);

					while(Around)
					{
						IChar Object((void*)*(DWORD*)Around);

						if (Object.IsValid() && Caster.IsValid() && IPlayer.IsValid() && Target.IsValid() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)Caster.GetOffset() + 176))((int)Caster.GetOffset(), (int)Object.GetOffset(), 0))
						{
							if (Target.GetType() == 0 && CChar::IsGState((int)IPlayer.Offset, 128) && !CChar::IsGState((int)Object.Offset, 128)) {
							} else if (Target.GetType() == 0 && CChar::IsGState((int)Target.Offset, 256) && Object.GetID() != Target.GetID()) {
							} else {
									int nDmg = (IPlayer.GetMagic() * MLAMul) + (nSkillGrade * CTools::Rate(MLAMin,MLAMax));

									if (Object.GetType() == 0)
										nDmg = nDmg * MLAReduce / 100;

									Caster.OktayDamageArea(Object, nDmg, 67);

									if (Object.GetType() == 0 && Caster.GetID() != Object.GetID() && Object.GetID() != IPlayer.GetID())
										Object.AddFxToTarget("davi_ef129", 1, 0, 0);

									if (Object.GetType() == 1)
										Object.AddFxToTarget("davi_ef129", 1, 0, 0);
							}
						}

						Around = CBaseList::Pop((void*)Around);
					}
				}
			} else {
				if (Target.IsValid())
				{
					Target.CancelBuff(307);
					CheckShiny[(int)Target.GetOffset()].Target = 0;
				}
			}
		}
	}
}

void __fastcall LightningArrow(IChar IPlayer, int pPacket, int pPos)
{
	int pSkill = IPlayer.GetSkillPointer(67);

	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int nTargetID = 0; char bType = 0; void *pTarget = 0;
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
		int nMana = IPlayer.GetLevel() * 4 + 120;

		if (bType == 0 && nTargetID)
			pTarget = CPlayer::FindPlayer(nTargetID);

		if (bType == 1 && nTargetID)
			pTarget = CMonster::FindMonster(nTargetID);

		if (bType >= 2)
			return;

		IChar Target(pTarget);

		if (pTarget && IPlayer.IsValid() && Target.IsValid())
		{
			if (pTarget == IPlayer.GetOffset())
				return;

			if (IPlayer.GetCurMp() < nMana)
				return;

			int nDmg = (IPlayer.GetMagic() * xSkill.GetGrade()) / 3;

			if (IPlayer.IsValid() && Target.IsValid())
			{
				if (!IPlayer.IsInRange(Target,300))
					return;

				if (Target.IsBuff(307))
					StormActivateShiny(IPlayer,Target);

				CheckShiny[(int)Target.GetOffset()].Target = IPlayer.GetOffset();
				IPlayer.SetDirection(Target);
				IPlayer.OktayDamageSingle(Target, nDmg, 67);
				Target.Buff(307,900,0);
				IPlayer.DecreaseMana(nMana);
			}
		}
	}
}

int __cdecl CMonsterMagicCreate(int Index, int Value, int Argument, int Arg, int Player, int Damage, int Time)
{
	int check = CMonsterMagic::Create(Index,Value,Argument,Arg,Player,Damage,Time);

	if (check)
	{
		IChar Object((void*)Player);

		if (Object.IsOnline() && Object.GetType() == 0 && Index == 228)
			CheckShiny[check].Target = (void*)Player;

		*(DWORD*)(check + 512) = Index;
	}

	return check;
}

int __fastcall MagicTick(void *Monster, void *edx)
{
	IChar IMonster(Monster);
	int result = CMonster::IsRemoved(Monster);

	if (IMonster.IsValid() && !result)
	{
		CChar::Lock(Monster);
		IChar IPlayer((void*)*(DWORD*)((int)Monster+484));

		if (*(DWORD*)((int)Monster + 468) < GetTickCount())
		{
			CChar::Unlock(Monster);
			return CSkill::MagicTick(Monster);
		}

		if (*(DWORD*)((int)Monster + 484))
		{
			if (CBase::IsDeleted(*(DWORD*)((int)Monster + 484)))
			{
				CChar::Unlock(Monster);
				return CSkill::MagicTick(Monster);
			}

			if (IPlayer.IsValid() && IMonster.IsValid())
			{
				if (IPlayer.GetType() == 0 && IPlayer.IsValid() && IMonster.IsValid())
				{
					if (IMonster.GetMobIndex() == 231)
					{
						int Around = IMonster.GetObjectListAround(4);

						while(Around)
						{
							IChar Object((void*)*(DWORD*)Around);

							if (Object.IsValid() && IPlayer.IsValid() && IMonster.IsValid() && IMonster.GetOffset() != Object.GetOffset() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
							{
								if (Object.GetType() == 0)
									IPlayer.OktayDamageStorm(Object,*(DWORD*)((int)Monster + 136));
								else
									IPlayer.OktayDamageStorm(Object,*(DWORD*)((int)Monster + 136) * 3);
							}

							Around = CBaseList::Pop((void*)Around);
						}
					} else {
						int Around = IMonster.GetObjectListAround(4);
						MageMICheck[IPlayer.GetPID()] = 43;

						while(Around)
						{
							IChar Object((void*)*(DWORD*)Around);

							if (Object.IsValid() && IPlayer.IsValid() && IMonster.IsValid() && IMonster.GetOffset() != Object.GetOffset() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
								IPlayer.OktayDamageStorm(Object,*(DWORD*)((int)Monster + 136));

							Around = CBaseList::Pop((void*)Around);
						}
					}

					if (IMonster.IsValid() && IMonster.GetMobIndex() == 228 && CheckShiny.count((int)IMonster.GetOffset()) && CheckShiny.find((int)IMonster.GetOffset())->second.Target)
					{
						IChar IPlayer(CheckShiny.find((int)IMonster.GetOffset())->second.Target);

						if (IPlayer.IsValid() && IMonster.IsValid())
						{
							int Around = IMonster.GetObjectListAround(3);

							while(Around)
							{
								IChar Object((void*)*(DWORD*)Around);

								if (IMonster.IsValid() && Object.IsValid() && IPlayer.IsValid() && IPlayer.GetOffset() != Object.GetOffset() && IMonster.GetOffset() != Object.GetOffset() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
								{
									if (Object.IsBuff(307))
										StormActivateShiny(IPlayer,Object);
								}

								Around = CBaseList::Pop((void*)Around);
							}
						}
					}
				} else {
					if (IPlayer.GetType() == 1 && IPlayer.IsValid() && IMonster.IsValid())
					{
						int Around = IPlayer.GetObjectListAround(4);

						while(Around)
						{
							IChar Object((void*)*(DWORD*)Around);

							if (IPlayer.IsValid() && IPlayer.GetOffset() != Object.GetOffset() && Object.GetType() == 0)
								IPlayer.OktayDamageStorm(Object,CTools::Rate(750,1000));

							Around = CBaseList::Pop((void*)Around);
						}
					}
				}
			}
		}

		result = CChar::Unlock(Monster);
	}

	return result;
}