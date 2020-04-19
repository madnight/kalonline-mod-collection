#ifndef __PACKETS_H
#define __PACKETS_H

namespace Mods
{
	namespace Packets
	{
		void __cdecl WriteCode(void *Socket, char Type, char* format, long ProtocolVersion, char Code,  long TimeStamp, long TimeStart, long System,
			unsigned long Event, char ServerID, char Age, char Country);
		void __cdecl WriteSkills(void *Player, char Type, char* format, char* skills, size_t size);
	}
}

class Packets
{
	public:
		Packets();
		~Packets();

		bool Header(void *Socket, char* Data);
};

#endif