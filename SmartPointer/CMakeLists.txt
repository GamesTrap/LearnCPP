project(SmartPointer)

set( SMARTPOINTER_SOURCES
	src/main.cpp
	src/NullPointerException.h
	src/SmartPointer.h
)

add_executable(${PROJECT_NAME} ${SMARTPOINTER_SOURCES})