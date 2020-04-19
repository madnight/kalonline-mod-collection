void __fastcall Confusion(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(9);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (int)(20 * nSkillGrade + 10);

        if (bType == 0 && nTargetID)
            pTarget = CPlayer::FindPlayer(nTargetID);

        if (bType == 1 && nTargetID)
            pTarget = CMonster::FindMonster(nTargetID);

        if (bType >= 2)
            return;

        if (IPlayer.IsValid() && pTarget && nSkillGrade)
        {
            if (IPlayer.GetCurMp() < nMana)
                return;

            if (pTarget == IPlayer.GetOffset())
                return;

            IChar Target(pTarget);

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                if (IPlayer.CheckHit(Target, 10))
                {
                    if (Target.GetType() == 1)
                        Target.Buff(7,2+(nSkillGrade*2),0);
                    else
                        Target.Buff(7,2+(nSkillGrade),0);

                    if (!Target.IsBuff(356))
                        Target.SendGStateEx(Target.GetGStateEx()+64);

                    Target.Buff(356,2+(nSkillGrade*2),0);
                } else {
                    IPlayer._ShowBattleMiss(Target, 9);
                }

                IPlayer.SetDirection(Target);
                IPlayer._ShowBattleAnimation(Target,9,nSkillGrade);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}