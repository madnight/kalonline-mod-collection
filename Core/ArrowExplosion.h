void __fastcall ContinueArrowExplosion(IChar IPlayer)
{
    if (!IPlayer.IsValid())
    {
        ResetContinueSkill(IPlayer);
        return;
    }

    IPlayer.CancelBuff(300);

    void *pTarget = CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerTarget;
    int nSkillGrade = CheckContinueSkill.find(
            IPlayer.GetPID())->second.PlayerSkillGrade;

    if (!(nSkillGrade && pTarget &&
        CheckContinueSkill.find(IPlayer.GetPID())->second.PlayerSkillCount))
    {
        ResetContinueSkill(IPlayer);
        return;
    }
    CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount--;
    IChar Target(pTarget);

    if (!(IPlayer.IsValid() && Target.IsValid()))
    {
        ResetContinueSkill(IPlayer);
        return;
    }

    if (!IPlayer.IsInRange(Target, 300))
    {
        ResetContinueSkill(IPlayer);
        return;
    }

    int Around = Target.GetObjectListAround(3);

    while (Around)
    {
        IChar Object((void*)*(DWORD*)Around);

        if (Object.IsValid() && IPlayer.IsValid() &&
            (*(int (__thiscall **)
                    (int, int, DWORD))(*(DWORD *)IPlayer.GetOffset() + 176))
            ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
        {
            int nDmg = (IPlayer.GetAttack() * AAEMul) +
                (nSkillGrade * CTools::Rate(AAEMin, AAEMax));

            if (Object.GetType() == 0) {
                nDmg = (nDmg * AAEReduce) / 100;
            }

            IPlayer.OktayDamageArea(Object, nDmg, 49);
        }

        Around = CBaseList::Pop((void*)Around);
    }

    ResetContinueSkill(IPlayer);
    return;
}

void __fastcall ArrowExplosion(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(49);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = 20 + (IPlayer.GetLevel() * 4);

        if (bType == 0 && nTargetID) {
            pTarget = CPlayer::FindPlayer(nTargetID);
        }

        if (bType == 1 && nTargetID) {
            pTarget = CMonster::FindMonster(nTargetID);
        }

        if (bType >= 2) {
            return;
        }

        if (!(IPlayer.IsValid() && pTarget && nSkillGrade) {
            return;
        }

        IChar Target(pTarget);

        if (pTarget == IPlayer.GetOffset()) {
            return;
        }

        if (IPlayer.GetCurMp() < nMana) {
            return;
        }

        if (!(IPlayer.IsValid() && Target.IsValid()))
        {
            return;
        }
        if (!IPlayer.IsInRange(Target, 300)) {
            return;
        }

        IPlayer.DecreaseMana(nMana);
        IPlayer.SetDirection(Target);
        IPlayer._ShowBattleAnimation(Target, 49);
        IPlayer.Buff(300, 5, 0);
        Target.AddFxToTarget("davi_ef131_04", 1, 0, 0);
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 49;
        CheckContinueSkill[IPlayer.GetPID()].PlayerTarget = Target.GetOffset();
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = nSkillGrade;
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 1;
        CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = GetTickCount() + 3000;

        if (Target.IsValid() && Target.GetType() == 1 && Target.GetMobTanker()
            && Target.GetMobTanker() != (int)IPlayer.GetOffset()) {
            Target.SetMobHostility(0);
        }

        if (Target.GetType() == 1) {
            IPlayer.OktayDamageSingle(Target, CTools::Rate(500, 750), 42);
        }

        if (Target.IsValid() && Target.GetType() == 1
            && Target.GetMobTanker() == (int)IPlayer.GetOffset()) {
            Target.SetMobHostility(25000);
        }
    }
}
