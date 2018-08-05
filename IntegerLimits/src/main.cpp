#include <iostream>

int main()
{
	std::cout << "Limits for integer types:" << '\n';
	std::cout << "int Minimum       = " << std::numeric_limits<int>::min() << '\n';
	std::cout << "int Maximum       =  " << std::numeric_limits<int>::max() << '\n';
	std::cout << "long Minimum      = " << std::numeric_limits<long>::min() << '\n';
	std::cout << "long Maximum      =  " << std::numeric_limits<long>::max() << '\n';
	std::cout << "long long Minimum = " << std::numeric_limits<long long>::min() << '\n';
	std::cout << "long long Maximum =  " << std::numeric_limits<long long>::max() << '\n';

	std::cout << '\n' << "unsigned maximum (minimum is 0):" << '\n';
	std::cout << "unsigned int       = " << std::numeric_limits<unsigned int>::max() << '\n';
	std::cout << "unsigned long      = " << std::numeric_limits<unsigned long>::max() << '\n';
	std::cout << "unsigned long long = " << std::numeric_limits<unsigned long long>::max() << '\n';

	std::cout << '\n' << "Number of bytes for:" << '\n';
	std::cout << "int       = " << sizeof(int) << '\n';
	std::cout << "long      = " << sizeof(long) << '\n';
	std::cout << "long long = " << sizeof(long long) << '\n';
	std::cout << "size_t    = " << sizeof(size_t) << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}