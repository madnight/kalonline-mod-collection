#define _WIN32_DCOM
#include <Windows.h>
#include <process.h>
#include <wininet.h>
#include <time.h>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <strstream>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <fcntl.h>
#include <io.h>
#include <list>
#include <vector>
#include <algorithm>
#include "MD5.h"
#include "base64.h"
#include "Sha256.h"
#include <iterator>
#include <iomanip>
#include <comdef.h>
#include <wbemidl.h>
#pragma pack(1)
HINSTANCE hL = 0;
FARPROC p[806] = {0};
#pragma warning(disable: 4018)
#pragma warning(disable: 4129)
#pragma warning (disable : 4244)
#pragma warning (disable : 4305)
#pragma warning (disable : 4309)
#pragma warning (disable : 4996)
char key = '255';
char newkey = 'Hell';

void Console()
{
    int hCrtIn, hCrtOut;
    FILE *conIn, *conOut;
    AllocConsole();
    hCrtIn = _open_osfhandle((intptr_t) GetStdHandle(STD_INPUT_HANDLE), _O_TEXT);
    hCrtOut = _open_osfhandle((intptr_t) GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
    conIn = _fdopen(hCrtIn, "r");
    conOut = _fdopen(hCrtOut, "w");
    *stdin = *conIn;
    *stdout = *conOut;
    SetConsoleTitleA("R3volutioN");
}

std::string encryptDecrypt(std::string toEncrypt)
{
    std::string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++) {
        output[i] = toEncrypt[i] ^ key;
    }

    return output;
}

std::string newencryptDecrypt(std::string toEncrypt)
{
    std::string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++) {
        output[i] = toEncrypt[i] ^ newkey;
    }

    return output;
}

enum TextColor
{
    TEXTCOLOR_GENERAL   = RGB(255, 255, 255),
    TEXTCOLOR_INFOMSG   = RGB(70, 227, 232),
    TEXTCOLOR_SHUTDOWN  = RGB(240, 116,  15),
    TEXTCOLOR_ORANGE    = RGB(255, 128,  64),
    TEXTCOLOR_BLUE      = RGB(0, 128, 255),
    TEXTCOLOR_YELLOW    = RGB(255, 255, 128),
    TEXTCOLOR_RED       = RGB(255,   0,   0),
    TEXTCOLOR_PARTY     = RGB(210,  64,   0),
    TEXTCOLOR_GUILD     = RGB(10, 255, 229),
    TEXTCOLOR_ALLIANCE  = RGB(128, 128, 192),
    TEXTCOLOR_GREEN     = RGB(0, 255,   0),
    TEXTCOLOR_DARKGREEN = RGB(0, 170,   0),
    TEXTCOLOR_FAILED    = RGB(250, 210,   0),
    TEXTCOLOR_CLASSMATE = RGB(0, 128,   0),
    TEXTCOLOR_PUPIL     = RGB(255, 128,  64),
    TEXTCOLOR_PINK      = RGB(255, 155, 255),
};

enum NoticeColor
{
    NOTICECOLOR_BLUE        = 0,
    NOTICECOLOR_RED         = 1,
    NOTICECOLOR_ORANGE      = 2,
    NOTICECOLOR_REDCENTER   = 3,
    NOTICECOLOR_WHITE       = 4,
    NOTICECOLOR_REDLONG     = 5,
    NOTICECOLOR_BLUECENTER  = 6,
    NOTICECOLOR_YELLOW      = 7,
    NOTICECOLOR_PINK        = 8,
    NOTICECOLOR_ORANGELONG  = 9,
};

std::string Int2String(int value)
{
    std::stringstream ss;
    ss << value;
    std::string str = ss.str();
    return str;
}

int String2Int(std::string String)
{
    int Integer;
    std::istringstream iss(String);
    iss >> Integer;
    return Integer;
}

char *MakeBuffer(const std::string &string)
{
    char *return_string = new char[string.length() + 1];
    strcpy(return_string, string.c_str());
    return return_string;
}

std::string GetHexString(char *bt)
{
    std::string s;
    s.clear();

    for (int i = 0; i < strlen(bt); i++)
    {
        byte b = bt[i];
        int n = 0, n1 = 0, n2 = 0;
        n = (int)b;
        n1 = n & 15;
        n2 = (n >> 4) & 15;

        if (n2 > 9) {
            s += Int2String((char)(n2 - 10 + (int)'A'));
        }
        else {
            s += Int2String(n2);
        }

        if (n1 > 9) {
            s += Int2String((char)(n1 - 10 + (int)'A'));
        }
        else {
            s += Int2String(n1);
        }

        if ((i + 1) != strlen(bt) && (i + 1) % 4 == 0) {
            s += "-";
        }
    }

    return s;
}

std::string GetSerial(std::string HWID)
{
    MD5 x;
    char *m = strdup(HWID.c_str());
    std::string mm = x.digestString(m);
    char *buffer = MakeBuffer(mm);
    std::string Serial = GetHexString(buffer);
    delete []buffer;
    return Serial;
}

