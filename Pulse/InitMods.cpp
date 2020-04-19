#include "StdAfx.h"
#include "InitMods.h"
#include "Interface.h"
#include "Memory.h"
#include "Packets.h"
#include "Player.h"
#include "Inventory.h"
#include "Monster.h"
#include "NPC.h"
#include "FriendList.h"
#include "Item.h"
#include "Server.h"

void Mods::Initialize()
{
	Interface<IMemory> Memory;

	// Basic fixes
	Memory->Fill(0x0049463d, IMemory::_I_NOP, 23);							// Recv Crypt disable
	Memory->Fill(0x0049488e, IMemory::_I_NOP, 32);							// Send Crypt disable

	Memory->Set(0x004B5C68, "thief", 6);									// Thief config reading fix
	Memory->Fill(0x00494e76, IMemory::_I_JMP_SHORT, 1);						// Version bypass

	Memory->Fill(0x0044da11, 8, 1);											// 8 party fix

	// Stats fixes
	Memory->Set(0x004babe0, "bsbwwwwwwddwwwwwbIwwwwwwbbbbbd", 31);

	void *p = &Mods::Player::g_BaseStats;					// Base stats fix (for thief)
	Memory->Set(0x0046353e, (char*)&p, 4);
	Memory->Set(0x004652e1, (char*)&p, 4);

	// Thief resistance fix
	p = &Mods::Player::g_FinalResistDivider;
	Memory->Set(0x00452056, (char*)&p, 4);

	// S2C_CODE packet fix
	Memory->Hook(0x00494dc1, Mods::Packets::WriteCode);

	// Player appear fixes
	Memory->Hook(0x00458358, Mods::Player::SendCreate);
	Memory->Hook(0x004514a1, Mods::Player::SendCreate);

	Memory->Hook(0x00458412, Mods::Player::SendExclusiveCreate);
	Memory->Set(0x0045840b, "\xff\x75\xf8\x90\x90", 5);
	Memory->Hook(0x0045d088, Mods::Player::SendExclusiveCreate);
	Memory->Set(0x0045d081, "\xff\x75\xf4\x90\x90", 5);
	Memory->Hook(0x004918eb, Mods::Player::SendExclusiveCreate);
	Memory->Set(0x004918e4, "\xff\x75\x08\x90\x90", 5);

	// mState fixes
	Memory->Hook(0x00451dc8, Mods::Player::SendMState);
	Memory->Hook(0x00451e98, Mods::Player::SendMState);

	// gState fixes
	Memory->Hook(0x0044190f, Mods::Player::SendGStateInSight);
	Memory->Hook(0x0044924f, Mods::Player::SendGStateInSight);
	Memory->Hook(0x0045cf4e, Mods::Player::SendGState);
	Memory->Hook(0x0046064d, Mods::Player::SendGState);
	Memory->Hook(0x00460694, Mods::Player::SendGState);
	Memory->Hook(0x00460800, Mods::Player::SendGState);
	Memory->Hook(0x00460a36, Mods::Player::SendGState);

	// Monster appear fixes
	Memory->Hook(0x0043a577, Mods::Monster::SendCreate);		// CMonster::SendCreate
	Memory->Hook(0x0043ab6f, Mods::Monster::SendCreate);		// CMonsterReal::SendCreate
	Memory->Hook(0x0044150e, Mods::Monster::SendCreateInSight);	// CMonsterGuildWar::Create
	Memory->Hook(0x0043a1de, Mods::Monster::SendCreateInSight);	// CMonster::Create
	Memory->Hook(0x004403e9, Mods::Monster::SendCreateInSight);	// CMonsterTowerBoss::Create
	Memory->Hook(0x004928F2, Mods::Monster::WriteExclusive);	// CMonsterGuildWar::Create
	Memory->Hook(0x00442011, Mods::Monster::SendCreateInSight);	// CMonsterMagic::Create
	Memory->Hook(0x00442dd7, Mods::Monster::SendCreateInSight);	// CMonsterMaguniMaster::Create
	Memory->Hook(0x0044332a, Mods::Monster::SendCreateInSight);	// CMonsterBigBirdMother::Create
	Memory->Hook(0x00444275, Mods::Monster::SendCreateInSight);	// CMonsterBigBirdMaster::Create
	Memory->Hook(0x004449f7, Mods::Monster::SendCreateInSight);	// CMonsterSiegeGun::Create
	Memory->Hook(0x0044528a, Mods::Monster::SendCreateInSight);	// CMonsterSiegeGunBall::Create

	// NPC appear fixes
	Memory->Hook(0x00449211, Mods::NPC::SendCreate);			//CNPC::SendCreate
	Memory->Hook(0x0044AD19, Mods::NPC::SendCreate);			//CNPCSiegeGunStone::SendCreate
	Memory->Hook(0x0044957A, Mods::NPC::SendCreateInSight);		//CNPC::Show
	Memory->Hook(0x0044AC56, Mods::NPC::SendCreateInSight);		//CNPC::Show

	// Item
	Memory->Hook(0x004269B8, Mods::Item::ItemDrop);
	Memory->Hook(0x00426FD1, Mods::Item::PrepItemDrop);
	Memory->Hook(0x0042DEFE, Mods::Item::PrepItemDrop);

	// Skill fix
	Memory->Hook(0x004570a8, Mods::Packets::WriteSkills);

	// FriendList fixes
	Memory->Hook(0x00467fd5, Mods::FriendList::SendList);
	Memory->Hook(0x00467c26, Mods::FriendList::SendAdd);

	// Assassin list fix
	Memory->Hook(0x0046b50f, Mods::NPC::SendAssassinList);
}