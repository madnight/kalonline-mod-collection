/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
#include "Monster.h"

// ##################################
// #            GETTER              #
// ##################################


int Monster::GetIndex()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+512]
}

int Monster::Get164()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+656]
}

int Monster::Get120()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+480]
}

int Monster::Get128()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+512]
}

int Monster::Get119()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+476]
}

void* Monster::GetState()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+464]
}

int Monster::GetAI()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+480]
}

int Monster::GetX1()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+448]
}

int Monster::GetY1()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+452]
}

int Monster::GetX2()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+456]
}

int Monster::GetY2()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+460]
}

int Monster::GetDamage()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+304]
}

int Monster::GetTime()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+468]
}

int Monster::GetXCoord()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+332]
}
//
int Monster::GetYCoord()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+336]
}

int Monster::GetID()
{
return	Server::CBase::Id(this->thispointer);
///	__asm mov eax, [ecx]
//	__asm mov eax, [eax+28]
}

// ##################################
// #            SETTER              #
// ##################################

void Monster::SetIndex(int i)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+512], ecx
}



void Monster::SetDamage(int i)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+304], ecx
}

void Monster::SetTime(int i)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+468], ecx
}

void Monster::SetGstate(int i)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+280], ecx
}


void Monster::Die()
{
	/**
	if(iMonster.Get()->GetSummonTick() < nTime && iMonster.Get()->Data.summon_type != kPetSummon)
  {
   Server::CChar::WriteInSight(iMonster.GetOffset(), 0x49, "db", iMonster.GetPid(), 0x34);
   Server::CChar::WriteInSight(iMonster.GetOffset(), 0x38, "db", iMonster.GetPid(), 7);
   (*(int (__thiscall **)(int*, int))(*(unsigned int *)(unsigned int)iMonster.GetOffset() + 188))(iMonster.GetOffset(), 0);
   Server::CBase::Delete(iMonster.GetOffset());
   return true;
  }
  **/

	Server::CChar::WriteInSight(this->thispointer, 0x38, "d", this->GetID());
	Server::CMonster::OnDelete(this->thispointer);
	//Server::CChar::CancelAllBuff(this->thispointer);
//	Server::CChar::WriteInSight(this->thispointer,61,"db",this->GetID(),9);
//	Server::CChar::Unlock(this->thispointer);
//	Server::CBase::Delete(this->thispointer);
}

LONG Monster::GetRelease()
{
	__asm mov eax, [ecx]
	__asm add eax, 352
}
