#include "Windows.h"
#include <sstream>

static int *g_lpClient = (int*)0x0070F9C8;
static float *m_fWriteTime = (float*)0x0070F9D0;
static float *g_fCurrentTime = (float*)0x007DE000;

static int (__thiscall *SendPacket)(void* _this, const  char* Buffer, int Length) = 
	(int (__thiscall*)(void*, const  char*, int))0x0052CBF0;

static int (__thiscall *SendPacketX)(void* _this, const  char* Buffer, int Length) = 
	(int (__thiscall*)(void*, const  char*, int))0x0052CBF0;

//-0x01 

// Folgende machen Problem (laufen ist dword harcode)
// 0x0040A070+0x390,  0x0040A070+0x3C5,
//	0x0040A070+0x420,
unsigned long MoveMent[] =
{
	0x0040A070+0x390,  0x0040A070+0x3C5,0x0040A070+0x420
};

// Needs to be Fixed
//48B06E

/**
.text:0048B06A                 add     ecx, 29h
.text:0048B06D                 push    ecx             ; Type
.text:0048B06E                 call    CPlayer__Send
**/

     push    0xXX             ; Type
     call    CPlayer__Send

/**
Eventuell mal checken
loc_50582F:				; CODE XREF: WinMain(x,x,x,x)+1332j
mov	eax, [ebp-73Ch]
mov	dword_711A08, eax
push	offset CPlayer__Send
**/

/**	if (speed >= MAX_SPEED)
{
__asm mov edi, 0
__asm xor edx, edx
__asm mov eax, 1
__asm div edi
}
if (zCoord <= 1000 || zCoord >= 60000 )
{
__asm mov edi, 0
__asm xor edx, edx
__asm mov eax, 1
__asm div edi
}

}**/

//	0x0048b06e, special solved 

