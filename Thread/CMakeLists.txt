project(Thread)

set( THREAD_SOURCES
	src/main.cpp
)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${THREAD_SOURCES})

target_link_libraries(${PROJECT_NAME} Threads::Threads)
