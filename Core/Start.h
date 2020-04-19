void __fastcall RealBlob(int Monster, void *edx)
{
    IChar IMonster((void*)Monster);

    if (IMonster.IsValid() && IMonster.GetMobTanker())
    {
        IChar IPlayer((void*)IMonster.GetMobTanker());

        if (IPlayer.IsValid())
        {
            if (!CheckBlob.find(IPlayer.GetPID())->second)
            {
                if (UnBlob.find(IMonster.GetMobIndex())->second)
                {
                    IMonster.SetMobTarget(0);
                    return;
                }

                CChar::Unlock(IMonster.GetOffset());
                IMonster.Blob();
                CChar::Lock(IMonster.GetOffset());
                return;
            }
        }

        (*(int (__thiscall **)(int, DWORD))(*(DWORD *)Monster + 188))(Monster, 0);
    }
}

void __fastcall Start(int Start, void *edx, u_short hostshort)
{
    CIOServer::Start(Start,hostshort);
    Interface<IMemory> Memory;
    Memory->Hook(0x0043DEE1, RealBlob, 0xe8, 6);
    LicenseSerialCheck = true;

    if (strlen(CWTCC) > 0 && (std::string)CWTCC == "true")
    {
        Memory->Copy((void*)0x00411916, &CWTCD, 1);
        Memory->Copy((void*)0x0041191F, &CWTCSH, 1);
        Memory->Copy((void*)0x00411931, &CWTCEH, 1);
    }

    Lisans = 1;
    _beginthread(ContinuesSkill, 0, 0);
}

int __cdecl Black(char *Msg, ...)
{
    std::string GetMsg = std::string(Msg);

    if ( GetMsg.substr(0,2) == "##" || GetMsg.substr(0,2) == "$$" || GetMsg.substr(0,2) == "@@" )
        return 0;

    if ( GetMsg.substr(0,11) == "[SpeedHack]" )
        return 0;

    if ( GetMsg.substr(0,20) == "invalid monster move" )
        return 0;

    if ( GetMsg.substr(0,9) == "move hack" )
        return 0;

    if ( GetMsg.substr(0,41) == "Invalid state at CSocket::Process() Type(" )
        return 0;

    if ( GetMsg.substr(0,20) == "close pending socket" )
        return 0;

    va_list va;
    va_start(va,Msg);
    int Check = CLog::AddV(1,Msg,va);
    va_end(va);
    return Check;
}

int __cdecl Blue(char *Msg, ...)
{
    std::string GetMsg = std::string(Msg);

    if ( GetMsg.substr(0,22) == "new connection in_addr" )
        return 0;

    if ( GetMsg.substr(0,20) == "close pending socket" )
        return 0;

    va_list va;
    va_start(va,Msg);
    int Check = CLog::AddV(0,Msg,va);
    va_end(va);
    return Check;
}