unsigned long SendPatches[245] =
{
	0x00401c7c,  0x0040e0ae,  0x0048db59,  0x004921f4,  0x00497221,  0x0049ad2b,  
	0x00401d35,  0x0040e0c1,  0x0048dc89,  0x004922a2,  0x0049766f,  0x0049ad6e,  
	0x0040a0b5,  0x0040e0e0,  0x0048e12a,  0x00492357,  0x0049769a,  0x0049b7e0,  
	0x0040ab6b,  0x0040e0f6,  0x0048e7fb,  0x0049243c,  0x0049919b,  0x0049b822,  
	0x0040abeb,  0x0044d360,  0x0048ed39,  0x00492614,  0x00499540,  0x0049b864,  
	0x0040ac7b,  0x0044daff,  0x0049174d,  0x00492670,  0x00499b1e,  0x0049b8a1,  
	0x0040acfc,  0x0044de62,  0x0049175e,  0x004926a6,  0x00499b47,  0x0049c058,  
	0x0040adbf,  0x0044decb,  0x00491b1e,  0x00492ba7,  0x00499b87,  0x0049c1ce,  
	0x0040bc6a,  0x0046c104,  0x00491b5b,  0x00493021,  0x00499bb7,  0x0049c4f8,  
	0x0040bfcb,  0x0046c57f,  0x00491ba8,  0x00493293,  0x0049a3d5,  0x0049c81b,  
	0x0040d1a6,  0x0047565a,  0x00491c24,  0x00493bd8,  0x0049a406,  0x0049cb70,  
	0x0040d3b8,  0x00487da1,  0x00491d9b,  0x00494813,  0x0049a461,  0x0049ccfd,  
	0x0040d64b,  0x00488058,  0x00491dc7,  0x00494aee,  0x0049a490,  0x0049cd5a,  
	0x0040da0a,  0x00488626,  0x00491e01,  0x00494f83,  0x0049a4b3,  0x0049cd9b,  
	0x0040da3f,  0x0048937d,  0x00491e2f,  0x00495f17,  0x0049a4fd,  0x0049d416,  
	0x0040da73,  0x00489774,  0x00491e5d,  0x0049626a,  0x0049a564,  0x0049d666,  
	0x0040db7a,  0x0048b497,  0x00491e8d,  0x00496327,  0x0049a585,  0x0049f462,  
	0x0040de35,  0x0048c115,  0x00491ebb,  0x00496361,  0x0049a5b8,  0x004a180b,  
	0x0040de9f,  0x0048c2a4,  0x0049212a,  0x0049660b,  0x0049a5d4,  0x004a198c,  
	0x0040dfee,  0x0048d78c,  0x00492158,  0x00497114,  0x0049a967,  0x004a2181,  

	0x004a3cb2,  0x004a9548,  0x004bf9da,  0x004dd593,  0x004e66a9,  0x004eb70c,
	0x004a4770,  0x004a96eb,  0x004c2dc2,  0x004dd5d0,  0x004e66e7,  0x004eb754,
	0x004a47a1,  0x004a9a47,  0x004c2dd5,  0x004dddad,  0x004e9cf4,  0x004eeb6d,
	0x004a47d3,  0x004a9b1c,  0x004c2de8,  0x004de4a4,  0x004e9d11,  0x004eeba7,
	0x004a4b5c,  0x004a9b2d,  0x004d8e27,  0x004def72,  0x004e9d2e,  0x004efc98,
	0x004a4c0c,  0x004a9e99,  0x004d8e5f,  0x004df99a,  0x004e9d4b,  0x004efcdb,
	0x004a4cfc,  0x004aa015,  0x004d8fef,  0x004dfdec,  0x004ea640,  0x004efd3e,
	0x004a4d25,  0x004aae09,  0x004d99e8,  0x004e0653,  0x004ea668,  0x004f234e,
	0x004a4d4e,  0x004acf2f,  0x004da01c,  0x004e08c7,  0x004ea6e5,  0x004f23c9,
	0x004a4db3,  0x004adff2,  0x004da0e6,  0x004e0938,  0x004eaba3,  0x004f25de,
	0x004a4f81,  0x004b0b90,  0x004da331,  0x004e18b0,  0x004eac61,  0x004f26ec,
	0x004a5008,  0x004ba71e,  0x004dad2c,  0x004e1adb,  0x004eafc5,  0x004f273e,
	0x004a8967,  0x004ba7dd,  0x004db8b6,  0x004e2660,  0x004eb020,  0x004f27e1,
	0x004a89fb,  0x004ba920,  0x004dbca4,  0x004e317e,  0x004eb07b,  0x004f2e16,
	0x004a8f77,  0x004bab4a,  0x004dbd41,  0x004e328f,  0x004eb15a,  0x004f41c2,
	0x004a900b,  0x004bb2ab,  0x004dbe1f,  0x004e5f5a,  0x004eb18e,  0x004f44db,
	0x004a917e,  0x004bb4f9,  0x004dbe6c,  0x004e65cc,  0x004eb1c6,  0x004f9cd4,
	0x004a91c8,  0x004bb612,  0x004dc133,  0x004e65f9,  0x004eb1fb,  0x004fe6eb,
	0x004a91f2,  0x004bc40f,  0x004dd0bd,  0x004e665a,  0x004eb43f,  0x004fe7f5,
	0x004a933e,  0x004bc63f,  0x004dd401,  0x004e666f,  0x004eb49e,  0x004fe89d,

	0x004ffc14,
	0x00500425,
	0x0049cc77,
	0x005005ed,
	0x004d8e97
};

unsigned long GetCaller(size_t Depth)
{
	unsigned long _Ebp, Addr;

	if (!Depth)
	{
		__asm mov eax, [ebp]
		__asm mov _Ebp, eax
	}
	else
	{
		__asm mov eax, ebp
		__asm mov _Ebp, eax
	}

	for(size_t i=0; i < Depth; i++)
	{
		__asm mov eax, _Ebp
		__asm mov eax, [eax]
		__asm mov _Ebp, eax
	}
	__asm mov eax, _Ebp
	__asm mov eax, [eax+4]
	__asm mov Addr, eax
	return Addr-5;
}

PIMAGE_NT_HEADERS GetModuleInfo(HMODULE Module)
{
	PIMAGE_DOS_HEADER DOS_Header = (PIMAGE_DOS_HEADER)Module;
	PIMAGE_NT_HEADERS NT_Header = (PIMAGE_NT_HEADERS)((unsigned)DOS_Header + DOS_Header->e_lfanew);
	return NT_Header;
}

LPVOID MemoryCopy(DWORD destination, DWORD source, int length)
{
	DWORD oldSource      = 0;
	DWORD oldDestination = 0;

	VirtualProtect((LPVOID)source,length,PAGE_EXECUTE_READWRITE,&oldSource);
	VirtualProtect((LPVOID)destination,length,PAGE_EXECUTE_READWRITE,&oldDestination);

	memcpy((void*)destination,(void*)source,length);

	VirtualProtect((LPVOID)destination,length,oldDestination,&oldDestination);
	VirtualProtect((LPVOID)source,length,oldSource,&oldSource);

	return (LPVOID)destination;
};

