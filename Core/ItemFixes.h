void __fastcall ModsItemPutInfo(void *_this, void *_edx, char **spec, int a3)
{
	unsigned long *v4 = (unsigned long*)_this;
	if (!a3) a3 = v4[13];
	*spec = CItem::PutDword(*spec, v4[9]);
	*spec = CItem::PutWord(*spec, *(short*)(v4[10] + 64));
	int v3;
	if (v4[11]) v3 = *(int*)(v4[11] + 32);
	else v3 = 0;
	*spec = CItem::PutByte(*spec, v3);
	*spec = CItem::PutDword(*spec, v4[12]);
	*spec = CItem::PutDword(*spec, a3);

	for(int i=0; i < 11; i++)
		*spec = CItem::PutByte(*spec, 0);
}

void __fastcall ModsSendStallList(void *player, void *_edx, char* packet)
{
	Interface<ITools> Tools;
	unsigned char type, pType, Items;
	unsigned long id, version;
	packet = Tools->ParseData(packet+2, "bbddb", &type, &pType, &id, &version, &Items);
	size_t Size = Items * 67;
	char *Packet = new char[Size];
	ZeroMemory(Packet, Size);
	void *GetPlayer = CPlayer::FindPlayer(id);

	for(unsigned char i=0; i < Items; i++)
	{
		unsigned short index;
		unsigned long iid;
		unsigned char prefix;
		unsigned long info, amount;
		unsigned char maxend, curend, setgem, xatk, xmagic, xdefense, xhit, xevasion;
		unsigned short xprotect;
		unsigned char upgrlvl, upgrrate;
		unsigned long price;
		unsigned char x=0,y=0,z=0,dsstype=0,eva=0,otp=0,hpinc=0,mpinc=0,str=0,hp=0,intel=0,wis=0,agi=0,a=0,dg1stat=0,dg1type=0,dg2stat=0,dg2type=0,PerfShotCheck=0;
		unsigned long remaintime=0,QigongGrade=0;
		unsigned short phyatk=0,magatk=0,def=0,absorb=0;

		packet = Tools->ParseData(packet, "dwbddbbbbbbbbbbbd", &iid, &index, &prefix, &info, &amount, &maxend, &curend, &setgem, &xatk,
			&xmagic, &xdefense, &xhit, &xevasion, &xprotect, &upgrlvl, &upgrrate, &price);

		int Value = 0, Item = 0;
		Undefined::CreateMonsterValue((char*)GetPlayer + 1068, (int)&Value, (int)&iid);
		int Recheck = 0, Check = 0;
		Check = Undefined::Check((int)((char*)GetPlayer + 1068), (int)&Recheck);

		if (Undefined::CheckValues(&Value, Check))
		{
			Item = *(DWORD*)(Undefined::GetValue(&Value) + 4);
			IItem IItem((void*)Item);

			if (IItem.GetType() == -2 || IItem.GetType() == 19 || IItem.GetType() == 0 || IItem.GetType() == -3 || IItem.GetType() == -1)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; phyatk = 17; magatk = 17; agi = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; phyatk = 17; magatk = 17; wis = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; phyatk = 17; magatk = 17; intel = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; phyatk = 17; magatk = 17; hp = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; phyatk = 17; magatk = 17; str = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; phyatk = 14; magatk = 14; agi = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; phyatk = 14; magatk = 14; wis = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; phyatk = 14; magatk = 14; intel = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; phyatk = 14; magatk = 14; hp = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; phyatk = 14; magatk = 14; str = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; phyatk = 12; magatk = 12; agi = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; phyatk = 12; magatk = 12; wis = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; phyatk = 12; magatk = 12; intel = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; phyatk = 12; magatk = 12; hp = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; phyatk = 12; magatk = 12; str = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; phyatk = 10; magatk = 10; agi = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; phyatk = 10; magatk = 10; wis = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; phyatk = 10; magatk = 10; intel = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; phyatk = 10; magatk = 10; hp = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; phyatk = 10; magatk = 10; str = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; phyatk = 8; magatk = 8; agi = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; phyatk = 8; magatk = 8; wis = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; phyatk = 8; magatk = 8; intel = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; phyatk = 8; magatk = 8; hp = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; phyatk = 8; magatk = 8; str = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; phyatk = 6; magatk = 6; agi = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; phyatk = 6; magatk = 6; wis = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; phyatk = 6; magatk = 6; intel = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; phyatk = 6; magatk = 6; hp = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; phyatk = 6; magatk = 6; str = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; phyatk = 4; magatk = 4; agi = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; phyatk = 4; magatk = 4; wis = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; phyatk = 4; magatk = 4; intel = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; phyatk = 4; magatk = 4; hp = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; phyatk = 4; magatk = 4; str = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; phyatk = 2; magatk = 2; agi = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; phyatk = 2; magatk = 2; wis = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; phyatk = 2; magatk = 2; intel = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; phyatk = 2; magatk = 2; hp = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; phyatk = 2; magatk = 2; str = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				}
			}

			if (IItem.GetType() >= 1 && IItem.GetType() <= 6)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; def = 18; agi = 7;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; def = 18; wis = 7;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; def = 18; intel = 7;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; def = 18; hp = 7;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; def = 18; str = 7;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; def = 16; agi = 5;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; def = 16; wis = 5;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; def = 16; intel = 5;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; def = 16; hp = 5;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; def = 16; str = 5;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; def = 14; agi = 3;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; def = 14; wis = 3;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; def = 14; intel = 3;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; def = 14; hp = 3;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; def = 14; str = 3;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; def = 12; agi = 3;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; def = 12; wis = 3;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; def = 12; intel = 3;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; def = 12; hp = 3;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; def = 12; str = 3;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; def = 10; agi = 2;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; def = 10; wis = 2;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; def = 10; intel = 2;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; def = 10; hp = 2;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; def = 10; str = 2;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; def = 8; agi = 2;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; def = 8; wis = 2;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; def = 8; intel = 2;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; def = 8; hp = 2;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; def = 8; str = 2;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; def = 6; agi = 1;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; def = 6; wis = 1;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; def = 6; intel = 1;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; def = 6; hp = 1;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; def = 6; str = 1;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; def = 4; agi = 1;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; def = 4; wis = 1;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; def = 4; intel = 1;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; def = 4; hp = 1;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; def = 4; str = 1;
				}
			}
		}

		int ItemStat = GetItemStat.find(iid)->second;

		if (GetItemStat.count(iid))
		{
			PerfShotCheck = GetItemStat.find(iid)->second / 100000000;
			ItemStat -= (100000000 * PerfShotCheck);
		}

		if (ItemStat)
		{
			int dg1typecheck = ItemStat / 10000000;
			if (dg1typecheck) dg1stat = 1;
			if (dg1typecheck > 0) dg1type = (dg1typecheck - 1);
			ItemStat -= (10000000 * dg1typecheck);
		}

		if (ItemStat)
		{
			int dg1statcheck = ItemStat / 1000000;
			if (dg1statcheck > 0) dg1stat = (dg1statcheck + 1);
			ItemStat -= (1000000 * dg1statcheck);
		}

		if (ItemStat)
		{
			int dg2typecheck = ItemStat / 100000;
			if (dg2typecheck) dg2stat = 1;
			if (dg2typecheck > 0) dg2type = (dg2typecheck - 1);
			ItemStat -= (100000 * dg2typecheck);
		}

		if (ItemStat)
		{
			int dg2statcheck = ItemStat / 10000;
			if (dg2statcheck > 0) dg2stat = (dg2statcheck + 1);
			ItemStat -= (10000 * dg2statcheck);
		}

		if (ItemStat && index >= 2986 && index <= 3009)
		{
			int yinyanggrade = ItemStat / 100;
			prefix = yinyanggrade + 1;
			ItemStat -= (100 * yinyanggrade);
		}

		if (ItemStat)
			QigongGrade = ItemStat % 100;

		if (index >= 3199 && index <= 3201 && prefix == 0)
			prefix = 1;

		if (index >= 2986 && index <= 3009 && prefix == 0)
			prefix = 1;

		if (index >= 3018 && index <= 3020)
			prefix = GetItemStat.find(iid)->second / 1000;

		Tools->Compile(Packet + i*67, "wdbddbbbbbbbbwbbbbbdbwwwwbbbbbbbbbbdbbwbbd",index, iid, prefix, info, amount, maxend, curend,
			setgem, xatk, xmagic, xdefense, xhit, xevasion, xprotect, upgrlvl, upgrrate, x, y, z, remaintime, dsstype, phyatk, magatk, def, absorb, eva, otp, hpinc, mpinc, str, hp, intel, wis, agi, PerfShotCheck, QigongGrade, dg1stat, dg1type, a, dg2stat, dg2type, price);
	}

	CPlayer::Write(player, type, "bddbbm", pType, id, version, Items, 0, Packet, Size);
	delete[] Packet;
}

