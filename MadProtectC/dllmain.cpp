#pragma comment(lib, "detours.lib")
#pragma comment(lib, "Ws2_32.lib")

#undef UNICODE
#include <cstdio>
#include <Winsock2.h>
#include <ws2tcpip.h>
#include <detours.h> 
#include <process.h>
#include <MadCore.h>
#include <Interface.h>
#include <cstdlib> 
#include <Packets.h>
#include <wininet.h>
#include <curl.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <time.h>
#include "sha\rehash.h"
#include <sstream>
#include <Wincrypt.h>


#pragma comment(lib, "MadLib.lib")
#pragma pack(1)

HMODULE Engine = GetModuleHandle(NULL);

PIMAGE_NT_HEADERS phEngine;
size_t EngineCodeBase;
size_t EngineCodeEnd;

PIMAGE_NT_HEADERS phThis;
size_t ThisCodeBase;
size_t ThisCodeEnd;



HINSTANCE hLThis = 0;
HINSTANCE hL = 0;
HINSTANCE hLx = 0;
FARPROC p[119] = {0};

static int (__stdcall *DetourRecv)(SOCKET, char *, int, int) = (int (__stdcall*)(SOCKET, char *, int, int))0x0052F060;

char* crypt(char *Data)
{
	for(int i = 0; i<sizeof(Data);i++)
		Data[i] = Data[i] + 27;

	return Data;
}

HANDLE CreateConsole()
{
	int hConHandle = 0;
	HANDLE lStdHandle = 0;
	FILE *fp = 0;
	AllocConsole();
	lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
	return lStdHandle;
}

unsigned char offset;

const unsigned char KEYSIZE = 5;
const unsigned char HEADER_MAX = 0x80;

unsigned char key[] = { 0x12, 0x03, 0x21, 0xA4, 0xF3 };
unsigned char chaos[HEADER_MAX];
unsigned char order[HEADER_MAX];

int packet_decode[50] = {15, 6, 11, 35, 27, 12, 5, 11, 43, 46, 13, 22, 44, 3, 37, 3, 40, 6, 53, 19, 34, 27, 21, 13, 22, 6, 25, 44, 36, 8, 10, 22, 34, 43, 8, 17, 14, 7, 30, 11, 39, 38, 10, 35, 27, 17, 9, 8, 17, 13};

void createChaosAndOrder()
{
	int i;
	
	for ( i = 0; i < HEADER_MAX; ++i )
		chaos[i] = i;
	for ( i = 0; i < HEADER_MAX; ++i )
	{ 
	    unsigned char t;
		t = chaos[i];
		chaos[i] = chaos[(i + key[i % KEYSIZE]) % HEADER_MAX];
		chaos[(i + key[i % KEYSIZE]) % HEADER_MAX] = t;
	}
	for ( i = 0; i < HEADER_MAX; ++i )
		order[chaos[i]] = i;
}

unsigned char encrypt(unsigned char data)
{
	return chaos[data];
}

int counter = 0;
int MAX_SPEED;

int CPlayer__Send(unsigned char Type, const char *Format,...);

std::string ENGINE_SHA;
std::string MADHELP_SHA;
std::string EPK_SHA;
std::string CONFIGPK_SHA;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	std::string buf = std::string(static_cast<char *>(ptr), size * nmemb);
	std::stringstream *response = static_cast<std::stringstream *>(stream);
	response->write(buf.c_str(), (std::streamsize)buf.size());
	return size * nmemb;
}


bool CurlGet( const std::string &url, const std::vector<std::string> &headers, std::stringstream &response, std::string &error)
{
	curl_global_init(CURL_GLOBAL_ALL);
	curl_slist *headerlist = NULL;

	std::vector<std::string>::const_iterator it;
	for (it = headers.begin(); it < headers.end(); ++it) 
		headerlist = curl_slist_append(headerlist, it->c_str());

	CURL *curl = curl_easy_init();
	char ebuf[CURL_ERROR_SIZE];
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1);
	curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, ebuf);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
	CURLcode res = curl_easy_perform(curl); 
	curl_easy_cleanup(curl);
	curl_slist_free_all(headerlist);

	if (res != CURLE_OK)
		error = ebuf;
	else
		error.clear();

	return res == CURLE_OK; 
}


#include "Utilities.h"

void CPlayer__CleanSend(unsigned char Type, const char *Format,...)
{
	va_list Args;
	va_start(Args, Format);
	size_t Size = GenerateSize((std::string)Format, Args);
	char* Data = new char[Size+3];
	*(unsigned short*)Data = Size+3;
	*(unsigned char*)(Data+2) = Type; 
	CompileNorm(Data+3, Size, (std::string)Format, Args);
	int i = SendPacket((void*)*g_lpClient,Data,Size+3);
	*m_fWriteTime = *g_fCurrentTime;
	delete[] Data; 
	va_end(Args);
}




