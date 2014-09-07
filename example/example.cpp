/**
 * An example of how this library could be used
 * @example example.cpp
 */
#include <MIDIfile.h>
#include <iostream>
#include <fstream>

using namespace MIDI;
using namespace std;

int main()
{
	// MIDIfile
	MIDIfile f;
	MIDItrack t;

	// Set format type
	f.setFormatType(0);
	// Set time division
	f.setTimeDivision(0xe0);

	// Set event (keydown)
	t.addNoteOnEvent(0, 0, makeNote(C), 100);

	// Set event (keyup)
	t.addNoteOffEvent(100, 0, makeNote(C), 100);

	// Adds the track
	f.addTrack(t);

	ofstream ff("test.midi");
	if(ff.is_open())
		f.output(ff);
	else
		cerr << "Cannot open file test.midi" << endl;

	ff.close();

	return 0;
}
