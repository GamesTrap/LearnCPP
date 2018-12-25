project(ProducerConsumerProblem)

set( PRODUCERCONSUMERPROBLEM_SOURCES
	src/main.cpp
	src/Random.h
	src/Producer.h
	src/Consumer.h
	src/Stack.h
)

add_executable(${PROJECT_NAME} ${PRODUCERCONSUMERPROBLEM_SOURCES})