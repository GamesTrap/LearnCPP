project(FunctionObject)

set( FUNCTIONOBJECT_SOURCES
	src/main.cpp
	src/Sine.h
)

add_executable(${PROJECT_NAME} ${FUNCTIONOBJECT_SOURCES})