void __fastcall Quest(void *QuestOffset, void *edx, int PlayerOffset)
{
	IQuest Quest(QuestOffset);
	IChar IPlayer((void*)PlayerOffset);

	if (IPlayer.IsOnline() && CheckDailyQuest.count(Quest.GetIndex()) && CheckDailyQuest.find(Quest.GetIndex())->second > 0)
	{
		if (LevelDailyQuest.find(Quest.GetIndex())->second > IPlayer.GetLevel())
		{
			IPlayer.SystemMessage("Your level is not enough to accepted the quest!",TEXTCOLOR_RED);
			return;
		}

		if (PlayerQuest.find((Quest.GetIndex() * 1000000000000) + IPlayer.GetPID())->second.Active == 1)
		{
			IPlayer.SystemMessage("You already accepted the quest!",TEXTCOLOR_RED);
			return;
		}

		if (!PlayerQuest.count((Quest.GetIndex() * 1000000000000) + IPlayer.GetPID()) || PlayerQuest.find((Quest.GetIndex() * 1000000000000) + IPlayer.GetPID())->second.Repeat < CheckDailyQuest.find(Quest.GetIndex())->second)
		{
			PlayerQuest[(Quest.GetIndex() * 1000000000000) + IPlayer.GetPID()].Active = 1;
			PlayerQuest[(Quest.GetIndex() * 1000000000000) + IPlayer.GetPID()].MobAmount = 0;
			CPlayer::Write(IPlayer.GetOffset(),255,"dddd",222,IPlayer.GetPID(),Quest.GetIndex(),0);
			IPlayer.StartQuest(Quest.GetIndex());
		} else {
			if (PlayerQuest.find((Quest.GetIndex() * 1000000000000) + IPlayer.GetPID())->second.Repeat >= CheckDailyQuest.find(Quest.GetIndex())->second)
			{
				int Time = (int)time(0) - PlayerQuest.find((Quest.GetIndex() * 1000000000000) + IPlayer.GetPID())->second.Time;

				if (Time < 0)
				{
					int Day = (Time / 86400) * - 1;
					int Hour = ((Time / 3600) % 24) * - 1;
					int Minute = ((Time / 60) % 60) * - 1;
					int Second = (Time % 60) * - 1;
					std::string msg = "Exceeded the maximum repeat limit of quest. You need to wait " + Int2String(Day) + " Days " + Int2String(Hour) + " Hours " + Int2String(Minute) + " Minutes " + Int2String(Second) + " Seconds.";
					IPlayer.SystemMessage(msg,TEXTCOLOR_RED);
				} else {
					PlayerQuest[(Quest.GetIndex() * 1000000000000) + IPlayer.GetPID()].Active = 1;
					PlayerQuest[(Quest.GetIndex() * 1000000000000) + IPlayer.GetPID()].MobAmount = 0;
					PlayerQuest[(Quest.GetIndex() * 1000000000000) + IPlayer.GetPID()].Repeat = 0;
					PlayerQuest[(Quest.GetIndex() * 1000000000000) + IPlayer.GetPID()].Time = (int)time(0) + DailyQuest.find(IPlayer.GetMobIndex())->second.Time;
					IPlayer.StartQuest(Quest.GetIndex());
					IPlayer.DailyQuestUpdate(Quest.GetIndex(),0,0,(int)time(0) + DailyQuest.find(IPlayer.GetMobIndex())->second.Time);
				}
			}
		}

		return;
	}

	if (IPlayer.IsOnline() && IPlayer.IsBuff(349))
	{
		IPlayer.SystemMessage("You can not use quest while riding.",TEXTCOLOR_RED);
		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == RentArmor.find(Quest.GetIndex())->second.Quest)
	{
		int DonationCoinCheck = CPlayer::FindItem(IPlayer.GetOffset(),DonationCoin,RentArmor.find(Quest.GetIndex())->second.Coin);

		if (DonationCoinCheck && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, DonationCoin, RentArmor.find(Quest.GetIndex())->second.Coin) && RentArmor.find(Quest.GetIndex())->second.Index)
		{
			int Armor = CItem::CreateItem(RentArmor.find(Quest.GetIndex())->second.Index, RentArmor.find(Quest.GetIndex())->second.Prefix, 1, -1);

			if (Armor)
			{
				int Info = 4194432;

				if (RentArmor.find(Quest.GetIndex())->second.Dss)
					*(DWORD*)(Armor + 84) = RentArmor.find(Quest.GetIndex())->second.Dss;
				
				if (RentArmor.find(Quest.GetIndex())->second.Bof)
					Info += 2097152;

				*(DWORD*)(Armor + 48) = Info;
				*(DWORD*)(Armor + 108) = RentArmor.find(Quest.GetIndex())->second.Def;
				*(DWORD*)(Armor + 116) = RentArmor.find(Quest.GetIndex())->second.Eva;
				
				int ValidItem = CPlayer::_InsertItem(IPlayer.GetOffset(), 7, Armor);

				if (ValidItem == 1)
				{
					CDBSocket::Write(17, "ddbbb",*(DWORD *)(Armor + 36),*(DWORD *)(Armor + 32),15,*(DWORD *)(Armor + 108),0);
					CDBSocket::Write(17, "ddbbb",*(DWORD *)(Armor + 36),*(DWORD *)(Armor + 32),10,*(DWORD *)(Armor + 116),0);
					PetLifeCheck[*(DWORD *)(Armor + 36)].Time = (int)time(0) + RentArmor.find(Quest.GetIndex())->second.Time;
					PetLifeCheck[*(DWORD *)(Armor + 36)].Player = (int)IPlayer.GetOffset();
					CDBSocket::Write(89,"ddd",IPlayer.GetPID(),PetLifeCheck.find(*(DWORD *)(Armor + 36))->second.Time,*(DWORD *)(Armor + 36));
					CPlayer::Write(IPlayer.GetOffset(),0xFF,"ddd",230,*(DWORD *)(Armor + 36),RentArmor.find(Quest.GetIndex())->second.Time*1000);
					*(DWORD*)(Armor+68) = GetTickCount() + (2000*RentArmor.find(Quest.GetIndex())->second.Time);
					*(DWORD*)(Armor+72) = 0;
					CItem::OnTimer(Armor,0);
				}
			}
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == RentWeapon.find(Quest.GetIndex())->second.Quest)
	{
		int DonationCoinCheck = CPlayer::FindItem(IPlayer.GetOffset(),DonationCoin,RentWeapon.find(Quest.GetIndex())->second.Coin);

		if (DonationCoinCheck && CPlayer::RemoveItem(IPlayer.GetOffset(), 9, DonationCoin, RentWeapon.find(Quest.GetIndex())->second.Coin) && RentWeapon.find(Quest.GetIndex())->second.Index)
		{
			int Weapon = CItem::CreateItem(RentWeapon.find(Quest.GetIndex())->second.Index, RentWeapon.find(Quest.GetIndex())->second.Prefix, 1, -1);

			if (Weapon)
			{
				int Info = 4194432;

				if (RentWeapon.find(Quest.GetIndex())->second.Dss)
					*(DWORD*)(Weapon + 84) = RentWeapon.find(Quest.GetIndex())->second.Dss;
				
				if (RentWeapon.find(Quest.GetIndex())->second.Mix)
					Info += RentWeapon.find(Quest.GetIndex())->second.Mix;

				*(DWORD*)(Weapon + 48) = Info;
				*(DWORD*)(Weapon + 100) = RentWeapon.find(Quest.GetIndex())->second.Attack;
				*(DWORD*)(Weapon + 104) = RentWeapon.find(Quest.GetIndex())->second.Magic;
				*(DWORD*)(Weapon + 112) = RentWeapon.find(Quest.GetIndex())->second.Toa;
				*(DWORD*)(Weapon + 124) = RentWeapon.find(Quest.GetIndex())->second.Upgrade;
				int ValidItem = CPlayer::_InsertItem(IPlayer.GetOffset(), 7, Weapon);

				if (ValidItem == 1)
				{
					CDBSocket::Write(17, "ddbbb",*(DWORD *)(Weapon + 36),*(DWORD *)(Weapon + 32),27,*(DWORD*)(Weapon + 100),0);
					CDBSocket::Write(17, "ddbbb",*(DWORD *)(Weapon + 36),*(DWORD *)(Weapon + 32),28,*(DWORD*)(Weapon + 104),0);
					CDBSocket::Write(17, "ddbbb",*(DWORD *)(Weapon + 36),*(DWORD *)(Weapon + 32),9,*(DWORD*)(Weapon + 112),0);
					CDBSocket::Write(28, "ddbb",*(DWORD *)(Weapon + 36),*(DWORD *)(Weapon + 32),2,*(DWORD*)(Weapon + 124));
					PetLifeCheck[*(DWORD *)(Weapon + 36)].Time = (int)time(0) + RentWeapon.find(Quest.GetIndex())->second.Time;
					PetLifeCheck[*(DWORD *)(Weapon + 36)].Player = (int)IPlayer.GetOffset();
					CDBSocket::Write(89,"ddd",IPlayer.GetPID(),PetLifeCheck.find(*(DWORD *)(Weapon + 36))->second.Time,*(DWORD *)(Weapon + 36));
					CPlayer::Write(IPlayer.GetOffset(),0xFF,"ddd",230,*(DWORD *)(Weapon + 36),RentWeapon.find(Quest.GetIndex())->second.Time*1000);
					*(DWORD*)(Weapon+68) = GetTickCount() + (2000*RentWeapon.find(Quest.GetIndex())->second.Time);
					*(DWORD*)(Weapon+72) = 0;
					CItem::OnTimer(Weapon,0);
				}
			}
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == PLQuest)
	{
		if (IPlayer.IsOnline() && Protect32::Active == true)
		{
			IPlayer.SystemMessage("You can not register while Protecting Leader running.",TEXTCOLOR_RED);
			return;
		}

		if (IPlayer.IsOnline() && IPlayer.GetPID() != IPlayer.GetGID())
		{
			IPlayer.SystemMessage("Only guild leader can register for Protecting Leader.",TEXTCOLOR_RED);
			return;
		}

		if (IPlayer.IsOnline() && ProtectLeaderName.count(IPlayer.GetGID()))
		{
			IPlayer.SystemMessage("You already registered to Protecting Leader.",TEXTCOLOR_RED);
			return;
		} else {
			int PlayerGuild = CPlayer::GetGuildName(PlayerOffset);

			if (IPlayer.IsOnline() && PlayerGuild)
			{
				ProtectLeaderName[IPlayer.GetGID()] = (char*)CPlayer::GetGuildName(PlayerOffset);
				ProtectLeaderList.push_back(IPlayer.GetGID());
				IPlayer.SystemMessage("Successfully registered to Protecting Leader.",TEXTCOLOR_GREEN);
			} else {
				IPlayer.SystemMessage("Guild level is low for Protecting Leader registration.",TEXTCOLOR_RED);
			}
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == ENPCQ)
	{
		if (ENPCDD && ENPCDC && ENPCDC >= GetTickCount())
		{
			IPlayer.SystemMessage("Cooldown did not over for Event NPC!",TEXTCOLOR_RED);
			return;
		}

		int ENPCItemCheck = CPlayer::FindItem(IPlayer.GetOffset(),ENPCII,1);

		if (!ENPCItemCheck)
		{
			IPlayer.SystemMessage("You do not have any event item to collect!",TEXTCOLOR_RED);
			return;
		}

		if (NPCEDailyLimit < ENPCDL)
		{
			if (ENPCItemCheck)
			{
				IItem IItem((void*)ENPCItemCheck);
				int CheckItem = 0, CheckItemLeft = ENPCIA - NPCECollectedTotalItem;

				if (IItem.GetAmount() > CheckItemLeft)
					CheckItem = CheckItemLeft;
				else
					CheckItem = IItem.GetAmount();

				NPCECollectedTotalItem += CheckItem;
				std::string msg = Int2String(CheckItem) + " event items have been collected from you. " + Int2String(NPCECollectedTotalItem) + " event items have been collected in total!";
				IPlayer.SystemMessage(msg,TEXTCOLOR_GREEN);
				(*(int (__thiscall **)(DWORD, void *, signed int, signed int))(*(DWORD*)ENPCItemCheck + 120))((int)ENPCItemCheck,IPlayer.GetOffset(),9,-CheckItem);
			}

			if (NPCECollectedTotalItem == ENPCIA)
			{
				if (NPCELeftTime > 0)
					CPlayer::WriteAll(0xFF, "ds", 234, "[Exp Event NPC] Event time has been extended!");
				else
					CPlayer::WriteAll(0xFF, "ds", 234, "[Exp Event NPC] Event has been started!");

				CPlayer::SetEventCode(0,1);
				NPCEDailyLimit++;
				NPCELeftTime += (ENPCDU + 2);
				NPCECollectedTotalItem = 0;
				ENPCDC = GetTickCount() + (ENPCDD*1000);
			}
		} else {
			IPlayer.SystemMessage("Daily limit has been exceeded! Please try again tomorrow!",TEXTCOLOR_RED);
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == ENPCRQ)
	{
		std::string msg = Int2String(NPCECollectedTotalItem) + " event items have been collected in total!";
		IPlayer.SystemMessage(msg,TEXTCOLOR_GREEN);
		return;
	}

	if (IPlayer.IsOnline() && BufferCheck.count(Quest.GetIndex()) && BufferCheck.find(Quest.GetIndex())->second.Index == Quest.GetIndex())
	{
		if (IPlayer.GetLevel() <= BufferCheck.find(Quest.GetIndex())->second.Limit)
		{
			IPlayer.Buff(48,1800,8*(BufferCheck.find(Quest.GetIndex())->second.Grade)+3);
			IPlayer.Buff(50,1800,8*(BufferCheck.find(Quest.GetIndex())->second.Grade)+3);
			IPlayer.Buff(47,1800,8*(BufferCheck.find(Quest.GetIndex())->second.Grade)+3);
			IPlayer.Buff(49,1800,8*(BufferCheck.find(Quest.GetIndex())->second.Grade)+3);
			IPlayer.Buff(46,1800,8*(BufferCheck.find(Quest.GetIndex())->second.Grade)+3);
			IPlayer.Buff(36,1800,8*(BufferCheck.find(Quest.GetIndex())->second.Grade)+16);
			CChar::CancelAllBuff(IPlayer.GetOffset(), 37);
			int AddBuff = CBuff::CreateBuff(37,1800,30*(BufferCheck.find(Quest.GetIndex())->second.Grade)+5,20*(BufferCheck.find(Quest.GetIndex())->second.Grade)+5);
			(*(int (__thiscall **)(int, int))(*(DWORD *)PlayerOffset + 180))(PlayerOffset, AddBuff);
			IPlayer.Buff(12,1800,45);
		} else {
			IPlayer.SystemMessage("Your level is too high!",TEXTCOLOR_RED);
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == LMSQuest)
	{
		if (IPlayer.IsOnline() && LastManStand::Active == true)
		{
			IPlayer.SystemMessage("Last Man Standing already running. Please try again later.",TEXTCOLOR_RED);
			return;
		}

		if (IPlayer.GetLevel() < LMSLimit)
		{
			IPlayer.SystemMessage("Your level is not enough to register for Last Man Standing.",TEXTCOLOR_RED);
		} else {
			if (!LastManRegistration.find(IPlayer.GetPID())->second)
			{
				LastManRegistration[IPlayer.GetPID()] = 1;
				IPlayer.SystemMessage("Successfully registered to Last Man Standing.",TEXTCOLOR_GREEN);
			} else {
				IPlayer.SystemMessage("You already registered to Last Man Standing.",TEXTCOLOR_RED);
			}
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == DTQuest)
	{
		if (IPlayer.IsOnline() && DuelTournament::Active == true)
		{
			IPlayer.SystemMessage("Duel Tournament already running. Please try again later.",TEXTCOLOR_RED);
			return;
		}

		if (IPlayer.GetLevel() < DTLimit)
		{
			IPlayer.SystemMessage("Your level is not enough to register for Duel Tournament.",TEXTCOLOR_RED);
		} else {
			if (!DuelTournamentRegistration.find(IPlayer.GetPID())->second)
			{
				DuelTournamentRegistration[IPlayer.GetPID()] = 1;
				DuelTournamentList.push_back(IPlayer.GetName());
				IPlayer.SystemMessage("Successfully registered to Duel Tournament.",TEXTCOLOR_GREEN);
				DuelTournament::RegisterAmount += 1;
			} else {
				IPlayer.SystemMessage("You already registered to Duel Tournament.",TEXTCOLOR_RED);
			}
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == HellQuest)
	{
		if (IPlayer.IsBuff(167))
		{
			int Time = IPlayer.GetBuffRemain(167) / 60;
			std::string msg = "You need to wait ";

			if (Time > 0)
			{
				msg = msg + Int2String(Time);
				msg = msg + " minutes to re-join Picture Of Hell!";
			} else {
				msg = msg + " less then a minute to re-join Picture Of Hell!";
			}

			IPlayer.SystemMessage(msg.c_str(),TEXTCOLOR_RED);
			return;
		}

		if (IPlayer.IsOnline() && Hell::Active == true)
		{
			IPlayer.SystemMessage("Picture Of Hell already running. Please try again later.",TEXTCOLOR_RED);
			return;
		}

		if (IPlayer.IsOnline() && IPlayer.IsParty())
		{
			int Party = CParty::FindParty(IPlayer.GetPartyID());

			if (!Party)
				return;

			if (!CParty::IsHead(Party, (int)IPlayer.Offset))
			{
				IPlayer.SystemMessage("You are not the party leader to start Picture Of Hell.", TEXTCOLOR_RED);
				return;
			}

			for (int i = CParty::GetPlayerList((void*)Party); i; i = CBaseList::Pop((void *)i))
			{
				int Members = *(DWORD*)((void*)i);
				IChar Member((void*)*(DWORD*)((void*)i));

				if (CChar::IsNormal(Members) && IPlayer.IsValid())
				{
					if (Member.GetLevel() < 60)
					{
						IPlayer.SystemMessage("Some of your party members levels are not enough.", TEXTCOLOR_RED);
						return;
					}

					if (Member.IsBuff(167))
					{
						IPlayer.SystemMessage("Some of your party members have time limit to re-join Picture Of Hell.", TEXTCOLOR_RED);
						return;
					}
				}
			}

			Hell::Delay = 0;
			Hell::KillCount = 0;
			Hell::Round = 1;
			Hell::Time = 1803;
			Hell::Rebirth = CParty::GetSize((void*)Party) * 3;
			Hell::Active = true;

			for (int i = CParty::GetPlayerList((void*)Party); i; i = CBaseList::Pop((void *)i))
			{
				int Members = *(DWORD*)((void*)i);
				IChar Member((void*)*(DWORD*)((void*)i));

				if (CChar::IsNormal(Members) && IPlayer.IsValid())
				{
					CPlayer::Write(Member.GetOffset(), 0xFF, "ddddd", 242, 74, 255, 255, 255);
					Member.Teleport(HellMap, HellX, HellY);
					Member.Buff(166,1802,0);
					Member.ScreenTime(1800);
					Member.SetRebirthTalisman(Hell::Rebirth);
				}
			}
		} else {
			IPlayer.SystemMessage("You need a party to start Picture Of Hell.",TEXTCOLOR_RED);
			return;
		}

		return;
	}

	if(IPlayer.IsOnline() && Quest.GetIndex() == F10Quest)
	{
		if (F10::Active == true)
		{
			IPlayer.SystemMessage("You can not register while Company System running.",TEXTCOLOR_RED);
			return;
		}

		if (F10Registration.find(IPlayer.GetPID())->second)
		{
			IPlayer.SystemMessage("You already registered to Company System.",TEXTCOLOR_RED);
			return;
		} else {
			F10Registration[IPlayer.GetPID()] = 1;
			F10::RegisterAmount += 1;
			IPlayer.SystemMessage("Successfully registered to Company System.",TEXTCOLOR_GREEN);
			return;
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == ScenarioQuest)
	{
		if (ScenarioRegistration.find(IPlayer.GetPID())->second && IPlayer.GetPID() == IPlayer.GetGID())
		{
			int Check = 0;

			if (Scenario::RegisterAmount > 0)
			{
				for (int i = 0; i <= Scenario::RegisterAmount; i++)
				{
					if (ScenarioGuildID.find(i)->second && ScenarioGuildID[i] == IPlayer.GetGID())
					{
						Check = 1;
						break;
					}
				}
			}

			if (Check == 0)
				ScenarioRegistration[IPlayer.GetPID()] = 0;
		}

		if (IPlayer.IsOnline() && Scenario::Active == true)
		{
			IPlayer.SystemMessage("You can not register while Destructing Key Points running.",TEXTCOLOR_RED);
			return;
		}

		if (IPlayer.IsOnline() && IPlayer.GetPID() != IPlayer.GetGID())
		{
			IPlayer.SystemMessage("Only guild leader can register for Destructing Key Points.",TEXTCOLOR_RED);
			return;
		}

		if (IPlayer.IsOnline() && ScenarioRegistration.find(IPlayer.GetPID())->second)
		{
			IPlayer.SystemMessage("You already registered to Destructing Key Points.",TEXTCOLOR_RED);
			return;
		} else {
			int PlayerGuild = CPlayer::GetGuildName(PlayerOffset);

			if (IPlayer.IsOnline() && PlayerGuild)
			{
				ScenarioRegistration[IPlayer.GetPID()] = 1;
				Scenario::RegisterAmount += 1;
				ScenarioGuildID[Scenario::RegisterAmount] = IPlayer.GetGID();
				ScenarioGuildName[Scenario::RegisterAmount] = (char*)CPlayer::GetGuildName(PlayerOffset);
				IPlayer.SystemMessage("Successfully registered to Destructing Key Points.",TEXTCOLOR_GREEN);
			} else {
				IPlayer.SystemMessage("Guild level is low for Destructing Key Points registration.",TEXTCOLOR_RED);
			}
		}

		return;
	}

	if (IPlayer.IsOnline() && HonorShop.find(Quest.GetIndex())->second)
	{
		if (HonorShop.find(Quest.GetIndex())->second > CheckHonor.find(IPlayer.GetPID())->second.RPx)
		{
			IPlayer.SystemMessage("You do not have enough reward points.",TEXTCOLOR_RED);
			return;
		} else {
			CheckHonor[IPlayer.GetPID()].RPx -= HonorShop.find(Quest.GetIndex())->second;
		}
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == BFQuest)
	{
		if (Battlefield::Active == true)
		{
			IPlayer.SystemMessage("You can not register while Battlefield running.",TEXTCOLOR_RED);
			return;
		}

		if (BattlefieldRegistration.find(IPlayer.GetPID())->second)
		{
			IPlayer.SystemMessage("You already registered to Battlefield.",TEXTCOLOR_RED);
			return;
		} else {
			BattlefieldRegistration[IPlayer.GetPID()] = 1;
			Battlefield::RegisterAmount += 1;
			IPlayer.SystemMessage("Successfully registered to Battlefield.",TEXTCOLOR_GREEN);
			return;
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == EmokQuestIndex)
	{
		int honor = 0, addtime = 0;

		if (CheckHonor.count(IPlayer.GetPID()))
			honor = CheckHonor.find(IPlayer.GetPID())->second.HPx;

		if(honor >= 2790 && honor < 12090)
			addtime = 30;
		else if(honor >= 12090 && honor < 44640)
			addtime = 40;
		else if(honor >= 44640 && honor < 78740)
			addtime = 50;
		else if(honor >= 78740)
			addtime = 60;

		if (IPlayer.IsOnline() && CheckEmok.find(IPlayer.GetPID())->second.Day == String2Int(Time::GetDay()) && CheckEmok.find(IPlayer.GetPID())->second.Time > 10)
		{
			IPlayer.Buff(156,CheckEmok.find(IPlayer.GetPID())->second.Time,0);
			IPlayer.Teleport(EmokMap, EmokX, EmokY);
		} else if (IPlayer.IsOnline() && CheckEmok.find(IPlayer.GetPID())->second.Day != String2Int(Time::GetDay()))
		{
			CheckEmok[IPlayer.GetPID()].Time = 3600+addtime;
			CheckEmok[IPlayer.GetPID()].Day = String2Int(Time::GetDay());
			IPlayer.Buff(156,CheckEmok.find(IPlayer.GetPID())->second.Time,0);
			IPlayer.Teleport(EmokMap, EmokX, EmokY);
			CDBSocket::Write(83,"ddd",IPlayer.GetPID(),CheckEmok.find(IPlayer.GetPID())->second.Day,CheckEmok.find(IPlayer.GetPID())->second.Time);
		} else {
			IPlayer.SystemMessage("You already used your daily free time.",TEXTCOLOR_RED);
		}

		return;
	}

	if (IPlayer.IsOnline() && Quest.GetIndex() == MysteryQuest)
	{
		int OTP = IPlayer.GetSkillPointer(87);
		int EVA = IPlayer.GetSkillPointer(88);
		int DEF = IPlayer.GetSkillPointer(89);

		if (!OTP && !EVA && !DEF)
		{
			IPlayer.SystemMessage("You do not have mystery skill to reset.",TEXTCOLOR_RED);
			return;
		}

		int MysteryItemCheck = CPlayer::FindItem(IPlayer.GetOffset(),MysteryResetItem,1);

		if (!MysteryItemCheck)
		{
			IPlayer.SystemMessage("You do not have Stone of chance for Mystery Skill to reset.",TEXTCOLOR_RED);
			return;
		}

		if (IPlayer.IsOnline() && OTP)
		{
			IPlayer.RemoveOTP(8 * *(DWORD*)(OTP + 8));
			*(DWORD*)(OTP + 8) = 0;
			CPlayer::Write(IPlayer.GetOffset(),11,"bb",85,0);
			CDBSocket::Write(22,"dbbw",IPlayer.GetPID(),*(DWORD*)(OTP + 4),*(DWORD*)(OTP + 8),*(DWORD*)((int)IPlayer.GetOffset() + 548));
			*(DWORD*)((int)IPlayer.GetOffset() + 4 * *(DWORD*)(OTP +4) + 632) = 0;
		}

		if (IPlayer.IsOnline() && EVA)
		{
			IPlayer.RemoveEva(6 * *(DWORD*)(EVA + 8));
			*(DWORD*)(EVA + 8) = 0;
			CPlayer::Write(IPlayer.GetOffset(),11,"bb",86,0);
			CDBSocket::Write(22,"dbbw",IPlayer.GetPID(),*(DWORD*)(EVA + 4),*(DWORD*)(EVA + 8),*(DWORD*)((int)IPlayer.GetOffset() + 548));
			*(DWORD*)((int)IPlayer.GetOffset() + 4 * *(DWORD*)(EVA +4) + 632) = 0;
		}

		if (IPlayer.IsOnline() && DEF)
		{
			IPlayer.RemoveDef(24 + (7 * *(DWORD*)(DEF + 8)));
			*(DWORD*)(DEF + 8) = 0;
			CPlayer::Write(IPlayer.GetOffset(),11,"bb",87,0);
			CDBSocket::Write(22,"dbbw",IPlayer.GetPID(),*(DWORD*)(DEF + 4),*(DWORD*)(DEF + 8),*(DWORD*)((int)IPlayer.GetOffset() + 548));
			*(DWORD*)((int)IPlayer.GetOffset() + 4 * *(DWORD*)(DEF +4) + 632) = 0;
		}

		(*(int (__thiscall **)(DWORD, void *, signed int, signed int))(*(DWORD*)MysteryItemCheck + 120))(MysteryItemCheck,IPlayer.GetOffset(),9,-1);
		return;
	}

	CQuest::Run(QuestOffset, PlayerOffset);
}