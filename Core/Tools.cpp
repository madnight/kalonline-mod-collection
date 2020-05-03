#include <Windows.h>
#include "Tools.h"
#include "Interface.h"

CREATE_INTERFACE(ITools)

unsigned long ITools::GetCaller(size_t Depth)
{
    unsigned long _Ebp, Addr;

    if (!Depth)
    {
        __asm mov eax, [ebp]
        __asm mov _Ebp, eax
    } else {
        __asm mov eax, ebp
        __asm mov _Ebp, eax
    }

    for (size_t i = 0; i < Depth; i++)
    {
        __asm mov eax, _Ebp
        __asm mov eax, [eax]
        __asm mov _Ebp, eax
    }

    __asm mov eax, _Ebp
    __asm mov eax, [eax+4]
    __asm mov Addr, eax
    return Addr - 5;
}

PIMAGE_NT_HEADERS ITools::GetModuleInfo(HMODULE Module)
{
    PIMAGE_DOS_HEADER DOS_Header = (PIMAGE_DOS_HEADER)Module;
    PIMAGE_NT_HEADERS NT_Header = (PIMAGE_NT_HEADERS)((unsigned)DOS_Header +
            DOS_Header->e_lfanew);
    return NT_Header;
}

std::string ITools::GetExecutableFromPath(std::string Path)
{
    size_t sep = Path.find_last_of("\\/");

    if (sep != std::string::npos) {
        return Path.substr(sep + 1);
    }
    else {
        return Path;
    }
}

size_t ITools::GenerateSize(std::string Format, ...)
{
    va_list Args;
    va_start(Args, Format);
    size_t Ret = this->GenerateSize(Format, Args);
    va_end(Args);
    return Ret;
}

size_t ITools::GenerateSize(std::string Format, va_list vArgs)
{
    int PacketSize = 0;
    std::string pSizeStr;

    for (size_t i = 0; i < Format.length(); i++)
    {
        switch (Format[i])
        {
            case 'b':
            case 'B':
                PacketSize += sizeof(unsigned char);
                va_arg(vArgs, unsigned char);
                break;

            case 'w':
            case 'W':
                PacketSize += sizeof(unsigned short);
                va_arg(vArgs, unsigned short);
                break;

            case 'd':
            case 'U':
                PacketSize += sizeof(unsigned long);
                va_arg(vArgs, unsigned long);
                break;

            case 'f':
                PacketSize += sizeof(float);
                va_arg(vArgs, float);
                break;

            case 'D':
                PacketSize += sizeof(double);
                va_arg(vArgs, double);
                break;

            case 'I':
                PacketSize += sizeof(__int64);
                va_arg(vArgs, unsigned __int64);
                break;

            case 's':
            case 'S':
                pSizeStr = va_arg(vArgs, char*);
                PacketSize += pSizeStr.length() + 1;
                break;

            case 'm':
            case 'M':
                va_arg(vArgs, char*);
                PacketSize += va_arg(vArgs, int);
                break;

            default:
                break;
        }
    }

    return PacketSize;
}

void ITools::Compile(char *Destination, int Size, std::string Format, ...)
{
    va_list Args;
    va_start(Args, Format);
    this->Compile(Destination, Size, Format, Args);
    va_end(Args);
}

void ITools::Compile(char *Destination, int Size, std::string Format,
    va_list vArgs)
{
    unsigned char pTypeByte = 0;
    unsigned short pTypeWord = 0;
    unsigned long pTypeDword = 0;
    float pTypeFloat = 0.0;
    double pTypeDouble = 0.0;
    unsigned __int64 pTypeQword = 0;
    std::string pTypeStr;
    char* pTypeArray = NULL;
    int pTypeArrayLen = 0;

    for (size_t i = 0; i < Format.length(); i++)
    {
        switch (Format[i])
        {
            case 'b':
            case 'B':
                pTypeByte = va_arg(vArgs, unsigned char);
                memcpy(Destination, &pTypeByte, sizeof(unsigned char));
                Destination += sizeof(unsigned char);
                break;

            case 'w':
            case 'W':
                pTypeWord = va_arg(vArgs, unsigned short);
                memcpy(Destination, &pTypeWord, sizeof(unsigned short));
                Destination += sizeof(unsigned short);
                break;

            case 'd':
            case 'U':
                pTypeDword = va_arg(vArgs, unsigned long);
                memcpy(Destination, &pTypeDword, sizeof(unsigned long));
                Destination += sizeof(unsigned long);
                break;

            case 'f':
                pTypeFloat = va_arg(vArgs, float);
                memcpy(Destination, &pTypeFloat, sizeof(float));
                Destination += sizeof(float);
                break;

            case 'D':
                pTypeDouble = va_arg(vArgs, double);
                memcpy(Destination, &pTypeDouble, sizeof(double));
                Destination += sizeof(double);
                break;

            case 'I':
                pTypeQword = va_arg(vArgs, unsigned __int64);
                memcpy((void*)Destination, (void*)&pTypeDword, 8);
                Destination += 8;

            case 's':
            case 'S':
                pTypeStr = va_arg(vArgs, char*);
                memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() + 1);
                Destination += pTypeStr.length() + 1;
                break;

            case 'm':
            case 'M':
                pTypeArray = va_arg(vArgs, char*);
                pTypeArrayLen = va_arg(vArgs, int);
                memcpy(Destination, pTypeArray, pTypeArrayLen);
                Destination += pTypeArrayLen;
                break;

            default:
                break;
        }
    }
}

