project(Performance)

set( PERFORMANCE_SOURCES
	src/main.cpp
	src/SimpleString.h
	src/MoveString.h
)

add_executable(${PROJECT_NAME} ${PERFORMANCE_SOURCES})