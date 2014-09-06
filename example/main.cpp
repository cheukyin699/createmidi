#include <MIDIfile.h>
#include <iostream>
#include <fstream>

using namespace MIDI;
using namespace std;

int main()
{
	MIDIfile f;
	f.setFormatType(0);
	f.setTimeDivision((unsigned short)0xe0);
	MIDItrack t;
	MIDItrackevt evt;
	evt.delta_time = 0;
	evt.evt_type_channel = 0x90;
	evt.param1 = makeNote(C);
	evt.param2 = 100;
	t.addEvent(evt);

	evt.delta_time = 100;
	evt.evt_type_channel = 0x80;
	evt.param1 = makeNote(C);
	evt.param2 = 100;
	t.addEvent(evt);

	f.addTrack(t);

	ofstream ff("test.midi", ios::binary);
	if(ff.is_open())
		f.output(ff);
	else
		cerr << "Cannot open file test.midi" << endl;

	ff.close();

	return 0;
}
