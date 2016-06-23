#include <winsock2.h>
#include "../detours 1.5/include/detours.h"

#include "../Server.h"
#include <iostream>

#include "hPacket.h"

#include <fstream>
#include <string>
#include <detours.h> 
#include <windows.h>
#include <ctime>
#include "Utilities.h"
#include <MadCore.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>

#include <string>
#include <sstream>
#include <iostream>

#pragma comment(lib, "MadLib.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "detours.lib")

#define DATA_BUFSIZE 32768

using namespace std;
#pragma pack(1)

static void (__thiscall *Process)(void *Socket, const char* Data) = (void (__thiscall*)(void*, const char*))0x00494930;
static void (__cdecl *Write)(void *Player, unsigned char Type, const char* Format, ...) = (void (__cdecl*)(void*, unsigned char, const char*, ...))0x00452e60;

static void (__thiscall *CIOSocket__Read) (int thisp, size_t a2) = (void (__thiscall*)(int thisp, size_t a2))0x00424440; 

FILE* pSendLogFile;
FILE* pRecvLogFile;




extern "C" int (WINAPI *pRecv)(SOCKET s, char* buf, int len, int flags) = recv;
int WINAPI MyRecv(SOCKET s, char* buf, int len, int flags);

int WINAPI MyRecv(SOCKET s, char* buf, int len, int flags)
{
	printf("TEST");
	printf("%s\n", buf);
	return pRecv(s, buf, len, flags);
}

HANDLE CreateConsole();
std::ofstream Logger;


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




void print_bytes(const void *object, size_t size)
{
	char bytesBuffer[16];
	size_t i;
	std::stringstream msg (std::stringstream::in | std::stringstream::out);
	msg << "[ ";
	for(i = 0; i < size; i++)
	{
		sprintf_s(bytesBuffer, sizeof(bytesBuffer),"%02x ", ((const unsigned char *) object)[i] & 0xff);
		msg << bytesBuffer;
	}
	msg << "]\n"; 
	printf( const_cast<char*>(msg.str().c_str()));
}

vector<vector<unsigned char>> Packet_Content_Filter;






#define CONFIG_FILE "PacketFilterConfig.ini"

void loadFilter()
{
	char sMessage[500];
	string prefix_content = "[PACKET_CONTENT_FILTER]";
	ifstream f;
	string s;
	string t;
	ifstream ifile(CONFIG_FILE);
	if (ifile) 
	{
		f.open(CONFIG_FILE, ios::in);
		while (!f.eof())        
		{
			getline(f, s);      
			if (s.substr(0, prefix_content.size()) == prefix_content) 
			{
				getline(f, s);
				t = (s.substr(0,1024));	
				sprintf_s(sMessage, sizeof(sMessage), " [PACKET_CONTENT_FILTER] -> %s installed \n\n", t.c_str());
				__asm lea eax, sMessage
				__asm push eax
				__asm mov edx, printf
				__asm call edx
				//printf(sMessage);
				vector<unsigned char> temp;
				std::istringstream hex_chars_stream(t);
				unsigned int c;
				while (hex_chars_stream >> std::hex >> c)
				{
					temp.push_back(c);
				}
				Packet_Content_Filter.push_back(temp);
			}


		}		
	}
	f.close();

}






BOOL check_bytes(const void *object, size_t size)
{

	for (int i=0;i<Packet_Content_Filter.size();i++)
	{

		int x = 0;
		for(x;x<size && x<Packet_Content_Filter.at(i).size();x++)
		{
			if (  Packet_Content_Filter.at(i).at(x) != 0x00)
				if (((const unsigned char *) object)[x] != Packet_Content_Filter.at(i).at(x))
					break;
		}
		if (x == Packet_Content_Filter.at(i).size())
			return FALSE;

	}

	return TRUE;
}


