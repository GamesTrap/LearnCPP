#include <iostream>

int main()
{
	std::cout << "Limits for integer types:" << std::endl;

	std::cout << "INT_MIN   = " << INT_MIN << std::endl;
	std::cout << "INT_MAX   =  " << INT_MAX << std::endl;
	std::cout << "LONG_MIN  = " << LONG_MIN << std::endl;
	std::cout << "LONG_MAX  =  " << LONG_MAX << std::endl;
	std::cout << "LLONG_MIN = " << LLONG_MIN << std::endl;
	std::cout << "LLONG_MAX =  " << LLONG_MAX << std::endl;

	std::cout << '\n' << "unsigned limits:" << std::endl;
	std::cout << "UINT_MAX   = " << UINT_MAX << std::endl;
	std::cout << "ULONG_MAX  = " << ULONG_MAX << std::endl;
	std::cout << "ULLONG_MAX = " << ULLONG_MAX << std::endl;

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}