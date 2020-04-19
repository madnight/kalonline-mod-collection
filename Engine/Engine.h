#ifndef __ENGINE_H
#define __ENGINE_H

#include <Windows.h>

namespace Engine
{
struct Packet
{
    unsigned short Size;
    unsigned char Type;
    char Data[8000];
};

namespace CEditor
{
static int (__cdecl *AddPKPWD)() = (int (__cdecl*)())0x007DC2B0;
static int (__cdecl *PWDPK)(int a1, signed int a2, signed int a3, signed int a4, const char *a5) = (int (__cdecl*)(int, signed int, signed int, signed int,const char*))0x007AF2F0;
static void (__thiscall *Clear)(void* _this) = (void (__thiscall*)(void*))0x00715050;
static void (__thiscall *Load)(void* _this, const char* Text) = (void (__thiscall*)(void*, const char*))0x00716140;
}

namespace KGameSys
{
static int (__cdecl *RidingEnable)(int ID, int Type) = (int (__cdecl*)(int,int))0x0064A890;
static int (__cdecl *RidingDisable)(int ID, int Type) = (int (__cdecl*)(int,int))0x0064AA00;
static int (__cdecl *ShowPet)(int Value, int Argument, char Packet) = (int (__cdecl*)(int,int,char))0x0063B9B0;
static int (__cdecl *AddMsg)(int a1, const char *a2) = (int (__cdecl*)(int,const char*))0x00425B60;
static int (__cdecl *ArmorGrade)(int a1) = (int (__cdecl*)(int))0x004BBAC0;
static void *(__thiscall *ItemMsg)(void *a, const char *a1) = (void *(__thiscall*)(void*,const char*))0x0040D850;
static int (__cdecl *RebirthTalisman)(int Argument, int Value, char Data) = (int (__cdecl*)(int,int,char))0x00632AC0;
static int (__cdecl *Scenario3_3)(unsigned int Value, int Data) = (int (__cdecl*)(unsigned int,int))0x006A3A50;
static int (__thiscall *LatestScreenMsg)(void *Argument, const char *a2) = (int (__thiscall*)(void*,const char*))0x005F2410;
static int (__thiscall *HellTime)(int Argument, int Value) = (int (__thiscall*)(int,int))0x00628190;
static char (__cdecl *SetHellTime)(int Time, char Value) = (char (__cdecl*)(int,char))0x006575C0;
static DWORD (__thiscall *RefreshHellTime)(int Window) = (DWORD (__thiscall*)(int))0x00657580;
static char (__thiscall *ScreenOverlay)(int a, int a2, int a3, int a4, char a5) = (char (__thiscall*)(int,int,int,int,char))0x0042B720;
static int (__cdecl *MBox)(int pText, int nType, int nAction, int nDest, int nDest2) = (int (__cdecl*)(int, int, int, int, int))0x0068F400;
static int (__thiscall *OnCancel)(void *Argument) = (int (__thiscall*)(void*))0x005958A0;
static int (__thiscall *OnOk)(void *Argument) = (int (__thiscall*)(void*))0x00595E70;
static unsigned long *m_pChattingControl = (unsigned long*)0x0097DD68;
static void (__cdecl *SetScreenInfo)(char Type, void *msg, char value) = (void (__cdecl*)(char, void*, char))0x006A0EC0;
static void (__cdecl *AddChattingMessage)(char Type, const char* Message, int Color) = (void (__cdecl*)(char, const char*, int))0x00698990;
static void (__cdecl *AddInfoMessage)(const char* Message, int Color, int type) = (void (__cdecl*)(const char*, int, int))0x006989C0;
static int (__cdecl *OpenWindow)(const char *name, int Argument, int Value, int Type, int nForce, int x) = (int (__cdecl*)(const char*,int,int,int,int,int))0x0068C3A0;
static int (__cdecl *OtherOpenWindow)(const char *name, int Argument, int Value, int Type, int nForce) = (int (__cdecl*)(const char*,int,int,int,int))0x0068EEA0;
static int (__cdecl *CloseWindow)(char *name) = (int (__cdecl*)(char*))0x0068EAE0;
static int (__cdecl *WindowCheck)(const char *name) = (int (__cdecl*)(const char*))0x0068EBF0;
static int (__thiscall *SetBuff)(void *a, int a2, int a3, signed __int64 a4, char a5, int a6, int a7, int a8, int a9, signed int a10, int a11) = (int (__thiscall*)(void*,int,int,signed __int64,char,int,int,int,int,signed int,int))0x0073AC60;
static int (__thiscall *SetIcon)(void *a, int Key, int Time, int a4, int nMsg) = (int (__thiscall*)(void*,int,int,int,int))0x00746030;
static int (__thiscall *RemoveIcon)(void *a, int Key, int nMsg) = (int (__thiscall*)(void*,int,int))0x00745DB0;
static int (__cdecl *CallBuff)(int a1, int a2, signed __int64 a3, char a4, int a5, int a6, int a7, int a8, int a9) = (int (__cdecl*)(int,int,signed __int64,char,int,int,int,int,int))0x006966C0;
static int (__thiscall *ShowBuffIcon)(int a) = (int (__thiscall*)(int))0x00413DB0;
static int (__thiscall *MakeTip)(void *a, int a2, int a3, signed int a4, char a5, int a6, int a7) = (int (__thiscall*)(void*,int,int,signed int,char,int,int))0x004AB660;
static int (__cdecl *FindItemFromIID)(int a2) = (int (__cdecl*)(int))0x00663730;
static int (__cdecl *FindItemFromIIDEx)(int a2) = (int (__cdecl*)(int))0x00663820;
static signed int (__cdecl *PressKey)(int a1) = (signed int (__cdecl*)(int))0x00698090;
static int PressedKey = (int)0x0097DDEC;
static int (__cdecl *Check)() = (int (__cdecl*)())0x00713900;
static int (__thiscall *CheckForDss)(int Item) = (int (__thiscall*)(int))0x00574200;
static int (__thiscall *CheckDssType)(void *Item, int Packet) = (int (__thiscall*)(void*,int))0x005749C0;
static int (__thiscall *DssConfirmButton)(void *Item, const char *Word, int Value) = (int (__thiscall*)(void*,const char*,int))0x00574DB0;
static int (__cdecl *KMsgGet)(int SysMsgIndex) = (int (__cdecl*)(int))0x0049A240;
static int (__thiscall *SetChangedText)(int Item, int TextName, int NewMsg) = (int (__thiscall*)(int,int,int))0x0072B1B0;
static int (__thiscall *SetDssWindow)(void *Window, int Packet) = (int (__thiscall*)(void*,int))0x00575030;
static int (__thiscall *SetQigoong)(int Window, int Packet) = (int (__thiscall*)(int,int))0x00575C30;
static void (__cdecl *DemonGongStone)(int Value, int Argument, int Packet) = (void (__cdecl*)(int,int,int))0x0063D940;
static int (__thiscall *SetDemonGongWindow)(void *Window, int Packet) = (int (__thiscall*)(void*,int))0x00590E60;
static void (__thiscall *SendIdle)(int Object) = (void (__thiscall*)(int))0x004038F0;
}

namespace KWindowCollector
{
static void (__cdecl *ProcessDestroy)() = (void (__cdecl*)())0x0068EF10;
}

namespace CD3DApplication
{
static HRESULT (__thiscall *Render3DEnvironment)(void* _this) = (HRESULT (__thiscall*)(void*))0x004674D0;
}

namespace KCommand
{
static int *m_bShowFrame = (int*)0x0097FC0C;
static int *m_bHideUI = (int*)0x0097FC14;
static int *m_bHideMe = (int*)0x0097FC18;
static int *m_bHideTerrain = (int*)0x0097FC1C;
static int *m_bHideModel = (int*)0x0097FC20;
static int *m_bHideFog = (int*)0x0097FC24;
static int *m_fFogEnd = (int*)0x0097FC38;
static int *m_bHideWater = (int*)0x0097FC40;
static bool (__cdecl *ProcessCommand)(const char* Text) = (bool (__cdecl*)(const char*))0x006B0850;
}

namespace KSunLight
{
static unsigned long *m_dwTime = (unsigned long*)0x0086CE50;
}

namespace KSocket
{
static int *g_lpClient = (int*)0x0096A40C;
static int (__thiscall *SendPacket)(void* _this, const char* Buffer, int Length) = (int (__thiscall*)(void*, const char*, int))0x0062B660;
static int (__cdecl *OnRecv)(Packet *Data) = (int (__cdecl*)(Packet*))0x0060F7F0;
static float *m_fWriteTime = (float*)0x0096A414;
}

namespace CGame_Character
{
static unsigned long *m_Master = (unsigned long*)0x00894E24;
static unsigned long (__cdecl *FindCharacter)(unsigned int nID, int) = (unsigned long (__cdecl*)(unsigned int, int))0x0040E000;
}

namespace KBattle_UI
{
static void (__thiscall *DrawOnCharacter)(void *_this, unsigned char Type, int Number, int CharacterID) = (void (__thiscall*)(void*, unsigned char, int, int))0x007528E0;
}

namespace CGameMonster
{
static signed int (__thiscall *OnChangeGState)(int a) = (signed int (__thiscall*)(int))0x00439270;
static char (__thiscall *ModelSkill)(int a, char a2, int a3, unsigned __int8 a4, unsigned __int16 a5, unsigned __int16 a6, char a7, char a8) = (char (__thiscall*)(int, char, int, unsigned __int8, unsigned __int16, unsigned __int16, char, char))0x00438B90;
}

namespace CFxEntityManager
{
static signed int (__thiscall *AddFxToTarget)(void *player, const char* name, int targetID, char autoRemove, char continued, signed int nForced, int nTargetType) = (signed int (__thiscall*)(void*, const char*, int, char, char, signed int, int))0x0078B000;
}

namespace Honor
{
static int *Range = (int*)0x0097DF10;
static int *PrevRange = (int*)0x0097DF1C;
static int *Point = (int*)0x0097DF08;
static int *Kill = (int*)0x0097DF20;
static int *Die = (int*)0x0097DF24;
static int *DKPWin = (int*)0x0097DF2C;
static int *DKPFull = (int*)0x0097DF28;
static int *PLWin = (int*)0x0097DF34;
static int *PLFull = (int*)0x0097DF30;
static int *SVWin = (int*)0x0097DF3C;
static int *SVFull = (int*)0x0097DF38;
static int *Reward = (int*)0x0097DF0C;
}

static float *g_fCurrentTime = (float*)0x0099E768;
static void *AddFx = (void*)0x0099D0D0;
}

#endif