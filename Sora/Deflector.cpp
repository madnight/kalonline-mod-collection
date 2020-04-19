#include "StdAfx.h"
#include "Deflector.h"

#include "Interface.h"

CREATE_INTERFACE(IDeflector)

IDeflector::IDeflector()
{
}
IDeflector::~IDeflector()
{
}

IDeflector* IDeflector::GetDeflectorInstance()
{
	Interface<IDeflector> Deflector;
	return Deflector;
}

bool IDeflector::Implement(int Name, unsigned long NumOfArguments)
{
	bool Ret;

	this->Lock.Enter();
	this->m_Deflections[Name].NumOfArguments = NumOfArguments;
	Ret = true;
	this->Lock.Leave();

	return Ret;
}

bool IDeflector::Register(int Name, void *This, void *observer)
{
	bool Ret;

	this->Lock.Enter();
	if (this->m_Deflections.count(Name))
	{
		bool isFound = false;
		for(size_t i=0; i < this->m_Deflections[Name].Observers.size(); i++)
			if (this->m_Deflections[Name].Observers[i].Pointer == observer) { isFound = true; break; }

		if (!isFound)
		{
			__Observer Observer;
			Observer.Pointer = observer;
			Observer.This = This;
			this->m_Deflections[Name].Observers.push_back(Observer);
			Ret = true;
		}
		else Ret = false;
	}
	else
	{
		__Observer Observer;
		Observer.Pointer = observer;
		Observer.This = This;
		this->m_Deflections[Name].Observers.push_back(Observer);
		Ret = true;
	}
	this->Lock.Leave();

	return Ret;
}

bool IDeflector::Unregister(int Name, void *observer)
{
	bool Ret;

	this->Lock.Enter();
	if (this->m_Deflections.count(Name))
	{
		bool isFound = false;
		std::vector<__Observer>::iterator I = this->m_Deflections[Name].Observers.begin();
		while(I != this->m_Deflections[Name].Observers.end())
		{
			if ((*I).Pointer == observer) { isFound = true; break; }
			I++;
		}

		if (isFound)
		{
			(*I).Lock.Enter();
			this->m_Deflections[Name].Observers.erase(I);	// Lock should be destroyed here
		}
	}
	else Ret = false;
	this->Lock.Leave();

	return Ret;
}
void IDeflector::Prioritize(int Name, void *observer)
{
	this->Lock.Enter();
	if (this->m_Deflections.count(Name))
	{
		this->m_Deflections[Name].PriorityObserver = observer;
	}
	this->Lock.Leave();
}
bool IDeflector::Forward(int Name, ...)
{
	bool Block = false;

	this->Lock.Enter();
	
	if (this->m_Deflections.count(Name))
	{
		unsigned long NumOfArguments = this->m_Deflections[Name].NumOfArguments;

		// Search for prioritized observer
		size_t PObs = 0;
		if (this->m_Deflections[Name].PriorityObserver)
		{
			for(size_t i=0; i < this->m_Deflections[Name].Observers.size(); i++)
				if (this->m_Deflections[Name].Observers[i].Pointer == this->m_Deflections[Name].PriorityObserver) { PObs = i; break; }
		}

		for(size_t c=0; c < this->m_Deflections[Name].Observers.size(); c++)
		{
			size_t i = c;

			// Switching prioritized observer
			if (PObs)
			{
				if (!i) i = PObs;
				else if (i == PObs) i = 0;
			}


			// TryEnterCriticalSection here (important)
			// To allow safe plugin unloading
			if (this->m_Deflections[Name].Observers[i].Lock.TryEnter())
			{
				void *observer = this->m_Deflections[Name].Observers[i].Pointer;
				void *This = this->m_Deflections[Name].Observers[i].This;
				unsigned long Result;
			
				// Note : this could screw up if the variables in the for() loop were ESP-based.
				for(unsigned long EbpOffset = 12 + (4* NumOfArguments); EbpOffset > 12; EbpOffset-=4)
				{
					__asm mov eax, EbpOffset
					__asm push [ebp+eax]
				}
				__asm mov ecx, This
				__asm call observer
				__asm movzx ecx, al
				__asm mov Result, ecx

				this->m_Deflections[Name].Observers[i].Lock.Leave();

				if (Result) { Block = true; break; }
			}
		}
	}

	this->Lock.Leave();

	return Block;
}
