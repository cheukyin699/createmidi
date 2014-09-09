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

#ifndef MIDIHEAD_H
#define MIDIHEAD_H

namespace MIDI
{

	const char HEADER_CHUNK_ID[4] = {'M', 'T', 'h', 'd'};
	const unsigned int HEADER_CHUNK_SIZE = 6;

	/**
	 * The structure for the Header Chunk of any MIDI file
	 */
	struct MIDIhead
	{
		char id[4];			/**< The Header Chunk ID (Always "MThd") - 4 bytes */
		unsigned int size;	/**< The Header Chunk size (Always 6 bytes) - 4 bytes */
		short type;			/**< The MIDI format type. Can be a value of 0 - 2.

								A type **0** file has 1 track that contains all of the MIDI events for
								entire song, including the song title, time signature, tempo and music
								events.

								A type **1** file should have 2 or more tracks. The first track should
								contain song information such as the title, time signature, tempo, etc.
								The second and following tracks contain a title, musical event data, etc.

								A type **2** file contains multiple tracks, but each track represents a
								different sequence which may not necessarily be played simultaneously.
								This is meant to be used to save drum patterns, or other multi-pattern
								music sequences. - 2 bytes */
		short track_count;	/**< The number of tracks - 2 bytes */
		short time_div;		/**< The time division - 2 bytes */

	}__attribute__((__packed__));

	/**
	 * Initializes the MIDI Header with the ID and the size
	 * @param mh The MIDIhead struct
	 * @see MIDIhead
	 */
	void MIDIheadInit(MIDIhead &mh);

	/**
	 * Get the whole MIDI Header Chunk as a character array
	 * @param mh The MIDIhead struct
	 * @return The character array
	 * @see MIDIhead
	 */
	char* getMIDIhead(MIDIhead mh);
}

#endif
