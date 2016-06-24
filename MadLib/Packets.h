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
 
#ifndef __PACKETS_H
#define __PACKETS_H

#include <string>

class IPackets
{
	public:
		void Hook();

		int Send(unsigned char Type, std::string Format, va_list Args);
		int Send(unsigned char Type, std::string Format, ...);
		bool Analyze(unsigned char PacketType, std::string Format, va_list vArgs);

	//	int Recv(Engine::Packet *Data);

		//template<class T> int DigitColor(T Number);
};

class IPipe
{
	private:
		//Lock Lock;
	//	HANDLE hPipe;
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