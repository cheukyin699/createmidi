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

			ostream output;
			vector<MIDItrack> tracks;

		public:

			/**
			 * The default constructor
			 */
			MIDIfile();

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
			MIDIhead getMIDIhead();

			/*************************
			 * SETTERS
			 ************************/

			/**
			 * Sets the output stream
			 * @param o The output stream
			 */
			void setOutput(ostream o);

	};
}

#endif
