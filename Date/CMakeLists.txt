project(Date)

set( DATE_SOURCES
	src/main.cpp
	src/Date.h
	src/Date.cpp
	src/INVALIDDATEEXCEPTION.h
)

add_executable(${PROJECT_NAME} ${DATE_SOURCES})