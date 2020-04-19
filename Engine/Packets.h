#ifndef __PACKETS_H
#define __PACKETS_H

#include <string>
#include "Lock.h"
#include "Engine.h"

class IPackets
{
	public:
		std::string RecCaller;
		std::string Recall;
		bool DssUpdateCheck;
		void Hook();
		int Send(unsigned char Type, std::string Format, va_list Args);
		int Send(unsigned char Type, std::string Format, ...);
		bool Analyze(unsigned char PacketType, std::string Format, va_list vArgs);
		int Recv(Engine::Packet *Data);
		template<class T> int DigitColor(T Number);
};

class IPipe
{
	private:
		Lock Lock;
		HANDLE hPipe;
		size_t Size;
		char *Buffer;
		bool HasData;
		size_t DataSize;

	public:
		void Create();
		void Write(bool IsSend, std::string Format, const char* Data, size_t Size);
		static unsigned long __stdcall Thread(void* Param);
};

#endif