#include <iostream>

struct BitFieldStructure
{
	unsigned int a : 4; //a and b are bit fields
	unsigned int b : 3;
};

int main()
{
	BitFieldStructure x{};
	x.a = 06;
	x.b = x.a | 3;
	//Conversion to unsigned and output
	std::cout << x.b << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}