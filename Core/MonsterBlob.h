int __fastcall CheckBlock(int Player, void *edx, int Object)
{
	IChar Objectx((void*)Object);
	IChar IPlayer((void*)Player);

	if (Objectx.IsValid() && IPlayer.IsValid())
	{
		if (Objectx.GetType() == 1 && (Objectx.GetLevel() > 99 || IPlayer.GetLevel() > 99))
		{
			if (!*(DWORD*)(Player + 264) || IPlayer.GetClass() == 1)
				return 0;

			if (IPlayer.GetClass() == 2)
				return (*(DWORD*)(Player + 264) + CTools::Rate(10,20)) >= CTools::Rate(1, 100);

			if (!CPlayer::IsWState(Player, 1))
			{
				int pSkill = *((DWORD*)((int)IPlayer.GetOffset() + 624) + 20 + 2);

				if (!CPlayer::IsWState(Player, 12) || !pSkill)
					return 0;
			}

			int Check = 0, ReCheck = 0;
			Check = CPlayer::IsWState(Player, 12) != 0;

			if (Check)
				ReCheck = (*(DWORD*)(Player + 264) + 3) / 3;
			else
				ReCheck = *(DWORD*)(Player + 264) + 3;

			return (*(DWORD*)(Player + 264) + ReCheck) >= CTools::Rate(1, 100);
		} else {
			return CPlayer::CheckBlock(Player,Object);
		}
	} else {
		return 0;
	}
}

void __fastcall MonsterTick(void *Monster, void *edx)
{
	IChar IMonster(Monster);

	if (IMonster.IsValid() && IMonster.GetMobTanker() && (IMonster.GetMobIndex() == 437 || IMonster.GetMobIndex() == 485 || IMonster.GetMobIndex() == 486 || IMonster.GetMobIndex() == 487 || IMonster.GetMobIndex() == 488) && !IMonster.IsBuff(360))
	{
		IChar IPlayer((void*)IMonster.GetMobTanker());

		if (IPlayer.IsValid() && IPlayer.GetMap() == IMonster.GetMap() && (int)CTools::Rate(1, 100) <= 7)
		{
			IMonster.Buff(360,10,0);
			CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 87, IMonster.GetID(), IMonster.GetID(), 1, 1);
			int *GetSetXY = new int[1];
			GetSetXY[0] = IPlayer.GetX();
			GetSetXY[1] = IPlayer.GetY();
			int check = CMonsterMagic::Create(230,IMonster.GetMap(),(int)GetSetXY,1,(int)IMonster.GetOffset(),0,5000);
			delete[] GetSetXY;
		} else {
			IMonster.Buff(360,2,0);
		}
	}

	if (IMonster.IsValid() && IMonster.GetMobTanker() && (IMonster.GetMobIndex() == 439 || IMonster.GetMobIndex() == 489 || IMonster.GetMobIndex() == 490 || IMonster.GetMobIndex() == 491 || IMonster.GetMobIndex() == 492) && !IMonster.IsBuff(360))
	{
		IChar IPlayer((void*)IMonster.GetMobTanker());

		if (IPlayer.IsValid() && IPlayer.GetMap() == IMonster.GetMap() && (int)CTools::Rate(1, 100) <= 7)
		{
			IMonster.Buff(360,10,0);
			CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 88, IMonster.GetID(), IMonster.GetID(), 1, 1);
			int *GetSetXY = new int[1];
			GetSetXY[0] = IPlayer.GetX();
			GetSetXY[1] = IPlayer.GetY();
			int check = CMonsterMagic::Create(229,IMonster.GetMap(),(int)GetSetXY,1,(int)IMonster.GetOffset(),0,5000);
			delete[] GetSetXY;
		} else {
			IMonster.Buff(360,2,0);
		}
	}

	if (IMonster.IsValid() && IMonster.GetMobTanker() && (IMonster.GetMobIndex() == 441 || IMonster.GetMobIndex() == 493 || IMonster.GetMobIndex() == 496 || IMonster.GetMobIndex() == 494 || IMonster.GetMobIndex() == 495) && !IMonster.IsBuff(360))
	{
		IChar IPlayer((void*)IMonster.GetMobTanker());

		if (IPlayer.IsValid() && IPlayer.GetMap() == IMonster.GetMap() && (int)CTools::Rate(1, 100) <= 7)
		{
			IMonster.Buff(360,10,0);
			CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 89, IMonster.GetID(), IMonster.GetID(), 1, 1);
			int *GetSetXY = new int[1];
			GetSetXY[0] = IPlayer.GetX();
			GetSetXY[1] = IPlayer.GetY();
			int check = CMonsterMagic::Create(228,IMonster.GetMap(),(int)GetSetXY,1,(int)IMonster.GetOffset(),0,5000);
			delete[] GetSetXY;
		} else {
			IMonster.Buff(360,2,0);
		}
	}

	if (IMonster.IsValid() && IMonster.GetMobTanker() && (IMonster.GetMobIndex() == 443 || IMonster.GetMobIndex() == 497 || IMonster.GetMobIndex() == 498 || IMonster.GetMobIndex() == 499 || IMonster.GetMobIndex() == 500) && !IMonster.IsBuff(360))
	{
		IChar IPlayer((void*)IMonster.GetMobTanker());

		if (IPlayer.IsValid() && IPlayer.GetMap() == IMonster.GetMap() && (int)CTools::Rate(1, 100) <= 10)
		{
			IMonster.Buff(360,3,0);
			CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 90, IMonster.GetID(), IMonster.GetID(), 1, 1);
			int Around = IPlayer.GetObjectListAround(3);

			while(Around)
			{
				IChar Object((void*)*(DWORD*)Around);

				if (Object.GetType() == 0)
					IPlayer.OktayDamageStorm(Object,CTools::Rate(750,1000));

				Around = CBaseList::Pop((void*)Around);
			}
		}
	}

	if (IMonster.IsValid() && IMonster.GetMobTanker() && (IMonster.GetMobIndex() == 435 || IMonster.GetMobIndex() == 481 || IMonster.GetMobIndex() == 482 || IMonster.GetMobIndex() == 483 || IMonster.GetMobIndex() == 484) && !IMonster.IsBuff(360))
	{
		IChar IPlayer((void*)IMonster.GetMobTanker());

		if (IPlayer.IsValid() && IPlayer.GetMap() == IMonster.GetMap() && (int)CTools::Rate(1, 100) <= 10)
		{
			IMonster.Buff(360,3,0);
			CChar::WriteInSight(IMonster.Offset, 63, "bddbb", 86, IMonster.GetID(), IMonster.GetID(), 1, 1);
			int Around = IPlayer.GetObjectListAround(3);

			while(Around)
			{
				IChar Object((void*)*(DWORD*)Around);

				if (Object.GetType() == 0)
					IPlayer.OktayDamageStorm(Object,CTools::Rate(750,1000));

				Around = CBaseList::Pop((void*)Around);
			}
		}
	}

	CMonsterReal::Tick(Monster);
}