#ifndef __CORE_H
#define __CORE_H

class ICore
{
	public:
		ICore(void);
		~ICore(void);
		void Boot(HMODULE hModule);
};

#endif