project(PrivateVirtualFunctions)

set( PRIVATEVIRTUALFUNCTIONS_SOURCES
	src/main.cpp
	src/GraphObj.h
	src/Line.h
	src/Place.h
	src/Rectangle.h
	src/Square.h
)

add_executable(${PROJECT_NAME} ${PRIVATEVIRTUALFUNCTIONS_SOURCES})