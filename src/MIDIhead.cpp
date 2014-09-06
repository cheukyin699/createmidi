#include <cstring>

#include <MIDIhead.h>

#include <iostream>
using namespace std;
namespace MIDI
{
	void MIDIheadInit(MIDIhead &mh)
	{
		std::strcpy(mh.id, HEADER_CHUNK_ID);
		mh.size = HEADER_CHUNK_SIZE;
	}

	char* getMIDIhead(MIDIhead mh)
	{
		// The return value
		char* ret = new char[sizeof(mh)];

		// Set the ID
		for(int i=0; i<4; i++)
			ret[i] = mh.id[i];

		// Set the size (size is constant 0x6)
		ret[4] = 0x0;
		ret[5] = 0x0;
		ret[6] = 0x0;
		ret[7] = mh.size;

		// Set format type
		ret[8] = 0x0;
		ret[9] = mh.type;

		// Set number of tracks
		ret[10] = mh.track_count >> 8;		// Upper 8 bits
		ret[11] = mh.track_count << 8 >> 8;	// Lower 8 bits

		// Set Time division
		ret[12] = mh.time_div >> 8;			// Upper 8 bits
		ret[13] = mh.time_div << 8 >> 8;		// Lower 8 bits

		return ret;
	}
}
