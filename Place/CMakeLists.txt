project(Place)

set( PLACE_SOURCES
	src/main.cpp
	src/Place.h
	src/Place.cpp
)

add_executable(${PROJECT_NAME} ${PLACE_SOURCES})