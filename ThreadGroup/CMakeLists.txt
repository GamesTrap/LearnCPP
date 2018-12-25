project(ThreadGroup)

set( THREADGROUP_SOURCES
	src/main.cpp
	src/ThreadGroup.h
)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${THREADGROUP_SOURCES})

target_link_libraries(${PROJECT_NAME} Threads::Threads)
