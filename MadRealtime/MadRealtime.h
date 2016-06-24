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
 
#include <Windows.h>
#include <Player.h>
#include <MadCore.h>
#include <IniReader.h>
#include "Utilities.h"

#pragma comment(lib, "MadLib.lib")

class Realtime
{
public:
	int itemindex_before;
	int prefix_used;
	int mix_info;
	int itemindex_after;

	Realtime(int be,int pre,int inf,int af)
	{
		this->itemindex_before = be;
		this->prefix_used = pre;
		this->mix_info = inf;
		this->itemindex_after = af;
	}  

};


class MixRealtime
{
public:
	int index;
	int info;
	MixRealtime(int be,int pre)
	{
		this->index = be;
		this->info = pre;
	}  
};



vector<Realtime> realtimes;
vector<MixRealtime> mix_realtimes;

namespace MadRealtime
{
	void Load_Config()
	{
		CIniReader *reader = new CIniReader(".\\MadRealtime.txt");
		int approx_config_items = (reader->GetFileSize() / 10);
		int counter = 0;
		realtimes.clear();
		for (int i = 1; i<approx_config_items;i++)
		{
			std::ostringstream header;	
			header << "NormalItem " << i;

			int itemindex_before = reader->ReadInteger(MAD_CONST(header),"ItemIndexBefore",0);
			int prefix_used = reader->ReadInteger(MAD_CONST(header),"PrefixUsed",0);
			int mix_info = reader->ReadInteger(MAD_CONST(header),"MixInfo",0);
			int itemindex_after = reader->ReadInteger(MAD_CONST(header),"ItemIndexAfter",0);

			if (itemindex_before != 0 && itemindex_after != 0)
			{
				realtimes.push_back(Realtime(itemindex_before,prefix_used,mix_info,itemindex_after));
				counter++;
			}
		}

		for (int i = 1; i<approx_config_items;i++)
		{
			std::ostringstream header;	
			header << "MixItem " << i;

			int index = reader->ReadInteger(MAD_CONST(header),"StoneIndex",0);
			int info = reader->ReadInteger(MAD_CONST(header),"Info",0);

			if (index != 0 && info != 0)
			{
				mix_realtimes.push_back(MixRealtime(index,info));
				counter++;
			}
		}

		Server::Console::WriteBlue("[MadRealtime started installed %d Realtimes]",counter); // (XEAxMaste Edition)
		delete reader;
	}

