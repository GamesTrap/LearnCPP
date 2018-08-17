#include <iostream>

#include <climits>

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
	std::cout << "UINT_MAX   = " << UINT32_MAX << '\n';
	std::cout << "ULONG_MAX  = " << ULONG_MAX << '\n';
	std::cout << "ULLONG_MAX = " << ULLONG_MAX << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}