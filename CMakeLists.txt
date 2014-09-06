cmake_minimum_required(VERSION 2.6)

project(CreateMIDI)
set(CREATEMIDI_VERSION_STRING "0.1.0")
set(CREATEMIDI_VERSION_MAJOR 1)
set(CREATEMIDI_VERSION_MINOR 0)
set(CREATEMIDI_VERSION_PATCH 0)

# Glob all the sources
file(GLOB_RECURSE CREATEMIDI_SOURCES "${CMAKE_SOURCE_DIR}/src" "src/*.cpp")
file(GLOB_RECURSE CREATEMIDI_HEADERS "${CMAKE_SOURCE_DIR}/include" "include/*.h")

include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(CreateMIDI SHARED ${CREATEMIDI_SOURCES} ${CREATEMIDI_HEADERS})


# Some examples
add_executable(example "${CMAKE_SOURCE_DIR}/example/example.cpp")
add_dependencies(example CreateMIDI)
target_link_libraries(example CreateMIDI)


# Doxygen API documents
find_package(Doxygen)
if(DOXYGEN_FOUND)
	set(DOXYGEN_SOURCE_DIR ${CMAKE_SOURCE_DIR})
	configure_file(${CMAKE_SOURCE_DIR}/Doxyfile.in ${CMAKE_SOURCE_DIR}/Doxyfile @ONLY)
	add_custom_target(doc
		${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		COMMENT "Generating API documents with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)
