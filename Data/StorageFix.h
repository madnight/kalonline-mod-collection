int __stdcall StorageFix(int IID, int Argument, int PID, int Value, int Num)
{
    xCDB dbItem;
    CDB(&dbItem);

    if ( Value )
    {
        if ( Value == 1 )
            Execute((SQLHSTMT*)&dbItem, "UPDATE Item SET [Num] = [Num] + %d "
                    "WHERE [IID] = %d", Num, IID);
    } else {
        Execute((SQLHSTMT*)&dbItem,"UPDATE Item SET [PID] = %d, [Info] = [Info] + 16 "
                "WHERE [IID] = %d",PID,IID);
    }

    Logging(5, 15, Argument, PID, IID, 0, 0, Num, Value);
    return FreeCDB(&dbItem);
}
