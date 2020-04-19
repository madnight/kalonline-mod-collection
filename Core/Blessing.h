void __fastcall Blessing(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(69);

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

        if (pTarget && nSkillGrade && IPlayer.IsValid())
        {
            int nMana = nSkillGrade * 10 + 400;
            IChar Target(pTarget);

            if (IPlayer.GetCurMp() < nMana)
                return;

            if(IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target,300))
                    return;

                if(IPlayer.GetID() != Target.GetID())
                {
                    Target.Buff(24,(nSkillGrade*3)+3,40);
                    Target.RemoveBuffIcon(0,0,703,34);
                    CChar::AddMState(Target.GetOffset(),0,2147483648);
                }

                IPlayer.Buff(24,(nSkillGrade*3)+3,40);
                IPlayer.RemoveBuffIcon(0,0,703,34);
                CChar::AddMState(IPlayer.GetOffset(),0,2147483648);
                IPlayer._ShowBattleAnimation(Target,69);
                IPlayer.DecreaseMana(nMana);
            }
        }
    }
}