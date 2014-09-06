#include <MIDIfile.h>

namespace MIDI
{
	MIDIfile::MIDIfile()
	{
		// Initializes MIDI header with default values
		MIDIheadInit(header);
	}

	MIDIfile::MIDIfile(MIDIhead head)
	{
		header = head;

		// Initializes MIDI header with default values
		MIDIheadInit(header);
	}

	MIDIfile::~MIDIfile()
	{
	}

	inline MIDIhead MIDIfile::getMIDIheader()
	{
		return header;
	}

	inline unsigned short MIDIfile::getTracksCount()
	{
		return header.track_count;
	}

	void MIDIfile::output(ostream& output)
	{
		// Get the most recent number of tracks first
		updateCount();

		// Output the header
		// (Has to loop because C++ stops at 0)
		char* tmp = getMIDIhead(header);
		for(int i=0; i<14; i++)
			output << tmp[i];

		// Output all the tracks one by one
		for(unsigned short i=0; i<tracks.size(); i++)
		{
			tracks[i].output(output);
		}
	}

	inline void MIDIfile::updateCount()
	{
		header.track_count = tracks.size();
	}

	void MIDIfile::setFormatType(unsigned short type)
	{
		header.type = type;
	}

	void MIDIfile::setTimeDivision(unsigned short div)
	{
		header.time_div = div;
	}

	void MIDIfile::addTrack(MIDItrack& track)
	{
		tracks.push_back(track);
	}
}