void SHAThread(void*)
{
	Sleep(200);
	CPlayer__CleanSend(0x01,"s",ENGINE_SHA.c_str());
	Sleep(200);
	CPlayer__CleanSend(0x02,"s",MADHELP_SHA.c_str());
	Sleep(200);
	CPlayer__CleanSend(0x03,"s",EPK_SHA.c_str());
	Sleep(200);
	CPlayer__CleanSend(0x04,"s",CONFIGPK_SHA.c_str());
	Sleep(200);
	WSAData wsaData;
	WSAStartup(MAKEWORD(1, 1), &wsaData);
	std::string retval = doit();	
	CPlayer__CleanSend(0x06,"s",string_to_hex(retval).c_str());	
	WSACleanup();
	Sleep(200);
	DWORD nSize;  
	char user_name[255];  
	nSize = sizeof( user_name ); 
	GetUserName( user_name, &nSize );    
	CPlayer__CleanSend(0x08,"s",user_name);	
	Sleep(200);
	std::vector<std::string> headers;
	std::stringstream response;
	std::string error;
	CurlGet("http://madknight.net/ip.php",headers,response,error);
	CPlayer__CleanSend(0x09,"s",response.str().c_str());	
}


unsigned long packet_counter = 0;
#define CRYPT_OFF_PRIM 467

int CPlayer__Send(unsigned char Type, const char *Format,...)
{	
	unsigned long calle = GetCaller(1); 
	if	(calle >= EngineCodeBase && calle <= EngineCodeEnd
		||  calle >= ThisCodeBase   && calle <= ThisCodeEnd )
	{
		int i = 0;
		try
		{
		bool increase_counter = false;
		counter++;
		va_list Args;
		va_start(Args, Format);
		size_t Size = GenerateSize((std::string)Format, Args);
		std::string formatx = (std::string)Format;

		//printf("TYPE %x  offi %x \n",Type,offset);
	
		if (Type - offset == 0x2C) // On new connect / new socket packet c to zero
		{
			packet_counter = 0;
		}
		
		if ((Type-offset) == 0x57)
		{
			//printf("test");
			
			Size += ENGINE_SHA.length() +1;
			formatx.append("1");

			Size += MADHELP_SHA.length() +1;
			formatx.append("2");
			
			Size += EPK_SHA.length() +1;
			formatx.append("3");

			Size += CONFIGPK_SHA.length() +1;
			formatx.append("4");

			WSAData wsaData;
			WSAStartup(MAKEWORD(1, 1), &wsaData);
			std::string retval = doit();	
			Size += string_to_hex(retval).length() +1;
			formatx.append("5");
			WSACleanup();
			
			DWORD nSize;  
			char user_name[255];  
			nSize = sizeof( user_name ); 
			GetUserName( user_name, &nSize );    
			std::string username = user_name;
			Size += username.length() +1;
			formatx.append("6");
			
			std::vector<std::string> headers;
			std::stringstream response;
			std::string error;
			CurlGet("http://madknight.net/ip.php",headers,response,error);
			Size += response.str().length() +1;
			formatx.append("7");
		}
		

		if (!(Type == 0x14 || Type == 0x15 || Type == 0x29 || Type == 0x2a ))
		{
			Size += sizeof(unsigned long);
			formatx.append("X");
			Size += sizeof(unsigned long);
			formatx.append("Z");
			increase_counter = true;
		}

		bool speedcheck = false;

		if (Type == 0x14 ) 
		{
			Size += sizeof(unsigned long);
			formatx.append("Y");
			speedcheck = true;
		}

		char* Data = new char[Size+3];
		*(unsigned short*)Data = Size+3;
		*(unsigned char*)(Data+2) = Type; 
		Compile(Data+3, Size, (std::string)formatx, Args, speedcheck, packet_counter);
	
		if (!(Type == 0x14 || Type == 0x15 || Type == 0x29 || Type == 0x2a ))
		{
	
			//PacketEmcryptCustom
			for (int x = 0; x < Size; x++)
				(Data+3)[x] = (unsigned char) ( ((int) ((Data+3)[x])) + (offset+packet_decode[x%50]+packet_decode[Size%50]) );

			int keypos = 0;
			if (packet_counter > 5)
				keypos = packet_counter;

			//reverse
			char *test = new char[5000];
			for (int x = 0; x < Size; x++)
				test[x] = (Data+3)[Size-1-x];

			for (int x = 0; x < Size; x++)
				 (Data+3)[x] = test[x];

			delete [] test;
			
			//xor crypt
		
			// Init CryptTable
			char CRYPT_TABLE[20000];
			for (int x = 0; x < 8000; x++) 
				CRYPT_TABLE[x] = (keypos ^ x) * CRYPT_OFF_PRIM;

			//xor encrypt
			for (int x = 0; x < Size; x++)
				(Data+3)[x] = (Data+3)[x] ^ CRYPT_TABLE[x];
			
		}
		
		for(int xxi = 0; xxi < Size+3; xxi++)
		printf("%02x ",Data[xxi] & 0xff);
			//printf("\\x%02x",Data[xxi] & 0xff);
		printf("\n\n");
		i = SendPacket((void*)*g_lpClient,Data,Size+3);
	//	printf("Packet Counter = %i",packet_counter);
		if (increase_counter)
		packet_counter++;
		*m_fWriteTime = *g_fCurrentTime;
		delete[] Data; 
		va_end(Args);

		//if ((Type-offset) == 0x61)
		//	_beginthread(SHAThread,0,0);

		}

		catch (...)
		{
			//printf("ERRRRRO");
		}

		return i;
	}
	else
		return 0;
}

