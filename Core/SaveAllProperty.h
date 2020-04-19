int __fastcall SaveAllProperty(int Player, void *edx, int Value)
{
    int result = 0;

    if (*(DWORD*)(Player + 272) >= 32000)
    {
        *(DWORD*)(Player + 1440) = 0;

        if (*(DWORD*)(Player + 276) >= 32000)
            CDBSocket::Write(2,"dbbwIbbbbbbwwwwbbddddb",*(DWORD*)(Player + 452),
                             *(DWORD*)(Player + 60),*(DWORD*)(Player + 464),*(DWORD*)(Player + 468),
                             *(DWORD*)(Player + 472),*(DWORD*)(Player + 476),*(DWORD*)(Player + 536),
                             *(DWORD*)(Player + 64),*(DWORD*)(Player + 68),*(DWORD*)(Player + 72),
                             *(DWORD*)(Player + 76),*(DWORD*)(Player + 80),32000,32000,
                             *(DWORD*)(Player + 544),*(DWORD*)(Player + 548),*(DWORD*)(Player + 552),
                             *(DWORD*)(Player + 316),*(DWORD*)(Player + 332),*(DWORD*)(Player + 336),
                             *(DWORD*)(Player + 340),*(DWORD*)(Player + 580),Value);
        else
            CDBSocket::Write(2,"dbbwIbbbbbbwwwwbbddddb",*(DWORD*)(Player + 452),
                             *(DWORD*)(Player + 60),*(DWORD*)(Player + 464),*(DWORD*)(Player + 468),
                             *(DWORD*)(Player + 472),*(DWORD*)(Player + 476),*(DWORD*)(Player + 536),
                             *(DWORD*)(Player + 64),*(DWORD*)(Player + 68),*(DWORD*)(Player + 72),
                             *(DWORD*)(Player + 76),*(DWORD*)(Player + 80),32000,*(DWORD*)(Player + 276),
                             *(DWORD*)(Player + 544),*(DWORD*)(Player + 548),*(DWORD*)(Player + 552),
                             *(DWORD*)(Player + 316),*(DWORD*)(Player + 332),*(DWORD*)(Player + 336),
                             *(DWORD*)(Player + 340),*(DWORD*)(Player + 580),Value);

        CIOCriticalSection::Enter((struct _RTL_CRITICAL_SECTION*)(Player + 1020));

        if (!Value && *(DWORD*)(Player + 1108))
            CItemTransform::SaveInfo(*(DWORD*)(Player + 1108), 0);

        int Check = *(DWORD*)(Player + 1344);
        *(DWORD*)(Player + 1344) = 0;
        result = CIOCriticalSection::Leave((void*)((char*)Player + 1020));

        if (Check)
            result = CPlayer::MLMAccumFee(Player, Check);
    } else {
        result = CPlayer::SaveAllProperty(Player,Value);
    }

    return result;
}
