project(NewOverloading)

set( NEWOVERLOADING_SOURCES
	src/main.cpp
	src/Person.h
	src/Object.h
)

add_executable(${PROJECT_NAME} ${NEWOVERLOADING_SOURCES})