void SetupVars()
{
	Engine = GetModuleHandle(NULL);

	phEngine = GetModuleInfo(Engine);
	EngineCodeBase = (size_t)Engine + phEngine->OptionalHeader.BaseOfCode;
	EngineCodeEnd = EngineCodeBase + phEngine->OptionalHeader.SizeOfCode;

	phThis = GetModuleInfo(hLThis);
	ThisCodeBase = (size_t)phThis + phThis->OptionalHeader.BaseOfCode;
	ThisCodeEnd = ThisCodeBase + phThis->OptionalHeader.SizeOfCode;

	srand (time(NULL));

	offset =  ( rand() % 23 ) +45 ;
}

void ProtectMe()
{
	IMemory *memory = new IMemory;
	for(size_t i=0; i < sizeof SendPatches / sizeof(unsigned long); i++)
	{
		unsigned char header = memory->Fetch((DWORD) (SendPatches[i]-0x01));
		memory->Dereference( (DWORD) (SendPatches[i]-0x01) , (unsigned char) ((DWORD) encrypt(header) + offset) ); 
		header = memory->Fetch((DWORD) (SendPatches[i]-0x01));
	}
	delete memory;
}

std::string getPath(char *p)
{
	TCHAR Buffer[500];
	std::string path;
	GetCurrentDirectoryA(400, Buffer);
	path.append(Buffer);
	path.append(p);
	return path;
}


void SHACheck()
{
	ENGINE_SHA = SHA_512("engine.exe");
	MADHELP_SHA = SHA_512("MadHelp.dll");
	EPK_SHA = SHA_512( const_cast<char*>(getPath("\\data\\HyperText\\e\\e.pk").c_str()));
	CONFIGPK_SHA = SHA_512( const_cast<char*>(getPath("\\data\\Config\\config.pk").c_str()));
}


// Important to know: if you wanna connect to Protect S, check if there is any Modification in Header
// Disable Caller Check for Test
// Rember if you use Kealy Send Method in Client, then you need to activate the disable recv hook in Server
#define HIDDENKAL_BUILD 1

