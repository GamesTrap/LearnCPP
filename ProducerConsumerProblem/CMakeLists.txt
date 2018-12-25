project(ProducerConsumerProblem)

set( PRODUCERCONSUMERPROBLEM_SOURCES
	src/main.cpp
	src/Stack.h
	src/Producer.h
	src/Consumer.h
	src/Random.h
)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${PRODUCERCONSUMERPROBLEM_SOURCES})

target_link_libraries(${PROJECT_NAME} Threads::Threads)