void __fastcall ModsSendTradeList(void *player, void *_edx, char* packet)
{
	Interface<ITools> Tools;
	unsigned char type = packet[2];
	unsigned char Items = packet[3];
	packet += 4;
	size_t Size = Items * 63;
	char *Packet = new char[Size];
	ZeroMemory(Packet, Size);
	void *GetPlayer = *(void**)((int)player + 120);

	for(unsigned char i=0; i < Items; i++)
	{
		unsigned short index;
		unsigned long iid;
		unsigned char prefix;
		unsigned long info, amount;
		unsigned char maxend, curend, setgem, xatk, xmagic, xdefense, xhit, xevasion;
		unsigned short xprotect;
		unsigned char upgrlvl, upgrrate;
		unsigned char x=0,y=0,z=0,dsstype=0,eva=0,otp=0,hpinc=0,mpinc=0,str=0,hp=0,intel=0,wis=0,agi=0,a=0,dg1stat=0,dg1type=0,dg2stat=0,dg2type=0,PerfShotCheck=0;
		unsigned long remaintime=0,QigongGrade=0;
		unsigned short phyatk=0,magatk=0,def=0,absorb=0;

		packet = Tools->ParseData(packet, "dwbddbbbbbbbbbbb", &iid, &index, &prefix, &info, &amount, &maxend, &curend, &setgem, &xatk,
			&xmagic, &xdefense, &xhit, &xevasion, &xprotect, &upgrlvl, &upgrrate);

		int CurrentPlayer = CTrade::GetOther(*(DWORD*)((int)GetPlayer + 1100),(int)GetPlayer);
		int Value = 0, Itemxx = 0;
		Undefined::CreateMonsterValue((char*)CurrentPlayer + 1068, (int)&Value, (int)&iid);
		int Recheck = 0, Check = 0;
		Check = Undefined::Check((int)((char*)CurrentPlayer + 1068), (int)&Recheck);

		if (Undefined::CheckValues(&Value, Check))
		{
			Itemxx = *(DWORD*)(Undefined::GetValue(&Value) + 4);
			IItem IItem((void*)Itemxx);

			if (IItem.GetType() == -2 || IItem.GetType() == 19 || IItem.GetType() == 0 || IItem.GetType() == -3 || IItem.GetType() == -1)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; phyatk = 17; magatk = 17; agi = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; phyatk = 17; magatk = 17; wis = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; phyatk = 17; magatk = 17; intel = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; phyatk = 17; magatk = 17; hp = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; phyatk = 17; magatk = 17; str = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; phyatk = 14; magatk = 14; agi = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; phyatk = 14; magatk = 14; wis = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; phyatk = 14; magatk = 14; intel = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; phyatk = 14; magatk = 14; hp = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; phyatk = 14; magatk = 14; str = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; phyatk = 12; magatk = 12; agi = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; phyatk = 12; magatk = 12; wis = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; phyatk = 12; magatk = 12; intel = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; phyatk = 12; magatk = 12; hp = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; phyatk = 12; magatk = 12; str = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; phyatk = 10; magatk = 10; agi = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; phyatk = 10; magatk = 10; wis = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; phyatk = 10; magatk = 10; intel = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; phyatk = 10; magatk = 10; hp = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; phyatk = 10; magatk = 10; str = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; phyatk = 8; magatk = 8; agi = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; phyatk = 8; magatk = 8; wis = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; phyatk = 8; magatk = 8; intel = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; phyatk = 8; magatk = 8; hp = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; phyatk = 8; magatk = 8; str = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; phyatk = 6; magatk = 6; agi = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; phyatk = 6; magatk = 6; wis = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; phyatk = 6; magatk = 6; intel = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; phyatk = 6; magatk = 6; hp = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; phyatk = 6; magatk = 6; str = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; phyatk = 4; magatk = 4; agi = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; phyatk = 4; magatk = 4; wis = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; phyatk = 4; magatk = 4; intel = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; phyatk = 4; magatk = 4; hp = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; phyatk = 4; magatk = 4; str = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; phyatk = 2; magatk = 2; agi = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; phyatk = 2; magatk = 2; wis = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; phyatk = 2; magatk = 2; intel = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; phyatk = 2; magatk = 2; hp = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; phyatk = 2; magatk = 2; str = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				}
			}

			if (IItem.GetType() >= 1 && IItem.GetType() <= 6)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; def = 18; agi = 7;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; def = 18; wis = 7;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; def = 18; intel = 7;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; def = 18; hp = 7;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; def = 18; str = 7;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; def = 16; agi = 5;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; def = 16; wis = 5;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; def = 16; intel = 5;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; def = 16; hp = 5;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; def = 16; str = 5;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; def = 14; agi = 3;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; def = 14; wis = 3;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; def = 14; intel = 3;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; def = 14; hp = 3;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; def = 14; str = 3;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; def = 12; agi = 3;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; def = 12; wis = 3;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; def = 12; intel = 3;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; def = 12; hp = 3;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; def = 12; str = 3;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; def = 10; agi = 2;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; def = 10; wis = 2;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; def = 10; intel = 2;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; def = 10; hp = 2;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; def = 10; str = 2;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; def = 8; agi = 2;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; def = 8; wis = 2;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; def = 8; intel = 2;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; def = 8; hp = 2;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; def = 8; str = 2;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; def = 6; agi = 1;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; def = 6; wis = 1;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; def = 6; intel = 1;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; def = 6; hp = 1;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; def = 6; str = 1;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; def = 4; agi = 1;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; def = 4; wis = 1;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; def = 4; intel = 1;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; def = 4; hp = 1;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; def = 4; str = 1;
				}
			}
		}

		int ItemStat = GetItemStat.find(iid)->second;

		if (GetItemStat.count(iid))
		{
			PerfShotCheck = GetItemStat.find(iid)->second / 100000000;
			ItemStat -= (100000000 * PerfShotCheck);
		}

		if (ItemStat)
		{
			int dg1typecheck = ItemStat / 10000000;
			if (dg1typecheck) dg1stat = 1;
			if (dg1typecheck > 0) dg1type = (dg1typecheck - 1);
			ItemStat -= (10000000 * dg1typecheck);
		}

		if (ItemStat)
		{
			int dg1statcheck = ItemStat / 1000000;
			if (dg1statcheck > 0) dg1stat = (dg1statcheck + 1);
			ItemStat -= (1000000 * dg1statcheck);
		}

		if (ItemStat)
		{
			int dg2typecheck = ItemStat / 100000;
			if (dg2typecheck) dg2stat = 1;
			if (dg2typecheck > 0) dg2type = (dg2typecheck - 1);
			ItemStat -= (100000 * dg2typecheck);
		}

		if (ItemStat)
		{
			int dg2statcheck = ItemStat / 10000;
			if (dg2statcheck > 0) dg2stat = (dg2statcheck + 1);
			ItemStat -= (10000 * dg2statcheck);
		}

		if (ItemStat && index >= 2986 && index <= 3009)
		{
			int yinyanggrade = ItemStat / 100;
			prefix = yinyanggrade + 1;
			ItemStat -= (100 * yinyanggrade);
		}

		if (ItemStat)
			QigongGrade = ItemStat % 100;

		if (index >= 3199 && index <= 3201 && prefix == 0)
			prefix = 1;

		if (index >= 2986 && index <= 3009 && prefix == 0)
			prefix = 1;

		if (index >= 3018 && index <= 3020)
			prefix = GetItemStat.find(iid)->second / 1000;

		Tools->Compile(Packet + i*63, "wdbddbbbbbbbbwbbbbbdbwwwwbbbbbbbbbbdbbwbb",index, iid, prefix, info, amount, maxend, curend,
			setgem, xatk, xmagic, xdefense, xhit, xevasion, xprotect, upgrlvl, upgrrate, x, y, z, remaintime, dsstype, phyatk, magatk, def, absorb, eva, otp, hpinc, mpinc, str, hp, intel, wis, agi, PerfShotCheck, QigongGrade, dg1stat, dg1type, a, dg2stat, dg2type);
	}

	CDBSocket::ProcessHtml((int)player, type, (int)"bbm", Items, 0, Packet, Size);
	delete[] Packet;
}