namespace Protect32
{
int Time = 0;
bool Active = false;
std::string FirstGuild = "";
std::string SecondGuild = "";
int GuildFirst = 0;
int GuildSecond = 0;
int Prayer = 0;
int RedScore = 0;
int BlueScore = 0;
int RedWin = 0;
int BlueWin = 0;
int Winner = 0;
int Round = 0;
int BluePrayerTime = 0;
int RedPrayerTime = 0;
}

namespace Battlefield
{
bool Active = false;
int RedScore = 0;
int BlueScore = 0;
int Time = 0;
int BFBuff = 161;
int RedStoneID[3] = {0};
int BlueStoneID[3] = {0};
int RegisterAmount = 0;
}

namespace Scenario
{
int Time = 3600;
int RedScore = 0;
int BlueScore = 0;
int BlueTeamSeal = 0;
int RedTeamSeal = 0;
int BlueTeamTowerCount = 0;
int RedTeamTowerCount = 0;
bool Active = false;
int RegisterAmount = 0;
std::string FirstGuild = "";
std::string SecondGuild = "";
int GuildFirst = 0;
int GuildSecond = 0;
}

namespace F10
{
bool Active = false;
int RegisterAmount = 0;
int ShowTime = 0;
int KillCount = 0;
int Dunamic = 0;
int Cheios = 0;
int DunamicSkill = 0;
int CheiosSkill = 0;
DWORD DunamicSkillDelay = 0;
DWORD CheiosSkillDelay = 0;
}

namespace Hell
{
bool Active = false;
int Round = 0;
int KillCount = 0;
int Time = 0;
int Rebirth = 0;
int Delay = 0;
}

namespace DuelTournament
{
bool Active = false;
int RoundTime = 0;
int RedScore = 0;
int BlueScore = 0;
int RegisterAmount = 0;
int Delay = 0;
bool SelectPlayers = false;
int FirstPlayer = 0;
int SecondPlayer = 0;
}

namespace LastManStand
{
bool Active = false;
int RegisterAmount = 0;
int Time = 0;
}

namespace Hunting
{
bool Active = false;
int Guild = 0;
void *Monster = 0;
}

struct CheckConfigCooldown
{
    int CooldownConfig;
    int DelayConfig;
};

struct CheckConfigEggCooldown
{
    int EggCooldownConfig;
    int EggDelayConfig;
};

struct CheckBof
{
    int Chest;
    int Gloves;
    int Boots;
    int Helmet;
    int Short;
    int FullSet;
    int HalfSet;
};

struct PlayerContinueSkill
{
    int PlayerX;
    int PlayerY;
    void *PlayerTarget;
    int PlayerSkillGrade;
    int PlayerSkillID;
    DWORD PlayerSkillDelay;
    int PlayerSkillCount;
};

struct PlayerFarContinueSkill
{
    void *PlayerTarget;
    int PlayerSkillGrade;
    int PlayerSkillID;
    DWORD PlayerSkillDelay;
    int PlayerSkillCount;
    int PlayerDamage;
};

struct RuptureContinueSkill
{
    void *PlayerTarget;
    int PlayerSkillGrade;
    int PlayerSkillID;
    DWORD PlayerSkillDelay;
    int PlayerSkillCount;
    int PlayerDamage;
};

struct CheckSkillBook
{
    int Index;
    int Class;
    int Action;
    int UpgradeAmount;
    int UpgradeMax;
};

struct CheckSummonTimer
{
    int Index;
    int Amount;
    int Map;
    int X;
    int Y;
    int Disappear;
    std::string Msg;
    std::string Day;
};

struct CheckCalculations
{
    int Class;
    int Rate;
};

struct ConfigShiny
{
    void *Target;
    DWORD Delay;
};

struct HonorPoint
{
    int HPx;
    int HKx;
    int HDx;
    int DKPTx;
    int DKPWx;
    int PLTx;
    int PLWx;
    int SVTx;
    int SVWx;
    int RPx;
};

struct CurrentHonorPoint
{
    int CurHPx;
    int CurHKx;
    int CurHDx;
    int CurDKPTx;
    int CurDKPWx;
    int CurPLTx;
    int CurPLWx;
    int CurSVTx;
    int CurSVWx;
    int CurRPx;
};

struct PimpConfig
{
    int Prefix;
    int GetA;
    int GetM;
    int GetTOA;
    int GetUpg;
};

struct ConfigPetLife
{
    int Time;
    int Player;
};

struct ConfigBuffer
{
    int Index;
    int Grade;
    int Delete;
    int Limit;
};

struct ConfigEmok
{
    int Day;
    int Time;
};

struct ConfigIceArrow
{
    DWORD Cooldown;
    DWORD Delay;
};

struct ConfigPlayerPet
{
    int Owner;
    int IID;
    int Buff;
};

