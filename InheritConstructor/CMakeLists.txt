project(InheritConstructor)

set( INHERITCONSTRUCTOR_SOURCES
	src/main.cpp
	src/DerivedClass.h
	src/BaseClass.h
)

add_executable(${PROJECT_NAME} ${INHERITCONSTRUCTOR_SOURCES})