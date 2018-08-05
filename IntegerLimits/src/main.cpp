#include <iostream>

int main()
{
	std::cout << "Limits for integer types:" << std::endl;
	std::cout << "int Minimum       = " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "int Maximum       =  " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "long Minimum      = " << std::numeric_limits<long>::min() << std::endl;
	std::cout << "long Maximum      =  " << std::numeric_limits<long>::max() << std::endl;
	std::cout << "long long Minimum = " << std::numeric_limits<long long>::min() << std::endl;
	std::cout << "long long Maximum =  " << std::numeric_limits<long long>::max() << std::endl;

	std::cout << '\n' << "unsigned maximum (minimum is 0):" << std::endl;
	std::cout << "unsigned int       = " << std::numeric_limits<unsigned int>::max() << std::endl;
	std::cout << "unsigned long      = " << std::numeric_limits<unsigned long>::max() << std::endl;
	std::cout << "unsigned long long = " << std::numeric_limits<unsigned long long>::max() << std::endl;

	std::cout << '\n' << "Number of bytes for:" << std::endl;
	std::cout << "int       = " << sizeof(int) << std::endl;
	std::cout << "long      = " << sizeof(long) << std::endl;
	std::cout << "long long = " << sizeof(long long) << std::endl;
	std::cout << "size_t    = " << sizeof(size_t) << std::endl;

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}