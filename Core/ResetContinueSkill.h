void __fastcall ResetContinueSkill(IChar IPlayer)
{
    if (IPlayer.IsOnline())
    {
        if (IPlayer.IsValid() && IPlayer.IsBuff(300)) {
            return;
        }

        if (CheckContinueSkill.count(IPlayer.GetPID()))
        {
            CheckContinueSkill[IPlayer.GetPID()].PlayerX = 0;
            CheckContinueSkill[IPlayer.GetPID()].PlayerY = 0;
            CheckContinueSkill[IPlayer.GetPID()].PlayerTarget = 0;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = 0;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillID = 0;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
            CheckContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 0;
            IPlayer.CouldntExecuteSkill();
        }
    }
}

void __fastcall ResetFarContinueSkill(IChar IPlayer)
{
    if (IPlayer.IsOnline())
    {
        CheckFarContinueSkill[IPlayer.GetPID()].PlayerTarget = 0;
        CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillID = 0;
        CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 0;
        CheckFarContinueSkill[IPlayer.GetPID()].PlayerDamage = 0;
        CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
        CheckFarContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = 0;
    }
}

void __fastcall ResetRuptureContinueSkill(IChar IPlayer)
{
    if (IPlayer.IsOnline())
    {
        CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerTarget = 0;
        CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillID = 0;
        CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillCount = 0;
        CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillDelay = 0;
        CheckRuptureContinueSkill[IPlayer.GetPID()].PlayerSkillGrade = 0;
    }
}