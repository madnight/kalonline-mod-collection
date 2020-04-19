void Loader()
{
	std::string Path = "./Loader/";
	WIN32_FIND_DATA DataFound;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	CreateDirectory(Path.c_str(), NULL);
	Path += "*.dll";
	hFind = FindFirstFile(Path.c_str(), &DataFound);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do 
		{
			if (!(DataFound.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				std::string FullName = "./Loader/" + (std::string)DataFound.cFileName;
				LoadLibrary(FullName.c_str());
			}
		} while (FindNextFile(hFind, &DataFound));
	}

	FindClose(hFind);
}