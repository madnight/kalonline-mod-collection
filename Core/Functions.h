namespace CSkill
{
	static void (__thiscall *Occupation)(void *SkillPointer) = (void (__thiscall*)(void*))0x004800E0;
	static signed int (__thiscall *LearnSkillCheck)(void *SkillPointer, signed int SkillID) = (int (__thiscall*)(void*,int))0x0047FD70;
	static bool (__stdcall *SkillPointers)(int Value, int Argument) = (bool (__stdcall*)(int,int))0x0048D9E0;
	static int (__thiscall *Calculations)(void *pSkill, int Player) = (int (__thiscall*)(void*,int))0x00480F20;
	static int (__thiscall *GetMagic)(void *Object, int Player, char Index, int Argument) = (int (__thiscall*)(void*,int,char,int))0x004856D0;
	static signed int (__thiscall *MagicTick)(void *Monster) = (signed int (__thiscall*)(void*))0x00442030;
	static int (__thiscall *Cure)(void *pSkill, int Player, void *pPacket, int pPos) = (int (__thiscall*)(void*, int, void*, int))0x00485B80;
	static int (__thiscall *GroupCure)(void *pSkill, int Player, int pPacket, int pPos) = (int (__thiscall*)(void*, int, int, int))0x004871C0;
	static void (__thiscall *SkillUp)(void *SkillPointer, signed int SkillID) = (void (__thiscall*)(void*,signed int))0x0047F970;
	static void (__thiscall *LearnSkill)(void *SkillPointer, signed int SkillID) = (void (__thiscall*)(void*,int))0x0047F7A0;
	static int (__thiscall *PrepareSkill)(void *SkillPointer, signed int SkillID, int Argument) = (int (__thiscall*)(void*,signed int,int))0x00480390;
	static void (__thiscall *LifeAbsorption) (void* pSkill, void* pPlayer, char* pPacket, char* pPos) = (void (__thiscall*) (void*, void*, char*, char*))0x00488330;
	static void (__thiscall *SoulDestruction) (void* pSkill, void* pPlayer, char* pPacket, char* pPos) = (void (__thiscall*) (void*, void*, char*, char*))0x00482FA0;
	static int (__thiscall *BlessingOfHealth) (int SkillPointer, int Player, int Target, int Argument) = (int (__thiscall*) (int, int, int,int))0x00489DD0;
	static int (__thiscall *BlessingOfCriticalHit) (int SkillPointer, int Player, int Target, int Argument) = (int (__thiscall*) (int, int, int,int))0x00489F60;
	static int (__thiscall *BlessingOfAgility) (int SkillPointer, int Player, int Target, int Argument) = (int (__thiscall*) (int, int, int,int))0x00489E60;
	static int (__thiscall *BlessingOfStrength) (int SkillPointer, int Player, int Target, int Argument) = (int (__thiscall*) (int, int, int,int))0x00489D90;
	static int (__thiscall *BlessingOfIntelligence) (int SkillPointer, int Player, int Target, int Argument) = (int (__thiscall*) (int, int, int,int))0x00489EE0;
	static int (__thiscall *ExecuteSkill) (void *SkillPointer, signed int SkillID, int Argument, int Value) = (int (__thiscall*)(void*,signed int,int,int))0x0047FBB0;
	static void (__thiscall *RefiningWeapon) (void* pSkill, void* pPlayer, char* pPacket, char* pPos) = (void (__thiscall*) (void*, void*, char*, char*))0x00488820;
	static void (__thiscall *DefenseImprovement) (void* pSkill, void* pPlayer, char* pPacket, char* pPos) = (void (__thiscall*) (void*, void*, char*, char*))0x004889F0;
	static void (__thiscall *SpeedUp) (void* pSkill, void* pPlayer, char* pPacket, char* pPos) = (void (__thiscall*) (void*, void*, char*, char*))0x00486EC0;
	static int (__thiscall *CheckBuff)(void *Value, int Argument, int Player) = (int (__thiscall*)(void*,int,int))0x00489AA0;
	static LONG (__thiscall* ObjectRelease)(void* pOject, LONG lpAddend) = (LONG (__thiscall*)(void*, LONG))0x004239C0;
	static void (__thiscall *ExecuteTransformSkill)(void *SkillPointer, signed int SkillID, int Argument, int Value) = (void (__thiscall*)(void*,signed int,int,int))0x0047FC90;
	static int (__thiscall *SkillOnLoad)(int pSkill, signed int SkillID, int pPos) = (int (__thiscall*)(int,signed int,int))0x0047F6B0;
	static int (__thiscall* Storm)(void* a, int a2, void* Player, int a4) = (int (__thiscall*)(void*, int, void*, int))0x004854D0;
	static int (__thiscall *Calls)(void *pSkill, int Player, int pPacket, int pPos) = (int (__thiscall*)(void*,int,int,int))0x0048A9A0;
	static int (__thiscall *Behead)(void *pSkill, int Player, void *pPacket, int pPos) = (int (__thiscall*)(void*,int,void*,int))0x004813A0;
}

namespace CPacket
{
	static int (__cdecl *xRead)(void *pPacket, const char* Format, ...) = (int (__cdecl*)(void*, const char*, ...))0x00497220;
	static int (__cdecl *Read)(char *pPacket, char *pPos, const char *sFormat, ...) = (int (__cdecl*)(char*, char*, const char*, ...))0x004975F0;
}

