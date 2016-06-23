#include "MadCore.h"

void MadCore::Register(PVOID *source, PVOID dest)
{
	if (this->call_reason == DLL_PROCESS_ATTACH)
	{
		this->sources.push_back(source);
		this->destinations.push_back(dest);
	}
}

void MadCore::RegisterHook(unsigned long source, PVOID dest)
{
	if (this->call_reason == DLL_PROCESS_ATTACH)
	{
		this->hook_sources.push_back(source);
		this->hook_destinations.push_back(dest);
	}
}


void MadCore::RegisterCustom(void (*pfunc)())
{
	if (this->call_reason == DLL_PROCESS_ATTACH)
	{
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		pfunc();
		DetourTransactionCommit();
	}
}


void MadCore::Attach()
{
	IMemory *Memory = new IMemory;
	for (unsigned int i = 0; i < this->sources.size() && i < this->destinations.size(); i++)
	{
		DetourAttach(this->sources[i],this->destinations[i]);
	}
	for (unsigned int i = 0; i < this->hook_sources.size() && i < this->hook_destinations.size(); i++)
	{
		Memory->Hook(this->hook_sources[i],this->hook_destinations[i]);
	}
	delete Memory;
}

void MadCore::Detach()
{
	for (unsigned int i = 0; i < this->sources.size() && i < this->destinations.size(); i++)
	{
		DetourDetach(this->sources[i],this->destinations[i]);
	}
	for (unsigned int i = 0; i < this->hook_sources.size() && i < this->hook_destinations.size(); i++)
	{
		DetourDetach((void**)&this->hook_sources[i],this->hook_destinations[i]);
	}
}

void MadCore::Boot(DWORD call_reason)
{
	this->call_reason = call_reason;
}

bool MadCore::Run()
{
	switch (this->call_reason)
	{
	case DLL_PROCESS_ATTACH:
		{
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			this->Attach();
			DetourTransactionCommit();
			break;
		}
	case DLL_PROCESS_DETACH:
		{
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			this->Detach();
			DetourTransactionCommit();
			break;
		}
	}
	return TRUE;
}