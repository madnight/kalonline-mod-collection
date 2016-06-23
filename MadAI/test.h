
void __fastcall Hooked_ChatCommand(void *thispointer, void *_edx, char *comm) 
{
	Player *player = new Player(thispointer);
	std::string command = comm;

	Server::Console::WriteRed("The Command: %s used by Player: %s",
		command.c_str(), player->GetName());

	if (command == "/MapPoint") 
		Server::Console::WriteBlue("nMap Print [%d]", player->GetMap());

	if (command == "/MyInfo")
	{
		Server::Console::WriteBlue("Your level is: [%d], Pid is: [%d], Type is: [%d], 
			CurHp is: [%d], CurMp is: [%d], SpeedUp is: [%d],  Admin is: [%d]",
			player->GetLevel(),player->GetPid(),player->getType(),player->GetCurHp()
			,player->GetCurMp(),player->GetSpeed(),player->GetAdmin());
	}

	if (command == "/emok")
		player->Teleport(0,339772,257384);

	if (command == "/fort")
		player->Teleport(0,267634,243008);

	if (command == "/Naroo")
		player->Teleport(0,257303,258710);

	if (command == "/cargo")
		player->Teleport(0,264931,262029);

	if (command == "/mine")
		player->Teleport(0,265642,285434);

	if (command == "/bird")
		player->Teleport(0,256442,288522);

	if (command == "/cop")
		player->Teleport(0,232828,294721);

	if (command == "/d1")
		player->Teleport(0,50684,34099);

	if (command == "/d3")
		player->Teleport(0,281325,249715);

	if (command == "/valley")
		player->Teleport(0,335622,340432);

	if (command =="/Money")
	{
		int index =31; // <--Money
		int amount = 500000000;
		Server::CItem::InsertItem(thispointer,21,index,0,amount,-1);
	}

	Server::CPlaywr::ChatCommand(thispointer,comm); // All onther commands work now
}