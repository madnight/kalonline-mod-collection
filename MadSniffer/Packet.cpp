/* Copyright © 2010 by YeZZx */

#include "hPacket.h"

IPacket::IPacket()
{
	iPos = (unsigned int)0;
}

void IPacket::addBuffer(char *_Buffer, int _Size)
{
	unsigned int iOldSize = m_content.size();
	m_content.resize((iOldSize + _Size));
	memcpy(&m_content[iOldSize], _Buffer, _Size);
}

void IPacket::addByte(char _Byte)
{
	m_content.push_back(_Byte);
}

void IPacket::addShort(short _Short)
{
	IPacket::addByte(((char *)(&_Short))[0]);
	IPacket::addByte(((char *)(&_Short))[1]);
}

void IPacket::addInt(int _Int)
{
	IPacket::addByte(((char *)(&_Int))[0]);
	IPacket::addByte(((char *)(&_Int))[1]);
	IPacket::addByte(((char *)(&_Int))[2]);
	IPacket::addByte(((char *)(&_Int))[3]);
}

void IPacket::addString(char *_Data)
{
	unsigned int iLen = strlen(_Data);
	IPacket::addInt(iLen);
	IPacket::addBuffer(_Data, iLen);
}

char IPacket::getByte()
{
	if (iPos < m_content.size())
	{
		return m_content[iPos++];
	} else {
		return ((char *)(&new char))[0];
	}
}

int IPacket::getInt()
{
	int iR = (int)0;
	((char *)&iR)[0] = IPacket::getByte();
	((char *)&iR)[1] = IPacket::getByte();
	((char *)&iR)[2] = IPacket::getByte();
	((char *)&iR)[3] = IPacket::getByte();
	return iR;
}

void IPacket::setInt(int _iPos, unsigned int _Value)
{
	m_content[_iPos] = ((char *)(&_Value))[0];
	m_content[_iPos + 1] = ((char *)(&_Value))[1];
	m_content[_iPos + 2] = ((char *)(&_Value))[2];
	m_content[_iPos + 3] = ((char *)(&_Value))[3];
}

unsigned int IPacket::getSize()
{
	return m_content.size();
}

char *IPacket::getData()
{
	return &m_content[0];
}