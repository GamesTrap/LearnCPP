project(PersonnelAdministration)

set( PERSONNELADMINISTRATION_SOURCES
	src/main.cpp
	src/Person.h
	src/PersonnelAdministration.h
	src/PersonnelAdministration.cpp
)

add_executable(${PROJECT_NAME} ${PERSONNELADMINISTRATION_SOURCES})