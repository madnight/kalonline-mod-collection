#ifndef __TOOLS_H
#define __TOOLS_H

#include <Windows.h>
#include <vector>
#include <string>

class ITools
{
	public:
		enum _INSTRUCTIONS
		{
			_I_NOP = 0x90,
			_I_CALL = 0xe8,
			_I_JMP = 0xe9,
			_I_JMP_SHORT = 0xeb,
			_I_JE_SHORT = 0x74,
			_I_JNZ_SHORT = 0x75,
		};

		virtual size_t GenerateSize(std::string Format, va_list vArgs);
		virtual size_t GenerateSize(std::string Format, ...);
		virtual void Compile(char* Destination, int Size, std::string Format, va_list vArgs);
		virtual void Compile(char* Destination, int Size, std::string Format, ...);
		virtual char* Compile(char* Destination, std::string Format, va_list vArgs);
		virtual char* Compile(char* Destination, std::string Format, ...);
		virtual char* ParseData(char* Data, char* Format, ...);
		virtual std::vector<std::string> Explode(std::string String, std::string Separator);
		virtual std::string GetExecutableFromPath(std::string Path);
		virtual unsigned long __declspec(noinline) GetCaller(size_t Depth = 1);
		virtual PIMAGE_NT_HEADERS GetModuleInfo(HMODULE Module);
		virtual void* MemcpyEx(void *Dest, void* Source, size_t Size);
		virtual void* MemcpyExS(void *Dest, void* Source, size_t Size);
		virtual void* MemcpyExD(void *Dest, void* Source, size_t Size);
		virtual void FillMemoryEx(void* Destination, unsigned char Fill, size_t Size);
		virtual void FillMemoryEx(unsigned long Destination, unsigned char Fill, size_t Size);
		virtual void SetMemoryEx(void* Destination, const char* Data, size_t Size);
		virtual void SetMemoryEx(unsigned long Destination, const char* Data, size_t Size);
		virtual unsigned long Intercept(unsigned char instruction, void* source, void* destination, size_t length);
};

#endif