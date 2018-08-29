project(ABSTRACTINHERITANCE)

set( ABSTRACTINHERITANCE_SOURCES
	src/main.cpp
	src/GraphObj.h
	src/Line.h
	src/Rectangle.h
	src/Quad.h
	src/Place.h
)

add_executable(${PROJECT_NAME} ${ABSTRACTINHERITANCE_SOURCES})