namespace CChar
{
	static int (__thiscall *GetDodge)(int Player) = (int (__thiscall*)(int))0x0043DB90;
	static int (__thiscall *GetDex)(int Player) = (int (__thiscall*)(int))0x0043BF20;
	static int (__thiscall *GetMaxMagic)(int Player) = (int (__thiscall*)(int))0x00458240;
	static int (__thiscall *GetMinMagic)(int Player) = (int (__thiscall*)(int))0x00458210;
	static int (__thiscall *GetInt)(int Player) = (int (__thiscall*)(int))0x0043BEA0;
	static int (__thiscall *GetMaxHP)(int Player) = (int (__thiscall*)(int))0x0043A200;
	static int (__thiscall *GetStr)(int Player) = (int (__thiscall*)(int))0x0043BE20;
	static int (__thiscall *GetHit)(int Player) = (int (__thiscall*)(int))0x0043DB60;
	static int (__thiscall *GetMinAttack)(int Player) = (int (__thiscall*)(int))0x0043D9A0;
	static int (__thiscall *IsMStateEx)(int Player, int Buff) = (int (__thiscall*)(int,int))0x00409310;
	static int (__thiscall *GetHth)(int Player) = (int (__thiscall*)(int))0x0043BE60;
	static __int64 (__thiscall *IsBState)(int Object, __int64 Value) = (__int64 (__thiscall*)(int,__int64))0x00409720;
	static int (__thiscall *GetWis)(int Player) = (int (__thiscall*)(int))0x0043BEE0;
	static int (__thiscall *GetFatalDamage)(int Player, int Damage, int Argument, int Value) = (int (__thiscall*)(int,int,int,int))0x0043EAC0;
	static int (__thiscall *GetMaxHp)(int Object) = (int (__thiscall*)(int))0x0043A200;
	static int (__thiscall *GetMaxMp)(int Object) = (int (__thiscall*)(int))0x0043AF90;
	static int (__thiscall *IsNormal) (int Object) = (int (__thiscall*) (int))0x0040B280;
	static int (__thiscall *Lock) (void *Object) = (int (__thiscall*) (void*))0x00412E90;
	static int (__thiscall *Unlock) (void *Object) = (int (__thiscall*) (void*))0x00412EB0;
	static int (__cdecl *WriteInSight) (void* pPlayer, BYTE bType, const char *Format, ...) = (int (__cdecl*) (void*, BYTE, const char*, ...))0x0040B9E0;
	static int (__thiscall *IsGState) (int Player, int Argument) = (int (__thiscall*)(int,int))0x0040B310;
	static int (__thiscall *FindBuff)(int Player, int BuffID) = (int (__thiscall*)(int,int))0x0040B4A0;
	static LONG (__thiscall *AddGState) (int Player, int Argument) = (LONG (__thiscall*) (int, int))0x00409910;
	static signed int (__thiscall *GetFinalDamage)(void *Value, int Player, int Damage, int Argument) = (signed int (__thiscall*)(void*,int,int,int))0x0043AD50;
	static void (__cdecl *WriteInRect)(int Player, unsigned char Type, int value, const char* Format, ...) = (void (__cdecl*)(int, unsigned char, int, const char*, ...))0x0040BA70;
	static bool (__thiscall *CheckHit) (void* pPlayer, void* pTarget, int arg) = (bool (__thiscall*) (void*, void*, int))0x0043DA00;
	static int (__thiscall *CancelBuffParty) (void *Player, int BuffID) = (int (__thiscall*)(void*,int))0x0040B870;
	static int (__thiscall *CancelAllBuff)(void *Player, int BuffID) = (int (__thiscall*)(void*,int))0x0040B6A0;
	static int (__thiscall *CancelAllBuff2)(void *Player) = (int (__thiscall*)(void*))0x0040B750;
	static __int64 (__thiscall *IsMState)(int Player, __int64 Argument) = (__int64 (__thiscall*)(int,__int64))0x00406BA0;
	static void (__thiscall *SetDirection)(void *Value, int Player, int Argument) = (void (__thiscall*)(void*,int,int))0x0040B180;
	static int (__thiscall *GetAttack)(void *Object) = (int (__thiscall*)(void*))0x0043D970;
	static unsigned (__thiscall* GetMagic) (void* pPlayer) = (unsigned (__thiscall*) (void*))0x00483230;
	static signed int (__thiscall *GetASpeed)(int Object) = (signed int (__thiscall*)(int))0x0043D8E0;
	static int (__cdecl *GetRange) (int Object, int NextObject) = (int (__cdecl*) (int, int))0x00448870;
	static int (__thiscall *GetAbsorb)(int Object) = ( int (__thiscall*)(int))0x00438F70;
	static int (__thiscall *GetDefense)(void *Value, int Player) = (int (__thiscall*)(void*,int))0x00438F30;
	static int (__thiscall *GetMaxAttack)(int Object) = (int (__thiscall*)(int))0x0043D9D0;
	static int (__thiscall *GetResist)(void* Object, int Type) = (int (__thiscall*)(void*, int))0x00438FA0;
	static int (__thiscall *AddMState)(void *player, int a2, int a3) = (int (__thiscall*)(void*,int,int))0x0043CE00;
	static int (__thiscall *SubMState)(void *player, int a2, int a3) = (int (__thiscall*)(void*,int,int))0x0043CE50;
	static int (__thiscall *SubGState)(int player, int a2) = (int (__thiscall*)(int,int))0x0040AC20;
	static int (__thiscall *SetXY)(int Object, int Tile) = (int (__thiscall*)(int,int))0x0040B110;
	static int (__thiscall *GetBuffRemain)(void *Object, int BuffID) = (int (__thiscall*)(void*,int))0x0040B4E0;
}

