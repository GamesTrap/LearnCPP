project(RegexTester)

set( REGEXTESTER_SOURCES
	src/main.cpp
	src/RegexTester.cpp
	src/RegexTester.h
)

add_executable(${PROJECT_NAME} ${REGEXTESTER_SOURCES})