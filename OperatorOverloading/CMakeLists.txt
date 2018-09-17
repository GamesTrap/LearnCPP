project(OperatorOverloading)

set( OPERATOROVERLOADING_SOURCES
	src/main.cpp
	src/Rational.h
	src/Rational.cpp
)

add_executable(${PROJECT_NAME} ${OPERATOROVERLOADING_SOURCES})