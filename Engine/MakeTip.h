int CheckArmorGrade = 0;

int __fastcall MyArmorGetGrade(int a, void *edx)
{
    int check = Engine::KGameSys::ArmorGrade(a);

    if (check)
        CheckArmorGrade = *(DWORD *)(check + 268);

    return check;
}

int __cdecl BofStatFix(int a1, void *edx, const char *a2)
{
    if (CheckArmorGrade && CheckArmorGrade > 90)
        return Engine::KGameSys::AddMsg(a1,"#nStrength 9#nIntelligence 9#nAgility 9#n");
    else
        return Engine::KGameSys::AddMsg(a1,"#n");
}

void BofFix()
{
    Interface<ITools> Tools;
    Tools->Intercept(ITools::_I_CALL, (void*)0x004B5E58, MyArmorGetGrade, 5);
    Tools->Intercept(ITools::_I_CALL, (void*)0x004B5F6A, BofStatFix, 5);
}

void __fastcall MakeTip(void *a, void *edx, int a2, int a3, signed int a4, char a5, int a6, int a7)
{
    Engine::KGameSys::MakeTip(a, a2, a3, a4, a5, a6, a7);
}