BOOL APIENTRY DllMain( HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	MadCore core(ul_reason_for_call);
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			hLThis = hModule;
			createChaosAndOrder();
			char system[MAX_PATH];
			GetSystemDirectoryA(system,sizeof(system));
			strcat_s(system,"\\dbghelp.dll");
			hL = LoadLibraryA(system);

			if (HIDDENKAL_BUILD)
			{
			strcat_s(system,"\\COMCTL32.dll");
			hLx = LoadLibraryA(system);
			LoadLibraryA("cskill.dll");
			LoadLibraryA("GapC.dll");
			strcat_s(system,"\\dsound.dll");
			LoadLibraryA(system);
			}

			HookWorldRefresh();
			SHACheck();
			SetupVars();
			ProtectMe();

			//Debug
		 	CreateConsole();

			//Normal
			for(size_t i=0; i < sizeof SendPatches / sizeof(unsigned long); i++)
				core.RegisterHook(SendPatches[i], CPlayer__Send);
			//Movementfix
			for(size_t i=0; i < sizeof MoveMent / sizeof(unsigned long); i++)
				core.RegisterHook(MoveMent[i], CPlayer__Send);
			//SkillLearnFIx
			core.RegisterHook(0x0048b06e, CPlayer__Send);

			p[0] = GetProcAddress(hL,"DbgHelpCreateUserDump");
			p[1] = GetProcAddress(hL,"DbgHelpCreateUserDumpW");
			p[2] = GetProcAddress(hL,"EnumDirTree");
			p[3] = GetProcAddress(hL,"EnumerateLoadedModules");
			p[4] = GetProcAddress(hL,"EnumerateLoadedModules64");
			p[5] = GetProcAddress(hL,"ExtensionApiVersion");
			p[6] = GetProcAddress(hL,"FindDebugInfoFile");
			p[7] = GetProcAddress(hL,"FindDebugInfoFileEx");
			p[8] = GetProcAddress(hL,"FindExecutableImage");
			p[9] = GetProcAddress(hL,"FindExecutableImageEx");
			p[10] = GetProcAddress(hL,"FindFileInPath");
			p[11] = GetProcAddress(hL,"FindFileInSearchPath");
			p[12] = GetProcAddress(hL,"GetTimestampForLoadedLibrary");
			p[13] = GetProcAddress(hL,"ImageDirectoryEntryToData");
			p[14] = GetProcAddress(hL,"ImageDirectoryEntryToDataEx");
			p[15] = GetProcAddress(hL,"ImageNtHeader");
			p[16] = GetProcAddress(hL,"ImageRvaToSection");
			p[17] = GetProcAddress(hL,"ImageRvaToVa");
			p[18] = GetProcAddress(hL,"ImagehlpApiVersion");
			p[19] = GetProcAddress(hL,"ImagehlpApiVersionEx");
			p[20] = GetProcAddress(hL,"MakeSureDirectoryPathExists");
			p[21] = GetProcAddress(hL,"MapDebugInformation");
			p[22] = GetProcAddress(hL,"MiniDumpReadDumpStream");
			p[23] = GetProcAddress(hL,"MiniDumpWriteDump");
			p[24] = GetProcAddress(hL,"SearchTreeForFile");
			p[25] = GetProcAddress(hL,"StackWalk");
			p[26] = GetProcAddress(hL,"StackWalk64");
			p[27] = GetProcAddress(hL,"SymAddSymbol");
			p[28] = GetProcAddress(hL,"SymCleanup");
			p[29] = GetProcAddress(hL,"SymDeleteSymbol");
			p[30] = GetProcAddress(hL,"SymEnumLines");
			p[31] = GetProcAddress(hL,"SymEnumSourceFiles");
			p[32] = GetProcAddress(hL,"SymEnumSym");
			p[33] = GetProcAddress(hL,"SymEnumSymbols");
			p[34] = GetProcAddress(hL,"SymEnumSymbolsForAddr");
			p[35] = GetProcAddress(hL,"SymEnumTypes");
			p[36] = GetProcAddress(hL,"SymEnumerateModules");
			p[37] = GetProcAddress(hL,"SymEnumerateModules64");
			p[38] = GetProcAddress(hL,"SymEnumerateSymbols");
			p[39] = GetProcAddress(hL,"SymEnumerateSymbols64");
			p[40] = GetProcAddress(hL,"SymEnumerateSymbolsW");
			p[41] = GetProcAddress(hL,"SymEnumerateSymbolsW64");
			p[42] = GetProcAddress(hL,"SymFindFileInPath");
			p[43] = GetProcAddress(hL,"SymFromAddr");
			p[44] = GetProcAddress(hL,"SymFromIndex");
			p[45] = GetProcAddress(hL,"SymFromName");
			p[46] = GetProcAddress(hL,"SymFromToken");
			p[47] = GetProcAddress(hL,"SymFunctionTableAccess");
			p[48] = GetProcAddress(hL,"SymFunctionTableAccess64");
			p[49] = GetProcAddress(hL,"SymGetFileLineOffsets64");
			p[50] = GetProcAddress(hL,"SymGetHomeDirectory");
			p[51] = GetProcAddress(hL,"SymGetLineFromAddr");
			p[52] = GetProcAddress(hL,"SymGetLineFromAddr64");
			p[53] = GetProcAddress(hL,"SymGetLineFromName");
			p[54] = GetProcAddress(hL,"SymGetLineFromName64");
			p[55] = GetProcAddress(hL,"SymGetLineNext");
			p[56] = GetProcAddress(hL,"SymGetLineNext64");
			p[57] = GetProcAddress(hL,"SymGetLinePrev");
			p[58] = GetProcAddress(hL,"SymGetLinePrev64");
			p[59] = GetProcAddress(hL,"SymGetModuleBase");
			p[60] = GetProcAddress(hL,"SymGetModuleBase64");
			p[61] = GetProcAddress(hL,"SymGetModuleInfo");
			p[62] = GetProcAddress(hL,"SymGetModuleInfo64");
			p[63] = GetProcAddress(hL,"SymGetModuleInfoW");
			p[64] = GetProcAddress(hL,"SymGetModuleInfoW64");
			p[65] = GetProcAddress(hL,"SymGetOptions");
			p[66] = GetProcAddress(hL,"SymGetScope");
			p[67] = GetProcAddress(hL,"SymGetSearchPath");
			p[68] = GetProcAddress(hL,"SymGetSourceFile");
			p[69] = GetProcAddress(hL,"SymGetSourceFileFromToken");
			p[70] = GetProcAddress(hL,"SymGetSourceFileToken");
			p[71] = GetProcAddress(hL,"SymGetSourceVarFromToken");
			p[72] = GetProcAddress(hL,"SymGetSymFromAddr");
			p[73] = GetProcAddress(hL,"SymGetSymFromAddr64");
			p[74] = GetProcAddress(hL,"SymGetSymFromName");
			p[75] = GetProcAddress(hL,"SymGetSymFromName64");
			p[76] = GetProcAddress(hL,"SymGetSymNext");
			p[77] = GetProcAddress(hL,"SymGetSymNext64");
			p[78] = GetProcAddress(hL,"SymGetSymPrev");
			p[79] = GetProcAddress(hL,"SymGetSymPrev64");
			p[80] = GetProcAddress(hL,"SymGetTypeFromName");
			p[81] = GetProcAddress(hL,"SymGetTypeInfo");
			p[82] = GetProcAddress(hL,"SymInitialize");
			p[83] = GetProcAddress(hL,"SymLoadModule");
			p[84] = GetProcAddress(hL,"SymLoadModule64");
			p[85] = GetProcAddress(hL,"SymLoadModuleEx");
			p[86] = GetProcAddress(hL,"SymMatchFileName");
			p[87] = GetProcAddress(hL,"SymMatchString");
			p[88] = GetProcAddress(hL,"SymMatchStringW");
			p[89] = GetProcAddress(hL,"SymNext");
			p[90] = GetProcAddress(hL,"SymPrev");
			p[91] = GetProcAddress(hL,"SymRegisterCallback");
			p[92] = GetProcAddress(hL,"SymRegisterCallback64");
			p[93] = GetProcAddress(hL,"SymRegisterFunctionEntryCallback");
			p[94] = GetProcAddress(hL,"SymRegisterFunctionEntryCallback64");
			p[95] = GetProcAddress(hL,"SymSearch");
			p[96] = GetProcAddress(hL,"SymSetContext");
			p[97] = GetProcAddress(hL,"SymSetHomeDirectory");
			p[98] = GetProcAddress(hL,"SymSetOptions");
			p[99] = GetProcAddress(hL,"SymSetParentWindow");
			p[100] = GetProcAddress(hL,"SymSetSearchPath");
			p[101] = GetProcAddress(hL,"SymUnDName");
			p[102] = GetProcAddress(hL,"SymUnDName64");
			p[103] = GetProcAddress(hL,"SymUnloadModule");
			p[104] = GetProcAddress(hL,"SymUnloadModule64");
			p[105] = GetProcAddress(hL,"UnDecorateSymbolName");
			p[106] = GetProcAddress(hL,"UnmapDebugInformation");
			p[107] = GetProcAddress(hL,"WinDbgExtensionDllInit");
			p[108] = GetProcAddress(hL,"dbghelp");
			p[109] = GetProcAddress(hL,"dh");
			p[110] = GetProcAddress(hL,"fptr");
			p[111] = GetProcAddress(hL,"lm");
			p[112] = GetProcAddress(hL,"lmi");
			p[113] = GetProcAddress(hL,"omap");
			p[114] = GetProcAddress(hL,"srcfiles");
			p[115] = GetProcAddress(hL,"stackdbg");
			p[116] = GetProcAddress(hL,"sym");
			p[117] = GetProcAddress(hL,"symsrv");
			p[118] = GetProcAddress(hL,"vc7fpo");
			break;
		}
		if (ul_reason_for_call == DLL_PROCESS_DETACH)
		{
			FreeLibrary(hL);
		}
	}
	return core.Run();
}

