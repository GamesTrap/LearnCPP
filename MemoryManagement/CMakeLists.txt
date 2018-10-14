project(MemoryManagement)

set( MEMORYMANAGEMENT_SOURCES
	src/main.cpp
	src/MemoryManagement.h
	src/Person.h
	src/Person.cpp
)

add_executable(${PROJECT_NAME} ${MEMORYMANAGEMENT_SOURCES})