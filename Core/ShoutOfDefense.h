void __fastcall ShoutOfDefense(IChar IPlayer)
{
    if (IPlayer.IsBuff(380)) {
        return;
    }

    if (IPlayer.IsValid())
    {
        int pSkill = IPlayer.GetSkillPointer(90);
        int Mana = (20 + IPlayer.GetLevel()) + ((20 + (IPlayer.GetLevel() * 4)) / 10);

        if (IPlayer.GetCurMp() <= Mana) {
            return;
        }

        if (pSkill && IPlayer.IsValid() && !IPlayer.IsBuff(380))
        {
            IPlayer.DecreaseMana(Mana);
            ISkill xSkill((void*)pSkill);
            IPlayer.Buff(379, 25, 0);
            IPlayer.Buff(380, 3600, 0);
            IPlayer._ShowBattleAnimation(IPlayer, 90);
            IPlayer.SetBuffIcon(25000, 0, 4240, 948);
            IPlayer.AddDef(50 + (xSkill.GetGrade() * 50));
        }
    }
}