void __fastcall ModsSendStorageList(void *player, void *_edx, char* packet)
{
	Interface<ITools> Tools;
	unsigned char type = packet[2];
	unsigned char Items = packet[3];
	packet += 4;
	size_t Size = Items * 63;
	char *Packet = new char[Size];
	ZeroMemory(Packet, Size);
	void *GetPlayer = *(void**)((int)player + 120);

	for(unsigned char i=0; i < Items; i++)
	{
		unsigned short index;
		unsigned long iid;
		unsigned char prefix;
		unsigned long info, amount;
		unsigned char maxend, curend, setgem, xatk, xmagic, xdefense, xhit, xevasion;
		unsigned short xprotect;
		unsigned char upgrlvl, upgrrate;
		unsigned char x=0,y=0,z=0,dsstype=0,eva=0,otp=0,hpinc=0,mpinc=0,str=0,hp=0,intel=0,wis=0,agi=0,a=0,dg1stat=0,dg1type=0,dg2stat=0,dg2type=0,PerfShotCheck=0;
		unsigned long remaintime=0,QigongGrade=0;
		unsigned short phyatk=0,magatk=0,def=0,absorb=0;

		packet = Tools->ParseData(packet, "wdbddbbbbbbbbbbb", &index, &iid, &prefix, &info, &amount, &maxend, &curend, &setgem, &xatk,
			&xmagic, &xdefense, &xhit, &xevasion, &xprotect, &upgrlvl, &upgrrate);

		int Value = 0, Item = 0;
		Undefined::CreateMonsterValueNew((char*)GetPlayer + 1128, (int)&Value, (int)&iid);
		int Recheck = 0, Check = 0;
		Check = Undefined::Check((int)((char*)GetPlayer + 1128), (int)&Recheck);

		if (*(DWORD*)&Value != *(DWORD*)Check)
		{
			Item = Undefined::GetValue(&Value);
			int GetNewItem = Item + 4;
			int RealItem = Undefined::NewGetItem(*((DWORD*)GetPlayer + 113), (int)&GetNewItem);
			IItem IItem((void*)RealItem);

			if (IItem.GetType() == -2 || IItem.GetType() == 19 || IItem.GetType() == 0 || IItem.GetType() == -3 || IItem.GetType() == -1)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; phyatk = 17; magatk = 17; agi = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; phyatk = 17; magatk = 17; wis = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; phyatk = 17; magatk = 17; intel = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; phyatk = 17; magatk = 17; hp = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; phyatk = 17; magatk = 17; str = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; phyatk = 14; magatk = 14; agi = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; phyatk = 14; magatk = 14; wis = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; phyatk = 14; magatk = 14; intel = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; phyatk = 14; magatk = 14; hp = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; phyatk = 14; magatk = 14; str = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; phyatk = 12; magatk = 12; agi = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; phyatk = 12; magatk = 12; wis = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; phyatk = 12; magatk = 12; intel = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; phyatk = 12; magatk = 12; hp = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; phyatk = 12; magatk = 12; str = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; phyatk = 10; magatk = 10; agi = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; phyatk = 10; magatk = 10; wis = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; phyatk = 10; magatk = 10; intel = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; phyatk = 10; magatk = 10; hp = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; phyatk = 10; magatk = 10; str = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; phyatk = 8; magatk = 8; agi = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; phyatk = 8; magatk = 8; wis = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; phyatk = 8; magatk = 8; intel = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; phyatk = 8; magatk = 8; hp = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; phyatk = 8; magatk = 8; str = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; phyatk = 6; magatk = 6; agi = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; phyatk = 6; magatk = 6; wis = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; phyatk = 6; magatk = 6; intel = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; phyatk = 6; magatk = 6; hp = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; phyatk = 6; magatk = 6; str = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; phyatk = 4; magatk = 4; agi = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; phyatk = 4; magatk = 4; wis = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; phyatk = 4; magatk = 4; intel = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; phyatk = 4; magatk = 4; hp = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; phyatk = 4; magatk = 4; str = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; phyatk = 2; magatk = 2; agi = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; phyatk = 2; magatk = 2; wis = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; phyatk = 2; magatk = 2; intel = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; phyatk = 2; magatk = 2; hp = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; phyatk = 2; magatk = 2; str = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				}
			}

			if (IItem.GetType() >= 1 && IItem.GetType() <= 6)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; def = 18; agi = 7;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; def = 18; wis = 7;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; def = 18; intel = 7;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; def = 18; hp = 7;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; def = 18; str = 7;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; def = 16; agi = 5;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; def = 16; wis = 5;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; def = 16; intel = 5;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; def = 16; hp = 5;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; def = 16; str = 5;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; def = 14; agi = 3;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; def = 14; wis = 3;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; def = 14; intel = 3;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; def = 14; hp = 3;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; def = 14; str = 3;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; def = 12; agi = 3;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; def = 12; wis = 3;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; def = 12; intel = 3;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; def = 12; hp = 3;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; def = 12; str = 3;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; def = 10; agi = 2;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; def = 10; wis = 2;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; def = 10; intel = 2;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; def = 10; hp = 2;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; def = 10; str = 2;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; def = 8; agi = 2;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; def = 8; wis = 2;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; def = 8; intel = 2;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; def = 8; hp = 2;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; def = 8; str = 2;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; def = 6; agi = 1;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; def = 6; wis = 1;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; def = 6; intel = 1;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; def = 6; hp = 1;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; def = 6; str = 1;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; def = 4; agi = 1;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; def = 4; wis = 1;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; def = 4; intel = 1;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; def = 4; hp = 1;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; def = 4; str = 1;
				}
			}
		}

		int ItemStat = GetItemStat.find(iid)->second;

		if (GetItemStat.count(iid))
		{
			PerfShotCheck = GetItemStat.find(iid)->second / 100000000;
			ItemStat -= (100000000 * PerfShotCheck);
		}

		if (ItemStat)
		{
			int dg1typecheck = ItemStat / 10000000;
			if (dg1typecheck) dg1stat = 1;
			if (dg1typecheck > 0) dg1type = (dg1typecheck - 1);
			ItemStat -= (10000000 * dg1typecheck);
		}

		if (ItemStat)
		{
			int dg1statcheck = ItemStat / 1000000;
			if (dg1statcheck > 0) dg1stat = (dg1statcheck + 1);
			ItemStat -= (1000000 * dg1statcheck);
		}

		if (ItemStat)
		{
			int dg2typecheck = ItemStat / 100000;
			if (dg2typecheck) dg2stat = 1;
			if (dg2typecheck > 0) dg2type = (dg2typecheck - 1);
			ItemStat -= (100000 * dg2typecheck);
		}

		if (ItemStat)
		{
			int dg2statcheck = ItemStat / 10000;
			if (dg2statcheck > 0) dg2stat = (dg2statcheck + 1);
			ItemStat -= (10000 * dg2statcheck);
		}

		if (ItemStat && index >= 2986 && index <= 3009)
		{
			int yinyanggrade = ItemStat / 100;
			prefix = yinyanggrade + 1;
			ItemStat -= (100 * yinyanggrade);
		}

		if (ItemStat)
			QigongGrade = ItemStat % 100;

		if (index >= 3199 && index <= 3201 && prefix == 0)
			prefix = 1;

		if (index >= 2986 && index <= 3009 && prefix == 0)
			prefix = 1;

		if (index >= 3018 && index <= 3020)
			prefix = GetItemStat.find(iid)->second / 1000;

		Tools->Compile(Packet + i*63, "wdbddbbbbbbbbwbbbbbdbwwwwbbbbbbbbbbdbbwbb",index, iid, prefix, info, amount, maxend, curend,
			setgem, xatk, xmagic, xdefense, xhit, xevasion, xprotect, upgrlvl, upgrrate, x, y, z, remaintime, dsstype, phyatk, magatk, def, absorb, eva, otp, hpinc, mpinc, str, hp, intel, wis, agi, PerfShotCheck, QigongGrade, dg1stat, dg1type, a, dg2stat, dg2type);
	}

	CDBSocket::ProcessHtml((int)player, type, (int)"bm", Items, Packet, Size);
	delete[] Packet;
}

