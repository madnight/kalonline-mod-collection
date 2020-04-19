int __fastcall CheckBuff(void *Argument, void *edx, int Value, int Player)
{
	void *Check = CPlayer::FindPlayer(Player);

	if (!Check)
		return 0;
	
	return 1;
}