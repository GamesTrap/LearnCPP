#include <iostream>

int main()
{
	float a{ 1.234567E-7f };
	float b{ 1.0000000f };
	float c{ -b };

	std::cout << "Inaccuracy with float Arithmetic:" << '\n';
	std::cout << "(a + b) + c = " << (a + b) + c << '\n'; //1.19209e-7
	std::cout << "a + (b + c) = " << a + (b + c) << '\n'; //1.23457e-7
	std::cout << (2 ^ 3) << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}