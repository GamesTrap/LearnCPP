project(GuardMemoryManagement)

set( GUARDMEMORYMANGEMENT_SOURCES
	src/main.cpp
	src/CountingObject.h
	src/CountingObject.cpp
	src/Person.h
	src/Guard.h
)

add_executable(${PROJECT_NAME} ${GUARDMEMORYMANGEMENT_SOURCES})