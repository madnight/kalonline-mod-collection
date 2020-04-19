void __fastcall ArmorBreaker(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(22);

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

        if (IPlayer.IsValid() && pTarget && nSkillGrade)
        {
            if (pTarget == IPlayer.GetOffset())
                return;

            int nMana = (30 * nSkillGrade) + 35;
            IChar Target(pTarget);

            if (IPlayer.GetCurMp() < nMana)
                return;

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!CanAttack(IPlayer.GetOffset(),0,(int)Target.GetOffset(),0))
                    return;

                if (!IPlayer.IsInRange(Target,300))
                    return;

                IPlayer.DecreaseMana(nMana);

                if (!Target.IsBuff(342))
                {
                    Target.SendGStateEx(Target.GetGStateEx()+131072);
                    Target.Buff(342,9,0);
                }

                IPlayer.SetDirection(Target);
                IPlayer._ShowBattleAnimation(Target,22,nSkillGrade);
            }
        }
    }
}