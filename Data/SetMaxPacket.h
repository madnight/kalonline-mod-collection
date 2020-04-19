void __cdecl QuestFix(int DB, const char *Statement, int PID, int QuestID, int Flag, int Clear)
{
    Execute((void*)DB, "INSERT INTO Quest VALUES (%d, %d, %d, %d, %d, %d, %d)",
            PID, QuestID, Flag, Clear, 0, 0, 0);
}

int __cdecl MaxInventorySize(void *DB, const char *Query, signed int Size, int PID, signed int Info)
{
    DWORD Type;
    xCDB dbItem;
    CDB(&dbItem);
    BindDword(&dbItem, &Type);

    if (Execute((SQLHSTMT*)&dbItem, "SELECT [Type] FROM BuffRemain WHERE [PID] = %d", PID))
    {
        while (Fetch(&dbItem))
        {
            if (Type == 172 || Type == 173 || Type == 174)
                Size += 36;
        }
    }

    FreeCDB(&dbItem);
    return Execute(DB,Query,Size,PID,Info);
}

void SetMaxPacket()
{
    Interface<IMemory> Memory;
    int NewPacket = 93;
    Memory->Copy((void*)0x00410DD5, &NewPacket, 1);
    Memory->Hook(0x00414646, QuestFix, 0xe8, 5);
    Memory->Hook(0x004132AD, MaxInventorySize, 0xe8, 5);
}
