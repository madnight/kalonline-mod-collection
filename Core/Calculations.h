int __fastcall Calculations(void *pSkill, void *edx, int Player)
{
    int Value = CSkill::Calculations(pSkill, Player);
    ISkill ISkill(pSkill);
    IChar IPlayer((void*)Player);

    if (Value > 0 && IPlayer.IsOnline())
    {
        if (ConfigCalculations.count((IPlayer.GetClass() * 100) + ISkill.GetIndex()) &&
            IPlayer.GetClass() == ConfigCalculations.find((IPlayer.GetClass() * 100) +
                ISkill.GetIndex())->second.Class &&
            ConfigCalculations.find((IPlayer.GetClass() * 100) +
                ISkill.GetIndex())->second.Rate && Value > 100)
            Value += ((Value * ConfigCalculations.find((IPlayer.GetClass() * 100) +
                            ISkill.GetIndex())->second.Rate) / 100);

        if (IPlayer.GetSpecialty() == 43 && IPlayer.GetClass() == 1)
        {
            if (ISkill.GetIndex() == 8 || ISkill.GetIndex() == 10 ||
                ISkill.GetIndex() == 22 || ISkill.GetIndex() == 28 ||
                ISkill.GetIndex() == 29 || ISkill.GetIndex() == 35 ||
                ISkill.GetIndex() == 55 || ISkill.GetIndex() == 57 ||
                ISkill.GetIndex() == 58 || ISkill.GetIndex() == 59) {
                Value += (IPlayer.GetLevel() * IPlayer.GetLevel()) / 10;
            }
        }

        if ((IPlayer.GetSpecialty() == 43 || IPlayer.GetSpecialty() == 11) &&
            IPlayer.GetClass() == 1)
        {
            if (ISkill.GetIndex() == 8 || ISkill.GetIndex() == 10 ||
                ISkill.GetIndex() == 22 || ISkill.GetIndex() == 28 ||
                ISkill.GetIndex() == 29 || ISkill.GetIndex() == 35 ||
                ISkill.GetIndex() == 55 || ISkill.GetIndex() == 57 ||
                ISkill.GetIndex() == 58 || ISkill.GetIndex() == 59) {
                IPlayer.IncreaseRage(MRIAmount);
            }
        }
    }

    return Value;
}
