project(CountMemoryManagement)

set( COUNTMEMORYMANAGEMENT_SOURCES
	src/main.cpp
	src/Person.h
	src/CountingObject.h
)

add_executable(${PROJECT_NAME} ${COUNTMEMORYMANAGEMENT_SOURCES})