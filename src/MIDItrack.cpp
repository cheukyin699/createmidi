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
		// For the delta_time
		unsigned char* ptr;
		delta_time = htonl(delta_time);
		ptr = (unsigned char*)&delta_time;
		for(unsigned int i=0; i<sizeof(delta_time); i++)
			evt_bytes.push_back(ptr[i]);
		
		// For the event type 4 bits and MIDI channel 4 bits
		evt_bytes.push_back(evt_type << 4 | mchannel << 4 >> 4);

		// Parameter's push
		evt_bytes.push_back(param1);
		evt_bytes.push_back(param2);
	}

	void MIDItrack::addEvent(unsigned int delta_time, unsigned char evt_type, unsigned char mchannel, unsigned char param)
	{
		// For the delta_time
		unsigned char* ptr;
		delta_time = htonl(delta_time);
		ptr = (unsigned char*)&delta_time;
		for(unsigned int i=0; i<sizeof(delta_time); i++)
			evt_bytes.push_back(ptr[i]);
		
		// For the event type 4 bits and MIDI channel 4 bits
		evt_bytes.push_back(evt_type << 4 | mchannel << 4 >> 4);

		// Parameter push
		evt_bytes.push_back(param);
	}

	inline void MIDItrack::addNoteOffEvent(unsigned int delta_time, unsigned char mchannel, unsigned char note, unsigned char veloc)
	{
		addEvent(delta_time, Note_Off_evt, mchannel, note, veloc);
	}

	inline void MIDItrack::addNoteOnEvent(unsigned int delta_time, unsigned char mchannel, unsigned char note, unsigned char veloc)
	{
		addEvent(delta_time, Note_On_evt, mchannel, note, veloc);
	}

	inline void MIDItrack::addNoteAfterTouchEvent(unsigned int delta_time, unsigned char mchannel, unsigned char note, unsigned char amount)
	{
		addEvent(delta_time, Note_Aftertouch_evt, mchannel, note, amount);
	}

	inline void MIDItrack::addControllerEvent(unsigned int delta_time, unsigned char mchannel, unsigned char type, unsigned char value)
	{
		addEvent(delta_time, Controller_evt, mchannel, type, value);
	}

	inline void MIDItrack::addProgramChangeEvent(unsigned int delta_time, unsigned char mchannel, unsigned char num)
	{
		addEvent(delta_time, Program_Change_evt, mchannel, num);
	}

	inline void MIDItrack::addChannelAftertouchEvent(unsigned int delta_time, unsigned char mchannel, unsigned char amount)
	{
		addEvent(delta_time, Channel_Aftertouch_evt, mchannel, amount);
	}

	inline void MIDItrack::addPitchBendEvent(unsigned int delta_time, unsigned char mchannel, unsigned char lsbval, unsigned char msbval)
	{
		addEvent(delta_time, Pitch_Bend_evt, mchannel, lsbval, msbval);
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
