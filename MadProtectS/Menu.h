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
 

#define MYMENU_EXIT         (WM_APP + 101)
#define MYMENU_MESSAGEBOX   (WM_APP + 102) 

static LRESULT (__stdcall *Orig_DLLWindowProc)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	= (LRESULT (__stdcall*)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam))0x004348E0;

HINSTANCE  inj_hModule;         
HWND       prnt_hWnd;           

HMENU CreateDLLWindowMenu()
{
	HMENU hMenu;
	hMenu = CreateMenu();
	HMENU hMenuPopup;
	if(hMenu==NULL)
		return FALSE;
	hMenuPopup = CreatePopupMenu();
	return hMenu;
}

DWORD WINAPI ThreadProc( LPVOID lpParam )
{  
	HWND hWnd = prnt_hWnd;//FindWindow(NULL,TEXT("MainSvrt on port 30001"));
	HMENU hCurrent = GetMenu(hWnd);
	HMENU hNew     = CreateMenu();
	HMENU hMenuPopup;
	hMenuPopup = CreateDLLWindowMenu();
	AppendMenu (hCurrent, MF_POPUP, (UINT_PTR) hMenuPopup, TEXT("MadProtection")); 
	AppendMenuA(hMenuPopup, MF_STRING, 9505, "Reload Config");
	AppendMenuA(hMenuPopup, MF_STRING, 9506, "Print Config");
	AppendMenuA(hMenuPopup, MF_STRING, 9508, "Debug Mode");
	
	HMENU hMenubar = CreateMenu();
	HMENU hMenu = CreateMenu();
	HMENU hSubMenu = CreatePopupMenu();

	//AppendMenu(hMenuPopup, MF_STRING | MF_POPUP, (UINT_PTR)hSubMenu, "Exception Test");
	//AppendMenu(hSubMenu, MF_STRING, 9510, "Access Violation");
	//AppendMenu(hSubMenu, MF_STRING, 9511, "Division by Zero");

	AppendMenuA(hMenuPopup, MF_STRING, 9509, "Uptime");
	AppendMenuA(hMenuPopup, MF_STRING, 9507, "Info");


	
	//SetMenu(hNew, hMenubar);
	
	DrawMenuBar(hWnd); 
	return 1;
}

std::string Uptime(int startime)
{
	int tage,stunden,minuten,sekunden,up;

	up = GetTickCount() - startime;
	tage = up/(1000*60*60*24);
	stunden = (up-(tage*1000*60*60*24))/(1000*60*60);
	minuten = (up-(tage*1000*60*60*24)-(stunden*1000*60*60))/(1000*60);
	sekunden = (up-(tage*1000*60*60*24)-(stunden*1000*60*60)-(minuten*1000*60))/1000;

	std::ostringstream message;
	message << "The Server Uptime is "<< tage << " days " << stunden << " hours " << minuten << " mins " << sekunden << " seconds ";
	return message.str();
}

LRESULT __stdcall Hooked_DLLWindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	prnt_hWnd = hWnd;
	IMadDatabase* maddb = new IMadDatabase(&config,database);
	std::string version = "Mad Protection Version ";
	version.append(VERSION);
	switch (Msg)
	{
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case 9505:
			maddb->Load_Config_MadProtectS();
			Server::Console::WriteBlue("[MadProtectS config reloaded]");
		case 9506:
			Server::Console::WriteBlack("---------------------------------------- MadProtectS Config ---------------------------------------- ");
			Server::Console::WriteBlack("[Protect]");
			Server::Console::WriteBlack("Checksum = %i",config.SHA_ENABLED);
			Server::Console::WriteBlack("HardwareID = %i",config.HWID_ENABLED);
			Server::Console::WriteBlack("CallerCheck = %i",config.CALLER_CHECK);
			//Server::Console::WriteBlack("PacketVerify = %i",config.PACKET_VERIFY);
			Server::Console::WriteBlack("SpeedCheck = %i",config.CLIENT_SPEEDCHECK);
			Server::Console::WriteBlack("UgOgCheck = %i",config.UG_OG_CHECK);
			Server::Console::WriteBlack("");
		    Server::Console::WriteBlack("MaxAttack = %i",config.MAX_ATTACK);
			Server::Console::WriteBlack("MaxDamage = %i",config.MAX_FINAL_DAMAGE);
			Server::Console::WriteBlack("MaxZ = %i",config.MAX_Z_VALUE);
			Server::Console::WriteBlack("MinZ = %i",config.MIN_Z_VALUE);
			Server::Console::WriteBlack("MaxSpeed = %i",config.MAX_MOVE_SPEED);
			Server::Console::WriteBlack("");
			Server::Console::WriteBlack("[Misc]");
			Server::Console::WriteBlack("WelcomeMsg = %s",config.Weclome_Message.c_str());
			Server::Console::WriteBlack("PlayerOnMsg = %i",config.PLAYERON_MSG);
			Server::Console::WriteBlack("ChatLog = %i",config.CHAT_LOG);
		//	Server::Console::WriteBlack("ExceptionReport = %i",config.EXCEPTION_REPORT);
			Server::Console::WriteBlack("");
			Server::Console::WriteBlack("[Checksum]");
			Server::Console::WriteBlack("Engine = %s",config.Engine_SHA.c_str());
			Server::Console::WriteBlack("MadHelp = %s",config.MadHelp_SHA.c_str());
			Server::Console::WriteBlack("Configpk = %s",config.Configpk_SHA.c_str());
			Server::Console::WriteBlack("Epk = %s",config.Epk_SHA.c_str());
			Server::Console::WriteBlack("---------------------------------------- MadProtectS Config ---------------------------------------- ");
			break;
		case 9507:
			MessageBoxA(hWnd, "This Protection is made by MadKnight.\nIt have an complete selfwritten SendMethod.\nPackethacks based on Clean, KOSP/R11 or KoemV1/V2\nSendmethods do not work.\nMadProtectS and MadHelp are crypted with Themida to avoid cracking.\n\n© 2013 MadKnight", version.c_str() ,MB_OK);
			break;
		case 9509:
			MessageBoxA(hWnd,Uptime(config.START_TIME).c_str(),"Uptime",MB_OK);
			break;
		case 9510:
			config.ACCESS_VIOLATION_TEST = 1;
			Server::Console::WriteRed("ACCESS_VIOLATION_TEST enabled");
			break;
		case 9511:
			config.INTEGER_DIVISION_BY_ZERO_TEST = 1;
			Server::Console::WriteRed("INTEGER_DIVISION_BY_ZERO_TEST enabled");
			break;
		case 9508:
			if (!config.DEBUG_MODE)
			{
				Server::Console::WriteBlue("[MadProtectS Debug Mode on]");
				config.DEBUG_MODE = 1;
			}
			else
			{
				Server::Console::WriteBlue("[MadProtectS Debug Mode off]");
				config.DEBUG_MODE = 0;
			}
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage (0);
		break;
	default:
		delete maddb;
		return Orig_DLLWindowProc(hWnd, Msg, wParam, lParam);
	}
	delete maddb;
	return Orig_DLLWindowProc(hWnd, Msg, wParam, lParam);	
}

