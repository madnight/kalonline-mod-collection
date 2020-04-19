#include "StdAfx.h"
#include "Packets.h"
#include "Interface.h"
#include "Deflector.h"
#include "Deflection.h"
#include "Tools.h"
#include "Server.h"

CREATE_INTERFACE(Packets)

Packets::Packets()
{
}

Packets::~Packets()
{
}

void __cdecl Mods::Packets::WriteCode(void *Socket, char Type, char* format,
        long ProtocolVersion, char Code, long TimeStamp, long TimeStart,
        long System, unsigned long Event, char ServerID, char Age, char Country)
{
    Server::CSocket::Write(Socket, 0x2a, "dbdddIbbb", ProtocolVersion, Code,
            TimeStamp, TimeStart, System, (unsigned __int64)Event, ServerID,
            Age, Country);
}

void __cdecl Mods::Packets::WriteSkills(void *Player, char Type, char* format,
        char* skills, size_t size)
{
    Interface<ITools> Tools;
    unsigned char Skills = skills[0];
    skills++;
    char *Array = new char[Skills*6];

    for(unsigned char i=0; i < Skills; i++)
    {
        char id, grade;
        skills = Tools->ParseData(skills, "bb", &id, &grade);
        if (id == 87) id = 85;
        else if (id == 88) id = 86;
        else if (id == 89) id = 87;
        else if (id == 79) id = 89;
        else if (id == 95) id = 88;
        Tools->Compile(Array +i*6, "bbd", id, grade, 0);
    }

    Server::CPlayer::Write(Player, 0x10, "bm", Skills, Array, Skills*6);
    delete[] Array;
}
