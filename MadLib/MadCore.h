#ifndef _MADCORE_H_
#define _MADCORE_H_
#pragma comment(lib, "detours.lib")


#undef UNICODE
#include <cstdio>
#include <windows.h>
#include <detours.h> 
#include <process.h>
#include <vector>
#include "Memory.h"

class MadCore
{
private:
	DWORD call_reason;
	std::vector<PVOID*> sources;
	std::vector<PVOID> destinations;
	std::vector<unsigned long> hook_sources;
	std::vector<PVOID> hook_destinations;
	void Attach();
	void Detach();
public:
	MadCore(DWORD call_reason){this->call_reason = call_reason;}
	void Boot(DWORD call_reason);
	void Register(PVOID* source, PVOID dest);
	void RegisterHook(unsigned long source, PVOID dest);
	void RegisterCustom(void (*pfunc)());
	bool Run();
};
#endif