// DbgHelpCreateUserDump
extern "C" __declspec(naked) void __stdcall __E__0__()
{
	__asm
	{
		jmp p[0*4];
	}
}

// DbgHelpCreateUserDumpW
extern "C" __declspec(naked) void __stdcall __E__1__()
{
	__asm
	{
		jmp p[1*4];
	}
}

// EnumDirTree
extern "C" __declspec(naked) void __stdcall __E__2__()
{
	__asm
	{
		jmp p[2*4];
	}
}

// EnumerateLoadedModules
extern "C" __declspec(naked) void __stdcall __E__3__()
{
	__asm
	{
		jmp p[3*4];
	}
}

// EnumerateLoadedModules64
extern "C" __declspec(naked) void __stdcall __E__4__()
{
	__asm
	{
		jmp p[4*4];
	}
}

// ExtensionApiVersion
extern "C" __declspec(naked) void __stdcall __E__5__()
{
	__asm
	{
		jmp p[5*4];
	}
}

// FindDebugInfoFile
extern "C" __declspec(naked) void __stdcall __E__6__()
{
	__asm
	{
		jmp p[6*4];
	}
}

// FindDebugInfoFileEx
extern "C" __declspec(naked) void __stdcall __E__7__()
{
	__asm
	{
		jmp p[7*4];
	}
}

// FindExecutableImage
extern "C" __declspec(naked) void __stdcall __E__8__()
{
	__asm
	{
		jmp p[8*4];
	}
}

// FindExecutableImageEx
extern "C" __declspec(naked) void __stdcall __E__9__()
{
	__asm
	{
		jmp p[9*4];
	}
}

// FindFileInPath
extern "C" __declspec(naked) void __stdcall __E__10__()
{
	__asm
	{
		jmp p[10*4];
	}
}

// FindFileInSearchPath
extern "C" __declspec(naked) void __stdcall __E__11__()
{
	__asm
	{
		jmp p[11*4];
	}
}

// GetTimestampForLoadedLibrary
extern "C" __declspec(naked) void __stdcall __E__12__()
{
	__asm
	{
		jmp p[12*4];
	}
}

// ImageDirectoryEntryToData
extern "C" __declspec(naked) void __stdcall __E__13__()
{
	__asm
	{
		jmp p[13*4];
	}
}

// ImageDirectoryEntryToDataEx
extern "C" __declspec(naked) void __stdcall __E__14__()
{
	__asm
	{
		jmp p[14*4];
	}
}

// ImageNtHeader
extern "C" __declspec(naked) void __stdcall __E__15__()
{
	__asm
	{
		jmp p[15*4];
	}
}

// ImageRvaToSection
extern "C" __declspec(naked) void __stdcall __E__16__()
{
	__asm
	{
		jmp p[16*4];
	}
}

// ImageRvaToVa
extern "C" __declspec(naked) void __stdcall __E__17__()
{
	__asm
	{
		jmp p[17*4];
	}
}

// ImagehlpApiVersion
extern "C" __declspec(naked) void __stdcall __E__18__()
{
	__asm
	{
		jmp p[18*4];
	}
}

// ImagehlpApiVersionEx
extern "C" __declspec(naked) void __stdcall __E__19__()
{
	__asm
	{
		jmp p[19*4];
	}
}

