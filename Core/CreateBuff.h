int __fastcall CBuffCBuffPrtyExIsExpired(int Buff, void *edx, int Player)
{
    IChar Object((void*)Player);

    if (*(DWORD*)(Buff + 4) == 400 && Object.IsOnline() && Object.IsValid())
    {
        int Time = ((*(DWORD*)(Buff + 8)) - GetTickCount()) / 1000;
        int Damage = *(DWORD*)(Buff + 12);

        if ((GetTickCount() / 1000) % 2 == 0 && Object.GetCurHp() > 1)
        {
            if (Damage > Object.GetCurHp()) {
                Damage = Object.GetCurHp() - 1;
            }

            Object.DecreaseHp(Damage);

            if (Object.GetType() == 1 &&
                (*(int (__thiscall **)(int))(*(DWORD*)Player + 64))
                (Player)) {
                *(DWORD*)(Player + 472) = GetTickCount() + 20000;
            }
        }
    }

    if (*(DWORD*)(Buff + 4) == 411 && Object.IsOnline())
    {
        int Time = ((*(DWORD*)(Buff + 8)) - GetTickCount()) / 1000;
        int Damage = *(DWORD*)(Buff + 12);

        if (Time == 2)
        {
            Object.AddMaxAttack(Damage);
            Object.AddMinAttack(Damage);
        }
    }

    if (*(DWORD*)(Buff + 4) == 415 && Object.IsOnline())
    {
        int Time = ((*(DWORD*)(Buff + 8)) - GetTickCount()) / 1000;
        int Damage = *(DWORD*)(Buff + 12);

        if (Time == 2) {
            Object.AddDef(Damage);
        }
    }

    if (*(DWORD*)(Buff + 4) == 416 && Object.IsOnline())
    {
        int Time = ((*(DWORD*)(Buff + 8)) - GetTickCount()) / 1000;
        int Damage = *(DWORD*)(Buff + 12);

        if (Time == 2) {
            Object.AddOTP(Damage);
        }
    }

    return CBuff::CBuffPrtyExIsExpired(Buff, Player);
}

int __fastcall CBuffPrtyExFreeBuff(int Buff, void *edx, int Player)
{
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline())
    {
        if (*(DWORD*)(Buff + 4) == 118 && *(DWORD*)(Buff + 28) == 2 &&
            *(DWORD*)(Buff + 12) == -50)
            return (*(int (__cdecl **)(DWORD, DWORD, DWORD, DWORD))
                    (*(DWORD*)Player + 96))(Player, 32, 0, -50);

        return CBuffPrtyEx::FreeBuff(Buff, Player);
    }

    return 0;
}

int __cdecl CreateBuff(int BuffID, __int32 Time, int Stat, int Object)
{
    if (BuffID == 9 && Time == 900 && Stat == 3 && *(DWORD*)(Object + 4) == 10) {
        Stat = 3 * *(DWORD*)(Object + 8);
    }

    if (BuffID == 29 && Object < 0 && Stat < 0)
    {
        Object *= -1;
        Stat *= -1;
    }

    if (BuffID >= 119 && BuffID <= 155)
    {
        int SetTime = 0;

        if (!Stat) {
            SetTime = Time + time(0);
        }

        void *Check = CBuff::CheckBuffCreate(0x20u);

        if (Check) {
            return (int)CBuff::CBuffExpire(Check, BuffID, SetTime, 0, 0, 0, 32);
        }
        else {
            return 0;
        }
    } else if (BuffID >= 156 && BuffID <= 255)
    {
        void *Check = CBuff::CheckBuffCreate(0x28u);

        if (!Check) {
            return 0;
        }

        return CBuff::CBuffRemainPrty(Check, BuffID, Time, 0, 0, 0, 0);
    } else if (BuffID >= 256)
    {
        void *Check = CBuff::CheckBuffCreate(0x2Cu);

        if (!Check) {
            return 0;
        }

        return CBuff::CBuffPrtyEx(Check, BuffID, Time * 1000, 0, 0, 0, 0, 0, 0, 0);
    } else {
        return CBuff::CreateBuff(BuffID, Time, Stat, Object);
    }
}