void __fastcall ModsSendItemInfo(void *player, void *_edx, char* Inventory)
{
	Interface<ITools> Tools;
	unsigned char type = Inventory[2];
	unsigned char Items = Inventory[3];
	Inventory += 4;
	char *FindSize = Inventory;
	char *WriteWear = Inventory;
	unsigned char WearAmount = 0;
	unsigned char FixedLoop = 0;

	for(unsigned char i = 0; i < Items; i++)
	{
		unsigned short index;
		unsigned long iid;
		unsigned char prefix;
		unsigned long info, amount;
		unsigned char maxend, curend, setgem, xatk, xmagic, xdefense, xhit, xevasion;
		unsigned short xprotect;
		unsigned char upgrlvl, upgrrate;
		unsigned char x=0,y=0,z=0,dsstype=0,eva=0,otp=0,hpinc=0,mpinc=0,str=0,hp=0,intel=0,wis=0,agi=0,a=0,dg1stat=0,dg1type=0,dg2stat=0,dg2type=0,PerfShotCheck=0;
		unsigned long remaintime=0,QigongGrade=0;
		unsigned short phyatk=0,magatk=0,def=0,absorb=0;
		FindSize = Tools->ParseData(FindSize, "dwbddbbbbbbbbbbb", &iid, &index, &prefix, &info, &amount, &maxend, &curend, &setgem, &xatk, &xmagic, &xdefense, &xhit, &xevasion, &xprotect, &upgrlvl, &upgrrate);
		if (info & 1) WearAmount += 1;
	}

	size_t ShowWear = WearAmount * 63;
	char *xPacket = new char[ShowWear];

	for(unsigned char i = 0; i < Items; i++)
	{
		unsigned short index;
		unsigned long iid;
		unsigned char prefix;
		unsigned long info, amount;
		unsigned char maxend, curend, setgem, xatk, xmagic, xdefense, xhit, xevasion;
		unsigned short xprotect;
		unsigned char upgrlvl, upgrrate;
		unsigned char x=0,y=0,z=0,dsstype=0,eva=0,otp=0,hpinc=0,mpinc=0,str=0,hp=0,intel=0,wis=0,agi=0,a=0,dg1stat=0,dg1type=0,dg2stat=0,dg2type=0,PerfShotCheck=0;
		unsigned long remaintime=0,QigongGrade=0;
		unsigned short phyatk=0,magatk=0,def=0,absorb=0;

		WriteWear = Tools->ParseData(WriteWear, "dwbddbbbbbbbbbbb", &iid, &index, &prefix, &info, &amount, &maxend, &curend, &setgem, &xatk,
			&xmagic, &xdefense, &xhit, &xevasion, &xprotect, &upgrlvl, &upgrrate);

		int Value = 0, Itemxx = 0;
		Undefined::CreateMonsterValue((char*)player + 1068, (int)&Value, (int)&iid);
		int Recheck = 0, Check = 0;
		Check = Undefined::Check((int)((char*)player + 1068), (int)&Recheck);

		if (Undefined::CheckValues(&Value, Check))
		{
			Itemxx = *(DWORD*)(Undefined::GetValue(&Value) + 4);
			IItem IItem((void*)Itemxx);

			if (IItem.GetType() == -2 || IItem.GetType() == 19 || IItem.GetType() == 0 || IItem.GetType() == -3 || IItem.GetType() == -1)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; phyatk = 17; magatk = 17; agi = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; phyatk = 17; magatk = 17; wis = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; phyatk = 17; magatk = 17; intel = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; phyatk = 17; magatk = 17; hp = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; phyatk = 17; magatk = 17; str = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; phyatk = 14; magatk = 14; agi = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; phyatk = 14; magatk = 14; wis = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; phyatk = 14; magatk = 14; intel = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; phyatk = 14; magatk = 14; hp = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; phyatk = 14; magatk = 14; str = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; phyatk = 12; magatk = 12; agi = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; phyatk = 12; magatk = 12; wis = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; phyatk = 12; magatk = 12; intel = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; phyatk = 12; magatk = 12; hp = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; phyatk = 12; magatk = 12; str = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; phyatk = 10; magatk = 10; agi = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; phyatk = 10; magatk = 10; wis = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; phyatk = 10; magatk = 10; intel = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; phyatk = 10; magatk = 10; hp = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; phyatk = 10; magatk = 10; str = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; phyatk = 8; magatk = 8; agi = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; phyatk = 8; magatk = 8; wis = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; phyatk = 8; magatk = 8; intel = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; phyatk = 8; magatk = 8; hp = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; phyatk = 8; magatk = 8; str = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; phyatk = 6; magatk = 6; agi = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; phyatk = 6; magatk = 6; wis = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; phyatk = 6; magatk = 6; intel = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; phyatk = 6; magatk = 6; hp = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; phyatk = 6; magatk = 6; str = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; phyatk = 4; magatk = 4; agi = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; phyatk = 4; magatk = 4; wis = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; phyatk = 4; magatk = 4; intel = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; phyatk = 4; magatk = 4; hp = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; phyatk = 4; magatk = 4; str = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; phyatk = 2; magatk = 2; agi = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; phyatk = 2; magatk = 2; wis = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; phyatk = 2; magatk = 2; intel = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; phyatk = 2; magatk = 2; hp = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; phyatk = 2; magatk = 2; str = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				}
			}

			if (IItem.GetType() >= 1 && IItem.GetType() <= 6)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; def = 18; agi = 7;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; def = 18; wis = 7;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; def = 18; intel = 7;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; def = 18; hp = 7;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; def = 18; str = 7;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; def = 16; agi = 5;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; def = 16; wis = 5;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; def = 16; intel = 5;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; def = 16; hp = 5;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; def = 16; str = 5;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; def = 14; agi = 3;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; def = 14; wis = 3;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; def = 14; intel = 3;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; def = 14; hp = 3;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; def = 14; str = 3;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; def = 12; agi = 3;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; def = 12; wis = 3;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; def = 12; intel = 3;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; def = 12; hp = 3;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; def = 12; str = 3;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; def = 10; agi = 2;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; def = 10; wis = 2;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; def = 10; intel = 2;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; def = 10; hp = 2;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; def = 10; str = 2;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; def = 8; agi = 2;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; def = 8; wis = 2;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; def = 8; intel = 2;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; def = 8; hp = 2;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; def = 8; str = 2;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; def = 6; agi = 1;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; def = 6; wis = 1;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; def = 6; intel = 1;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; def = 6; hp = 1;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; def = 6; str = 1;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; def = 4; agi = 1;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; def = 4; wis = 1;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; def = 4; intel = 1;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; def = 4; hp = 1;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; def = 4; str = 1;
				}
			}
		}

		int ItemStat = GetItemStat.find(iid)->second;

		if (GetItemStat.count(iid))
		{
			PerfShotCheck = GetItemStat.find(iid)->second / 100000000;
			ItemStat -= (100000000 * PerfShotCheck);
		}

		if (ItemStat)
		{
			int dg1typecheck = ItemStat / 10000000;
			if (dg1typecheck) dg1stat = 1;
			if (dg1typecheck > 0) dg1type = (dg1typecheck - 1);
			ItemStat -= (10000000 * dg1typecheck);
		}

		if (ItemStat)
		{
			int dg1statcheck = ItemStat / 1000000;
			if (dg1statcheck > 0) dg1stat = (dg1statcheck + 1);
			ItemStat -= (1000000 * dg1statcheck);
		}

		if (ItemStat)
		{
			int dg2typecheck = ItemStat / 100000;
			if (dg2typecheck) dg2stat = 1;
			if (dg2typecheck > 0) dg2type = (dg2typecheck - 1);
			ItemStat -= (100000 * dg2typecheck);
		}

		if (ItemStat)
		{
			int dg2statcheck = ItemStat / 10000;
			if (dg2statcheck > 0) dg2stat = (dg2statcheck + 1);
			ItemStat -= (10000 * dg2statcheck);
		}

		if (ItemStat && index >= 2986 && index <= 3009)
		{
			int yinyanggrade = ItemStat / 100;
			prefix = yinyanggrade + 1;
			ItemStat -= (100 * yinyanggrade);
		}

		if (ItemStat)
			QigongGrade = ItemStat % 100;

		if (index >= 3199 && index <= 3201 && prefix == 0)
			prefix = 1;

		if (index >= 2986 && index <= 3009 && prefix == 0)
			prefix = 1;

		if (index >= 3018 && index <= 3020)
			prefix = GetItemStat.find(iid)->second / 1000;

		if (index >= 3381 && index <= 3383)
		{
			CPlayer::Write(player,194,"dd",iid,100);
			if (index == 3381) CPlayer::Write(player,193,"ddd",iid,101,10);
			if (index == 3382) CPlayer::Write(player,193,"ddd",iid,101,11);
			if (index == 3383) CPlayer::Write(player,193,"ddd",iid,101,12);

			if (index == 3383 && GetItemStat.find(iid)->second == 0)
				CPlayer::Write(player,193,"ddd",iid,100,GetItemStat.find(iid)->second+2);
			else
				CPlayer::Write(player,193,"ddd",iid,100,GetItemStat.find(iid)->second+1);
		}

		if (index >= 3384 && index <= 3386)
		{
			if (GetItemStat.count(iid))
			{
				int ItemStat = GetItemStat.find(iid)->second;
				int Stat = ItemStat / 1000;
				int Value = ItemStat % 100;
				CPlayer::Write(player,194,"dd",iid,Value);
				CPlayer::Write(player,193,"ddd",iid,Value,Stat);
			}
		}

		if (info & 1)
		{
			Tools->Compile(xPacket + FixedLoop*63, "wdbddbbbbbbbbwbbbbbdbwwwwbbbbbbbbbbdbbwbb",index, iid, prefix, info, amount, maxend, curend, setgem, xatk, xmagic, xdefense, xhit, xevasion, xprotect, upgrlvl, upgrrate, x, y, z, remaintime, dsstype, phyatk, magatk, def, absorb, eva, otp, hpinc, mpinc, str, hp, intel, wis, agi, PerfShotCheck, QigongGrade, dg1stat, dg1type, a, dg2stat, dg2type);
			FixedLoop += 1;
		}
	}

	CPlayer::Write(player, type, "bm", WearAmount, xPacket, ShowWear);
	delete[] xPacket;

	for(unsigned char i = 0; i < Items; i++)
	{
		char Packet[63];
		unsigned short index;
		unsigned long iid;
		unsigned char prefix;
		unsigned long info, amount;
		unsigned char maxend, curend, setgem, xatk, xmagic, xdefense, xhit, xevasion;
		unsigned short xprotect;
		unsigned char upgrlvl, upgrrate;
		unsigned char x=0,y=0,z=0,dsstype=0,eva=0,otp=0,hpinc=0,mpinc=0,str=0,hp=0,intel=0,wis=0,agi=0,a=0,dg1stat=0,dg1type=0,dg2stat=0,dg2type=0,PerfShotCheck=0;
		unsigned long remaintime=0,QigongGrade=0;
		unsigned short phyatk=0,magatk=0,def=0,absorb=0;

		Inventory = Tools->ParseData(Inventory, "dwbddbbbbbbbbbbb", &iid, &index, &prefix, &info, &amount, &maxend, &curend, &setgem, &xatk,
			&xmagic, &xdefense, &xhit, &xevasion, &xprotect, &upgrlvl, &upgrrate);

		int Value = 0, Itemxx = 0;
		Undefined::CreateMonsterValue((char*)player + 1068, (int)&Value, (int)&iid);
		int Recheck = 0, Check = 0;
		Check = Undefined::Check((int)((char*)player + 1068), (int)&Recheck);

		if (Undefined::CheckValues(&Value, Check))
		{
			Itemxx = *(DWORD*)(Undefined::GetValue(&Value) + 4);
			IItem IItem((void*)Itemxx);

			if (IItem.GetType() == -2 || IItem.GetType() == 19 || IItem.GetType() == 0 || IItem.GetType() == -3 || IItem.GetType() == -1)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; phyatk = 17; magatk = 17; agi = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; phyatk = 17; magatk = 17; wis = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; phyatk = 17; magatk = 17; intel = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; phyatk = 17; magatk = 17; hp = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; phyatk = 17; magatk = 17; str = 8;
					hpinc = 250; mpinc = 200;
					if (IItem.GetType() == -1) eva = 18; else otp = 18;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; phyatk = 14; magatk = 14; agi = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; phyatk = 14; magatk = 14; wis = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; phyatk = 14; magatk = 14; intel = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; phyatk = 14; magatk = 14; hp = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; phyatk = 14; magatk = 14; str = 5;
					hpinc = 200; mpinc = 150;
					if (IItem.GetType() == -1) eva = 15; else otp = 15;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; phyatk = 12; magatk = 12; agi = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; phyatk = 12; magatk = 12; wis = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; phyatk = 12; magatk = 12; intel = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; phyatk = 12; magatk = 12; hp = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; phyatk = 12; magatk = 12; str = 3;
					hpinc = 130; mpinc = 110;
					if (IItem.GetType() == -1) eva = 12; else otp = 12;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; phyatk = 10; magatk = 10; agi = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; phyatk = 10; magatk = 10; wis = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; phyatk = 10; magatk = 10; intel = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; phyatk = 10; magatk = 10; hp = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; phyatk = 10; magatk = 10; str = 3;
					hpinc = 110; mpinc = 90;
					if (IItem.GetType() == -1) eva = 10; else otp = 10;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; phyatk = 8; magatk = 8; agi = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; phyatk = 8; magatk = 8; wis = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; phyatk = 8; magatk = 8; intel = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; phyatk = 8; magatk = 8; hp = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; phyatk = 8; magatk = 8; str = 2;
					hpinc = 90; mpinc = 70;
					if (IItem.GetType() == -1) eva = 8; else otp = 8;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; phyatk = 6; magatk = 6; agi = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; phyatk = 6; magatk = 6; wis = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; phyatk = 6; magatk = 6; intel = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; phyatk = 6; magatk = 6; hp = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; phyatk = 6; magatk = 6; str = 2;
					hpinc = 70; mpinc = 50;
					if (IItem.GetType() == -1) eva = 6; else otp = 6;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; phyatk = 4; magatk = 4; agi = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; phyatk = 4; magatk = 4; wis = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; phyatk = 4; magatk = 4; intel = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; phyatk = 4; magatk = 4; hp = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; phyatk = 4; magatk = 4; str = 1;
					hpinc = 50; mpinc = 30;
					if (IItem.GetType() == -1) eva = 4; else otp = 4;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; phyatk = 2; magatk = 2; agi = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; phyatk = 2; magatk = 2; wis = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; phyatk = 2; magatk = 2; intel = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; phyatk = 2; magatk = 2; hp = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; phyatk = 2; magatk = 2; str = 1;
					hpinc = 30; mpinc = 10;
					if (IItem.GetType() == -1) eva = 2; else otp = 2;
				}
			}

			if (IItem.GetType() >= 1 && IItem.GetType() <= 6)
			{
				if (IItem.GetSetGem() == 240)
				{
					dsstype = 1; def = 18; agi = 7;
				} else if (IItem.GetSetGem() == 239)
				{
					dsstype = 1; def = 18; wis = 7;
				} else if (IItem.GetSetGem() == 238)
				{
					dsstype = 1; def = 18; intel = 7;
				} else if (IItem.GetSetGem() == 237)
				{
					dsstype = 1; def = 18; hp = 7;
				} else if (IItem.GetSetGem() == 236)
				{
					dsstype = 1; def = 18; str = 7;
				} else if (IItem.GetSetGem() == 235)
				{
					dsstype = 2; def = 16; agi = 5;
				} else if (IItem.GetSetGem() == 234)
				{
					dsstype = 2; def = 16; wis = 5;
				} else if (IItem.GetSetGem() == 233)
				{
					dsstype = 2; def = 16; intel = 5;
				} else if (IItem.GetSetGem() == 232)
				{
					dsstype = 2; def = 16; hp = 5;
				} else if (IItem.GetSetGem() == 231)
				{
					dsstype = 2; def = 16; str = 5;
				} else if (IItem.GetSetGem() == 230)
				{
					dsstype = 3; def = 14; agi = 3;
				} else if (IItem.GetSetGem() == 229)
				{
					dsstype = 3; def = 14; wis = 3;
				} else if (IItem.GetSetGem() == 228)
				{
					dsstype = 3; def = 14; intel = 3;
				} else if (IItem.GetSetGem() == 227)
				{
					dsstype = 3; def = 14; hp = 3;
				} else if (IItem.GetSetGem() == 226)
				{
					dsstype = 3; def = 14; str = 3;
				} else if (IItem.GetSetGem() == 225)
				{
					dsstype = 4; def = 12; agi = 3;
				} else if (IItem.GetSetGem() == 224)
				{
					dsstype = 4; def = 12; wis = 3;
				} else if (IItem.GetSetGem() == 223)
				{
					dsstype = 4; def = 12; intel = 3;
				} else if (IItem.GetSetGem() == 222)
				{
					dsstype = 4; def = 12; hp = 3;
				} else if (IItem.GetSetGem() == 221)
				{
					dsstype = 4; def = 12; str = 3;
				} else if (IItem.GetSetGem() == 220)
				{
					dsstype = 5; def = 10; agi = 2;
				} else if (IItem.GetSetGem() == 219)
				{
					dsstype = 5; def = 10; wis = 2;
				} else if (IItem.GetSetGem() == 218)
				{
					dsstype = 5; def = 10; intel = 2;
				} else if (IItem.GetSetGem() == 217)
				{
					dsstype = 5; def = 10; hp = 2;
				} else if (IItem.GetSetGem() == 216)
				{
					dsstype = 5; def = 10; str = 2;
				} else if (IItem.GetSetGem() == 215)
				{
					dsstype = 6; def = 8; agi = 2;
				} else if (IItem.GetSetGem() == 214)
				{
					dsstype = 6; def = 8; wis = 2;
				} else if (IItem.GetSetGem() == 213)
				{
					dsstype = 6; def = 8; intel = 2;
				} else if (IItem.GetSetGem() == 212)
				{
					dsstype = 6; def = 8; hp = 2;
				} else if (IItem.GetSetGem() == 211)
				{
					dsstype = 6; def = 8; str = 2;
				} else if (IItem.GetSetGem() == 210)
				{
					dsstype = 7; def = 6; agi = 1;
				} else if (IItem.GetSetGem() == 209)
				{
					dsstype = 7; def = 6; wis = 1;
				} else if (IItem.GetSetGem() == 208)
				{
					dsstype = 7; def = 6; intel = 1;
				} else if (IItem.GetSetGem() == 207)
				{
					dsstype = 7; def = 6; hp = 1;
				} else if (IItem.GetSetGem() == 206)
				{
					dsstype = 7; def = 6; str = 1;
				} else if (IItem.GetSetGem() == 205)
				{
					dsstype = 8; def = 4; agi = 1;
				} else if (IItem.GetSetGem() == 204)
				{
					dsstype = 8; def = 4; wis = 1;
				} else if (IItem.GetSetGem() == 203)
				{
					dsstype = 8; def = 4; intel = 1;
				} else if (IItem.GetSetGem() == 202)
				{
					dsstype = 8; def = 4; hp = 1;
				} else if (IItem.GetSetGem() == 201)
				{
					dsstype = 8; def = 4; str = 1;
				}
			}

			if (!CBase::IsDeleted((int)player) && IItem.GetType() == -3 && otp && *(DWORD*)((int)player + 460) == 4)
			{
				eva = otp;
				otp = 0;
			}
		}

		int ItemStat = GetItemStat.find(iid)->second;

		if (GetItemStat.count(iid))
		{
			PerfShotCheck = GetItemStat.find(iid)->second / 100000000;
			ItemStat -= (100000000 * PerfShotCheck);
		}

		if (ItemStat)
		{
			int dg1typecheck = ItemStat / 10000000;
			if (dg1typecheck) dg1stat = 1;
			if (dg1typecheck > 0) dg1type = (dg1typecheck - 1);
			ItemStat -= (10000000 * dg1typecheck);
		}

		if (ItemStat)
		{
			int dg1statcheck = ItemStat / 1000000;
			if (dg1statcheck > 0) dg1stat = (dg1statcheck + 1);
			ItemStat -= (1000000 * dg1statcheck);
		}

		if (ItemStat)
		{
			int dg2typecheck = ItemStat / 100000;
			if (dg2typecheck) dg2stat = 1;
			if (dg2typecheck > 0) dg2type = (dg2typecheck - 1);
			ItemStat -= (100000 * dg2typecheck);
		}

		if (ItemStat)
		{
			int dg2statcheck = ItemStat / 10000;
			if (dg2statcheck > 0) dg2stat = (dg2statcheck + 1);
			ItemStat -= (10000 * dg2statcheck);
		}

		if (ItemStat && index >= 2986 && index <= 3009)
		{
			int yinyanggrade = ItemStat / 100;
			prefix = yinyanggrade + 1;
			ItemStat -= (100 * yinyanggrade);
		}

		if (ItemStat)
			QigongGrade = ItemStat % 100;

		if (index >= 3199 && index <= 3201 && prefix == 0)
			prefix = 1;

		if (index >= 2986 && index <= 3009 && prefix == 0)
			prefix = 1;

		if (index >= 3018 && index <= 3020)
			prefix = GetItemStat.find(iid)->second / 1000;

		if (index >= 3381 && index <= 3383)
		{
			CPlayer::Write(player,194,"dd",iid,100);
			if (index == 3381) CPlayer::Write(player,193,"ddd",iid,101,10);
			if (index == 3382) CPlayer::Write(player,193,"ddd",iid,101,11);
			if (index == 3383) CPlayer::Write(player,193,"ddd",iid,101,12);

			if (index == 3383 && GetItemStat.find(iid)->second == 0)
				CPlayer::Write(player,193,"ddd",iid,100,GetItemStat.find(iid)->second+2);
			else
				CPlayer::Write(player,193,"ddd",iid,100,GetItemStat.find(iid)->second+1);
		}

		if (index >= 3384 && index <= 3386)
		{
			if (GetItemStat.count(iid))
			{
				int ItemStat = GetItemStat.find(iid)->second;
				int Stat = ItemStat / 1000;
				int Value = ItemStat % 100;
				CPlayer::Write(player,194,"dd",iid,Value);
				CPlayer::Write(player,193,"ddd",iid,Value,Stat);
			}
		}

		Tools->Compile(Packet, "wdbddbbbbbbbbwbbbbbdbwwwwbbbbbbbbbbdbbwbb",index, iid, prefix, info, amount, maxend, curend, setgem, xatk, xmagic, xdefense, xhit, xevasion, xprotect, upgrlvl, upgrrate, x, y, z, remaintime, dsstype, phyatk, magatk, def, absorb, eva, otp, hpinc, mpinc, str, hp, intel, wis, agi, PerfShotCheck, QigongGrade, dg1stat, dg1type, a, dg2stat, dg2type);
		if (info & 1)
			int nothing = 0;
		else
			CPlayer::Write(player, 7, "m", Packet, 63);
	}
}

