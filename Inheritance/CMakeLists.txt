project(Inheritance)

set( INHERITANCE_SOURCES
	src/main.cpp
	src/Line.h
	src/Rectangle.h
	src/GraphObj.h
)

add_executable(${PROJECT_NAME} ${INHERITANCE_SOURCES})