namespace CIOCriticalSection
{
	static void (__thiscall *Enter)(void *Section) = (void (__thiscall*)(void*))0x00423640;
	static int (__thiscall *Leave)(void *Section) = (int (__thiscall*)(void*))0x004236D0;
}

namespace CItemDefense
{
	static signed int (__thiscall *StorageIn)(void *Item, int Player, int Argument) = (signed int (__thiscall*)(void*,int,int))0x0042B0F0;
	static char (__thiscall *ApplySpec) (int Item, int Player) = (char (__thiscall*)(int,int))0x0042AAF0;
	static int (__thiscall *PutOn)(int Item, int Player) = (int (__thiscall*)(int ,int))0x0042AC10;
	static int (__thiscall *PutOff)(void *Item, int Player) = (int (__thiscall*)(void*,int))0x0042AD60;
	static signed int (__thiscall *ChangePrefix)(void *Item, int Player, int ID, int Chance, int a5) = (signed int (__thiscall*)(void*,int,int,int,int))0x0042B710;
}

namespace CMonsterReal
{
	static int (__thiscall *Move)(int Monster) = (int (__thiscall*)(int))0x0043DBC0;
	static signed int (__thiscall *GetChasePt)(int Monster, int Argument, int Value) = (signed int (__thiscall*)(int,int,int))0x0043E470;
	static int (__thiscall *AI) (void *Monster) = (int (__thiscall*) (void*))0x0043D060;
	static int (__thiscall *ScanSight) (int Object) = (int (__thiscall*)(int))0x0043E8C0;
	static int (__thiscall *Attack) (int Monster) = (int (__thiscall*)(int))0x0043D510;
	static void (__thiscall *Tick) (void* Monster) = (void (__thiscall*)(void*))0x0043D140;
	static int (__thiscall *AddHostility) (void *Monster, int Player, int mainHost, signed int additionalHost) = (int (__thiscall*)(void*,int, int, signed int))0x0043D210;
	static int (__thiscall *Die) (int mob, int buffIndex, int a3, int a4, int tankerID) = (int (__thiscall*) (int, int, int, int, int))0x00442360;
	static int (__thiscall *AllotExp) (int mob, int a2, int tankerID, int* a4) = (int (__thiscall*) (int, int, int, int*))0x0043ECC0;
}

namespace CInitMonster
{
	static bool (__thiscall *IsRace)(int Object, int Type) = (bool (__thiscall*)(int,int))0x00441570;
	static int (__thiscall *DropItem)(void* any, int a2, int a3, int tankerID, int a5, int a6) = (int (__thiscall*)(void*,int, int, int, int, int))0x00437D70;
}

namespace CItemGeneral
{
	static signed int (__thiscall *StorageIn)(int Item, int Player, int Amount) = (signed int (__thiscall*)(int,int,int))0x0042D180;
	static int (__thiscall *Use)(void *Item, int Player) = (int (__thiscall*)(void*,int))0x0042CFB0;
}

namespace CInitItem
{
	static char (__thiscall *ApplySpec)(int Item,int Player) = (char (__thiscall*)(int,int))0x0041ED70;
	static int (__thiscall *Use)(int Item, int Player) = (int (__thiscall*)(int,int))0x0041EE50;
}

namespace CItem
{
	static LONG (__cdecl *NewIID)() = (LONG (__cdecl*)())0x004273B0;
	static char* (__cdecl *PutByte)(char*, char) = (char* (__cdecl*)(char*, char))0x004189A0;
	static char* (__cdecl *PutWord)(char*, short) = (char* (__cdecl*)(char*, short))0x0042F960;
	static char* (__cdecl *PutDword)(char*, long) = (char* (__cdecl*)(char*, long))0x0044F9b0;
	static int (__thiscall *OnTimer)(int Item, int Value) = (int (__thiscall*)(int,int))0x00426640;
	static int (__cdecl *FindInitItem)(int Index) = (int (__cdecl*)(int))0x00425C60;
	static int (__cdecl *NewItem)(int Value) = (int (__cdecl*)(int))0x00425D00;
	static int (__thiscall *AddGState)(int Object, int Item) = (int (__thiscall*)(int,int))0x004261F0;
	static int (__thiscall *RemoveItem)(void *Player, int Item) = (int (__thiscall*)(void*,int))0x0046F320;
	static signed int (__stdcall *MixItemCheck)(int MainItem, int Weapon, int Armor) = (signed int (__stdcall*)(int,int,int))0x0046EF90;
	static int (__thiscall *ReturnIndex)(int Item) = (int (__thiscall*)(int))0x0046EF70;
	static int (__stdcall *InsertItem)(int Player, int Value, int Index, int Prefix, int Amount, int Argument) = (int (__stdcall*)(int,int,int,int,int,int))0x004274A0;
	static int (__thiscall *GetLevel)(int Item) = (int (__thiscall*)(int))0x004295B0;
	static int (__thiscall *SendItemInfo)(void *Item, int Player, char Argument) = (int (__thiscall*)(void*,int,char))0x00427430;
	static int (__thiscall *IsState)(int Item, int Argument) = (int (__thiscall*)(int,int))0x00427130;
	static int (__thiscall *SubState)(int Item, int Argument) = (int (__thiscall*)(int,int))0x00427B90;
	static int (__cdecl *FindPrefix)(char ID) = (int (__cdecl*)(char))0x00425CB0;
	static int (__cdecl *CreateItem)(int Index, int Prefix, int Value, int Argument) = (int (__cdecl*)(int,int,int,int))0x00426110;
	static int (__thiscall *AddState)(int a, int a2) = (int (__thiscall*)(int,int))0x004261F0;
}

