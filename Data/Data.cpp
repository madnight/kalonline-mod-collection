#include <Windows.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <strstream>
#include <sstream>
#include <comdef.h>
#include <wbemidl.h>
#include <process.h>
#pragma pack(1)
HINSTANCE hL = 0;
FARPROC p[806] = {0};
#pragma warning(disable: 4018)
#pragma comment(lib,"wbemuuid.lib")
#pragma comment(lib,"Detours/enigma_ide.lib")
#pragma comment(lib,"Detours/detours.lib")
#include "Detours/enigma_ide.h"
#include "Detours/detours.h"
#include "Exports.h"
#include "MD5.h"
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include "Interface.h"
#include "Memory.h"
#include "Functions.h"
#include "StorageFix.h"
#include "SetMaxPacket.h"
#include "Packet.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			InitializeADVAPI32();
			SetMaxPacket();
			DetourTransactionBegin();
			DetourAttach(&(PVOID&)StorageInfo, StorageFix);
			DetourAttach(&(PVOID&)Process, DBProcess);
			DetourTransactionCommit();
			break;
		}
	case DLL_PROCESS_DETACH:
		{
			FinalizeADVAPI32();
			SetMaxPacket();
			DetourTransactionBegin();
			DetourDetach(&(PVOID&)StorageInfo, StorageFix);
			DetourDetach(&(PVOID&)Process, DBProcess);
			DetourTransactionCommit();
			break;
		}
	}
	return TRUE;
}