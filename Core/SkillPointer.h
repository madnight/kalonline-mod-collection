bool __stdcall MySkillPointer(int Value,int Argument)
{
    bool Check = CSkill::SkillPointers(Value,Argument);

    if ((*(DWORD*)Argument > 36 && *(DWORD*)Argument < 45)
            || *(DWORD*)Argument == 70 || *(DWORD*)Argument == 71
            || *(DWORD*)Argument == 82 || *(DWORD*)Argument == 87
            || *(DWORD*)Argument == 88 || *(DWORD*)Argument == 89
            || *(DWORD*)Argument == 90 || *(DWORD*)Argument == 91
            || *(DWORD*)Argument == 92 || *(DWORD*)Argument == 93
            || *(DWORD*)Argument == 94 || *(DWORD*)Argument == 95
            || *(DWORD*)Argument == 79)
    {
        if (Check == true)
            return false;
        else
            return true;
    }

    if ((*(DWORD*)Argument > 65598 && *(DWORD*)Argument < 65613)
            || *(DWORD*)Argument == 65618 || *(DWORD*)Argument == 65623
            || *(DWORD*)Argument == 65624 || *(DWORD*)Argument == 65625
            || *(DWORD*)Argument == 65615 || *(DWORD*)Argument == 65626
            || *(DWORD*)Argument == 65627 || *(DWORD*)Argument == 65628
            || *(DWORD*)Argument == 65629 || *(DWORD*)Argument == 65630
            || *(DWORD*)Argument == 65631)
    {
        if (Check == true)
            return false;
        else
            return true;
    }

    if ((*(DWORD*)Argument > 131117 && *(DWORD*)Argument < 131124)
            || *(DWORD*)Argument == 131142 || *(DWORD*)Argument == 131143
            || *(DWORD*)Argument == 131154 || *(DWORD*)Argument == 131159
            || *(DWORD*)Argument == 131160 || *(DWORD*)Argument == 131161
            || *(DWORD*)Argument == 131151 || *(DWORD*)Argument == 131162
            || *(DWORD*)Argument == 131163 || *(DWORD*)Argument == 131164
            || *(DWORD*)Argument == 131165 || *(DWORD*)Argument == 131166
            || *(DWORD*)Argument == 131167)
    {
        if (Check == true)
            return false;
        else
            return true;
    }

    if ((*(DWORD*)Argument > 196607 && *(DWORD*)Argument < 196646)
            || *(DWORD*)Argument == 196671 || *(DWORD*)Argument == 196678
            || *(DWORD*)Argument == 196695 || *(DWORD*)Argument == 196696
            || *(DWORD*)Argument == 196697 || *(DWORD*)Argument == 196698
            || *(DWORD*)Argument == 196699 || *(DWORD*)Argument == 196700
            || *(DWORD*)Argument == 196701 || *(DWORD*)Argument == 196702
            || *(DWORD*)Argument == 196703 || *(DWORD*)Argument == 196687)
    {
        if (Check == true)
            return false;
        else
            return true;
    }

    if (*(DWORD*)Argument > 262143 && *(DWORD*)Argument < 262243)
    {
        if (Check == true)
            return false;
        else
            return true;
    }

    return Check;
}

void SetSkillPointer()
{
    Interface<IMemory> Memory;
    Memory->Hook(0x00446EE6, MySkillPointer,0xe8,5);
}