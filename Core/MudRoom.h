void __fastcall MudRoom(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(20);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nMana = (nSkillGrade * 2) + 80;
        int Time = nSkillGrade * 60;

        if (IPlayer.IsValid() && IPlayer.GetCurMp() >= nMana && nSkillGrade)
        {
            if (IPlayer.IsValid() && !IPlayer.IsBuff(399))
            {
                IPlayer.DecreaseMana(nMana);
                IPlayer._ShowBattleAnimation(IPlayer, 20);

                if (nSkillGrade == 1) {
                    IPlayer.Buff(398, 5+Time, 0);
                }

                if (nSkillGrade == 2) {
                    IPlayer.Buff(398, 1000, 0);
                }

                if (nSkillGrade == 3) {
                    IPlayer.Buff(398, 2000, 0);
                }

                if (nSkillGrade == 4) {
                    IPlayer.Buff(398, 3000, 0);
                }

                if (nSkillGrade == 5) {
                    IPlayer.Buff(398, 4000, 0);
                }

                if (nSkillGrade == 6) {
                    IPlayer.Buff(398, 5000, 0);
                }

                if (nSkillGrade == 7) {
                    IPlayer.Buff(398, 6000, 0);
                }

                if (nSkillGrade == 8) {
                    IPlayer.Buff(398, 7000, 0);
                }

                if (nSkillGrade == 9) {
                    IPlayer.Buff(398, 8000, 0);
                }

                if (nSkillGrade == 10) {
                    IPlayer.Buff(398, 9000, 0);
                }

                IPlayer.Buff(399, 10000, 0);
                IPlayer.AddDef(nSkillGrade);
                IPlayer.AddAbsorb(nSkillGrade);
                IPlayer.SetBuffIcon(Time*1000, 0, 9101, 1010);
            }
        }
    }
}