char *ITools::Compile(char *Destination, std::string Format, ...)
{
    va_list Args;
    va_start(Args, Format);
    char *end = this->Compile(Destination, Format, Args);
    va_end(Args);
    return end;
}

char *ITools::Compile(char *Destination, std::string Format, va_list vArgs)
{
    unsigned char pTypeByte = 0;
    unsigned short pTypeWord = 0;
    unsigned long pTypeDword = 0;
    float pTypeFloat = 0.0;
    double pTypeDouble = 0.0;
    unsigned __int64 pTypeQword = 0;
    std::string pTypeStr;
    char* pTypeArray = NULL;
    int pTypeArrayLen = 0;

    for (size_t i = 0; i < Format.length(); i++)
    {
        switch (Format[i])
        {
            case 'b':
            case 'B':
                pTypeByte = va_arg(vArgs, unsigned char);
                memcpy(Destination, &pTypeByte, sizeof(unsigned char));
                Destination += sizeof(unsigned char);
                break;

            case 'w':
            case 'W':
                pTypeWord = va_arg(vArgs, unsigned short);
                memcpy(Destination, &pTypeWord, sizeof(unsigned short));
                Destination += sizeof(unsigned short);
                break;

            case 'd':
            case 'U':
                pTypeDword = va_arg(vArgs, unsigned long);
                memcpy(Destination, &pTypeDword, sizeof(unsigned long));
                Destination += sizeof(unsigned long);
                break;

            case 'f':
                pTypeFloat = va_arg(vArgs, float);
                memcpy(Destination, &pTypeFloat, sizeof(float));
                Destination += sizeof(float);
                break;

            case 'D':
                pTypeDouble = va_arg(vArgs, double);
                memcpy(Destination, &pTypeDouble, sizeof(double));
                Destination += sizeof(double);
                break;

            case 'I':
                pTypeQword = va_arg(vArgs, unsigned __int64);
                memcpy((void*)Destination, (void*)&pTypeDword, 8);
                Destination += 8;

            case 's':
            case 'S':
                pTypeStr = va_arg(vArgs, char*);
                memcpy(Destination, pTypeStr.c_str(), pTypeStr.length() + 1);
                Destination += pTypeStr.length() + 1;
                break;

            case 'm':
            case 'M':
                pTypeArray = va_arg(vArgs, char*);
                pTypeArrayLen = va_arg(vArgs, int);
                memcpy(Destination, pTypeArray, pTypeArrayLen);
                Destination += pTypeArrayLen;
                break;

            default:
                break;
        }
    }

    return Destination;
}

char *ITools::ParseData(char *Data, char *Format, ...)
{
    va_list vArgs;
    va_start(vArgs, Format);

    for (unsigned int i = 0; i < strlen(Format); i++)
    {
        switch (Format[i])
        {
            case 'b':
                *va_arg(vArgs, unsigned char*) = *(unsigned char*)Data;
                Data += sizeof(unsigned char);
                break;

            case 'w':
                *va_arg(vArgs, unsigned short*) = *(unsigned short*)Data;
                Data += sizeof(unsigned short);
                break;

            case 'd':
                *va_arg(vArgs, unsigned long*) = *(unsigned long*)Data;
                Data += sizeof(unsigned long);
                break;

            case 'f':
                *va_arg(vArgs, float*) = *(float*)Data;
                Data += sizeof(float);
                break;

            case 'D':
                *va_arg(vArgs, double*) = *(double*)Data;
                Data += sizeof(double);
                break;

            case 'I':
                *va_arg(vArgs, __int64*) = *(__int64*)Data;
                Data += sizeof(__int64);
                break;

            case 's':
                *va_arg(vArgs, char**) = Data;
                Data += strlen(Data) + 1;
                break;

            case 'm':
                *va_arg(vArgs, unsigned char**) = (unsigned char*)Data;
                Data += va_arg(vArgs, unsigned long);
                break;

            case '?':
                Data += va_arg(vArgs, unsigned long);
                break;
        }
    }

    va_end(vArgs);
    return Data;
}

