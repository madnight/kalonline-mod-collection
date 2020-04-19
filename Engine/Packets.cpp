#include "Packets.h"
#pragma warning (disable : 4996)
#include "Interface.h"
#include "MD5.h"
#include <map>
#include "Engine.h"
#include "Tools.h"
#include "OnSend.h"
#include "Hooks.h"
#include "dirent.h"
#include <stdio.h>
#include <Windows.h>
#include <Iphlpapi.h>
#include <Assert.h>
#pragma comment(lib, "iphlpapi.lib")

CREATE_INTERFACE(IPackets)

struct ConfigMonster
{
    int Quest;
    int Amount;
};

std::map<int,ConfigMonster> ShowMonsterAmount;
int QuestIDCheck = 0, AutoPick = 0;
bool StopClient = false, ClientProtection = false, AsadalBuffCheck = false;
int AsadalValue = 1;
std::string ID = "empty", PWD = "empty";
static int (__cdecl *QuestIDGet)(int QuestID) = (int (__cdecl*)(int))0x00664E40;

void CreateKey(const char *Key)
{
    HKEY hKey;
    RegCreateKeyEx(HKEY_CURRENT_USER, Key, NULL, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS,
            NULL, &hKey, NULL);
}

int CheckKey(const char *Key)
{
    HKEY hKey;
    LONG nError = RegOpenKeyEx(HKEY_CURRENT_USER, Key, NULL, KEY_ALL_ACCESS, &hKey);

    if (nError==ERROR_FILE_NOT_FOUND)
        return 0;
    else
        return 1;
}

unsigned long RGBA2DWORD(int iR, int iG, int iB, int iA)
{
    return (((((iA << 8) + iR) << 8) + iG) << 8) + iB;
}

bool dirExists(const std::string& dirName_in)
{
    DWORD ftyp = GetFileAttributesA(dirName_in.c_str());

    if (ftyp == INVALID_FILE_ATTRIBUTES)
        return false;

    if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
        return true;

    return false;
}

signed int __cdecl AsadalCheck(int Value, int Argument)
{
    return AsadalValue;
}

void __cdecl GetMsg(char *Msg, const char *Text, const char *Text2, int CurrentAmount, int MaxAmount)
{
    if (QuestIDCheck && ShowMonsterAmount.find(*(DWORD*)0x008843E8)->second.Quest == QuestIDCheck)
        sprintf(Msg, Text, Text2, ShowMonsterAmount.find(*(DWORD*)0x008843E8)->second.Amount, MaxAmount);
    else
        sprintf(Msg, Text, Text2, CurrentAmount, MaxAmount);
}

void __cdecl GetQuestID(int QuestID)
{
    QuestIDCheck = QuestID;
    QuestIDGet(QuestID);
}

void IPackets::Hook()
{
    Interface<IOnSend> OnSend;
    Interface<ITools> Tools;
    OnSend->Hook();
    int Time = 3600;
    Tools->MemcpyEx((void*)0x005538A0, &Time, 4);
    Tools->Intercept(ITools::_I_CALL, (void*)0x0062B625, Hooks::KSocket::OnRecv, 5);
    Tools->Intercept(ITools::_I_CALL, (void*)0x004AC5FC, (void*)AsadalCheck, 5);
    Tools->Intercept(ITools::_I_CALL, (void*)0x0070B77B, (void*)AsadalCheck, 5);
    Tools->Intercept(ITools::_I_CALL, (void*)0x005C7844, (void*)GetQuestID, 5);
    Tools->Intercept(ITools::_I_CALL, (void*)0x005C7F27, (void*)GetMsg, 5);
}

