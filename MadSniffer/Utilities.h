#include <windows.h>
#include <ctime>
#include <cstdio>

char* time_stamp()
{
	time_t t = time(0);   
	struct tm * now = localtime(&t);
	char *timestamp;
	sprintf(timestamp,"%04d/%02d/%02d %02d:%02d:%02d", now->tm_year+1900, now->tm_mon, 
		now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
	return timestamp;
}

char* Header(char* Data)
{
	char Type = Data[2];
	switch(Type)
	{
	case 0x00: return "RestoreChar";
	case 0x01: return "AntiCp";
	case 0x02: return "AccountLogin";
	case 0x03: return "HackShield+engine.exeCRCcheck";
	case 0x04: return "CreateChar";
	case 0x05: return "Ping";
	case 0x06: return "DuplicateCharIsValidAdminNamecheck";
	case 0x07: return "DeleteChar";
	case 0x08: return "RandomConnectInfo";
	case 0x09: return "VersionCheck";
	case 0x0A: return "CSocket::LoadPlayer(GameLogin)";
	case 0x0b: return "CPlayer::GameStart";
	case 0x0c: return "(SYSTEM_GUILDWAR_SIEGEGUN)";
	case 0x0d: return "(SYSTEM_GUILDWAR_SIEGEGUN)";
	case 0x0e: return "(SYSTEM_GUILDWAR_SIEGEGUN)";
	case 0x0f: return "CPlayer::Attack";
	case 0x10: return "CPlayerSkill::ExcuteSkill";
	case 0x11: return "CPlayer::ProcessMsg(chat)";
	case 0x12: return "CPlayer::OnTeleport";
	case 0x13: return "CPlayer::Write (selectchar)";
	case 0x14: return "CSMap::MovePlayer";
	case 0x15: return "CSMap::MovePlayerandstop";
	case 0x16: return "CNPC:: reply";
	case 0x17: return "CCastle::GetCastle(getnpctax)";
	case 0x18: return "CPlayer::BuyItemEx";
	case 0x19: return "CPlayer::SellItem/";
	case 0x1a: return "CPlayer::DropItem";
	case 0x1b: return "CPlayer::Write0x5D(quitgame)";
	case 0x1c: return "CPlayer::ShowOffItem)";
	case 0x1d: return "CChar::WriteInSight";
	case 0x1e: return "CPlayer::GetNeedPoint(setstatpoint)";
	case 0x1f: return "CPlayer:: restGState";
	case 0x20: return "CSMap::PickUpItem";
	case 0x21: return "CPlayer::UseItem";
	case 0x22: return "CPlayer::AskTrade";
	case 0x23: return "CPlayer::OnAskTrade";
	case 0x24: return "CPlayer::CancelTrade";
	case 0x25: return "GameServ.CPlayer:: revival";
	case 0x26: return "CPlayer::SiegeGunProcess(FALSE)";
	case 0x27: return "CPlayer::SiegeGunProcess(TRUE)";
	case 0x28: return "CPlayer::SiegeGunControl";
	case 0x29: return "CPlayerSkill::LearnSkill";
	case 0x2a: return "CPlayerSkill::SkillUp";
	case 0x2b: return "CPlayerSkill::PreSkill";
	case 0x2c: return "CPlayer::AskParty";
	case 0x2d: return "CPlayer::OnAskParty";
	case 0x2e: return "CGuild";
	case 0x2f: return "CPlayer::LeaveParty";
	case 0x30: return "CPlayer::ExileParty";
	case 0x31: return "CPlayer::PutInStorage";
	case 0x32: return "CPlayer::PutOutStorage";
	case 0x33: return "CQuest::CallProcess";
	case 0x34: return "CPlayer::StorageInfo";
	case 0x35: return "Unkown Packet";
	case 0x36: return "CAuthSocket::Write";
	case 0x37: return "InvalidpackettypeatCPlayer::Process()";
	case 0x38: return "CPlayer::SaveRevivalPt";
	case 0x39: return "CPlayer::EnchantItem";
	case 0x3a: return "CPlayer::SetStallInfo";
	case 0x3b: return "CPlayer::removeItemuseStoneOfJob";
	case 0x3c: return "CPlayer::removeItemuseHighGradeSo";
	case 0x3d: return "CChar::WriteInSightpacket";
	case 0x3e: return "CPlayer::TradeAgreed";
	case 0x3f: return "CPlayer::TrashItem(destroy)";
	case 0x40: return "CPlayer::FRDProcess";
	case 0x41: return "CPlayer::PutOnItem";
	case 0x42: return "CPlayer::PutOffItem";
	case 0x43: return "CPlayer::SwitchStall";
	case 0x44: return "CPlayer::ProcessEvent";
	case 0x45: return "removeGState";
	case 0x46: return "CPlayer::GetStallInfo";
	case 0x47: return "CPlayer::BuyItemAtStall";
	case 0x48: return "CPlayer::EventSetMoraif";
	case 0x49: return "CPlayer::IsCookingGState0x40";
	case 0x4a: return "CPlayer:: revivalSkill(AcceptMageRevive)";
	case 0x4b: return "CPlayerSkill::redistribute-> CPlayer:: removeItem(useStoneOfChance)";
	case 0x4c: return "CPlayer::ExchangeBoddariToItem";
	case 0x4d: return "CPlayer::ExchangeDanjiToItem";
	case 0x4e: return "CPlayer::InitStatuseStoneofBirth";
	case 0x4f: return "CPlayer::PKBulletinInfoSend(GetAssaList)";
	case 0x50: return "CPlayer::AskPvP";
	case 0x51: return "CPlayer::OnAskPvP";
	case 0x52: return "CPlayer::Transform";
	case 0x53: return "CPlayer::Bless";
	case 0x54: return "CPlayerSkill::ExcuteTransformSkill";
	case 0x55: return "CPlayer::MLMProcessTeacher/Student";
	case 0x56: return "InvalidpackettypeatCPlayer::Process()";
	case 0x57: return "InvalidpackettypeatCPlayer::Process()";
	case 0x58: return "addGState0x800";
	case 0x59: return "CPlayer::Shortcut(skillbar)";
	case 0x5a: return "CPlayer::SetMyTelPt(usesaving/movingscroll)";
	case 0x5b: return "CPlayer::UpgradeItem(0,id->makerevs|1,id->increase%|2,id->upgrade)";
	case 0x5c: return "CPlayer::MAILProcess(messagesystem)";
	case 0x5d: return "CMonster::FindMonsterasUNIT";
	case 0x5e: return "CMonster::FindMonsterasUNIT";
	case 0x5f: return "CPlayer::ChangeGuildName(GuildNameChangeScroll)";
	case 0x60: return "CPlayer::ChangePlayerName(NameChangeScroll)";
	case 0x61: return "CPlayer::NPCProcess(gotofishisle/D4door(asnpc)openoO?)";
	case 0x62: return "CPlayer::EnforceItemlvl1|CPlayer::MixItem|CPlayer::EnforceItemlvl2";
	default:
		return "Unknown Packet";
	}
	return 0;
}


char* ParseData(char* Data, char* Format, ...)
{
	va_list vArgs;
	va_start(vArgs, Format);
	for(unsigned int i=0; i < strlen(Format); i++)
	{
		switch (Format[i])
		{
		case 'b':
			*va_arg(vArgs, unsigned char*) = *(unsigned char*)Data;
			Data += sizeof(unsigned char);
			break;
		case 'w':
			*va_arg(vArgs, unsigned short*) = *(unsigned short*)Data;
			Data += sizeof(unsigned short);
			break;
		case 'd':
			*va_arg(vArgs, unsigned long*) = *(unsigned long*)Data;
			Data += sizeof(unsigned long);
			break;
		case 'f':
			*va_arg(vArgs, float*) = *(float*)Data;
			Data += sizeof(float);
			break;
		case 'D':
			*va_arg(vArgs, double*) = *(double*)Data;
			Data += sizeof(double);
			break;
		case 'I':
			*va_arg(vArgs, __int64*) = *(__int64*)Data;
			Data += sizeof(__int64);
			break;
		case 's':
			*va_arg(vArgs, char**) = Data;
			Data += strlen(Data) +1;
			break;
		case 'm':
			*va_arg(vArgs, unsigned char**) = (unsigned char*)Data;
			Data += va_arg(vArgs, unsigned long);
			break;
		case '?':
			Data += va_arg(vArgs, unsigned long);
			break;
		}
	}
	va_end(vArgs);
	return Data;
}

