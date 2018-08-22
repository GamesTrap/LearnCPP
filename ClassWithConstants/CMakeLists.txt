project(ClassWithConstants)

set( CLASSWITHCONSTANTS_SOURCES
	src/main.cpp
	src/Constants.h
	src/Constants.cpp
)

add_executable(${PROJECT_NAME} ${CLASSWITHCONSTANTS_SOURCES})