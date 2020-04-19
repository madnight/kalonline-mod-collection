#include "StdAfx.h"
#include <string>
#include "Interface.h"
#include "Deflector.h"
#include "InitMods.h"
#pragma comment(lib, "Sora.lib")

/* No Interface - Clear symbol exporting */

const char *PluginName = "Pulse";
const char *PluginDescription = "Server HeartBeat Plugin";
const char *PluginAuthor = "Kealy sirix strik3r";
const char *PluginVersion = "0.01";

extern "C"
{
    __declspec(dllexport) unsigned long __cdecl nGetPluginID() {
        return PLUGIN_ID;
    }
    __declspec(dllexport) const char* __cdecl nGetPluginName() {
        return PluginName;
    }
    __declspec(dllexport) const char* __cdecl nGetPluginDescription() {
        return PluginDescription;
    }
    __declspec(dllexport) const char* __cdecl nGetPluginAuthor() {
        return PluginAuthor;
    }
    __declspec(dllexport) const char* __cdecl nGetPluginVersion() {
        return PluginVersion;
    }
};

extern "C" __declspec(dllexport) void __cdecl nInitializePlugin(HMODULE hModule)
{
    // Start everything here - no DllMain()
    Mods::Initialize();
}

extern "C" __declspec(dllexport) void __cdecl nUninstallPlugin()
{
    // Delete all the interfaces
    Interface<void>::Purge();
}

