int __fastcall OnOk(void *Argument, void *edx)
{
    Interface<IPackets> Packets;

    if (*((DWORD *)Argument + 111) == 1000)
        Packets->Send(254,"dss",1,Packets->RecCaller.c_str(),Packets->Recall.c_str());

    return Engine::KGameSys::OnOk(Argument);
}

int __fastcall OnCancel(void *Argument, void *edx)
{
    Interface<IPackets> Packets;

    if (*((DWORD *)Argument + 111) == 1000)
        Packets->Send(254,"dss",0,Packets->RecCaller.c_str(),Packets->Recall.c_str());

    return Engine::KGameSys::OnCancel(Argument);
}

signed int __cdecl PressKey(int Word, void *edx)
{
    if ( Engine::KGameSys::PressedKey)
    {
        int ReCheck = Engine::KGameSys::Check();
        if ( ReCheck && ReCheck && (*(int (__thiscall **)(int))(*(DWORD *)ReCheck + 148))(ReCheck) )
        {
            return 0;
        } else {
            if ( Word == 118 || Word == 86 )
            {
                if ( !Engine::KGameSys::WindowCheck("Honor") )
                    return Engine::KGameSys::OpenWindow("Honor", 0,0,0,0,0);
                else
                    return Engine::KGameSys::CloseWindow("Honor");
            }

            if ( Word == 66 || Word == 98 )
            {
                Interface<IPackets> Packets;
                Packets->Send(255, "dd", 5, 1);
            }
        }
    }

    return Engine::KGameSys::PressKey(Word);
}