void __fastcall TherapeuticTouch(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(72);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (int)(((((xSkill.GetGrade() - 1) + 50) * xSkill.GetGrade()) + 100) * 1.98);

        if (bType == 0 && nTargetID)
            pTarget = CPlayer::FindPlayer(nTargetID);

        if (bType >= 1)
            return;

        if (IPlayer.GetCurMp() < nMana)
            return;

        if (pTarget && IPlayer.IsValid())
        {
            IChar Target(pTarget);

            if (!IPlayer.IsInRange(Target,300))
                return;

            if (IPlayer.IsValid() && Target.IsValid())
            {
                Target.Buff(45, 12, xSkill.GetGrade() * 120);
                Target.RemoveBuffIcon(0,0,803,59);
                IPlayer._ShowBattleAnimation(Target, 72);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}