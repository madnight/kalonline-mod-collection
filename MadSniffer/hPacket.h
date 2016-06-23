/* Copyright © 2010 by YeZZx */
#include "Windows.h"
#include <vector>

class IPacket
{
	public:
		IPacket();
		void addBuffer(char *_Buffer, int _Size);
		void addByte(char _bByte);
		void addShort(short _Short);
		void addInt(int _Int);
		void addString(char *_Data);
		char getByte();
		int getInt();
		void setInt(int _iPos, unsigned int _Value);
		unsigned int getSize();
		char *getData();
	protected:
		unsigned int iPos;
		std::vector<char> m_content;
};