void __fastcall CSocketProcessObserver(void *Socket, void *_edx, char* Data)
{

	unsigned short Size;
	unsigned char Type;

	char* content = ParseData(Data, "wb", &Size, &Type);

	time_t t = time(0);   
	struct tm * now = localtime(&t);

	char* ip = inet_ntoa(((struct in_addr*)Socket)[35]);

	FILE* pSendLogFile;

	char filename[100];


	sprintf_s(filename, sizeof(filename),"Log\\MadSnifferLog_%04d_%02d_%02d_%02d_%02d.txt", now->tm_year+1900, now->tm_mon+1, 
		now->tm_mday, now->tm_hour, now->tm_min);

	pSendLogFile = fopen(filename, "a+");

	//printf( "%04d/%02d/%02d %02d:%02d:%02d [MadSniffer] Packet from IP:%s \nType: %s (0x%02x) \n",now->tm_year+1900, now->tm_mon, 
	//	now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec , ip, Header(Data) ,Type);

	//	std::ostringstream msg = print_bytes(Data,Size);

	fprintf(pSendLogFile, "%04d/%02d/%02d %02d:%02d:%02d [MadSniffer] Packet from IP:%s - Type: %s (0x%02x)  Size:%i \n",now->tm_year+1900, now->tm_mon+1, 
		now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec , ip, Header(Data) ,Type, Size);
	fclose(pSendLogFile);

	Process(Socket, Data);
}