struct ConfigRentArmor
{
    int Quest;
    int Index;
    int Prefix;
    int Def;
    int Eva;
    int Bof;
    int Dss;
    int Coin;
    int Time;
};

struct ConfigRentWeapon
{
    int Quest;
    int Index;
    int Prefix;
    int Attack;
    int Magic;
    int Toa;
    int Upgrade;
    int Mix;
    int Dss;
    int Coin;
    int Time;
};

struct ConfigMining
{
    DWORD Time;
    int Index;
    int Amount;
    int Cycle;
};

struct ConfigLevelReward
{
    int Class;
    int Index;
    int Prefix;
    int Amount;
    int Info;
    int Attack;
    int Magic;
    int Toa;
    int Upgrade;
    int Defense;
    int Evasion;
    int Endurance;
    std::string Msg;
};

struct ConfigDailyQuest
{
    int Quest;
    int MobAmount;
    int Repeat;
    int Time;
    int Item;
    int ItemAmount;
    int Exp;
};

struct ConfigPlayerQuest
{
    int Active;
    int MobAmount;
    int Repeat;
    int Time;
};

struct ConfigPetTime
{
    int Time;
    int Heal;
    int Pick;
};

struct ConfigItemShop
{
    int Type;
    int Priority;
    int Price;
    int Discount;
    int ItemIndex;
    int Amount;
};

