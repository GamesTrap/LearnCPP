project(String)

set( STRING_SOURCES
	src/main.cpp
	src/String.h
	src/String.cpp
)

add_executable(${PROJECT_NAME} ${STRING_SOURCES})