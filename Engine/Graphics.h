#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include "Lock.h"

class IGraphics
{
	protected:
		Lock m_Lock;

	public:
		void Lock();
		void Unlock();
};

#endif