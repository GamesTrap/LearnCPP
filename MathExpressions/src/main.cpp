#include <iostream>

#include <cmath>

int main()
{
	float x;
	std::cout << "Enter x: ";
	std::cin >> x;

	std::cout << "x       = " << x << '\n';
	std::cout << "fabs(x) = " << fabs(x) << '\n';
	std::cout << "sqrt(x) = " << sqrt(x) << '\n';
	std::cout << "sin(x)  = " << sin(x) << '\n'; //x in radians
	std::cout << "exp(x)  = " << exp(x) << '\n';
	std::cout << "log(x)  = " << log(x) << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}