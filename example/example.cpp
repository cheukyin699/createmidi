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
	//! MIDIfile
	MIDIfile f;
	MIDItrack t;
	MIDItrackevt evt;

	//! Set format type
	f.setFormatType(0);
	//! Set time division
	f.setTimeDivision((unsigned short)0xe0);

	//! Set event (keydown)
	evt.delta_time = 0;
	evt.evt_type_channel = 0x90;
	evt.param1 = makeNote(C);
	evt.param2 = 100;
	t.addEvent(evt);

	//! Set event (keyup)
	evt.delta_time = 100;
	evt.evt_type_channel = 0x80;
	evt.param1 = makeNote(C);
	evt.param2 = 100;
	t.addEvent(evt);

	//! Adds the track
	f.addTrack(t);

	ofstream ff("test.midi", ios::binary);
	if(ff.is_open())
		f.output(ff);
	else
		cerr << "Cannot open file test.midi" << endl;

	ff.close();

	return 0;
}