namespace CConsole
{
	static int (__cdecl *Red)(char *arg0, ...) = (int (__cdecl*)(char*,...))0x004328C0;
	static int (__cdecl *Blue)(char *arg0, ...) = (int (__cdecl*)(char*,...))0x00432860;
	static int (__cdecl *Black)(char *arg0, ...) = (int (__cdecl*)(char*,...))0x00432890;
}

namespace CPlayer
{
	static int (__thiscall *GetPalsyDamage)(int Player, int Target) = (int (__thiscall*)(int,int))0x0046C9F0;
	static int (__cdecl *UpdatePrtyPer)(int Player, int Type, int InOut, char Amount, int Value) = (int (__cdecl*)(int,int,int,char,int))0x0045B100;
	static int (__cdecl *UpdatePrtyPt)(int Player, int Type, int InOut, char Amount, int Value) = (int (__cdecl*)(int,int,int,char,int))0x00459840;
	static int (__cdecl *UpdateProperty)(int Player, int Type, int InOut, signed __int64 Exp) = (int (__cdecl*)(int,int,int,signed __int64))0x00458800;
	static int (__thiscall *AddWState)(int Player, char Type) = (int (__thiscall*)(int,char))0x00427BB0;
	static size_t (__thiscall *ProcessMsg)(void *Player, char *Msg) = (size_t (__thiscall*)(void*,char*))0x00460A50;
	static int(__cdecl *CountWarrelationPlayer)() = (int(__cdecl*)())0x0046E0D0;
	static int (__thiscall *SwitchStall)(void *Player, int Value) = (int (__thiscall*)(void*,int))0x0045F540;
	static void (__thiscall *OnTeleport)(void *Player, int Argument, int Value) = (void (__thiscall*)(void*,int,int))0x0045CE50;
	static int (__thiscall *GameStart)(void *Player) = (int (__thiscall*)(void*))0x00458270;
	static void *(__thiscall *SendCreate)(void *Player, int Object, void *Argument) = (void *(__thiscall*)(void*,int,void*))0x00451390;
	static int (__thiscall *CheckBlock)(int Player, int Object) = (int (__thiscall*)(int,int))0x00452130;
	static void (__cdecl *WriteInMap)(int Map, unsigned char Type, const char* Format, ...) = (void (__cdecl*)(int, unsigned char, const char*, ...))0x004509F0;
	static int (__cdecl *ScanPlayer)(int PID) = (int (__cdecl*)(int))0x00450790;
	static LONG (__thiscall *Hostility)(int Object, volatile LONG *lpAddend) = (LONG (__thiscall*)(int,volatile LONG*))0x00423980;
	static int (__thiscall *MLMAccumFee)(int Player, int Value) = (int (__thiscall*)(int,int))0x00467400;
	static int (__stdcall *SetEventCode)(signed int a1, int a2) = (int (__stdcall*)(signed int,int))0x0046BFD0;
	static int (__thiscall *GetInvenSize)(int Player) = (int (__thiscall*)(int))0x00456720;
	static int (__thiscall *GetMSpeed)(void *Player, int Value) = (int (__thiscall*)(void*,int))0x00452070;
	static void (__thiscall *DropItem)(int Player, char a2, int a3) = (void (__thiscall*)(int,char,int))0x0045D7E0;
	static void (__thiscall *DropItemONPKDie)(void *Player) = (void (__thiscall*)(void*))0x0046B890;
	static int (__thiscall *GetGuildName)(int Player) = (int (__thiscall*)(int))0x0046ACD0;
	static signed int (__thiscall *InitStat)(void *Player) = (signed int (__thiscall*)(void*))0x00465250;
	static int (__thiscall *TradeAgreed)(void *Player) = (int (__thiscall*)(void*))0x0045E720;
	static int (__thiscall *CancelTrade)(void *Player) = (int (__thiscall*)(void*))0x0045E3B0;
	static int (__thiscall *CutdownExp)(int Player, signed int expLoss) = (int (__thiscall*)(int, signed int))0x004643A0;
	static void (__cdecl *EventBuff)(int ID) = (void (__cdecl*)(int))0x0046B770;
	static signed int (__thiscall *RemoveItem)(void *Player, int Value, int Index, int Amount) = (signed int (__thiscall*)(void*,int,int,int))0x0045DA90;
	static int (__thiscall *BuyItemEx)(void *Player, char Npc, int Tax, int ItemSize, int pPacket, int pPos) = (int (__thiscall*)(void*,char,int,int,int,int))0x0045D2F0;
	static int (__thiscall *Imperial)(void *pPlayer, int MainItem, int Armor, int Stone, int Weapon, int NextStone) = (int (__thiscall*)(void*,int,int,int,int,int))0x0046F350;
	static void (__thiscall *EnforceItem)(void *pPlayer, int MixLevel, int ItemIndex, int DemonSword, int Item, int NextItem, char Stone) = (void (__thiscall*)(void*,int,int,int,int,int,char))0x0046E1B0;
	static int (__thiscall *_OutOfInven)(void *Player,int Item) = (int (__thiscall*)(void*,int))0x0045D140;
	static int (__thiscall *ChatCommand)(int Player, const char *Command) = (int (__thiscall*)(int,const char*))0x00461080;
	static int (__thiscall *RevivalSkill) (void *Player, int Argument, int Target) = (int (__thiscall*) (void*, int, int))0x00464750;
	static signed int (__thiscall *RevivalItem) (void *Player, int Argument) = (signed int (__thiscall*) (void*, int))0x00464950;
	static void (__cdecl *Write)(void *Player, unsigned char Type, const char* Format, ...) = (void (__cdecl*)(void*, unsigned char, const char*, ...))0x00452E60;
	static int (__thiscall *Attack)(void *Player,int Target, int TargetID) = (int (__thiscall*)(void*,int,int))0x0045C740;
	static signed int (__thiscall *Damage)(int Player, int Target, int Damage, int Argument, int Argument1, int Argument2, int Argument3) = (signed int (__thiscall*)(int,int,int,int,int,int,int))0x00451530;
	static int (__thiscall *Rest)(void *Player, int Value) = (int (__thiscall*)(void*,int))0x004642B0;
	static int (__thiscall *IsEState) (int Player, int Argument) = (int (__thiscall*) (int, int))0x0044A510;
	static int (__thiscall *SubEState) (int Player, int Argument) = (int (__thiscall*) (int, int))0x0044A4E0;
	static int (__cdecl *FindPlayerByName)(char Name) = (int (__cdecl*)(char))0x00450890;
	static void* (__cdecl* FindPlayer) (int nID) = (void* (__cdecl*) (int))0x00450810;
	static int (__thiscall *Teleport) (int Player, int Map, int X, int Y, int Z) = (int (__thiscall*) (int, int, int, int, int))0x0045CC90;
	static bool (__thiscall *IsWearBuffStandard)(int Player) = (bool (__thiscall*)(int))0x0046BD80;
	static int (__thiscall *IsWState)(int Player, char Argument) = (int (__thiscall*)(int,char))0x00427BE0;
	static int (__thiscall *SubWState)(int Player, char Argument) = (int (__thiscall*)(int,char))0x00428CD0;
	static int (__thiscall *GetObjectAround)(void *Value, int pPlayer, int Argument) = (int (__thiscall*)(void*,int,int))0x004935A0;
	static int (__thiscall *_InsertItem)(void *Player, int Argument, int Item) = (int (__thiscall*)(void*,int,int))0x0045DE10;
	static char (__thiscall *Process)(void *Player, int Packet, void *Argument, int Value) = ( char (__thiscall*)(void*,int,void*, int))0x00452ED0;
	static void (__thiscall *ShowOffItem)(void *a, int a2, void *a3, int a4) = (void (__thiscall*)(void*,int,void*,int))0x0045E460;
	static int (__thiscall *MAILProcess)(void *a, int a2, int a3, int a4) = (int (__thiscall*)(void*,int,int,int))0x00468890;
	static int (__thiscall *FRDProcess)(void *a, int a2, void *a3, int a4) = (int (__thiscall*)(void*,int,void*,int))0x004675B0;
	static int (__thiscall *LevelUp)(void *Player) = (int (__thiscall*)(void*))0x0045CC00;
	static int (__thiscall *SaveAllProperty)(int Player, int Argument) = (int (__thiscall*)(int,int))0x004586A0;
	static int (__thiscall *LevelUpUnknown)(void *Player, int Argument) = (int (__thiscall*)(void*,int))0x0047FF00;
	static int (__thiscall *MLMPayMoney)(int Player, int Argument) = (int (__thiscall*)(int,int))0x00467080;
	static int (__thiscall *MLMLevelUp)(void *Player) = (int (__thiscall*)(void*))0x004674D0;
	static int (__thiscall *ExchangeDanjiToItem) (void *Player, int Value, int Argument) = (int (__thiscall*) (void*, int, int))0x0046D570;
	static int (__thiscall *ExchahgeItem) (void *Player, int Argument, int Value, int a4, int Index, int Amount) = (int (__thiscall*)(void*,int,int,int,int,int))0x00456AD0;
	static void (__thiscall *Transform)(void *Player, int Type, signed int Grade) = (void (__thiscall*)(void*,int,signed int))0x0046BA30;
	static void (__thiscall *FreeTransform)(void *Player) = (void (__thiscall*)(void*))0x0046BB90;
	static int (__thiscall *Tick)(void *Player) = (int (__thiscall*)(void*))0x00452620;
	static signed int (__thiscall *OnLoadPlayer)(void *Player, int Value) = (signed int (__thiscall*)(void*,int))0x00456C40;
	static int (__thiscall *LeaveParty)(int Player) = (int (__thiscall*)(int))0x0045FD70;
	static signed int (__thiscall *CanAttack)(void *Player, int Target, int Value) = (signed int (__thiscall*)(void*,int,int))0x0046AE50;
	static int (__cdecl *WriteAll)(unsigned char Type, const char* Format, ...) = (int (__cdecl*)(unsigned char, const char*, ...))0x00450910;
	static int (__thiscall *FindItem)(void *Player, int ItemIndex, int Amount) = (int (__thiscall*)(void*,int,int))0x0045D190;
	static int (__thiscall* SendMail)(void *Player, int a1, int a2, char *a3, const char* Text, int a4, int a5, int a6, int a7, int a8, int a9) = (int (__thiscall*)(void*,int, int, char *, const char*, int, int, int, int, int, int))0x00468280;
	static void (__thiscall *Pick)(void* MapObject, int Player, int x, int y) = (void (__thiscall*)(void*,int,int,int))0x004938A0;
}

