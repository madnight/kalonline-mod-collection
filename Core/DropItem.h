void __fastcall DropItemONPKDie(void *Player, void *edx)
{
    IChar IPlayer(Player);

    if (IPlayer.IsOnline())
    {
        if (strlen(SinCheck) &&
                ((std::string)SinCheck == "disable" ||
                 (std::string)SinCheck == "Disable"))
            return;
        else
            CPlayer::DropItemONPKDie(Player);
    }
}
