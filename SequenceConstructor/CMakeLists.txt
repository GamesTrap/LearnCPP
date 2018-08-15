project(SequenceConstructor)

set( SEQUENCECONSTRUCTOR_SOURCES
	src/main.cpp
	src/NumberSequence.h
	src/NumberSequence.cpp
)

add_executable(${PROJECT_NAME} ${SEQUENCECONSTRUCTOR_SOURCES})