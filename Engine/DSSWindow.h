static int (__thiscall *KalItemShop1)(void *a, const char *a2, int a3) = (int (__thiscall*)(void*,const char*,int))0x00583C50;
static int (__thiscall *KalItemShop2)(void *a, const char *a2, int a3) = (int (__thiscall*)(void*,const char*,int))0x00583D60;
static int (__thiscall *KalItemShop3)(void *a, const char *a2, int a3) = (int (__thiscall*)(void*,const char*,int))0x00586AD0;
static int (__stdcall *KalShop)(char a1) = (int (__stdcall*)(char))0x00586A20;
static int (__cdecl *ShopKal)() = (int (__cdecl*)())0x00583490;
static int (__thiscall *UnknownShop)(void *a) = (int (__thiscall*)(void*))0x0065EE90;

int __fastcall MyKalItemShop1(void *a, void *edx, const char *a2, int a3)
{
    if (_stricmp(a2, "cancel") && _stricmp(a2, "close"))
    {
        if (!_stricmp(a2, "ok"))
        {
            if (*((DWORD*)a + 111))
            {
                if (!*((BYTE*)a + 452))
                {
                    *((BYTE*)a + 452) = 1;
                    KalShop(0);
                    Interface<IPackets> Packets;
                    Packets->Send(183, "bbdw", 4, *(BYTE*)(ShopKal() + 4), *((DWORD*)a + 112), *((DWORD*)a + 110));
                }
            }

            return (*(int (__thiscall **)(void *))(*(DWORD *)a + 232))(a);
        }
    }

    return KalItemShop1(a,a2,a3);
}

int __fastcall MyKalItemShop2(void *a, void *edx, const char *a2, int a3)
{
    if (_stricmp(a2, "cancel") && _stricmp(a2, "close"))
    {
        if (!_stricmp(a2, "ok"))
        {
            if (*((DWORD*)a + 111))
            {
                if (!*((BYTE*)a + 452))
                {
                    *((BYTE*)a + 452) = 1;
                    KalShop(0);
                    Interface<IPackets> Packets;
                    Packets->Send(183, "bbdw", 4, *(BYTE*)(ShopKal() + 4), *((DWORD*)a + 112), *((DWORD*)a + 110));
                }
            }

            return (*(int (__thiscall **)(void *))(*(DWORD *)a + 232))(a);
        }
    }

    return KalItemShop2(a,a2,a3);
}

int __fastcall MyKalItemShop3(void *a, void *edx, const char *a2, int a3)
{
    if (_stricmp(a2, "cancel") && _stricmp(a2, "close"))
    {
        if (!_stricmp(a2, "ok"))
        {
            if (*((DWORD*)a + 111) && !*((BYTE*)a + 480))
            {
                *((BYTE*)a + 480) = 1;
                KalShop(0);
                Interface<IPackets> Packets;
                if (*((DWORD*)a + 119) < 16u)
                    Packets->Send(183, "bbdws", 2, *(BYTE*)(ShopKal() + 4), *((DWORD*)a + 112), *((DWORD*)a + 110), (int)((char*)a + 456));
                else
                    Packets->Send(183, "bbdws", 2, *(BYTE*)(ShopKal() + 4), *((DWORD*)a + 112), *((DWORD*)a + 110), *((DWORD*)a + 114));
            }

            return (*(int (__thiscall **)(void *))(*(DWORD *)a + 232))(a);
        }
    }

    return KalItemShop3(a,a2,a3);
}

void __fastcall CheckForDss(int Item, void *edx)
{
    Interface<IPackets> Packets;

    if (Packets->DssUpdateCheck == true && *(DWORD*)(Item + 880) == 0 && *(DWORD*)(Item + 888) == 0)
    {
        *(DWORD*)(*(DWORD*)(Item + 872) + 184) = 1;
        (*(void (__thiscall **)(void *))(*(DWORD *)Item + 260))((void*)Item);
        *(DWORD*)(Item + 888) = 1;
        *(DWORD*)(Item + 880) = GetTickCount();
        int Msg = Engine::KGameSys::KMsgGet(3574);
        Engine::KGameSys::SetChangedText(Item, (int)"convers_title", Msg);
        *(float*)(Item + 884) = 3000.0;
    }

    Engine::KGameSys::CheckForDss(Item);
    Packets->DssUpdateCheck = false;

    if (*(DWORD*)(Item + 880) == 0 && *(DWORD*)(Item + 888) == 0)
    {
        *(DWORD*)(*(DWORD*)(Item + 872) + 184) = 0;
        Engine::KGameSys::SetChangedText(Item, (int)"convers_title", (int)" ");
        Engine::KGameSys::SetChangedText(Item, (int)"convers_per", (int)" ");
    }
}