char const hexd[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',   'B','C','D','E','F'};

std::string byte_2_str(char* bytes, int size) {
	std::string str;
	//std::string temp;
	for (int i = 0; i < size; ++i) {
		const char ch = bytes[i];
		str.append(&hexd[(ch  & 0xF0) >> 4], 1);
		str.append(&hexd[ch & 0xF], 1);
		str.append(" ");
	}
	return str;
}

void ParsePacket(char *sPacket, int iLen)
{
	IPacket Packet;
	Packet.addBuffer(sPacket, iLen);
	char bByte = Packet.getByte();
	print_bytes(&bByte,iLen);
	//return check_bytes(&bByte,iLen);
}

extern "C" int (WINAPI *pWSARecv)(SOCKET,LPWSABUF,DWORD,LPDWORD,LPDWORD,LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE) = WSARecv;
int             WINAPI MyWSARecv (SOCKET,LPWSABUF,DWORD,LPDWORD,LPDWORD,LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE);
typedef int (WINAPI *WSA_recv) (SOCKET, LPWSABUF , DWORD, LPDWORD, LPDWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE );
WSA_recv Recv_original = NULL;


//extern "C" BOOL(WINAPI *pGetQueuedCompletionStatus) (HANDLE, LPDWORD, PULONG_PTR, LPOVERLAPPED *, DWORD) = GetQueuedCompletionStatus;
//BOOL            WINAPI MyGetQueuedCompletionStatus  (HANDLE, LPDWORD, PULONG_PTR, LPOVERLAPPED *, DWORD);
typedef int (WINAPI *pGetQueuedCompletionStatus_hook) (HANDLE, LPDWORD, PULONG_PTR, LPOVERLAPPED *, DWORD );
pGetQueuedCompletionStatus_hook Q_original = NULL;

char *WSARecvBuffer;
int WINAPI Recv_hook(SOCKET s,LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine)
{

	bool forward = true;

	if (lpBuffers->buf != NULL)
		WSARecvBuffer = lpBuffers->buf;
	else
		WSARecvBuffer = 0;

	for (int x = 0; x < (int)dwBufferCount; x++)
		if (lpBuffers[x].buf[0] != 0 )
		{
			IPacket Packet;
			Packet.addBuffer(lpBuffers[x].buf,  60);
			char bByte = Packet.getByte();
			print_bytes(&bByte,60);
			forward = check_bytes(&bByte,60);

			if(!forward)
				Server::Console::WriteBlue("Filtered in WSARecv!");

			std::cout << std::endl;	
		}// ( sizeof(lpBuffers[x].buf) / sizeof(lpBuffers[x].buf[0]) - 1) );
		//std::cout << byte_2_str(lpBuffers[x].buf,sizeof(lpBuffers[x].buf)*20);	//printf("%s ",lpBuffers[x].buf);


		//printf("%x %i %i %s",lpBuffers[x].buf, lpBuffers[x].len, 1, s);
		//	Sleep(10);
		if ( forward)
			return Recv_original( s, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpOverlapped, lpCompletionRoutine);
		else
			return WSA_IO_PENDING;
}



   CRITICAL_SECTION cs; 
    HANDLE t;

BOOL WINAPI MyGetQueuedCompletionStatus (HANDLE CompletionPort, LPDWORD lpBytesTransferred, PULONG_PTR lpCompletionKey, LPOVERLAPPED *lpOverlapped, DWORD dwMilliseconds)
{
	EnterCriticalSection(&cs); 

	t = GetCurrentThread();
	//Sleep(10000);
	// I wouldn't touch shit here, you may fuckup the proxy
	//int retn = Q_original(CompletionPort, lpBytesTransferred, lpCompletionKey, lpOverlapped, dwMilliseconds);


	//	if ((int)*lpBytesTransferred <= 0)
	//	return retn;
	Server::Console::WriteBlue("%i",lpCompletionKey);

			//	Server::Console::WriteBlue("%i",*(DWORD *)lpCompletionKey + 20);
	bool forward = true;

	if (lpBytesTransferred > 0 && WSARecvBuffer)
	{


		
		IPacket Packet;
		Packet.addBuffer(WSARecvBuffer,  60);
		char bByte = Packet.getByte();
		print_bytes(&bByte,60);
		forward = check_bytes(&bByte,60);

		if(!forward)
		{
			Server::Console::WriteBlue("Filtered in MyGetQueuedCompletionStatus!");
			//CloseHandle(t);
			//__asm mov edx, 0x00423ED5
		//	__asm jmp edx
		}

		Sleep(100);
		std::cout << std::endl; std::cout << std::endl;
		//	HandleMessage(WSARecvBuffer, *lpBytesTransferred, 0, (SOCKET) CompletionPort);
	}
	LeaveCriticalSection(&cs); 
	if(forward)
		return Q_original(CompletionPort, lpBytesTransferred, lpCompletionKey, lpOverlapped, dwMilliseconds);
	else
		return 0;
}


/**
void __cdecl CIOSocket__IOThread()
{
  HANDLE v0; // eax@1
  unsigned __int32 CompletionKey; // [sp+0h] [bp-10h]@2
  int v2; // [sp+4h] [bp-Ch]@2
  DWORD NumberOfBytesTransferred; // [sp+8h] [bp-8h]@2
  LPOVERLAPPED Overlapped; // [sp+Ch] [bp-4h]@2

  v0 = GetCurrentThread();
  SetThreadIdealProcessor(v0, 32u);
  while ( 1 )
  {
    v2 = GetQueuedCompletionStatus(CompletionPort, &NumberOfBytesTransferred, &CompletionKey, &Overlapped, 4294967295u);
    InterlockedIncrement(&RunningThreadCount);
    (*(void (__thiscall **)(unsigned __int32, int, DWORD, LPOVERLAPPED))(*(_DWORD *)CompletionKey + 20))(
      CompletionKey,
      v2,
      NumberOfBytesTransferred,
      Overlapped);
    InterlockedDecrement(&RunningThreadCount);
  }
}
**/



BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	
	CreateConsole();
	//	MadCore core(ul_reason_for_call);
	//core.Register(&(PVOID&)Process,(PVOID)CSocketProcessObserver);
	switch(ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		loadFilter();
		 InitializeCriticalSection(&cs); 
		Recv_original = (WSA_recv)DetourFunction((PBYTE)&WSARecv, (PBYTE)&Recv_hook);
		Q_original = (pGetQueuedCompletionStatus_hook)DetourFunction((PBYTE)&GetQueuedCompletionStatus, (PBYTE)&MyGetQueuedCompletionStatus);
		//  Recv_original = (WSA_recv)DetourFunction((PBYTE)0x0042454A, (PBYTE)&Recv_hook);
		break;
	case DLL_PROCESS_DETACH:

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;

	//core.RegisterHook(0x0042454A,Recv_hook);
	//return core.Run();
}