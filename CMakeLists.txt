cmake_minimum_required(VERSION 2.6)

project(CreateMIDI)

# Glob all the sources
file(GLOB_RECURSE CREATEMIDI_SOURCES "${CMAKE_SOURCE_DIR}/src" "src/*.cpp")
file(GLOB_RECURSE CREATEMIDI_HEADERS "${CMAKE_SOURCE_DIR}/include" "include/*.h")

include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(CreateMIDI SHARED ${CREATEMIDI_SOURCES} ${CREATEMIDI_HEADERS})


# Some examples
#add_executable(example "${CMAKE_SOURCE_DIR}/example/main.cpp")
#add_dependencies(example CreateMIDI)
#target_link_libraries(example CreateMIDI)
