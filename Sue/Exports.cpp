#include "StdAfx.h"
#include <string>
#include "Exports.h"
#include "Interface.h"

CREATE_INTERFACE(IExports)

FARPROC IExports::p[];
unsigned long IExports::_p;

void IExports::Initialize()
{
	wchar_t *_system = new wchar_t[MAX_PATH];
	GetSystemDirectoryW(_system, MAX_PATH);
	std::wstring _syspath = _system;
	delete _system;
	_syspath += L"\\gdi32.dll";
	this->hL = LoadLibraryW(_syspath.c_str());

	p[0] = GetProcAddress(this->hL, "SetTextColor");
	p[1] = GetProcAddress(this->hL, "TextOutA");
	p[2] = GetProcAddress(this->hL, "GetTextMetricsA");

}

extern "C" __declspec(naked) void __stdcall __E__0__() { IExports::_p = (unsigned long)IExports::p[0]; __asm jmp IExports::_p }
extern "C" __declspec(naked) void __stdcall __E__1__() { IExports::_p = (unsigned long)IExports::p[1]; __asm jmp IExports::_p }
extern "C" __declspec(naked) void __stdcall __E__2__() { IExports::_p = (unsigned long)IExports::p[2]; __asm jmp IExports::_p }



