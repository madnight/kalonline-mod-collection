int __fastcall GetFinalDamage(void *Target, void *edx, int Player, int Damage, int Argument)
{
	IChar IPlayer((void*)Player);
	IChar ITarget(Target);
	int CheckDamage = CChar::GetFinalDamage(Target,Player,Damage,Argument);

	if (IPlayer.IsValid() && IPlayer.GetType() == 0)
		IPlayer.Buff(313,3,0);

	if (ITarget.IsValid() && ITarget.GetType() == 0)
		ITarget.Buff(313,3,0);

	if (IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && ITarget.GetType() == 0)
	{
		if((IPlayer.GetLevel() >= ITarget.GetLevel() + 10) && CChar::IsGState((int)IPlayer.Offset, 256))
		{
			IPlayer.SystemMessage("You are not allowed to assasinate a player who is 10 levels lower than you.", TEXTCOLOR_RED);
			return 0;
		}

		if((IPlayer.GetLevel() + 10 <= ITarget.GetLevel()) && CChar::IsGState((int)ITarget.Offset, 256))
		{
			IPlayer.SystemMessage("You are not allowed to hit assassin who is 10 levels higher than you.", TEXTCOLOR_RED);
			return 0;
		}
	}

	if (IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && CheckDamage >= 1000)
	{
		if (IPlayer.GetLevel() < ITarget.GetLevel())
		{
			int GetLD = ITarget.GetLevel() - IPlayer.GetLevel();

			if (GetLD >= 10)
				CheckDamage = CheckDamage / 2;
			else
				CheckDamage = (CheckDamage * (100 - (5 * GetLD))) / 100;
		}
	}

	if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && IPlayer.IsBuff(356))
		return 0;

	if (Scenario::Active == true && IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && IPlayer.IsBuff(162) && ITarget.IsBuff(162))
		return 0;

	if (Scenario::Active == true && IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && IPlayer.IsBuff(163) && ITarget.IsBuff(163))
		return 0;

	if (Protect32::Active == true && IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && IPlayer.IsBuff(170) && ITarget.IsBuff(170))
		return 0;

	if (Protect32::Active == true && IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && IPlayer.IsBuff(171) && ITarget.IsBuff(171))
		return 0;

	if (Scenario::Active == true && ITarget.IsValid() && ITarget.GetType() == 1 && CheckDamage)
	{
		if ((ITarget.GetMobIndex() == 352 || ITarget.GetMobIndex() == 354) && IPlayer.IsBuff(162))
			return 0;

		if ((ITarget.GetMobIndex() == 356 || ITarget.GetMobIndex() == 358) && IPlayer.IsBuff(163))
			return 0;
	}

	if (Scenario::Active == true && ITarget.IsValid() && ITarget.GetType() == 1 && CheckDamage)
	{
		if (ITarget.GetMobIndex() == 360 && IPlayer.IsBuff(162) && Scenario::RedTeamSeal == 0)
		{
			IPlayer.SystemMessage("White Tiger seal should be broken to attack Giant Tower.",TEXTCOLOR_RED);
			return 0;
		}

		if (ITarget.GetMobIndex() == 360 && IPlayer.IsBuff(163) && Scenario::BlueTeamSeal == 0)
		{
			IPlayer.SystemMessage("Blue Dragon seal should be broken to attack Giant Tower.",TEXTCOLOR_RED);
			return 0;
		}
	}

	if (Scenario::Active == true && ITarget.IsValid() && ITarget.GetType() == 1 && CheckDamage )
	{
		if (ITarget.GetMobIndex() == 360 && CheckDamage >= ITarget.GetCurHp() && IPlayer.IsBuff(162))
		{
			Scenario::RedScore += 10;
			Scenario::RedTeamTowerCount += 1;
			Scenario::Time = 0;
		}

		if (ITarget.GetMobIndex() == 360 && CheckDamage >= ITarget.GetCurHp() && IPlayer.IsBuff(163))
		{
			Scenario::BlueScore += 10;
			Scenario::BlueTeamTowerCount += 1;
			Scenario::Time = 0;
		}
	}

	if (IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && IPlayer.IsBuff(160) && ITarget.IsBuff(160))
		return 0;

	if (IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && IPlayer.IsBuff(161) && ITarget.IsBuff(161))
		return 0;

	if (ITarget.IsValid() && ITarget.GetType() == 1 && CheckDamage)
	{
		if (ITarget.GetMobIndex() == 445 && IPlayer.IsBuff(161))
			return 0;

		if (ITarget.GetMobIndex() == 448 && IPlayer.IsBuff(160))
			return 0;
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0 && CheckDamage)
	{
		if(CheckDamage > ITarget.GetCurHp() && (IPlayer.IsBuff(160) || IPlayer.IsBuff(161)))
		{
			CheckHonor[ITarget.GetPID()].HDx += 1;
			CheckHonor[IPlayer.GetPID()].HKx += 1;
			CheckHonor[IPlayer.GetPID()].RPx += 1;
			CheckHonor[IPlayer.GetPID()].HPx += 1;
		}
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0 && CheckDamage)
	{
		if(CheckDamage > ITarget.GetCurHp() && (IPlayer.IsBuff(162) || IPlayer.IsBuff(163)) )
		{
			CheckHonor[ITarget.GetPID()].HDx += 1;
			CheckHonor[IPlayer.GetPID()].HKx += 1;
			CheckHonor[IPlayer.GetPID()].RPx += 1;
			CheckHonor[IPlayer.GetPID()].HPx += 1;
		}
	}

	if (IPlayer.IsValid() && IPlayer.GetType() == 0 && CSMap::IsOnTile(*(void **)((int)IPlayer.Offset + 320), (int)IPlayer.Offset + 332, 131072) && !CChar::IsGState((int)IPlayer.GetOffset(),128))
		return 0;

	if (ITarget.IsValid() && ITarget.GetType() == 0 && CSMap::IsOnTile(*(void **)((int)ITarget.Offset + 320), (int)ITarget.Offset + 332, 131072) && !CChar::IsGState((int)ITarget.GetOffset(),128))
		return 0;

	if (ITarget.IsValid() && ITarget.GetType() == 1)
	{
		if (ITarget.IsBuff(159))
			return 0;
	}

	if (IPlayer.IsValid() && IPlayer.GetType() == 1)
	{
		if (IPlayer.IsBuff(159))
			return 0;
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0)
	{
		if (ITarget.IsBuff(159) || (ITarget.IsBuff(327) && !ITarget.IsBuff(11) && !ITarget.IsBuff(339) && !ITarget.IsBuff(348) && !ITarget.IsBuff(350)) || (ITarget.IsBuff(329) && !ITarget.IsBuff(11) && !ITarget.IsBuff(339) && !ITarget.IsBuff(348) && !ITarget.IsBuff(350)))
			return 0;
	}

	if (IPlayer.IsValid() && IPlayer.GetType() == 0)
	{
		if (IPlayer.IsBuff(159) || (IPlayer.IsBuff(327) && !IPlayer.IsBuff(352) && !IPlayer.IsBuff(353) && !IPlayer.IsBuff(341)) || (IPlayer.IsBuff(329) && !IPlayer.IsBuff(341) && !IPlayer.IsBuff(352) && !IPlayer.IsBuff(348) && !IPlayer.IsBuff(353)))
			return 0;
	}

	if (IPlayer.IsValid() && IPlayer.GetType() == 0 && CheckDamage <= 0 && IPlayer.GetClass() == 1)
	{
		if (IPlayer.IsBuff(306) && MageMICheck.find(IPlayer.GetPID())->second != 24 && MageMICheck.find(IPlayer.GetPID())->second != 43 && MageMICheck.find(IPlayer.GetPID())->second != 44 && MageMICheck.find(IPlayer.GetPID())->second != 45 && MageMICheck.find(IPlayer.GetPID())->second != 48 && MageMICheck.find(IPlayer.GetPID())->second != 73 && MageMICheck.find(IPlayer.GetPID())->second != 74 && MageMICheck.find(IPlayer.GetPID())->second != 75)
		{
			int pSkill = IPlayer.GetSkillPointer(64);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int nDmg = (IPlayer.GetMagic() * MMIMul) + (xSkill.GetGrade() * CTools::Rate(MMIMin,MMIMax));

				if(ITarget.GetType() == 0)
					nDmg = nDmg * MMIReduce / 100;

				CheckDamage = nDmg;
			}
		}
	}

	if (IPlayer.IsValid() && IPlayer.GetType() == 0 && IPlayer.GetType() == 0 && CheckDamage && IPlayer.GetClass() == 1)
	{
		if (IPlayer.IsBuff(306) && MageMICheck.find(IPlayer.GetPID())->second != 24 && MageMICheck.find(IPlayer.GetPID())->second != 43 && MageMICheck.find(IPlayer.GetPID())->second != 44 && MageMICheck.find(IPlayer.GetPID())->second != 45 && MageMICheck.find(IPlayer.GetPID())->second != 48 && MageMICheck.find(IPlayer.GetPID())->second != 73 && MageMICheck.find(IPlayer.GetPID())->second != 74 && MageMICheck.find(IPlayer.GetPID())->second != 75)
		{
			int pSkill = IPlayer.GetSkillPointer(64);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int nDmg = (IPlayer.GetMagic() * MMIMul) + (xSkill.GetGrade() * CTools::Rate(MMIMin,MMIMax));

				if(ITarget.GetType() == 0)
					nDmg = nDmg * MMIReduce / 100;

				CheckDamage += nDmg;
			}
		}
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0)
	{
		if (ITarget.IsBuff(284) && CheckDamage > 10)
			CheckDamage = CheckDamage / 10;
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0)
	{
		if (ITarget.IsBuff(283) && CheckDamage > 10)
			CheckDamage = ((CheckDamage * 7) / 10);
	}

	if (ITarget.IsValid() && CheckDamage > 100 && ITarget.IsBuff(342))
		CheckDamage += (CheckDamage / 20);

	if (ITarget.IsValid() && ITarget.GetType() == 0)
	{
		if (ITarget.IsBuff(122) && CheckDamage)
			CheckDamage = ((CheckDamage * 88) / 100);
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0)
	{
		if (*(DWORD*)((int)ITarget.GetOffset() + 292) & 2147483648)
			return 0;
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0 && ITarget.GetClass() == 0 && CheckDamage > 0 && ITarget.GetSpecialty() == 23)
	{
		int DefendChance = 135;

		if (ITarget.GetLevel() < 100)
			DefendChance = (((ITarget.GetLevel() - 69) * 7) / 2) + 25;

		if ((int)CTools::Rate(1, 1000) <= DefendChance)
		{
			ITarget.SystemMessage("[Weapon Defend] You blocked enemy's attack.",TEXTCOLOR_RED);
			ITarget._ShowBattleAnimation(ITarget, 37);
			return 0;
		}
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0 && ITarget.GetClass() == 0)
	{
		if ((ITarget.GetSpecialty() == 43 || ITarget.GetSpecialty() == 11) && CheckDamage >= 100 && ITarget.GetLevel() >= 50)
		{
			int pSkill = ITarget.GetSkillPointer(44);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int DevineSuction = xSkill.GetGrade();

				if (CTools::Rate(1,1000) >= (1000 - (DevineSuction * 60)))
				{
					int RealDamage = CheckDamage;
					CheckDamage = ((CheckDamage * (100 - (DevineSuction * 6))) / 100);
					int AbsorbedDamage = RealDamage - CheckDamage;
					std::string msg = "[Devine Suction] You absorbed " + Int2String(AbsorbedDamage) + " damage from enemy's attack.";
					ITarget.SystemMessage(msg,TEXTCOLOR_RED);
				}
			}
		}
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0 && ITarget.GetClass() == 3)
	{
		if (ITarget.GetSpecialty() >= 3 && CheckDamage >= 100)
		{
			int pSkill = ITarget.GetSkillPointer(25);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int AcroGrade = xSkill.GetGrade();

				if ((int)CTools::Rate(1, 100) <= ((AcroGrade * 2) + 3))
				{
					CheckDamage = CheckDamage * 9 / 10;
					ITarget.SystemMessage("[Acrobatic] Damage reduces by %10.",TEXTCOLOR_RED);
				}
			}
		}

		if (ITarget.GetSpecialty() == 43 && CheckDamage >= 100)
		{
			int pSkill = ITarget.GetSkillPointer(26);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int AcroGrade = xSkill.GetGrade();

				if ((int)CTools::Rate(1, 100) <= 7)
				{
					CheckDamage = CheckDamage * 3 / 4;
					ITarget.SystemMessage("[High Grade Acrobatic] Damage reduces by %25.",TEXTCOLOR_RED);
				}
			}
		}
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0 && ITarget.GetClass() == 1 && CheckDamage >= 100)
	{
		int pSkill = ITarget.GetSkillPointer(76);

		if (pSkill && ITarget.IsBuff(309))
		{
			if (!CheckFarContinueSkill.find(ITarget.GetPID())->second.PlayerSkillID)
			{
				ISkill xSkill((void*)pSkill);
				CheckFarContinueSkill[ITarget.GetPID()].PlayerTarget = IPlayer.GetOffset();
				CheckFarContinueSkill[ITarget.GetPID()].PlayerSkillID = 76;
				CheckFarContinueSkill[ITarget.GetPID()].PlayerSkillCount = xSkill.GetGrade();
				CheckFarContinueSkill[ITarget.GetPID()].PlayerDamage = CheckDamage;
				CheckFarContinueSkill[ITarget.GetPID()].PlayerSkillDelay = 0;
			}
		}
	}

	if (ITarget.IsValid() && ITarget.GetType() == 0 && ITarget.GetClass() == 3 && CheckDamage)
	{
		if (ITarget.IsBuff(337))
		{
			int pSkill = ITarget.GetSkillPointer(63);

			if (pSkill && ITarget.IsValid() && IPlayer.IsValid() && GetTickCount() >= CODelay.find(ITarget.GetPID())->second && CTools::Rate(1, 1000) >= 650)
			{
				ISkill xSkill((void*)pSkill);
				int nSkillGrade = xSkill.GetGrade();
				int Around = IPlayer.GetObjectListAround(3);
				int nDmg = CheckDamage + (nSkillGrade * CTools::Rate(TCOMin,TCOMax));

				while(Around)
				{
					IChar Object((void*)*(DWORD*)Around);

					if(Object.IsValid() && ITarget.IsValid() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)ITarget.GetOffset() + 176))((int)ITarget.GetOffset(), (int)Object.GetOffset(), 0))
					{
						if (Object.GetType() == 0)
							nDmg = (nDmg * TCOReduce) / 100;

						ITarget.OktayDamageNoAgro(Object, nDmg, 63);
					}

					Around = CBaseList::Pop((void*)Around);
				}

				CODelay[ITarget.GetPID()] = GetTickCount() + 1500;
				ITarget._ShowBattleAnimation(IPlayer, 63);
			}
		}

		if (ITarget.IsBuff(335))
		{
			int pSkill = ITarget.GetSkillPointer(20);

			if (pSkill && ITarget.IsValid() && IPlayer.IsValid() && CTools::Rate(1, 1000) >= 650)
			{
				if (IPlayer.GetCurHp() > 1)
				{
					ISkill xSkill((void*)pSkill);
					int nSkillGrade = xSkill.GetGrade();
					int nDmg = CheckDamage + (nSkillGrade * CTools::Rate(TCAMin,TCAMax));

					if (IPlayer.GetType() == 0)
						nDmg = (nDmg * TCAReduce) / 100;

					ITarget.OktayDamageNoAgro(IPlayer, nDmg, 20);
					ITarget._ShowBattleAnimation(IPlayer, 20);
				}
			}
		}
	}

	if (DuelTournament::Active == true && IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && IPlayer.IsBuff(373) && ITarget.IsBuff(374))
		DuelTournament::RedScore += CheckDamage;

	if (DuelTournament::Active == true && IPlayer.IsValid() && ITarget.IsValid() && CheckDamage && IPlayer.GetType() == 0 && IPlayer.IsBuff(374) && ITarget.GetType() == 0 && ITarget.IsBuff(373))
		DuelTournament::BlueScore += CheckDamage;

	if (IPlayer.IsValid() && ITarget.IsValid() && CheckDamage > ConfigPVPMaxDmg && IPlayer.GetType() == 0 && ITarget.GetType() == 0 && IPlayer.GetAdmin() == 0 && ITarget.GetAdmin() == 0)
		CheckDamage = ConfigPVPMaxDmg;

	if (IPlayer.IsValid() && IPlayer.GetAdmin() <= 3 && CheckDamage >= ConfigMaxDamage && IPlayer.GetType() == 0)
		return 0;

	if (IPlayer.IsValid() && IPlayer.GetAdmin() <= 3 && IPlayer.GetType() == 0)
	{
		if (IPlayer.GetMinMagAttack() >= ConfigMaxMagAtk || IPlayer.GetMinMagAttack() <= 0)
			return 0;
		
		if (IPlayer.GetMaxMagAttack() >= ConfigMaxMagAtk || IPlayer.GetMaxMagAttack() <= 0)
			return 0;
		
		if (IPlayer.GetMaxPhyAttack() >= ConfigMaxPhyAtk || IPlayer.GetMaxPhyAttack() <= 0)
			return 0;
		
		if (IPlayer.GetMinPhyAttack() >= ConfigMaxPhyAtk || IPlayer.GetMinPhyAttack() <= 0)
			return 0;
		
		return CheckDamage;
	} else {
		return CheckDamage;
	}
}