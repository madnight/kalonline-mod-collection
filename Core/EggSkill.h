void __fastcall ExecuteTransformSkill(void *pSkill, void* edx, signed int SkillID, int pPacket, int pPos)
{
	ISkill Skill(pSkill);
	IChar IPlayer(Skill.GetPlayer());
	DWORD CdTime = 0, CooldownCheck = 0, DelayTime = 0;

	if (CheckEggCooldownConfig.count(SkillID))
	{
		CdTime = CheckEggCooldownConfig.find(SkillID)->second.EggCooldownConfig;
		DelayTime = CheckEggCooldownConfig.find(SkillID)->second.EggDelayConfig;
	}

	if (IPlayer.IsValid() && CChar::IsGState((int)IPlayer.GetOffset(),512))
	{
		if (EggCooldownTable.count(IPlayer.GetPID()+4000000000+(SkillID*1000000)))
			CooldownCheck = EggCooldownTable.find(IPlayer.GetPID()+4000000000+(SkillID*1000000))->second;

		int nTargetID = 0; char bType = 0;
		CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
		void* pTarget = 0;

		if (bType == 0 && nTargetID)
			pTarget = CPlayer::FindPlayer(nTargetID);
		
		if (bType == 1 && nTargetID)
			pTarget = CMonster::FindMonster(nTargetID);

		IChar Target(pTarget);

		if (SkillID == 110 && IPlayer.IsBuff(327))
		{
			IPlayer.CancelBuff(327);
			return;
		}

		if (CooldownCheck > GetTickCount())
		{
			IPlayer.SystemMessage("Invalid egg skill time detected!", TEXTCOLOR_RED);
			return;
		} else {
			EggCooldownTable[IPlayer.GetPID()+4000000000+(SkillID*1000000)] = GetTickCount()+CdTime+DelayTime;
		}

		if (IPlayer.IsBuff(327))
			IPlayer.CancelBuff(327);

		if (CheckContinueSkill.count(IPlayer.GetPID()) && CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillID)
			ResetContinueSkill(IPlayer);

		if (IPlayer.GetTransformGrade() == 1 && Target.IsValid())
		{
			if (SkillID == 104)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 2 && Target.IsValid())
		{
			if (SkillID == 104 || SkillID == 105)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 3)
		{
			if ((SkillID == 104 || SkillID == 105) && Target.IsValid())
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else if(SkillID == 106)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 97 && Target.IsValid())
		{
			if (SkillID == 101)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 98)
		{
			if (SkillID == 101 && Target.IsValid())
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else if (SkillID == 102)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 99)
		{
			if (SkillID == 101 && Target.IsValid())
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else if (SkillID == 102)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else if (SkillID == 103)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 65 && Target.IsValid())
		{
			if (SkillID == 107)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 66)
		{
			if (SkillID == 107 && Target.IsValid())
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else if (SkillID == 108)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 67)
		{
			if (SkillID == 107 && Target.IsValid())
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else if (SkillID == 108)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else if (SkillID == 109)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 4)
		{
			if ((SkillID == 104 || SkillID == 105) && Target.IsValid())
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else if (SkillID == 106)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else if (SkillID == 113)
			{
				RevolveAttack(IPlayer);
				return;
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 68)
		{
			if (SkillID == 107 && Target.IsValid())
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else if (SkillID == 108)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else if (SkillID == 109)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else if (SkillID == 115)
			{
				BloodSuction(IPlayer,pPacket,pPos);
				return;
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 100)
		{
			if (SkillID == 101 && Target.IsValid())
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(Target, SkillID + 37);
			} else if (SkillID == 102)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else if (SkillID == 103)
			{
				SkillID -= 37;
				IPlayer._ShowBattleAnimation(IPlayer, SkillID + 37);
			} else if (SkillID == 116)
			{
				EggThunderbolt(IPlayer);
			} else {
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 129)
		{
			if (SkillID == 110)
			{
				HighClassHiding(IPlayer);
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 130)
		{
			if (SkillID == 110)
			{
				HighClassHiding(IPlayer);
				return;
			}

			if (SkillID == 111)
			{
				ZilPoong(IPlayer, pPacket, pPos);
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 131)
		{
			if (SkillID == 110)
			{
				HighClassHiding(IPlayer);
				return;
			}

			if (SkillID == 111)
			{
				ZilPoong(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 112)
			{
				ShinRhoe(IPlayer);
				return;
			}
		}

		if (IPlayer.GetTransformGrade() == 132)
		{
			if (SkillID == 110)
			{
				HighClassHiding(IPlayer);
				return;
			}

			if (SkillID == 111)
			{
				ZilPoong(IPlayer, pPacket, pPos);
				return;
			}

			if (SkillID == 112)
			{
				ShinRhoe(IPlayer);
				return;
			}

			if (SkillID == 114)
			{
				WhirlwindFeather(IPlayer);
				return;
			}
		}

		if (IPlayer.GetMap() != 21 && SkillID == 101 && IPlayer.GetTransformGrade() >= 97 && IPlayer.GetTransformGrade() <= 100)
			ActivateShiny(IPlayer, pPacket, pPos);

		CSkill::ExecuteTransformSkill(pSkill, SkillID, pPacket, pPos);
	}
}