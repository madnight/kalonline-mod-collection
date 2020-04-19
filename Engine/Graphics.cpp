#include "Graphics.h"
#include "Interface.h"

CREATE_INTERFACE(IGraphics)

void IGraphics::Lock()
{
	this->m_Lock.Enter();
}

void IGraphics::Unlock()
{
	this->m_Lock.Leave();
}