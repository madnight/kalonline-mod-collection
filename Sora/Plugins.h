#ifndef __PLUGINS_H
#define __PLUGINS_H

#include <vector>
#include <string>

class Module
{
	private:
		std::string m_Name, m_Description, m_Author, m_Version;
		HMODULE m_hModule;
		unsigned long m_PluginID;

	public:
		Module(std::wstring Name);
		~Module();

		void Install();
		void Uninstall();
		void ReloadConfig();

		HMODULE GetModule();
};

class IPlugins
{
	private:
		std::vector<Module*> m_Plugins;

	public:
		IPlugins();

		void Load();
};

#endif