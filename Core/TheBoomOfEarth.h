void __fastcall TheBoomOfEarth(IChar IPlayer)
{
    if (IPlayer.IsOnline())
    {
        int pSkill = IPlayer.GetSkillPointer(91);

        if (pSkill && IPlayer.IsValid())
        {
            if (CPlayer::IsWState((int)IPlayer.GetOffset(), 12)) {
                return;
            }

            ISkill xSkill((void*)pSkill);
            int Mana = 200 + (xSkill.GetGrade() * (20 + (xSkill.GetGrade() - 1)));

            if (IPlayer.GetCurMp() <= Mana) {
                return;
            }

            IPlayer.DecreaseMana(Mana);
            IPlayer._ShowBattleAnimation(IPlayer, 91);

            if (IPlayer.IsValid())
            {
                int Around = IPlayer.GetObjectListAround(3);

                while (Around)
                {
                    IChar Object((void*) * (DWORD*)Around);

                    if (Object.IsValid() && IPlayer.IsValid() &&
                        (*(int (__thiscall **)(int, int, DWORD))
                            (*(DWORD *)IPlayer.GetOffset() + 176))
                        ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0)) {
                        Object.Buff(7, 2 * xSkill.GetGrade(), 0);
                    }

                    Around = CBaseList::Pop((void*)Around);
                }
            }
        }
    }
}
