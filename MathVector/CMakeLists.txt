project(MathVector)

set( MATHVECTOR_SOURCES
	src/main.cpp
	src/MathVector.h
	src/Vector.h
)

add_executable(${PROJECT_NAME} ${MATHVECTOR_SOURCES})