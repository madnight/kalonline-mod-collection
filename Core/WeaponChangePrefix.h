signed int __fastcall WeaponChangePrefix(void *Item, void *edx, int Player, int ID, int Chance, int Argument)
{
	IChar IPlayer((void*)Player);
	IItem IItem(Item);
	int CurrentPrefix = 0, NewPrefix = 0, AddPrefix = 0;

	if (!IPlayer.IsValid())
		return 0;

	if (IItem.GetInfo() & 4194304)
	{
		IPlayer.BoxMsg("Item is locked.");
		return 0;
	}

	if (CItem::IsState((int)IItem.GetOffset(), 1) || ID >= 0 && ID )
		return 0;

	if (IItem.Prefix())
		CurrentPrefix = IItem.PrefixID();

	NewPrefix = CurrentPrefix;
	int Rate = CTools::Rate(1, 100);
	int CheckPolish = CItem::IsState((int)IItem.GetOffset(), 64);

	for (signed int i = 0; i < 2; ++i)
	{
		if ( Rate <= (int)*(DWORD*)(Chance + 4 * i) )
		{
			NewPrefix = *(DWORD *)(Argument + 4 * i);
			break;
		}
	}

	if (CurrentPrefix == NewPrefix)
	{
		if ( CheckPolish )
		{
			CDBSocket::Write(21, "dddbb",IItem.GetIID(),IPlayer.GetID(),64,0,255);
			CItem::SubState((int)IItem.GetOffset(),64);
			CItem::SendItemInfo(IItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
			return 1;
		}

		if (IItem.GetEndurance() >= 5)
			IItem.DecreaseEndurance(5);
		else
			IItem.DecreaseEndurance(IItem.GetEndurance());

		if (IItem.GetEndurance() <= 0)
		{
			CPlayer::Write(IPlayer.GetOffset(), 91, "db",IItem.GetIID(),IItem.GetEndurance());
			CDBSocket::Write(3,"ddwdbddd",IItem.GetIID(),IPlayer.GetID(),IItem.CheckIndex(),1,27,0,0,0);

			if ( CItem::GetLevel((int)IItem.GetOffset()) >= 40 )
				CItem::InsertItem((int)IPlayer.GetOffset(), 27, 517, 0, 15, -1);

			CBase::Delete(IItem.GetOffset());
		} else {
			CPlayer::Write(IPlayer.GetOffset(), 91, "db",IItem.GetIID(),IItem.GetEndurance());
			CDBSocket::Write(18,"ddb",IItem.GetIID(),IPlayer.GetID(),IItem.GetEndurance());
		}
	} else {
		int CurrentInfo = 0, CurrentMixInfo = 0, SetMixInfo = 0;

		if (IItem.GetInfo())
			CurrentInfo = IItem.GetInfo();

		if (CurrentInfo >= 1310720)
			CurrentMixInfo = 1310720;
		else if (CurrentInfo >= 1179648)
			CurrentMixInfo = 1179648;
		else if (CurrentInfo >= 1114112)
			CurrentMixInfo = 1114112;
		else if (CurrentInfo >= 1081344)
			CurrentMixInfo = 1081344;
		else if (CurrentInfo >= 1064960)
			CurrentMixInfo = 1064960;
		else if (CurrentInfo >= 1056768)
			CurrentMixInfo = 1056768;
		else if (CurrentInfo >= 1052672)
			CurrentMixInfo = 1052672;
		else if (CurrentInfo >= 1050624)
			CurrentMixInfo = 1050624;
		else if (CurrentInfo >= 1049600)
			CurrentMixInfo = 1049600;
		else if (CurrentInfo >= 1049088)
			CurrentMixInfo = 1049088;
		else if (CurrentInfo >= 1048832)
			CurrentMixInfo = 1048832;

		if (CurrentMixInfo)
			CurrentInfo -= CurrentMixInfo;

		if (CheckPimp.count(NewPrefix) && CheckPimp.find(NewPrefix)->second.Prefix)
		{
			IItem.SetTalismanOA(CheckPimp.find(NewPrefix)->second.GetA);
			IItem.SetTalismanOM(CheckPimp.find(NewPrefix)->second.GetM);
			IItem.SetTOA(CheckPimp.find(NewPrefix)->second.GetTOA);
			IItem.SetUpgrade(CheckPimp.find(NewPrefix)->second.GetUpg);
			CDBSocket::Write(17, "ddbbb",IItem.GetIID(),IPlayer.GetPID(),27,IItem.GetTalismanOA(),0);
			CDBSocket::Write(17, "ddbbb",IItem.GetIID(),IPlayer.GetPID(),28,IItem.GetTalismanOM(),0);
			CDBSocket::Write(17, "ddbbb",IItem.GetIID(),IPlayer.GetPID(),9,IItem.GetTOA(),0);
			CDBSocket::Write(28, "ddbb",IItem.GetIID(),IPlayer.GetPID(),2,IItem.GetUpgrade());
			CItem::SendItemInfo(IItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
			return 1;
		}

		if (MixConfigPrefix.count(NewPrefix) && MixConfigPrefix.find(NewPrefix)->second)
		{
			SetMixInfo = MixConfigInfo.find(NewPrefix)->second;
			CDBSocket::Write(21, "dddbb",IItem.GetIID(),IPlayer.GetID(),IItem.GetInfo(),0,0);
			IItem.SetInfo(CurrentInfo + SetMixInfo);
			CDBSocket::Write(21, "dddbb",IItem.GetIID(),IPlayer.GetID(),CurrentInfo + SetMixInfo,8,7);
			CItem::SendItemInfo(IItem.GetOffset(), (int)IPlayer.GetOffset(), 92);		
			CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, 10, 0, 128, 255);

			if (MixConfigMsg.count(NewPrefix))
				IPlayer.SystemMessage(MixConfigMsg.find(NewPrefix)->second,TEXTCOLOR_DARKGREEN);

			return 1;
		}

		if (WeaponReplace.count(IItem.CheckIndex()) && WeaponReplaceIndex.count(IItem.CheckIndex()))
		{
			if (WeaponReplace.find(IItem.CheckIndex())->second == NewPrefix)
			{
				if (CBase::IsDeleted((int)Item))
					return 0;

				if (IPlayer.IsBuff(328))
					return 0;
				else
					IPlayer.Buff(328,3,0);

				int ReplacePrefix = 0, ReplaceItem = 0, ReplaceInfo = 0, ReplaceA = 0, ReplaceM = 0, ReplaceTOA = 0, ReplaceEB = 0, ReplaceGem = 0;
				int ItemStat = GetItemStat.find(IItem.GetIID())->second;

				if (*(DWORD *)((int)Item + 44))
					ReplacePrefix = *(DWORD *)(*(DWORD *)((int)Item + 44) + 32);

				if (*(DWORD *)((int)Item + 48))
					ReplaceInfo = *(DWORD *)((int)Item + 48);

				if (*(DWORD *)((int)Item + 100))
					ReplaceA = *(DWORD *)((int)Item + 100);

				if (*(DWORD *)((int)Item + 104))
					ReplaceM = *(DWORD *)((int)Item + 104);

				if (*(DWORD *)((int)Item + 112))
					ReplaceTOA = *(DWORD *)((int)Item + 112);

				if (*(DWORD *)((int)Item + 124))
					ReplaceEB = *(DWORD *)((int)Item + 124);

				if (*(DWORD *)((int)Item + 84))
					ReplaceGem = *(DWORD *)((int)Item + 84);

				int ItemNewIndex = IItem.CheckIndex();
				int DeleteCheck = (*(int (__thiscall **)(DWORD, void *, signed int, signed int))(*(DWORD*)Item + 120))((int)Item,IPlayer.GetOffset(),9,-1);

				if (!DeleteCheck)
				{
					ReplaceItem = CItem::CreateItem(WeaponReplaceIndex.find(ItemNewIndex)->second, ReplacePrefix, 1, -1);

					if (ReplaceItem)
					{
						CIOObject::AddRef(ReplaceItem);
						*(DWORD *)(ReplaceItem + 48) = ReplaceInfo;
						*(DWORD *)(ReplaceItem + 100) = ReplaceA;
						*(DWORD *)(ReplaceItem + 104) = ReplaceM;
						*(DWORD *)(ReplaceItem + 112) = ReplaceTOA;
						*(DWORD *)(ReplaceItem + 124) = ReplaceEB;
						*(DWORD *)(ReplaceItem + 84) = ReplaceGem;

						if ( CPlayer::_InsertItem(IPlayer.GetOffset(), 27, ReplaceItem) != 1 )
						{
							CConsole::Red("Real time weapon replace insert item Null error [PID (%d)] ", IPlayer.GetPID());
							CBase::Delete((void *)ReplaceItem);
							CIOCriticalSection::Leave((void*)((char *)IPlayer.GetOffset() + 1020));
							return 0;
						}

						CIOObject::Release((void *)ReplaceItem);
						GetItemStat[*(DWORD *)(ReplaceItem + 36)] = ItemStat;
						CDBSocket::Write(90,"ddd",IPlayer.GetPID(),ItemStat,*(DWORD *)(ReplaceItem + 36));
						CDBSocket::Write(87,"ddd",IPlayer.GetPID(),*(DWORD *)(ReplaceItem + 84),*(DWORD *)(ReplaceItem + 36));
						CDBSocket::Write(21, "dddbb",*(DWORD *)(ReplaceItem + 36),*(DWORD *)(ReplaceItem + 32),*(DWORD *)(ReplaceItem + 48),8,7);
						CDBSocket::Write(17, "ddbbb",*(DWORD *)(ReplaceItem + 36),*(DWORD *)(ReplaceItem + 32),27,*(DWORD *)(ReplaceItem + 100),0);
						CDBSocket::Write(17, "ddbbb",*(DWORD *)(ReplaceItem + 36),*(DWORD *)(ReplaceItem + 32),28,*(DWORD *)(ReplaceItem + 104),0);
						CDBSocket::Write(17, "ddbbb",*(DWORD *)(ReplaceItem + 36),*(DWORD *)(ReplaceItem + 32),9,*(DWORD *)(ReplaceItem + 112),0);
						CDBSocket::Write(28, "ddbb",*(DWORD *)(ReplaceItem + 36),*(DWORD *)(ReplaceItem + 32),2,*(DWORD *)(ReplaceItem + 124));
						CItem::SendItemInfo((void*)ReplaceItem, (int)IPlayer.GetOffset(), 92);
						CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, 0, 0, 128, 255);
					}
				} else {
					return 0;
				}

				return 1;
			}
		}

		if (WeaponReplacePrefix.count(NewPrefix))
		{
			IPlayer.BoxMsg("Enchanting item and the talisman are different.");
			return 0;
		}

		if (NewPrefix == ImpConfigRead)
		{
			if ( IItem.CheckIndex() >= 769 && IItem.CheckIndex() <= 801 
				|| IItem.CheckIndex() >= 1433 && IItem.CheckIndex() <= 1441 
				|| IItem.CheckIndex() >= 1700 && IItem.CheckIndex() <= 1704 
				|| IItem.CheckIndex() >= 3033 && IItem.CheckIndex() <= 3039
				|| IItem.CheckIndex() >= 1921 && IItem.CheckIndex() <= 1927 
				|| IItem.CheckIndex() >= 1821 && IItem.CheckIndex() <= 1824 
				|| IItem.CheckIndex() >= 1448 && IItem.CheckIndex() <= 1453 
				|| IItem.CheckIndex() >= 1442 && IItem.CheckIndex() <= 1445 
				|| IItem.CheckIndex() >= 2676 && IItem.CheckIndex() <= 2682 
				|| IItem.CheckIndex() >= 2688 && IItem.CheckIndex() <= 2693 
				|| IItem.CheckIndex() >= 2700 && IItem.CheckIndex() <= 2705 
				|| IItem.CheckIndex() >= 4329 && IItem.CheckIndex() <= 4335 
				|| IItem.CheckIndex() == 1853 || IItem.CheckIndex() == 1669 
				|| IItem.CheckIndex() == 1668 )
			{
				IPlayer.SystemMessage("Your weapon already imperial.",TEXTCOLOR_RED);
				return 0;
			}

			int ItemStat = GetItemStat.find(IItem.GetIID())->second;
			int GetWeaponGrade = *(DWORD*)(*(DWORD *)((int)Item + 40) + 80), Imp = 0, xMixPrefix = 0, ImpItem = 0;

			if (GetWeaponGrade > 90)
				return 0;

			switch (GetWeaponGrade)
			{
			case 0x28:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					Imp = 7210;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1433;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 )
						Imp = 771;
					else
						Imp = 770;
				} else {
					Imp = 769;
				}
				break;
			case 0x2D:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					Imp = 7290;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1434;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 )
						Imp = 774;
					else
						Imp = 773;
				} else {
					Imp = 772;
				}
				break;
			case 0x30:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					Imp = 7214;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1435;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 )
						Imp = 777;
					else
						Imp = 776;
				} else {
					Imp = 775;
				}
				break;
			case 0x32:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					Imp = 7218;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1436;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 )
						Imp = 781;
					else
						Imp = 780;
				} else {
					Imp = (*(DWORD *)(*(DWORD *)((int)Item + 40) + 72) != 0) + 778;
				}
				break;
			case 0x35:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					Imp = 7222;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1437;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 )
						Imp = 785;
					else
						Imp = 784;
				} else {
					Imp = (*(DWORD *)(*(DWORD *)((int)Item + 40) + 72) != 0) + 782;
				}
				break;
			case 0x38:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					Imp = 7226;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1438;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 )
						Imp = 789;
					else
						Imp = 788;
				} else {
					Imp = (*(DWORD *)(*(DWORD *)((int)Item + 40) + 72) != 0) + 786;
				}
				break;
			case 0x3B:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					Imp = 7230;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1439;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 )
						Imp = 793;
					else
						Imp = 792;
				} else {
					Imp = (*(DWORD *)(*(DWORD *)((int)Item + 40) + 72) != 0) + 790;
				}
				break;
			case 0x3E:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					if (IItem.CheckIndex() == 7231)
						Imp = 7230;
					else if (IItem.CheckIndex() == 7233)
						Imp = 7235;
					else if (IItem.CheckIndex() == 7234)
						Imp = 7236;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1440;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 )
						Imp = 797;
					else
						Imp = 796;
				} else {
					Imp = (*(DWORD *)(*(DWORD *)((int)Item + 40) + 72) != 0) + 794;
				}
				break;
			case 0x41:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					Imp = 7238;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1441;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 672 )
						Imp = 801;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 1677 )
						Imp = 1821;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 1678 )
						Imp = 1822;
					else
						Imp = 800;
				} else {
					Imp = (*(DWORD *)(*(DWORD *)((int)Item + 40) + 72) != 0) + 798;
				}
				break;
			case 0x46:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					if (IItem.CheckIndex() == 7239)
						Imp = 7241;
					else if (IItem.CheckIndex() == 7240)
						Imp = 7242;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 1704;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 1698 )
						Imp = 1853;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 1705 )
						Imp = 1823;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 1706 )
						Imp = 1824;
					else
						Imp = 1702;
				} else {
					if ( IItem.CheckIndex() == 1695 )
						Imp = 1700;
					else
						Imp = 1701;
				}
				break;
			case 0x4B:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					if (IItem.CheckIndex() == 7243)
						Imp = 7245;
					else if (IItem.CheckIndex() == 7244)
						Imp = 7246;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					if ( IItem.CheckIndex() == -1328 )
						Imp = 4335;
					else
						Imp = 1927;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 1917 )
						Imp = 1924;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 1918 )
						Imp = 1925;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 1919 )
						Imp = 1926;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == -1325 )
						Imp = 4332;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == -1326 )
						Imp = 4333;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == -1327 )
						Imp = 4334;
					else if ( IItem.CheckIndex() == -1324 )
						Imp = 4331;
					else
						Imp = 1923;
				} else {
					if ( IItem.CheckIndex() == 1914 )
						Imp = 1921;
					else if ( IItem.CheckIndex() == -1322 )
						Imp = 4329;
					else if ( IItem.CheckIndex() == -1323 )
						Imp = 4330;
					else
						Imp = 1922;
				}
				break;
			case 0x50:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					if (IItem.CheckIndex() == 7247)
						Imp = 7249;
					else if (IItem.CheckIndex() == 7248)
						Imp = 7250;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 3039;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 3029 )
						Imp = 3036;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 3030 )
						Imp = 3037;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 3031 )
						Imp = 3038;
					else
						Imp = 3035;
				} else {
					if ( IItem.CheckIndex() == 3026 )
						Imp = 3033;
					else
						Imp = 3034;
				}
				break;
			case 0x5A:
				if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == -1 )
				{
					if (IItem.CheckIndex() == 7251)
						Imp = 7253;
					else if (IItem.CheckIndex() == 7252)
						Imp = 7254;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 3 )
				{
					Imp = 3161;
				} else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) )
				{
					if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 3150 )
						Imp = 3158;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 3151 )
						Imp = 3159;
					else if ( *(DWORD *)(*(DWORD *)((int)Item + 40) + 96) == 1 && IItem.CheckIndex() == 3152 )
						Imp = 3160;
					else
						Imp = 3157;
				} else {
					if ( IItem.CheckIndex() == 3147 )
						Imp = 3155;
					else
						Imp = 3156;
				}
				break;
			default:
				break;
			}

			if (!Imp)
				return 0;

			if (*(DWORD *)((int)Item + 44))
				xMixPrefix = *(DWORD *)(*(DWORD *)((int)Item + 44) + 32);
			else 
				xMixPrefix = 0;

			int DeleteCheck = (*(int (__thiscall **)(DWORD, void *, signed int, signed int))(*(DWORD*)Item + 120))((int)Item,IPlayer.GetOffset(),9,-1);

			if (!DeleteCheck)
			{
				ImpItem = CItem::CreateItem(Imp, xMixPrefix, 1, -1);

				if (ImpItem)
				{
					CIOObject::AddRef(ImpItem);

					if ( *(DWORD *)((int)Item + 48) )
						*(DWORD *)(ImpItem + 48) = *(DWORD *)((int)Item + 48);

					if ( *(DWORD *)((int)Item + 100) )
						*(DWORD *)(ImpItem + 100) = *(DWORD *)((int)Item + 100);

					if ( *(DWORD *)((int)Item + 104) )
						*(DWORD *)(ImpItem + 104) = *(DWORD *)((int)Item + 104);

					if ( *(DWORD *)((int)Item + 112) )
						*(DWORD *)(ImpItem + 112) = *(DWORD *)((int)Item + 112);

					if ( *(DWORD *)((int)Item + 124) )
						*(DWORD *)(ImpItem + 124) = *(DWORD *)((int)Item + 124);

					if ( *(DWORD *)((int)Item + 84) )
						*(DWORD *)(ImpItem + 84) = *(DWORD *)((int)Item + 84);

					if ( CPlayer::_InsertItem(IPlayer.GetOffset(), 27, ImpItem) != 1 )
					{
						CConsole::Red("MixItem() insert item Null error [PID (%d)] ", IPlayer.GetPID());
						CBase::Delete((void *)ImpItem);
						CIOCriticalSection::Leave((void*)((char *)IPlayer.GetOffset() + 1020));
						return 0;
					}

					CIOObject::Release((void *)ImpItem);
					GetItemStat[*(DWORD *)(ImpItem + 36)] = ItemStat;
					CDBSocket::Write(90,"ddd",IPlayer.GetPID(),ItemStat,*(DWORD *)(ImpItem + 36));
					CDBSocket::Write(87,"ddd",IPlayer.GetPID(),*(DWORD *)(ImpItem + 84),*(DWORD *)(ImpItem + 36));
					CDBSocket::Write(21, "dddbb",*(DWORD *)(ImpItem + 36),*(DWORD *)(ImpItem + 32),*(DWORD *)(ImpItem + 48),8,7);
					CDBSocket::Write(17, "ddbbb",*(DWORD *)(ImpItem + 36),*(DWORD *)(ImpItem + 32),27,*(DWORD *)(ImpItem + 100),0);
					CDBSocket::Write(17, "ddbbb",*(DWORD *)(ImpItem + 36),*(DWORD *)(ImpItem + 32),28,*(DWORD *)(ImpItem + 104),0);
					CDBSocket::Write(17, "ddbbb",*(DWORD *)(ImpItem + 36),*(DWORD *)(ImpItem + 32),9,*(DWORD *)(ImpItem + 112),0);
					CDBSocket::Write(28, "ddbb",*(DWORD *)(ImpItem + 36),*(DWORD *)(ImpItem + 32),2,*(DWORD *)(ImpItem + 124));
					CItem::SendItemInfo((void*)ImpItem, (int)IPlayer.GetOffset(), 92);
					CPlayer::Write(IPlayer.GetOffset(), 0xFF, "ddddd", 242, 10, 0, 128, 255);
				}
			} else {
				return 0;
			}

			return 1;
		}

		AddPrefix = CItem::FindPrefix(NewPrefix);

		if ( !AddPrefix )
			return 0;

		*(DWORD *)((int)IItem.GetOffset() + 44) = AddPrefix;
		CDBSocket::Write(19,"ddbb",IItem.GetIID(),IPlayer.GetID(),NewPrefix);

		if ( CheckPolish )
			CItem::SubState((int)IItem.GetOffset(),64);

		CItem::SendItemInfo(IItem.GetOffset(), (int)IPlayer.GetOffset(), 92);
	}

	return 1;
}