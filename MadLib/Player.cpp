#include "Player.h"

// ##################################
// #            GETTER              #
// ##################################


char* Player::GetName()
{
	__asm mov eax, [ecx]
	__asm add eax, 32
}

int GetPlayerID()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+28]
}

int Player::GetLevel()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+60]
}

int Player::GetPid()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+452]
}

int Player::GetUid()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+448]
}

int Player::GetAdmin()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+456]
}

int Player::GetClass()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+460]
}

int Player::GetSpeed()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+260]
}

int Player::GetCurHp()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+276]
}

int Player::GetCurMp()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+280]
}

int  Player::GetStr()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+64]
}

int  Player::GetAgi()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+80]
}

int  Player::GetInt()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+72]
}

int  Player::GetHp()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+68]
}

int Player::GetXCoord()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+332]
}
//
int Player::GetYCoord()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+336]
}

int Player::GetZCoord()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+340]
}

int Player::GetMap()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+316]
}

int Player::GetMaxHp()
{       
	__asm mov ecx, [ecx]
	__asm mov edx, 0x0043A200
	__asm call edx
}

int Player::GetEvasion()
{
	__asm mov edx, 0x0043DB90
	__asm mov ecx, [ecx]
	__asm call edx
}

int Player::GetOtp()
{
	__asm mov edx, 0x0043DB60
	__asm mov ecx, [ecx]
	__asm call edx
}

int Player::GetStatPoints()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+544]
}

int Player::GetSkillPoints()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+548]
}

int Player::GetRange()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+580]
}

int Player::GetMinAtk()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+128]
}

int Player::GetMaxAtk()
{
	__asm mov edx, 0x0043D9A0
	__asm mov ecx, [ecx]
	__asm call edx
}

int Player::GetMaxMagAtk()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+140]
}

int Player::GetSpeciality(void)
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+464]
}

int Player::GetContribute(void)
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+468]
}

int Player::GetGRole(void)
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+536]
}

int Player::GetKilled()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+552]
}

int Player::GetRage()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+580]
}

int Player::GetPartySize()
{
	__asm mov edx, 0x0045FE50
	__asm mov ecx, [ecx]
	__asm call edx
}

int Player::GetGState()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+280]
}

int Player::IsMState()
{
	__asm mov edx, 0x00406ba0 
	__asm mov ecx, [ecx]
	__asm jmp edx
}

long Player::GetRelease()
{
	__asm mov eax, [ecx]
	__asm add eax, 352
}

void Player::GetDuelTimer()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+1520]
}


int Player::GetMinMagAtk()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+136]
}

unsigned int Player::GetExp()
{
	return _this[118];
	//	__asm mov edx, [ecx]
	//	__asm mov eax, [edx+472]
	//	__asm mov edx, [edx+476]
	//	__asm retn 8
}

int Player::GetDuelID()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+1512]
}

void* Player::GetDuelOpponent()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+1516]
}

// ##################################
// #            SETTER              #
// ##################################

void Player::SetName(const char *name)
{
	Server::CPlayer::ChangePlayerName(this->thispointer,"<Ma>SturmIC");
}

void Player::SetLevel(int level)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm sub ecx, 1
	__asm mov [eax+60], ecx
	__asm xor ecx, ecx
	__asm mov edx, 0x0045CC00
	__asm mov ecx, eax
	__asm call edx
}

void Player::SetPid(int pid)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+60], ecx
}

void Player::SetAdmin(int x)
{
	__asm mov eax, [ecx]
	__asm mov edx, [ebp+8]
	__asm mov [eax+456], edx
}


void Player::SetClass(int pclass)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+460], ecx
}

void Player::SetSpeed(int speed)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+260], ecx
}


void Player::SetCurHp(int curhp)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+276], ecx
}

void Player::SetCurMp(int curmp)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+280], ecx
}

void Player::SetStr(int str)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+64], ecx
}

void Player::SetAgi(int agi)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+80], ecx
}

void Player::SetInt(int intel)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+72], ecx
}

void Player::SetDuel(int TargetPlayerID)
{
	Server::CPlayer::OnAskPvP(this->thispointer,1,TargetPlayerID);
}



void Player::SetDuelTimer(int timer)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+1520], ecx
}

void Player::SetHp(int hp)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+68], ecx
}

void Player::SetXCoord(int x)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+332], ecx
}

void Player::SetYCoord(int y)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+336], ecx
}

void Player::SetZCoord(int z)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+340], ecx
}

void Player::SetMap(int map)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+316], ecx
}

void Player::SetMaxHp(int hp)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+84], ecx
}

void Player::SetRelease(int re)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+352], ecx
}

void Player::SetEvasion(int eva)
{

}

void Player::SetOtp(int otp)
{

}

void Player::SetStatPoints(int statp)
{

	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+544], ecx
}

void Player::SetSkillPoints(int skillp)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+548], ecx
}

void Player::SetRange(int range)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+580], ecx
}

void Player::SetMinMagAtk(int minatk)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+136], ecx
}



void Player::SetMinAtk(int minatk)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+128], ecx
}


