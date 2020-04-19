#include "StdAfx.h"
#include "FriendList.h"
#include "Interface.h"
#include "Server.h"
#include "Tools.h"

void __fastcall Mods::FriendList::SendList(void *pSocket, void *_edx, char* Packet)
{
	Interface<ITools> Tools;
	Packet+=3;
	char nType = Packet[0];
	unsigned char fCount = Packet[1];
	Packet+=2;
	char *offset = Packet;;

	size_t nSize = 0;
	for(unsigned char i=0; i < fCount; i++)
	{
		char* name;
		long id;
		offset = Tools->ParseData(offset, "ds", &id, &name);
		nSize += 4 + strlen(name)+1 +1 +4 +1;
	}

	char *nPacket = new char[nSize];
	offset = nPacket;
	
	for(unsigned char i=0; i < fCount; i++)
	{
		char* name;
		long id;
		Packet = Tools->ParseData(Packet, "ds", &id, &name);

		long *pFriend = (long*)Server::CPlayer::FindPlayer(name);
		offset = Tools->Compile(offset, "dsbdb", id, name, pFriend ? true : false, pFriend ? pFriend[0x1c] : 0, 0);
	}
	
	Server::CSocket::Write(pSocket, 0x12, "bbm", 2, fCount, nPacket, nSize);
	delete[] nPacket;
}

void __cdecl Mods::FriendList::SendAdd(void *vPlayer, unsigned char pType, char* pFormat, char fType, long id, char* name, char type)
{
	long *pFriend = (long*)Server::CPlayer::FindPlayer(name);
	Server::CPlayer::Write(vPlayer, 0x12, "bdsbdb", 0, id, name, pFriend ? true : false, pFriend ? pFriend[0x1c] : 0, 0);
}