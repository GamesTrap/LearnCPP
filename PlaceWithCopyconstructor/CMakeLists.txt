project(PlaceWithCopyconstructor)

set( PLACEWITHCOPYCONSTRUCTOR_SOURCES
	src/main.cpp
	src/PlaceWithCopyconstructor.h
	src/PlaceWithCopyconstructor.cpp
)

add_executable(${PROJECT_NAME} ${PLACEWITHCOPYCONSTRUCTOR_SOURCES})