void __fastcall ModsSendUpdateItemInfo(void *player, void *_edx, char* Item)
{
	Interface<ITools> Tools;
	char Type = Item[2];
	char *Packet = new char[63];
	unsigned short index;
	unsigned long iid;
	unsigned char prefix;
	unsigned long info, amount;
	unsigned char maxend, curend, setgem, xatk, xmagic, xdefense, xhit, xevasion;
	unsigned short xprotect;
	unsigned char upgrlvl, upgrrate;
	unsigned char x=0,y=0,z=0,dsstype=0,eva=0,otp=0,hpinc=0,mpinc=0,str=0,hp=0,intel=0,wis=0,agi=0,a=0,dg1stat=0,dg1type=0,dg2stat=0,dg2type=0,PerfShotCheck=0;
	unsigned long remaintime=0,QigongGrade=0;
	unsigned short phyatk=0,magatk=0,def=0,absorb=0;

	Tools->ParseData(Item+3, "dwbddbbbbbbbbbbb", &iid, &index, &prefix, &info, &amount, &maxend, &curend, &setgem, &xatk,
		&xmagic, &xdefense, &xhit, &xevasion, &xprotect, &upgrlvl, &upgrrate);

	int xValue = 0, xItem = 0;
	Undefined::CreateMonsterValueNew((char*)player + 1128, (int)&xValue, (int)&iid);
	int xRecheck = 0, xCheck = 0;
	xCheck = Undefined::Check((int)((char*)player + 1128), (int)&xRecheck);

	if (*(DWORD*)&xValue != *(DWORD*)xCheck)
	{
		xItem = Undefined::GetValue(&xValue);
		int xGetNewItem = xItem + 4;
		int xRealItem = Undefined::NewGetItem(*((DWORD*)player + 113), (int)&xGetNewItem);
		IItem IItem((void*)xRealItem);

		if (IItem.GetType() == -2 || IItem.GetType() == 19 || IItem.GetType() == 0 || IItem.GetType() == -3 || IItem.GetType() == -1)
		{
			if (IItem.GetSetGem() == 240)
			{
				dsstype = 1; phyatk = 17; magatk = 17; agi = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 239)
			{
				dsstype = 1; phyatk = 17; magatk = 17; wis = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 238)
			{
				dsstype = 1; phyatk = 17; magatk = 17; intel = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 237)
			{
				dsstype = 1; phyatk = 17; magatk = 17; hp = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 236)
			{
				dsstype = 1; phyatk = 17; magatk = 17; str = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 235)
			{
				dsstype = 2; phyatk = 14; magatk = 14; agi = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 234)
			{
				dsstype = 2; phyatk = 14; magatk = 14; wis = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 233)
			{
				dsstype = 2; phyatk = 14; magatk = 14; intel = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 232)
			{
				dsstype = 2; phyatk = 14; magatk = 14; hp = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 231)
			{
				dsstype = 2; phyatk = 14; magatk = 14; str = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 230)
			{
				dsstype = 3; phyatk = 12; magatk = 12; agi = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 229)
			{
				dsstype = 3; phyatk = 12; magatk = 12; wis = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 228)
			{
				dsstype = 3; phyatk = 12; magatk = 12; intel = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 227)
			{
				dsstype = 3; phyatk = 12; magatk = 12; hp = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 226)
			{
				dsstype = 3; phyatk = 12; magatk = 12; str = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 225)
			{
				dsstype = 4; phyatk = 10; magatk = 10; agi = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 224)
			{
				dsstype = 4; phyatk = 10; magatk = 10; wis = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 223)
			{
				dsstype = 4; phyatk = 10; magatk = 10; intel = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 222)
			{
				dsstype = 4; phyatk = 10; magatk = 10; hp = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 221)
			{
				dsstype = 4; phyatk = 10; magatk = 10; str = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 220)
			{
				dsstype = 5; phyatk = 8; magatk = 8; agi = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 219)
			{
				dsstype = 5; phyatk = 8; magatk = 8; wis = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 218)
			{
				dsstype = 5; phyatk = 8; magatk = 8; intel = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 217)
			{
				dsstype = 5; phyatk = 8; magatk = 8; hp = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 216)
			{
				dsstype = 5; phyatk = 8; magatk = 8; str = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 215)
			{
				dsstype = 6; phyatk = 6; magatk = 6; agi = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 214)
			{
				dsstype = 6; phyatk = 6; magatk = 6; wis = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 213)
			{
				dsstype = 6; phyatk = 6; magatk = 6; intel = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 212)
			{
				dsstype = 6; phyatk = 6; magatk = 6; hp = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 211)
			{
				dsstype = 6; phyatk = 6; magatk = 6; str = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 210)
			{
				dsstype = 7; phyatk = 4; magatk = 4; agi = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 209)
			{
				dsstype = 7; phyatk = 4; magatk = 4; wis = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 208)
			{
				dsstype = 7; phyatk = 4; magatk = 4; intel = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 207)
			{
				dsstype = 7; phyatk = 4; magatk = 4; hp = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 206)
			{
				dsstype = 7; phyatk = 4; magatk = 4; str = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 205)
			{
				dsstype = 8; phyatk = 2; magatk = 2; agi = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			} else if (IItem.GetSetGem() == 204)
			{
				dsstype = 8; phyatk = 2; magatk = 2; wis = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			} else if (IItem.GetSetGem() == 203)
			{
				dsstype = 8; phyatk = 2; magatk = 2; intel = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			} else if (IItem.GetSetGem() == 202)
			{
				dsstype = 8; phyatk = 2; magatk = 2; hp = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			} else if (IItem.GetSetGem() == 201)
			{
				dsstype = 8; phyatk = 2; magatk = 2; str = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			}
		}

		if (IItem.GetType() >= 1 && IItem.GetType() <= 6)
		{
			if (IItem.GetSetGem() == 240)
			{
				dsstype = 1; def = 18; agi = 7;
			} else if (IItem.GetSetGem() == 239)
			{
				dsstype = 1; def = 18; wis = 7;
			} else if (IItem.GetSetGem() == 238)
			{
				dsstype = 1; def = 18; intel = 7;
			} else if (IItem.GetSetGem() == 237)
			{
				dsstype = 1; def = 18; hp = 7;
			} else if (IItem.GetSetGem() == 236)
			{
				dsstype = 1; def = 18; str = 7;
			} else if (IItem.GetSetGem() == 235)
			{
				dsstype = 2; def = 16; agi = 5;
			} else if (IItem.GetSetGem() == 234)
			{
				dsstype = 2; def = 16; wis = 5;
			} else if (IItem.GetSetGem() == 233)
			{
				dsstype = 2; def = 16; intel = 5;
			} else if (IItem.GetSetGem() == 232)
			{
				dsstype = 2; def = 16; hp = 5;
			} else if (IItem.GetSetGem() == 231)
			{
				dsstype = 2; def = 16; str = 5;
			} else if (IItem.GetSetGem() == 230)
			{
				dsstype = 3; def = 14; agi = 3;
			} else if (IItem.GetSetGem() == 229)
			{
				dsstype = 3; def = 14; wis = 3;
			} else if (IItem.GetSetGem() == 228)
			{
				dsstype = 3; def = 14; intel = 3;
			} else if (IItem.GetSetGem() == 227)
			{
				dsstype = 3; def = 14; hp = 3;
			} else if (IItem.GetSetGem() == 226)
			{
				dsstype = 3; def = 14; str = 3;
			} else if (IItem.GetSetGem() == 225)
			{
				dsstype = 4; def = 12; agi = 3;
			} else if (IItem.GetSetGem() == 224)
			{
				dsstype = 4; def = 12; wis = 3;
			} else if (IItem.GetSetGem() == 223)
			{
				dsstype = 4; def = 12; intel = 3;
			} else if (IItem.GetSetGem() == 222)
			{
				dsstype = 4; def = 12; hp = 3;
			} else if (IItem.GetSetGem() == 221)
			{
				dsstype = 4; def = 12; str = 3;
			} else if (IItem.GetSetGem() == 220)
			{
				dsstype = 5; def = 10; agi = 2;
			} else if (IItem.GetSetGem() == 219)
			{
				dsstype = 5; def = 10; wis = 2;
			} else if (IItem.GetSetGem() == 218)
			{
				dsstype = 5; def = 10; intel = 2;
			} else if (IItem.GetSetGem() == 217)
			{
				dsstype = 5; def = 10; hp = 2;
			} else if (IItem.GetSetGem() == 216)
			{
				dsstype = 5; def = 10; str = 2;
			} else if (IItem.GetSetGem() == 215)
			{
				dsstype = 6; def = 8; agi = 2;
			} else if (IItem.GetSetGem() == 214)
			{
				dsstype = 6; def = 8; wis = 2;
			} else if (IItem.GetSetGem() == 213)
			{
				dsstype = 6; def = 8; intel = 2;
			} else if (IItem.GetSetGem() == 212)
			{
				dsstype = 6; def = 8; hp = 2;
			} else if (IItem.GetSetGem() == 211)
			{
				dsstype = 6; def = 8; str = 2;
			} else if (IItem.GetSetGem() == 210)
			{
				dsstype = 7; def = 6; agi = 1;
			} else if (IItem.GetSetGem() == 209)
			{
				dsstype = 7; def = 6; wis = 1;
			} else if (IItem.GetSetGem() == 208)
			{
				dsstype = 7; def = 6; intel = 1;
			} else if (IItem.GetSetGem() == 207)
			{
				dsstype = 7; def = 6; hp = 1;
			} else if (IItem.GetSetGem() == 206)
			{
				dsstype = 7; def = 6; str = 1;
			} else if (IItem.GetSetGem() == 205)
			{
				dsstype = 8; def = 4; agi = 1;
			} else if (IItem.GetSetGem() == 204)
			{
				dsstype = 8; def = 4; wis = 1;
			} else if (IItem.GetSetGem() == 203)
			{
				dsstype = 8; def = 4; intel = 1;
			} else if (IItem.GetSetGem() == 202)
			{
				dsstype = 8; def = 4; hp = 1;
			} else if (IItem.GetSetGem() == 201)
			{
				dsstype = 8; def = 4; str = 1;
			}
		}

		if (!CBase::IsDeleted((int)player) && IItem.GetType() == -3 && otp && *(DWORD*)((int)player + 460) == 4)
		{
			eva = otp;
			otp = 0;
		}
	}

	int Value = 0, Itemxx = 0;
	Undefined::CreateMonsterValue((char*)player + 1068, (int)&Value, (int)&iid);
	int Recheck = 0, Check = 0;
	Check = Undefined::Check((int)((char*)player + 1068), (int)&Recheck);

	if (Undefined::CheckValues(&Value, Check))
	{
		Itemxx = *(DWORD*)(Undefined::GetValue(&Value) + 4);
		IItem IItem((void*)Itemxx);

		if (IItem.GetType() == -2 || IItem.GetType() == 19 || IItem.GetType() == 0 || IItem.GetType() == -3 || IItem.GetType() == -1)
		{
			if (IItem.GetSetGem() == 240)
			{
				dsstype = 1; phyatk = 17; magatk = 17; agi = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 239)
			{
				dsstype = 1; phyatk = 17; magatk = 17; wis = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 238)
			{
				dsstype = 1; phyatk = 17; magatk = 17; intel = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 237)
			{
				dsstype = 1; phyatk = 17; magatk = 17; hp = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 236)
			{
				dsstype = 1; phyatk = 17; magatk = 17; str = 8;
				hpinc = 250; mpinc = 200;
				if (IItem.GetType() == -1) eva = 18; else otp = 18;
			} else if (IItem.GetSetGem() == 235)
			{
				dsstype = 2; phyatk = 14; magatk = 14; agi = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 234)
			{
				dsstype = 2; phyatk = 14; magatk = 14; wis = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 233)
			{
				dsstype = 2; phyatk = 14; magatk = 14; intel = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 232)
			{
				dsstype = 2; phyatk = 14; magatk = 14; hp = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 231)
			{
				dsstype = 2; phyatk = 14; magatk = 14; str = 5;
				hpinc = 200; mpinc = 150;
				if (IItem.GetType() == -1) eva = 15; else otp = 15;
			} else if (IItem.GetSetGem() == 230)
			{
				dsstype = 3; phyatk = 12; magatk = 12; agi = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 229)
			{
				dsstype = 3; phyatk = 12; magatk = 12; wis = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 228)
			{
				dsstype = 3; phyatk = 12; magatk = 12; intel = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 227)
			{
				dsstype = 3; phyatk = 12; magatk = 12; hp = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 226)
			{
				dsstype = 3; phyatk = 12; magatk = 12; str = 3;
				hpinc = 130; mpinc = 110;
				if (IItem.GetType() == -1) eva = 12; else otp = 12;
			} else if (IItem.GetSetGem() == 225)
			{
				dsstype = 4; phyatk = 10; magatk = 10; agi = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 224)
			{
				dsstype = 4; phyatk = 10; magatk = 10; wis = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 223)
			{
				dsstype = 4; phyatk = 10; magatk = 10; intel = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 222)
			{
				dsstype = 4; phyatk = 10; magatk = 10; hp = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 221)
			{
				dsstype = 4; phyatk = 10; magatk = 10; str = 3;
				hpinc = 110; mpinc = 90;
				if (IItem.GetType() == -1) eva = 10; else otp = 10;
			} else if (IItem.GetSetGem() == 220)
			{
				dsstype = 5; phyatk = 8; magatk = 8; agi = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 219)
			{
				dsstype = 5; phyatk = 8; magatk = 8; wis = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 218)
			{
				dsstype = 5; phyatk = 8; magatk = 8; intel = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 217)
			{
				dsstype = 5; phyatk = 8; magatk = 8; hp = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 216)
			{
				dsstype = 5; phyatk = 8; magatk = 8; str = 2;
				hpinc = 90; mpinc = 70;
				if (IItem.GetType() == -1) eva = 8; else otp = 8;
			} else if (IItem.GetSetGem() == 215)
			{
				dsstype = 6; phyatk = 6; magatk = 6; agi = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 214)
			{
				dsstype = 6; phyatk = 6; magatk = 6; wis = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 213)
			{
				dsstype = 6; phyatk = 6; magatk = 6; intel = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 212)
			{
				dsstype = 6; phyatk = 6; magatk = 6; hp = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 211)
			{
				dsstype = 6; phyatk = 6; magatk = 6; str = 2;
				hpinc = 70; mpinc = 50;
				if (IItem.GetType() == -1) eva = 6; else otp = 6;
			} else if (IItem.GetSetGem() == 210)
			{
				dsstype = 7; phyatk = 4; magatk = 4; agi = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 209)
			{
				dsstype = 7; phyatk = 4; magatk = 4; wis = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 208)
			{
				dsstype = 7; phyatk = 4; magatk = 4; intel = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 207)
			{
				dsstype = 7; phyatk = 4; magatk = 4; hp = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 206)
			{
				dsstype = 7; phyatk = 4; magatk = 4; str = 1;
				hpinc = 50; mpinc = 30;
				if (IItem.GetType() == -1) eva = 4; else otp = 4;
			} else if (IItem.GetSetGem() == 205)
			{
				dsstype = 8; phyatk = 2; magatk = 2; agi = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			} else if (IItem.GetSetGem() == 204)
			{
				dsstype = 8; phyatk = 2; magatk = 2; wis = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			} else if (IItem.GetSetGem() == 203)
			{
				dsstype = 8; phyatk = 2; magatk = 2; intel = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			} else if (IItem.GetSetGem() == 202)
			{
				dsstype = 8; phyatk = 2; magatk = 2; hp = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			} else if (IItem.GetSetGem() == 201)
			{
				dsstype = 8; phyatk = 2; magatk = 2; str = 1;
				hpinc = 30; mpinc = 10;
				if (IItem.GetType() == -1) eva = 2; else otp = 2;
			}
		}

		if (IItem.GetType() >= 1 && IItem.GetType() <= 6)
		{
			if (IItem.GetSetGem() == 240)
			{
				dsstype = 1; def = 18; agi = 7;
			} else if (IItem.GetSetGem() == 239)
			{
				dsstype = 1; def = 18; wis = 7;
			} else if (IItem.GetSetGem() == 238)
			{
				dsstype = 1; def = 18; intel = 7;
			} else if (IItem.GetSetGem() == 237)
			{
				dsstype = 1; def = 18; hp = 7;
			} else if (IItem.GetSetGem() == 236)
			{
				dsstype = 1; def = 18; str = 7;
			} else if (IItem.GetSetGem() == 235)
			{
				dsstype = 2; def = 16; agi = 5;
			} else if (IItem.GetSetGem() == 234)
			{
				dsstype = 2; def = 16; wis = 5;
			} else if (IItem.GetSetGem() == 233)
			{
				dsstype = 2; def = 16; intel = 5;
			} else if (IItem.GetSetGem() == 232)
			{
				dsstype = 2; def = 16; hp = 5;
			} else if (IItem.GetSetGem() == 231)
			{
				dsstype = 2; def = 16; str = 5;
			} else if (IItem.GetSetGem() == 230)
			{
				dsstype = 3; def = 14; agi = 3;
			} else if (IItem.GetSetGem() == 229)
			{
				dsstype = 3; def = 14; wis = 3;
			} else if (IItem.GetSetGem() == 228)
			{
				dsstype = 3; def = 14; intel = 3;
			} else if (IItem.GetSetGem() == 227)
			{
				dsstype = 3; def = 14; hp = 3;
			} else if (IItem.GetSetGem() == 226)
			{
				dsstype = 3; def = 14; str = 3;
			} else if (IItem.GetSetGem() == 225)
			{
				dsstype = 4; def = 12; agi = 3;
			} else if (IItem.GetSetGem() == 224)
			{
				dsstype = 4; def = 12; wis = 3;
			} else if (IItem.GetSetGem() == 223)
			{
				dsstype = 4; def = 12; intel = 3;
			} else if (IItem.GetSetGem() == 222)
			{
				dsstype = 4; def = 12; hp = 3;
			} else if (IItem.GetSetGem() == 221)
			{
				dsstype = 4; def = 12; str = 3;
			} else if (IItem.GetSetGem() == 220)
			{
				dsstype = 5; def = 10; agi = 2;
			} else if (IItem.GetSetGem() == 219)
			{
				dsstype = 5; def = 10; wis = 2;
			} else if (IItem.GetSetGem() == 218)
			{
				dsstype = 5; def = 10; intel = 2;
			} else if (IItem.GetSetGem() == 217)
			{
				dsstype = 5; def = 10; hp = 2;
			} else if (IItem.GetSetGem() == 216)
			{
				dsstype = 5; def = 10; str = 2;
			} else if (IItem.GetSetGem() == 215)
			{
				dsstype = 6; def = 8; agi = 2;
			} else if (IItem.GetSetGem() == 214)
			{
				dsstype = 6; def = 8; wis = 2;
			} else if (IItem.GetSetGem() == 213)
			{
				dsstype = 6; def = 8; intel = 2;
			} else if (IItem.GetSetGem() == 212)
			{
				dsstype = 6; def = 8; hp = 2;
			} else if (IItem.GetSetGem() == 211)
			{
				dsstype = 6; def = 8; str = 2;
			} else if (IItem.GetSetGem() == 210)
			{
				dsstype = 7; def = 6; agi = 1;
			} else if (IItem.GetSetGem() == 209)
			{
				dsstype = 7; def = 6; wis = 1;
			} else if (IItem.GetSetGem() == 208)
			{
				dsstype = 7; def = 6; intel = 1;
			} else if (IItem.GetSetGem() == 207)
			{
				dsstype = 7; def = 6; hp = 1;
			} else if (IItem.GetSetGem() == 206)
			{
				dsstype = 7; def = 6; str = 1;
			} else if (IItem.GetSetGem() == 205)
			{
				dsstype = 8; def = 4; agi = 1;
			} else if (IItem.GetSetGem() == 204)
			{
				dsstype = 8; def = 4; wis = 1;
			} else if (IItem.GetSetGem() == 203)
			{
				dsstype = 8; def = 4; intel = 1;
			} else if (IItem.GetSetGem() == 202)
			{
				dsstype = 8; def = 4; hp = 1;
			} else if (IItem.GetSetGem() == 201)
			{
				dsstype = 8; def = 4; str = 1;
			}
		}

		if (!CBase::IsDeleted((int)player) && IItem.GetType() == -3 && otp && *(DWORD*)((int)player + 460) == 4)
		{
			eva = otp;
			otp = 0;
		}
	}

	int ItemStat = GetItemStat.find(iid)->second;

	if (GetItemStat.count(iid))
	{
		PerfShotCheck = GetItemStat.find(iid)->second / 100000000;
		ItemStat -= (100000000 * PerfShotCheck);
	}

	if (ItemStat)
	{
		int dg1typecheck = ItemStat / 10000000;
		if (dg1typecheck) dg1stat = 1;
		if (dg1typecheck > 0) dg1type = (dg1typecheck - 1);
		ItemStat -= (10000000 * dg1typecheck);
	}

	if (ItemStat)
	{
		int dg1statcheck = ItemStat / 1000000;
		if (dg1statcheck > 0) dg1stat = (dg1statcheck + 1);
		ItemStat -= (1000000 * dg1statcheck);
	}

	if (ItemStat)
	{
		int dg2typecheck = ItemStat / 100000;
		if (dg2typecheck) dg2stat = 1;
		if (dg2typecheck > 0) dg2type = (dg2typecheck - 1);
		ItemStat -= (100000 * dg2typecheck);
	}

	if (ItemStat)
	{
		int dg2statcheck = ItemStat / 10000;
		if (dg2statcheck > 0) dg2stat = (dg2statcheck + 1);
		ItemStat -= (10000 * dg2statcheck);
	}

	if (ItemStat && index >= 2986 && index <= 3009)
	{
		int yinyanggrade = ItemStat / 100;
		prefix = yinyanggrade + 1;
		ItemStat -= (100 * yinyanggrade);
	}

	if (ItemStat)
		QigongGrade = ItemStat % 100;

	if (index >= 3199 && index <= 3201 && prefix == 0)
		prefix = 1;

	if (index >= 2986 && index <= 3009 && prefix == 0)
		prefix = 1;

	if (index >= 3018 && index <= 3020)
		prefix = GetItemStat.find(iid)->second / 1000;

	if (index >= 3381 && index <= 3383)
	{
		CPlayer::Write(player,194,"dd",iid,100);
		if (index == 3381) CPlayer::Write(player,193,"ddd",iid,101,10);
		if (index == 3382) CPlayer::Write(player,193,"ddd",iid,101,11);
		if (index == 3383) CPlayer::Write(player,193,"ddd",iid,101,12);

		if (index == 3383 && GetItemStat.find(iid)->second == 0)
			CPlayer::Write(player,193,"ddd",iid,100,GetItemStat.find(iid)->second+2);
		else
			CPlayer::Write(player,193,"ddd",iid,100,GetItemStat.find(iid)->second+1);
	}

	if (index >= 3384 && index <= 3386)
	{
		if (GetItemStat.count(iid))
		{
			int ItemStat = GetItemStat.find(iid)->second;
			int Stat = ItemStat / 1000;
			int Value = ItemStat % 100;
			CPlayer::Write(player,194,"dd",iid,Value);
			CPlayer::Write(player,193,"ddd",iid,Value,Stat);
		}
	}

	Tools->Compile(Packet, "wdbddbbbbbbbbwbbbbbdbwwwwbbbbbbbbbbdbbwbb",index, iid, prefix, info, amount, maxend, curend,
		setgem, xatk, xmagic, xdefense, xhit, xevasion, xprotect, upgrlvl, upgrrate, x, y, z, remaintime, dsstype, phyatk, magatk, def, absorb, eva, otp, hpinc, mpinc, str, hp, intel, wis, agi, PerfShotCheck, QigongGrade, dg1stat, dg1type, a, dg2stat, dg2type);

	CPlayer::Write(player, Type, "m", Packet, 63);
	delete[] Packet;
}

void ItemFixes()
{
	Interface<IMemory> Memory;
	Memory->Fill(0x00458039,IMemory::_I_NOP, 8);
	Memory->Hook(0x0045803f,ModsSendItemInfo);
	Memory->HookAPI(0x00426750,ModsItemPutInfo);
	Memory->Hook(0x0042748c,ModsSendUpdateItemInfo);
	Memory->Hook(0x0045ec94,ModsSendStorageList);
	Memory->Hook(0x0045f4f9,ModsSendStallList);
	Memory->Hook(0x0045e65c,ModsSendTradeList);
}