#include <windows.h>
#include "IItem.h"
#include "IChar.h"
#include "Functions.h"

IItem::IItem(void* Offset)
{
    this->Offset = Offset;
}

IItem::~IItem()
{
}

void* IItem::GetOffset()
{
    return this->Offset;
}

int IItem::GetInfo()
{
    return *(DWORD *)((int)this->Offset + 48);
}

int IItem::GetType()
{
    return *(DWORD *)(*(DWORD *)((int)this->Offset + 40) + 72) - 2;
}

int IItem::Prefix()
{
    return *(DWORD*)((int)this->Offset + 44);
}

int IItem::PrefixID()
{
    if (this->Prefix()) {
        return *(DWORD*)(*(DWORD*)((int)this->Offset + 44) + 32);
    }
    else {
        return 0;
    }
}

int IItem::GetEndurance()
{
    return *(DWORD*)((int)this->Offset + 96);
}

int IItem::GetIID()
{
    return *(DWORD *)((int)this->Offset + 36);
}

int IItem::CheckIndex()
{
    return *(DWORD *)(*(DWORD *)((int)this->Offset + 40) + 64);
}

void IItem::IncreaseEndurance(int Value)
{
    *(DWORD*)((int)this->Offset + 96) += Value;
}

void IItem::DecreaseEndurance(int Value)
{
    *(DWORD*)((int)this->Offset + 96) -= Value;
}

void IItem::SetInfo(int Value)
{
    *(DWORD *)((int)this->Offset + 48) = Value;
}

int IItem::GetTalismanOA()
{
    return *(DWORD *)((int)this->Offset + 100);
}

int IItem::GetTalismanOM()
{
    return *(DWORD *)((int)this->Offset + 104);
}

int IItem::GetTOA()
{
    return *(DWORD *)((int)this->Offset + 112);
}

int IItem::GetUpgrade()
{
    return *(DWORD *)((int)this->Offset + 124);
}

void IItem::SetTalismanOA(int Value)
{
    *(DWORD *)((int)this->Offset + 100) = Value;
}

void IItem::SetTalismanOM(int Value)
{
    *(DWORD *)((int)this->Offset + 104) = Value;
}

void IItem::SetTOA(int Value)
{
    *(DWORD *)((int)this->Offset + 112) = Value;
}

void IItem::SetUpgrade(int Value)
{
    *(DWORD *)((int)this->Offset + 124) = Value;
}

int IItem::GetAmount()
{
    return *(DWORD *)((int)this->Offset + 52);
}

int IItem::GetSetGem()
{
    return *(DWORD *)((int)this->Offset + 84);
}

void IItem::SetSetGem(int Value)
{
    *(DWORD *)((int)this->Offset + 84) = Value;
}

int IItem::LevelLimit()
{
    return *(DWORD *)(*(DWORD *)((int)this->Offset + 40) + 100);
}

void IItem::SetLevelLimit(int Value)
{
    *(DWORD *)(*(DWORD *)((int)this->Offset + 40) + 100) = Value;
}

int IItem::GetItemPointerFromIID(void *Player, int IID)
{
    IChar IPlayer(Player);

    if (IPlayer.IsOnline())
    {
        int CheckValue = 0, Checkx = 0, Recheckx = 0, IID = this->GetIID(), MyItem = 0;
        Undefined::CreateMonsterValue((char*)IPlayer.GetOffset() + 1068,
            (int)&CheckValue, (int)&IID);
        Checkx = Undefined::Check((int)((char*)IPlayer.GetOffset() + 1068),
                (int)&Recheckx);

        if (Undefined::CheckValues(&CheckValue, Checkx))
        {
            MyItem = *(DWORD *)(Undefined::GetValue(&CheckValue) + 4);
            return MyItem;
        }
    }

    return 0;
}

int IItem::GetGrade()
{
    return *(DWORD *)(*(DWORD *)((int)this->Offset + 40) + 80);
}