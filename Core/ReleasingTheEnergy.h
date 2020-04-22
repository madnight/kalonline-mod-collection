void __fastcall ReleasingTheEnergy(IChar IPlayer)
{
    if (IPlayer.IsBuff(391)) {
        return;
    }

    int pSkill = IPlayer.GetSkillPointer(92);

    if (IPlayer.IsOnline() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int Mana = (15 + (xSkill.GetGrade() * 5));

        if (IPlayer.GetCurMp() < Mana) {
            return;
        }

        if (IPlayer.IsValid() && !IPlayer.IsBuff(391))
        {
            IPlayer.DecreaseMana(Mana);
            IPlayer.Buff(390, 10*xSkill.GetGrade(), 0);
            IPlayer.Buff(391, 3600, 0);
            IPlayer._ShowBattleAnimation(IPlayer, 92);
            IPlayer.SetBuffIcon(10000*xSkill.GetGrade(), 0, 4244, 952);
            IPlayer.IncreaseMaxHp(500*xSkill.GetGrade());
            IPlayer.IncreaseHp(500*xSkill.GetGrade());
            IPlayer.AddMaxAttack(100*xSkill.GetGrade());
            IPlayer.AddMinAttack(100*xSkill.GetGrade());
        }
    }
}