namespace CQuest
{
	static char (__thiscall *Run)(void *Quest, int Player) = ( char (__thiscall*)(void*,int))0x0047CEC0;
}

namespace CDBSocket 
{
	static int (__cdecl *RealProcess)(char *a1) = (int (__cdecl*)(char*))0x0040CD90;
	static LPVOID (__cdecl *MemoryMalloc)(size_t size) = (LPVOID (__cdecl*)(size_t))0x00401000;
	static int (__cdecl *Write)(unsigned char Type, const char* Format, ...) = (int (__cdecl*)(unsigned char, const char*, ...))0x0040DC80;
	static int (__thiscall *Process)(void *Socket, const char* Data) = (int (__thiscall*)(void*, const char*))0x00494930;
	static int (__cdecl *ProcessHtml)(int a1, char a2, char a3, ...) = (int (__cdecl*)(int,char,char,...))0x004948C0;
}

namespace CParty
{
	static int (__cdecl *FindParty) (int partyID) = (int (__cdecl*)(int))0x0044D4E0;
	static int (__thiscall *GetRandomPlayer) (void *PartyID) = (int (__thiscall*)(void*))0x0044E7C0;
	static int (__thiscall *GetSize) (void *PartyID) = (int (__thiscall*)(void*))0x00412ED0;
	static int (__thiscall *Join) (int party, int inviter, int joiner) = (int (__thiscall*)(int, int, int))0x0044D9D0;
	static int (__cdecl *Accept) (int inviter, int joiner) = (int (__cdecl*)(int, int))0x0044D550;
	static void* (__cdecl *CParty) (void *a, int a2) = (void* (__cdecl*)(void*, int))0x0044D3C0;
	static void* (__cdecl *Add) (void *a) = (void* (__cdecl*)(void*))0x0044D7F0;
	static signed int (__thiscall *IsHead) (int a, int a2) = (signed int (__thiscall*)(int, int))0x0044D890;
	static int (__cdecl *Locks) (void *inviter, void *joiner) = (int (__cdecl*)(void*, void*))0x00460490;
	static int (__cdecl *Delocks) (void *inviter, void *joiner) = (int (__cdecl*)(void*, void*))0x0044D620;
	static void* (__cdecl *Unknown1) (size_t a1) = (void* (__cdecl*)(size_t))0x00435820;
	static int (__thiscall *GetPlayerList) (void *s) = (int (__thiscall*)(void*))0x0044F390;
	static int (__thiscall *Chant)(void *Party, int Player, int BuffID) = (int (__thiscall*)(void*,int,int))0x0044F290;
}

