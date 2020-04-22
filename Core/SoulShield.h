void __fastcall SoulShield(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(15);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nMana = (nSkillGrade * 2) + 50;
        int Time = 60 + (nSkillGrade * 60);

        if (IPlayer.IsValid() && IPlayer.GetCurMp() >= nMana && nSkillGrade)
        {
            if (IPlayer.IsValid() && !IPlayer.IsBuff(397))
            {
                IPlayer.DecreaseMana(nMana);
                IPlayer._ShowBattleAnimation(IPlayer, 15);

                if (nSkillGrade == 1) {
                    IPlayer.Buff(396, 5+Time, 0);
                }

                if (nSkillGrade == 2) {
                    IPlayer.Buff(396, 1000, 0);
                }

                if (nSkillGrade == 3) {
                    IPlayer.Buff(396, 2000, 0);
                }

                if (nSkillGrade == 4) {
                    IPlayer.Buff(396, 3000, 0);
                }

                if (nSkillGrade == 5) {
                    IPlayer.Buff(396, 4000, 0);
                }

                if (nSkillGrade == 6) {
                    IPlayer.Buff(396, 5000, 0);
                }

                if (nSkillGrade == 7) {
                    IPlayer.Buff(396, 6000, 0);
                }

                if (nSkillGrade == 8) {
                    IPlayer.Buff(396, 7000, 0);
                }

                if (nSkillGrade == 9) {
                    IPlayer.Buff(396, 8000, 0);
                }

                if (nSkillGrade == 10) {
                    IPlayer.Buff(396, 9000, 0);
                }

                IPlayer.Buff(397, 10000, 0);
                IPlayer.AddDef(6 * nSkillGrade);
                IPlayer.SetBuffIcon(Time*1000, 0, 9100, 1009);
            }
        }
    }
}