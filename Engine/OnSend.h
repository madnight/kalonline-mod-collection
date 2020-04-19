#ifndef __ONSEND_H
#define __ONSEND_H

#include <string>

class IOnSend
{
	private:
		static unsigned long Patches[];

	public:
		void Hook();
};

#endif