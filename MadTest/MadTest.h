/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
#include "../Server.h"

namespace MadTest
{
	//static void (__stdcall *Start)(int start) = (void (__stdcall*)(int start))0x00424A40;
	static int (__stdcall *WinMain)(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) = 
		(int (__stdcall*)(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd))0x00434600;

	void __stdcall WinMainHook(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
	{
		WinMain(hInstance,hPrevInstance,lpCmdLine,nShowCmd);
	}
	
	void __cdecl Write(const char *a1, char a2)
	{
			
	}

	
	int __fastcall Create(int* thispointer,void *_edx)
	{
		
	}


	BOOL __cdecl sub_421EC0(HANDLE hFile, LPCSTR arg4, ...)
	{
	}
}