namespace CIOServer
{
	static void (__thiscall *Start)(int start,u_short hostshort) = (void (__thiscall*)(int start,u_short))0x00424A40;
}

namespace CItemWeapon
{
	static int (__thiscall *PutOff)(void *Player, int Argument) = (int (__thiscall*)(void*,int))0x00428770;
	static int (__thiscall *ApplySpec)(int Item, int Player) = (int (__thiscall*)(int,int))0x00427E70;
	static int (__thiscall *PutOn)(int Item, int Player) = (int (__thiscall*)(int,int))0x00428140;
	static signed int (__thiscall *ChangePrefix)(void *Item, int Player, int Type, int Chance, int Argument) = (signed int (__thiscall*)(void*,int,int,int,int))0x004297B0;
	static signed int (__thiscall *StorageIn)(void *Item, int Player, int Argument) = (signed int (__thiscall*)(void*,int,int))0x00428F30;
}

namespace CPrefix
{
	static char (__thiscall *ApplySpec)(int Item,int Player) = (char (__thiscall*)(int,int))0x0041FA60;
}

namespace CMonster
{
	static void (__thiscall *OnDelete)(void *Monster) = (void (__thiscall*)(void*))0x0043a3f0;
	static int (__thiscall *IsRemoved) (void *mID) = (int (__thiscall*) (void*))0x00449450;
	static void* (__cdecl *FindMonster) (int nID) = (void* (__cdecl*) (int))0x0043A240;
	static int (__thiscall *GetObjectAround)(void *Value, int pPlayer, int Argument) = (int (__thiscall*)(void*,int,int))0x004934F0;
	static signed int (__thiscall *CanAttack) (int Monster, int Target, int Value) = (signed int (__thiscall*) (int, int, int))0x0043A770;
	static int (__cdecl *ScanMonster) (int Index) = (int (__cdecl*) (int))0x0043A350;
}

