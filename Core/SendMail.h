void __fastcall MAILProcess(void *Player, void *edx, int Type, int pPacket,
                            int pPos)
{
    IChar IPlayer(Player);

    if (IPlayer.IsOnline() && Type == 7 && !IPlayer.IsBuff(343))
    {
        IPlayer.Buff(343,1,0);
        Interface<ITools> Tools;
        char Packet[63] = {0};
        int Check, nMID=0, nIID=0;
        char byMType=0;
        unsigned __int16 wLen = 0;
        char Msg[512] = {0};
        Check = CPacket::xRead((void *)pPacket, "dbdw", &nMID, &byMType, &nIID, &wLen);
        Check = CPacket::xRead((void *)Check, "m", &Msg, wLen);
        int Index = 0, Prefix = 0, MaxEnd = 0, CurEnd = 0, Info = 0, Num = 0, XHit = 0,
            XDefense = 0, XAttack = 0, XMagic = 0, XDodge = 0, Protect = 0, UpgrLevel = 0,
            SetGem = 0, ItemStat = 0;
        RETCODE rc;
        HENV henv;
        HDBC hdbc;
        HSTMT hstmt;
        SDWORD cbData;
        const char *db = ConfigCheckDB2;
        SQLAllocEnv(&henv);
        SQLAllocConnect(henv, &hdbc);
        rc = SQLConnect(hdbc, (unsigned char*)db, SQL_NTS, 0, 0, 0, 0);

        if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO))
        {
            SQLFreeConnect(hdbc);
            SQLFreeEnv(henv);
            return;
        }

        rc = SQLAllocStmt(hdbc, &hstmt);
        std::stringstream query;
        query << "SELECT [Index],[MaxEnd],[CurEnd],[Info],[Num],[XHit],[XDefense]," <<
            "[XAttack],[XMagic],[XDodge],[Protect],[UpgrLevel],[SetGem],[Prefix]," <<
            "[ItemStat] FROM [Item] WHERE [IID] = '" << nIID << "'";
        std::string runquery = query.str();
        const char *sql =  runquery.c_str();
        rc = SQLExecDirect(hstmt, (unsigned char*)sql, SQL_NTS);
        if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO))
        {
            SQLFreeStmt(hstmt, SQL_DROP);
            SQLDisconnect(hdbc);
            SQLFreeConnect(hdbc);
            SQLFreeEnv(henv);
            return;
        } else {
            for (rc = SQLFetch(hstmt); rc == SQL_SUCCESS; rc = SQLFetch(hstmt))
            {
                SQLGetData(hstmt, 1, SQL_INTEGER, &Index, sizeof(int), &cbData);
                SQLGetData(hstmt, 2, SQL_INTEGER, &MaxEnd, sizeof(int), &cbData);
                SQLGetData(hstmt, 3, SQL_INTEGER, &CurEnd, sizeof(int), &cbData);
                SQLGetData(hstmt, 4, SQL_INTEGER, &Info, sizeof(int), &cbData);
                SQLGetData(hstmt, 5, SQL_INTEGER, &Num, sizeof(int), &cbData);
                SQLGetData(hstmt, 6, SQL_INTEGER, &XHit, sizeof(int), &cbData);
                SQLGetData(hstmt, 7, SQL_INTEGER, &XDefense, sizeof(int), &cbData);
                SQLGetData(hstmt, 8, SQL_INTEGER, &XAttack, sizeof(int), &cbData);
                SQLGetData(hstmt, 9, SQL_INTEGER, &XMagic, sizeof(int), &cbData);
                SQLGetData(hstmt, 10, SQL_INTEGER, &XDodge, sizeof(int), &cbData);
                SQLGetData(hstmt, 11, SQL_INTEGER, &Protect, sizeof(int), &cbData);
                SQLGetData(hstmt, 12, SQL_INTEGER, &UpgrLevel, sizeof(int), &cbData);
                SQLGetData(hstmt, 13, SQL_INTEGER, &SetGem, sizeof(int), &cbData);
                SQLGetData(hstmt, 14, SQL_INTEGER, &Prefix, sizeof(int), &cbData);
                SQLGetData(hstmt, 15, SQL_INTEGER, &ItemStat, sizeof(int), &cbData);
            }
        }

        SQLFreeStmt(hstmt, SQL_DROP);
        SQLDisconnect(hdbc);
        SQLFreeConnect(hdbc);
        SQLFreeEnv(henv);
        unsigned char x=0,y=0,z=0,dsstype=0,eva=0,otp=0,hpinc=0,mpinc=0,str=0,hp=0,
                      intel=0,wis=0,agi=0,a=0,dg1stat=0,dg1type=0,dg2stat=0,dg2type=0,PerfShotCheck=0;
        unsigned long remaintime=0,QigongGrade=0;
        unsigned short phyatk=0,magatk=0,def=0,absorb=0;
        if (ItemStat) GetItemStat[nIID] = ItemStat;

        if (Index > 0)
        {
            int MakeItem = CItem::CreateItem(Index, 0, 1, -1);

            if (MakeItem)
            {
                IItem IItem((void*)MakeItem);

                if (IItem.GetType() == -2 || IItem.GetType() == 19 || IItem.GetType() == 0
                        || IItem.GetType() == -3 || IItem.GetType() == -1)
                {
                    if (SetGem == 240)
                    {
                        dsstype = 1;
                        phyatk = 17;
                        magatk = 17;
                        agi = 8;
                        hpinc = 250;
                        mpinc = 200;
                        if (IItem.GetType() == -1) eva = 18;
                        else otp = 18;
                    } else if (SetGem == 239)
                    {
                        dsstype = 1;
                        phyatk = 17;
                        magatk = 17;
                        wis = 8;
                        hpinc = 250;
                        mpinc = 200;
                        if (IItem.GetType() == -1) eva = 18;
                        else otp = 18;
                    } else if (SetGem == 238)
                    {
                        dsstype = 1;
                        phyatk = 17;
                        magatk = 17;
                        intel = 8;
                        hpinc = 250;
                        mpinc = 200;
                        if (IItem.GetType() == -1) eva = 18;
                        else otp = 18;
                    } else if (SetGem == 237)
                    {
                        dsstype = 1;
                        phyatk = 17;
                        magatk = 17;
                        hp = 8;
                        hpinc = 250;
                        mpinc = 200;
                        if (IItem.GetType() == -1) eva = 18;
                        else otp = 18;
                    } else if (SetGem == 236)
                    {
                        dsstype = 1;
                        phyatk = 17;
                        magatk = 17;
                        str = 8;
                        hpinc = 250;
                        mpinc = 200;
                        if (IItem.GetType() == -1) eva = 18;
                        else otp = 18;
                    } else if (SetGem == 235)
                    {
                        dsstype = 2;
                        phyatk = 14;
                        magatk = 14;
                        agi = 5;
                        hpinc = 200;
                        mpinc = 150;
                        if (IItem.GetType() == -1) eva = 15;
                        else otp = 15;
                    } else if (SetGem == 234)
                    {
                        dsstype = 2;
                        phyatk = 14;
                        magatk = 14;
                        wis = 5;
                        hpinc = 200;
                        mpinc = 150;
                        if (IItem.GetType() == -1) eva = 15;
                        else otp = 15;
                    } else if (SetGem == 233)
                    {
                        dsstype = 2;
                        phyatk = 14;
                        magatk = 14;
                        intel = 5;
                        hpinc = 200;
                        mpinc = 150;
                        if (IItem.GetType() == -1) eva = 15;
                        else otp = 15;
                    } else if (SetGem == 232)
                    {
                        dsstype = 2;
                        phyatk = 14;
                        magatk = 14;
                        hp = 5;
                        hpinc = 200;
                        mpinc = 150;
                        if (IItem.GetType() == -1) eva = 15;
                        else otp = 15;
                    } else if (SetGem == 231)
                    {
                        dsstype = 2;
                        phyatk = 14;
                        magatk = 14;
                        str = 5;
                        hpinc = 200;
                        mpinc = 150;
                        if (IItem.GetType() == -1) eva = 15;
                        else otp = 15;
                    } else if (SetGem == 230)
                    {
                        dsstype = 3;
                        phyatk = 12;
                        magatk = 12;
                        agi = 3;
                        hpinc = 130;
                        mpinc = 110;
                        if (IItem.GetType() == -1) eva = 12;
                        else otp = 12;
                    } else if (SetGem == 229)
                    {
                        dsstype = 3;
                        phyatk = 12;
                        magatk = 12;
                        wis = 3;
                        hpinc = 130;
                        mpinc = 110;
                        if (IItem.GetType() == -1) eva = 12;
                        else otp = 12;
                    } else if (SetGem == 228)
                    {
                        dsstype = 3;
                        phyatk = 12;
                        magatk = 12;
                        intel = 3;
                        hpinc = 130;
                        mpinc = 110;
                        if (IItem.GetType() == -1) eva = 12;
                        else otp = 12;
                    } else if (SetGem == 227)
                    {
                        dsstype = 3;
                        phyatk = 12;
                        magatk = 12;
                        hp = 3;
                        hpinc = 130;
                        mpinc = 110;
                        if (IItem.GetType() == -1) eva = 12;
                        else otp = 12;
                    } else if (SetGem == 226)
                    {
                        dsstype = 3;
                        phyatk = 12;
                        magatk = 12;
                        str = 3;
                        hpinc = 130;
                        mpinc = 110;
                        if (IItem.GetType() == -1) eva = 12;
                        else otp = 12;
                    } else if (SetGem == 225)
                    {
                        dsstype = 4;
                        phyatk = 10;
                        magatk = 10;
                        agi = 3;
                        hpinc = 110;
                        mpinc = 90;
                        if (IItem.GetType() == -1) eva = 10;
                        else otp = 10;
                    } else if (SetGem == 224)
                    {
                        dsstype = 4;
                        phyatk = 10;
                        magatk = 10;
                        wis = 3;
                        hpinc = 110;
                        mpinc = 90;
                        if (IItem.GetType() == -1) eva = 10;
                        else otp = 10;
                    } else if (SetGem == 223)
                    {
                        dsstype = 4;
                        phyatk = 10;
                        magatk = 10;
                        intel = 3;
                        hpinc = 110;
                        mpinc = 90;
                        if (IItem.GetType() == -1) eva = 10;
                        else otp = 10;
                    } else if (SetGem == 222)
                    {
                        dsstype = 4;
                        phyatk = 10;
                        magatk = 10;
                        hp = 3;
                        hpinc = 110;
                        mpinc = 90;
                        if (IItem.GetType() == -1) eva = 10;
                        else otp = 10;
                    } else if (SetGem == 221)
                    {
                        dsstype = 4;
                        phyatk = 10;
                        magatk = 10;
                        str = 3;
                        hpinc = 110;
                        mpinc = 90;
                        if (IItem.GetType() == -1) eva = 10;
                        else otp = 10;
                    } else if (SetGem == 220)
                    {
                        dsstype = 5;
                        phyatk = 8;
                        magatk = 8;
                        agi = 2;
                        hpinc = 90;
                        mpinc = 70;
                        if (IItem.GetType() == -1) eva = 8;
                        else otp = 8;
                    } else if (SetGem == 219)
                    {
                        dsstype = 5;
                        phyatk = 8;
                        magatk = 8;
                        wis = 2;
                        hpinc = 90;
                        mpinc = 70;
                        if (IItem.GetType() == -1) eva = 8;
                        else otp = 8;
                    } else if (SetGem == 218)
                    {
                        dsstype = 5;
                        phyatk = 8;
                        magatk = 8;
                        intel = 2;
                        hpinc = 90;
                        mpinc = 70;
                        if (IItem.GetType() == -1) eva = 8;
                        else otp = 8;
                    } else if (SetGem == 217)
                    {
                        dsstype = 5;
                        phyatk = 8;
                        magatk = 8;
                        hp = 2;
                        hpinc = 90;
                        mpinc = 70;
                        if (IItem.GetType() == -1) eva = 8;
                        else otp = 8;
                    } else if (SetGem == 216)
                    {
                        dsstype = 5;
                        phyatk = 8;
                        magatk = 8;
                        str = 2;
                        hpinc = 90;
                        mpinc = 70;
                        if (IItem.GetType() == -1) eva = 8;
                        else otp = 8;
                    } else if (SetGem == 215)
                    {
                        dsstype = 6;
                        phyatk = 6;
                        magatk = 6;
                        agi = 2;
                        hpinc = 70;
                        mpinc = 50;
                        if (IItem.GetType() == -1) eva = 6;
                        else otp = 6;
                    } else if (SetGem == 214)
                    {
                        dsstype = 6;
                        phyatk = 6;
                        magatk = 6;
                        wis = 2;
                        hpinc = 70;
                        mpinc = 50;
                        if (IItem.GetType() == -1) eva = 6;
                        else otp = 6;
                    } else if (SetGem == 213)
                    {
                        dsstype = 6;
                        phyatk = 6;
                        magatk = 6;
                        intel = 2;
                        hpinc = 70;
                        mpinc = 50;
                        if (IItem.GetType() == -1) eva = 6;
                        else otp = 6;
                    } else if (SetGem == 212)
                    {
                        dsstype = 6;
                        phyatk = 6;
                        magatk = 6;
                        hp = 2;
                        hpinc = 70;
                        mpinc = 50;
                        if (IItem.GetType() == -1) eva = 6;
                        else otp = 6;
                    } else if (SetGem == 211)
                    {
                        dsstype = 6;
                        phyatk = 6;
                        magatk = 6;
                        str = 2;
                        hpinc = 70;
                        mpinc = 50;
                        if (IItem.GetType() == -1) eva = 6;
                        else otp = 6;
                    } else if (SetGem == 210)
                    {
                        dsstype = 7;
                        phyatk = 4;
                        magatk = 4;
                        agi = 1;
                        hpinc = 50;
                        mpinc = 30;
                        if (IItem.GetType() == -1) eva = 4;
                        else otp = 4;
                    } else if (SetGem == 209)
                    {
                        dsstype = 7;
                        phyatk = 4;
                        magatk = 4;
                        wis = 1;
                        hpinc = 50;
                        mpinc = 30;
                        if (IItem.GetType() == -1) eva = 4;
                        else otp = 4;
                    } else if (SetGem == 208)
                    {
                        dsstype = 7;
                        phyatk = 4;
                        magatk = 4;
                        intel = 1;
                        hpinc = 50;
                        mpinc = 30;
                        if (IItem.GetType() == -1) eva = 4;
                        else otp = 4;
                    } else if (SetGem == 207)
                    {
                        dsstype = 7;
                        phyatk = 4;
                        magatk = 4;
                        hp = 1;
                        hpinc = 50;
                        mpinc = 30;
                        if (IItem.GetType() == -1) eva = 4;
                        else otp = 4;
                    } else if (SetGem == 206)
                    {
                        dsstype = 7;
                        phyatk = 4;
                        magatk = 4;
                        str = 1;
                        hpinc = 50;
                        mpinc = 30;
                        if (IItem.GetType() == -1) eva = 4;
                        else otp = 4;
                    } else if (SetGem == 205)
                    {
                        dsstype = 8;
                        phyatk = 2;
                        magatk = 2;
                        agi = 1;
                        hpinc = 30;
                        mpinc = 10;
                        if (IItem.GetType() == -1) eva = 2;
                        else otp = 2;
                    } else if (SetGem == 204)
                    {
                        dsstype = 8;
                        phyatk = 2;
                        magatk = 2;
                        wis = 1;
                        hpinc = 30;
                        mpinc = 10;
                        if (IItem.GetType() == -1) eva = 2;
                        else otp = 2;
                    } else if (SetGem == 203)
                    {
                        dsstype = 8;
                        phyatk = 2;
                        magatk = 2;
                        intel = 1;
                        hpinc = 30;
                        mpinc = 10;
                        if (IItem.GetType() == -1) eva = 2;
                        else otp = 2;
                    } else if (SetGem == 202)
                    {
                        dsstype = 8;
                        phyatk = 2;
                        magatk = 2;
                        hp = 1;
                        hpinc = 30;
                        mpinc = 10;
                        if (IItem.GetType() == -1) eva = 2;
                        else otp = 2;
                    } else if (SetGem == 201)
                    {
                        dsstype = 8;
                        phyatk = 2;
                        magatk = 2;
                        str = 1;
                        hpinc = 30;
                        mpinc = 10;
                        if (IItem.GetType() == -1) eva = 2;
                        else otp = 2;
                    }
                }

                if (IItem.GetType() >= 1 && IItem.GetType() <= 6)
                {
                    if (SetGem == 240)
                    {
                        dsstype = 1;
                        def = 18;
                        agi = 7;
                    } else if (SetGem == 239)
                    {
                        dsstype = 1;
                        def = 18;
                        wis = 7;
                    } else if (SetGem == 238)
                    {
                        dsstype = 1;
                        def = 18;
                        intel = 7;
                    } else if (SetGem == 237)
                    {
                        dsstype = 1;
                        def = 18;
                        hp = 7;
                    } else if (SetGem == 236)
                    {
                        dsstype = 1;
                        def = 18;
                        str = 7;
                    } else if (SetGem == 235)
                    {
                        dsstype = 2;
                        def = 16;
                        agi = 5;
                    } else if (SetGem == 234)
                    {
                        dsstype = 2;
                        def = 16;
                        wis = 5;
                    } else if (SetGem == 233)
                    {
                        dsstype = 2;
                        def = 16;
                        intel = 5;
                    } else if (SetGem == 232)
                    {
                        dsstype = 2;
                        def = 16;
                        hp = 5;
                    } else if (SetGem == 231)
                    {
                        dsstype = 2;
                        def = 16;
                        str = 5;
                    } else if (SetGem == 230)
                    {
                        dsstype = 3;
                        def = 14;
                        agi = 3;
                    } else if (SetGem == 229)
                    {
                        dsstype = 3;
                        def = 14;
                        wis = 3;
                    } else if (SetGem == 228)
                    {
                        dsstype = 3;
                        def = 14;
                        intel = 3;
                    } else if (SetGem == 227)
                    {
                        dsstype = 3;
                        def = 14;
                        hp = 3;
                    } else if (SetGem == 226)
                    {
                        dsstype = 3;
                        def = 14;
                        str = 3;
                    } else if (SetGem == 225)
                    {
                        dsstype = 4;
                        def = 12;
                        agi = 3;
                    } else if (SetGem == 224)
                    {
                        dsstype = 4;
                        def = 12;
                        wis = 3;
                    } else if (SetGem == 223)
                    {
                        dsstype = 4;
                        def = 12;
                        intel = 3;
                    } else if (SetGem == 222)
                    {
                        dsstype = 4;
                        def = 12;
                        hp = 3;
                    } else if (SetGem == 221)
                    {
                        dsstype = 4;
                        def = 12;
                        str = 3;
                    } else if (SetGem == 220)
                    {
                        dsstype = 5;
                        def = 10;
                        agi = 2;
                    } else if (SetGem == 219)
                    {
                        dsstype = 5;
                        def = 10;
                        wis = 2;
                    } else if (SetGem == 218)
                    {
                        dsstype = 5;
                        def = 10;
                        intel = 2;
                    } else if (SetGem == 217)
                    {
                        dsstype = 5;
                        def = 10;
                        hp = 2;
                    } else if (SetGem == 216)
                    {
                        dsstype = 5;
                        def = 10;
                        str = 2;
                    } else if (SetGem == 215)
                    {
                        dsstype = 6;
                        def = 8;
                        agi = 2;
                    } else if (SetGem == 214)
                    {
                        dsstype = 6;
                        def = 8;
                        wis = 2;
                    } else if (SetGem == 213)
                    {
                        dsstype = 6;
                        def = 8;
                        intel = 2;
                    } else if (SetGem == 212)
                    {
                        dsstype = 6;
                        def = 8;
                        hp = 2;
                    } else if (SetGem == 211)
                    {
                        dsstype = 6;
                        def = 8;
                        str = 2;
                    } else if (SetGem == 210)
                    {
                        dsstype = 7;
                        def = 6;
                        agi = 1;
                    } else if (SetGem == 209)
                    {
                        dsstype = 7;
                        def = 6;
                        wis = 1;
                    } else if (SetGem == 208)
                    {
                        dsstype = 7;
                        def = 6;
                        intel = 1;
                    } else if (SetGem == 207)
                    {
                        dsstype = 7;
                        def = 6;
                        hp = 1;
                    } else if (SetGem == 206)
                    {
                        dsstype = 7;
                        def = 6;
                        str = 1;
                    } else if (SetGem == 205)
                    {
                        dsstype = 8;
                        def = 4;
                        agi = 1;
                    } else if (SetGem == 204)
                    {
                        dsstype = 8;
                        def = 4;
                        wis = 1;
                    } else if (SetGem == 203)
                    {
                        dsstype = 8;
                        def = 4;
                        intel = 1;
                    } else if (SetGem == 202)
                    {
                        dsstype = 8;
                        def = 4;
                        hp = 1;
                    } else if (SetGem == 201)
                    {
                        dsstype = 8;
                        def = 4;
                        str = 1;
                    }
                }

                CBase::Delete((void*)MakeItem);
            }
        }

        if (GetItemStat.count(nIID))
        {
            PerfShotCheck = GetItemStat.find(nIID)->second / 100000000;
            ItemStat -= (100000000 * PerfShotCheck);
        }

        if (ItemStat)
        {
            int dg1typecheck = ItemStat / 10000000;
            if (dg1typecheck) dg1stat = 1;
            if (dg1typecheck > 0) dg1type = (dg1typecheck - 1);
            ItemStat -= (10000000 * dg1typecheck);
        }

        if (ItemStat)
        {
            int dg1statcheck = ItemStat / 1000000;
            if (dg1statcheck > 0) dg1stat = (dg1statcheck + 1);
            ItemStat -= (1000000 * dg1statcheck);
        }

        if (ItemStat)
        {
            int dg2typecheck = ItemStat / 100000;
            if (dg2typecheck) dg2stat = 1;
            if (dg2typecheck > 0) dg2type = (dg2typecheck - 1);
            ItemStat -= (100000 * dg2typecheck);
        }

        if (ItemStat)
        {
            int dg2statcheck = ItemStat / 10000;
            if (dg2statcheck > 0) dg2stat = (dg2statcheck + 1);
            ItemStat -= (10000 * dg2statcheck);
        }

        if (ItemStat && Index >= 2986 && Index <= 3009)
        {
            int yinyanggrade = ItemStat / 100;
            Prefix = yinyanggrade + 1;
            ItemStat -= (100 * yinyanggrade);
        }

        if (ItemStat)
            QigongGrade = ItemStat % 100;

        if (Index >= 3199 && Index <= 3201 && Prefix == 0)
            Prefix = 1;

        if (Index >= 2986 && Index <= 3009 && Prefix == 0)
            Prefix = 1;

        if (Index >= 3018 && Index <= 3020)
            Prefix = GetItemStat.find(nIID)->second / 1000;

        if (Index)
        {
            Tools->Compile(Packet,"wdbddbbbbbbbbwbbbbbdbwwwwbbbbbbbbbbdbbwbb",Index,nIID,
                           Prefix,Info,Num,MaxEnd,CurEnd,SetGem,XAttack,XMagic,XDefense,XHit,XDodge,
                           Protect,UpgrLevel,UpgrLevel, x, y, z, remaintime, dsstype, phyatk, magatk, def,
                           absorb, eva, otp, hpinc, mpinc, str, hp, intel, wis, agi, PerfShotCheck,
                           QigongGrade, dg1stat, dg1type, a, dg2stat, dg2type);
            CPlayer::Write(Player, 19, "bdbdwmm", 2, nMID, byMType, nIID, wLen, &Msg, wLen,
                           Packet, 63);
            return;
        }
    }

    CPlayer::MAILProcess(Player,Type,pPacket,pPos);
}

int __fastcall SendMail(void* Player, void *edx, int a1, int a2,
                        char* ReceiverName, const char *Text, int a5, int a6, int Index, int a8, int a9,
                        int Price)
{
    IChar IPlayer(Player);

    if (IPlayer.IsOnline())
    {
        if (Index == 31 && Price > 0)
        {
            IPlayer.SystemMessage("You can not send geons with price!", TEXTCOLOR_RED);
            return 0;
        }
    }

    return CPlayer::SendMail(Player, a1, a2, ReceiverName, Text, a5, a6, Index, a8,
                             a9, Price);
}
