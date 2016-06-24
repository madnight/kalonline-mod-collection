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
 
#include "Ultilities.h"

typedef int (__cdecl *WREngineFunc)(void);                
typedef int (__thiscall *RefreshEntities)(void*);    
DWORD WREngineFuncPtr = 0x004a73b0;                                    
DWORD RefreshEntitiesPtr = 0x00425960;                                   
BYTE *WREngineActive = (BYTE*)0x006ddf58;                                
int MaxFPS = 60;                                                
int MaxTime = (1000/MaxFPS);                                         
DWORD SleepTime;                                    


WPARAM __fastcall WorldRefresh(void *thisPointer, void* _edx) 
{
	void *that; 
	char state; 
	struct tagMSG Msg; 
	HACCEL hAccel; 
	int PerformanceTime; 
	unsigned __int64 lpFrequency; 
	unsigned __int64 lpPerformanceCount; 
	unsigned __int64 lpPerformanceStep; 
	that = thisPointer; 
	QueryPerformanceFrequency((LARGE_INTEGER*)&lpFrequency);
	hAccel = LoadAcceleratorsA(NULL, (LPCSTR)0x71); 
	Msg.message = 0; 
	PeekMessageA(&Msg, NULL, WM_NULL, WM_NULL, PM_NOREMOVE); 
	while (Msg.message != 0x12) 
	{
		__asm pushad 
		if (*((BYTE*)that+0x9d)) state = (!!PeekMessageA(&Msg, NULL, WM_NULL, WM_NULL, PM_REMOVE)); 
		else state = (!!GetMessageA(&Msg, NULL, 0, 0)); 
		if (state) 
		{ 
			if ((!hAccel) || (!(*(DWORD*)that+0x38)) || (!TranslateAcceleratorA(*((HWND*)that+0x38), hAccel, &Msg))) 
			{ 
				TranslateMessage(&Msg); 
				DispatchMessageA(&Msg); 
			} 
			((WREngineFunc)WREngineFuncPtr)(); 
		} 
		else 
		{ 
			if ((*((BYTE*)that+0x9d)) && (*(BYTE*)WREngineActive)) 
			{ 
				QueryPerformanceCounter((LARGE_INTEGER*)&lpPerformanceCount); 
				int tmpActive = ((RefreshEntities)RefreshEntitiesPtr)(that); 

				QueryPerformanceCounter((LARGE_INTEGER*)&lpPerformanceStep); 
				if (tmpActive < 0) SendMessageA(*((HWND*)that+0x38), WM_COMMAND, 0x9C46, 0); 

				PerformanceTime = (int)(lpFrequency / (lpPerformanceStep-lpPerformanceCount)); 
				if (PerformanceTime) PerformanceTime = 1000 / PerformanceTime; 
				if (MaxTime > PerformanceTime) 
				{ 
					SleepTime = (MaxTime - PerformanceTime); 
					Sleep(SleepTime); 
				} 
			} 
		} 
		__asm popad 
	} 
	if (hAccel) DestroyAcceleratorTable(hAccel); 
	return Msg.wParam; 
}


void HookWorldRefresh()
{
	Intercept(INST_CALL,0x00505869,(DWORD)WorldRefresh,5); 
	Intercept(INST_CALL,0x00505bfc,(DWORD)WorldRefresh,5); 
}