LPVOID MemcpyEx(DWORD lpDest, DWORD lpSource, int len)
{
	DWORD oldSourceProt,oldDestProt=0;
	VirtualProtect((LPVOID)lpSource,len,PAGE_EXECUTE_READWRITE,&oldSourceProt);
	VirtualProtect((LPVOID)lpDest,len,PAGE_EXECUTE_READWRITE,&oldDestProt);
	memcpy((void*)lpDest,(void*)lpSource,len);
	VirtualProtect((LPVOID)lpDest,len,oldDestProt,&oldDestProt);
	VirtualProtect((LPVOID)lpSource,len,oldSourceProt,&oldSourceProt);
	return (LPVOID)lpDest;
};


void MemoryCopy(void *Destination, void *Source, size_t Size)
{
	unsigned long p1, p2;
	VirtualProtect(Destination, Size, PAGE_EXECUTE_READWRITE, &p1);
	VirtualProtect(Source, Size, PAGE_EXECUTE_READWRITE, &p2);
	CopyMemory(Destination, Source, Size);
	VirtualProtect(Destination, Size, p1, &p1);
	VirtualProtect(Source, Size, p1, &p2);
};

size_t GenerateSize(std::string Format, va_list vArgs)
{
	int PacketSize = 0;
	std::string pSizeStr;

	for(size_t i=0; i < Format.length();i++)
	{
		switch (Format[i])
		{
		case 'b':
		case 'B':
			PacketSize += sizeof(unsigned char);
			va_arg(vArgs, unsigned char);
			break;
		case 'w':
		case 'W':
			PacketSize += sizeof(unsigned short);
			va_arg(vArgs, unsigned short);
			break;
		case 'd':
		case 'U':
			PacketSize += sizeof(unsigned long);
			va_arg(vArgs, unsigned long);
			break;
		case 'f':
			PacketSize += sizeof(float);
			va_arg(vArgs, float);
			break;
		case 'D':
			PacketSize += sizeof(double);
			va_arg(vArgs, double);
			break;
		case 'I':
			PacketSize += sizeof(__int64);
			va_arg(vArgs, unsigned __int64);
			break;
		case 's':
		case 'S':
			pSizeStr = va_arg(vArgs, char*);
			PacketSize += pSizeStr.length() +1;
			break;
		case 'm':
		case 'M':
			va_arg(vArgs, char*);
			PacketSize += va_arg(vArgs, int);
			break;
		default:
			break;
		}
	}
	return PacketSize;
}


DWORD GetSpeed()
{
	__try 
	{
		DWORD speed;
		DWORD* dwSpeedpointer = (DWORD*)0x006F3840;
		MemcpyEx((DWORD)&speed,DWORD(((DWORD)*dwSpeedpointer)+0x00004B14),4);
		return speed;
	}
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{
		return 1;
	}
	return 1;
}

std::string string_to_hex(const std::string& input)
{
	static const char* const lut = "0123456789ABCDEF";
	size_t len = input.length();

	std::string output;
	output.reserve(2 * len);
	for (size_t i = 0; i < len; ++i)
	{
		const unsigned char c = input[i];
		output.push_back(lut[c >> 4]);
		output.push_back(lut[c & 15]);
	}
	return output;
}

std::string doit()
{
	std::stringstream retn;
	char ac[80];
	if (gethostname(ac, sizeof(ac)) == SOCKET_ERROR) {
		retn << "Error " << WSAGetLastError() <<
			" when getting local host name.";

	}
	retn << ac ;

	struct hostent *phe = gethostbyname(ac);
	if (phe == 0) {
		retn << "Yow! Bad host lookup.";

	}

	for (int i = 0; phe->h_addr_list[i] != 0; ++i) {
		struct in_addr addr;
		memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
		retn  << inet_ntoa(addr);
	}

	return retn.str();
}

