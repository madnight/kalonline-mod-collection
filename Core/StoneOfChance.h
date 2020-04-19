void __fastcall StoneOfChance(void *pSkill, void *edx, unsigned int SkillID)
{
	int SkillPointer = 0, SkillGrade = 0;

	if (SkillID == 79)
		return;

	if (SkillID < 90)
	{
		SkillPointer = *((DWORD*)pSkill + SkillID + 2);

		if (SkillPointer)
		{
			IChar IPlayer(*(void**)pSkill);
			SkillGrade = *(DWORD*)(SkillPointer + 8);

			if (IPlayer.IsOnline() && SkillGrade && (CPlayer::RemoveItem(*(void **)pSkill, 9, 362, 1) || CPlayer::RemoveItem(*(void **)pSkill, 9, 502, 1)))
			{
				if (IPlayer.IsOnline() && IPlayer.GetClass() == 0 && (SkillID == 37 || SkillID == 39 || SkillID == 44 || SkillID == 70 || SkillID == 82 || SkillID == 87 || SkillID == 88 || SkillID == 89))
					return;

				if (IPlayer.IsOnline() && IPlayer.GetClass() == 1 && (SkillID == 63 || SkillID == 64 || SkillID == 68 || SkillID == 70 || SkillID == 71 || SkillID == 82 || SkillID == 87 || SkillID == 88 || SkillID == 89))
					return;

				if (IPlayer.IsOnline() && IPlayer.GetClass() == 2 && (SkillID == 46 || SkillID == 48 || SkillID == 70 || SkillID == 71 || SkillID == 82 || SkillID == 87 || SkillID == 88 || SkillID == 89))
					return;

				if (IPlayer.IsOnline() && IPlayer.GetClass() == 3 && (SkillID == 37 || SkillID == 50 || SkillID == 70 || SkillID == 87 || SkillID == 88 || SkillID == 89))
					return;

				if (IPlayer.IsOnline() && (*(int (__thiscall **)(int, DWORD))(*(DWORD *)SkillPointer + 48))(SkillPointer, *(DWORD *)pSkill))
				{
					if (IPlayer.IsOnline() && IPlayer.GetClass() == 0 && SkillID == 36)
						IPlayer.DecreaseCritDamage(20);

					if (IPlayer.IsOnline() && IPlayer.GetClass() == 2 && SkillID == 32)
						IPlayer.DecreaseCritDamage(80);
					
					if (IPlayer.IsOnline() && IPlayer.GetClass() == 3 && SkillID == 4)
					{
						IPlayer.DecreaseCritRate(SkillGrade);
						IPlayer.DecreaseCritDamage(SkillGrade);
					}

					if (IPlayer.IsOnline() && IPlayer.GetClass() == 3 && SkillID == 5)
					{
						IPlayer.DecreaseCritRate(SkillGrade);
						IPlayer.DecreaseCritDamage(SkillGrade);
					}

					Undefined::DeleteSkill(SkillPointer);
				}
			}
		}
	}
}