namespace CConsolef
{
	static int (__cdecl *Red)(char *arg0, ...) = (int (__cdecl*)(char*,...))0x004328C0;
	static int (__cdecl *Blue)(char *arg0, ...) = (int (__cdecl*)(char*,...))0x00432860;
	static int (__cdecl *Black)(char *arg0, ...) = (int (__cdecl*)(char*,...))0x00432890;
	static BOOL (__cdecl *Status)() = (BOOL (__cdecl*)())0x004961B0;
}

namespace CBuff
{
	static void *(__thiscall *CBuffExpire)(void *Check, int BuffID, int Time, int Value, int Argument, int Val, int Arg) = (void *(__thiscall*)(void*,int,int,int,int,int,int))0x004064F0;
	static int (__cdecl *CreateBuff)(int BuffID, __int32 Time, int Stat, int Object) = (int (__cdecl*)(int,__int32,int,int))0x00402610;
	static void *(__cdecl *CheckBuffCreate)(size_t Check) = (void *(__cdecl*)(size_t))0x00401000;
	static int (__thiscall *CBuffRemainPrty)(void *Check, int BuffID, int Time, int Type, int Stat, int Argument, int Value) = (int (__thiscall*)(void*,int,int,int,int,int,int))0x00406770;
	static int (__thiscall *CBuffPrtyEx)(void *Check, int BuffID, int Time, int Type, int Stat, int Argument, int Value, int nType, int bType, int cType) = (int (__thiscall*)(void*,int,int,int,int,int,int,int,int,int))0x00406490;
	static int (__thiscall *CBuffPrtyExIsExpired)(int Buff, int Player) = (int (__thiscall*)(int,int))0x00409480;
}

namespace CBase
{
	static int (__thiscall *IsDeleted)(int Object) = (int (__thiscall*)(int))0x0040B2F0;
	static int (__thiscall *Delete)(void *Object) = (int (__thiscall*)(void*))0x00411780;
}

namespace CBaseList
{
	static int (__thiscall *Pop)(void *Object) = (int (__thiscall*)(void*))0x00402430;
}

namespace CLink
{
	static void* (__thiscall *MoveTo)(void *Value, int Argument) = (void* (__thiscall*)(void*,int))0x00438C40;
}

namespace CSMap
{
	static int (__stdcall *IsValidTile)(int X, int Argument) = (int (__stdcall*)(int,int))0x00438130;
	static int (__thiscall *IsOnTile)(void *Map, int CoordinateX, int Argument) = (int (__thiscall*)(void*,int,int))0x0045CD80;
}

namespace CIOObject
{
	static int (__thiscall *Release)(void *Object) = (int (__thiscall*)(void*))0x00401DE0;
	static LONG (__thiscall *AddRef)(int Object) = (LONG (__thiscall*)(int))0x004010D0;
}

namespace CItemOrnament
{
	static int (__thiscall *SetWearState)(int Item, int Player) = (int (__thiscall*)(int,int))0x0042C4B0;
	static signed int (__thiscall *StorageIn)(int Item, int Player, int Value) = (signed int (__thiscall*)(int,int,int))0x0042CB80;
	static int (__thiscall *PutOff)(void *Item, int Player) = (int (__thiscall*)(void*,int))0x0042C870;
	static char (__thiscall *ApplySpec)(void *Item, int Player) = (char (__thiscall*)(void*,int))0x0042C6E0;
	static int (__thiscall *PutOn)(int Item, int Player) = (int (__thiscall*)(int,int))0x0042C760;
	static void *(__thiscall *CItemOrnament)(void *Pointer, int Value) = (void *(__thiscall*)(void*,int))0x0042C450;
	static signed int (__thiscall *ChangePrefix)(void *Item, int Player, int Type, int Chance, int Argument) = (signed int (__thiscall*)(void*,int,int,int,int))0x0042CD20;
}

namespace CTools
{
	static unsigned int (__cdecl *Rate)(unsigned int Value, signed int Argument) = (unsigned int (__cdecl*)(unsigned int,signed int))0x00406E10;
}

namespace CItemTransform
{
	static int (__thiscall *SaveInfo)(int Argument, int Value) = (int (__thiscall*)(int,int))0x0042F2C0;
	static int (__thiscall *PutOn)(int Item, int Player) = (int (__thiscall*)(int,int))0x0042EAE0;
	static int (__thiscall *ApplySpec)(void *Item, int Player) = (int (__thiscall*)(void*,int))0x0042EA00;
	static int (__thiscall *FreeSpec)(void *Item, int Player) = (int (__thiscall*)(void*,int))0x0042EA70;
	static int (__thiscall *ApplyTransform)(int Type, int Player, signed int Grade) = (int (__thiscall*)(int,int,signed int))0x0042F300;
	static int (__thiscall *UpdateExp)(int PlayerEgg, int Player, int Check) = (int (__thiscall*)(int,int,int))0x0042F030;
}