void Compile( char* Destination, int Size, std::string Format, va_list vArgs, bool speed_check, unsigned long packet_C)
{
	unsigned long calle = GetCaller(2); 
	if	(calle >= EngineCodeBase && calle <= EngineCodeEnd
		||  calle >= ThisCodeBase   && calle <= ThisCodeEnd)
	{
		//printf("%x\n",calle);
		/**	case 'X':
		pTypeDword = calle;
		memcpy(Destination, &pTypeDword, sizeof(unsigned long));
		Destination += sizeof(unsigned long);
		break;
		**/

		DWORD speed = 0;
		if (speed_check)
		{
			speed = GetSpeed();
			printf("speed sendend%i\n",speed);
		}
		
		//__try 
		//{
		//DWORD* dwSpeedpointer = (DWORD*)0x006F3840;
		//MemcpyEx((DWORD)&speed,DWORD(((DWORD)*dwSpeedpointer)+0x00004B14),4);
		//}
		//__except(EXCEPTION_EXECUTE_HANDLER) 
		//{
		//speed = 0;
		//}

		unsigned char pTypeByte = 0;
		unsigned short pTypeWord = 0;
		unsigned long pTypeDword = 0;
		float pTypeFloat = 0.0;
		double pTypeDouble = 0.0;
		unsigned __int64 pTypeQword = 0;
		std::string pTypeStr;
		char* pTypeArray = NULL;
		int pTypeArrayLen = 0;

		char user_name[255];  
		std::vector<std::string> headers;
		std::stringstream response;
		std::string error;

		for(size_t i=0; i < Format.length();i++)
		{
			switch (Format[i])
			{
			case 'b':
			case 'B':
				pTypeByte = va_arg(vArgs, unsigned char);
				memcpy(Destination, &pTypeByte, sizeof(unsigned char));
				Destination += sizeof(unsigned char);
				break;
			case 'w':
			case 'W':
				pTypeWord = va_arg(vArgs, unsigned short);
				memcpy(Destination, &pTypeWord, sizeof(unsigned short));
				Destination += sizeof(unsigned short);
				break;
			case 'd':
			case 'U':
				pTypeDword = va_arg(vArgs, unsigned long);
				memcpy(Destination, &pTypeDword, sizeof(unsigned long));
				Destination += sizeof(unsigned long);
				break;
			case 'f':
				pTypeFloat = va_arg(vArgs, float);
				memcpy(Destination, &pTypeFloat, sizeof(float));
				Destination += sizeof(float);
				break;
			case 'D':
				pTypeDouble = va_arg(vArgs, double);
				memcpy(Destination, &pTypeDouble, sizeof(double));
				Destination += sizeof(double);
				break;
			case 'I':
				pTypeQword = va_arg(vArgs, unsigned __int64);
				memcpy((void*)Destination,(void*)&pTypeDword,8);
				Destination+= 8;
			case 's':
			case 'S':
				pTypeStr = va_arg(vArgs, char*);
				memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() +1);
				Destination += pTypeStr.length() +1;
				break;
			case '1':
				pTypeStr = ENGINE_SHA;
				memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() +1);
				Destination += pTypeStr.length() +1;
				break;
			case '2':
				pTypeStr = MADHELP_SHA;
				memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() +1);
				Destination += pTypeStr.length() +1;
				break;
			case '3':
				pTypeStr = EPK_SHA;
				memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() +1);
				Destination += pTypeStr.length() +1;
				break;
			case '4':
				pTypeStr = CONFIGPK_SHA;
				memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() +1);
				Destination += pTypeStr.length() +1;
				break;
			case '5':
				WSAData wsaData;
				WSAStartup(MAKEWORD(1, 1), &wsaData);
				pTypeStr =  string_to_hex(doit());
				WSACleanup();
				memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() +1);
				Destination += pTypeStr.length() +1;
				break;
			case '6':
				DWORD nSize;  
				nSize = sizeof( user_name ); 
				GetUserName( user_name, &nSize );    
				//std::string username = user_name;
				pTypeStr = user_name;
				memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() +1);
				Destination += pTypeStr.length() +1;
				break;
			case '7':
				CurlGet("http://madknight.net/ip.php",headers,response,error);
				pTypeStr = response.str();
				memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() +1);
				Destination += pTypeStr.length() +1;
				break;
			case 'm':
			case 'M':
				pTypeArray = va_arg(vArgs, char*);
				pTypeArrayLen = va_arg(vArgs, int);
				memcpy(Destination, pTypeArray, pTypeArrayLen);
				Destination += pTypeArrayLen;
				break;
			case 'X':
				pTypeDword = calle;
				memcpy(Destination, &pTypeDword, sizeof(unsigned long));
				Destination += sizeof(unsigned long);
				break;
			case 'Y':
				pTypeDword = speed;
				memcpy(Destination, &pTypeDword, sizeof(unsigned long));
				Destination += sizeof(unsigned long);
				break;
			case 'Z':
				pTypeDword = packet_C;
				memcpy(Destination, &pTypeDword, sizeof(unsigned long));
				Destination += sizeof(unsigned long);
				break;
			default:
				break;
			}
		}
		
	}
}

