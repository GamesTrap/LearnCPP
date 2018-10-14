#include <iostream>

#define PRINT(X) std::cout << (#X) << " = " << (X) << '\n';
#include "Matrix3D.h"

int main()
{
	Matrix<float> a(3, 4);
	Matrix<float> b(4, 5);
	Matrix<float> c;
	std::vector<float> v = { 99.0,99.0,99.0,99.0,99.0 };
	Matrix3D<float> matrix3D(2, 3, 4);
	matrix3D.I();

	a.init(1.0);
	for (std::size_t i = 0; i < b.rows(); ++i)
		for (std::size_t j = 0; j < b.columns(); ++j)
			b[i][j] = i + j;

	c = a * b;

	PRINT(a);
	PRINT(b);
	PRINT(c);

	std::cout << "a.I(); :" << '\n';
	a.I();
	PRINT(a);
	PRINT(b);
	PRINT(a * b);

	a *= b;
	std::cout << "a *= b;" << '\n';
	PRINT(a);
	PRINT(b);

	b[1] = v;
	std::cout << "b[1] = v:" << '\n';
	PRINT(b);

	std::cout << "Assignment of a submatrix:" << '\n';
	for(std::size_t i = 0; i < matrix3D.dim1(); ++i)
	{
		PRINT(i);
		PRINT(matrix3D[i]);
	}

	std::cout << "matrix3D[1] = b;:" << '\n';
	matrix3D[1] = b;
	for(std::size_t i = 0; i < matrix3D.dim1(); ++i)
	{
		PRINT(i);
		PRINT(matrix3D[i]);
	}
	v = { 33.0,33.0,33.0,33.0,33.0 };
	std::cout << "matrix3D[0][1] = v; (33):" << '\n';
	matrix3D[0][1] = v;
	for(std::size_t i = 0; i < matrix3D.dim1(); ++i)
	{
		PRINT(i);
		PRINT(matrix3D[i]);
	}
	matrix3D.init(100);
	std::cout << "matrix3D.init(100)):" << '\n';
	for(std::size_t i = 0; i < matrix3D.dim1(); ++i)
	{
		PRINT(i);
		PRINT(matrix3D[i]);
	}
	matrix3D.I();
	std::cout << "matrix3D.I()):" << '\n';
	for(std::size_t i = 0; i < matrix3D.dim1(); ++i)
	{
		PRINT(i);
		PRINT(matrix3D[i]);
	}


	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}