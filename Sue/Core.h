#ifndef __CORE_H
#define __CORE_H

class ICore
{
	private:
	public:
		void Boot();
		static unsigned long __stdcall Run(void* Arg);
};

#endif