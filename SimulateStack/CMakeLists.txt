project(SimulateStack)

set( SIMULATESTACK_SOURCES
	src/main.cpp
	src/SimpleStack.h
)

add_executable(${PROJECT_NAME} ${SIMULATESTACK_SOURCES})