namespace Undefined
{
	static int (__thiscall *ForPortalCheck)(void *Value, int Player) = (int (__thiscall*)(void*,int))0x00496520;
	static int (__thiscall *CreateSkillValue)(void *a, int a2, int a3) = (int (__thiscall*)(void*,int,int))0x00446130;
	static int (__thiscall *CheckSkillValue)(void *a, int a2, int a3) = (int (__thiscall*)(void*,int,int))0x0047F910;
	static void *(__thiscall *CheckSkillX)(void *a) = (void *(__thiscall*)(void*))0x0047F760;
	static int (__thiscall *CheckSkillY)(int a, int a2, int a3) = (int (__thiscall*)(int,int,int))0x0047F780;
	static int (__thiscall *CreateMonsterValueNew)(void *a, int a2, int a3) = (int (__thiscall*)(void*,int,int))0x00433170;
	static int (__cdecl *NewGetItem)(int a1, int a2) = (int (__cdecl*)(int,int))0x00426060;
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

namespace CMonsterMaguniMaster
{
	static int (__thiscall *AI)(void *Monster) = (int (__thiscall*)(void*))0x00440550;
	static int (__thiscall *Tick)(void *Monster) = (int (__thiscall*)(void*))0x00442E10;
	static int (__thiscall *Die)(int a, int b, int c, int d, int e) = (int (__thiscall*)(int, int, int, int, int))0x00444560;
}

namespace CNPC
{
	static int (__cdecl *FindNPC)(char Npc) = (int (__cdecl*)(char))0x00448FA0;
}

namespace CCastle
{
	static int (__cdecl *WarBegin)(int Time) = (int (__cdecl*)(int))0x00419E10;
	static int (__thiscall *WarEnd)(void *Value) = (int (__thiscall*)(void*))0x0041BEE0;
	static int (__cdecl *GetMonsterTile2CID)(int a1, int a2, int a3) = (int (__cdecl*)(int,int,int))0x0041A400;
	static signed int (__cdecl *IsAllCastleWarRelation)(int Check) = (signed int (__cdecl*)(int))0x0041A670;
	static int (__cdecl *GetCastle)(char Castle) = (int (__cdecl*)(char))0x0041A3B0;
	static int (__thiscall *GetTaxRate)(void *Tax) = (int (__thiscall*)(void*))0x0041B610;
	static int (__thiscall *IsPayment)(void *Castle) = (int (__thiscall*)(void*))0x0041B690;
	static int (__thiscall *AddTax)(void *Castle, int Price) = (int (__thiscall*)(void*,int))0x0041B700;
}

namespace CGuild
{
	static int (__cdecl *BrokenStandard)(int a1) = (int (__cdecl*)(int))0x00417BA0;
	static int (__cdecl *BrokenGate)(int a1, int a2) = (int (__cdecl*)(int,int))0x00417BE0;
	static bool (__cdecl *IsWarringPeriod)() = (bool (__cdecl*)())0x00417450;
}

namespace CLog
{
	static bool (__cdecl *AddV)(signed int Value, const char *Msg, va_list Argument) = (bool (__cdecl*)(signed int, const char*, va_list))0x00432530;
}

namespace CMonsterGuildWar
{
	static signed int (__thiscall *Damage)(void *Target, int Player, int Damage, int Arg, int Val, int Value, int Argument)  = (signed int (__thiscall*)(void*,int,int,int,int,int,int))0x00441590;
}

namespace CCalendar
{
	static void (__thiscall *OnTimer)(void *Value, int Argument) = (void (__thiscall*)(void*,int))0x0040A750;
}

namespace CItemMoney
{
	static signed int (__thiscall *StorageIn)(int Item, int Player, int Amount) = (signed int (__thiscall*)(int,int,int))0x0042E080;
}

namespace CMonsterInvaderBoss
{
	static void (__thiscall *AI)(void *Monster) = (void (__thiscall*)(void*))0x004457F0;
}

namespace CMonsterMaguniWithSkillOnly
{
	static void (__thiscall *AI)(void *Monster) = (void (__thiscall*)(void*))0x0043F4E0;
}

namespace CMonsterMaguniWithSkill
{
	static void (__thiscall *AI)(void *Monster) = (void (__thiscall*)(void*))0x0043F8E0;
}

namespace CMonsterSiegeGunBall
{
	static void (__thiscall *AI)(void *Monster) = (void (__thiscall*)(void*))0x004453B0;
}

namespace CMonsterSiegeGunRuins
{
	static void (__thiscall *AI)(void *Monster) = (void (__thiscall*)(void*))0x00442730;
}

namespace CMonsterSiegeGun
{
	static void (__thiscall *AI)(void *Monster) = (void (__thiscall*)(void*))0x00444A10;
}

namespace CMonsterMagic
{
	static int (__cdecl *Create)(int Index, int Value, int Argument, int Arg, int Player, int Damage, int Time) = (int (__cdecl*)(int,int,int,int,int,int,int))0x00441DE0;
}

namespace CNPCDoor
{
	static int (__thiscall *Tick)(void *NPC) = (int (__thiscall*)(void*))0x00449BF0;
}

namespace CBuffPrtyEx
{
	static int (__thiscall *FreeBuff)(int a, int Player) = (int (__thiscall*)(int,int))0x00409230;
}

namespace CPortal
{
	static int (__cdecl *OpenPortal)(int Player) = (int (__cdecl*)(int))0x0040EC70;
}

namespace CTrade
{
	static int (__thiscall *GetOther)(int TradeID, int Player) = (int (__thiscall*)(int,int))0x0045E6E0;
	static int (__thiscall *IsEnd)(int TradeID) = (int (__thiscall*)(int))0x0045E6C0;
}

namespace CObject
{
	static long (__cdecl *WriteExclusive)(unsigned char Type, const char* Format, ...) = (long (__cdecl*)(unsigned char, const char*, ...))0x0044FCE0;
}