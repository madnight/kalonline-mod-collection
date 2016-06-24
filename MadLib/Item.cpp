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
 
#include "Item.h"

void Item::AddRef()
{
	__asm mov eax, [ecx]
	__asm mov eax, 0x004010D0
	__asm jmp eax
}

bool Item::Create(void *itemp, int a2, int a3)
{
	  __asm mov eax, [ebp+12]
	  __asm push 0
	  __asm push eax
	  __asm mov esi, ecx
	  __asm mov ecx, [ebp+8]
	  __asm push 0
	  __asm push ecx
	  __asm mov edx, 0x0046110
	  __asm call edx
	  __asm xor ecx, ecx
	  __asm mov [esi], eax
}


int Item::GetIID()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+36]
}



int Item::GetState()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+48]
}

int Item::GetNum()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+52]
}

int Item::GetGrade()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+92]
}

int Item::GetPid()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+32]
}

int Item::GetMaxEnd()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+92]
}

int Item::GetCurEnd()
{
	__asm mov eax, [ecx]
	__asm mov eax, [eax+96]
}

void Item::SetState(int state)
{
	__asm mov eax, [ecx]
	__asm mov edx, [ebp+8]
	__asm mov [eax+48], edx
}

void Item::Delete()
{
	__asm mov ecx, [ecx]
    __asm mov eax, 0x00411780
    __asm jmp eax
}

void Item::AddState(int state)
{
	__asm mov eax, [ecx]
	__asm mov edx, 0x004261F0
	__asm jmp edx
}

int Item::GetIndex()
{
	return ((int*)_this[10])[16]; 
}

//45E9DB look here
int Item::GetPrefix()
{
	if ( _this[11] )
		return ((int*)_this[11])[8]; 
	else 
		return 0;
}



bool Item::IsMixStone()
{
	if(this->GetIndex() == 9357 || this->GetIndex() == 9365)
		return true;
	else
		return false;
}

void Item::SetNum(int num)
{
	__asm mov eax, [ecx]
	__asm mov ecx, [ebp+8]
	__asm mov [eax+52], ecx
}

void Item::CopyProperties(Item item)
{
	_this[6] = ((int*) item.thispointer)[6];
	_this[8] = ((int*) item.thispointer)[8];
	_this[9] = ((int*) item.thispointer)[9];
	_this[10] = ((int*) item.thispointer)[10];
	_this[11] = ((int*) item.thispointer)[11];
	_this[12] = ((int*) item.thispointer)[12];
	_this[13] = ((int*) item.thispointer)[13];
	_this[14] = ((int*) item.thispointer)[14];
	_this[15] = ((int*) item.thispointer)[15];
	_this[16] = ((int*) item.thispointer)[16];
	_this[17] = ((int*) item.thispointer)[17];
	_this[18] = ((int*) item.thispointer)[18];
	_this[19] = ((int*) item.thispointer)[19];
	_this[20] = ((int*) item.thispointer)[20];
	_this[21] = ((int*) item.thispointer)[21];
	_this[22] = ((int*) item.thispointer)[22];
}



