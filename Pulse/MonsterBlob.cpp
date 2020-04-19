#include "StdAfx.h"
#include "Interface.h"
#include "Deflector.h"
#include "Deflection.h"
#include "Lock.h"
#include "Memory.h"
#include "Hooks.h"
#include "Tools.h"
#include "Server.h"

class MonsterBlob
{
	private:
		Lock Lock;

	public:
		MonsterBlob();
		~MonsterBlob();
		bool Observer(void *Monster);
};

CREATE_INTERFACE(MonsterBlob)

MonsterBlob::MonsterBlob()
{
}

MonsterBlob::~MonsterBlob()
{
}