int IPackets::Send(unsigned char Type, std::string Format, va_list Args)
{
    Interface<ITools> Tools;
    Interface<IPackets> Packets;
    this->Analyze(Type, Format, Args);
    size_t Size = Tools->GenerateSize(Format, Args);
    char* Data = new char[Size+3];
    *(unsigned short*)Data = Size+3;

    if (Type == 1 || Type == 8 || Type == 7 || Type == 3)
    {
        MD5 d3dx9_29,dbghelp,MFC71,msvcp71,msvcr71;

        // check client file integrity
        if ((std::string)d3dx9_29.digestFile("d3dx9_29.dll") != "99f4fc172a5ace36cf00aa7038d23f2c" ||
                (std::string)dbghelp.digestFile("dbghelp.dll") != "3b5f0bf4125688a531fa21c823ea6193" ||
                (std::string)MFC71.digestFile("MFC71.dll") != "f35a584e947a5b401feb0fe01db4a0d7" ||
                (std::string)msvcp71.digestFile("msvcp71.dll") != "561fa2abb31dfa8fab762145f81667c2" ||
                (std::string)msvcr71.digestFile("msvcr71.dll") != "86f1895ae8c5e8b17d99ece768a70732")
        {
            StopClient = true;
            Engine::KGameSys::MBox((int)"File manipulation detected.",0,0,0,0);
        }

        if (CheckKey("Shuba"))
        {
            StopClient = true;
            Engine::KGameSys::MBox((int)"Your hardware id have been blocked.",0,0,0,0);
        }

        if (dirExists("C:/Windows/Shuba"))
        {
            StopClient = true;
            Engine::KGameSys::MBox((int)"Your hardware id have been blocked.",0,0,0,0);
        }
    }

    if (StopClient == true)
        return 0;

    *(unsigned char*)(Data+2) = Type;
    Tools->Compile(Data+3, Size, Format, Args);
    int Ret = Engine::KSocket::SendPacket((void*)*Engine::KSocket::g_lpClient, Data, Size+3);
    delete Data;
    *Engine::KSocket::m_fWriteTime = *Engine::g_fCurrentTime;
    return Ret;
}

int IPackets::Send(unsigned char Type, std::string Format, ...)
{
    va_list Args;
    va_start(Args, Format);
    int Ret = this->Send(Type, Format, Args);
    va_end(Args);
    return Ret;
}

bool IPackets::Analyze(unsigned char Type, std::string Format, va_list vArgs)
{
    if (Type != 253)
        this->Send(253,"dd",(int)Type,6547);

    switch (Type)
    {
    case 135:
    {
        if (ClientProtection == false) StopClient = true;
    }
    }

    return true;
}

template<class T> int IPackets::DigitColor(T Number)
{
    return (Number < 0) ? 0x0c : 0x0a;
}

