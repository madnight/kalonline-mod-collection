void __fastcall RevolveAttack(IChar IPlayer)
{
    if (IPlayer.IsValid() && IPlayer.GetRage() >= 15000)
    {
        int Around = IPlayer.GetObjectListAround(2);

        while (Around)
        {
            IChar Object((void*)*(DWORD*)Around);

            if (Object.IsValid() && IPlayer.IsValid() &&
                (*(int (__thiscall **)(int, int, DWORD))
                    (*(DWORD *)IPlayer.GetOffset() + 176))
                ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
            {
                int nDmg = (IPlayer.GetAttack() * ERAMul);

                if (Object.GetType() == 0) {
                    nDmg = (nDmg * ERAReduce) / 100;
                }

                IPlayer.OktayDamageSingle(Object, nDmg, 113);
            }

            Around = CBaseList::Pop((void*)Around);
        }

        IPlayer.DecreaseRage(15000);
    }
}
