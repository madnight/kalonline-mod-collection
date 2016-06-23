#ifndef __Item_H
#define __Item_H


#include "../Server.h"
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")

#include <map>
#define _this ((int*) this->thispointer)

class Item
{
private: 
	void* thispointer;
public:
	Item(void *itempointer) { this->thispointer = itempointer; }

    int GetIID();
	int GetState();
	int GetNum();
	int GetMaxEnd();
	int GetCurEnd();
	int GetIndex();
	int GetPid();
	int GetGrade();
	int GetPrefix();

	void SetNum(int num);

	bool IsMixStone();

	void Mix(int tali);

	void AddState(int state);
	void SetState(int state);
	void AddRef();
	bool Create(void* itemp, int a, int a2);
	void CopyProperties(Item item);
	void Delete();
};


#endif