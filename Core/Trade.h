void __fastcall CancelTrade(void *Player, void *edx)
{
	IChar IPlayer(Player);

	if (IPlayer.IsOnline())
	{
		CPlayer::CancelTrade(Player);
		IPlayer.CancelBuff(257);
	}
}

void __fastcall TradeAgreed(void *Player, void *edx)
{
	IChar IPlayer(Player);

	if (IPlayer.IsOnline())
	{
		CPlayer::TradeAgreed(Player);
		IPlayer.CancelBuff(257);
	}
}

void __fastcall ShowOffItem(void *Player, void *edx, int Amount, void *pPacket, int pPos)
{
	IChar IPlayer(Player);

	if (IPlayer.IsOnline())
	{
		if (IPlayer.IsBuff(257))
		{
			IPlayer.SystemMessage("You only can upload once on the trading list.",TEXTCOLOR_RED);
			return;
		}

		CPlayer::ShowOffItem(Player,Amount,pPacket,pPos);
		IPlayer.Buff(257,604800,0);
	}
}