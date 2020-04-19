void __fastcall ExecuteSkill(void *pSkill, void* edx, signed int SkillID, int pPacket, int pPos)
{
	if (SkillID > 100)
		return;

	if (SkillID == 88) SkillID = 95;
	ISkill Skill(pSkill);
	IChar IPlayer(Skill.GetPlayer());
	int SkillPointerCheck = IPlayer.GetSkillPointer(SkillID);
	DWORD CdTime = 0, CooldownCheck = 0, DelayTime = 0;
	IPlayer.Buff(313,3,0);

	if (IPlayer.IsValid() && IPlayer.IsBuff(349))
	{
		IPlayer.DisableRiding();
		return;
	}

	if (!SkillPointerCheck)
		return;

	if (CheckCooldownConfig.count(SkillID + (IPlayer.GetClass() * 100)))
	{
		CdTime = CheckCooldownConfig.find(SkillID + (IPlayer.GetClass() * 100))->second.CooldownConfig;
		DelayTime = CheckCooldownConfig.find(SkillID + (IPlayer.GetClass() * 100))->second.DelayConfig;
	}

	if (IPlayer.IsValid() && !CChar::IsGState((int)IPlayer.GetOffset(),512))
	{
		if(IPlayer.GetClass() == 1 && IPlayer.GetMap() == 21 && (SkillID == 43	|| SkillID == 45 || SkillID == 48))
			return;

		if (SkillID == 0 && IPlayer.IsBuff(385))
			return;

		if (SkillID == 6 && IPlayer.IsBuff(329))
		{
			IPlayer.CancelBuff(329);
			IPlayer.CancelBuff(40);
			return;
		}

		if (CooldownTable.count(IPlayer.GetPID()+4000000000+(SkillID*1000000)))
			CooldownCheck = CooldownTable.find(IPlayer.GetPID()+4000000000+(SkillID*1000000))->second;

		if (CooldownCheck > GetTickCount())
		{
			IPlayer.SystemMessage("Invalid skill time detected!", TEXTCOLOR_RED);
			return;
		} else {
			CooldownTable[IPlayer.GetPID()+4000000000+(SkillID*1000000)] = GetTickCount()+CdTime+DelayTime;
		}

		if (IPlayer.GetClass() == 1 && IPlayer.GetSpecialty() == 23)
			MageMICheck[IPlayer.GetPID()] = SkillID;

		if (SkillID != 0 && IPlayer.IsBuff(329))
		{
			IPlayer.CancelBuff(329);
			IPlayer.CancelBuff(40);

			if (SkillID != 7 && SkillID != 8 && SkillID != 10 && SkillID != 33)
				return;
		}

		if (CheckContinueSkill.count(IPlayer.GetPID()) && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID)
			ResetContinueSkill(IPlayer);

		if (IPlayer.GetClass() == 0 && SkillID == 38 && IPlayer.GetSpecialty() == 23)
		{
			SpinSlash(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 0 && SkillID == 40 && IPlayer.GetSpecialty() == 43)
		{
			PerfectDefense(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 0 && SkillID == 41 && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43))
		{
			PowerfulWideningWound(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 0 && SkillID == 42 && IPlayer.GetSpecialty() == 43)
		{
			ProvocationOfBlow(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 0 && SkillID == 43 && IPlayer.GetSpecialty() == 23)
		{
			SwordDance(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 0 && IPlayer.GetLevel() >= 81 && SkillID == 90 && IPlayer.GetSpecialty() == 23)
		{
			ShoutOfDefense(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 0 && IPlayer.GetLevel() >= 81 && SkillID == 91 && IPlayer.GetSpecialty() == 43)
		{
			TheBoomOfEarth(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 0 && IPlayer.GetLevel() >= 81 && SkillID == 92 && IPlayer.GetSpecialty() == 23)
		{
			ShoutOfFightingSpirit(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 0 && IPlayer.GetLevel() >= 81 && SkillID == 93 && IPlayer.GetSpecialty() == 43)
		{
			TheWaveOfEarth(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 2 && IPlayer.GetLevel() >= 81 && SkillID == 90 && IPlayer.GetSpecialty() == 23)
		{
			OneHitStrike(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 2 && IPlayer.GetLevel() >= 81 && SkillID == 92 && IPlayer.GetSpecialty() == 23)
		{
			ArrowsOfTheMaster(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 2 && IPlayer.GetLevel() >= 81 && SkillID == 91 && IPlayer.GetSpecialty() == 43)
		{
			MassiveFire(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 2 && IPlayer.GetLevel() >= 81 && SkillID == 93 && IPlayer.GetSpecialty() == 43)
		{
			SpiritOfTheArrows(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetLevel() >= 85 && SkillID == 95 && IPlayer.GetSpecialty() >= 23)
		{
			if (CChar::IsMState((int)IPlayer.GetOffset(),1))
				CChar::SubMState(IPlayer.GetOffset(),1,0);

			WalkOnTheAir(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 1 && IPlayer.IsBuff(287) && (SkillID == 17 || SkillID == 18 || SkillID == 19 || SkillID == 20 || SkillID == 21))
		{
			IPlayer.CouldntExecuteSkill();
			return;
		}

		if (IPlayer.GetClass() == 1 && IPlayer.GetLevel() >= 81 && SkillID == 90 && IPlayer.GetSpecialty() == 23)
		{
			Punishment(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 1 && IPlayer.GetLevel() >= 81 && SkillID == 91 && IPlayer.GetSpecialty() == 43)
		{
			Incapacitation(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 1 && IPlayer.GetLevel() >= 81 && SkillID == 92 && IPlayer.GetSpecialty() == 23)
		{
			ReleasingTheEnergy(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 1 && IPlayer.GetLevel() >= 81 && SkillID == 93 && IPlayer.GetSpecialty() == 43)
		{
			Bombing(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 40)
		{
			SoulDestruction((void*)SkillPointerCheck,IPlayer.GetOffset(),pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 59)
		{
			int pSkill = IPlayer.GetSkillPointer(59);

			if (IPlayer.IsValid() && pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int nTargetID = 0; char bType = 0; void *pTarget = 0;
				CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

				if (bType == 0 && nTargetID)
					pTarget = CPlayer::FindPlayer(nTargetID);
				else
					return;

				if (pTarget && IPlayer.IsValid())
				{
					IChar Target(pTarget);
					if (IPlayer.GetCurMp() < xSkill.DecreaseMana()) return;

					if (IPlayer.IsValid() && Target.IsValid())
					{
						if (!IPlayer.IsInRange(Target,300)) return;
						IPlayer.DecreaseMana(xSkill.DecreaseMana());
						Target.IncreaseHp(Target.GetMaxHp());
						IPlayer._ShowBattleAnimation(Target, 55);
					}
				}
			}

			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 63)
		{
			int pSkill = IPlayer.GetSkillPointer(63);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);

				if (IPlayer.IsBuff(286) || IPlayer.IsBuff(287))
					return;

				if (IPlayer.GetCurMp() >= 102)
				{
					IPlayer.DecreaseMana(102);
					IPlayer.Buff(286,900,0);
					IPlayer.Buff(287,905,0);
					IPlayer.AddDef(100);
					IPlayer.AddAbsorb(5);
					IPlayer.SetBuffIcon(900000,0,1414,147);
					IPlayer._ShowBattleAnimation(IPlayer, 63);
				}
			}

			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 64 && !IPlayer.IsBuff(305))
		{
			int pSkill = IPlayer.GetSkillPointer(64);
			int nMana = IPlayer.GetLevel() * 5;

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);

				if(IPlayer.GetCurMp() < nMana)
					return;

				if (IPlayer.IsBuff(305) || IPlayer.IsBuff(306))
					return;

				IPlayer.DecreaseMana(nMana);
				IPlayer.Buff(305,20+(xSkill.GetGrade()*5),0);
				IPlayer.Buff(306,25+(xSkill.GetGrade()*5),0);
				IPlayer.SetBuffIcon(20000 + (xSkill.GetGrade() * 5000), 0, 1794, 202);
				IPlayer._ShowBattleAnimation(IPlayer, 64);
			}

			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 65 && IPlayer.GetSpecialty() == 23)
		{
			FlameInjection(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 66 && IPlayer.GetSpecialty() == 23)
		{
			Icicle(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 67 && IPlayer.GetSpecialty() == 23)
		{
			LightningArrow(IPlayer,pPacket,pPos);
			return;
		}

		if(IPlayer.GetClass() == 1 && IPlayer.GetMap() != 21 && (SkillID == 4	|| SkillID == 9 || SkillID == 23 || SkillID == 31 || SkillID == 41 || SkillID == 42 || SkillID == 75))
			ActivateShiny(IPlayer, pPacket, pPos);

		if (IPlayer.GetClass() == 1 && SkillID == 69 && IPlayer.GetSpecialty() == 43)
		{
			Blessing(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 72 && IPlayer.GetSpecialty() == 43)
		{
			TherapeuticTouch(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 73 && IPlayer.GetSpecialty() == 23)
		{
			Fireball(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 74 && IPlayer.GetSpecialty() == 23)
		{
			IceArrow(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 75 && IPlayer.GetSpecialty() == 23)
		{
			Thunderbolt(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 1 && SkillID == 76 && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43) && !IPlayer.IsBuff(309))
		{
			int pSkill = IPlayer.GetSkillPointer(76);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int nMana = (xSkill.GetGrade() * 10) + 590;

				if(IPlayer.GetCurMp() < nMana)
					return;

				IPlayer.DecreaseMana(nMana);
				IPlayer.Buff(309,(15 + (xSkill.GetGrade() * 5)),0);
				IPlayer.Buff(310,(20 + (xSkill.GetGrade() * 5)),0);
				IPlayer.SetBuffIcon((15 + (xSkill.GetGrade() * 5)) * 1000,0,2356,298);
				IPlayer._ShowBattleAnimation(IPlayer,76);
			}

			return;
		}

		if (IPlayer.GetClass() == 2 && SkillID == 46 && IPlayer.GetSpecialty() == 23 && !IPlayer.IsBuff(289))
		{
			int pSkill = *((DWORD*)((int)IPlayer.GetOffset() + 624) + 46 + 2);
			IPlayer.SetBuffIcon(30000,0,2101,227);
			IPlayer.Buff(40,30,90);
			IPlayer.RemoveBuffIcon(0,0,798,54);
			IPlayer.Buff(288,30,0);
			IPlayer.Buff(289,60,0);

			if(IPlayer.GetCurMp() >= 50 && pSkill)
				IPlayer.DecreaseMana(50);
			else
				return;

			IPlayer._ShowBattleAnimation(IPlayer, 46);
			return;
		}

		if (IPlayer.GetClass() == 2 && SkillID == 47 && IPlayer.GetSpecialty() == 23)
		{
			ArrowRain(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 2 && SkillID == 49 && IPlayer.GetSpecialty() == 43)
		{
			ArrowExplosion(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 2 && SkillID == 50 && IPlayer.GetSpecialty() == 43)
		{
			VirulentArrow(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 2 && SkillID == 51 && IPlayer.GetSpecialty() == 23)
		{
			CombativeSpirit(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 1)
		{
			Behead(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 4 && SkillID == 1)
		{
			Behead(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 6)
		{
			Hiding(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 3 && IPlayer.GetLevel() >= 81 && SkillID == 90 && IPlayer.GetSpecialty() == 23)
		{
			CriticalStrike(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && IPlayer.GetLevel() >= 81 && SkillID == 92 && IPlayer.GetSpecialty() == 23)
		{
			CriticalDiffusion(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 3 && IPlayer.GetLevel() >= 81 && SkillID == 91 && IPlayer.GetSpecialty() == 43)
		{
			StrikeOfGod(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 3 && IPlayer.GetLevel() >= 81 && SkillID == 93 && IPlayer.GetSpecialty() == 43)
		{
			DestroyingArmor(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 33 && IPlayer.GetSpecialty() == 23)
		{
			WrathOfHeaven(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 36 && IPlayer.GetSpecialty() == 23)
		{
			SpinBlade(IPlayer);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 32 && IPlayer.GetSpecialty() == 43)
		{
			ShadowSlash(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 28 && IPlayer.GetSpecialty() == 43)
		{
			LightningSlash(IPlayer,pPacket,pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 19 && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43))
		{
			SpinAttack(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 22 && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43))
		{
			ArmorBreaker(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 23 && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43))
		{
			TwinBladeStrike(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 18 && (IPlayer.GetSpecialty() == 7 || IPlayer.GetSpecialty() == 23))
		{
			FinalBlow(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 21 && (IPlayer.GetSpecialty() == 7 || IPlayer.GetSpecialty() == 23))
		{
			SuicidalBlow(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 15 && (IPlayer.GetSpecialty() == 7 || IPlayer.GetSpecialty() == 23))
		{
			AnkleAmputate(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 16 && (IPlayer.GetSpecialty() == 7 || IPlayer.GetSpecialty() == 23))
		{
			VitalStrike(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 14 && (IPlayer.GetSpecialty() == 7 || IPlayer.GetSpecialty() == 23))
		{
			FatalWound(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 17 && (IPlayer.GetSpecialty() == 7 || IPlayer.GetSpecialty() == 23))
		{
			Rupture(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 7)
		{
			Assault(IPlayer, pPacket, pPos);
			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 13 && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43) && !IPlayer.IsBuff(333))
		{
			int pSkill = IPlayer.GetSkillPointer(13);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int nSkillGrade = xSkill.GetGrade();
				int nMana = nSkillGrade * 20 + 80;

				if (IPlayer.GetCurMp() >= nMana && nSkillGrade)
				{
					if (!IPlayer.IsBuff(333))
						IPlayer.SendGStateEx(IPlayer.GetGStateEx() + 1024);

					IPlayer.Buff(333, nSkillGrade * 15, 0);
					IPlayer.DecreaseMana(nMana);
					IPlayer._ShowBattleAnimation(IPlayer,13,nSkillGrade);
				}
			}

			return;
		}

		if (IPlayer.GetClass() == 3 && IPlayer.GetSpecialty() >= 3)
		{
			if (SkillID == 8)
			{
				Stun(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 9)
			{
				Confusion(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 10)
			{
				Strangle(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 12 && !IPlayer.IsBuff(354) && !IPlayer.IsBuff(355))
			{
				DualShadow(IPlayer, pPacket, pPos);
				return;
			}
		}

		if (IPlayer.GetClass() == 3 && SkillID == 20 && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43) && !IPlayer.IsBuff(335))
		{
			int pSkill = IPlayer.GetSkillPointer(20);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int nSkillGrade = xSkill.GetGrade();
				int nMana = nSkillGrade * 30 + 45;

				if(IPlayer.GetCurMp() >= nMana && nSkillGrade)
				{
					IPlayer.Buff(335, 30, 0);
					IPlayer.Buff(336, 35, 0);
					IPlayer.SetBuffIcon(30000, 0, 2019, 217);
					IPlayer.DecreaseMana(nMana);
					IPlayer._ShowBattleAnimation(IPlayer, 20);
					CChar::CancelAllBuff(IPlayer.GetOffset(), 337);
				}
			}

			return;
		}

		if (IPlayer.GetClass() == 3 && SkillID == 63 && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43) && !IPlayer.IsBuff(337))
		{
			int pSkill = IPlayer.GetSkillPointer(63);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int nSkillGrade = xSkill.GetGrade();
				int nMana = nSkillGrade * 30 + 50;

				if(IPlayer.GetCurMp() >= nMana && nSkillGrade)
				{
					IPlayer.Buff(337, 30, 0);
					IPlayer.Buff(338, 35, 0);
					IPlayer.SetBuffIcon(30000, 0, 2427, 323);
					IPlayer.DecreaseMana(nMana);
					IPlayer._ShowBattleAnimation(IPlayer, 63);
					CChar::CancelAllBuff(IPlayer.GetOffset(), 335);
				}
			}

			return;
		}

		if (IPlayer.GetClass() == 4 && IPlayer.GetSpecialty() >= 1)
		{
			if (SkillID == 13)
			{
				GhostKnife(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 14)
			{
				GhostFlash(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 15)
			{
				SoulShield(IPlayer, pPacket, pPos);
				return;
			}
		}

		if (IPlayer.GetClass() == 4 && IPlayer.GetSpecialty() >= 3)
		{
			if (SkillID == 18)
			{
				Wave(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 19)
			{
				GhostWindow(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 20)
			{
				MudRoom(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 21)
			{
				ExecutiveDirector(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 22)
			{
				TheSoulsPenance(IPlayer, pPacket, pPos);
				return;
			}
		}

		if (IPlayer.GetClass() == 4 && (IPlayer.GetSpecialty() == 7 || IPlayer.GetSpecialty() == 23))
		{
			if (SkillID == 25)
			{
				Entangling(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 26)
			{
				SpearOfPain(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 27)
			{
				int pSkill = IPlayer.GetSkillPointer(27);

				if (IPlayer.IsValid() && pSkill && !IPlayer.IsBuff(406))
				{
					ISkill xSkill((void*)pSkill);
					int nSkillGrade = xSkill.GetGrade();
					int nMana = (nSkillGrade * 2) + 300;

					if(IPlayer.IsValid() && IPlayer.GetCurMp() >= nMana && nSkillGrade)
					{
						IPlayer._ShowBattleAnimation(IPlayer, 27);
						IPlayer.DecreaseMana(nMana);
						IPlayer.SetBuffIcon(((nSkillGrade*60)+300)*1000,0,9103,1012);
						IPlayer.Buff(405,(nSkillGrade*60)+300,0);
						IPlayer.Buff(406,(nSkillGrade*100)+300,0);
					}
				}

				return;
			}

			if (SkillID == 28)
			{
				DrainBlood(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 29)
			{
				MentalBreakdown(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 54)
			{
				MagicalExplosion(IPlayer, pPacket, pPos);
				return;
			}
		}

		if (IPlayer.GetClass() == 4 && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43))
		{
			if (SkillID == 36)
			{
				JigukKing(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 37)
			{
				JeungjangKing(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 38)
			{
				AmplificationOfBlood(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 39)
			{
				WaveOfEmperor(IPlayer, pPacket, pPos);
				return;
			}
		}

		if (IPlayer.GetClass() == 4 && IPlayer.GetSpecialty() == 23)
		{
			if (SkillID == 44)
			{
				Collapse(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 45)
			{
				if (!IPlayer.IsBuff(406))
					return;

				int pSkill = IPlayer.GetSkillPointer(45);

				if (IPlayer.IsValid() && pSkill)
				{
					ISkill xSkill((void*)pSkill);
					int nSkillGrade = xSkill.GetGrade();
					int nMana = (nSkillGrade * 2) + 200;

					if(IPlayer.IsValid() && IPlayer.GetCurMp() >= nMana && nSkillGrade)
					{
						IPlayer._ShowBattleAnimation(IPlayer, 45);
						IPlayer.DecreaseMana(nMana);
						IPlayer.SetBuffIcon(-2,-1,9106,1015);
						IPlayer.Buff(412,1296000,15*nSkillGrade);
					}
				}

				return;
			}

			if (SkillID == 46)
			{
				SixSouls(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 47)
			{
				ExplodingSpirit(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 90)
			{
				SpiritWave(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 92)
			{
				Doggebi(IPlayer, pPacket, pPos);
				return;
			}
		}

		if (IPlayer.GetClass() == 4 && IPlayer.GetSpecialty() == 43)
		{
			if (SkillID == 50)
			{
				JigukKingOfTaein(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 51)
			{
				JeungjangKingOfTaein(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 52)
			{
				SoulBlow(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 91)
			{
				RisingKing4th(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 93)
			{
				Gangshin4th(IPlayer, pPacket, pPos);
				return;
			}
		}

		CSkill::ExecuteSkill(pSkill, SkillID, pPacket, pPos);
	}
}