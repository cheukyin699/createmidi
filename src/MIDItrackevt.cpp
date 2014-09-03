#include <MIDItrackevt.h>

namespace MIDI
{
	unsigned char makeNote(MIDInote note, short octave = 0)
	{
		return (unsigned char)((int)note + 60 + 12 * octave);
	}
}
