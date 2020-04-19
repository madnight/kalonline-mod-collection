#include "StdAfx.h"
#include "Hooks.h"

#include "Interface.h"

#include "Process.h"


void __fastcall Hooks::CSocket::Login(void* Socket, void* _edx, int nId, int nUID)
{
	Interface<IProcess> Process;
	Process->Login(Socket, nId, nUID);
}
