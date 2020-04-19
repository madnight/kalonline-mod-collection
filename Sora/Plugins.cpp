#include "StdAfx.h"
#include "Plugins.h"
#include <string>
#include "Interface.h"
#include "Server.h"

CREATE_INTERFACE(IPlugins)

IPlugins::IPlugins()
{
    this->Load();
}

void IPlugins::Load()
{
    // Loading modules in ./Plugins/

    std::wstring Path = L"./Plugins/";
    WIN32_FIND_DATA DataFound;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    CreateDirectory(Path.c_str(), NULL);

    Path += L"*.dll";
    hFind = FindFirstFile(Path.c_str(), &DataFound);

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!(DataFound.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                // found a dll, let's load it.
                std::wstring FullName = L"./Plugins/" + (std::wstring)DataFound.cFileName;

                Module *Plugin = new Module(FullName);
                if (Plugin->GetModule()) this->m_Plugins.push_back(Plugin);
                else delete Plugin;
            }
        } while (FindNextFile(hFind, &DataFound));
    }
    FindClose(hFind);
}

Module::Module(std::wstring Name)
{
    this->m_hModule = LoadLibrary(Name.c_str());
    if (this->m_hModule) this->Install();
}

Module::~Module()
{
    if (this->m_hModule)
    {
        this->Uninstall();
        FreeLibrary(this->m_hModule);
    }
}

void Module::Install()
{
    typedef void (__cdecl *PLUGIN_INIT)(HMODULE);
    PLUGIN_INIT InitializePlugin = (PLUGIN_INIT)GetProcAddress(this->m_hModule, "nInitializePlugin");

    if (InitializePlugin)
    {
        FARPROC GetName = GetProcAddress(this->m_hModule, "nGetPluginName");
        FARPROC GetDescription = GetProcAddress(this->m_hModule, "nGetPluginDescription");
        FARPROC GetAuthor = GetProcAddress(this->m_hModule, "nGetPluginAuthor");
        FARPROC GetVersion = GetProcAddress(this->m_hModule, "nGetPluginVersion");
        FARPROC GetPluginID = GetProcAddress(this->m_hModule, "nGetPluginID");

        this->m_PluginID = GetPluginID();
        this->m_Name = GetName();
        this->m_Description = GetDescription();
        this->m_Author = GetAuthor();
        this->m_Version = GetVersion();

        InitializePlugin(this->m_hModule);
    }
    else
    {
        FreeLibrary(this->m_hModule);
        this->m_hModule = NULL;
    }
}

void Module::Uninstall()
{
    FARPROC UninstallPlugin = GetProcAddress(this->m_hModule, "nUninstallPlugin");
    if (UninstallPlugin) UninstallPlugin();
}

HMODULE Module::GetModule() {
    return this->m_hModule;
}
