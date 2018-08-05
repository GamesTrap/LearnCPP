#include <iostream>

int main()
{
	std::cout << "Limits for integer types:" << '\n';

	std::cout << "INT_MIN   = " << INT_MIN << '\n';
	std::cout << "INT_MAX   =  " << INT_MAX << '\n';
	std::cout << "LONG_MIN  = " << LONG_MIN << '\n';
	std::cout << "LONG_MAX  =  " << LONG_MAX << '\n';
	std::cout << "LLONG_MIN = " << LLONG_MIN << '\n';
	std::cout << "LLONG_MAX =  " << LLONG_MAX << '\n';

	std::cout << '\n' << "unsigned limits:" << '\n';
	std::cout << "UINT_MAX   = " << UINT_MAX << '\n';
	std::cout << "ULONG_MAX  = " << ULONG_MAX << '\n';
	std::cout << "ULLONG_MAX = " << ULLONG_MAX << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}