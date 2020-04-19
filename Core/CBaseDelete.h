void __fastcall CBaseDelete(void *Object, void *edx)
{
	IChar Check(Object);
	int Type = 2, IID = 0, PID = 0, Erase = (int)Object; std::string DeleteIP = "error";

	if (Check.IsOnline())
		Type = Check.GetType();

	if (Type == 0 && Check.IsOnline())
	{
		PID = Check.GetPID();

		if (LastManStand::Active == true && Check.IsBuff(378))
			LastManStand::RegisterAmount--;

		if (Protect32::Active == true && Protect32::Prayer == 1 && Check.GetGID() == Check.GetPID() && Check.GetGID() == Protect32::GuildFirst)
		{
			Protect32::Prayer = 0;
			Protect32::BluePrayerTime = 0;
		}

		if (Protect32::Active == true && Protect32::Prayer == 2 && Check.GetGID() == Check.GetPID() && Check.GetGID() == Protect32::GuildSecond)
		{
			Protect32::Prayer = 0;
			Protect32::RedPrayerTime = 0;
		}

		if (MiningLimit.count(Check.GetIP()) && MiningLimit.find(Check.GetIP())->second && Check.IsBuff(296))
			DeleteIP = Check.GetIP();

		if (ShopLimit.count(Check.GetIP()) && ShopLimit.find(Check.GetIP())->second && Check.IsBuff(297))
			DeleteIP = Check.GetIP();
	}

	if (Type == 1 && Check.IsOnline())
	{
		if (Check.IsValid() && Check.GetMobTanker())
		{
			IChar EAPlayer((void*)Check.GetMobTanker());

			if (Check.IsValid() && EAPlayer.IsOnline() && DailyQuest.count(Check.GetMobIndex()))
			{
				if (EAPlayer.IsParty())
				{
					void *Party = (void *)CParty::FindParty(EAPlayer.GetPartyID());

					for (int i = CParty::GetPlayerList(Party); i; i = CBaseList::Pop((void*)i))
					{
						IChar IMembers((void*)*(DWORD*)((void*)i));

						if (IMembers.IsOnline() && CChar::GetRange((int)IMembers.GetOffset() + 332, *(DWORD*)((void*)i) + 332) <= 300 && PlayerQuest.count((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID()) && PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.Active == 1)
						{
							PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID()].MobAmount = PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.MobAmount + 1;
							CPlayer::Write(IMembers.GetOffset(),255,"dddd",222,IMembers.GetPID(),DailyQuest.find(Check.GetMobIndex())->second.Quest,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.MobAmount);

							if (PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.MobAmount >= DailyQuest.find(Check.GetMobIndex())->second.MobAmount)
							{
								PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID()].Active = 0;
								PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID()].MobAmount = 0;
								PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID()].Repeat = PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.Repeat + 1;
								PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID()].Time = (int)time(0) + DailyQuest.find(Check.GetMobIndex())->second.Time;
								IMembers.DailyQuestUpdate(DailyQuest.find(Check.GetMobIndex())->second.Quest,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.Repeat,0,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.Time);
								IMembers.EndQuest(DailyQuest.find(Check.GetMobIndex())->second.Quest);
								CPlayer::Write(IMembers.GetOffset(),255,"dddd",222,IMembers.GetPID(),DailyQuest.find(Check.GetMobIndex())->second.Quest,0);
								(*(int (__cdecl **)(int, signed int, signed int, unsigned __int64, unsigned __int64))(*(DWORD *)IMembers.GetOffset() + 88))((int)IMembers.GetOffset(), 25, 1, (unsigned __int64)DailyQuest.find(Check.GetMobIndex())->second.Exp, HIDWORD(DailyQuest.find(Check.GetMobIndex())->second.Exp));

								if (DailyQuest.find(Check.GetMobIndex())->second.Item)
									CItem::InsertItem((int)IMembers.GetOffset(),27,DailyQuest.find(Check.GetMobIndex())->second.Item,0,DailyQuest.find(Check.GetMobIndex())->second.ItemAmount,-1);
							} else {
								IMembers.DailyQuestUpdate(DailyQuest.find(Check.GetMobIndex())->second.Quest,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.Repeat,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.MobAmount,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + IMembers.GetPID())->second.Time);
							}
						}
					}
				} else {
					if (EAPlayer.IsOnline() && PlayerQuest.count((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID()) && PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.Active == 1)
					{
						PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID()].MobAmount = PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.MobAmount + 1;
						CPlayer::Write(EAPlayer.GetOffset(),255,"dddd",222,EAPlayer.GetPID(),DailyQuest.find(Check.GetMobIndex())->second.Quest,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.MobAmount);

						if (PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.MobAmount >= DailyQuest.find(Check.GetMobIndex())->second.MobAmount)
						{
							PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID()].Active = 0;
							PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID()].MobAmount = 0;
							PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID()].Repeat = PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.Repeat + 1;
							PlayerQuest[(DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID()].Time = (int)time(0) + DailyQuest.find(Check.GetMobIndex())->second.Time;
							EAPlayer.DailyQuestUpdate(DailyQuest.find(Check.GetMobIndex())->second.Quest,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.Repeat,0,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.Time);
							EAPlayer.EndQuest(DailyQuest.find(Check.GetMobIndex())->second.Quest);
							CPlayer::Write(EAPlayer.GetOffset(),255,"dddd",222,EAPlayer.GetPID(),DailyQuest.find(Check.GetMobIndex())->second.Quest,0);
							(*(int (__cdecl **)(int, signed int, signed int, unsigned __int64, unsigned __int64))(*(DWORD *)EAPlayer.GetOffset() + 88))((int)EAPlayer.GetOffset(), 25, 1, (unsigned __int64)DailyQuest.find(Check.GetMobIndex())->second.Exp, HIDWORD(DailyQuest.find(Check.GetMobIndex())->second.Exp));

							if (DailyQuest.find(Check.GetMobIndex())->second.Item)
								CItem::InsertItem((int)EAPlayer.GetOffset(),27,DailyQuest.find(Check.GetMobIndex())->second.Item,0,DailyQuest.find(Check.GetMobIndex())->second.ItemAmount,-1);
						} else {
							EAPlayer.DailyQuestUpdate(DailyQuest.find(Check.GetMobIndex())->second.Quest,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.Repeat,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.MobAmount,PlayerQuest.find((DailyQuest.find(Check.GetMobIndex())->second.Quest * 1000000000000) + EAPlayer.GetPID())->second.Time);
						}
					}
				}
			}

			if (Check.IsValid() && EAPlayer.IsValid() && CheckContinueSkill.count(EAPlayer.GetPID()) && CheckContinueSkill.find(EAPlayer.GetPID())->second.PlayerSkillID == 49)
			{
				EAPlayer.CancelBuff(300);

				if (CheckContinueSkill.find(EAPlayer.GetPID())->second.PlayerTarget == Check.GetOffset())
				{
					if (EAPlayer.IsInRange(Check,300))
					{
						int Around = Check.GetObjectListAround(3);

						while(Around)
						{
							IChar Object((void*)*(DWORD*)Around);

							if (Object.IsValid() && EAPlayer.IsValid() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)EAPlayer.GetOffset() + 176))((int)EAPlayer.GetOffset(), (int)Object.GetOffset(), 0))
							{
								int nDmg = (EAPlayer.GetAttack() * AAEMul) + (CheckContinueSkill.find(EAPlayer.GetPID())->second.PlayerSkillGrade * CTools::Rate(AAEMin,AAEMax));

								if (Object.GetType() == 0)
									nDmg = (nDmg * AAEReduce) / 100;

								if (Object.GetOffset() != (void*)Erase)
									EAPlayer.OktayDamageArea(Object,nDmg,49);
							}

							Around = CBaseList::Pop((void*)Around);
						}
					}
				}

				ResetContinueSkill(EAPlayer);
			}
		}
	}

	if (Type == 3 && Check.IsOnline())
	{
		IItem xItem(Object);
		IID = xItem.GetIID();
	}

	CBase::Delete(Object);

	if (Type == 0 && PID && Erase && CBase::IsDeleted(Erase))
	{
		ShopLimit.erase(DeleteIP);
		MiningLimit.erase(DeleteIP);
		CheckEmok.erase(PID);
		CheckCurHonor.erase(PID);
		CheckHonor.erase(PID);
		BeadOfFire.erase(PID);
		MageMICheck.erase(PID);
		CheckBlob.erase(PID);
		PlayerPet.erase(PID);
		CheckShiny.erase(Erase);
		CheckContinueSkill.erase(PID);
		CheckFarContinueSkill.erase(PID);
		CheckRuptureContinueSkill.erase(PID);
		CODelay.erase(PID);
		CheckMining.erase(PID);
		TrigramGrade.erase(PID);
		TrigramHP.erase(PID);
		TrigramMP.erase(PID);
		TrigramAtk.erase(PID);
		TrigramStr.erase(PID);
		TrigramAgi.erase(PID);
		TrigramInt.erase(PID);
		TrigramWis.erase(PID);
		TrigramHth.erase(PID);
		Taegeuk.erase(PID);
		CheckHaninMirror.erase(PID);
		CheckEssense1.erase(PID);
		CheckEssense2.erase(PID);
		CheckEssense3.erase(PID);
		CheckEssense4.erase(PID);
		CheckEssense5.erase(PID);
	}

	if (Type == 1 && Erase && CBase::IsDeleted(Erase))
	{
		SummonAi.erase(Erase);
		CheckShiny.erase(Erase);
		MonsterDisappear.erase(Erase);
	}

	if (Type == 1 && Erase && Erase == (int)Hunting::Monster)
	{
		Hunting::Active = false;
		Hunting::Guild = 0;
		Hunting::Monster = 0;
		CPlayer::WriteAll(0xFF, "dsd", 247, "Hunting System ended.", 2);
	}

	if (Type == 3 && Erase && IID && CBase::IsDeleted(Erase))
	{
		ItemLockCheck.erase(IID);
		PetLifeCheck.erase(IID);
		GetItemStat.erase(IID);
	}
}