void CompileNorm(char* Destination, int Size, std::string Format, va_list vArgs)
{
	unsigned char pTypeByte = 0;
	unsigned short pTypeWord = 0;
	unsigned long pTypeDword = 0;
	float pTypeFloat = 0.0;
	double pTypeDouble = 0.0;
	unsigned __int64 pTypeQword = 0;
	std::string pTypeStr;
	char* pTypeArray = NULL;
	int pTypeArrayLen = 0;

	for(size_t i=0; i < Format.length();i++)
	{
		switch (Format[i])
		{
		case 'b':
		case 'B':
			pTypeByte = va_arg(vArgs, unsigned char);
			memcpy(Destination, &pTypeByte, sizeof(unsigned char));
			Destination += sizeof(unsigned char);
			break;
		case 'w':
		case 'W':
			pTypeWord = va_arg(vArgs, unsigned short);
			memcpy(Destination, &pTypeWord, sizeof(unsigned short));
			Destination += sizeof(unsigned short);
			break;
		case 'd':
		case 'U':
			pTypeDword = va_arg(vArgs, unsigned long);
			memcpy(Destination, &pTypeDword, sizeof(unsigned long));
			Destination += sizeof(unsigned long);
			break;
		case 'f':
			pTypeFloat = va_arg(vArgs, float);
			memcpy(Destination, &pTypeFloat, sizeof(float));
			Destination += sizeof(float);
			break;
		case 'D':
			pTypeDouble = va_arg(vArgs, double);
			memcpy(Destination, &pTypeDouble, sizeof(double));
			Destination += sizeof(double);
			break;
		case 'I':
			pTypeQword = va_arg(vArgs, unsigned __int64);
			memcpy((void*)Destination,(void*)&pTypeDword,8);
			Destination+= 8;
		case 's':
		case 'S':
			pTypeStr = va_arg(vArgs, char*);
			memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() +1);
			Destination += pTypeStr.length() +1;
			break;
		case 'm':
		case 'M':
			pTypeArray = va_arg(vArgs, char*);
			pTypeArrayLen = va_arg(vArgs, int);
			memcpy(Destination, pTypeArray, pTypeArrayLen);
			Destination += pTypeArrayLen;
			break;
		default:
			break;
		}
	}
}

#define INST_NOP  0x90
#define INST_CALL 0xE8
#define INST_JMP  0xE9
#define INST_BYTE 0x00
#define SHORT_JZ  0x74
#define STD_CALL_LEN 0x05
#define INST_JMPR  0xEB
#define INST_RET 0xC3
#define _DWORD DWORD
#define _WORD WORD
#define _BYTE BYTE





void *DetourFunction(BYTE *src, const BYTE *dst, const int len) // credits to gamedeception
{
	BYTE *jmp = (BYTE*)malloc(len+5);
	DWORD dwback;
	VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len); jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src+1) = (DWORD)(dst - src) - 5;
	VirtualProtect(src, len, dwback, &dwback);
	return (jmp-len);
}


DWORD Intercept(int instruction, DWORD source, DWORD destination, int length)
{
	DWORD realTarget;
	LPBYTE buffer = new BYTE[length];

	memset(buffer,0x90,length); 

	if(instruction != INST_NOP && length >= 5)
	{
		buffer[(length-5)] = instruction;
		DWORD dwJMP = (DWORD)destination - (source + 5 + (length-5));
		memcpy(&realTarget,(void*)(source+1),4);
		realTarget = realTarget + source + 5;
		memcpy(buffer + 1 + (length - 5),&dwJMP,4);
	}

	if(instruction == SHORT_JZ)
	{
		buffer[0] = instruction;
		buffer[1] = (BYTE)destination;
	}

	if(instruction == INST_BYTE)
	{
		buffer[0] = (BYTE)destination;
	}

	MemoryCopy(source,(DWORD)buffer,length);
	delete[] buffer;

	return realTarget;
}







