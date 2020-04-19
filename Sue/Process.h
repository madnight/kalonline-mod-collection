#ifndef __PROCESS_H
#define __PROCESS_H

class IProcess
{
private:
    unsigned char MaxCharCount;

public:
    void Hook();
    void Login(void *Socket, int nId, int nUID);
};

#endif