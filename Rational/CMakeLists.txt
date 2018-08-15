project(Rational)

set( RATIONAL_SOURCES
	src/main.cpp
	src/Rational.h
	src/Rational.cpp
)

add_executable(${PROJECT_NAME} ${RATIONAL_SOURCES})