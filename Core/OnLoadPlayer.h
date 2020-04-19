int __fastcall OnLoadPlayer(void *Player, void *edx, int Value)
{
	IChar IPlayer(Player);

	if (IPlayer.IsOnline())
	{
		CPlayer::Write(Player,0xFF,"dd",238,128);
		CPlayer::Write(Player,0xFF,"dd",221,0);	
	}

	int Check = CPlayer::OnLoadPlayer(Player,Value);

	if (IPlayer.IsOnline())
	{
		CDBSocket::Write(92,"d",IPlayer.GetPID());
		CDBSocket::Write(82,"d",IPlayer.GetPID());
		CDBSocket::Write(84,"d",IPlayer.GetPID());

		if (IPlayer.GetClass() == 3 && IPlayer.GetStr() < 14 && IPlayer.GetLevel() == 1)
		{
			IPlayer.IncreaseStat(14,0);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),0,*(DWORD *)((int)Player + 4 * 0 + 64));
			IPlayer.IncreaseStat(10,1);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),1,*(DWORD *)((int)Player + 4 * 1 + 64));
			IPlayer.IncreaseStat(8,2);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),2,*(DWORD *)((int)Player + 4 * 2 + 64));
			IPlayer.IncreaseStat(5,3);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),3,*(DWORD *)((int)Player + 4 * 3 + 64));
			IPlayer.IncreaseStat(18,4);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),4,*(DWORD *)((int)Player + 4 * 4 + 64));
		}

		if (IPlayer.GetClass() == 4 && IPlayer.GetHth() < 10 && IPlayer.GetLevel() == 1)
		{
			IPlayer.IncreaseStat(-52,0);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),0,*(DWORD *)((int)Player + 4 * 0 + 64));
			IPlayer.IncreaseStat(10,1);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),1,*(DWORD *)((int)Player + 4 * 1 + 64));
			IPlayer.IncreaseStat(-140,2);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),2,*(DWORD *)((int)Player + 4 * 2 + 64));
			IPlayer.IncreaseStat(14,3);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),3,*(DWORD *)((int)Player + 4 * 3 + 64));
			IPlayer.IncreaseStat(-64,4);
			CDBSocket::Write(16,"dbwbb",IPlayer.GetPID(),23,IPlayer.GetStatPoint(),4,*(DWORD *)((int)Player + 4 * 4 + 64));
		}

		if (IPlayer.GetX() < 0 || IPlayer.GetY() < 0 || IPlayer.GetZ() < 0)
		{
			IPlayer.BoxMsg("Player has been unstucked.");
			IPlayer.SetX(257514);
			IPlayer.SetY(259273);
			IPlayer.SetZ(16168);
			SaveAllProperty((int)Player, 0, 0);
			IPlayer.Kick();
			return 0;
		}

		if (PlayerBlockCheck.find(IPlayer.GetUID())->second)
		{
			IPlayer.BoxMsg("Your account has been blocked.");
			IPlayer.Kick();
			return 0;
		}

		if ((IPlayer.GetClass() == 4 || IPlayer.GetClass() == 0 || IPlayer.GetClass() == 2 || IPlayer.GetClass() == 3 || (IPlayer.GetClass() == 1 && IPlayer.GetSpecialty() == 23)) && IPlayer.GetLevel() >= 70)
		{
			int pSkill = IPlayer.GetSkillPointer(70);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				IPlayer.AddMaxAttack((IPlayer.GetMaxPhyAttack() * (4 + (xSkill.GetGrade() * 4))) / 100);
				IPlayer.AddMinAttack((IPlayer.GetMaxPhyAttack() * (4 + (xSkill.GetGrade() * 4))) / 100);
			}

			pSkill = IPlayer.GetSkillPointer(71);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				IPlayer.AddMaxAttack((IPlayer.GetMaxPhyAttack() * (4 + (xSkill.GetGrade() * 4))) / 100);
				IPlayer.AddMinAttack((IPlayer.GetMaxPhyAttack() * (4 + (xSkill.GetGrade() * 4))) / 100);
			}
		}

		if (IPlayer.GetClass() == 1 && IPlayer.GetLevel() >= 70 && IPlayer.GetSpecialty() == 43)
		{
			int pSkill = IPlayer.GetSkillPointer(71);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				IPlayer.AddDef(8 + (xSkill.GetGrade() * 4));
			}
		}

		if (IPlayer.GetClass() == 3)
		{
			int pSkill = IPlayer.GetSkillPointer(2);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				IPlayer.AddMinAttack(xSkill.GetGrade());
				IPlayer.AddMaxAttack(xSkill.GetGrade());
			}
		}

		if (IPlayer.GetClass() == 3)
		{
			int pSkill = IPlayer.GetSkillPointer(3);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				IPlayer.AddOTP(xSkill.GetGrade()*2);
			}
		}

		if (IPlayer.GetClass() == 3)
		{
			int Crit = IPlayer.GetSkillPointer(4);
			int CritDamage = IPlayer.GetSkillPointer(5);
			int LastCritDamage = IPlayer.GetSkillPointer(37);

			if (Crit)
			{
				IPlayer.IncreaseCritRate(*(DWORD*)((int)Crit + 8));
				IPlayer.IncreaseCritDamage(*(DWORD*)((int)Crit + 8));
			}

			if (CritDamage)
			{
				IPlayer.IncreaseCritRate(*(DWORD*)((int)CritDamage + 8));
				IPlayer.IncreaseCritDamage(*(DWORD*)((int)CritDamage + 8));
			}

			if (LastCritDamage)
			{
				IPlayer.IncreaseCritRate(*(DWORD*)((int)LastCritDamage + 8));
				IPlayer.IncreaseCritDamage(*(DWORD*)((int)LastCritDamage + 8) * 2);
			}
		}

		if (IPlayer.GetLevel() >= 96)
		{
			int pSkill = IPlayer.GetSkillPointer(94);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				IPlayer.IncreaseCritRate(xSkill.GetGrade() * 5);
				IPlayer.IncreaseCritDamage(xSkill.GetGrade() * 5);
			}
		}

		if (IPlayer.GetClass() == 3 || IPlayer.GetClass() == 4)
		{
			int pSkill = IPlayer.GetSkillPointer(30);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				IPlayer.IncreaseMaxHp((xSkill.GetGrade() * 5) * IPlayer.GetHth());
			}
		}

		if (IPlayer.GetClass() == 0 && IPlayer.GetLevel() < 100 && IPlayer.GetSpecialty() == 43)
			IPlayer.AddDef(((IPlayer.GetLevel() - 65) * 5) - ((IPlayer.GetDef() * 2) / 50));
		
		if (IPlayer.GetClass() == 0 && IPlayer.GetLevel() >= 100 && IPlayer.GetSpecialty() == 43)
			IPlayer.AddDef(((100 - 65) * 5) - ((IPlayer.GetDef() * 2) / 50));

		if (IPlayer.GetLevel() >= 81)
		{
			int OTP = IPlayer.GetSkillPointer(87);
			int EVA = IPlayer.GetSkillPointer(88);
			int DEF = IPlayer.GetSkillPointer(89);

			if (OTP)
			{
				ISkill xSkill((void*)OTP);
				IPlayer.AddOTP(8 * xSkill.GetGrade());
			}

			if (EVA)
			{
				ISkill xSkill((void*)EVA);
				IPlayer.AddEva(6 * xSkill.GetGrade());
			}

			if (DEF)
			{
				ISkill xSkill((void*)DEF);
				IPlayer.AddDef(24 + (7 * xSkill.GetGrade()));
			}
		}

		if (IPlayer.GetLevel() >= 70)
		{
			IPlayer.IncreaseMaxHp(250);
			IPlayer.IncreaseMaxMp(100);
		}

		if (IPlayer.GetLevel() >= 75)
		{
			IPlayer.IncreaseMaxHp(300);
			IPlayer.IncreaseMaxMp(125);
		}

		if (IPlayer.GetLevel() >= 80)
		{
			IPlayer.IncreaseMaxHp(350);
			IPlayer.IncreaseMaxMp(150);
		}

		if (IPlayer.GetLevel() >= 85)
		{
			IPlayer.IncreaseMaxHp(550);
			IPlayer.IncreaseMaxMp(250);
		}

		if (IPlayer.GetLevel() >= 90)
		{
			IPlayer.IncreaseMaxHp(950);
			IPlayer.IncreaseMaxMp(450);
		}

		if (IPlayer.GetLevel() >= 95)
		{
			IPlayer.IncreaseMaxHp(1750);
			IPlayer.IncreaseMaxMp(850);
		}

		if (IPlayer.GetLevel() >= 70 && IPlayer.GetLevel() <= 74)
		{
			int Value = IPlayer.GetLevel() - 69;
			IPlayer.IncreaseMaxHp(Value*6);
			IPlayer.IncreaseMaxMp(Value*3);
		}

		if (IPlayer.GetLevel() >= 75 && IPlayer.GetLevel() <= 79)
		{
			int Value = IPlayer.GetLevel() - 74;
			IPlayer.IncreaseMaxHp((Value*12)+30);
			IPlayer.IncreaseMaxMp((Value*6)+15);
		}

		if (IPlayer.GetLevel() >= 80 && IPlayer.GetLevel() <= 84)
		{
			int Value = IPlayer.GetLevel() - 79;
			IPlayer.IncreaseMaxHp((Value*18)+90);
			IPlayer.IncreaseMaxMp((Value*9)+45);
		}

		if (IPlayer.GetLevel() >= 85 && IPlayer.GetLevel() <= 89)
		{
			int Value = IPlayer.GetLevel() - 84;
			IPlayer.IncreaseMaxHp((Value*24)+180);
			IPlayer.IncreaseMaxMp((Value*12)+90);
		}

		if (IPlayer.GetLevel() >= 90 && IPlayer.GetLevel() <= 94)
		{
			int Value = IPlayer.GetLevel() - 89;
			IPlayer.IncreaseMaxHp((Value*30)+300);
			IPlayer.IncreaseMaxMp((Value*15)+150);
		}

		if (IPlayer.GetLevel() >= 95)
		{
			int Value = IPlayer.GetLevel() - 94;
			IPlayer.IncreaseMaxHp((Value*36)+450);
			IPlayer.IncreaseMaxMp((Value*18)+225);
		}

		if(IPlayer.GetClass() == 2 && IPlayer.GetLevel() < 100 && IPlayer.GetSpecialty() == 43)
			IPlayer.AddEva((IPlayer.GetAgi() * (IPlayer.GetLevel() / 2) / 400));

		if(IPlayer.GetClass() == 2 && IPlayer.GetLevel() >= 100 && IPlayer.GetSpecialty() == 43)
			IPlayer.AddEva((IPlayer.GetAgi() * (100 / 2) / 400));

		if (IPlayer.GetClass() == 4)
		{
			int pSkill = IPlayer.GetSkillPointer(17);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int nSkillGrade = xSkill.GetGrade();
				IPlayer.IncreaseMaxMp(30*nSkillGrade);
			}
		}

		if (IPlayer.GetClass() == 4)
		{
			int pSkill = IPlayer.GetSkillPointer(23);

			if (pSkill)
			{
				ISkill xSkill((void*)pSkill);
				int nSkillGrade = xSkill.GetGrade();
				IPlayer.AddInt(2*nSkillGrade);
			}
		}

		return Check;
	} else {
		return 0;
	}
}