time_t uptimestart;
int BofConfigRead = 0, ImpConfigRead = 0, TotalBlock = 0, NailKill = 0;
int NPCEDailyLimit = 0, NPCECollectedTotalItem = 0, NPCELeftTime = 0;
char ItemShopPacket[9000] = {0};
#define HIDWORD(l) ((DWORD)(((DWORDLONG)(l)>>32)&0xFFFFFFFF))
std::map<int, int> CheckHaninMirror;
std::map<int, int> CheckEssense1;
std::map<int, int> CheckEssense2;
std::map<int, int> CheckEssense3;
std::map<int, int> CheckEssense4;
std::map<int, int> CheckEssense5;
std::map<int, int> PacketHackCheck;
std::map<std::string, int> MiningLimit;
std::map<std::string, int> ShopLimit;
std::map<int, int> TrigramGrade;
std::map<int, int> TrigramHP;
std::map<int, int> TrigramMP;
std::map<int, int> TrigramAtk;
std::map<int, int> TrigramStr;
std::map<int, int> TrigramAgi;
std::map<int, int> TrigramInt;
std::map<int, int> TrigramWis;
std::map<int, int> TrigramHth;
std::map<int, int> Taegeuk;
std::map<int, int> CheckDailyQuest;
std::map<int, int> LevelDailyQuest;
std::map<int, ConfigItemShop> ItemShopCheck;
std::map<__int64, ConfigPlayerQuest> PlayerQuest;
std::map<int, ConfigDailyQuest> DailyQuest;
std::map<int, ConfigLevelReward> LevelReward;
std::map<int, ConfigMining> CheckMining;
std::map<int, int> GetItemStat;
std::map<int, ConfigBuffer> BufferCheck;
std::map<int, ConfigRentArmor> RentArmor;
std::map<int, ConfigRentWeapon> RentWeapon;
std::map<int, HonorPoint> CheckHonor;
std::map<int, CurrentHonorPoint> CheckCurHonor;
std::map<int, ConfigEmok> CheckEmok;
std::map<int, CheckBof> BeadOfFire;
std::map<int, int> CooldownTable;
std::map<int, int> EggCooldownTable;
std::map<int, PlayerFarContinueSkill> CheckFarContinueSkill;
std::map<int, PlayerContinueSkill> CheckContinueSkill;
std::map<int, RuptureContinueSkill> CheckRuptureContinueSkill;
std::map<int, ConfigShiny> CheckShiny;
std::map<int, ConfigIceArrow> CheckIceArrow;
std::map<int, CheckSkillBook> SkillBook;
std::map<int, CheckConfigCooldown> CheckCooldownConfig;
std::map<int, CheckConfigEggCooldown> CheckEggCooldownConfig;
std::map<int, CheckCalculations> ConfigCalculations;
std::map<int, PimpConfig> CheckPimp;
std::map<std::string, CheckSummonTimer> SummonTimer;
std::map<int, ConfigPetLife> PetLifeCheck;
std::map<int, ConfigPlayerPet> PlayerPet;
std::map<std::string, std::string> Read2ndPwd;
std::map<int, int> CheckBlob;
std::map<int, DWORD> Mute;
std::map<int, int> SetBuffx;
std::map<int, DWORD> CODelay;
std::map<int, void*> SummonAi;
std::map<int, DWORD> MonsterDisappear;
std::map<int, int> UnBlob;
std::map<int, int> MixConfigPrefix;
std::map<int, int> MixConfigInfo;
std::map<int, std::string> MixConfigMsg;
std::map<int, int> BattlefieldRegistration;
std::map<int, int> ScenarioRegistration;
std::map<int, int> ScenarioGuildID;
std::map<int, std::string> ScenarioGuildName;
std::map<std::string, std::string> AutoNoticeDay;
std::map<std::string, std::string> AutoNoticeMsg;
std::map<int, int> LevelGap;
std::map<int, int> HonorShop;
std::map<int, int> HonorIndex;
std::map<int, int> F10Registration;
std::map<int, int> WeaponReplace;
std::map<int, int> WeaponReplaceIndex;
std::map<int, int> WeaponReplacePrefix;
std::map<int, int> ArmorPimpConfig;
std::map<int, std::string> ItemLockCheck;
std::map<int, ConfigPetTime> PetTime;
std::map<int, int> PlayerBlockCheck;
std::map<int, int> DuelTournamentRegistration;
std::vector<const char*> DuelTournamentList;
std::vector<int> MSS;
std::vector<int> ProtectLeaderList;
std::map<int, std::string> ProtectLeaderName;
std::map<int, int> LastManRegistration;
std::map<int, int> MageMICheck;
#pragma comment(lib,"Detours/enigma_ide.lib")
#pragma comment(lib,"Detours/detours.lib")
#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"Wininet.lib")
#pragma comment(lib,"netapi32.lib")
#pragma comment(lib,"wbemuuid.lib")
#include <stdio.h>
#include <lm.h>
#include "Detours/enigma_ide.h"
#include "Detours/detours.h"
#include "Exports.h"
#include "Memory.h"
#include "Tools.h"
#include "Interface.h"
#include "Time.h"
#include "Functions.h"
#include "ReadConfig.h"
#include "StatPointValue.h"
#include "PasswordDecode.h"
#include "ISkill.h"
#include "IChar.h"
#include "ResetContinueSkill.h"
#include "IItem.h"
#include "IQuest.h"
#include "Calculations.h"
#include "CreateBuff.h"
#include "Process.h"
#include "Summon.h"
#include "CBaseDelete.h"
#include "BlessingOfHealth.h"
#include "BlessingOfStrength.h"
#include "BlessingOfAgility.h"
#include "BlessingOfIntelligence.h"
#include "BlessingOfCriticalHit.h"
#include "RefiningWeapon.h"
#include "DefenseImprovement.h"
#include "SpeedUp.h"
#include "RefreshBuff.h"
#include "Mix.h"
#include "ExpTable.h"
#include "EagleStat.h"
#include "StoneOfBirth.h"
#include "StoneOfChance.h"
#include "MonsterBlob.h"
#include "SaveAllProperty.h"
#include "BuyItemEx.h"
#include "SendMail.h"
#include "Timer.h"
#include "Command.h"
#include "Loader.h"
#include "CDBProcess.h"
#include "Ornament.h"
#include "Player.h"
#include "OnLoadPlayer.h"
#include "LevelUp.h"
#include "SkillUpgradeCheck.h"
#include "AutoLearn.h"
#include "Packet.h"
#include "SkillPointer.h"
#include "CanAttack.h"
#include "EggExp.h"
#include "FinalDamage.h"
#include "Trade.h"
#include "ItemUse.h"
#include "Quest.h"
#include "PowerfulWideningWound.h"
#include "PerfectDefense.h"
#include "ProvocationOfBlow.h"
#include "SpinSlash.h"
#include "SwordDance.h"
#include "TherapeuticTouch.h"
#include "Blessing.h"
#include "Fireball.h"
#include "IceArrow.h"
#include "Icicle.h"
#include "Thunderbolt.h"
#include "VirulentArrow.h"
#include "ArrowExplosion.h"
#include "ArrowRain.h"
#include "CombativeSpirit.h"
#include "RevolveAttack.h"
#include "BloodSuction.h"
#include "EggThunderbolt.h"
#include "LifeAbsorption.h"
#include "LightningArrow.h"
#include "FlameInjection.h"
#include "CounterDamage.h"
#include "WhirlwindFeather.h"
#include "HighClassHiding.h"
#include "ShinRhoe.h"
#include "ZilPoong.h"
#include "Hiding.h"
#include "Behead.h"
#include "WrathOfHeaven.h"
#include "LightningSlash.h"
#include "ShadowSlash.h"
#include "SpinBlade.h"
#include "TwinBladeStrike.h"
#include "ArmorBreaker.h"
#include "SpinAttack.h"
#include "SuicidalBlow.h"
#include "FinalBlow.h"
#include "Assault.h"
#include "VitalStrike.h"
#include "AnkleAmputate.h"
#include "Rupture.h"
#include "FatalWound.h"
#include "Confusion.h"
#include "Stun.h"
#include "Strangle.h"
#include "DualShadow.h"
#include "ShoutOfDefense.h"
#include "TheBoomOfEarth.h"
#include "ShoutOfFightingSpirit.h"
#include "TheWaveOfEarth.h"
#include "WalkOnTheAir.h"
#include "OneHitStrike.h"
#include "ArrowsOfTheMaster.h"
#include "MassiveFire.h"
#include "SpiritOfTheArrows.h"
#include "Punishment.h"
#include "CriticalStrike.h"
#include "CriticalDiffusion.h"
#include "StrikeOfGod.h"
#include "DestroyingArmor.h"
#include "Bombing.h"
#include "Incapacitation.h"
#include "ReleasingTheEnergy.h"
#include "GhostKnife.h"
#include "GhostFlash.h"
#include "SoulShield.h"
#include "Wave.h"
#include "GhostWindow.h"
#include "MudRoom.h"
#include "ExecutiveDirector.h"
#include "TheSoulsPenance.h"
#include "JigukKing.h"
#include "JeungjangKing.h"
#include "AmplificationOfBlood.h"
#include "WaveOfEmperor.h"
#include "Entangling.h"
#include "SpearOfPain.h"
#include "JigukKingOfTaein.h"
#include "JeungjangKingOfTaein.h"
#include "SoulBlow.h"
#include "DrainBlood.h"
#include "MagicalExplosion.h"
#include "MentalBreakdown.h"
#include "Collapse.h"
#include "SixSouls.h"
#include "ExplodingSpirit.h"
#include "SpiritWave.h"
#include "Doggebi.h"
#include "RisingKing4th.h"
#include "Gangshin4th.h"
#include "Skill.h"
#include "EggSkill.h"
#include "DropItem.h"
#include "ArmorPut.h"
#include "WeaponPut.h"
#include "DefenseChangePrefix.h"
#include "WeaponChangePrefix.h"
#include "Revival.h"
#include "CastleWarFix.h"
#include "CutDownExp.h"
#include "Calls.h"
#include "Transform.h"
#include "ContinuesSkill.h"
#include "Start.h"
#include "NormalHit.h"
#include "Storage.h"
#include "ItemFixes.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
    LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            InitializeADVAPI32();
            ReadConfig();
            ItemFixes();
            ExpMultiplier();
            SwitchTable();
            Loader();
            SetSkillPointer();
            uptimestart = time(0);
            ConfigDBCheck = DBCheck();
            SetLearnUpgradeLimit();
            DetourTransactionBegin();
            DetourAttach(&(PVOID&)CIOServer::Start, Start);

            if (ConfigDBCheck)
            {
                DetourAttach(&(PVOID&)CPlayer::RemoveItem, PlayerRemoveItem);
                DetourAttach(&(PVOID&)CNPCDoor::Tick, NPCTick);
                DetourAttach(&(PVOID&)CBuff::CreateBuff, CreateBuff);
                DetourAttach(&(PVOID&)CDBSocket::Process, Process);
                DetourAttach(&(PVOID&)CSkill::BlessingOfHealth, BlessingOfHealth);
                DetourAttach(&(PVOID&)CSkill::BlessingOfStrength, BlessingOfStrength);
                DetourAttach(&(PVOID&)CSkill::BlessingOfAgility, BlessingOfAgility);
                DetourAttach(&(PVOID&)CSkill::BlessingOfIntelligence, BlessingOfIntelligence);
                DetourAttach(&(PVOID&)CSkill::BlessingOfCriticalHit, BlessingOfCriticalHit);
                DetourAttach(&(PVOID&)CSkill::RefiningWeapon, RefiningWeapon);
                DetourAttach(&(PVOID&)CSkill::DefenseImprovement, DefenseImprovement);
                DetourAttach(&(PVOID&)CSkill::SpeedUp, SpeedUp);
                DetourAttach(&(PVOID&)CSkill::CheckBuff, CheckBuff);
                DetourAttach(&(PVOID&)CPlayer::EnforceItem, EnforceItem);
                DetourAttach(&(PVOID&)CPlayer::Imperial, Imperial);
                DetourAttach(&(PVOID&)CItemTransform::ApplySpec, TransformApplySpec);
                DetourAttach(&(PVOID&)CItemTransform::FreeSpec, TransformFreeSpec);
                DetourAttach(&(PVOID&)Undefined::StoneOfChance, StoneOfChance);
                DetourAttach(&(PVOID&)CPlayer::InitStat, SOB);
                DetourAttach(&(PVOID&)CPlayer::BuyItemEx, BuyItemEx);
                DetourAttach(&(PVOID&)CPlayer::SaveAllProperty, SaveAllProperty);
                DetourAttach(&(PVOID&)CPlayer::SendMail, SendMail);
                DetourAttach(&(PVOID&)CPlayer::ChatCommand, ChatCommand);
                DetourAttach(&(PVOID&)CDBSocket::RealProcess, CDBProcess);
                DetourAttach(&(PVOID&)CCalendar::OnTimer, OnTimer);
                DetourAttach(&(PVOID&)CPlayer::Tick, Tick);
                DetourAttach(&(PVOID&)CPlayer::OnLoadPlayer, OnLoadPlayer);
                DetourAttach(&(PVOID&)CPlayer::Process, Packet);
                DetourAttach(&(PVOID&)CPlayer::LevelUp, LevelUp);
                DetourAttach(&(PVOID&)CSkill::Occupation, Occupation);
                DetourAttach(&(PVOID&)CSkill::LearnSkillCheck, LearnSkillCheck);
                DetourAttach(&(PVOID&)CPlayer::LevelUpUnknown, AutoLearn);
                DetourAttach(&(PVOID&)CPlayer::CancelTrade, CancelTrade);
                DetourAttach(&(PVOID&)CPlayer::TradeAgreed, TradeAgreed);
                DetourAttach(&(PVOID&)CPlayer::ShowOffItem, ShowOffItem);
                DetourAttach(&(PVOID&)CPlayer::CanAttack, CanAttack);
                DetourAttach(&(PVOID&)CItemTransform::UpdateExp, UpdateExp);
                DetourAttach(&(PVOID&)CChar::GetFinalDamage, GetFinalDamage);
                DetourAttach(&(PVOID&)CQuest::Run, Quest);
                DetourAttach(&(PVOID&)CItemGeneral::Use, ItemUse);
                DetourAttach(&(PVOID&)CSkill::ExecuteTransformSkill, ExecuteTransformSkill);
                DetourAttach(&(PVOID&)CSkill::ExecuteSkill, ExecuteSkill);
                DetourAttach(&(PVOID&)CPlayer::DropItemONPKDie, DropItemONPKDie);
                DetourAttach(&(PVOID&)CItemDefense::ApplySpec, DefenseApplySpec);
                DetourAttach(&(PVOID&)CItemDefense::PutOff, DefensePutOff);
                DetourAttach(&(PVOID&)CItemWeapon::ApplySpec, WeaponApplySpec);
                DetourAttach(&(PVOID&)CItemWeapon::PutOff, WeaponPutOff);
                DetourAttach(&(PVOID&)CItemWeapon::PutOn, WeaponPutOn);
                DetourAttach(&(PVOID&)CItemDefense::ChangePrefix, DefenseChangePrefix);
                DetourAttach(&(PVOID&)CItemWeapon::ChangePrefix, WeaponChangePrefix);
                DetourAttach(&(PVOID&)CPlayer::RevivalItem, RevivalItem);
                DetourAttach(&(PVOID&)CPlayer::RevivalSkill, RevivalSkill);
                DetourAttach(&(PVOID&)CMonsterGuildWar::Damage, GuildWarDamage);
                DetourAttach(&(PVOID&)CPlayer::CutdownExp, CutdownExp);
                DetourAttach(&(PVOID&)CSkill::Calls, Calls);
                DetourAttach(&(PVOID&)CConsole::Black, Black);
                DetourAttach(&(PVOID&)CConsole::Blue, Blue);
                DetourAttach(&(PVOID&)CItemDefense::PutOn, ArmorPutOn);
                DetourAttach(&(PVOID&)CPlayer::MAILProcess, MAILProcess);
                DetourAttach(&(PVOID&)CPlayer::Transform, Transform);
                DetourAttach(&(PVOID&)CSkill::Calculations, Calculations);
                DetourAttach(&(PVOID&)CPlayer::Attack, NormalHit);
                DetourAttach(&(PVOID&)CMonsterMaguniMaster::Tick, SummonTick);
                DetourAttach(&(PVOID&)CSkill::LifeAbsorption, LifeAbsorption);
                DetourAttach(&(PVOID&)CSkill::MagicTick, MagicTick);
                DetourAttach(&(PVOID&)CItem::NewItem, NewItem);
                DetourAttach(&(PVOID&)CItemOrnament::PutOn, OrnamentPutOn);
                DetourAttach(&(PVOID&)CItemOrnament::ApplySpec, OrnamentApplySpec);
                DetourAttach(&(PVOID&)CItemOrnament::PutOff, OrnamentPutOff);
                DetourAttach(&(PVOID&)CMonsterMaguniMaster::AI, SummonAI);
                DetourAttach(&(PVOID&)CMonsterMaguniMaster::Die, SummonDie);
                DetourAttach(&(PVOID&)CItemWeapon::StorageIn, CItemWeaponStorageIn);
                DetourAttach(&(PVOID&)CItemDefense::StorageIn, CItemDefenseStorageIn);
                DetourAttach(&(PVOID&)CBase::Delete, CBaseDelete);
                DetourAttach(&(PVOID&)CMonsterMagic::Create, CMonsterMagicCreate);
                DetourAttach(&(PVOID&)CPlayer::CheckBlock, CheckBlock);
                DetourAttach(&(PVOID&)CItem::CreateItem, MyCreateItem);
                DetourAttach(&(PVOID&)CItemGeneral::StorageIn, CItemGeneralStorageIn);
                DetourAttach(&(PVOID&)CMonsterReal::Tick, MonsterTick);
                DetourAttach(&(PVOID&)CItemOrnament::ChangePrefix, OrnamentChangePrefix);
                DetourAttach(&(PVOID&)CItem::OnTimer, ItemOnTimer);
                DetourAttach(&(PVOID&)CPlayer::GameStart, MyGameStart);
                DetourAttach(&(PVOID&)CPlayer::SendCreate, MySendCreate);
                DetourAttach(&(PVOID&)CCastle::WarEnd, WarEnd);
                DetourAttach(&(PVOID&)CItemOrnament::StorageIn, CItemOrnamentStorageIn);
                DetourAttach(&(PVOID&)CBuffPrtyEx::FreeBuff, CBuffPrtyExFreeBuff);
                DetourAttach(&(PVOID&)CItemOrnament::SetWearState, OrnamentSetWearState);
                DetourAttach(&(PVOID&)CPlayer::UpdateProperty, MyUpdateProperty);
                DetourAttach(&(PVOID&)CBuff::CBuffPrtyExIsExpired, CBuffCBuffPrtyExIsExpired);
            }

            DetourTransactionCommit();
            break;
        }

        case DLL_PROCESS_DETACH:
        {
            FinalizeADVAPI32();
            ReadConfig();
            ItemFixes();
            ExpMultiplier();
            SwitchTable();
            Loader();
            SetSkillPointer();
            SetLearnUpgradeLimit();
            DetourTransactionBegin();
            DetourDetach(&(PVOID&)CIOServer::Start, Start);
            DetourDetach(&(PVOID&)CPlayer::RemoveItem, PlayerRemoveItem);
            DetourDetach(&(PVOID&)CNPCDoor::Tick, NPCTick);
            DetourDetach(&(PVOID&)CBuff::CreateBuff, CreateBuff);
            DetourDetach(&(PVOID&)CDBSocket::Process, Process);
            DetourDetach(&(PVOID&)CSkill::BlessingOfHealth, BlessingOfHealth);
            DetourDetach(&(PVOID&)CSkill::BlessingOfStrength, BlessingOfStrength);
            DetourDetach(&(PVOID&)CSkill::BlessingOfAgility, BlessingOfAgility);
            DetourDetach(&(PVOID&)CSkill::BlessingOfIntelligence, BlessingOfIntelligence);
            DetourDetach(&(PVOID&)CSkill::BlessingOfCriticalHit, BlessingOfCriticalHit);
            DetourDetach(&(PVOID&)CSkill::RefiningWeapon, RefiningWeapon);
            DetourDetach(&(PVOID&)CSkill::DefenseImprovement, DefenseImprovement);
            DetourDetach(&(PVOID&)CSkill::SpeedUp, SpeedUp);
            DetourDetach(&(PVOID&)CSkill::CheckBuff, CheckBuff);
            DetourDetach(&(PVOID&)CPlayer::EnforceItem, EnforceItem);
            DetourDetach(&(PVOID&)CPlayer::Imperial, Imperial);
            DetourDetach(&(PVOID&)CItemTransform::ApplySpec, TransformApplySpec);
            DetourDetach(&(PVOID&)CItemTransform::FreeSpec, TransformFreeSpec);
            DetourDetach(&(PVOID&)Undefined::StoneOfChance, StoneOfChance);
            DetourDetach(&(PVOID&)CPlayer::InitStat, SOB);
            DetourDetach(&(PVOID&)CPlayer::BuyItemEx, BuyItemEx);
            DetourDetach(&(PVOID&)CPlayer::SaveAllProperty, SaveAllProperty);
            DetourDetach(&(PVOID&)CPlayer::SendMail, SendMail);
            DetourDetach(&(PVOID&)CPlayer::ChatCommand, ChatCommand);
            DetourDetach(&(PVOID&)CDBSocket::RealProcess, CDBProcess);
            DetourDetach(&(PVOID&)CCalendar::OnTimer, OnTimer);
            DetourDetach(&(PVOID&)CPlayer::Tick, Tick);
            DetourDetach(&(PVOID&)CPlayer::OnLoadPlayer, OnLoadPlayer);
            DetourDetach(&(PVOID&)CPlayer::Process, Packet);
            DetourDetach(&(PVOID&)CPlayer::LevelUp, LevelUp);
            DetourDetach(&(PVOID&)CSkill::Occupation, Occupation);
            DetourDetach(&(PVOID&)CSkill::LearnSkillCheck, LearnSkillCheck);
            DetourDetach(&(PVOID&)CPlayer::LevelUpUnknown, AutoLearn);
            DetourDetach(&(PVOID&)CPlayer::CancelTrade, CancelTrade);
            DetourDetach(&(PVOID&)CPlayer::TradeAgreed, TradeAgreed);
            DetourDetach(&(PVOID&)CPlayer::ShowOffItem, ShowOffItem);
            DetourDetach(&(PVOID&)CPlayer::CanAttack, CanAttack);
            DetourDetach(&(PVOID&)CItemTransform::UpdateExp, UpdateExp);
            DetourDetach(&(PVOID&)CChar::GetFinalDamage, GetFinalDamage);
            DetourDetach(&(PVOID&)CQuest::Run, Quest);
            DetourDetach(&(PVOID&)CItemGeneral::Use, ItemUse);
            DetourDetach(&(PVOID&)CSkill::ExecuteTransformSkill, ExecuteTransformSkill);
            DetourDetach(&(PVOID&)CSkill::ExecuteSkill, ExecuteSkill);
            DetourDetach(&(PVOID&)CPlayer::DropItemONPKDie, DropItemONPKDie);
            DetourDetach(&(PVOID&)CItemDefense::ApplySpec, DefenseApplySpec);
            DetourDetach(&(PVOID&)CItemDefense::PutOff, DefensePutOff);
            DetourDetach(&(PVOID&)CItemWeapon::ApplySpec, WeaponApplySpec);
            DetourDetach(&(PVOID&)CItemWeapon::PutOff, WeaponPutOff);
            DetourDetach(&(PVOID&)CItemWeapon::PutOn, WeaponPutOn);
            DetourDetach(&(PVOID&)CItemDefense::ChangePrefix, DefenseChangePrefix);
            DetourDetach(&(PVOID&)CItemWeapon::ChangePrefix, WeaponChangePrefix);
            DetourDetach(&(PVOID&)CPlayer::RevivalItem, RevivalItem);
            DetourDetach(&(PVOID&)CPlayer::RevivalSkill, RevivalSkill);
            DetourDetach(&(PVOID&)CMonsterGuildWar::Damage, GuildWarDamage);
            DetourDetach(&(PVOID&)CPlayer::CutdownExp, CutdownExp);
            DetourDetach(&(PVOID&)CSkill::Calls, Calls);
            DetourDetach(&(PVOID&)CConsole::Black, Black);
            DetourDetach(&(PVOID&)CConsole::Blue, Blue);
            DetourDetach(&(PVOID&)CItemDefense::PutOn, ArmorPutOn);
            DetourDetach(&(PVOID&)CPlayer::MAILProcess, MAILProcess);
            DetourDetach(&(PVOID&)CPlayer::Transform, Transform);
            DetourDetach(&(PVOID&)CSkill::Calculations, Calculations);
            DetourDetach(&(PVOID&)CPlayer::Attack, NormalHit);
            DetourDetach(&(PVOID&)CMonsterMaguniMaster::Tick, SummonTick);
            DetourDetach(&(PVOID&)CSkill::LifeAbsorption, LifeAbsorption);
            DetourDetach(&(PVOID&)CSkill::MagicTick, MagicTick);
            DetourDetach(&(PVOID&)CItem::NewItem, NewItem);
            DetourDetach(&(PVOID&)CItemOrnament::PutOn, OrnamentPutOn);
            DetourDetach(&(PVOID&)CItemOrnament::ApplySpec, OrnamentApplySpec);
            DetourDetach(&(PVOID&)CItemOrnament::PutOff, OrnamentPutOff);
            DetourDetach(&(PVOID&)CMonsterMaguniMaster::AI, SummonAI);
            DetourDetach(&(PVOID&)CMonsterMaguniMaster::Die, SummonDie);
            DetourDetach(&(PVOID&)CItemWeapon::StorageIn, CItemWeaponStorageIn);
            DetourDetach(&(PVOID&)CItemDefense::StorageIn, CItemDefenseStorageIn);
            DetourDetach(&(PVOID&)CBase::Delete, CBaseDelete);
            DetourDetach(&(PVOID&)CMonsterMagic::Create, CMonsterMagicCreate);
            DetourDetach(&(PVOID&)CPlayer::CheckBlock, CheckBlock);
            DetourDetach(&(PVOID&)CItem::CreateItem, MyCreateItem);
            DetourDetach(&(PVOID&)CItemGeneral::StorageIn, CItemGeneralStorageIn);
            DetourDetach(&(PVOID&)CMonsterReal::Tick, MonsterTick);
            DetourDetach(&(PVOID&)CItemOrnament::ChangePrefix, OrnamentChangePrefix);
            DetourDetach(&(PVOID&)CItem::OnTimer, ItemOnTimer);
            DetourDetach(&(PVOID&)CPlayer::GameStart, MyGameStart);
            DetourDetach(&(PVOID&)CPlayer::SendCreate, MySendCreate);
            DetourDetach(&(PVOID&)CCastle::WarEnd, WarEnd);
            DetourDetach(&(PVOID&)CItemOrnament::StorageIn, CItemOrnamentStorageIn);
            DetourDetach(&(PVOID&)CBuffPrtyEx::FreeBuff, CBuffPrtyExFreeBuff);
            DetourDetach(&(PVOID&)CItemOrnament::SetWearState, OrnamentSetWearState);
            DetourDetach(&(PVOID&)CPlayer::UpdateProperty, MyUpdateProperty);
            DetourDetach(&(PVOID&)CBuff::CBuffPrtyExIsExpired, CBuffCBuffPrtyExIsExpired);
            DetourTransactionCommit();
            break;
        }
    }

    return TRUE;
}
