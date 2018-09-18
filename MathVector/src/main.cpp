#include <iostream>

#include "MathVector.h"

int main()
{
	MathVector<double> v1(4, 1.0);
	const MathVector<double> v2(10, 2.0);
	std::cout << "v1 = " << v1;
	std::cout << "v2 = " << v2;

	v1 *= 1.234567; //Multiply all elements of v1
	std::cout << "v1 = " << v1;

	v1 = v2 * 1.234567;
	std::cout << "v1 = v2 * 1.234567:" << '\n' << v1;

	v1 = 1.234567 * v2;
	std::cout << "is equal to 1.234567 * v2:" << '\n' << v1;

	const MathVector<double> v3 = { 1.1,2.2,3.3 };
	std::cout << "v3 = " << v3;

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}