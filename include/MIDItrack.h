#ifndef MIDITRACK_H
#define MIDITRACK_H

#include <vector>

#include <MIDItrackevt.h>

using namespace std;

namespace MIDI
{

	const char TRACK_CHUNK_ID[] = "MTrk";

	/**
	 * The MIDItrack class
	 */
	class MIDItrack
	{
		private:
			char id[4];
			unsigned int size;

			vector<char> evt_bytes;

		public:

			/**
			 * The default constructor
			 */
			MIDItrack();

			/**
			 * The default deconstructor
			 */
			~MIDItrack();

			/**
			 * Adds an MIDI track event
			 * @param evt The track event
			 */
			void addEvent(MIDItrackevt evt);

			/**
			 * Adds an MIDI track event
			 * @param delta_time Delta time
			 * @param evt_type Event type
			 * @param mchannel MIDI channel number
			 * @param param1 The first parameter
			 * @param param2 The second parameter
			 */
			void addEvent(unsigned int delta_time, char evt_type, char mchannel, char param1, char param2);
	};
}

#endif
