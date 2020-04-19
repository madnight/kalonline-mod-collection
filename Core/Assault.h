void __fastcall Assault(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(7);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);

        if (bType == 0 && nTargetID)
            pTarget = CPlayer::FindPlayer(nTargetID);

        if (bType == 1 && nTargetID)
            pTarget = CMonster::FindMonster(nTargetID);

        if (bType >= 2)
            return;

        if (pTarget && nSkillGrade && IPlayer.IsValid())
        {
            int nMana = nSkillGrade * 20 + 25;
            IChar Target(pTarget);

            if (pTarget == IPlayer.GetOffset())
                return;

            if (IPlayer.GetCurMp() < nMana)
                return;

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                if (IPlayer.CheckHit(Target, 20))
                {
                    int nDmg = ((IPlayer.GetAttack() + 128) * TAssMul) + (nSkillGrade * CTools::Rate(TAssMin,TAssMax));

                    if (Target.GetType() == 0)
                        nDmg = (nDmg * TAssReduce) / 100;

                    IPlayer.OktayDamageSingle(Target,nDmg,7);
                } else {
                    IPlayer._ShowBattleMiss(Target,7);
                }

                IPlayer.SetDirection(Target);
                IPlayer._ShowBattleAnimation(Target, 7);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}