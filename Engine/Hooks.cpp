#include "Hooks.h"
#include "Interface.h"
#include "Chatbox.h"
#include "Packets.h"

int __cdecl Hooks::KCommand::ProcessCommand(const char* Text)
{
	Interface<IChatbox> Chatbox;
	return Chatbox->EnterText(Text);
}

int __cdecl Hooks::KSocket::WritePacketAutoCrc(unsigned char Type, const char* Format, ...)
{
	Interface<IPackets> Packets;
	va_list Args;
	int Ret;
	va_start(Args, Format);
	if (Type != 253 && Type != 254 && Type != 255) Type = Type - 1;
	Ret = Packets->Send(Type, (std::string)Format, Args);
	va_end(Args);
	return Ret;
}

int __cdecl Hooks::KSocket::OnRecv(Engine::Packet *Data)
{
	Interface<IPackets> Packets;
	return Packets->Recv(Data);
}