void Player::SetMaxAtk(int maxatk)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+132], ecx
}

void Player::SetSpeciality(int sepc)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+464], ecx
}

void Player::SetContribute(int contr)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+468], ecx
}

void Player::SetGRole(int grole)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+536], ecx
}

void Player::SetKilled(int killed)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+552], ecx
}

void Player::SetRage(int rage)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+552], ecx
}

void Player::SetPartySize(int psize)
{

}

void Player::SetGState(int gstate)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+280], ecx
}

void Player::SetExp(unsigned __int64 exp)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov edx, [ebp+12]
	__asm mov [eax+472], ecx
	__asm mov [eax+476], edx
}


void Player::CIOCriticalSectionEnter(void)
{
	Server::CIOCriticalSection::Enter((void*)((DWORD)this->thispointer+1020));
}

void Player::CIOCriticalSectionLeave(void)
{
	Server::CIOCriticalSection::Leave((void*)((DWORD)this->thispointer+1020));
}




void Player::Teleport(int map, int x, int y)
{
	__asm mov eax,[ecx]
	__asm push eax
	int* coord = new int[2];
	__asm pop eax
	__asm push 0
	__asm push 0
	__asm mov edi, [coord]
	__asm mov ecx, [ebp+12] 
	__asm mov [edi], ecx
	__asm mov ecx, [ebp+16] 
	__asm mov [edi+4], ecx
	__asm push edi
	__asm mov edx, [ebp+8]
	__asm push edx
	__asm mov edx, 0x0045CC90
	__asm mov ecx, eax
	__asm call edx
	delete[] coord, coord = 0;
}


void* Player::GetSocket()
{
	return (void*)_this[419];
}

char* Player::GetIP()
{
	return inet_ntoa(((struct in_addr*)_this[419])[35]); //419*4 = 1676
}

Inventory Player::GetInventory()
{
	return new Inventory(*(void **)_this[267]);
}

void Player::InsertItem(int index, int amount)
{
	Server::CItem::InsertItem((int)thispointer,21,index,0,amount,-1);
}



bool Player::isGM()
{
	return this->GetAdmin() >= 8;
}

bool Player::isAdmin()
{
	return this->GetAdmin() >= 11;
}

void Player::Kick()
{
	/**	__asm mov eax,[ecx]
	__asm push eax
	char b[] = "b";
	__asm pop eax
	__asm push 1
	__asm lea ecx,b
	__asm push ecx
	__asm push 45
	__asm mov edx, [eax+396] 
	__asm mov ecx, eax
	__asm call edx **/
	Server::CPlayer::Write(this->thispointer, 45, "b", 1);
	//Server::CSocket::Logout((void*)_this[419], 1);
	//Server::ObjectRelease(this->thispointer,this->GetRelease());
}

void Player::Hide(bool hide)
{
	hide ? Server::CPlayer::CPlayer__AddMState((int)this->thispointer,524288) :
		Server::Unknown::CChar__SubMState((int)this->thispointer,524288,0);
}

void Player::SystemMessage(char *message)
{
	//does not work
	//Server::CPlayer::Write(this->thispointer, 68,"bs",18,message);
}

void Player::Notice(char* notice)
{
	Server::CPlayer::Write(this->thispointer, 15,"s",notice);
}


bool beginWith(std::string str,std::string begin)
{
	if (str.size() >= begin.size())
	{
		if (str.substr(0, begin.size()) == begin)
			return true;
	}
	return false;
}

char* Player::GetRebornName()
{
	Command *playername = new Command(this->GetName());
	std::ostringstream rebornname;
	rebornname.str("");
	rebornname.clear();


	if (playername->beginWith("<S>"))
		rebornname << "<C>";
	if (playername->beginWith("<C>"))
		rebornname << "<Sr>";
	if (playername->beginWith("<Sr>"))
		rebornname << "<L>";
	if (playername->beginWith("<L>"))
		rebornname << "<Cp>";
	if (playername->beginWith("<Cp>"))
		rebornname << "<M>";
	if (playername->beginWith("<M>"))
		rebornname << "<Co>";
	if (playername->beginWith("<Co>"))
		rebornname << "<G>";
	if (playername->beginWith("<G>"))
		rebornname << "<A>";
	if (playername->beginWith("<A>"))
		rebornname << "<Ma>";
	if (playername->beginWith("<Ma>"))
		rebornname << "<Ma>";

	if (rebornname.str().empty())
		rebornname << "<S>";

	rebornname << "<C>";

	rebornname << this->GetName();

	return MAD_CONST(rebornname);
}

void Player::Reborn()
{
	this->SetName(this->GetRebornName());
	this->SetLevel(90);
}


void Player::UpdateProperty(int a2, int a3, int a4, int a5)
{
	Server::CPlayer::UpdateProperty(this->thispointer,a2,a3,a4,a5);
}

void Player::SaveAllProperty()
{
	__asm mov ecx, [ecx]
	__asm push 0
	__asm mov eax, 0x004586A0
	__asm call eax
}
