#ifndef __LOCK_H
#define __LOCK_H

#include <Windows.h>

class Lock
{
	private:
		CRITICAL_SECTION _CriticalSection;
		bool Locked;

	public:
		Lock() { this->Locked = false; InitializeCriticalSection(&this->_CriticalSection); }
		virtual ~Lock() { DeleteCriticalSection(&this->_CriticalSection); }
		void Enter() { EnterCriticalSection(&this->_CriticalSection); this->Locked = true; }
		void Leave() { this->Locked = false; LeaveCriticalSection(&this->_CriticalSection); }
		bool IsLocked() { return this->Locked; }
};

#endif