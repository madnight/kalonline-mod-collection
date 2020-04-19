#include "Chatbox.h"
#include "Interface.h"
#include "Tools.h"
#include "Engine.h"
#include "Hooks.h"
#include "Graphics.h"
#include <sstream>

CREATE_INTERFACE(IChatbox)

#define MAX_CHATHISTORY 200

IChatbox::IChatbox()
{
    this->_EditEmpty = true;
    this->_ChatHistory.clear();
    this->_ChatHistoryI = this->_ChatHistory.begin();
}

void IChatbox::ChatHistoryMove(bool Up)
{
    if (Up)
    {
        if (this->_EditEmpty)
        {
            if (this->_ChatHistory.size())
            {
                this->_EditEmpty = false;
                this->_ChatHistoryI = this->_ChatHistory.begin();
            }
            else return;
        } else {
            std::list<std::string>::iterator I = this->_ChatHistory.end();
            I--;
            if (this->_ChatHistoryI != I) this->_ChatHistoryI++;
        }
    } else {
        if (this->_EditEmpty) return;
        else
        {
            if (this->_ChatHistoryI == this->_ChatHistory.begin())
            {
                this->_EditEmpty = true;
                this->ClearEditor();
                return;
            }
            else this->_ChatHistoryI--;
        }
    }

    this->ClearEditor();
    this->AddEditorText(*this->_ChatHistoryI);
}

void IChatbox::HookCommand()
{
    Interface<ITools> Tools;
    Tools->Intercept(ITools::_I_CALL, (void*)0x00697795, Hooks::KCommand::ProcessCommand, 5);
    Tools->Intercept(ITools::_I_CALL, (void*)0x00748EA3, Hooks::KCommand::ProcessCommand, 5);
}

void IChatbox::Display(std::string Text)
{
    Interface<IGraphics> Graphics;
    Graphics->Lock();
    Engine::KGameSys::AddChattingMessage('*', Text.c_str(), 0xffffff);
    Graphics->Unlock();
}

void IChatbox::AddEditorText(std::string Text)
{
    Interface<IGraphics> Graphics;
    Graphics->Lock();

    if (*Engine::KGameSys::m_pChattingControl)
    {
        unsigned long *m_Edit = (unsigned long*)((*Engine::KGameSys::m_pChattingControl) +0x880);
        if (m_Edit)
        {
            void (__thiscall *OnKeyDown)(void* _this, unsigned int) = (void (__thiscall*)
                    (void*, unsigned int)) ((*(unsigned long*)((*(unsigned long*)m_Edit)+0x6c)));
            Engine::CEditor::Load(m_Edit, Text.c_str());
            OnKeyDown(m_Edit, VK_END);
        }
    }

    Graphics->Unlock();
}

void IChatbox::ClearEditor()
{
    Interface<IGraphics> Graphics;
    Graphics->Lock();

    if (*Engine::KGameSys::m_pChattingControl)
    {
        unsigned long *m_Edit = (unsigned long*)((*Engine::KGameSys::m_pChattingControl) + 0x880);
        if (m_Edit) Engine::CEditor::Clear(m_Edit);
    }

    Graphics->Unlock();
}

int IChatbox::EnterText(std::string Text)
{
    bool Block = false;
    Interface<ITools> Tools;
    Interface<IChatbox> Chatbox;
    Interface<IGraphics> Graphics;

    if (Text[0] == '/')
    {
        std::vector<std::string> p = Tools->Explode(Text, " ");
        std::string c = p[0].substr(1);;

        if (c == "set")
        {
            Block = true;
            if (p.size() > 1)
            {
                std::string a = p[1];
                Graphics->Lock();

                if (a == "time")
                {
                    if (p.size() > 2) *Engine::KSunLight::m_dwTime = atoi(p[2].c_str()) * 0x927c0;
                }
                else if (a == "hideme") *Engine::KCommand::m_bHideMe = !*Engine::KCommand::m_bHideMe;
                else if (a == "hideui") *Engine::KCommand::m_bHideUI = !*Engine::KCommand::m_bHideUI;
                else if (a == "hidefog") *Engine::KCommand::m_bHideFog = !*Engine::KCommand::m_bHideFog;
                else if (a == "hideterrain") *Engine::KCommand::m_bHideTerrain = !*Engine::KCommand::m_bHideTerrain;
                else if (a == "hidemodel") *Engine::KCommand::m_bHideModel = !*Engine::KCommand::m_bHideModel;
                else if (a == "hidewater") *Engine::KCommand::m_bHideWater = !*Engine::KCommand::m_bHideWater;
                Graphics->Unlock();
            }
        } else if (c == "help")
        {
            Chatbox->Display("   /set time [num]");
            Chatbox->Display("   /set hideme");
            Chatbox->Display("   /set hideui");
            Chatbox->Display("   /set hidefog");
            Chatbox->Display("   /set hidewater");
            Chatbox->Display("   /set hidemodel");
            Chatbox->Display("   /set hideterrain");
        }
        else Engine::KCommand::ProcessCommand(Text.c_str());
    } else {
        if (Chatbox->_ChatHistory.size())
        {
            std::list<std::string>::iterator I = Chatbox->_ChatHistory.begin();
            if (*I != Text)
            {
                Chatbox->_ChatHistory.push_front(Text);
                if (Chatbox->_ChatHistory.size() >= MAX_CHATHISTORY) Chatbox->_ChatHistory.pop_back();
            }
        } else {
            Chatbox->_ChatHistory.push_front(Text);
            if (Chatbox->_ChatHistory.size() >= MAX_CHATHISTORY) Chatbox->_ChatHistory.pop_back();
        }
    }

    Chatbox->_ChatHistoryI = Chatbox->_ChatHistory.begin();
    Chatbox->_EditEmpty = true;
    return (!Block) ? 0 : 1;
}
