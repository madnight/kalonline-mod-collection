#include "StdAfx.h"
#include "Process.h"
#include "Interface.h"
#include "Server.h"
#include "Hooks.h"
#include "Tools.h"

CREATE_INTERFACE(IProcess)

void IProcess::Hook()
{
    Interface<ITools> Tools;
    this->MaxCharCount = 4;
    char thief = 4;
    Tools->MemcpyExD((void*)0x0041adf9, &MaxCharCount, 1);
    Tools->MemcpyExD((void*)0x00416ed4, &MaxCharCount, 1);
    Tools->MemcpyExD((void*)0x00416e89, &thief, 1);
    Tools->Intercept(ITools::I_CALL, (void*)0x004118c9, Hooks::CSocket::Login, 5);
}

void IProcess::Login(void *Socket, int nId, int nUID)
{
    char *end;

    char delName[17];
    DWORD delPID;
    unsigned __int8 delLevel;
    unsigned __int8 delClass;
    void *delPacket;
    unsigned __int8 delDayLeft;

    DWORD PID;
    char Name[17];
    unsigned char Class;
    unsigned char Specialty;
    unsigned char Level;
    DWORD GID;
    unsigned short Strength;
    unsigned short Health;
    unsigned short Intelligence;
    unsigned short Wisdom;
    unsigned short Dexterity;
    unsigned char Face;
    unsigned char Hair;


    char *pBuffer = (char*)Server::CIOBuffer::Alloc();
    char *dbPacket = pBuffer;
    *((unsigned char*)pBuffer + 2) = 0;
    end = (char *)dbPacket + 10;

    Server::_CDB db;
    Server::CDB::CDB(&db);
    Server::CDB::Bind_Dword(&db, &PID);
    Server::CDB::Bind_String(&db, Name, 17);
    Server::CDB::Bind_Byte(&db, &Class);
    Server::CDB::Bind_Byte(&db, &Specialty);
    Server::CDB::Bind_Byte(&db, &Level);
    Server::CDB::Bind_Dword(&db, &GID);
    Server::CDB::Bind_Word(&db, &Strength);
    Server::CDB::Bind_Word(&db, &Health);
    Server::CDB::Bind_Word(&db, &Intelligence);
    Server::CDB::Bind_Word(&db, &Wisdom);
    Server::CDB::Bind_Word(&db, &Dexterity);
    Server::CDB::Bind_Byte(&db, &Face);
    Server::CDB::Bind_Byte(&db, &Hair);

    int nCount = 0;
    Server::CDB::Prepare("SELECT TOP %d [PID], [Name], [Class], [Specialty], [Level], "
            "[GID], [Strength], [Health], [Intelligence], [Wisdom], [Dexterity], [Face], "
            "[Hair] FROM Player WHERE UID = %d ORDER BY [Level]", this->MaxCharCount, nUID);

    if (Server::CDB::Execute(&db, "SELECT TOP %d [PID], [Name], [Class], [Specialty], "
                "[Level], [GID], [Strength], [Health], [Intelligence], [Wisdom], [Dexterity], "
                "[Face], [Hair] FROM Player WHERE UID = %d ORDER BY [Level]", this->MaxCharCount, nUID))
    {
        char *d;
        while (Server::CDB::Fetch(&db))
        {
            end = Server::PutDword(end, PID);
            end = Server::PutString(end, Name);
            end = Server::PutByte(end, Class);
            end = Server::PutByte(end, Specialty);
            end = Server::PutByte(end, Level);
            end = Server::PutDword(end, GID);
            end = Server::PutWord(end, Strength);
            end = Server::PutWord(end, Health);
            end = Server::PutWord(end, Intelligence);
            end = Server::PutWord(end, Wisdom);
            end = Server::PutWord(end, Dexterity);
            end = Server::PutByte(end, Face);
            d = Server::PutByte(end, Hair);
            end = d + 1;
            *d = 0;

            Server::_CDB dbItem;
            unsigned __int16 wIndex;
            Server::CDB::CDB(&dbItem);
            Server::CDB::Bind_Word(&dbItem, &wIndex);
            Server::CDB::Prepare("SELECT TOP 13 [Index] FROM Item WHERE [PID] = %d AND "
                    "( [Info] & %d) = %d", PID, 17, 1);
            if (Server::CDB::Execute(&dbItem, "SELECT TOP 13 [Index] FROM Item WHERE "
                        "[PID] = %d AND ( [Info] & %d) = %d", PID, 17, 1))
            {
                while (Server::CDB::Fetch(&dbItem))
                {
                    end = Server::PutWord(end, wIndex);
                    ++*d;
                }
            }
            Server::CDB::_CDB(&dbItem);
            nCount++;
        }
    }

    *(WORD *)dbPacket = (WORD)end - (WORD)dbPacket;
    *((DWORD *)pBuffer + 2000) = *(WORD *)dbPacket;
    Server::WritePacket(dbPacket + 3, "dbw", nId, nCount, (unsigned short)(end - dbPacket -10));
    Server::CIOSocket::Write(Socket, pBuffer);
    Server::CDB::_CDB(&db);

    char *delBuffer = (char*)Server::CIOBuffer::Alloc();
    delPacket = delBuffer;
    *((unsigned char *)delBuffer + 2) = 29;
    end = (char *)delPacket + 10;

    int delCount = 0;
    Server::_CDB dbDel;
    Server::CDB::CDB(&dbDel);
    Server::CDB::Bind_Dword(&dbDel, &delPID);
    Server::CDB::Bind_String(&dbDel, delName, 17);
    Server::CDB::Bind_Byte(&dbDel, &delLevel);
    Server::CDB::Bind_Byte(&dbDel, &delClass);
    Server::CDB::Bind_Byte(&dbDel, &delDayLeft);
    Server::CDB::Prepare("SELECT TOP 5 PlayerDeleted.PID, Name, [Level], Class, "
            "DayLeft = 14-datediff(dd, DeletedTime, getdate()) FROM PlayerDeleted, "
            "Player WHERE PlayerDeleted.UID = %d AND PlayerDeleted.PID= Player.PID "
            "ORDER BY DayLeft DESC", nUID);

    if (Server::CDB::Execute(&dbDel, "SELECT TOP 5 PlayerDeleted.PID, Name, [Level], "
                "Class, DayLeft = 14-datediff(dd, DeletedTime, getdate()) FROM PlayerDeleted, "
                "Player WHERE PlayerDeleted.UID = %d AND PlayerDeleted.PID= Player.PID"
                " ORDER BY DayLeft DESC", nUID))
    {
        while (Server::CDB::Fetch(&dbDel) && delCount <= 5)
        {
            end = Server::PutDword(end, delPID);
            end = Server::PutString(end, delName);
            end = Server::PutByte(end, delLevel);
            end = Server::PutByte(end, delClass);
            end = Server::PutByte(end, delDayLeft);
            delCount++;
        }
    }
    Server::CDB::_CDB(&dbDel);

    *(unsigned short *)delPacket = (unsigned short)end - (unsigned short)delPacket;
    *((unsigned long *)delBuffer + 2000) = *(unsigned short *)delPacket;

    Server::WritePacket((char *)delPacket + 3, "dbw", nId, delCount, end - ((char *)delPacket + 10));
    Server::CIOSocket::Write(Socket, delBuffer);
}
