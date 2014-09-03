#include <MIDItrackevt.h>

namespace MIDI
{
	unsigned char makeNote(MIDInote note, short octave)
	{
		return (unsigned char)((int)note + 60 + 12 * octave);
	}
}
