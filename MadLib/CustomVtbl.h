#ifndef _CUSTOMVTBL_H_
#define _CUSTOMVTBL_H_

#include <Windows.h>
#include "../Server.h"

class CustomVtbl
{
public:
	CustomVtbl(int address1,int address2, int address3, int address4) 
	{
		this->Copy = address1;
		this->CanExcute = address2;
		this->Excute = address3;
		this->ExcutePassive = address4;
	}
	
	int Copy;
	int CanExcute;
	int Excute;
	int ExcutePassive;

};

#endif