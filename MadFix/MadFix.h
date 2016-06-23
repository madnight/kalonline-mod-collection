#include "Windows.h"
#include <MainPlayer.h>
#include <process.h>

namespace MadFix
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			Server::Console::WriteBlue("[MadMultiCore started]");
		}
	}
	namespace CMonsterObject
	{
		struct ThreadParams
		{
			void* thisp;
			DWORD v5;
		};

		unsigned int __stdcall MonsterThread(void* data)
		{
			void* thisp = ((ThreadParams*)data)->thisp;
			DWORD v5 = ((ThreadParams*)data)->v5;
			 while ( v5 !=  (unsigned int) (char*)thisp + 80 )
			 {
				 void* v3;
				 __asm mov eax, v5
				 __asm sub eax, 428
				 __asm mov v3, eax
				 v5 = *(DWORD *)v5;
				 __asm mov eax, v3
				 __asm mov edx, [eax]
				 __asm mov ecx, v3
				 __asm call dword ptr [edx+208]
			 }
			return 0;
		}

		unsigned int __stdcall MonsterThreadSec(void* data)
		{
			void* thisp = ((ThreadParams*)data)->thisp;
			DWORD v6 = ((ThreadParams*)data)->v5;
			while ( v6 !=  (unsigned int) (char*)thisp + 80 )
			{
				void* v2;
				__asm mov eax, v6
				__asm sub eax, 428
				__asm mov v2, eax
				v6 = *(DWORD *)v6;
				__asm mov eax, v2
				__asm mov edx, [eax]
				__asm mov ecx, v2
				__asm call dword ptr [edx+204]

			}
			return 0;
		}


		void __fastcall OnTimer(void* thisp, void* __edx, int a2)
		{
			int v2,v3,v6,v7;
			DWORD v8;

			if ( a2 )
			{
				if ( a2 == 1 )
				{
					Server::CIOCriticalSection::Enter((struct _RTL_CRITICAL_SECTION *)((char*)thisp + 16));
					Server::CIOCriticalSection::Enter((struct _RTL_CRITICAL_SECTION *)((char*)thisp + 48));
					Server::CLink::MoveTo((void *)((char*)thisp + 88), (int)(char*)thisp + 80);
					Server::CIOCriticalSection::Leave((char*)thisp + 48);

					DWORD v5;
					__asm mov eax, thisp
					__asm mov ecx, [eax+80]
					__asm mov v5, ecx


					ThreadParams* x = (ThreadParams*)malloc(sizeof(ThreadParams));

					x->thisp = thisp;
					x->v5 = v5;

					_beginthreadex(NULL, 0, MonsterThread, x, NULL, NULL);
			/**		while ( v5 !=  (unsigned int) (char*)thisp + 80 )
					{
						void* v3;
						__asm mov eax, v5
						__asm sub eax, 428
						__asm mov v3, eax
						v5 = *(DWORD *)v5;
						__asm mov eax, v3
						__asm mov edx, [eax]
						__asm mov ecx, v3
						__asm call dword ptr [edx+208]
					}
				**/
					Server::CIOCriticalSection::Leave((char*)thisp + 16);
					Server::CIOObject::AddTimer(thisp, 1000, 1);
				}
			}
			else
			{
				if ( !*(DWORD *)((char*)thisp + 96) )
				{
					//CMonsterBigBirdMother__Create();
					//*(_DWORD *)(v4 + 96) = 1;
				}
				v8 = GetTickCount();
				do
				{
					v7 = v8 + 30;
					Server::CIOCriticalSection::Enter((struct _RTL_CRITICAL_SECTION *)((char*)thisp + 16));
					Server::CIOCriticalSection::Enter((struct _RTL_CRITICAL_SECTION *)((char*)thisp + 48));
					Server::CLink::MoveTo((void *)((char*)thisp + 88), (int)(char*)thisp + 80);
					Server::CIOCriticalSection::Leave((char*)thisp + 48);

					DWORD v6;
					__asm mov eax, thisp
					__asm mov ecx, [eax+80]
					__asm mov v6, ecx

					ThreadParams* x = (ThreadParams*)malloc(sizeof(ThreadParams));

					x->thisp = thisp;
					x->v5 = v6;

					_beginthreadex(NULL, 0, MonsterThreadSec, x, NULL, NULL);
				/**	while ( v6 !=  (unsigned int) (char*)thisp + 80 )
					{
						void* v2;
						__asm mov eax, v6
						__asm sub eax, 428
						__asm mov v2, eax
						v6 = *(DWORD *)v6;
						__asm mov eax, v2
						__asm mov edx, [eax]
						__asm mov ecx, v2
						__asm call dword ptr [edx+204]

					}
				**/	
					Server::CIOCriticalSection::Leave((char*)thisp + 16);
					v8 = GetTickCount();
				}
				while ( v7 <= v8 );
				Server::CIOObject::AddTimer(thisp, v7 - v8, 0);
			}
		}
	}
}