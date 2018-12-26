project(ReadWriteThread)

set( READWRITETHREAD_SOURCES
	src/main.cpp
	src/Writer.h
	src/Reader.h
	src/Resource.h
	src/ReaderOrWriter.h
	src/Random.h
	src/ThreadGroup.h
)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${READWRITETHREAD_SOURCES})

target_link_libraries(${PROJECT_NAME} Threads::Threads)