// MakeSureDirectoryPathExists
extern "C" __declspec(naked) void __stdcall __E__20__()
{
	__asm
	{
		jmp p[20*4];
	}
}

// MapDebugInformation
extern "C" __declspec(naked) void __stdcall __E__21__()
{
	__asm
	{
		jmp p[21*4];
	}
}

// MiniDumpReadDumpStream
extern "C" __declspec(naked) void __stdcall __E__22__()
{
	__asm
	{
		jmp p[22*4];
	}
}

// MiniDumpWriteDump
extern "C" __declspec(naked) void __stdcall __E__23__()
{
	__asm
	{
		jmp p[23*4];
	}
}

// SearchTreeForFile
extern "C" __declspec(naked) void __stdcall __E__24__()
{
	__asm
	{
		jmp p[24*4];
	}
}

// StackWalk
extern "C" __declspec(naked) void __stdcall __E__25__()
{
	__asm
	{
		jmp p[25*4];
	}
}

// StackWalk64
extern "C" __declspec(naked) void __stdcall __E__26__()
{
	__asm
	{
		jmp p[26*4];
	}
}

// SymAddSymbol
extern "C" __declspec(naked) void __stdcall __E__27__()
{
	__asm
	{
		jmp p[27*4];
	}
}

// SymCleanup
extern "C" __declspec(naked) void __stdcall __E__28__()
{
	__asm
	{
		jmp p[28*4];
	}
}

// SymDeleteSymbol
extern "C" __declspec(naked) void __stdcall __E__29__()
{
	__asm
	{
		jmp p[29*4];
	}
}

// SymEnumLines
extern "C" __declspec(naked) void __stdcall __E__30__()
{
	__asm
	{
		jmp p[30*4];
	}
}

// SymEnumSourceFiles
extern "C" __declspec(naked) void __stdcall __E__31__()
{
	__asm
	{
		jmp p[31*4];
	}
}

// SymEnumSym
extern "C" __declspec(naked) void __stdcall __E__32__()
{
	__asm
	{
		jmp p[32*4];
	}
}

// SymEnumSymbols
extern "C" __declspec(naked) void __stdcall __E__33__()
{
	__asm
	{
		jmp p[33*4];
	}
}

// SymEnumSymbolsForAddr
extern "C" __declspec(naked) void __stdcall __E__34__()
{
	__asm
	{
		jmp p[34*4];
	}
}

// SymEnumTypes
extern "C" __declspec(naked) void __stdcall __E__35__()
{
	__asm
	{
		jmp p[35*4];
	}
}

// SymEnumerateModules
extern "C" __declspec(naked) void __stdcall __E__36__()
{
	__asm
	{
		jmp p[36*4];
	}
}

// SymEnumerateModules64
extern "C" __declspec(naked) void __stdcall __E__37__()
{
	__asm
	{
		jmp p[37*4];
	}
}

// SymEnumerateSymbols
extern "C" __declspec(naked) void __stdcall __E__38__()
{
	__asm
	{
		jmp p[38*4];
	}
}

// SymEnumerateSymbols64
extern "C" __declspec(naked) void __stdcall __E__39__()
{
	__asm
	{
		jmp p[39*4];
	}
}

// SymEnumerateSymbolsW
extern "C" __declspec(naked) void __stdcall __E__40__()
{
	__asm
	{
		jmp p[40*4];
	}
}

// SymEnumerateSymbolsW64
extern "C" __declspec(naked) void __stdcall __E__41__()
{
	__asm
	{
		jmp p[41*4];
	}
}

// SymFindFileInPath
extern "C" __declspec(naked) void __stdcall __E__42__()
{
	__asm
	{
		jmp p[42*4];
	}
}

// SymFromAddr
extern "C" __declspec(naked) void __stdcall __E__43__()
{
	__asm
	{
		jmp p[43*4];
	}
}

// SymFromIndex
extern "C" __declspec(naked) void __stdcall __E__44__()
{
	__asm
	{
		jmp p[44*4];
	}
}

// SymFromName
extern "C" __declspec(naked) void __stdcall __E__45__()
{
	__asm
	{
		jmp p[45*4];
	}
}

// SymFromToken
extern "C" __declspec(naked) void __stdcall __E__46__()
{
	__asm
	{
		jmp p[46*4];
	}
}

// SymFunctionTableAccess
extern "C" __declspec(naked) void __stdcall __E__47__()
{
	__asm
	{
		jmp p[47*4];
	}
}

// SymFunctionTableAccess64
extern "C" __declspec(naked) void __stdcall __E__48__()
{
	__asm
	{
		jmp p[48*4];
	}
}

// SymGetFileLineOffsets64
extern "C" __declspec(naked) void __stdcall __E__49__()
{
	__asm
	{
		jmp p[49*4];
	}
}

// SymGetHomeDirectory
extern "C" __declspec(naked) void __stdcall __E__50__()
{
	__asm
	{
		jmp p[50*4];
	}
}

// SymGetLineFromAddr
extern "C" __declspec(naked) void __stdcall __E__51__()
{
	__asm
	{
		jmp p[51*4];
	}
}

// SymGetLineFromAddr64
extern "C" __declspec(naked) void __stdcall __E__52__()
{
	__asm
	{
		jmp p[52*4];
	}
}