std::vector<std::string> ITools::Explode(std::string String,
    std::string Separator)
{
    std::vector<std::string> r;
    int p = String.find(Separator);

    while (p != std::string::npos)
    {
        if (p) {
            r.push_back(String.substr(0, p));
        }

        String = String.substr(p + Separator.length());
        p = String.find(Separator);
    }

    if (String.length()) {
        r.push_back(String);
    }

    return r;
}

void ITools::SetMemoryEx(void* Destination, const char* Data, size_t Size)
{
    this->MemcpyExD(Destination, (void*)Data, Size);
}

void ITools::SetMemoryEx(unsigned long Destination, const char* Data,
    size_t Size)
{
    this->SetMemoryEx((void*)Destination, Data, Size);
}

void* ITools::MemcpyEx(void *Dest, void* Source, size_t Size)
{
    unsigned long oldSourceProt, oldDestProt;
    VirtualProtect(Source, Size, PAGE_EXECUTE_READWRITE, &oldSourceProt);
    VirtualProtect(Dest, Size, PAGE_EXECUTE_READWRITE, &oldDestProt);
    memcpy(Dest, Source, Size);
    VirtualProtect(Dest, Size, oldDestProt, &oldDestProt);
    VirtualProtect(Source, Size, oldSourceProt, &oldSourceProt);
    return Dest;
}

void* ITools::MemcpyExS(void *Dest, void* Source, size_t Size)
{
    unsigned long oldSourceProt;
    VirtualProtect(Source, Size, PAGE_EXECUTE_READWRITE, &oldSourceProt);
    memcpy(Dest, Source, Size);
    VirtualProtect(Source, Size, oldSourceProt, &oldSourceProt);
    return Dest;
}

void* ITools::MemcpyExD(void *Dest, void* Source, size_t Size)
{
    unsigned long oldDestProt;
    VirtualProtect((LPVOID)Dest, Size, PAGE_EXECUTE_READWRITE, &oldDestProt);
    memcpy(Dest, Source, Size);
    VirtualProtect(Dest, Size, oldDestProt, &oldDestProt);
    return Dest;
}

void ITools::FillMemoryEx(void* Destination, unsigned char Fill, size_t Size)
{
    unsigned long oldDestProt;
    VirtualProtect(Destination, Size, PAGE_EXECUTE_READWRITE, &oldDestProt);
    FillMemory(Destination, Size, Fill);
    VirtualProtect(Destination, Size, oldDestProt, &oldDestProt);
}

void ITools::FillMemoryEx(unsigned long Destination, unsigned char Fill,
    size_t Size)
{
    unsigned long oldDestProt;
    VirtualProtect((void*)Destination, Size, PAGE_EXECUTE_READWRITE, &oldDestProt);
    FillMemory((void*)Destination, Size, Fill);
    VirtualProtect((void*)Destination, Size, oldDestProt, &oldDestProt);
}

unsigned long ITools::Intercept(unsigned char instruction, void *source,
    void *destination,
    size_t length)
{
    unsigned long realTarget;
    LPBYTE buffer = new BYTE[length];
    memset(buffer, 0x90, length);

    if (instruction != ITools::_I_NOP && length >= 5)
    {
        buffer[(length - 5)] = instruction;
        unsigned long dwJMP = (unsigned long)destination - ((unsigned long)source + 5
                + (length - 5));
        memcpy(&realTarget, (void*)((unsigned long)source + 1), 4);
        realTarget = realTarget + (unsigned long)source + 5;
        memcpy(buffer + 1 + (length - 5), &dwJMP, 4);
    }

    if (instruction == ITools::_I_JE_SHORT)
    {
        buffer[0] = instruction;
        buffer[1] = (BYTE)destination;
    }

    if (instruction == 0x00) {
        buffer[0] = (BYTE)destination;
    }

    this->MemcpyExD(source, buffer, length);
    delete[] buffer;
    return realTarget;
}