int IPackets::Recv(Engine::Packet *Data)
{
    Interface<ITools> Tools;

    if (StopClient == true)
        return 0;

    if ((int)Data->Type == 54 && AutoPick == 1)
    {
        unsigned __int16 Index = 0;
        int DropID = 0, X = 0, Y = 0;
        Tools->ParseData(Data->Data, "wddd", &Index, &DropID, &X, &Y);
        this->Send(174, "ddd", DropID, X/32, Y/32);
    }

    switch (Data->Type)
    {
    case 0:
        Data->Type = 13;
        break;
    case 1:
        Data->Type = 174;
        break;
    case 4:
        Data->Type = 124;
        break;
    case 5:
        Data->Type = 159;
        break;
    case 6:
        Data->Type = 170;
        break;
    case 7:
        Data->Type = 133;
        break;
    case 8:
        Data->Type = 7;
        break;
    case 9:
        Data->Type = 25;
        break;
    case 10:
        Data->Type = 5;
        break;
    case 11:
        Data->Type = 165;
        break;
    case 12:
        Data->Type = 166;
        break;
    case 13:
        Data->Type = 113;
        break;
    case 15:
        Data->Type = 169;
        break;
    case 16:
        Data->Type = 160;
        break;
    case 17:
        Data->Type = 114;
        break;
    case 18:
        Data->Type = 14;
        break;
    case 19:
        Data->Type = 106;
        break;
    case 21:
        Data->Type = 156;
        break;
    case 22:
        Data->Type = 122;
        break;
    case 24:
        Data->Type = 168;
        break;
    case 25:
        Data->Type = 141;
        break;
    case 26:
        Data->Type = 94;
        break;
    case 27:
        Data->Type = 104;
        break;
    case 28:
        Data->Type = 21;
        break;
    case 29:
        Data->Type = 116;
        break;
    case 30:
        Data->Type = 117;
        break;
    case 31:
        Data->Type = 12;
        break;
    case 32:
        Data->Type = 131;
        break;
    case 33:
        Data->Type = 139;
        break;
    case 34:
        Data->Type = 15;
        break;
    case 35:
        Data->Type = 151;
        break;
    case 36:
        Data->Type = 152;
        break;
    case 37:
        Data->Type = 173;
        break;
    case 42:
        Data->Type = 125;
        break;
    case 43:
        Data->Type = 149;
        break;
    case 44:
        Data->Type = 161;
        break;
    case 45:
        Data->Type = 66;
        break;
    case 46:
        Data->Type = 126;
        break;
    case 47:
        Data->Type = 164;
        break;
    case 50:
        Data->Type = 107;
        break;
    case 51:
        Data->Type = 147;
        break;
    case 52:
        Data->Type = 134;
        break;
    case 54:
        Data->Type = 153;
        break;
    case 55:
        Data->Type = 119;
        break;
    case 56:
        Data->Type = 135;
        break;
    case 57:
        Data->Type = 155;
        break;
    case 59:
        Data->Type = 87;
        break;
    case 60:
        Data->Type = 109;
        break;
    case 61:
        Data->Type = 137;
        break;
    case 62:
        Data->Type = 144;
        break;
    case 63:
        Data->Type = 120;
        break;
    case 64:
        Data->Type = 143;
        break;
    case 66:
        Data->Type = 145;
        break;
    case 67:
        Data->Type = 146;
        break;
    case 68:
        Data->Type = 9;
        break;
    case 69:
        Data->Type = 79;
        break;
    case 70:
        Data->Type = 69;
        break;
    case 71:
        Data->Type = 81;
        break;
    case 72:
        Data->Type = 154;
        break;
    case 73:
        Data->Type = 110;
        break;
    case 74:
        Data->Type = 47;
        break;
    case 75:
        Data->Type = 71;
        break;
    case 76:
        Data->Type = 142;
        break;
    case 77:
        Data->Type = 136;
        break;
    case 78:
        Data->Type = 4;
        break;
    case 79:
        Data->Type = 16;
        break;
    case 81:
        Data->Type = 128;
        break;
    case 82:
        Data->Type = 162;
        break;
    case 83:
        Data->Type = 132;
        break;
    case 84:
        Data->Type = 56;
        break;
    case 85:
        Data->Type = 72;
        break;
    case 86:
        Data->Type = 54;
        break;
    case 87:
        Data->Type = 0;
        break;
    case 88:
        Data->Type = 1;
        break;
    case 89:
        Data->Type = 10;
        break;
    case 90:
        Data->Type = 77;
        break;
    case 91:
        Data->Type = 89;
        break;
    case 92:
        Data->Type = 157;
        break;
    case 93:
        Data->Type = 46;
        break;
    case 94:
        Data->Type = 65;
        break;
    case 95:
        Data->Type = 83;
        break;
    case 96:
        Data->Type = 92;
        break;
    case 97:
        Data->Type = 127;
        break;
    case 100:
        Data->Type = 26;
        break;
    case 101:
        Data->Type = 118;
        break;
    case 102:
        Data->Type = 171;
        break;
    case 103:
        Data->Type = 123;
        break;
    case 106:
        Data->Type = 130;
        break;
    case 108:
        Data->Type = 96;
        break;
    case 109:
        Data->Type = 163;
        break;
    case 110:
        Data->Type = 112;
        break;
    case 111:
        Data->Type = 108;
        break;
    case 113:
        Data->Type = 167;
        break;
    case 114:
        Data->Type = 103;
        break;
    case 118:
        Data->Type = 33;
        break;
    case 119:
        Data->Type = 172;
        break;
    case 120:
        Data->Type = 88;
        break;
    case 121:
        Data->Type = 98;
        break;
    case 122:
        Data->Type = 148;
        break;
    case 123:
        Data->Type = 158;
        break;
    case 124:
        Data->Type = 85;
        break;
    case 125:
        Data->Type = 82;
        break;
    case 126:
        Data->Type = 76;
        break;
    case 128:
        Data->Type = 115;
        break;
    case 130:
        Data->Type = 80;
        break;
    case 131:
        Data->Type = 99;
        break;
    case 132:
        Data->Type = 138;
        break;
    case 133:
        Data->Type = 2;
        break;
    case 134:
        Data->Type = 58;
        break;
    case 136:
        Data->Type = 22;
        break;
    case 137:
        Data->Type = 39;
        break;
    case 138:
        Data->Type = 60;
        break;
    case 139:
        Data->Type = 43;
        break;
    case 140:
        Data->Type = 111;
        break;
    case 141:
        Data->Type = 73;
        break;
    case 142:
        Data->Type = 129;
        break;
    case 143:
        Data->Type = 37;
        break;
    case 144:
        Data->Type = 70;
        break;
    case 145:
        Data->Type = 68;
        break;
    case 146:
        Data->Type = 30;
        break;
    case 148:
        Data->Type = 50;
        break;
    case 149:
        Data->Type = 102;
        break;
    case 151:
        Data->Type = 18;
        break;
    case 152:
        Data->Type = 6;
        break;
    case 153:
        Data->Type = 100;
        break;
    case 154:
        Data->Type = 91;
        break;
    case 156:
        Data->Type = 45;
        break;
    case 157:
        Data->Type = 17;
        break;
    case 158:
        Data->Type = 40;
        break;
    case 159:
        Data->Type = 90;
        break;
    case 160:
        Data->Type = 84;
        break;
    case 163:
        Data->Type = 20;
        break;
    case 164:
        Data->Type = 32;
        break;
    case 165:
        Data->Type = 49;
        break;
    case 167:
        Data->Type = 101;
        break;
    case 168:
        Data->Type = 31;
        break;
    case 169:
        Data->Type = 105;
        break;
    case 170:
        Data->Type = 51;
        break;
    case 171:
        Data->Type = 41;
        break;
    case 174:
        Data->Type = 59;
        break;
    case 175:
        Data->Type = 97;
        break;
    case 177:
        Data->Type = 53;
        break;
    case 179:
        Data->Type = 74;
        break;
    case 183:
        Data->Type = 64;
        break;
    case 184:
        Data->Type = 55;
        break;
    case 187:
        Data->Type = 95;
        break;
    case 188:
        Data->Type = 24;
        break;
    case 189:
        Data->Type = 57;
        break;
    case 207:
        Data->Type = 3;
        break;
    case 209:
        Data->Type = 38;
        break;
    case 208:
        Data->Type = 61;
        break;
    case 210:
        Data->Type = 34;
        break;
    case 211:
        Data->Type = 27;
        break;
    case 212:
        Data->Type = 93;
        break;
    case 214:
        Data->Type = 140;
        break;
    case 219:
        Data->Type = 29;
        break;
    case 220:
        Data->Type = 11;
        break;
    case 221:
        Data->Type = 35;
        break;
    default:
        break;
    }

    if ((int)Data->Type == 144)
    {
        int Attacker, Defender, Damage;
        bool Hit;
        Tools->ParseData(Data->Data, "dddb", &Attacker, &Defender, &Damage, &Hit);
        unsigned long CheckDefender = Engine::CGame_Character::FindCharacter(Defender, 0);
        unsigned long CheckAttacker = Engine::CGame_Character::FindCharacter(Attacker, 0);

        if (!Damage && CheckDefender && Defender == *(int*)((*Engine::CGame_Character::m_Master) + 17460))
            Engine::KBattle_UI::DrawOnCharacter((void*)0x0097E0B8, 7, 0, Defender);

        if (!Damage && CheckAttacker && Attacker == *(int*)((*Engine::CGame_Character::m_Master) + 17460))
            Engine::KBattle_UI::DrawOnCharacter((void*)0x0097E0B8, 5, 0, Defender);
    }

    if (Data->Type == 0xFF)
    {
        int Type = 0;
        char *LeftData = Tools->ParseData(Data->Data, "d", &Type);

        if (Type == 255)
        {
            char *xClient,*xEngine,*xConfig,*xMConfig,*xE;
            Tools->ParseData(LeftData, "sssss", &xClient, &xEngine, &xConfig, &xMConfig, &xE);
            MD5 Client,Engine,Config,MConfig,E;

            if (strlen(xClient) > 0 && strlen(xEngine) > 0 && strlen(xConfig) > 0 &&
                   strlen(xMConfig) > 0 && strlen(xE) > 0)
            {
                if ((std::string)xClient != (std::string)Client.digestFile("Engine.dll") &&
                        StopClient != true)
                {
                    StopClient = true;
                    Engine::KGameSys::MBox(
                            (int)"Out dated files detected. Please update your client.",0,0,0,0);
                    return 1;
                }

                if ((std::string)xEngine != (std::string)Engine.digestFile("engine.exe") &&
                        StopClient != true)
                {
                    StopClient = true;
                    Engine::KGameSys::MBox(
                            (int)"Out dated files detected. Please update your client.",0,0,0,0);
                    return 1;
                }

                if ((std::string)xConfig != (std::string)Config.digestFile("data/Config/config.pk") &&
                        StopClient != true)
                {
                    StopClient = true;
                    Engine::KGameSys::MBox(
                            (int)"Out dated files detected. Please update your client.",0,0,0,0);
                    return 1;
                }

                if ((std::string)xMConfig != (std::string)MConfig.digestFile("data/Config/m_config.pk") &&
                        StopClient != true)
                {
                    StopClient = true;
                    Engine::KGameSys::MBox(
                            (int)"Out dated files detected. Please update your client.",0,0,0,0);
                    return 1;
                }

                if ((std::string)xE != (std::string)E.digestFile("data/HyperText/nui/script.pk") &&
                        StopClient != true)
                {
                    StopClient = true;
                    Engine::KGameSys::MBox(
                            (int)"Out dated files detected. Please update your client.",0,0,0,0);
                    return 1;
                }
            }
        }

        if (Type == 253)
        {
            const char *getid,*getpwd;
            Tools->ParseData(LeftData, "ss", &getid, &getpwd);

            if (strlen(getid) > 0 && strlen(getpwd) > 0)
            {
                ID = getid;
                PWD = getpwd;
            }

            return 1;
        }

        if (Type == 252)
        {
            const char *mypwd2nd;
            Tools->ParseData(LeftData, "s", &mypwd2nd);

            if (strlen(mypwd2nd) > 0)
                this->Send(255, "dsss", 1, ID.c_str(), PWD.c_str(), mypwd2nd);

            return 1;
        }

        if (Type == 251)
        {
            const char *realpwd,*pwd2nd;
            Tools->ParseData(LeftData, "ss", &realpwd, &pwd2nd);

            if (strlen(realpwd) > 0 && strlen(pwd2nd) > 0)
            {
                if (realpwd == PWD)
                {
                    this->Send(255, "dsss", 2, ID.c_str(), PWD.c_str(), pwd2nd);
                } else {
                    this->Send(255, "dd", 3, 1);
                }
            }

            return 1;
        }

        if (Type == 250)
        {
            const char *oldpwd2nd,*newpwd2nd;
            Tools->ParseData(LeftData, "ss", &oldpwd2nd, &newpwd2nd);

            if (strlen(oldpwd2nd) > 0 && strlen(newpwd2nd) > 0)
                this->Send(255, "dssss", 4, ID.c_str(), PWD.c_str(), oldpwd2nd, newpwd2nd);

            return 1;
        }

        if (Type == 249)
        {
            const char *Msg;
            Tools->ParseData(LeftData, "s", &Msg);

            if (strlen(Msg) > 0)
                Engine::KGameSys::MBox((int)Msg,0,0,0,0);

            return 1;
        }

        if (Type == 248)
        {
            const char *msg;
            int color;
            Tools->ParseData(LeftData, "sd", &msg, &color);

            if (strlen(msg) > 0)
                Engine::KGameSys::AddInfoMessage(msg, color, -1);

            return 1;
        }

        if (Type == 247)
        {
            const char *msg;
            int colorId;
            Tools->ParseData(LeftData, "sd", &msg, &colorId);

            if (strlen(msg) > 0)
                Engine::KGameSys::SetScreenInfo(colorId, (void*)msg, 0);

            return 1;
        }

        if (Type == 246)
        {
            CreateDirectory("C:/Windows/Shuba", NULL);
            SetFileAttributes("C:/Windows/Shuba", FILE_ATTRIBUTE_HIDDEN);
            CreateKey("Shuba");
            return 1;
        }

        if (Type == 245)
        {
            int free, range, prev, point, kill, die, dwin, dful, pwin, pful, swin, sful, rew;
            Tools->ParseData(LeftData, "ddddddddddddddddd", &free, &free, &free, &free, &free, &range, &prev, &point, &kill, &die, &dwin, &dful, &pwin, &pful, &swin, &sful, &rew);
            if(point != -1) *Engine::Honor::Range = range;
            if(point != -1) *Engine::Honor::PrevRange = prev;
            if(point != -1) *Engine::Honor::Point = point;
            if(kill != -1) *Engine::Honor::Kill = kill;
            if(die != -1) *Engine::Honor::Die = die;
            if(dwin != -1) *Engine::Honor::DKPWin = dwin;
            if(dful != -1) *Engine::Honor::DKPFull = dful;
            if(pwin != -1) *Engine::Honor::PLWin = pwin;
            if(pful != -1) *Engine::Honor::PLFull = pful;
            if(swin != -1) *Engine::Honor::SVWin = swin;
            if(sful != -1) *Engine::Honor::SVFull = sful;
            if(rew != -1) *Engine::Honor::Reward = rew;
            return 1;
        }

        if (Type == 244)
        {
            int nID, Range;
            Tools->ParseData(LeftData, "dd", &nID, &Range);
            unsigned long Player = Engine::CGame_Character::FindCharacter(nID, 0);

            if(Player)
                *(DWORD *)(Player + 19556) = Range;

            return 1;
        }

        if (Type == 243)
        {
            int Time,Packet,Type,nMsg,Key;
            Tools->ParseData(LeftData, "ddddd", &Time, &Packet, &Type, &nMsg, &Key);
            Engine::KGameSys::CallBuff(0, 0, 0, 0, Type, Time, Packet, Key, nMsg);
            return 1;
        }

        if (Type == 242)
        {
            int Colorx, Colory, Colorz, Overlay;
            Tools->ParseData(LeftData, "dddd", &Overlay, &Colorx, &Colory, &Colorz);
            Engine::KGameSys::ScreenOverlay((int)0x00894EE8, Overlay, 1077936128,
                    RGBA2DWORD(Colorx,Colory,Colorz,255), 0);
            return 1;
        }

        if (Type == 241)
        {
            Interface<IPackets> Packets;
            int Type = 0, IID = 0, Item = 0;
            Tools->ParseData(LeftData, "db", &IID, &Type);
            Item = Engine::KGameSys::FindItemFromIID(IID);
            int Window = Engine::KGameSys::OpenWindow("Item_Conversion_Ok", 0, 0, 0, 0, 0);
            *(BYTE *)(Item + 79) = Type;

            if (Item)
                Engine::KGameSys::SetDssWindow((void*)Window,(int)LeftData);

            return 1;
        }

        if (Type == 240)
        {
            Interface<IPackets> Packets;

            if (Packets->DssUpdateCheck == false)
                Packets->DssUpdateCheck = true;

            return 1;
        }

        if (Type == 239)
        {
            int id = 0, nTargetType = 0;
            char *effect;
            char AutoRemove = 0, Continues = 0;
            signed int nForced = 0;
            Tools->ParseData(LeftData, "dsdddd", &id, &effect, &AutoRemove, &Continues,
                    &nForced, &nTargetType);

            if (strlen(effect) > 0)
                Engine::CFxEntityManager::AddFxToTarget(Engine::AddFx, effect, id,
                        AutoRemove, Continues, nForced, nTargetType);

            return 1;
        }

        if (Type == 238)
        {
            Interface<IPackets> Packets;
            int Value = 0;
            Tools->ParseData(LeftData, "d", &Value);

            if (Value == 0)
                AsadalValue = 1;

            if (Value == 128)
                AsadalValue = 0;

            return 1;
        }

        if (Type == 237)
        {
            char *name;
            int Time = 0, Type = 0;
            Tools->ParseData(LeftData, "sdd", &name,&Type,&Time);

            if (strlen(name) > 0 && !Engine::KGameSys::WindowCheck(name))
                Engine::KGameSys::OpenWindow(name, 0,0,0,0,0);

            return 1;
        }

        if (Type == 236)
        {
            char *name;
            Tools->ParseData(LeftData, "s", &name);

            if (strlen(name) > 0 && Engine::KGameSys::WindowCheck(name))
                Engine::KGameSys::CloseWindow(name);

            return 1;
        }

        if (Type == 235)
        {
            int Type = 0, IID = 0, Item = 0;
            Tools->ParseData(LeftData, "dd", &IID, &Type);
            Item = Engine::KGameSys::FindItemFromIID(IID);
            int Window = Engine::KGameSys::WindowCheck("Item_Qigong_Rates");

            if (Item && Window)
                Engine::KGameSys::SetQigoong(Window,(int)LeftData);

            return 1;
        }

        if (Type == 234)
        {
            const char *msg;
            Tools->ParseData(LeftData, "s", &msg);

            if (strlen(msg) > 0)
            {
                int Screen = Engine::KGameSys::OpenWindow("screeninfoedit", 0, 0, 0, 0, 0);
                Engine::KGameSys::LatestScreenMsg((void*)Screen,msg);
            }

            return 1;
        }

        if (Type == 233)
        {
            int time = 0;
            Tools->ParseData(LeftData, "d", &time);
            int Window = Engine::KGameSys::OpenWindow("hell_time", 0, 0, 0, 0, 0);

            if ( Window )
            {
                Engine::KGameSys::HellTime(Window, 1);
                Engine::KGameSys::SetHellTime(time, 0);
                Engine::KGameSys::RefreshHellTime(Window);
            }

            return 1;
        }

        if (Type == 232)
        {
            Engine::KGameSys::Scenario3_3(0x40,(int)LeftData);
            return 1;
        }

        if (Type == 231)
        {
            Engine::KGameSys::RebirthTalisman(0,0,(char)LeftData);
            return 1;
        }

        if (Type == 230)
        {
            int IID = 0, pItem = 0, Value = 0;
            Tools->ParseData(LeftData, "dd", &IID, & Value);
            pItem = Engine::KGameSys::FindItemFromIID(IID);

            if (!pItem)
                pItem = Engine::KGameSys::FindItemFromIIDEx(IID);

            if(pItem)
            {
                *(DWORD*)(pItem + 68) = Value;
                *(DWORD*)(pItem + 72) = 0;
            }

            return 1;
        }

        if (Type == 229)
        {
            Engine::KGameSys::ShowPet(1,1,(char)LeftData);
            return 1;
        }

        if (Type == 228)
        {
            int Type = 0;
            const char *Msg = "", *CallerName = "", *Name = "";
            Tools->ParseData(LeftData, "dsss", &Type, &Msg, &CallerName, &Name);

            if (strlen(CallerName) > 0 && strlen(Name) > 0)
            {
                this->RecCaller = CallerName;
                this->Recall = Name;
                Engine::KGameSys::MBox((int)Msg,4,Type,0,0);
            }

            return 1;
        }

        if (Type == 227)
        {
            int ID = 0, Type = 0;
            Tools->ParseData(LeftData, "dd", &ID, &Type);

            if (ID && Type)
                Engine::KGameSys::RidingEnable(ID,Type);

            return 1;
        }

        if (Type == 226)
        {
            int ID = 0, Type = 0;
            Tools->ParseData(LeftData, "dd", &ID, &Type);

            if (ID)
                Engine::KGameSys::RidingDisable(ID,Type);

            return 1;
        }

        if (Type == 225)
        {
            char Type = 0, Prefix = 0;
            int IID = 0;
            Tools->ParseData(LeftData, "bdb", &Type, &IID, &Prefix);
            Engine::KGameSys::DemonGongStone(0,0,(int)LeftData);
            return 1;
        }

        if (Type == 224)
        {
            char Type = 0;
            int Value = 0, IID = 0, Item = 0;
            Tools->ParseData(LeftData, "ddb", &IID, &Value, &Type);
            Item = Engine::KGameSys::FindItemFromIID(IID);
            int Window = Engine::KGameSys::WindowCheck("mstone_socket");

            if (Item && Window)
                Engine::KGameSys::SetDemonGongWindow((void*)Window,(int)LeftData);

            return 1;
        }

        if (Type == 223)
        {
            int MAILID = 0;
            Tools->ParseData(LeftData, "d", &MAILID);

            if (MAILID > 0)
            {
                Interface<IPackets> Packets;
                Packets->Send(56,"bd",9,MAILID);
            }

            return 1;
        }

        if (Type == 222)
        {
            int PID = 0, Quest = 0, Amount = 0;
            Tools->ParseData(LeftData, "ddd", &PID, &Quest, &Amount);

            if (PID && Quest)
            {
                ShowMonsterAmount[PID].Quest = Quest;
                ShowMonsterAmount[PID].Amount = Amount;
            }

            return 1;
        }

        if (Type == 221)
        {
            int Pick = 0;
            Tools->ParseData(LeftData, "d", &Pick);
            AutoPick = Pick;
            return 1;
        }

        if (Type == 220)
        {
            StopClient = true;
            Engine::KGameSys::MBox(
                    (int)"Packet hack detected. Client connection closed.",0,0,0,0);
            return 1;
        }

        return 1;
    }

    Engine::KSocket::OnRecv(Data);
    return 1;
}
