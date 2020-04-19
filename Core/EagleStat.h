void __fastcall TransformApplySpec(void *Item, void *edx, int Player)
{
	IChar IPlayer((void*)Player);
	IItem IItem(Item);

	if (!IPlayer.IsOnline())
		return;

	if (IItem.CheckIndex() == 1596)
	{
		int EggGrade = *(DWORD*)((int)Item + 92);
		IPlayer.AddHp((EggGrade / 2) + 1);
		IPlayer.AddWis((EggGrade / 4) + 1);
		IPlayer.AddAgi((EggGrade / 6) + 1);
	} else {
		CItemTransform::ApplySpec(Item,Player);
	}
}

void __fastcall TransformFreeSpec(void *Item, void *edx, int Player)
{
	IChar IPlayer((void*)Player);
	IItem IItem(Item);

	if (!IPlayer.IsOnline())
		return;

	if (IItem.CheckIndex() == 1596)
	{
		int EggGrade = *(DWORD*)((int)Item + 92);
		IPlayer.RemoveHp((EggGrade / 2) + 1);
		IPlayer.RemoveWis((EggGrade / 4) + 1);
		IPlayer.RemoveAgi((EggGrade / 6) + 1);
	} else {
		CItemTransform::FreeSpec(Item,Player);
	}
}