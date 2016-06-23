#include "Summon.h"

std::vector<Monster> monsters;	
std::vector<MonsterGenInfo> info_monsters;	

std::vector<int> monster_ids;	

void spawn_monster(int Monsterindex, int x, int y, int map, unsigned int time, int respawn)
{
	;
	GenMonster genMonster; 
	MonsterGenInfo info;
	int monster_id = rand() % 1000000 + 1000000; //Can maybe cause probs
	genMonster.ID = monster_id;
	genMonster.unk_0 = 0x4B7DC8; 
	genMonster.unk_4 = 1;
	genMonster.unk_8 = 1; 
	genMonster.unk_72 = *(DWORD*)0x4E2738;
	genMonster.unk_80 = 1000; 
	genMonster.Index = Monsterindex;
	genMonster.Map = map; 
	genMonster.X1 = x;
	genMonster.Y1 = y; 
	genMonster.X2 = x; 
	genMonster.Y2 = y;

	Monster monster = Monster(Server::CMonster::Create(&genMonster,0));
	
	info.Monsterindex = Monsterindex;
	info.x = x;
	info.y = y;
	info.time = time;
	info.map = map;
	info.respawn = respawn;

	monsters.push_back(monster);
	info_monsters.push_back(info);
  monster_ids.push_back(monster.GetID());

	monster.SetTime(time);
	Sleep(10);
	
}

void __fastcall MonsterOnDie(void* monsterp, void *_edx)
{
	Server::CChar::CancelAllBuff(monsterp);

	for (int i = 0; i < monsters.size(); i++)
		if (monsters.at(i).thispointer == monsterp)
		{
			if (info_monsters.at(i).respawn == 1 &&  GetTickCount() <= monsters.at(i).GetTime())
			{
				spawn_monster(info_monsters.at(i).Monsterindex,
					info_monsters.at(i).x,
					info_monsters.at(i).y,
					info_monsters.at(i).map,
					info_monsters.at(i).time,
					info_monsters.at(i).respawn);
			}
			monsters.erase(monsters.begin()+i);
			info_monsters.erase(info_monsters.begin()+i);
		}
}


//Selber über die Monster Liste iterieren! Da sonst Problem mit pointer kill und maincrash
void __fastcall SpawnTimer(void* crit, void *_edx)
{
	for (int i = 0; i < monster_ids.size(); i++)
	{
		/**Monster monster = Monster(Server::CMonster::FindMonster(monster_ids.at(i)));
		if (monster.thispointer)
		{
		if (  GetTickCount() >= monster.GetTime())
		{
			monsters.at(i).Die();

			monster_ids.erase(monster_ids.begin()+i);
		}
		}
		
		**/
			
		//	monsters.at(i).SetGstate(1);
		//	Sleep(10);
		//	monsters.erase(monsters.begin()+i);
		//	info_monsters.erase(info_monsters.begin()+i);
		
	}
	Server::CIOCriticalSection::Enter(crit);
}


int first_call = 1;
void Summon::spwan_alt(int Monsterindex, int x, int y, int map, int amount, int time, int respawn) 
{ 
	if (first_call)
	{
		IMemory *memory = new IMemory;
		memory->Set(0x0043A1EE, "\x8B\x45\xFC\x90\x90", 5); //Return Monster Pointer Hook
		memory->Hook(0x004423DB,MonsterOnDie);
		memory->Hook(0x00438BB7,SpawnTimer); // CPlayerObject__OnTimer Hook (immer darauf achten nicht bei push epb hooken) 
		first_call = 0;
		delete memory;
	}
	for (int i = 0; i < amount; i++)
		spawn_monster(Monsterindex,x,y,map,GetTickCount()+(1000*time),respawn);
} 


void Summon::spawn(int Monsterindex, int x, int y, int map, int amount, int spawntime)
{
	IMemory *Memory = new IMemory;

	Memory->Dereference((DWORD)0x0044402B,(DWORD)Monsterindex);
	Memory->Dereference((DWORD)0x004440A6,(DWORD)x);
	Memory->Dereference((DWORD)0x004440AD,(DWORD)y);
	Memory->Dereference((DWORD)0x004440BA,(DWORD)map);
	Memory->Dereference((DWORD)0x00444129,(DWORD)spawntime);

	for (int i = 0; i < amount; i++)
	{
		__asm push 0
		__asm mov edx, 0x00443FD0
		__asm call edx
		__asm add esp, 4 
	}
	delete Memory;
}


/**

void __stdcall OnTimer(int a1)
{
Server::CPlayerObject::OnTimer(a1);

for (int i = 0; i < monsters.size(); i++)
{
if (  GetTickCount() >= monsters.at(i).GetTime())
{
monsters.at(i).Die();
monsters.erase(monsters.begin()+i);
Server::Console::WriteBlue("Monster Died!");
}
}
}



MONSTER Iterate
CIOCriticalSection__Enter((struct _RTL_CRITICAL_SECTION *)(this + 16));
CIOCriticalSection__Enter((struct _RTL_CRITICAL_SECTION *)(v4 + 48));
CLink__MoveTo((void *)(v4 + 88), v4 + 80);
CIOCriticalSection__Leave(v4 + 48);
v5 = *(_DWORD *)(v4 + 80);
while ( v5 != v4 + 80 )
{
v3 = v5 - 428;
v5 = *(_DWORD *)v5;
(*(void (__thiscall **)(int))(*(_DWORD *)v3 + 208))(v3);
}
CIOCriticalSection__Leave(v4 + 16);
CIOObject__AddTimer(v4, 1000, 1);
**/