project(NumToString)

set( NUMTOSTRING_SOURCES
	src/main.cpp
	src/NumToString.cpp
	src/NumToString.h
)

add_executable(${PROJECT_NAME} ${NUMTOSTRING_SOURCES})