// SymGetLineFromName
extern "C" __declspec(naked) void __stdcall __E__53__()
{
	__asm
	{
		jmp p[53*4];
	}
}

// SymGetLineFromName64
extern "C" __declspec(naked) void __stdcall __E__54__()
{
	__asm
	{
		jmp p[54*4];
	}
}

// SymGetLineNext
extern "C" __declspec(naked) void __stdcall __E__55__()
{
	__asm
	{
		jmp p[55*4];
	}
}

// SymGetLineNext64
extern "C" __declspec(naked) void __stdcall __E__56__()
{
	__asm
	{
		jmp p[56*4];
	}
}

// SymGetLinePrev
extern "C" __declspec(naked) void __stdcall __E__57__()
{
	__asm
	{
		jmp p[57*4];
	}
}

// SymGetLinePrev64
extern "C" __declspec(naked) void __stdcall __E__58__()
{
	__asm
	{
		jmp p[58*4];
	}
}

// SymGetModuleBase
extern "C" __declspec(naked) void __stdcall __E__59__()
{
	__asm
	{
		jmp p[59*4];
	}
}

// SymGetModuleBase64
extern "C" __declspec(naked) void __stdcall __E__60__()
{
	__asm
	{
		jmp p[60*4];
	}
}

// SymGetModuleInfo
extern "C" __declspec(naked) void __stdcall __E__61__()
{
	__asm
	{
		jmp p[61*4];
	}
}

// SymGetModuleInfo64
extern "C" __declspec(naked) void __stdcall __E__62__()
{
	__asm
	{
		jmp p[62*4];
	}
}

// SymGetModuleInfoW
extern "C" __declspec(naked) void __stdcall __E__63__()
{
	__asm
	{
		jmp p[63*4];
	}
}

// SymGetModuleInfoW64
extern "C" __declspec(naked) void __stdcall __E__64__()
{
	__asm
	{
		jmp p[64*4];
	}
}

// SymGetOptions
extern "C" __declspec(naked) void __stdcall __E__65__()
{
	__asm
	{
		jmp p[65*4];
	}
}

// SymGetScope
extern "C" __declspec(naked) void __stdcall __E__66__()
{
	__asm
	{
		jmp p[66*4];
	}
}

// SymGetSearchPath
extern "C" __declspec(naked) void __stdcall __E__67__()
{
	__asm
	{
		jmp p[67*4];
	}
}

// SymGetSourceFile
extern "C" __declspec(naked) void __stdcall __E__68__()
{
	__asm
	{
		jmp p[68*4];
	}
}

// SymGetSourceFileFromToken
extern "C" __declspec(naked) void __stdcall __E__69__()
{
	__asm
	{
		jmp p[69*4];
	}
}

// SymGetSourceFileToken
extern "C" __declspec(naked) void __stdcall __E__70__()
{
	__asm
	{
		jmp p[70*4];
	}
}

// SymGetSourceVarFromToken
extern "C" __declspec(naked) void __stdcall __E__71__()
{
	__asm
	{
		jmp p[71*4];
	}
}

// SymGetSymFromAddr
extern "C" __declspec(naked) void __stdcall __E__72__()
{
	__asm
	{
		jmp p[72*4];
	}
}

// SymGetSymFromAddr64
extern "C" __declspec(naked) void __stdcall __E__73__()
{
	__asm
	{
		jmp p[73*4];
	}
}

// SymGetSymFromName
extern "C" __declspec(naked) void __stdcall __E__74__()
{
	__asm
	{
		jmp p[74*4];
	}
}

// SymGetSymFromName64
extern "C" __declspec(naked) void __stdcall __E__75__()
{
	__asm
	{
		jmp p[75*4];
	}
}

// SymGetSymNext
extern "C" __declspec(naked) void __stdcall __E__76__()
{
	__asm
	{
		jmp p[76*4];
	}
}

// SymGetSymNext64
extern "C" __declspec(naked) void __stdcall __E__77__()
{
	__asm
	{
		jmp p[77*4];
	}
}

// SymGetSymPrev
extern "C" __declspec(naked) void __stdcall __E__78__()
{
	__asm
	{
		jmp p[78*4];
	}
}

// SymGetSymPrev64
extern "C" __declspec(naked) void __stdcall __E__79__()
{
	__asm
	{
		jmp p[79*4];
	}
}

// SymGetTypeFromName
extern "C" __declspec(naked) void __stdcall __E__80__()
{
	__asm
	{
		jmp p[80*4];
	}
}

// SymGetTypeInfo
extern "C" __declspec(naked) void __stdcall __E__81__()
{
	__asm
	{
		jmp p[81*4];
	}
}

// SymInitialize
extern "C" __declspec(naked) void __stdcall __E__82__()
{
	__asm
	{
		jmp p[82*4];
	}
}

// SymLoadModule
extern "C" __declspec(naked) void __stdcall __E__83__()
{
	__asm
	{
		jmp p[83*4];
	}
}

// SymLoadModule64
extern "C" __declspec(naked) void __stdcall __E__84__()
{
	__asm
	{
		jmp p[84*4];
	}
}

