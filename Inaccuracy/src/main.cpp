#include <iostream>

int main()
{
	const float a{ 1.234567E-7f };
	const float b{ 1.0000000f };
	const float c{ -b };

	std::cout << "Inaccuracy with float Arithmetic:" << '\n';
	std::cout << "(a + b) + c = " << (a + b) + c << '\n'; //1.19209e-7
	std::cout << "a + (b + c) = " << a + (b + c) << '\n'; //1.23457e-7
	std::cout << (2 ^ 3) << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}