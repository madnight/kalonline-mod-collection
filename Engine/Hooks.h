#ifndef __HOOKS_H
#define __HOOKS_H

#include "Engine.h"

namespace Hooks
{
namespace KCommand
{
int __cdecl ProcessCommand(const char* Text);
}

namespace KSocket
{
int __cdecl WritePacketAutoCrc(unsigned char Type, const char* Format, ...);
int __cdecl OnRecv(Engine::Packet *Data);
}

HWND __stdcall CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName,
        DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent,
        HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
}

#endif
