project(PrivateInheritance)

set( PRIVATEINHERITANCE_SOURCES
	src/main.cpp
	src/Queue.h
	src/QueueD.h
)

add_executable(${PROJECT_NAME} ${PRIVATEINHERITANCE_SOURCES})