#include <cstring>

#include <MIDItrack.h>

namespace MIDI
{
	MIDItrack::MIDItrack()
	{
		// Set up default ID value
		std::strcpy(this.id, TRACK_CHUNK_ID);
		// Set up default size
		this.size = 0;
	}

	MIDItrack::~MIDItrack()
	{
		delete[] this.id;
	}
}
