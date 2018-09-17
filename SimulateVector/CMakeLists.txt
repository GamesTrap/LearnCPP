project(SimulateVector)

set( SIMULATEVECTOR_SOURCES
	src/main.cpp
	src/Vector.h
)

add_executable(${PROJECT_NAME} ${SIMULATEVECTOR_SOURCES})