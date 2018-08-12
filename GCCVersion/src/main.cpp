#include <iostream>

#if __GNUG__
    #define COMPILER "GNU C++ Compiler"
#else
    #define COMPILER "other compiler"
#endif

int main()
{
	std::cout << COMPILER << '\n';
#if __GNUC__ > 5
	std::cout << "Version >= 6: " << __VERSION__ << '\n';
#endif

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}