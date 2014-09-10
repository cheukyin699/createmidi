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

	// Controller Types
	const char Bank_Select				= 0x0;
	const char Modulation				= 0x1;
	const char Breath_Controller		= 0x2;
	const char Foot_Controller			= 0x4;
	const char Portamento_Time			= 0x5;
	const char Data_Entry				= 0x6;
	const char Main_Volume				= 0x7;
	const char Balance					= 0x8;
	const char Pan						= 0xA;
	const char Expression_Controller	= 0xB;
	const char Effect_Control1			= 0xC;
	const char Effect_Control2			= 0xD;
	//! General-Purpose Controllers 1-4 (This one is for calculations)
	const char Base_GPC					= 0x10;
	//! LSB for Controllers 0-31 (This is for calculations)
	const char Base_Controller_LSB		= 0x20;
	//! For sustain
	const char Damper_Pedal				= 0x40;
	const char Portamento				= 0x41;
	const char Sostenuto				= 0x42;
	const char Soft_Pedal				= 0x43;
	const char Legato_Footswitch		= 0x44;
	const char Hold2					= 0x45;
	//! Sound Controllers 1-10 (Used for calculations)
	const char Base_Sound_Controller	= 0x46;
	//! General-Purpose Controllers 5-8 (Used for calculations)
	const char Base_Upper_GPC			= 0x50;
	const char Portamento_Control		= 0x54;
	//! Effects 1-5 (Used for calculations)
	const char Base_Effects				= 0x5B;
	const char Data_Increment			= 0x60;
	const char Data_Decrement			= 0x61;
	const char NR_Param_Num_LSB			= 0x62;
	const char NR_Param_Num_MSB			= 0x63;
	const char R_Param_Num_LSB			= 0x64;
	const char R_Param_Num_MSB			= 0x65;
	//! Mode Messages 1-7 (Used for calculations)
	const char Base_Mode_Msg			= 0x79;

	// Meta Event Type Numbers
	const char Meta_Seq_Num				= 0x0;
	const char Meta_Text_Evt			= 0x1;
	const char Meta_Copyright_Notice	= 0x2;
	const char Meta_Seq_Track_Name		= 0x3;
	const char Meta_Instrument_Name		= 0x4;
	const char Meta_Lyrics				= 0x5;
	const char Meta_Marker				= 0x6;
	const char Meta_Cue_Point			= 0x7;
	const char Meta_Channel_PFX			= 0x20;
	const char Meta_EOT					= 0xFF;
	const char Meta_Set_Tempo			= 0x51;
	const char Meta_SMPTE_Offset		= 0x54;
	const char Meta_Time_Signature		= 0x58;
	const char Meta_Key_Signature		= 0x59;
	const char Meta_Seq_Specific		= 0x7F;

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
	inline unsigned char makeNote(MIDInote note, short octave = 0)
	{
		return (unsigned char)((int)note + 60 + 12 * octave);
	}

	/**
	 * Gets the GPC<num> using Base_GPC and Base_Upper_GPC
	 * @param GPC_num The General-Purpose Controller number (1-8)
	 * @return The GPC<num> type (number) or 0 if unsuccessful
	 * @see Base_GPC
	 * @see Base_Upper_GPC
	 */
	unsigned char GPCtype(unsigned short GPC_num);

	/**
	 * Gets the Controller_LSB<num> using Base_Controller_LSB
	 * @param cLSB_num The Controller LSB number (0-31)
	 * @return The Controller_LSB<num> type (number) or 0 if unsuccessful
	 * @see Base_Controller_LSB
	 */
	unsigned char Controller_LSB_type(unsigned short cLSB_num);

	/**
	 * Gets the Sound_Controller<num> using Base_Sound_Controller
	 * @param SC_num The Sound Controller number (1-10)
	 * @return The Sound_Controller<num> type (number) or 0 if unsuccessful
	 * @see Base_Sound_Controller
	 */
	unsigned char Sound_Controller_type(unsigned short SC_num);

	/**
	 * Gets the Effects<num> using Base_Effects
	 * @param E_num The Effects number (1-5)
	 * @return The Effects<num> type (number) or 0 if unsuccessful
	 * @see Base_Effects
	 */
	unsigned char Effects_type(unsigned short E_num);

	/**
	 * Gets the Mode_Msg<num> using Base_Mode_Msg
	 * @param MM_num The Mode Message number (1-7)
	 * @return The Mode_Msg<num> type (number) or 0 if unsuccessful
	 * @see Base_Mode_Msg
	 */
	unsigned char Mode_Msg_type(unsigned short MM_num);
}

#endif
