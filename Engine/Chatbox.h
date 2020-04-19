#ifndef __CHATBOX_H
#define __CHATBOX_H

#include <string>
#include <list>
#include "Lock.h"

class IChatbox
{
protected:
    std::list<std::string>::iterator _ChatHistoryI;
    std::list<std::string> _ChatHistory;
    bool _EditEmpty;

public:
    IChatbox();
    void HookCommand();
    int EnterText(std::string Text);
    void Display(std::string Text);
    void AddEditorText(std::string Text);
    void ClearEditor();
    void ChatHistoryMove(bool Up);
};

#endif