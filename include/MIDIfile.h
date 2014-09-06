#ifndef MIDIFILE_H
#define MIDIFILE_H

#include <iostream>
#include <fstream>
#include <vector>

#include <MIDIhead.h>
#include <MIDItrack.h>

using namespace std;

/**
 * @namespace MIDI
 * @brief The MIDI namespace
 * @see MIDIfile
 * @see MIDIhead
 * @see MIDItrack
 */
namespace MIDI
{
	/**
	 * The MIDIfile class
	 *
	 * Allows user to *create* and *write* to an **MIDI** formatted file.
	 *
	 * @see MIDIhead
	 * @see MIDItrack
	 */
	class MIDIfile
	{
		private:
			MIDIhead header;

			vector<MIDItrack> tracks;

		public:

			/**
			 * The default constructor
			 */
			MIDIfile();

			/**
			 * Constructor
			 * @param head The MIDIhead
			 */
			MIDIfile(MIDIhead head);

			/**
			 * The default destructor
			 */
			~MIDIfile();

			/*************************
			 * GETTERS
			 ************************/

			/**
			 * Gets the MIDIhead of this file and returns it
			 * @return The MIDIhead header
			 */
			inline MIDIhead getMIDIheader();

			/**
			 * Gets the number of Tracks
			 * @return The number of tracks
			 */
			inline unsigned short getTracksCount();

			/*************************
			 * SETTERS
			 ************************/

			/**
			 * Sets the MIDI format type
			 * @param type MIDI format type (0-2)
			 */
			void setFormatType(unsigned short type);

			/**
			 * Sets the MIDI time division
			 *
			 * For more information, see MIDIhead
			 * @param div The time division
			 * @see MIDIhead
			 */
			void setTimeDivision(unsigned short div);

			/**
			 * Dumps everything to the output stream
			 * @param output The output stream
			 */
			void output(ostream& output);

			/**
			 * Adds a track to vector
			 * @param track Track to be added
			 */
			void addTrack(MIDItrack& track);

			/**
			 * Updates the track count to the number of tracks in vector
			 */
			inline void updateCount();

	};
}

#endif
