void __fastcall ShinRhoe(IChar IPlayer)
{
    if (IPlayer.IsValid() && IPlayer.GetRage() >= 4800)
    {
        int Around = IPlayer.GetObjectListAround(2);

        while(Around)
        {
            IChar Object((void*)*(DWORD*)Around);

            if (Object.IsValid() && IPlayer.IsValid() &&
                    (*(int (__thiscall **)(int, int, DWORD))
                     (*(DWORD *)IPlayer.GetOffset() + 176))
                    ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
            {
                int nDmg = (IPlayer.GetAttack() * TEShinMul);

                if (Object.GetType() == 0)
                    nDmg = nDmg * TEShinReduce / 100;

                IPlayer.OktayDamageArea(Object,nDmg,112);
            }

            Around = CBaseList::Pop((void*)Around);
        }

        IPlayer._ShowBattleAnimation(IPlayer, 112);
        IPlayer.DecreaseRage(4800);
    }
}
