void SetLearnUpgradeLimit()
{
    Interface<IMemory> Memory;
    int NewPacket = 96;
    Memory->Copy((void*)0x0047F97C, &NewPacket, 1);
    Memory->Copy((void*)0x0047F7AC, &NewPacket, 1);
    Memory->Copy((void*)0x0047F6BC, &NewPacket, 1);
    int FriendSize = 200;
    Memory->Copy((void*)0x00467E12, &FriendSize, 1);
}

void playerLearnSkill(int skillid, int player) {

    IChar IPlayer((void*)*(DWORD*)player);

    int pSkill = IPlayer.GetSkillPointer(skillid);

    if (!pSkill) {
        CSkill::LearnSkill(player, skillid);
    }
}


void sendSkill(int checkGrade, int skillID, int gradeLimit, int player) {

    IChar IPlayer((void*)*(DWORD*)SkillPointer);
    int pSkill = IPlayer.GetSkillPointer(64);
    ISkill xSkill((void*)pSkill);

    for (int i = 0; i <= checkGrade; i++)
    {
        if (xSkill.GetGrade() < gradeLimit && xSkill.GetGrade() + 1 <= checkGrade)
        {
            CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), skillID, xSkill.GetGrade() + 1, 56);
            CPlayer::Write(IPlayer.GetOffset(), 81, "bb", skillID, xSkill.GetGrade() + 1);
            *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
        }
    }
}

int checkGrade(int level)
{
    int CheckGrade = 0;

    if (level >= 100) {
        CheckGrade = 7;
    }
    else if (level >= 95) {
        CheckGrade = 6;
    }
    else if (level >= 90) {
        CheckGrade = 5;
    }
    else if (level >= 85) {
        CheckGrade = 4;
    }
    else if (level >= 80) {
        CheckGrade = 3;
    }
    else if (level >= 75) {
        CheckGrade = 2;
    }
    return CheckGrade;
}


