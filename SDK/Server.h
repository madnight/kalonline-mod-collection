#ifndef __SERVER_H
#define __SERVER_H

namespace CPacket
{
	static int (__cdecl *xRead)(void *pPacket, const char* Format, ...) = (int (__cdecl*)(void*, const char*, ...))0x00497220;
	static int (__cdecl *Read)(char *pPacket, char *pPos, const char *sFormat, ...) = (int (__cdecl*)(char*, char*, const char*, ...))0x004975F0;
}

namespace CDBSocket 
{
	static int (__cdecl *RealProcess)(char *a1) = (int (__cdecl*)(char*))0x0040CD90;
	static int (__cdecl *Write)(unsigned char Type, const char* Format, ...) = (int (__cdecl*)(unsigned char, const char*, ...))0x0040DC80;
	static int (__thiscall *Process)(void *Socket, const char* Data) = (int (__thiscall*)(void*, const char*))0x00494930;
	static int (__cdecl *ProcessHtml)(int a1, char a2, char a3, ...) = (int (__cdecl*)(int,char,char,...))0x004948C0;
}

namespace Undefined
{
	static int (__thiscall *SendItemInfo)(void *Item, int Player, char Argument) = (int (__thiscall*)(void*,int,char))0x00427430;
	static void* (__cdecl* FindPlayer) (int nID) = (void* (__cdecl*) (int))0x00450810;
	static int (__cdecl *DeleteSkill)(int SkillPointer) = (int (__cdecl*)(int))0x00401020;
	static int (__cdecl *Login)(char a1, char a2, ...) = (int (__cdecl*)(char,char,...))0x00401E00;
	static signed int (__stdcall *CheckID)(int *ID) = (signed int (__stdcall*)(int*))0x00494230;
	static signed int (__fastcall *LoginSuccess)(signed __int32 *a1, unsigned int a2) = (signed int (__fastcall*)(signed __int32 *,unsigned int))0x00496CD0;
	static int (__thiscall *StoneOfChance)(void *pSkill, signed int SkillID) = (int (__thiscall*)(void*,signed int))0x00480240;
	static LONG (__thiscall *ForKick)(void *Object, int Value) = (LONG (__thiscall*)(void*,int))0x00495B20;
	static bool (__thiscall *CheckValues)(void *Argument, int Value) = (bool (__thiscall*)(void*,int))0x0047D070;
	static int (__cdecl *MapCheck)(signed int a1) = (int (__cdecl*)(signed int))0x00491080;
	static int (__cdecl *GetMonsterValue)(size_t Argument) = (int (__cdecl*)(size_t))0x00401000;
	static signed int (__thiscall *CellMapCheck)(void *a, int a2, int a3) = (int (__thiscall*)(void*,int,int))0x00491360;
	static void* (__thiscall *MonsterCreate)(void *a) = (void* (__thiscall*)(void*))0x00442DF0;
	static int (__thiscall *CreateMonsterValue)(void *a, int a2, int a3) = (int (__thiscall*)(void*,int,int))0x0044AE20;
	static int (__thiscall *Check)(int a, int a2) = (int (__thiscall*)(int,int))0x00430C20;
	static int (__thiscall *GetValue)(void *a) = (int (__thiscall*)(void*))0x00420250;
	static signed int (__thiscall *MonsterPath)(void *Map, int Object, signed int AddX, signed int AddY, int Value, int Argument) = (signed int (__thiscall*)(void*,int,signed int,signed int,int,int))0x004925C0;
	static int (__cdecl *CalcRange)(int a1, int a2) = (int (__cdecl*)(int, int))0x00448870;
	static int (__cdecl *Blob)(int a1, int a2) = (int (__cdecl*)(int,int))0x0043D870;
	static int (__thiscall *sub_40F070)(void *a, int *a2) = (int (__thiscall*)(void*, int*))0x0040F070;
	static int (__thiscall *sub_430C20)(int a, int *a2) = (int (__thiscall*)(int, int*))0x00430C20;
	static bool (__thiscall *sub_47D070)(int Value) = (bool (__thiscall*)(int))0x0047D070;
	static int (__thiscall *sub_420250)(void *a) = (int (__thiscall*)(void*))0x00420250;
	static int (__thiscall *sub_446090)(void* a3, int *a, int a2) = (int (__thiscall*)(void*, int*, int))0x00446090;
}

