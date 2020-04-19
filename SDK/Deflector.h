#ifndef __DEFLECTOR_H
#define __DEFLECTOR_H

#include <map>
#include <string>
#include <vector>

#include "Lock.h"

#ifdef SORA_BASE
#define SORA_API __declspec(dllexport)
#else
#define SORA_API __declspec(dllimport)
#endif

struct __Observer
{
	Lock Lock;
	void *Pointer;
	void *This;
};
struct __Deflection
{
	unsigned long NumOfArguments;
	std::vector<__Observer> Observers;
	void *PriorityObserver;

	__Deflection() { PriorityObserver=NULL; NumOfArguments=0; }
};

class IDeflector
{
	private:
		Lock Lock;
		std::map<int, __Deflection> m_Deflections;

	public:
		#ifdef SORA_BASE
		IDeflector();
		~IDeflector();
		#endif

		SORA_API bool Implement(int Name, unsigned long NumOfArguments);

		SORA_API bool Register(int Name, void *This, void *observer);
		SORA_API bool Unregister(int Name, void *observer);

		SORA_API void Prioritize(int Name, void *observer);

		SORA_API bool Forward(int Name, ...);

		SORA_API static IDeflector* GetDeflectorInstance();
};

#endif