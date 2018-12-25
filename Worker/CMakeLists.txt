project(Worker)

set( WORKER_SOURCES
	src/main.cpp
	src/CallWrapper.h
	src/Worker.h
)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${WORKER_SOURCES})

target_link_libraries(${PROJECT_NAME} Threads::Threads)
