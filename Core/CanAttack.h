int __fastcall CanAttack(void *Player, void *edx, int Target, int Value)
{
	IChar IPlayer(Player);
	IChar ITarget((void*)Target);

	if (IPlayer.IsOnline() && ITarget.IsOnline())
	{
		if (IPlayer.GetType() == 0 && ITarget.GetType() == 0)
		{
			if (IPlayer.IsValid() && ITarget.IsValid() && ITarget.IsBuff(327))
				return 0;

			if (IPlayer.IsValid() && ITarget.IsValid() && ITarget.IsBuff(329))
				return 0;

			if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.IsBuff(378) && ITarget.IsBuff(378))
				return 1;

			if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.IsBuff(160) && ITarget.IsBuff(161))
				return 1;

			if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.IsBuff(161) && ITarget.IsBuff(160))
				return 1;

			if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.IsBuff(162) && ITarget.IsBuff(163))
				return 1;

			if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.IsBuff(163) && ITarget.IsBuff(162))
				return 1;

			if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.IsBuff(170) && ITarget.IsBuff(171))
				return 1;

			if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.IsBuff(171) && ITarget.IsBuff(170))
				return 1;

			if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.IsBuff(373) && ITarget.IsBuff(374))
				return 1;

			if (IPlayer.IsValid() && ITarget.IsValid() && IPlayer.IsBuff(374) && ITarget.IsBuff(373))
				return 1;
		}

		return CPlayer::CanAttack(Player,Target,Value);
	} else {
		return 0;
	}
}