static signed int (__cdecl *IsPlayerCheck)() = (signed int (__cdecl*)())0x00694D60;
static signed int (__cdecl *IsPlayerAttack)() = (signed int (__cdecl*)())0x006917A0;
static int (__thiscall *EndDashSkill)(int Player) = (int (__thiscall*)(int))0x0041DDA0;
static void *(__thiscall *SetTip)(int pTarget, LPCTSTR pString, COLORREF color, int dwLife, int bShowName) = (void *(__thiscall*)(int,LPCTSTR,COLORREF,int,int))0x0041A510;	
static int (__thiscall *PlayerTick)(void *pTarget, unsigned int Value) = (int (__thiscall*)(void*,unsigned int))0x00404620;
static signed int (__cdecl *SkillButton)(int Value) = (signed int (__cdecl*)(int))0x004149E0;

signed int __cdecl MySkillButton(int Value)
{
	if (Value == 93 && *(DWORD*)(*Engine::CGame_Character::m_Master + 20656) == 4)
	{
		Interface<IPackets> Packets;
		Packets->Send(117,"b",Value);
		return 0;
	}

	if (Value == 95)
	{
		Interface<IPackets> Packets;
		Packets->Send(117,"b",Value);
		return 0;
	}

	return SkillButton(Value);
}

signed int __cdecl MyIsPlayerCheck()
{
	if (*(DWORD*)(*Engine::CGame_Character::m_Master + 18304) & 256 || *(DWORD*)(*Engine::CGame_Character::m_Master + 18304) & 268435456)
		return 0;

	if (*(DWORD*)(*Engine::CGame_Character::m_Master + 18260) & 4194304)
		return 0;

	return IsPlayerCheck();
}

int __fastcall MyPlayerTick(void *pTarget, void *edx, unsigned int Value)
{
	int Check = PlayerTick(pTarget,Value);

	if (*(int*)((int)pTarget + 19564) == 1 && *(int*)((int)pTarget + 20656) == 0 && *(DWORD*)((int)pTarget + 19572))
	{
		if (GetTickCount() > (*(DWORD*)((int)pTarget + 19572) + 1500))
			EndDashSkill((int)pTarget);
	}

	if (*(DWORD*)((int)pTarget + 18256) & 262144)
	{
		if (*(DWORD *)((int)pTarget + 19828) == 0)
			SetTip((int)pTarget,*(const char**)((int)pTarget + 17592),RGB(0,128,255),10000,false);
	}

	if (*(DWORD*)((int)pTarget + 18256) & 524288)
	{
		if (*(DWORD *)((int)pTarget + 19828) == 0)
			SetTip((int)pTarget,*(const char**)((int)pTarget + 17592),RGB(255,0,0),10000,false);
	}

	return Check;
}

signed int __cdecl MyIsPlayerAttack()
{
	int Check = IsPlayerAttack();
	
	if (*(DWORD*)(*Engine::CGame_Character::m_Master + 18256) & 262144 || *(DWORD*)(*Engine::CGame_Character::m_Master + 18256) & 524288)
		Check = 1;

	return Check;
}

void *__fastcall MySetTip(int pTarget, void *edx, LPCTSTR pString, COLORREF color, int dwLife, int bShowName)
{
	if (*(DWORD*)(pTarget + 18256) & 262144)
		return SetTip(pTarget,pString,RGB(0,128,255),dwLife,bShowName);

	if (*(DWORD*)(pTarget + 18256) & 524288)
		return SetTip(pTarget,pString,RGB(255,0,0),dwLife,bShowName);

	return SetTip(pTarget,pString,color,dwLife,bShowName);
}