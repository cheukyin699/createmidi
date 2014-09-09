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

#ifndef MIDITRACKEVT_H
#define MIDITRACKEVT_H

namespace MIDI
{
	// Event type constants
	const char Note_Off_evt = 0x8;
	const char Note_On_evt = 0x9;
	const char Note_Aftertouch_evt = 0xA;
	const char Controller_evt = 0xB;
	const char Program_Change_evt = 0xC;
	const char Channel_Aftertouch_evt = 0xD;
	const char Pitch_Bend_evt = 0xE;
	const char Meta_evt = 0xFF;

	/**
	 * An enum of some notes
	 */
	enum MIDInote
	{
		C, CSharp,
		D,
		EFlat, E,
		F, FSharp,
		G, GSharp,
		A,
		BFlat, B
	};

	/**
	 * The structure for any MIDI track event
	 */
	struct MIDItrackevt
	{
		unsigned int delta_time;			/**< The event delta time determines when an event should be
												played relative to the track's last event. A delta time of
												0 means that it should be played simultaneously with the
												last event.

												A track's first event delta time defines the amount of time
												to wait before playing the first event.

												Events unaffected by time are still preceded by a delta time
												, but should always use a value of 0 and come first in
												stream of track events.

												Delta times are relative values. The actual time represented
												is determined by a couple factors. The time division and
												tempo. If no tempo is defined, 120 beats per minute is 
												assumed. */
		unsigned char evt_type_channel;		/**< The combination of the event type and the MIDI channel */
		unsigned char param1;				/**< First event parameter */
		unsigned char param2;				/**< Second event parameter */
	};

	/**
	 * Create a note with normal note and octave
	 * @param note Character from A-G
	 * @param octave Valid octaves = -5 to 5 (default to 0)
	 * @return The MIDI note number
	 * @see MIDInote
	 */
	unsigned char makeNote(MIDInote note, short octave = 0);

}

#endif