typedef int (__cdecl *WREngineFunc)(void);                
typedef int (__thiscall *RefreshEntities)(void*);    
DWORD WREngineFuncPtr = 0x004a73b0;                                    
DWORD RefreshEntitiesPtr = 0x00425960;                                   
BYTE *WREngineActive = (BYTE*)0x006ddf58;                                
int MaxFPS = 60;                                                
int MaxTime = (1000/MaxFPS);                                         
DWORD SleepTime;                                    


WPARAM __fastcall WorldRefresh(void *thisPointer, void* _edx) 
{
	void *that; 
	char state; 
	struct tagMSG Msg; 
	HACCEL hAccel; 
	int PerformanceTime; 
	unsigned __int64 lpFrequency; 
	unsigned __int64 lpPerformanceCount; 
	unsigned __int64 lpPerformanceStep; 
	that = thisPointer; 
	QueryPerformanceFrequency((LARGE_INTEGER*)&lpFrequency);
	hAccel = LoadAcceleratorsA(NULL, (LPCSTR)0x71); 
	Msg.message = 0; 
	PeekMessageA(&Msg, NULL, WM_NULL, WM_NULL, PM_NOREMOVE); 
	while (Msg.message != 0x12) 
	{
		__asm pushad 
		if (*((BYTE*)that+0x9d)) state = (!!PeekMessageA(&Msg, NULL, WM_NULL, WM_NULL, PM_REMOVE)); 
		else state = (!!GetMessageA(&Msg, NULL, 0, 0)); 
		if (state) 
		{ 
			if ((!hAccel) || (!(*(DWORD*)that+0x38)) || (!TranslateAcceleratorA(*((HWND*)that+0x38), hAccel, &Msg))) 
			{ 
				TranslateMessage(&Msg); 
				DispatchMessageA(&Msg); 
			} 
			((WREngineFunc)WREngineFuncPtr)(); 
		} 
		else 
		{ 
			if ((*((BYTE*)that+0x9d)) && (*(BYTE*)WREngineActive)) 
			{ 
				QueryPerformanceCounter((LARGE_INTEGER*)&lpPerformanceCount); 
				int tmpActive = ((RefreshEntities)RefreshEntitiesPtr)(that); 

				QueryPerformanceCounter((LARGE_INTEGER*)&lpPerformanceStep); 
				if (tmpActive < 0) SendMessageA(*((HWND*)that+0x38), WM_COMMAND, 0x9C46, 0); 

				PerformanceTime = (int)(lpFrequency / (lpPerformanceStep-lpPerformanceCount)); 
				if (PerformanceTime) PerformanceTime = 1000 / PerformanceTime; 
				if (MaxTime > PerformanceTime) 
				{ 
					SleepTime = (MaxTime - PerformanceTime); 
					Sleep(SleepTime); 
				} 
			} 
		} 
		__asm popad 
	} 
	if (hAccel) DestroyAcceleratorTable(hAccel); 
	return Msg.wParam; 
}


void HookWorldRefresh()
{
	Intercept(INST_CALL,0x00505869,(DWORD)WorldRefresh,5); 
	Intercept(INST_CALL,0x00505bfc,(DWORD)WorldRefresh,5); 
}




LPVOID MemcpyExS(DWORD lpDest, DWORD lpSource, int len)
{
	DWORD oldSourceProt,oldDestProt=0;
	VirtualProtect((LPVOID)lpSource,len,PAGE_EXECUTE_READWRITE,&oldSourceProt);
	VirtualProtect((LPVOID)lpDest,len,PAGE_EXECUTE_READWRITE,&oldDestProt);
	memcpy((void*)lpDest,(void*)lpSource,len);
	VirtualProtect((LPVOID)lpDest,len,oldDestProt,&oldDestProt);
	VirtualProtect((LPVOID)lpSource,len,oldSourceProt,&oldSourceProt);
	return (LPVOID)lpDest;
};

bool bDataCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for(;*szMask;++szMask,++pData,++bMask)
		if(*szMask=='x' && *pData!=*bMask )
			return false;
	return (*szMask) == NULL;
}

DWORD dwFindPattern(DWORD dwAddress,DWORD dwLen, BYTE *bMask, char * szMask) 
{
	for(DWORD i=0;i<dwLen;i++)
		if( bDataCompare( (BYTE*)( dwAddress+i ),bMask,szMask) )
			return (DWORD)(dwAddress+i);
	return NULL;
}


