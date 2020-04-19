#ifndef __TOOLS_H
#define __TOOLS_H

#include <vector>
#include <string>

class ITools
{
	public:
		virtual size_t GenerateSize(std::string Format, va_list vArgs);
		virtual size_t GenerateSize(std::string Format, ...);

		virtual char* Compile(char* Destination, std::string Format, va_list vArgs);
		virtual char* Compile(char* Destination, std::string Format, ...);
		virtual char* ParseData(char* Data, char* Format, ...);
		virtual std::vector<std::string> Explode(std::string String, std::string Separator);
		virtual std::string GetExecutableFromPath(std::string Path);

		virtual unsigned long __declspec(noinline) GetCaller(size_t Depth = 1);
		virtual PIMAGE_NT_HEADERS GetModuleInfo(HMODULE Module);

		template<class T> void *Pointer(T func)
		{
			__asm mov eax, func
			//T* _p = &func;
			//void *p = &_p;
			//return (void*)*(int*)((void*)*(int*)p);
		}
};

#endif