void __fastcall Occupation(void *SkillPointer, void *edx)
{
    IChar IPlayer((void*)*(DWORD*)SkillPointer);

    if (!IPlayer.IsOnline())
    {
        CSkill::Occupation(SkillPointer);
        return;
    }

    if (IPlayer.GetSpecialty() >= 23) {
        IPlayer.AddFxToTarget("davi_ef134", 1, 0, 0);
    }

    int c = IPlayer.GetClass();
    int l = IPlayer.GetLevel();
    int s = IPlayer.GetSpecialty();

    if (c == 4 && l >= 70 && s == 23)
    {
        if (!IPlayer.GetSkillPointer(70))
        {
            CSkill::LearnSkill(SkillPointer, 70);
            IPlayer.AddMaxAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
            IPlayer.AddMinAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
        }
    }

    if (c == 4 && l >= 70 && s == 43)
    {
        if (!IPlayer.GetSkillPointer(71))
        {
            CSkill::LearnSkill(SkillPointer, 71);
            IPlayer.AddMaxAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
            IPlayer.AddMinAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
        }
    }

    if (c == 4 && l >= 50 && (s == 7 || s == 23)) {
        playerLearnSkill(35, SkillPointer)
    }

    if (c == 4 && l >= 50 && (s == 11 || s == 43)) {
        playerLearnSkill(43, SkillPointer)
    }

    if (c == 0 && l >= 70 && s == 23) {
        playerLearnSkill(37, SkillPointer)
    }

    if (c == 0 && l >= 70 && s == 43)
    {
        if (!IPlayer.GetSkillPointer(39))
        {
            CSkill::LearnSkill(SkillPointer, 39);
            IPlayer.AddDef(((l - 65) * 5) - ((IPlayer.GetDef() * 2) / 50));
        }
    }

    if (c == 0 && l >= 50 && (s == 11 || s == 43)) {
        playerLearnSkill(82, SkillPointer)
    }

    if (c == 0 && l >= 50 && (s == 11 || s == 43)) {
        playerLearnSkill(44, SkillPointer)
    }

    if (c == 0 && l >= 70 && (s == 23 || s == 43))
    {
        if (!IPlayer.GetSkillPointer(70))
        {
            CSkill::LearnSkill(SkillPointer, 70);
            IPlayer.AddMaxAttack((IPlayer.GetMaxPhyAttack() * 8) / 100);
            IPlayer.AddMinAttack((IPlayer.GetMaxPhyAttack() * 8) / 100);
        }
    }

    if (c == 1 && l >= 70 && s == 43) {
        playerLearnSkill(68, SkillPointer)
    }

    if (c == 1 && l >= 50 && (s == 11 || s == 43 || s == 7 || s == 23)) {
        playerLearnSkill(82, SkillPointer)
    }

    if (c == 1 && l >= 70 && s == 23)
    {
        if (!IPlayer.GetSkillPointer(70))
        {
            CSkill::LearnSkill(SkillPointer, 70);
            IPlayer.AddMaxAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
            IPlayer.AddMinAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
        }
    }

    if (c == 1 && l >= 70 && s == 43)
    {
        if (IPlayer.GetSkillPointer(71))
        {
            CSkill::LearnSkill(SkillPointer, 71);
            IPlayer.AddDef(12);
        }
    }

    if (c == 1 && l >= 70 && (s == 23 || s == 43)) {
        playerLearnSkill(63, SkillPointer)
    }

    if (c == 1 && l >= 70 && s == 23) {
        playerLearnSkill(64, SkillPointer)
    }

    if (c == 2 && l >= 70 && (s == 23 || s == 43))
    {
        if (!IPlayer.GetSkillPointer(70))
        {
            CSkill::LearnSkill(SkillPointer, 70);
            IPlayer.AddMaxAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
            IPlayer.AddMinAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
        }
    }

    if (c == 2 && l >= 70 && s == 43)
    {
        if (!IPlayer.GetSkillPointer(48))
        {
            CSkill::LearnSkill(SkillPointer, 48);
            IPlayer.AddEva((IPlayer.GetAgi() * (l / 2) / 400));
        }
    }

    if (c == 2 && l >= 70 && s == 23) {
        playerLearnSkill(46, SkillPointer)
    }

    if (c == 2 && l >= 50 && (s == 11 || s == 43)) {
        playerLearnSkill(82, SkillPointer)
    }

    if (c == 3 && l >= 70 && (s == 23 || s == 43))
    {
        if (!IPlayer.GetSkillPointer(70))
        {
            CSkill::LearnSkill(SkillPointer, 70);
            IPlayer.AddMaxAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
            IPlayer.AddMinAttack((IPlayer.GetMaxMagAttack() * 8) / 100);
        }
    }

    if ((c == 3 || c == 4) && l >= 50 && s > 3)
    {
        if (!IPlayer.GetSkillPointer(30)
        {
            CSkill::LearnSkill(SkillPointer, 30);
            IPlayer.IncreaseMaxHp(5 * IPlayer.GetHth());
        }
    }
    CSkill::Occupation(SkillPointer);
}

signed int __fastcall LearnSkillCheck(void *SkillPointer, void *edx,
    signed int s) // s == SkillID
{
    IChar IPlayer((void*)*(DWORD*)SkillPointer);

    if (IPlayer.IsOnline())
    {
        if (IPlayer.GetClass() == 0 &&
                (s == 37 || s == 39 || s == 44 || s == 70 || s == 82 || s == 87
              || s == 88 || s == 89 || s == 90 || s == 91 || s == 92 || s == 93
              || s == 94 || s == 95 || s == 79)) {
            return 0;
        }

        if (IPlayer.GetClass() == 1 &&
                  (s == 63 || s == 64 || s == 68 || s == 70 || s == 71 || s == 82
                || s == 87 || s == 88 || s == 89 || s == 90 || s == 91 || s == 92
                || s == 93 || s == 94 || s == 95 || s == 79)) {
            return 0;
        }

        if (IPlayer.GetClass() == 2 &&
                  (s == 46 || s == 48 || s == 70 || s == 71 || s == 82 || s == 87
                || s == 88 || s == 89 || s == 90 || s == 91 || s == 92 || s == 93
                || s == 94 || s == 95 || s == 79)) {
            return 0;
        }

        if (IPlayer.GetClass() == 3 &&
                  (s == 37 || s == 50 || s == 70 || s == 87 || s == 88 || s == 89
                || s == 90 || s == 91 || s == 92 || s == 93 || s == 94 || s == 95
                || s == 79)) {
            return 0;
        }

        if (IPlayer.GetClass() == 4 &&
                  (s == 30 || s == 35 || s == 43 || s == 70 || s == 71 || s == 87
                || s == 88 || s == 89 || s == 90 || s == 91 || s == 92 || s == 93
                || s == 94 || s == 95 || s == 79)) {
            return 0;
        }
    }

    return CSkill::LearnSkillCheck(SkillPointer, s);
}

void __fastcall AutoLearn(void *SkillPointer, void *edx, int Value)
{
    IChar IPlayer((void*)*(DWORD*)SkillPointer);

    if (!IPlayer.IsOnline())
    {
        CPlayer::LevelUpUnknown(SkillPointer, Value);
        return;
    }

    int OTP = IPlayer.GetSkillPointer(87);
    int EVA = IPlayer.GetSkillPointer(88);
    int DEF = IPlayer.GetSkillPointer(89);

    if (IPlayer.GetLevel() >= 82 && OTP)
    {
        ISkill xSkill((void*)OTP);
        int CheckGrade = 0;

        if (IPlayer.GetLevel() >= 100) {
            CheckGrade = 20;
        }
        else {
            CheckGrade = IPlayer.GetLevel() - 80;
        }

        for (int i = 0; i <= CheckGrade; i++)
        {
            if (xSkill.GetGrade() < 20 && xSkill.GetGrade() + 1 <= CheckGrade)
            {
                CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 87, xSkill.GetGrade() + 1, 56);
                CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 85, xSkill.GetGrade() + 1);
                *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                IPlayer.AddOTP(8);
            }
        }
    }

    if (IPlayer.GetLevel() >= 82 && EVA)
    {
        ISkill xSkill((void*)EVA);
        int CheckGrade = 0;

        if (IPlayer.GetLevel() >= 100) {
            CheckGrade = 20;
        }
        else {
            CheckGrade = IPlayer.GetLevel() - 80;
        }

        for (int i = 0; i <= CheckGrade; i++)
        {
            if (xSkill.GetGrade() < 20 && xSkill.GetGrade() + 1 <= CheckGrade)
            {
                CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 88, xSkill.GetGrade() + 1, 56);
                CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 86, xSkill.GetGrade() + 1);
                *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                IPlayer.AddEva(6);
            }
        }
    }

    if (IPlayer.GetLevel() >= 82 && DEF)
    {
        ISkill xSkill((void*)DEF);
        int CheckGrade = 0;

        if (IPlayer.GetLevel() >= 100) {
            CheckGrade = 20;
        }
        else {
            CheckGrade = IPlayer.GetLevel() - 80;
        }

        for (int i = 0; i <= CheckGrade; i++)
        {
            if (xSkill.GetGrade() < 20 && xSkill.GetGrade() + 1 <= CheckGrade)
            {
                CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 89, xSkill.GetGrade() + 1, 56);
                CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 87, xSkill.GetGrade() + 1);
                *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                IPlayer.AddDef(7);
            }
        }
    }

    if (IPlayer.GetClass() == 3 && IPlayer.GetLevel() >= 60
        && IPlayer.GetSpecialty() >= 3)
    {
        int pSkill = IPlayer.GetSkillPointer(37);

        if (!pSkill)
        {
            CSkill::LearnSkill(SkillPointer, 37);
            IPlayer.IncreaseCritRate(1);
            IPlayer.IncreaseCritDamage(2);
        }
    }

    if (IPlayer.GetClass() == 0 && IPlayer.GetLevel() >= 51
        && (IPlayer.GetSpecialty() == 11 || IPlayer.GetSpecialty() == 43))
    {
        int pSkill = IPlayer.GetSkillPointer(44);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = 0;

            if (IPlayer.GetLevel() >= 54) {
                CheckGrade = 5;
            }
            else {
                CheckGrade = IPlayer.GetLevel() - 49;
            }

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 5 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 44, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 44, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                }
            }
        }
    }

    if (IPlayer.GetLevel() >= 81 && IPlayer.GetSpecialty() == 23)
    {
        int pSkill = IPlayer.GetSkillPointer(90);

        if (!pSkill) {
            CSkill::LearnSkill(SkillPointer, 90);
        }

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = 1;

            if (IPlayer.GetLevel() >= 91) {
                CheckGrade = 3;
            }
            else if (IPlayer.GetLevel() >= 86) {
                CheckGrade = 2;
            }

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 3 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 90, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 90, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                }
            }
        }
    }

    if (IPlayer.GetLevel() >= 81 && IPlayer.GetSpecialty() == 43)
    {
        int pSkill = IPlayer.GetSkillPointer(91);

        if (!pSkill) {
            CSkill::LearnSkill(SkillPointer, 91);
        }

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = 1;

            if (IPlayer.GetLevel() >= 91) {
                CheckGrade = 3;
            }
            else if (IPlayer.GetLevel() >= 86) {
                CheckGrade = 2;
            }

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 3 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 91, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 91, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                }
            }
        }
    }

    if (IPlayer.GetLevel() >= 81 && IPlayer.GetSpecialty() == 23)
    {
        int pSkill = IPlayer.GetSkillPointer(92);

        if (!pSkill) {
            CSkill::LearnSkill(SkillPointer, 92);
        }

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = 1;

            if (IPlayer.GetLevel() >= 91) {
                CheckGrade = 3;
            }
            else if (IPlayer.GetLevel() >= 86) {
                CheckGrade = 2;
            }

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 3 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 92, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 92, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                }
            }
        }
    }

    if (IPlayer.GetLevel() >= 81 && IPlayer.GetSpecialty() == 43)
    {
        int pSkill = IPlayer.GetSkillPointer(93);

        if (!pSkill) {
            CSkill::LearnSkill(SkillPointer, 93);
        }

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = 1;

            if (IPlayer.GetLevel() >= 91) {
                CheckGrade = 3;
            }
            else if (IPlayer.GetLevel() >= 86) {
                CheckGrade = 2;
            }

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 3 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 93, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 93, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                }
            }
        }
    }

    if (IPlayer.GetClass() != 2 && IPlayer.GetLevel() >= 86
        && IPlayer.GetSpecialty() >= 23)
    {
        int pSkill = IPlayer.GetSkillPointer(94);

        if (!pSkill)
        {
            CSkill::LearnSkill(SkillPointer, 94);
            IPlayer.IncreaseCritRate(5);
            IPlayer.IncreaseCritDamage(5);
        }

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = 1;

            if (IPlayer.GetLevel() >= 91) {
                CheckGrade = 2;
            }

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 2 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 94, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 94, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                    IPlayer.IncreaseCritRate(5);
                    IPlayer.IncreaseCritDamage(5);
                }
            }
        }
    }

    if (IPlayer.GetLevel() >= 85 && IPlayer.GetSpecialty() >= 23)
    {
        int pSkill = IPlayer.GetSkillPointer(95);

        if (!pSkill) {
            CSkill::LearnSkill(SkillPointer, 95);
        }

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = IPlayer.GetLevel() - 84;

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 10 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 95, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 95, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                }
            }
        }
    }

    if (IPlayer.GetLevel() >= 81 && IPlayer.GetSpecialty() >= 23)
    {
        int pSkill = IPlayer.GetSkillPointer(79);

        if (!pSkill) {
            CSkill::LearnSkill(SkillPointer, 79);
        }

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = IPlayer.GetLevel() - 80;
            sendSkill(CheckGrade, 79, 10, SkillPointer);
        }
    }

    if (IPlayer.GetClass() == 3 && IPlayer.GetLevel() >= 61
        && IPlayer.GetSpecialty() >= 3)
    {
        int pSkill = IPlayer.GetSkillPointer(37);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = IPlayer.GetLevel() - 59;

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 8 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    IPlayer.IncreaseCritRate(1);
                    IPlayer.IncreaseCritDamage(2);
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 37, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 37, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                }
            }
        }
    }

    if (((IPlayer.GetClass() == 0 &&
                (IPlayer.GetSpecialty() == 23 || IPlayer.GetSpecialty() == 43)) ||
            (IPlayer.GetClass() == 1 &&
                IPlayer.GetSpecialty() == 23) ||
            (IPlayer.GetClass() == 2 &&
                (IPlayer.GetSpecialty() == 23 ||
                    IPlayer.GetSpecialty() == 43)) ||
            (IPlayer.GetClass() == 3 &&
                (IPlayer.GetSpecialty() == 23 ||
                    IPlayer.GetSpecialty() == 43))) && IPlayer.GetLevel() >= 75)
    {
        int pSkill = IPlayer.GetSkillPointer(70);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = checkGrade(IPlayer.GetLevel());

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 7 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 70, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 70, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                    IPlayer.AddMaxAttack((IPlayer.GetMaxPhyAttack() * 4) / 100);
                    IPlayer.AddMinAttack((IPlayer.GetMaxPhyAttack() * 4) / 100);
                }
            }
        }
    }

    if (IPlayer.GetClass() == 1 && IPlayer.GetSpecialty() == 43
        && IPlayer.GetLevel() >= 75)
    {
        int pSkill = IPlayer.GetSkillPointer(71);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = checkGrade(IPlayer.GetLevel());
            sendSkill(CheckGrade, 71, 7, SkillPointer);
        }
    }

    if (IPlayer.GetClass() == 1 && IPlayer.GetLevel() >= 71
        && IPlayer.GetSpecialty() == 23)
    {
        int pSkill = IPlayer.GetSkillPointer(64);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = 0;

            if (IPlayer.GetLevel() >= 75) {
                CheckGrade = 6;
            }
            else {
                CheckGrade = IPlayer.GetLevel() - 69;
            }
            sendSkill(CheckGrade, 64, 6, SkillPointer);
        }
    }

    if ((IPlayer.GetClass() == 3 || IPlayer.GetClass() == 4)
        && IPlayer.GetLevel() >= 55)
    {
        int pSkill = IPlayer.GetSkillPointer(30);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = 0;

            if (IPlayer.GetLevel() >= 70) {
                CheckGrade = 5;
            }
            else if (IPlayer.GetLevel() >= 65) {
                CheckGrade = 4;
            }
            else if (IPlayer.GetLevel() >= 60) {
                CheckGrade = 3;
            }
            else if (IPlayer.GetLevel() >= 55) {
                CheckGrade = 2;
            }

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 5 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 30, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 30, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                    IPlayer.IncreaseMaxHp(5 * IPlayer.GetHth());
                }
            }
        }
    }

    if (IPlayer.GetClass() == 4 && IPlayer.GetSpecialty() == 23
        && IPlayer.GetLevel() >= 75)
    {
        int pSkill = IPlayer.GetSkillPointer(70);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = checkGrade(IPlayer.GetLevel());

            if (IPlayer.GetLevel() >= 100) {
                CheckGrade = 7;
            }
            else if (IPlayer.GetLevel() >= 95) {
                CheckGrade = 6;
            }
            else if (IPlayer.GetLevel() >= 90) {
                CheckGrade = 5;
            }
            else if (IPlayer.GetLevel() >= 85) {
                CheckGrade = 4;
            }
            else if (IPlayer.GetLevel() >= 80) {
                CheckGrade = 3;
            }
            else if (IPlayer.GetLevel() >= 75) {
                CheckGrade = 2;
            }

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 7 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 70, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 70, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                    IPlayer.AddMaxAttack((IPlayer.GetMaxPhyAttack() * 4) / 100);
                    IPlayer.AddMinAttack((IPlayer.GetMaxPhyAttack() * 4) / 100);
                }
            }
        }
    }

    if (IPlayer.GetClass() == 4 && IPlayer.GetSpecialty() == 43 && IPlayer.GetLevel() >= 75)
    {
        int pSkill = IPlayer.GetSkillPointer(71);

        if (pSkill)
        {
            ISkill xSkill((void*)pSkill);
            int CheckGrade = checkGrade(IPlayer.GetLevel());

            for (int i = 0; i <= CheckGrade; i++)
            {
                if (xSkill.GetGrade() < 7 && xSkill.GetGrade() + 1 <= CheckGrade)
                {
                    CDBSocket::Write(10, "ddbw", IPlayer.GetPID(), 71, xSkill.GetGrade() + 1, 56);
                    CPlayer::Write(IPlayer.GetOffset(), 81, "bb", 71, xSkill.GetGrade() + 1);
                    *(DWORD*)((int)xSkill.GetOffset() + 8) = xSkill.GetGrade() + 1;
                    IPlayer.AddMaxAttack((IPlayer.GetMaxPhyAttack() * 4) / 100);
                    IPlayer.AddMinAttack((IPlayer.GetMaxPhyAttack() * 4) / 100);
                }
            }
        }
    }

    CPlayer::LevelUpUnknown(SkillPointer, Value);
}
