#include <MIDIfile.h>

namespace MIDI
{
	MIDIfile::MIDIfile()
	{
		// Initializes MIDI header with default values
		MIDIheadInit(header);
	}

	MIDIfile::~MIDIfile()
	{
	}

	MIDIhead MIDIfile::getMIDIhead()
	{
		return header;
	}

	void MIDIfile::output(ostream& output)
	{
	}
}
