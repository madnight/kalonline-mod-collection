#ifndef __TOOLS_H
#define __TOOLS_H

class ITools
{
public:
    enum _INSTRUCTIONS
    {
        I_NOP = 0x90,
        I_CALL = 0xe8,
        I_JMP = 0xe9,
        I_JMP_SHORT = 0xeb,
        I_JE_SHORT = 0x74,
        I_JNZ_SHORT = 0x75,
    };

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