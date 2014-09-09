/*
 * This file is part of CreateMIDI.
 *
 * CreateMIDI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CreateMIDI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CreateMIDI.  If not, see <http://www.gnu.org/licenses/>.
 */

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
