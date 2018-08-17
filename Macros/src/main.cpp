#include <iostream>

//To test it, comment out one or both of the following macros
//#define BRANCH1
#define CONSTANT 42

int main()
{
#ifdef BRANCH1
	std::cout << "BRANCH1 is defined" << '\n';
#elif CONSTANT == 42
	std::cout << "BRANCH1 is undefined, constant is 42" << '\n';
#else
	std::cout << "BRANCH1 is undefined, constant is undefined or != 42" << '\n';
#endif

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}