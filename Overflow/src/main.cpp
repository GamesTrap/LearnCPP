#include <iostream>

int main()
{
	const int ai{ 50000 }; //Initialization with 50000
	const int bi{ 1'000'000 }; //Initialization with 1000000, with seperator
	const int ci{ ai * bi };

	std::cout << "int numbers have " << 8 * sizeof(int) << " bits on your system" << '\n';
	std::cout << "Calculation with int:  ";
	std::cout << ai << " * " << bi << " = " << ci << '\n';
	//Outputs -1539607552 instead of 50000000000 at 32 bit int

	long al{ 50000L }; //L (or l): Marking as long
	const long bl{ 1000000L };
	const long cl{ al * bl };
	std::cout << '\n' << "long numbers have " << 8 * sizeof(long) << " bits on your system" << '\n';
	std::cout << "Calculation with long: ";
	std::cout << al << " * " << bl << " = " << cl << '\n';

	std::cout << '\n' << "Produce long overflow:" << '\n';
	al = std::numeric_limits<long>::max() / 2 + 1000;
	std::cout << "2 * " << al << " = " << (2 * al) << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}