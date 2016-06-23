#include <Windows.h>
#include "Utilities.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


namespace MadEvent 
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			readConfig();
			Server::Console::WriteBlue("[MadEvent started]");
		}
	}
	namespace CPlayerObject
	{
		void __stdcall OnTimer(int a1)
		{
			Server::CPlayerObject::OnTimer(a1);
			EventCheck();
		}
	}
}

	