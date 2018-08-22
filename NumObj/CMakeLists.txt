project(NumObj)

set( NUMOBJ2_SOURCES
	src/main.cpp
	src/NumObj.h
	src/NumObj.cpp
)

add_executable(${PROJECT_NAME} ${NUMOBJ2_SOURCES})