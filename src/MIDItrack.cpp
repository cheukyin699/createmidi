#include <cstring>

#include <MIDItrack.h>

namespace MIDI
{
	MIDItrack::MIDItrack()
	{
		// Set up default ID value
		std::strcpy(id, TRACK_CHUNK_ID);
		// Set up default size
		size = 0;
	}

	MIDItrack::~MIDItrack()
	{
		delete[] id;
	}

	void MIDItrack::addEvent(MIDItrackevt evt)
	{
	}

	void MIDItrack::addEvent(unsigned int delta_time, char evt_type, char mchannel, char param1, char param2)
	{
	}
}
