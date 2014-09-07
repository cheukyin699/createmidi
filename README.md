CreateMIDI	v0.0.0
==================

About
-----
CreateMIDI is a library that helps you create MIDI files.

Author: Ng Cheuk Yin <mailto:cheukyin699@yahoo.com>

Build
-----

You may use CMake to compile the sources to library.

	mkdir build/ && cd build/
	cmake ..
	make
	make install

Documentation
-------------

Documentation is automatically generated with Doxygen.

1. **CMake**

	You can build the documentation by the make command (Makefile created in 'Build')

	(Must have done 'Build')

		make doc

2. **Doxygen**

	If you don't have CMake, Doxygen will do.

		doxygen Doxyfile

