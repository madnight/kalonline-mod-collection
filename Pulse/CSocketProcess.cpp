#include "StdAfx.h"
#include "Interface.h"
#include "Deflector.h"
#include "Deflection.h"
#include "Hooks.h"
#include "Memory.h"

class CSocketProcess
{
public:
    CSocketProcess();
    ~CSocketProcess();
};

CREATE_INTERFACE(CSocketProcess)

CSocketProcess::CSocketProcess()
{
}

CSocketProcess::~CSocketProcess()
{
}
