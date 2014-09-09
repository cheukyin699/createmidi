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

#ifndef MIDITRACK_H
#define MIDITRACK_H

#include <iostream>
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

			vector<unsigned char> evt_bytes;

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
			 * Updates the size of the vector to the header
			 */
			inline void updateSize();

			/**
			 * Dumps everything to output stream
			 * @param output The output stream
			 */
			void output(ostream& output);

			/******************
			 * EVENT CREATIONS
			 ******************/

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
			void addEvent(unsigned int delta_time, unsigned char evt_type, unsigned char mchannel, unsigned char param1, unsigned char param2);

			/**
			 * Adds an MIDI track event
			 * @param delta_time Delta time
			 * @param evt_type Event type
			 * @param mchannel MIDI channel number
			 * @param param The parameter (One only)
			 */
			void addEvent(unsigned int delta_time, unsigned char evt_type, unsigned char mchannel, unsigned char param);

			/**
			 * Adds a note off MIDI event
			 *
			 * The note off event is used to signal when an MIDI key is released. These events have two
			 * parameters identical to a note on event. The note number specifies which of the 128 MIDI
			 * keys is being played and the velocity determines how fast/hard the key was released. The
			 * note number is normally used to specify which previously pressed key is being released and
			 * the velocity is usually ignored, but is sometimes used to adjust the slope of an instruments
			 * release phase.
			 * @param delta_time Delta time
			 * @param mchannel MIDI channel number
			 * @param note Note
			 * @param veloc Velocity
			 *
			 * @see addEvent
			 * @see MIDInote
			 */
			inline void addNoteOffEvent(unsigned int delta_time, unsigned char mchannel, unsigned char note, unsigned char veloc)
			{
				addEvent(delta_time, Note_Off_evt, mchannel, note, veloc);
			}

			/**
			 * Adds a note on MIDI event
			 *
			 * The note on event is used to signal when an MIDI key is pressed. This type of event has two
			 * parameters. The note number that specifies which of the 128 MIDI keys is being played and
			 * the velocity determines how fast/hard the key is pressed. The note nuember is normally used
			 * to specify the instruments musical pitch and the velocity is usually to specify the
			 * instruments playback volume and intensity.
			 * @param delta_time Delta time
			 * @param mchannel MIDI channel number
			 * @param note Note
			 * @param veloc Velocity
			 *
			 * @see addEvent
			 * @see MIDInote
			 */
			inline void addNoteOnEvent(unsigned int delta_time, unsigned char mchannel, unsigned char note, unsigned char veloc)
			{
				addEvent(delta_time, Note_On_evt, mchannel, note, veloc);
			}

			/**
			 * Adds a note aftertouch MIDI event
			 *
			 * The note aftertouch event is used to indicate a pressure change on one of the currently
			 * pressed MIDI keys. It has two parameters. The note number of which key's pressure is
			 * changing and the aftertouch value which specifies the amount of pressure being applied.
			 *
			 * Note aftertouch is used for extra expressino of particular notes, often introducing or
			 * increasing some type of modulation during the instrument's sustain phrase.
			 * @param delta_time Delta time
			 * @param mchannel MIDI channel number
			 * @param note Note
			 * @param amount The amount (0 = no pressure; 127 = full pressure)
			 */
			inline void addNoteAfterTouchEvent(unsigned int delta_time, unsigned char mchannel, unsigned char note, unsigned char amount)
			{
				addEvent(delta_time, Note_Aftertouch_evt, mchannel, note, amount);
			}

			/**
			 * Adds a controller event
			 *
			 * The controller event signals the change in an MIDI channel state. There are 128 controllers
			 * which define different attributes of the channel including volume, pan, modulation, effects,
			 * and more. This event has two parameters. The controller number specifies which control is
			 * changing and the controller value defines it's new setting.
			 * @param delta_time Delta time
			 * @param mchannel MIDI channel number
			 * @param type Controller type
			 * @param value Value
			 */
			inline void addControllerEvent(unsigned int delta_time, unsigned char mchannel, unsigned char type, unsigned char value)
			{
				addEvent(delta_time, Controller_evt, mchannel, type, value);
			}

			/**
			 * Adds a program change event
			 *
			 * The program change event is used to change which program (instrument/patch) should be played
			 * on the MIDI channel. This type of event takes only one parameter: the program number of the
			 * new instrument/patch.
			 * @param delta_time Delta time
			 * @param mchannel MIDI channel number
			 * @param num The program number of the new instrument/patch
			 */
			inline void addProgramChangeEvent(unsigned int delta_time, unsigned char mchannel, unsigned char num)
			{
				addEvent(delta_time, Program_Change_evt, mchannel, num);
			}

			/**
			 * Adds a channel aftertouch event
			 *
			 * The channel aftertouch event is simular to the note aftertouch message, except it effects
			 * all keys currently pressed on the specific MIDI channel. This type of event takes only one
			 * parameter: the aftertouch amount
			 * @param delta_time Delta time
			 * @param mchannel MIDI channel number
			 * @param amount The aftertouch amount (0 = no pressure; 127 = full pressure)
			 */
			inline void addChannelAftertouchEvent(unsigned int delta_time, unsigned char mchannel, unsigned char amount)
			{
				addEvent(delta_time, Channel_Aftertouch_evt, mchannel, amount);
			}

			/**
			 * Adds a pitch bend event
			 *
			 * The pitch bend event is similar to a controller event, except that it is a unique MIDI
			 * channel event that has two bytes to describe it's value. The pitch value is defined by both
			 * parameters of the MIDI channel event by joining them in the format yyyyyyyxxxxxxx, where
			 * the y characters represent the last 7 bits of the second parameter and the x characters
			 * represent the last 7 bits of the first parameter. The combining of both parameters enables
			 * high accuracy values (0-16383). The pitch value affects all playing notes on the current
			 * channel. Values below 8192 decrease the pitch, while values above 8192 increase the pitch.
			 * The pitch range may vary from instrument to instrument, but is usually +- 2 semi-tones.
			 * @param delta_time Delta time
			 * @param mchannel MIDI channel number
			 * @param lsbval Value (LSB)
			 * @param msbval Value (MSB)
			 */
			inline void addPitchBendEvent(unsigned int delta_time, unsigned char mchannel, unsigned char lsbval, unsigned char msbval)
			{
				addEvent(delta_time, Pitch_Bend_evt, mchannel, lsbval, msbval);
			}
	};
}

#endif
