#include <iostream>
#include <array>

int main()
{
	const char* sArray[] = { "one", "two" };
	const char** sPointer = sArray; //Pointer to const char*
	//Output:
	std::cout << sArray[0] << '\n'; //one
	std::cout << *sArray << '\n'; //one
	std::cout << sArray[1] << '\n'; //two
	std::cout << sArray[1][0] << '\n'; //t
	std::cout << *sPointer << '\n'; //one
	std::cout << sPointer[1] << '\n'; //two

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}
