project(StringView)

set( STRINGVIEW_SOURCES
	src/main.cpp
	src/StringView.h
)

add_executable(${PROJECT_NAME} ${STRINGVIEW_SOURCES})