struct xCDB
{
	int Data[4];
};

static int (__stdcall *UpdatePlayer)(void *Data) = (int (__stdcall*)(void*))0x00413CB0;
static int (__cdecl *Logging)(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) = (int (__cdecl*)(int,int,int,int,int,int,int,int,int))0x0040DD10;
static int (__thiscall *Process)(void *Socket, int Data) = (int (__thiscall*)(void*,int))0x00410F10;
static int (__stdcall *StorageInfo)(int IID, int Argument, int PID, int Value, int Num) = (int (__stdcall*)(int,int,int,int,int))0x00414460;
static int (__cdecl *ServerSend)(int Packet, char Type, const char *Argument, ...) = (int (__cdecl*)(int,char,const char*,...))0x00410EA0;
static char *(__cdecl *Read)(char *pPos, char Type, ...) = (char *(__cdecl*)(char*,char,...))0x0041CB40;
static void (__thiscall *CDB)(void *DB) = (void (__thiscall*)(void*))0x004026C0;
static void (__thiscall *CDBx)(void *DB) = (void (__thiscall*)(void*))0x00402DA0;
static int (__thiscall *FreeCDB)(void *DB) = (int (__thiscall*)(void*))0x004026F0;
static int (__cdecl *Execute)(void *DB, const char* Statement, ...) = (int (__cdecl*)(void*, const char*, ...))0x00402730;
static int (__cdecl *Executex)(void *DB, const char* Statement, ...) = (int (__cdecl*)(void*, const char*, ...))0x00402B20;
static int (__cdecl *Prepare)(const char* Statement, ...) = (int (__cdecl*)(const char*, ...))0x0040DCE0;
static int (__thiscall *Fetch)(void *DB) = (int (__thiscall*)(void*))0x00402ce0;
static void (__thiscall *BindString)(void *DB, char* String, int Length) = (void (__thiscall*)(void*, char*, int))0x0041B260;
static void (__thiscall *BindDword)(void *DB, unsigned long* Value) = (void (__thiscall*)(void*, unsigned long*))0x0041B1C0;
static void (__thiscall *BindWord)(void *DB, unsigned short* Value) = (void (__thiscall*)(void*, unsigned short*))0x0041B390;
static void (__thiscall *BindByte)(void *DB, unsigned char* Value) = (void (__thiscall*)(void*, unsigned char*))0x0041B170;
static int (__cdecl *Black)(char *arg0, ...) = (int (__cdecl*)(char*,...))0x0040DCB0;
static int (__cdecl *Blue)(char *arg0, ...) = (int (__cdecl*)(char*,...))0x0040DC80;