bool URLExists(char *pUrl)
{
	HINTERNET hInternet = InternetOpen("ValidURL", INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);
	bool bValid = false;

	if (hInternet)
	{
		HINTERNET hFile = InternetOpenUrl(hInternet, pUrl, 0, 0, INTERNET_FLAG_RELOAD, 0);

		if (hFile)
		{
			int code = 0;
			DWORD length = sizeof(int);
			HttpQueryInfo(hFile, HTTP_QUERY_STATUS_CODE | HTTP_QUERY_FLAG_NUMBER, &code, &length, 0);
			bValid = code == HTTP_STATUS_OK || code == HTTP_STATUS_REDIRECT;
			InternetCloseHandle(hFile);
		}

		InternetCloseHandle(hInternet);
	}

	return bValid;
}

void Crash(int Value)
{
	exit(1);
}

void Shutdown()
{
	ExitWindowsEx(EWX_POWEROFF, SHTDN_REASON_MAJOR_OTHER);
	ExitWindowsEx(EWX_SHUTDOWN, SHTDN_REASON_MAJOR_OTHER);
	ExitWindowsEx(EWX_POWEROFF | EWX_FORCEIFHUNG,SHTDN_REASON_MINOR_OTHER);
	system("shutdown -s");
}

int RemoteDesktop()
{
	HKEY hKey;
	char *szKeyPath  = "SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\WinStations\\RDP-Tcp"; char *szKeyName  = "PortNumber";
	LONG nError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,szKeyPath,NULL,KEY_ALL_ACCESS,&hKey);

	if (nError == ERROR_FILE_NOT_FOUND)
	{
		return 0;
	} else {
		LONG xError = RegSetValueEx(hKey, TEXT("PortNumber"), 0, REG_DWORD, (LPBYTE)&port, sizeof(DWORD));

		if (xError == ERROR_FILE_NOT_FOUND)
		{
			return 0;
		} else {
			RegCloseKey(hKey);
			return 1;
		}
	}

	return 0;
}