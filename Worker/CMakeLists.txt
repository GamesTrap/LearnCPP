project(Worker)

set( WORKER_SOURCES
	src/main.cpp
	src/Worker.h
	src/CallWrapper.h
)

add_executable(${PROJECT_NAME} ${WORKER_SOURCES})