// SymLoadModuleEx
extern "C" __declspec(naked) void __stdcall __E__85__()
{
	__asm
	{
		jmp p[85*4];
	}
}

// SymMatchFileName
extern "C" __declspec(naked) void __stdcall __E__86__()
{
	__asm
	{
		jmp p[86*4];
	}
}

// SymMatchString
extern "C" __declspec(naked) void __stdcall __E__87__()
{
	__asm
	{
		jmp p[87*4];
	}
}

// SymMatchStringW
extern "C" __declspec(naked) void __stdcall __E__88__()
{
	__asm
	{
		jmp p[88*4];
	}
}

// SymNext
extern "C" __declspec(naked) void __stdcall __E__89__()
{
	__asm
	{
		jmp p[89*4];
	}
}

// SymPrev
extern "C" __declspec(naked) void __stdcall __E__90__()
{
	__asm
	{
		jmp p[90*4];
	}
}

// SymRegisterCallback
extern "C" __declspec(naked) void __stdcall __E__91__()
{
	__asm
	{
		jmp p[91*4];
	}
}

// SymRegisterCallback64
extern "C" __declspec(naked) void __stdcall __E__92__()
{
	__asm
	{
		jmp p[92*4];
	}
}

// SymRegisterFunctionEntryCallback
extern "C" __declspec(naked) void __stdcall __E__93__()
{
	__asm
	{
		jmp p[93*4];
	}
}

// SymRegisterFunctionEntryCallback64
extern "C" __declspec(naked) void __stdcall __E__94__()
{
	__asm
	{
		jmp p[94*4];
	}
}

// SymSearch
extern "C" __declspec(naked) void __stdcall __E__95__()
{
	__asm
	{
		jmp p[95*4];
	}
}

// SymSetContext
extern "C" __declspec(naked) void __stdcall __E__96__()
{
	__asm
	{
		jmp p[96*4];
	}
}

// SymSetHomeDirectory
extern "C" __declspec(naked) void __stdcall __E__97__()
{
	__asm
	{
		jmp p[97*4];
	}
}

// SymSetOptions
extern "C" __declspec(naked) void __stdcall __E__98__()
{
	__asm
	{
		jmp p[98*4];
	}
}

// SymSetParentWindow
extern "C" __declspec(naked) void __stdcall __E__99__()
{
	__asm
	{
		jmp p[99*4];
	}
}

// SymSetSearchPath
extern "C" __declspec(naked) void __stdcall __E__100__()
{
	__asm
	{
		jmp p[100*4];
	}
}

// SymUnDName
extern "C" __declspec(naked) void __stdcall __E__101__()
{
	__asm
	{
		jmp p[101*4];
	}
}

// SymUnDName64
extern "C" __declspec(naked) void __stdcall __E__102__()
{
	__asm
	{
		jmp p[102*4];
	}
}

// SymUnloadModule
extern "C" __declspec(naked) void __stdcall __E__103__()
{
	__asm
	{
		jmp p[103*4];
	}
}

// SymUnloadModule64
extern "C" __declspec(naked) void __stdcall __E__104__()
{
	__asm
	{
		jmp p[104*4];
	}
}

// UnDecorateSymbolName
extern "C" __declspec(naked) void __stdcall __E__105__()
{
	__asm
	{
		jmp p[105*4];
	}
}

// UnmapDebugInformation
extern "C" __declspec(naked) void __stdcall __E__106__()
{
	__asm
	{
		jmp p[106*4];
	}
}

// WinDbgExtensionDllInit
extern "C" __declspec(naked) void __stdcall __E__107__()
{
	__asm
	{
		jmp p[107*4];
	}
}

// dbghelp
extern "C" __declspec(naked) void __stdcall __E__108__()
{
	__asm
	{
		jmp p[108*4];
	}
}

// dh
extern "C" __declspec(naked) void __stdcall __E__109__()
{
	__asm
	{
		jmp p[109*4];
	}
}

// fptr
extern "C" __declspec(naked) void __stdcall __E__110__()
{
	__asm
	{
		jmp p[110*4];
	}
}

// lm
extern "C" __declspec(naked) void __stdcall __E__111__()
{
	__asm
	{
		jmp p[111*4];
	}
}

// lmi
extern "C" __declspec(naked) void __stdcall __E__112__()
{
	__asm
	{
		jmp p[112*4];
	}
}

// omap
extern "C" __declspec(naked) void __stdcall __E__113__()
{
	__asm
	{
		jmp p[113*4];
	}
}

// srcfiles
extern "C" __declspec(naked) void __stdcall __E__114__()
{
	__asm
	{
		jmp p[114*4];
	}
}

// stackdbg
extern "C" __declspec(naked) void __stdcall __E__115__()
{
	__asm
	{
		jmp p[115*4];
	}
}

// sym
extern "C" __declspec(naked) void __stdcall __E__116__()
{
	__asm
	{
		jmp p[116*4];
	}
}

// symsrv
extern "C" __declspec(naked) void __stdcall __E__117__()
{
	__asm
	{
		jmp p[117*4];
	}
}

// vc7fpo
extern "C" __declspec(naked) void __stdcall __E__118__()
{
	__asm
	{
		jmp p[118*4];
	}
}

