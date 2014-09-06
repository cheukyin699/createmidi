#include <cstring>
#include <iostream>
#include <arpa/inet.h>

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
	}

	void MIDItrack::addEvent(MIDItrackevt evt)
	{
		// Actually calls the other implementation of addEvent
		addEvent(evt.delta_time, evt.evt_type_channel >> 4, evt.evt_type_channel << 4 >> 4, evt.param1, evt.param2);
	}

	inline void MIDItrack::updateSize()
	{
		size = evt_bytes.size();
	}

	void MIDItrack::addEvent(unsigned int delta_time, unsigned char evt_type, unsigned char mchannel, unsigned char param1, unsigned char param2)
	{
		unsigned char* ptr;
		delta_time = htonl(delta_time);
		ptr = (unsigned char*)&delta_time;

		// For the delta_time
		for(unsigned int i=0; i<sizeof(delta_time); i++)
			evt_bytes.push_back(ptr[i]);
		
		// For the event type 4 bits and MIDI channel 4 bits
		evt_bytes.push_back(evt_type << 4 | mchannel << 4 >> 4);
		//cout << hex << (unsigned int)(evt_type << 4|mchannel << 4 >> 4) << endl;

		// Parameter push
		evt_bytes.push_back(param1);
		evt_bytes.push_back(param2);
	}

	void MIDItrack::output(ostream& output)
	{
		// Updates the size of header value
		updateSize();

		// Put the header values in
		for(int i=0; i<sizeof(id); i++)
			output << id[i];
		unsigned int temp = htonl(size);
		unsigned char* ptr = (unsigned char*)&temp;
		for(int i=0; i<sizeof(temp); i++)
			output << ptr[i];

		// Put the events in byte by byte
		for(unsigned long i=0; i<size; i++)
		{
			output << evt_bytes[i];
		}
	}
}
