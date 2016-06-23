#include <windows.h> 

#define INST_NOP  0x90
#define INST_CALL 0xE8
#define INST_JMP  0xE9
#define INST_BYTE 0x00
#define SHORT_JZ  0x74
#define STD_CALL_LEN 0x05
#ifndef __MEMORY_H
#define __MEMORY_H

#define INST_JMPR  0xEB
#define INST_RET 0xC3
#define _DWORD DWORD
#define _WORD WORD
#define _BYTE BYTE

#pragma comment(lib, "detours.lib")
#include <map>
#include <windows.h>
#include <detours.h> 

class Patch;
class IMemory
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
			_I_PUSH = 0x68,
		};

	private:
		std::map<void*, Patch*> m_Patches;

	public:
		void Copy(void *Source, void *Destination, size_t Size);
		void Copy(DWORD destination, DWORD source, int length);

		void Fill(unsigned long Destination, unsigned char Fill, size_t Size, bool Recoverable = true);
		void Fill(void *Destination, unsigned char Fill, size_t Size, bool Recoverable = true);
		void Dereference(DWORD destination, DWORD source, int length = 4);
		void Dereference(DWORD destination, unsigned char source, int length = 1);

		unsigned char Fetch(DWORD destination, int length = 1);
		int FetchInteger(DWORD destination, int length = 4);

		void Set(unsigned long Destination, unsigned char *Data, size_t Size, bool Recoverable = true);
		void Set(void *Destination, unsigned char *Data, size_t Size, bool Recoverable = true);
		void Set(unsigned long Destination, const char *Data, size_t Size, bool Recoverable = true);
		void Set(void *Destination, const char *Data, size_t Size, bool Recoverable = true);

		void Hook(void *Address, void *Destination, unsigned char Instruction = _I_CALL, size_t Size = 5, bool Recoverable = true);
		void Hook(unsigned long Address, void *Destination, unsigned char Instruction = _I_CALL, size_t Size = 5, bool Recoverable = true);
		void Hook(unsigned long Address[], size_t Count, void *Destination, unsigned char Instruction = _I_CALL, size_t Size = 5, bool Recoverable = true);
		void Hook(void *Address, unsigned long Destination, unsigned char Instruction = _I_CALL, size_t Size = 5, bool Recoverable = true);
		void Hook(unsigned long Address, unsigned long Destination, unsigned char Instruction = _I_CALL, size_t Size = 5, bool Recoverable = true);
		void Hook(unsigned long Address[], size_t Count, unsigned long Destination, unsigned char Instruction = _I_CALL, size_t Size = 5, bool Recoverable = true);

		void HookAPI(void *Address, unsigned long Destination);
		void HookAPI(unsigned long Address, unsigned long Destination);
		void HookAPI(void *Address, void *Destination);
		void HookAPI(unsigned long Address, void *Destination);

		void Restore(void *Address);
		void Restore(unsigned long Address);
		void Restore(unsigned long Address[], size_t Count);
		
		void Restore(unsigned long Address, void *Destination); 
};

class Patch
{
	private:
		void* m_Address;
		size_t m_Size;
		unsigned char *m_Original;
		bool m_Recoverable;

		Patch(void *Address, unsigned char *Data, size_t Size, bool Recoverable);

	public:
		~Patch();

	friend class IMemory;
};

#endif
