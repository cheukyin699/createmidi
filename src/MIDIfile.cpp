#include <MIDIfile.h>

namespace MIDI
{
	MIDIfile::MIDIfile()
	{
		// Initializes MIDI header with default values
		MIDIheadInit(this.header);
	}

	MIDIfile::~MIDIfile()
	{
	}

	MIDIhead MIDIfile::getMIDIhead()
	{
		return this.header;
	}

	void MIDIfile::setOutput(ostream o)
	{
		this.output = o;
	}
}
