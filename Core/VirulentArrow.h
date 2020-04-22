void __fastcall VirulentArrow(IChar IPlayer, int pPacket, int pPos)
{
    int pSkill = IPlayer.GetSkillPointer(50);

    if (IPlayer.IsValid() && pSkill)
    {
        ISkill xSkill((void*)pSkill);
        int nSkillGrade = xSkill.GetGrade();
        int nTargetID = 0;
        char bType = 0;
        void *pTarget = 0;
        CPacket::Read((char*)pPacket, (char*)pPos, "bd", &bType, &nTargetID);
        int nMana = (int)(((((nSkillGrade - 1) + 25) * nSkillGrade) + 230) * 0.98);

        if (bType == 0 && nTargetID) {
            pTarget = CPlayer::FindPlayer(nTargetID);
        }

        if (bType == 1 && nTargetID) {
            pTarget = CMonster::FindMonster(nTargetID);
        }

        if (bType >= 2) {
            return;
        }

        if (pTarget && nSkillGrade && IPlayer.IsValid())
        {
            IChar Target(pTarget);

            if (IPlayer.GetCurMp() < nMana) {
                return;
            }

            if (pTarget == IPlayer.GetOffset()) {
                return;
            }

            if (IPlayer.IsValid() && Target.IsValid())
            {
                if (!IPlayer.IsInRange(Target, 300)) {
                    return;
                }

                int Item = CPlayer::FindItem(IPlayer.Offset, 360, 2);

                if (Item)
                    (*(int (__thiscall **)(DWORD, void *, signed int, signed int))
                        (*(DWORD*)Item + 120))(Item, IPlayer.GetOffset(), 9, -2);
                else {
                    return;
                }

                IPlayer.DecreaseMana(nMana);
                IPlayer._ShowBattleAnimation(Target, 50);
                IPlayer.SetDirection(Target);
                int Around = Target.GetObjectListAround(4);
                int nDmg = (IPlayer.GetAttack() * AVAMul) + (nSkillGrade * CTools::Rate(AVAMin,
                            AVAMax));

                while (Around)
                {
                    IChar Object((void*)*(DWORD*)Around);

                    if (Object.IsValid() && IPlayer.IsValid() &&
                        (*(int (__thiscall **)(int, int, DWORD))
                            (*(DWORD *)IPlayer.GetOffset() + 176))
                        ((int)IPlayer.GetOffset(), (int)Object.GetOffset(), 0))
                    {
                        if (Object.GetType() == 0) {
                            nDmg = nDmg * AVAReduce / 100;
                        }

                        if (Object.GetType() == 0) {
                            IPlayer.OktayDamageArea(Object, IPlayer.GetAttack(), 50);
                        }

                        if (Object.GetType() == 1) {
                            IPlayer.OktayDamageArea(Object, IPlayer.GetAttack()*xSkill.GetGrade(), 50);
                        }

                        Object.Buff(11, 10, nDmg);
                    }

                    Around = CBaseList::Pop((void*)Around);
                }
            }
        }
    }
}
