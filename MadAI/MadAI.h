/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
#include "../Server.h"

#include <Monster.h>

namespace MadAI
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Server::Console::WriteBlue("[MadAI started]");
		}
	}

	namespace CMonsterReal
	{

		void __fastcall AI (void *monsterpointer, void* _edx) 
		{
			Monster *monster = new Monster(monsterpointer);

			if ( ! Server::CMonster::IsRemoved(monsterpointer) )
			{
				if ( ! Server::CChar::IsGState( monsterpointer, 1) )
				{
					Server::CChar::Lock(monsterpointer);

					if ( monster->Get164() == 1 && monster->Get120()  == 1 )
					{
						if ( monster->Get119() == 1 )
						{
							void *target;
							target = Server::CMonsterReal::ScanSight(monsterpointer);
							if ( target )
								(*(void (__thiscall **)(void *, void*))(*(_DWORD *)monsterpointer + 188))(monsterpointer, target);
						}
					}

					if ( monster->GetState() )
					{
						if ( ! Server::CChar::IsNormal( monster->GetState() ) )
						{
							(*(void (__thiscall **)(void*, void*))(*(_DWORD *)monsterpointer + 132))(monsterpointer, monster->GetState() );
							(*(void (__thiscall **)(void*, _DWORD))(*(_DWORD *)monsterpointer + 188))(monsterpointer, 0);
						}
					}

					switch ( monster->GetAI() )
					{
					case 1:
					case 2:
					case 3:
					case 7:
						(*(void (__thiscall **)(void*))(*(_DWORD *)monsterpointer + 248))(monsterpointer);
						break;
					case 4:
						(*(void (__thiscall **)(void*))(*(_DWORD *)monsterpointer + 244))(monsterpointer);
						break;
					default:
						break;
					}
					Server::CChar::Unlock(monsterpointer);
				}
			}
			delete monster;
		}
	}
}