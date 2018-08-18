#include <iostream>

typedef float real; //New name with typedef
using REAL = double; //New name with using

int main()
{
	const real number1{ 1.7353f }; //number1 is of type float
	const REAL number2{ 3.1415 }; //number2 is of type double

	std::cout << number1 << '\n';
	std::cout << number2 << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}