	namespace CIOServer
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Load_Config();
			//	Server::Console::WriteBlue("[MadRealtime started]");
		}
	}


	namespace CPlayer
	{
		void __fastcall ChatCommand(void *thispointer,  void *_edx, char *comm)
		{
			Player player(thispointer);
			Command command(comm);

			if(player.isGM())
			{
				if (command.beginWith("/reloadrealtime"))
				{
					Load_Config();
					Server::Console::WriteBlue("[MadRealtime config reloaded]");
				}
			}
			Server::CPlayer::ChatCommand(thispointer,comm);
		}
	}


	namespace CItemGeneral
	{
		void __fastcall Enchant(void *Talipointer, void* _edx, void *Playerpointer, void *ItemPointer)
		{
			Item *tali = new Item(Talipointer);
			Item *item = new Item(ItemPointer);
			bool found = false;
			Server::Console::WriteBlue("Enchant!");
			for (unsigned int i=0; i < mix_realtimes.size(); i++) 
			{
				if (mix_realtimes[i].index == tali->GetIndex())
				{
					found = true;
					void* MixedItem = Server::CItem::CreateItem( item->GetIndex()  , 0, 1, -1);
					Server::CIOObject::AddRef(MixedItem);
					Server::Console::WriteBlue("Enchantx!");
					Item *mixed_item = new Item(MixedItem);
					mixed_item->CopyProperties(item);
					mixed_item->SetState(mix_realtimes[i].info);
					Server::CPlayer::InsertItem(Playerpointer,3,MixedItem);
					Server::CBase::Delete(MixedItem);
					Server::CIOObject::Release(MixedItem);
					delete mixed_item;
				}
			}

			if (found)
			{

				Server::CItemGeneral::UpdateNum(ItemPointer,Playerpointer,50,-1);
				Server::CItemGeneral::UpdateNum(Talipointer,Playerpointer,50,-1);
				//Server::Console::WriteBlue("Send Delete");
			
				// Von Striker Update ITEM val = 92
				//	Server::CItem::SendItemInfo(this->offset,(int*)player,val);
			}
			else
			{
				Server::CItemGeneral::Enchant(Talipointer,Playerpointer,ItemPointer);
			}

			delete tali,item;
			/**
			if (tali->IsMixStone())
			{
			void* MixedItem = Server::CItem::CreateItem(item->GetIndex() , 0, 1, -1);
			Item *mixed_item = new Item(MixedItem);
			mixed_item->Mix(tali->GetIndex());

			Server::CIOObject::AddRef(newITem);
			Server::CPlayer::InsertItem(Playerpointer,3,newITem);
			Server::CBase::Delete(newITem);
			Server::CIOObject::Release(newITem);
			}


			//Server::Console::WriteBlue("%d", *(_DWORD *)(*(_DWORD *)( (int)Talipointer + 40) + 64) );

			if ( ((int*)(((int*) Talipointer)[10]))[16]  == 9357 || ((int*)(((int*) Talipointer)[10]))[16]  == 9365)
			{
			//Server::Console::WriteBlue("%d", *(_DWORD *)(*(_DWORD *)( (int)Talipointer + 40) + 64) );
			//	((int*) ItemPointer)[12] = 1048960;

			void* newITem = Server::CItem::CreateItem((int) ((int*)(((int*) ItemPointer)[10]))[16] , 0, 1, -1);

			Server::CIOObject::AddRef(newITem);
			((int*) newITem)[12] = 1048960;

			Server::CPlayer::InsertItem(Playerpointer,3,newITem);
			Server::CBase::Delete(newITem);
			Server::CIOObject::Release(newITem);

			//Server::CPlayer::OutofInven(Playerpointer,ItemPointer);



			}
			//		else 
			//	{
			Server::CItem::CItemGeneral__Enchant(Talipointer,Playerpointer,ItemPointer);
			///	}

			**/
		}
	}


	/**namespace CItemWeapon
	{
	void __fastcall ChangePrefix(void *WeaponPointer,void* _edx,void *Playerptr, int a3, int a4, int a5)
	{

	Item *item = new Item(WeaponPointer);
	for (unsigned int i=0; i < MixItems.size(); i++) 
	{
	//	if (a4 == 236731408)
	//	{

	item->SetState(MixItems[i].info);
	Server::Console::WriteBlue("Done."); 
	//}
	}
	delete item;
	Server::Console::WriteBlue("[Prefix changed]");
	Server::Console::WriteBlue("%d",a3); 
	Server::Console::WriteBlue("%d",a4); //236731408
	Server::Console::WriteBlue("%d",a5); //236731416
	}

	}**/

	/**

	namespace CPlayer
	{
	void __fastcall EnchantItem(void* playerp, void* _edx, signed int Tali_IID,signed int Item_IID)
	{

	int v3;
	int v4;
	void *v5;
	char v6; 
	char v7;
	int v8;
	int v9; 
	int v10; 
	int v11;
	try {
	v5 = playerp;
	if ( Tali_IID != Item_IID )
	{
	Server::CIOCriticalSection::Enter( (void*) ( (DWORD)playerp+1020) );
	Server::Unknown::sub_44AE20( (void *) ( (DWORD)v5 + 1068 ) , (int)&v11, (int)&Tali_IID);
	v3 = (int)Server::Unknown::sub_430C20( (void *) ( (DWORD)v5 + 1068 ) , &v7);
	if ( Server::Unknown::sub_47D070(&v11, v3) )
	{
	v9 = *(_DWORD *)(Server::Unknown::sub_420250(&v11) + 4); // UP to here work

	Server::Unknown::sub_44AE20( (void *) ( (DWORD)v5 + 1068 ) ,(int)&v10, (int)&Item_IID);
	v4 = (int)Server::Unknown::sub_430C20( (void *) ( (DWORD)v5 + 1068 ) , &v6);
	if ( Server::Unknown::sub_47D070(&v10, v4) )
	{
	v8 = *(_DWORD *)(Server::Unknown::sub_420250(&v10) + 4);
	Server::Console::WriteBlue("%lld",*(DWORD *)v9 + 172 );
	//if ( !(*(int (__thiscall **)(int, void *, int))(*(DWORD *)v9 + 172))(v9, v5, v8) )
	//int __thiscall CItemGeneral__Enchant(int this, int a2, int a3)
	//	Server::CPlayer::OutofInven(v9);
	//	if ( (*(int (__thiscall **)(int))(*(DWORD *)v8 + 168))(v8) )
	//bool __thiscall CItemDefense__IsBroken(int this)

	Server::Console::WriteBlue("%lld",*(DWORD *)v8 + 168 );
	//	Server::CPlayer::OutofInven(v8);
	}
	}
	Server::CIOCriticalSection::Leave((void*)((DWORD)playerp+1020));
	} 
	}
	catch (...) 
	{
	}
	}



	Player *player = new Player(playerp);
	//2024377574
	//  *(_DWORD *)(a3 + 36) = CItem__NewIID();

	//CItem ADD STATE ist fucking INFO!!  (+48)

	// CPlayer__FindItem(v12, 657, 1)
	//  CPlayer__RemoveItem(v12, 9, 657, 1) )
	//	Server::CPlayer::FindItem();
	Server::Console::WriteBlue("[Item enchanted by %s Item: %lld Tali: %lld ",player->GetName(),Item_IID,Tali_IID);
	Server::CPlayer::EnchantItem(playerp,Item_IID,Tali_IID);
	//	Server::CPlayer::GameStart(playerp);
	//Server::CPlayer::GameRestart(playerp);

	delete player;
	**/
}


