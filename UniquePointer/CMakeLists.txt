project(UniquePointer)

set( UNIQUEPOINTER_SOURCES
	src/main.cpp
	src/Place.h
	src/Place.cpp
)

add_executable(${PROJECT_NAME} ${UNIQUEPOINTER_SOURCES})