namespace Server
{
	namespace CSocket
	{
		static void (__thiscall *Process)(void *Socket, const char* Data) = (void (__thiscall*)(void*, const char*))0x00494930;
		static void (__cdecl *Write)(void *Socket, unsigned char Type, const char* Format, ...) = (void (__cdecl*)(void*, unsigned char, const char*, ...))0x004948c0;
	}
	namespace CPlayer
	{
		static void (__cdecl *Write)(void *Player, unsigned char Type, const char* Format, ...) = (void (__cdecl*)(void*, unsigned char, const char*, ...))0x00452e60;
		static char* (__thiscall *GetGuildName)(void *Player) = (char* (__thiscall*)(void*))0x0046acd0;
		static char* (__thiscall *GetGuildClassTitle)(void *Player) = (char* (__thiscall*)(void*))0x0046ad70;
		static unsigned long (__cdecl *FindPlayer)(void *Player) = (unsigned long (__cdecl*)(void*))0x00450890;
		static int (__thiscall *IsPCBang)(void *Player) = (int (__thiscall*)(void*))0x0046c040;
		static void (__thiscall *Send)(void *Player, char* Data) = (void (__thiscall*)(void*, char*))0x00452e00;
	}
	namespace CChar
	{
		static void (__thiscall *Lock)(void *Char) = (void (__thiscall*)(void*))0x00412e90;
		static void (__thiscall *Unlock)(void *Char) = (void (__thiscall*)(void*))0x00412eb0;
		static int (__thiscall *IsGState)(void *Char, unsigned long State) = (int (__thiscall*)(void*, unsigned long))0x0040b310;
		static int (__thiscall *AddGState)(void *Char, unsigned long State) = (int (__thiscall*)(void*, unsigned long))0x00409910;
		static void (__cdecl *WriteInSight)(void *Char, unsigned char Type, const char* Format, ...) = (void (__cdecl*)(void*, unsigned char, const char*, ...))0x0040b9e0;
		static unsigned short (__thiscall *GetMaxMagic)(void *Char) = (unsigned short (__thiscall*)(void*))0x00458240;
		static unsigned short (__thiscall *GetMinMagic)(void *Char) = (unsigned short (__thiscall*)(void*))0x00458210;
		static unsigned short (__thiscall *GetMaxAttack)(void *Char) = (unsigned short (__thiscall*)(void*))0x0043d9d0;
		static unsigned short (__thiscall *GetMinAttack)(void *Char) = (unsigned short (__thiscall*)(void*))0x0043d9a0;
		static unsigned short (__thiscall *GetResist)(void *Char, unsigned char Type) = (unsigned short (__thiscall*)(void*, unsigned char))0x00438fa0;
	}
	namespace CObject
	{
		static long (__cdecl *WriteExclusive)(unsigned char Type, const char* Format, ...) = (long (__cdecl*)(unsigned char, const char*, ...))0x0044fce0;
	}
	namespace CMonster
	{
		static void (__thiscall *OnDelete)(void *Monster) = (void (__thiscall*)(void*))0x0043a3f0;
		static unsigned long (__thiscall *GetOperatorName)(void *Monster) = (unsigned long (__thiscall*)(void*))0x0043a720;
		static unsigned long (__thiscall *GetGuildName)(void *Monster) = (unsigned long (__thiscall*)(void*))0x00438eb0;
	}
	namespace CSMap
	{
		static unsigned long (__thiscall *GetCellMap)(void *_this, void*, void*) = (unsigned long (__thiscall*)(void*, void*, void*))0x00491360;
	}
	namespace CIOBuffer
	{
		static void (__thiscall *Release)(void *Buffer) = (void (__thiscall*)(void*))0x00401070;
	}
	namespace CBuff
	{
		static void* (__cdecl *CreateBuff)(int, int) = (void* (__cdecl*)(int, int))0x004402610;
	}
	namespace CDBSocket
	{
		static void (__cdecl *Write)(unsigned char Type, const char* Format, ...) = (void (__cdecl*)(unsigned char, const char*, ...))0x0040dc80;
	}
	namespace CIOCriticalSection
	{
		static void (__thiscall *Enter)(void *Section) = (void (__thiscall*)(void*))0x00423640;
		static void (__thiscall *Leave)(void *Section) = (void (__thiscall*)(void*))0x004236d0;
	}
	namespace CBase
	{
		static void* (__thiscall *Id)(void *base) = (void* (__thiscall*)(void*))0x00407760;
	}
	namespace CItem
	{
		static char* (__cdecl *PutByte)(char*, char) = (char* (__cdecl*)(char*, char))0x004189a0;
		static char* (__cdecl *PutWord)(char*, short) = (char* (__cdecl*)(char*, short))0x0042f960;
		static char* (__cdecl *PutDword)(char*, long) = (char* (__cdecl*)(char*, long))0x0044f9b0;
	}
	static void (__cdecl *WriteConsole)(const char*, ...) = (void (__cdecl*)(const char*, ...))0x004328c0;
	static char* (__cdecl *ReadPacketSecure)(char* Data, char* DataEnd, const char* Format, ...) = (char* (__cdecl*)(char*, char*, const char*, ...))0x004975f0;
}

#endif