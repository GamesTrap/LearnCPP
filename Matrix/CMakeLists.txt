project(Matrix)

set( MATRIX_SOURCES
	src/main.cpp
	src/Matrix.h
	src/Matrix3D.h
)

add_executable(${PROJECT_NAME} ${MATRIX_SOURCES})