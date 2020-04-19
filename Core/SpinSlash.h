void __fastcall SpinSlash(IChar IPlayer)
{
	int pSkill = IPlayer.GetSkillPointer(38);
	
	if (IPlayer.IsValid() && pSkill)
	{
		ISkill xSkill((void*)pSkill);
		int nMana = (xSkill.GetGrade() == 1) ? 209 : (200 + (xSkill.GetGrade() * 20));

		if (IPlayer.GetCurMp() < nMana)
			return;

		if (IPlayer.IsValid() && CPlayer::IsWState((int)IPlayer.GetOffset(),12))
		{
			int Around = IPlayer.GetObjectListAround(3);

			while(Around)
			{
				IChar Object((void*)*(DWORD*)Around);

				if (Object.IsValid() && IPlayer.IsValid() && (*(int (__thiscall **)(int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
				{
					int nDmg = (IPlayer.GetAttack() * KSSMul) + (xSkill.GetGrade() * CTools::Rate(KSSMin,KSSMax) + (IPlayer.GetDeathBlow() * CTools::Rate(KSSDBMin,KSSDBMax)));

					if (Object.GetType() == 0)
						nDmg = (nDmg * KSSReduce) / 100;

					IPlayer.OktayDamageArea(Object,nDmg,38);
				}

				Around = CBaseList::Pop((void*)Around);
			}

			IPlayer._ShowBattleAnimation(IPlayer, 38);
			IPlayer.RemoveDeathBlow(IPlayer.GetDeathBlow());
			IPlayer.DecreaseMana(nMana);
		}
	}
}