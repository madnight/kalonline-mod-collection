void __fastcall WeaponApplySpec(int Item, void *edx, int Player)
{
    IItem IItem((void*)Item);
    IChar IPlayer((void*)Player);

    if (IPlayer.IsOnline())
    {
        int atk = IPlayer.GetMaxPhyAttack();
        CItemWeapon::ApplySpec(Item, Player);
        int check = IPlayer.GetMaxPhyAttack() -
            (atk + (*(DWORD*)(Item + 100) * (2 * *(DWORD*)(Item + 100) + 7) / 9));
        int FirstDemonGongType = 0, SecondDemonGongType = 0, FirstDemonGongStat = 0, SecondDemonGongStat = 0;

        if (GetItemStat.count(IItem.GetIID()))
        {
            FirstDemonGongType = (GetItemStat.find(IItem.GetIID())->second % 100000000) / 10000000;
            SecondDemonGongType = (GetItemStat.find(IItem.GetIID())->second % 1000000) / 100000;
            FirstDemonGongStat = (GetItemStat.find(IItem.GetIID())->second % 10000000) / 1000000;
            SecondDemonGongStat = (GetItemStat.find(IItem.GetIID())->second % 100000) / 10000;
        }

        if (FirstDemonGongType)
        {
            if (FirstDemonGongType == 1)
            {
                IPlayer.AddMinAttack(DemonGongStatWeaponEarth[0][FirstDemonGongStat-1]);
                IPlayer.AddMaxAttack(DemonGongStatWeaponEarth[0][FirstDemonGongStat-1]);
                IPlayer.AddOTP(DemonGongStatWeaponEarth[1][FirstDemonGongStat-1]);
            }

            if (FirstDemonGongType == 2)
            {
                IPlayer.AddMinAttack(DemonGongStatWeaponWind[0][FirstDemonGongStat-1]);
                IPlayer.AddMaxAttack(DemonGongStatWeaponWind[0][FirstDemonGongStat-1]);
                IPlayer.AddEva(DemonGongStatWeaponWind[1][FirstDemonGongStat-1]);
            }

            if (FirstDemonGongType == 3)
            {
                IPlayer.AddMinAttack(DemonGongStatWeaponWater[0][FirstDemonGongStat-1]);
                IPlayer.AddMaxAttack(DemonGongStatWeaponWater[0][FirstDemonGongStat-1]);
                IPlayer.IncreaseMaxHp(DemonGongStatWeaponWater[1][FirstDemonGongStat-1]);
            }
        }

        if (SecondDemonGongType)
        {
            if (SecondDemonGongType == 1)
            {
                IPlayer.AddMinAttack(DemonGongStatWeaponEarth[0][SecondDemonGongStat-1]);
                IPlayer.AddMaxAttack(DemonGongStatWeaponEarth[0][SecondDemonGongStat-1]);
                IPlayer.AddOTP(DemonGongStatWeaponEarth[1][SecondDemonGongStat-1]);
            }

            if (SecondDemonGongType == 2)
            {
                IPlayer.AddMinAttack(DemonGongStatWeaponWind[0][SecondDemonGongStat-1]);
                IPlayer.AddMaxAttack(DemonGongStatWeaponWind[0][SecondDemonGongStat-1]);
                IPlayer.AddEva(DemonGongStatWeaponWind[1][SecondDemonGongStat-1]);
            }

            if (SecondDemonGongType == 3)
            {
                IPlayer.AddMinAttack(DemonGongStatWeaponWater[0][SecondDemonGongStat-1]);
                IPlayer.AddMaxAttack(DemonGongStatWeaponWater[0][SecondDemonGongStat-1]);
                IPlayer.IncreaseMaxHp(DemonGongStatWeaponWater[1][SecondDemonGongStat-1]);
            }
        }

        if (GetItemStat.find(IItem.GetIID())->second > 0)
        {
            int QigongType = GetItemStat.find(IItem.GetIID())->second % 100;

            if (QigongType)
            {
                IPlayer.AddMaxAttack(check*QigongWeapon[QigongType-1][0]/100);
                IPlayer.AddMinAttack(check*QigongWeapon[QigongType-1][1]/100);
                IPlayer.IncreaseMaxHp(QigongWeapon[QigongType-1][2]);
                IPlayer.IncreaseMaxMp(QigongWeapon[QigongType-1][3]);

                if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                    IPlayer.AddEva(QigongWeapon[QigongType-1][4]);
                else
                    IPlayer.AddOTP(QigongWeapon[QigongType-1][4]);

                int Type = QigongWeapon[QigongType-1][5];
                int Stat = QigongWeapon[QigongType-1][6];

                if (Type == 0)
                    IPlayer.AddStr(Stat);
                else if (Type == 1)
                    IPlayer.AddHp(Stat);
                else if (Type == 2)
                    IPlayer.AddInt(Stat);
                else if (Type == 3)
                    IPlayer.AddWis(Stat);
                else if (Type == 4)
                    IPlayer.AddAgi(Stat);
            }
        }

        if (IItem.GetSetGem() == 240 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*17/100);
            IPlayer.AddMinAttack(check*17/100);
            IPlayer.AddAgi(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(18);
            else
                IPlayer.AddOTP(18);

            IPlayer.IncreaseMaxHp(250);
            IPlayer.IncreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 239 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*17/100);
            IPlayer.AddMinAttack(check*17/100);
            IPlayer.AddWis(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(18);
            else
                IPlayer.AddOTP(18);

            IPlayer.IncreaseMaxHp(250);
            IPlayer.IncreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 238 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*17/100);
            IPlayer.AddMinAttack(check*17/100);
            IPlayer.AddInt(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(18);
            else
                IPlayer.AddOTP(18);

            IPlayer.IncreaseMaxHp(250);
            IPlayer.IncreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 237 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*17/100);
            IPlayer.AddMinAttack(check*17/100);
            IPlayer.AddHp(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(18);
            else
                IPlayer.AddOTP(18);

            IPlayer.IncreaseMaxHp(250);
            IPlayer.IncreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 236 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*17/100);
            IPlayer.AddMinAttack(check*17/100);
            IPlayer.AddStr(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(18);
            else
                IPlayer.AddOTP(18);

            IPlayer.IncreaseMaxHp(250);
            IPlayer.IncreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 235 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*14/100);
            IPlayer.AddMinAttack(check*14/100);
            IPlayer.AddAgi(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(15);
            else
                IPlayer.AddOTP(15);

            IPlayer.IncreaseMaxHp(200);
            IPlayer.IncreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 234 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*14/100);
            IPlayer.AddMinAttack(check*14/100);
            IPlayer.AddWis(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(15);
            else
                IPlayer.AddOTP(15);

            IPlayer.IncreaseMaxHp(200);
            IPlayer.IncreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 233 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*14/100);
            IPlayer.AddMinAttack(check*14/100);
            IPlayer.AddInt(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(15);
            else
                IPlayer.AddOTP(15);

            IPlayer.IncreaseMaxHp(200);
            IPlayer.IncreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 232 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*14/100);
            IPlayer.AddMinAttack(check*14/100);
            IPlayer.AddHp(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(15);
            else
                IPlayer.AddOTP(15);

            IPlayer.IncreaseMaxHp(200);
            IPlayer.IncreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 231 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*14/100);
            IPlayer.AddMinAttack(check*14/100);
            IPlayer.AddStr(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(15);
            else
                IPlayer.AddOTP(15);

            IPlayer.IncreaseMaxHp(200);
            IPlayer.IncreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 230 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*12/100);
            IPlayer.AddMinAttack(check*12/100);
            IPlayer.AddAgi(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(12);
            else
                IPlayer.AddOTP(12);

            IPlayer.IncreaseMaxHp(130);
            IPlayer.IncreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 229 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*12/100);
            IPlayer.AddMinAttack(check*12/100);
            IPlayer.AddWis(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(12);
            else
                IPlayer.AddOTP(12);

            IPlayer.IncreaseMaxHp(130);
            IPlayer.IncreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 228 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*12/100);
            IPlayer.AddMinAttack(check*12/100);
            IPlayer.AddInt(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(12);
            else
                IPlayer.AddOTP(12);

            IPlayer.IncreaseMaxHp(130);
            IPlayer.IncreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 227 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*12/100);
            IPlayer.AddMinAttack(check*12/100);
            IPlayer.AddHp(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(12);
            else
                IPlayer.AddOTP(12);

            IPlayer.IncreaseMaxHp(130);
            IPlayer.IncreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 226 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*12/100);
            IPlayer.AddMinAttack(check*12/100);
            IPlayer.AddStr(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(12);
            else
                IPlayer.AddOTP(12);

            IPlayer.IncreaseMaxHp(130);
            IPlayer.IncreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 225 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*10/100);
            IPlayer.AddMinAttack(check*10/100);
            IPlayer.AddAgi(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(10);
            else
                IPlayer.AddOTP(10);

            IPlayer.IncreaseMaxHp(110);
            IPlayer.IncreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 224 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*10/100);
            IPlayer.AddMinAttack(check*10/100);
            IPlayer.AddWis(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(10);
            else
                IPlayer.AddOTP(10);

            IPlayer.IncreaseMaxHp(110);
            IPlayer.IncreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 223 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*10/100);
            IPlayer.AddMinAttack(check*10/100);
            IPlayer.AddInt(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(10);
            else
                IPlayer.AddOTP(10);

            IPlayer.IncreaseMaxHp(110);
            IPlayer.IncreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 222 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*10/100);
            IPlayer.AddMinAttack(check*10/100);
            IPlayer.AddHp(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(10);
            else
                IPlayer.AddOTP(10);

            IPlayer.IncreaseMaxHp(110);
            IPlayer.IncreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 221 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*10/100);
            IPlayer.AddMinAttack(check*10/100);
            IPlayer.AddStr(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(10);
            else
                IPlayer.AddOTP(10);

            IPlayer.IncreaseMaxHp(110);
            IPlayer.IncreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 220 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*8/100);
            IPlayer.AddMinAttack(check*8/100);
            IPlayer.AddAgi(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(8);
            else
                IPlayer.AddOTP(8);

            IPlayer.IncreaseMaxHp(90);
            IPlayer.IncreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 219 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*8/100);
            IPlayer.AddMinAttack(check*8/100);
            IPlayer.AddWis(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(8);
            else
                IPlayer.AddOTP(8);

            IPlayer.IncreaseMaxHp(90);
            IPlayer.IncreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 218 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*8/100);
            IPlayer.AddMinAttack(check*8/100);
            IPlayer.AddInt(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(8);
            else
                IPlayer.AddOTP(8);

            IPlayer.IncreaseMaxHp(90);
            IPlayer.IncreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 217 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*8/100);
            IPlayer.AddMinAttack(check*8/100);
            IPlayer.AddHp(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(8);
            else
                IPlayer.AddOTP(8);

            IPlayer.IncreaseMaxHp(90);
            IPlayer.IncreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 216 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*8/100);
            IPlayer.AddMinAttack(check*8/100);
            IPlayer.AddStr(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(8);
            else
                IPlayer.AddOTP(8);

            IPlayer.IncreaseMaxHp(90);
            IPlayer.IncreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 215 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*6/100);
            IPlayer.AddMinAttack(check*6/100);
            IPlayer.AddAgi(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(6);
            else
                IPlayer.AddOTP(6);

            IPlayer.IncreaseMaxHp(70);
            IPlayer.IncreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 214 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*6/100);
            IPlayer.AddMinAttack(check*6/100);
            IPlayer.AddWis(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(6);
            else
                IPlayer.AddOTP(6);

            IPlayer.IncreaseMaxHp(70);
            IPlayer.IncreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 213 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*6/100);
            IPlayer.AddMinAttack(check*6/100);
            IPlayer.AddInt(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(6);
            else
                IPlayer.AddOTP(6);

            IPlayer.IncreaseMaxHp(70);
            IPlayer.IncreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 212 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*6/100);
            IPlayer.AddMinAttack(check*6/100);
            IPlayer.AddHp(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(6);
            else
                IPlayer.AddOTP(6);

            IPlayer.IncreaseMaxHp(70);
            IPlayer.IncreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 211 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*6/100);
            IPlayer.AddMinAttack(check*6/100);
            IPlayer.AddStr(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(6);
            else
                IPlayer.AddOTP(6);

            IPlayer.IncreaseMaxHp(70);
            IPlayer.IncreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 210 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*4/100);
            IPlayer.AddMinAttack(check*4/100);
            IPlayer.AddAgi(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(4);
            else
                IPlayer.AddOTP(4);

            IPlayer.IncreaseMaxHp(50);
            IPlayer.IncreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 209 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*4/100);
            IPlayer.AddMinAttack(check*4/100);
            IPlayer.AddWis(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(4);
            else
                IPlayer.AddOTP(4);

            IPlayer.IncreaseMaxHp(50);
            IPlayer.IncreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 208 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*4/100);
            IPlayer.AddMinAttack(check*4/100);
            IPlayer.AddInt(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(4);
            else
                IPlayer.AddOTP(4);

            IPlayer.IncreaseMaxHp(50);
            IPlayer.IncreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 207 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*4/100);
            IPlayer.AddMinAttack(check*4/100);
            IPlayer.AddHp(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(4);
            else
                IPlayer.AddOTP(4);

            IPlayer.IncreaseMaxHp(50);
            IPlayer.IncreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 206 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*4/100);
            IPlayer.AddMinAttack(check*4/100);
            IPlayer.AddStr(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(4);
            else
                IPlayer.AddOTP(4);

            IPlayer.IncreaseMaxHp(50);
            IPlayer.IncreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 205 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*2/100);
            IPlayer.AddMinAttack(check*2/100);
            IPlayer.AddAgi(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(2);
            else
                IPlayer.AddOTP(2);

            IPlayer.IncreaseMaxHp(30);
            IPlayer.IncreaseMaxMp(10);
        } else if (IItem.GetSetGem() == 204 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*2/100);
            IPlayer.AddMinAttack(check*2/100);
            IPlayer.AddWis(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(2);
            else
                IPlayer.AddOTP(2);

            IPlayer.IncreaseMaxHp(30);
            IPlayer.IncreaseMaxMp(10);
        } else if (IItem.GetSetGem() == 203 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*2/100);
            IPlayer.AddMinAttack(check*2/100);
            IPlayer.AddInt(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(2);
            else
                IPlayer.AddOTP(2);

            IPlayer.IncreaseMaxHp(30);
            IPlayer.IncreaseMaxMp(10);
        } else if (IItem.GetSetGem() == 202 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*2/100);
            IPlayer.AddMinAttack(check*2/100);
            IPlayer.AddHp(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(2);
            else
                IPlayer.AddOTP(2);

            IPlayer.IncreaseMaxHp(30);
            IPlayer.IncreaseMaxMp(10);
        } else if (IItem.GetSetGem() == 201 && IItem.GetInfo() & 1)
        {
            IPlayer.AddMaxAttack(check*2/100);
            IPlayer.AddMinAttack(check*2/100);
            IPlayer.AddStr(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.AddEva(2);
            else
                IPlayer.AddOTP(2);

            IPlayer.IncreaseMaxHp(30);
            IPlayer.IncreaseMaxMp(10);
        }
    }
}

void __fastcall WeaponPutOff(void *Item,void *edx,int Player)
{
    IChar IPlayer((void*)Player);
    IItem IItem((void*)Item);

    if (IPlayer.IsBuff(256))
    {
        IPlayer.SystemMessage("You need to wait 3 seconds to put off your weapon.", TEXTCOLOR_INFOMSG);
    } else {
        IPlayer.Buff(256,2,0);
        int atk = IPlayer.GetMaxPhyAttack();
        CItemWeapon::PutOff(Item, Player);
        int check = atk - (IPlayer.GetMaxPhyAttack() + (*(DWORD*)((int)Item + 100) * (2 * *(DWORD*)((int)Item + 100) + 7) / 9));
        int FirstDemonGongType = 0, SecondDemonGongType = 0, FirstDemonGongStat = 0, SecondDemonGongStat = 0;

        if (GetItemStat.count(IItem.GetIID()))
        {
            FirstDemonGongType = (GetItemStat.find(IItem.GetIID())->second % 100000000) / 10000000;
            SecondDemonGongType = (GetItemStat.find(IItem.GetIID())->second % 1000000) / 100000;
            FirstDemonGongStat = (GetItemStat.find(IItem.GetIID())->second % 10000000) / 1000000;
            SecondDemonGongStat = (GetItemStat.find(IItem.GetIID())->second % 100000) / 10000;
        }

        if (FirstDemonGongType)
        {
            if (FirstDemonGongType == 1)
            {
                IPlayer.RemoveMinAttack(DemonGongStatWeaponEarth[0][FirstDemonGongStat-1]);
                IPlayer.RemoveMaxAttack(DemonGongStatWeaponEarth[0][FirstDemonGongStat-1]);
                IPlayer.RemoveOTP(DemonGongStatWeaponEarth[1][FirstDemonGongStat-1]);
            }

            if (FirstDemonGongType == 2)
            {
                IPlayer.RemoveMinAttack(DemonGongStatWeaponWind[0][FirstDemonGongStat-1]);
                IPlayer.RemoveMaxAttack(DemonGongStatWeaponWind[0][FirstDemonGongStat-1]);
                IPlayer.RemoveEva(DemonGongStatWeaponWind[1][FirstDemonGongStat-1]);
            }

            if (FirstDemonGongType == 3)
            {
                IPlayer.RemoveMinAttack(DemonGongStatWeaponWater[0][FirstDemonGongStat-1]);
                IPlayer.RemoveMaxAttack(DemonGongStatWeaponWater[0][FirstDemonGongStat-1]);
                IPlayer.DecreaseMaxHp(DemonGongStatWeaponWater[1][FirstDemonGongStat-1]);
            }
        }

        if (SecondDemonGongType)
        {
            if (SecondDemonGongType == 1)
            {
                IPlayer.RemoveMinAttack(DemonGongStatWeaponEarth[0][SecondDemonGongStat-1]);
                IPlayer.RemoveMaxAttack(DemonGongStatWeaponEarth[0][SecondDemonGongStat-1]);
                IPlayer.RemoveOTP(DemonGongStatWeaponEarth[1][SecondDemonGongStat-1]);
            }

            if (SecondDemonGongType == 2)
            {
                IPlayer.RemoveMinAttack(DemonGongStatWeaponWind[0][SecondDemonGongStat-1]);
                IPlayer.RemoveMaxAttack(DemonGongStatWeaponWind[0][SecondDemonGongStat-1]);
                IPlayer.RemoveEva(DemonGongStatWeaponWind[1][SecondDemonGongStat-1]);
            }

            if (SecondDemonGongType == 3)
            {
                IPlayer.RemoveMinAttack(DemonGongStatWeaponWater[0][SecondDemonGongStat-1]);
                IPlayer.RemoveMaxAttack(DemonGongStatWeaponWater[0][SecondDemonGongStat-1]);
                IPlayer.DecreaseMaxHp(DemonGongStatWeaponWater[1][SecondDemonGongStat-1]);
            }
        }

        if (GetItemStat.find(IItem.GetIID())->second > 0)
        {
            int QigongType = GetItemStat.find(IItem.GetIID())->second % 100;

            if (QigongType)
            {
                IPlayer.RemoveMaxAttack(check*QigongWeapon[QigongType-1][0]/100);
                IPlayer.RemoveMinAttack(check*QigongWeapon[QigongType-1][1]/100);
                IPlayer.DecreaseMaxHp(QigongWeapon[QigongType-1][2]);
                IPlayer.DecreaseMaxMp(QigongWeapon[QigongType-1][3]);

                if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                    IPlayer.RemoveEva(QigongWeapon[QigongType-1][4]);
                else
                    IPlayer.RemoveOTP(QigongWeapon[QigongType-1][4]);

                int Type = QigongWeapon[QigongType-1][5];
                int Stat = QigongWeapon[QigongType-1][6];

                if (Type == 0)
                    IPlayer.RemoveStr(Stat);
                else if (Type == 1)
                    IPlayer.RemoveHp(Stat);
                else if (Type == 2)
                    IPlayer.RemoveInt(Stat);
                else if (Type == 3)
                    IPlayer.RemoveWis(Stat);
                else if (Type == 4)
                    IPlayer.RemoveAgi(Stat);
            }
        }

        if (IItem.GetSetGem() == 240)
        {
            IPlayer.RemoveMaxAttack(check*17/100);
            IPlayer.RemoveMinAttack(check*17/100);
            IPlayer.RemoveAgi(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(18);
            else
                IPlayer.RemoveOTP(18);

            IPlayer.DecreaseMaxHp(250);
            IPlayer.DecreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 239)
        {
            IPlayer.RemoveMaxAttack(check*17/100);
            IPlayer.RemoveMinAttack(check*17/100);
            IPlayer.RemoveWis(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(18);
            else
                IPlayer.RemoveOTP(18);

            IPlayer.DecreaseMaxHp(250);
            IPlayer.DecreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 238)
        {
            IPlayer.RemoveMaxAttack(check*17/100);
            IPlayer.RemoveMinAttack(check*17/100);
            IPlayer.RemoveInt(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(18);
            else
                IPlayer.RemoveOTP(18);

            IPlayer.DecreaseMaxHp(250);
            IPlayer.DecreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 237)
        {
            IPlayer.RemoveMaxAttack(check*17/100);
            IPlayer.RemoveMinAttack(check*17/100);
            IPlayer.RemoveHp(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(18);
            else
                IPlayer.RemoveOTP(18);

            IPlayer.DecreaseMaxHp(250);
            IPlayer.DecreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 236)
        {
            IPlayer.RemoveMaxAttack(check*17/100);
            IPlayer.RemoveMinAttack(check*17/100);
            IPlayer.RemoveStr(8);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(18);
            else
                IPlayer.RemoveOTP(18);

            IPlayer.DecreaseMaxHp(250);
            IPlayer.DecreaseMaxMp(200);
        } else if (IItem.GetSetGem() == 235)
        {
            IPlayer.RemoveMaxAttack(check*14/100);
            IPlayer.RemoveMinAttack(check*14/100);
            IPlayer.RemoveAgi(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(15);
            else
                IPlayer.RemoveOTP(15);

            IPlayer.DecreaseMaxHp(200);
            IPlayer.DecreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 234)
        {
            IPlayer.RemoveMaxAttack(check*14/100);
            IPlayer.RemoveMinAttack(check*14/100);
            IPlayer.RemoveWis(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(15);
            else
                IPlayer.RemoveOTP(15);

            IPlayer.DecreaseMaxHp(200);
            IPlayer.DecreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 233)
        {
            IPlayer.RemoveMaxAttack(check*14/100);
            IPlayer.RemoveMinAttack(check*14/100);
            IPlayer.RemoveInt(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(15);
            else
                IPlayer.RemoveOTP(15);

            IPlayer.DecreaseMaxHp(200);
            IPlayer.DecreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 232)
        {
            IPlayer.RemoveMaxAttack(check*14/100);
            IPlayer.RemoveMinAttack(check*14/100);
            IPlayer.RemoveHp(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(15);
            else
                IPlayer.RemoveOTP(15);

            IPlayer.DecreaseMaxHp(200);
            IPlayer.DecreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 231)
        {
            IPlayer.RemoveMaxAttack(check*14/100);
            IPlayer.RemoveMinAttack(check*14/100);
            IPlayer.RemoveStr(5);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(15);
            else
                IPlayer.RemoveOTP(15);

            IPlayer.DecreaseMaxHp(200);
            IPlayer.DecreaseMaxMp(150);
        } else if (IItem.GetSetGem() == 230)
        {
            IPlayer.RemoveMaxAttack(check*12/100);
            IPlayer.RemoveMinAttack(check*12/100);
            IPlayer.RemoveAgi(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(12);
            else
                IPlayer.RemoveOTP(12);

            IPlayer.DecreaseMaxHp(130);
            IPlayer.DecreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 229)
        {
            IPlayer.RemoveMaxAttack(check*12/100);
            IPlayer.RemoveMinAttack(check*12/100);
            IPlayer.RemoveWis(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(12);
            else
                IPlayer.RemoveOTP(12);

            IPlayer.DecreaseMaxHp(130);
            IPlayer.DecreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 228)
        {
            IPlayer.RemoveMaxAttack(check*12/100);
            IPlayer.RemoveMinAttack(check*12/100);
            IPlayer.RemoveInt(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(12);
            else
                IPlayer.RemoveOTP(12);

            IPlayer.DecreaseMaxHp(130);
            IPlayer.DecreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 227)
        {
            IPlayer.RemoveMaxAttack(check*12/100);
            IPlayer.RemoveMinAttack(check*12/100);
            IPlayer.RemoveHp(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(12);
            else
                IPlayer.RemoveOTP(12);

            IPlayer.DecreaseMaxHp(130);
            IPlayer.DecreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 226)
        {
            IPlayer.RemoveMaxAttack(check*12/100);
            IPlayer.RemoveMinAttack(check*12/100);
            IPlayer.RemoveStr(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(12);
            else
                IPlayer.RemoveOTP(12);

            IPlayer.DecreaseMaxHp(130);
            IPlayer.DecreaseMaxMp(110);
        } else if (IItem.GetSetGem() == 225)
        {
            IPlayer.RemoveMaxAttack(check*10/100);
            IPlayer.RemoveMinAttack(check*10/100);
            IPlayer.RemoveAgi(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(10);
            else
                IPlayer.RemoveOTP(10);

            IPlayer.DecreaseMaxHp(110);
            IPlayer.DecreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 224)
        {
            IPlayer.RemoveMaxAttack(check*10/100);
            IPlayer.RemoveMinAttack(check*10/100);
            IPlayer.RemoveWis(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(10);
            else
                IPlayer.RemoveOTP(10);

            IPlayer.DecreaseMaxHp(110);
            IPlayer.DecreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 223)
        {
            IPlayer.RemoveMaxAttack(check*10/100);
            IPlayer.RemoveMinAttack(check*10/100);
            IPlayer.RemoveInt(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(10);
            else
                IPlayer.RemoveOTP(10);

            IPlayer.DecreaseMaxHp(110);
            IPlayer.DecreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 222)
        {
            IPlayer.RemoveMaxAttack(check*10/100);
            IPlayer.RemoveMinAttack(check*10/100);
            IPlayer.RemoveHp(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(10);
            else
                IPlayer.RemoveOTP(10);

            IPlayer.DecreaseMaxHp(110);
            IPlayer.DecreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 221)
        {
            IPlayer.RemoveMaxAttack(check*10/100);
            IPlayer.RemoveMinAttack(check*10/100);
            IPlayer.RemoveStr(3);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(10);
            else
                IPlayer.RemoveOTP(10);

            IPlayer.DecreaseMaxHp(110);
            IPlayer.DecreaseMaxMp(90);
        } else if (IItem.GetSetGem() == 220)
        {
            IPlayer.RemoveMaxAttack(check*8/100);
            IPlayer.RemoveMinAttack(check*8/100);
            IPlayer.RemoveAgi(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(8);
            else
                IPlayer.RemoveOTP(8);

            IPlayer.DecreaseMaxHp(90);
            IPlayer.DecreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 219)
        {
            IPlayer.RemoveMaxAttack(check*8/100);
            IPlayer.RemoveMinAttack(check*8/100);
            IPlayer.RemoveWis(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(8);
            else
                IPlayer.RemoveOTP(8);

            IPlayer.DecreaseMaxHp(90);
            IPlayer.DecreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 218)
        {
            IPlayer.RemoveMaxAttack(check*8/100);
            IPlayer.RemoveMinAttack(check*8/100);
            IPlayer.RemoveInt(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(8);
            else
                IPlayer.RemoveOTP(8);

            IPlayer.DecreaseMaxHp(90);
            IPlayer.DecreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 217)
        {
            IPlayer.RemoveMaxAttack(check*8/100);
            IPlayer.RemoveMinAttack(check*8/100);
            IPlayer.RemoveHp(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(8);
            else
                IPlayer.RemoveOTP(8);

            IPlayer.DecreaseMaxHp(90);
            IPlayer.DecreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 216)
        {
            IPlayer.RemoveMaxAttack(check*8/100);
            IPlayer.RemoveMinAttack(check*8/100);
            IPlayer.RemoveStr(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(8);
            else
                IPlayer.RemoveOTP(8);

            IPlayer.DecreaseMaxHp(90);
            IPlayer.DecreaseMaxMp(70);
        } else if (IItem.GetSetGem() == 215)
        {
            IPlayer.RemoveMaxAttack(check*6/100);
            IPlayer.RemoveMinAttack(check*6/100);
            IPlayer.RemoveAgi(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(6);
            else
                IPlayer.RemoveOTP(6);

            IPlayer.DecreaseMaxHp(70);
            IPlayer.DecreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 214)
        {
            IPlayer.RemoveMaxAttack(check*6/100);
            IPlayer.RemoveMinAttack(check*6/100);
            IPlayer.RemoveWis(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(6);
            else
                IPlayer.RemoveOTP(6);

            IPlayer.DecreaseMaxHp(70);
            IPlayer.DecreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 213)
        {
            IPlayer.RemoveMaxAttack(check*6/100);
            IPlayer.RemoveMinAttack(check*6/100);
            IPlayer.RemoveInt(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(6);
            else
                IPlayer.RemoveOTP(6);

            IPlayer.DecreaseMaxHp(70);
            IPlayer.DecreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 212)
        {
            IPlayer.RemoveMaxAttack(check*6/100);
            IPlayer.RemoveMinAttack(check*6/100);
            IPlayer.RemoveHp(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(6);
            else
                IPlayer.RemoveOTP(6);

            IPlayer.DecreaseMaxHp(70);
            IPlayer.DecreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 211)
        {
            IPlayer.RemoveMaxAttack(check*6/100);
            IPlayer.RemoveMinAttack(check*6/100);
            IPlayer.RemoveStr(2);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(6);
            else
                IPlayer.RemoveOTP(6);

            IPlayer.DecreaseMaxHp(70);
            IPlayer.DecreaseMaxMp(50);
        } else if (IItem.GetSetGem() == 210)
        {
            IPlayer.RemoveMaxAttack(check*4/100);
            IPlayer.RemoveMinAttack(check*4/100);
            IPlayer.RemoveAgi(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(4);
            else
                IPlayer.RemoveOTP(4);

            IPlayer.DecreaseMaxHp(50);
            IPlayer.DecreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 209)
        {
            IPlayer.RemoveMaxAttack(check*4/100);
            IPlayer.RemoveMinAttack(check*4/100);
            IPlayer.RemoveWis(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(4);
            else
                IPlayer.RemoveOTP(4);

            IPlayer.DecreaseMaxHp(50);
            IPlayer.DecreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 208)
        {
            IPlayer.RemoveMaxAttack(check*4/100);
            IPlayer.RemoveMinAttack(check*4/100);
            IPlayer.RemoveInt(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(4);
            else
                IPlayer.RemoveOTP(4);

            IPlayer.DecreaseMaxHp(50);
            IPlayer.DecreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 207)
        {
            IPlayer.RemoveMaxAttack(check*4/100);
            IPlayer.RemoveMinAttack(check*4/100);
            IPlayer.RemoveHp(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(4);
            else
                IPlayer.RemoveOTP(4);

            IPlayer.DecreaseMaxHp(50);
            IPlayer.DecreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 206)
        {
            IPlayer.RemoveMaxAttack(check*4/100);
            IPlayer.RemoveMinAttack(check*4/100);
            IPlayer.RemoveStr(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(4);
            else
                IPlayer.RemoveOTP(4);

            IPlayer.DecreaseMaxHp(50);
            IPlayer.DecreaseMaxMp(30);
        } else if (IItem.GetSetGem() == 205)
        {
            IPlayer.RemoveMaxAttack(check*2/100);
            IPlayer.RemoveMinAttack(check*2/100);
            IPlayer.RemoveAgi(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(2);
            else
                IPlayer.RemoveOTP(2);

            IPlayer.DecreaseMaxHp(30);
            IPlayer.DecreaseMaxMp(10);
        } else if (IItem.GetSetGem() == 204)
        {
            IPlayer.RemoveMaxAttack(check*2/100);
            IPlayer.RemoveMinAttack(check*2/100);
            IPlayer.RemoveWis(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(2);
            else
                IPlayer.RemoveOTP(2);

            IPlayer.DecreaseMaxHp(30);
            IPlayer.DecreaseMaxMp(10);
        } else if (IItem.GetSetGem() == 203)
        {
            IPlayer.RemoveMaxAttack(check*2/100);
            IPlayer.RemoveMinAttack(check*2/100);
            IPlayer.RemoveInt(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(2);
            else
                IPlayer.RemoveOTP(2);

            IPlayer.DecreaseMaxHp(30);
            IPlayer.DecreaseMaxMp(10);
        } else if (IItem.GetSetGem() == 202)
        {
            IPlayer.RemoveMaxAttack(check*2/100);
            IPlayer.RemoveMinAttack(check*2/100);
            IPlayer.RemoveHp(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(2);
            else
                IPlayer.RemoveOTP(2);

            IPlayer.DecreaseMaxHp(30);
            IPlayer.DecreaseMaxMp(10);
        } else if (IItem.GetSetGem() == 201)
        {
            IPlayer.RemoveMaxAttack(check*2/100);
            IPlayer.RemoveMinAttack(check*2/100);
            IPlayer.RemoveStr(1);

            if (IItem.GetType() == -1 || (IItem.GetType() == -3 && IPlayer.GetClass() == 4))
                IPlayer.RemoveEva(2);
            else
                IPlayer.RemoveOTP(2);

            IPlayer.DecreaseMaxHp(30);
            IPlayer.DecreaseMaxMp(10);
        }
    }
}


void __fastcall WeaponPutOn(int Item,void *edx,int Player)
{
    IChar IPlayer((void*)Player);
    IItem IItem((void*)Item);

    if (IPlayer.IsBuff(256))
    {
        IPlayer.SystemMessage("You need to wait 3 seconds to put on your weapon.", TEXTCOLOR_INFOMSG);
    } else {
        IPlayer.Buff(256,2,0);

        if (IPlayer.IsValid() && IPlayer.IsBuff(120))
        {
            if (IItem.LevelLimit() > 5)
                IItem.SetLevelLimit(IItem.LevelLimit()-5);
        }

        CItemWeapon::PutOn(Item, Player);

        if (IPlayer.IsValid() && IPlayer.IsBuff(120))
        {
            if (IItem.LevelLimit() > 5)
                IItem.SetLevelLimit(IItem.LevelLimit()+5);
        }
    }
}
